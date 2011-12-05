import FWCore.ParameterSet.Config as cms

DATALIST=[
	#"/QCD_Pt-120to170_TuneZ2_7TeV_pythia6/Fall11-PU_S6-START44_V5-v1/AODSIM",
        #  "/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM",
        #  "/QCD_Pt-300to470_TuneZ2_7TeV_pythia6/Fall11-PU_S6-START44_V5-v1/AODSIM",
#          "/QCD_Pt-15to3000_TuneZ2_Flat_7TeV_pythia6/Fall11-Peak32PU_START42_V14B-v1/GEN-SIM-RECO",
          "/Jet/Run2011B-PromptReco-v1/AOD"
          ]
HLTProc="HLT"
# It will select the events based on the TriggerSelections. The ntuple will only save the triggers whose name matches any entry in TriggerSelections
TriggerSelections=cms.vstring("HLT_*Jet*")

process = cms.Process("validation")
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

#keep the logging output to a nice level
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("RecoBTag.Configuration.RecoBTag_cff")

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#Global tag
#from Configuration.PyReleaseValidation.autoCond import autoCond
from Configuration.AlCa.autoCond import autoCond
process.GlobalTag.globaltag = autoCond['startup']

process.source = cms.Source("PoolSource",
#    fileNames = cms.untracked.vstring("rfio:/castor/cern.ch/user/z/zhangjin/Test_QCD_Pt-15to3000_TuneZ2_Fall11_Peak32PU_RECO.root")
fileNames = cms.untracked.vstring("file:/afs/cern.ch/user/z/zhangjin/MetaData/Test_Jet_Run2011B_AOD.root",
                                  "file:/afs/cern.ch/user/z/zhangjin/MetaData/Test_Jet_Run2011B_AOD_2.root")
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

########### Event cleaning ###########
#Require a good vertex

process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi")

process.oneGoodVertexFilter = cms.EDFilter("VertexSelector",
   src = cms.InputTag("offlinePrimaryVertices"),
   cut = cms.string("!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2"),
   filter = cms.bool(True),   # otherwise it won't filter the events, just produce an empty vertex collection.
)

#Filter for removing scraping events
process.noscraping = cms.EDFilter("FilterOutScraping",
                                applyfilter = cms.untracked.bool(True),
                                debugOn = cms.untracked.bool(False),
                                numtrack = cms.untracked.uint32(10),
                                thresh = cms.untracked.double(0.25)
                                )


########### Trigger selection ###########
# Select events based on the HLT triggers....singleJet and BTag triggers
# Use the instructions provided at:
# https://twiki.cern.ch/twiki/bin/viewauth/CMS/TriggerResultsFilter
# This eases the trigger selection for different HLT menus and also takes care of wildcard and trigger versioning
#######

import HLTrigger.HLTfilters.triggerResultsFilter_cfi as hlt
process.JetHLTFilter = hlt.triggerResultsFilter.clone(
   triggerConditions = TriggerSelections,
   hltResults = cms.InputTag("TriggerResults","",HLTProc),
   l1tResults = cms.InputTag( "" ),
   throw = cms.bool( False) #set to false to deal with missing triggers while running over different trigger menus
)

########### Jet selection and JEC ###########
# Apply "loose PF JetID" first
process.PFJetsFilter = cms.EDFilter("PFJetSelector",
  src = cms.InputTag("ak5PFJets"),
  cut = cms.string("pt > 10.0 && abs(eta) < 2.4 && neutralHadronEnergyFraction < 0.99 && neutralEmEnergyFraction < 0.99 && nConstituents > 1 && chargedHadronEnergyFraction > 0.0 && chargedMultiplicity > 0.0 && chargedEmEnergyFraction < 0.99"),
  filter = cms.bool(True)
)

# Then apply the JEC
#...........................................
# JEC in 38X....switch off use of confDB
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')

##------------------  PF JETS --------------
process.ak5PFJetsJEC = process.ak5PFJetsL2L3.clone(
    src = 'PFJetsFilter', 
    correctors = ['ak5PFL2L3'])

#............................................


#Filter to remove pthat>15 events in MinBias samples
process.pthat_filter = cms.EDFilter("MCProcessFilter",
	  MaxPthat = cms.untracked.vdouble(15.0),
	  ProcessID = cms.untracked.vint32(0),
	  MinPthat = cms.untracked.vdouble(1.0)
)

process.load("PhysicsTools.HepMCCandAlgos.flavorHistoryPaths_cfi")

########### Rerun b-tagging for PF Jets ###########
process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")

process.ak5PFJetTracksAssociatorAtVertex = cms.EDProducer("JetTracksAssociatorAtVertex",
   process.j2tParametersVX,
   jets = cms.InputTag("ak5PFJetsJEC")
)


process.standardImpactParameterPFTagInfos = process.impactParameterTagInfos.clone(
  jetTracks = "ak5PFJetTracksAssociatorAtVertex"
)

process.standardSecondaryVertexPFTagInfos = process.secondaryVertexTagInfos.clone(
  trackIPTagInfos = "standardImpactParameterPFTagInfos"
)

process.standardSecondaryVertex3TrkPFTagInfos = process.standardSecondaryVertexPFTagInfos.clone()
process.standardSecondaryVertex3TrkPFTagInfos.vertexCuts.multiplicityMin = 3

process.standardGhostTrackVertexPFTagInfos = process.standardSecondaryVertexPFTagInfos.clone()
process.standardGhostTrackVertexPFTagInfos.vertexReco = process.ghostTrackVertexRecoBlock.vertexReco
process.standardGhostTrackVertexPFTagInfos.vertexCuts.multiplicityMin = 1

process.standardCombinedSecondaryVertexPF = process.combinedSecondaryVertex.clone()
process.standardCombinedSecondaryVertex3TrkPF = process.combinedSecondaryVertex.clone()

process.standardSecondaryVertexV0PFTagInfos = process.standardSecondaryVertexPFTagInfos.clone()
process.standardSecondaryVertexV0PFTagInfos.vertexCuts.v0Filter = cms.PSet(k0sMassWindow = cms.double(-1.0))

process.standardCombinedSecondaryVertexV0PF = process.standardCombinedSecondaryVertexPF.clone()
process.standardCombinedSecondaryVertexV0PF.trackPairV0Filter = cms.PSet(k0sMassWindow = cms.double(-1.0))
process.standardCombinedSecondaryVertexV0PF.pseudoVertexV0Filter = cms.PSet(k0sMassWindow = cms.double(-1.0)) 
process.standardCombinedSecondaryVertexV0PF.trackMultiplicityMin = 2


process.standardTrackCountingHighEffPFBJetTags = process.trackCountingHighEffBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"))
)


process.standardTrackCountingHighPurPFBJetTags = process.trackCountingHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"))
)

process.standardJetProbabilityPFBJetTags = process.jetProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos")) 
)

process.standardJetBProbabilityPFBJetTags = process.jetBProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos")) 
)

process.standardSimpleSecondaryVertexHighEffPFBJetTags = process.simpleSecondaryVertexHighEffBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.standardSimpleSecondaryVertexHighPurPFBJetTags = process.simpleSecondaryVertexHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.standardGhostTrackPFBJetTags = process.ghostTrackBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"),
	                         cms.InputTag("standardGhostTrackVertexPFTagInfos"))
)

process.standardCombinedSecondaryVertexPFBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  jetTagComputer = cms.string('standardCombinedSecondaryVertexPF'),
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"),
                           cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.standardCombinedSecondaryVertexMVAPFBJetTags = process.combinedSecondaryVertexMVABJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"),
                           cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.standardSoftMuonPFTagInfos = process.softMuonTagInfos.clone(
  jets = "ak5PFJetsJEC"
)

process.standardSoftElectronPFTagInfos = process.softElectronTagInfos.clone(
  jets = "ak5PFJetsJEC"
)

process.standardSoftMuonPFBJetTags = process.softMuonBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonPFTagInfos"))
)

process.standardSoftMuonByPtPFBJetTags = process.softMuonByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonPFTagInfos"))
)

process.standardSoftMuonByIP3dPFBJetTags = process.softMuonByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonPFTagInfos"))
)

process.standardSoftElectronByPtPFBJetTags = process.softElectronByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftElectronPFTagInfos"))
)

process.standardSoftElectronByIP3dPFBJetTags = process.softElectronByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftElectronPFTagInfos"))
)

########### MC truth flavour matching ###########
process.load("PhysicsTools.JetMCAlgos.CaloJetsMCFlavour_cfi")

process.AK5PFbyRef = process.AK5byRef.clone(
  jets = "ak5PFJetsJEC"
)
process.AK5PFbyValAlgo = process.AK5byValAlgo.clone(
  srcByReference = "AK5PFbyRef"
)

process.flavourSeq = cms.Sequence(
    process.myPartons *
    process.AK5PFbyRef *
    process.AK5PFbyValAlgo )
########### Generation Level Jet Matching ###########
#stole from PAT
process.load("PhysicsTools.PatAlgos.mcMatchLayer0.jetMatch_cfi")
process.patJetGenJetMatch.src = "ak5PFJetsJEC"

########### Dump contents into ntuple ###########
process.load("bTag.CommissioningCommonSetup.tagntupleproducer_cfi")

process.standardPFBTagNtuple = process.bTagNtuple.clone()
process.standardPFBTagNtuple.jetSrc = cms.InputTag( "ak5PFJetsJEC" )
process.standardPFBTagNtuple.svComputer = cms.InputTag( "standardCombinedSecondaryVertexPF" )
process.standardPFBTagNtuple.TriggerTag = cms.InputTag( "TriggerResults::"+HLTProc)
process.standardPFBTagNtuple.TriggerSelection = TriggerSelections
process.standardPFBTagNtuple.flavorHistory = cms.InputTag("flavorHistoryFilter")
process.standardPFBTagNtuple.getSharedHitInfo = cms.bool(False)
process.standardPFBTagNtuple.jetMCSrc = cms.InputTag( "AK5PFbyValAlgo" )
#set this to FALSE for 39X samples, set it to TRUE for 3_11 samples
process.standardPFBTagNtuple.HepMCTag = cms.untracked.InputTag( "generator" )
process.standardPFBTagNtuple.BSTag = cms.InputTag( "offlineBeamSpot" )
process.standardPFBTagNtuple.SimTruthTag = cms.untracked.InputTag( "g4SimHits" )
process.standardPFBTagNtuple.jetTracks = cms.InputTag( "ak5PFJetTracksAssociatorAtVertex" )
process.standardPFBTagNtuple.SVTagInfos = cms.InputTag( "standardSecondaryVertexPFTagInfos" )
process.standardPFBTagNtuple.IPTagInfos = cms.InputTag( "standardImpactParameterPFTagInfos" )
process.standardPFBTagNtuple.ElectronTagInfos = cms.InputTag( "standardSoftElectronPFTagInfos" )
process.standardPFBTagNtuple.MuonTagInfos = cms.InputTag( "standardSoftMuonPFTagInfos" )
process.standardPFBTagNtuple.Label = cms.string("standardPF")
process.standardPFBTagNtuple.GenJetMatcher = cms.InputTag("patJetGenJetMatch")
process.standardPFBTagNtuple.filename = cms.string("standardPFNtuple.root")
process.standardPFBTagNtuple.TrackMCTruthMatchChi2Cut = cms.double(1E9)
process.standardPFBTagNtuple.bTagConfig = cms.VPSet(
    cms.PSet(
    alias = cms.string("standardTrackCountingHighEffPFBJetTags"),
    label = cms.InputTag("standardTrackCountingHighEffPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardTrackCountingHighPurPFBJetTags"),
    label = cms.InputTag("standardTrackCountingHighPurPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardJetProbabilityPFBJetTags"),
    label = cms.InputTag("standardJetProbabilityPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardJetBProbabilityPFBJetTags"),
    label = cms.InputTag("standardJetBProbabilityPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSimpleSecondaryVertexHighEffPFBJetTags"),
    label = cms.InputTag("standardSimpleSecondaryVertexHighEffPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSimpleSecondaryVertexHighPurPFBJetTags"),
    label = cms.InputTag("standardSimpleSecondaryVertexHighPurPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardCombinedSecondaryVertexPFBJetTags"),
    label = cms.InputTag("standardCombinedSecondaryVertexPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardGhostTrackPFBJetTags"),
    label = cms.InputTag("standardGhostTrackPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardCombinedSecondaryVertexMVAPFBJetTags"),
    label = cms.InputTag("standardCombinedSecondaryVertexMVAPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSoftMuonPFBJetTags"),
    label = cms.InputTag("standardSoftMuonPFBJetTags")
    ),
    cms.PSet(
    alias = cms.string("standardSoftMuonByIP3dPFBJetTags"),
    label = cms.InputTag("standardSoftMuonByIP3dPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSoftMuonByPtPFBJetTags"),
    label = cms.InputTag("standardSoftMuonByPtPFBJetTags")
    ),
    cms.PSet(
    alias = cms.string("standardSoftElectronByIP3dPFBJetTags"),
    label = cms.InputTag("standardSoftElectronByIP3dPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSoftElectronByPtPFBJetTags"),
    label = cms.InputTag("standardSoftElectronByPtPFBJetTags")
    )
    )

process.svTagInfos = cms.Sequence(
    process.standardSecondaryVertexPFTagInfos +
    process.standardSecondaryVertexV0PFTagInfos + 
    process.standardSecondaryVertex3TrkPFTagInfos +
    process.standardGhostTrackVertexPFTagInfos 
)

process.ipTaggers = cms.Sequence(
    process.standardTrackCountingHighEffPFBJetTags +
    process.standardTrackCountingHighPurPFBJetTags +
    process.standardJetProbabilityPFBJetTags +
    process.standardJetBProbabilityPFBJetTags 
)

process.svTaggers = cms.Sequence(
    process.standardSimpleSecondaryVertexHighEffPFBJetTags +
    process.standardSimpleSecondaryVertexHighPurPFBJetTags +
    process.standardGhostTrackPFBJetTags +
    process.standardCombinedSecondaryVertexPFBJetTags +
    process.standardCombinedSecondaryVertexMVAPFBJetTags 
)

process.slTagInfos = cms.Sequence(
    process.standardSoftMuonPFTagInfos +
    process.softElectronCands+
    process.standardSoftElectronPFTagInfos
)

process.slTaggers = cms.Sequence(
    process.standardSoftMuonPFBJetTags +
    process.standardSoftMuonByPtPFBJetTags +
    process.standardSoftMuonByIP3dPFBJetTags +
    process.standardSoftElectronByPtPFBJetTags +
    process.standardSoftElectronByIP3dPFBJetTags 
)


process.plots = cms.Path(
#  process.pthat_filter+
  process.JetHLTFilter +
  process.noscraping +
  process.offlinePrimaryVertices *
  process.oneGoodVertexFilter +
  process.flavorHistorySeq +
  process.PFJetsFilter *
  process.ak5PFJetsJEC *
  process.ak5PFJetTracksAssociatorAtVertex  *
  process.standardImpactParameterPFTagInfos  *
  process.svTagInfos *
  process.ipTaggers *
  process.svTaggers *
  process.slTagInfos *
  process.slTaggers *
  process.flavourSeq *
  process.patJetGenJetMatch *
  process.standardPFBTagNtuple 
)

## Added for getting the L1 and HLT summary report
process.options = cms.untracked.PSet(
  wantSummary = cms.untracked.bool(True)
)

process.MessageLogger.categories.append('L1GtTrigReport')
process.MessageLogger.categories.append('HLTrigReport')
process.MessageLogger.cerr.FwkReport.reportEvery = 500
process.MessageLogger.cerr.threshold = cms.untracked.string('ERROR')

import sys,os,datetime,re

if __name__ == '__main__' and 'submit' in sys.argv:
    castorhome_=os.getenv("CASTOR_HOME")
    home_=os.getenv("HOME")
    castorhome_=castorhome_.replace("/castor/cern.ch/","")
    time=datetime.datetime.now().strftime("%d%b%Y")
    new_py = open('bTagNtupleMaker.py').read()
    needdel = re.match(r".*(\nimport sys,os,datetime,re.*)", new_py, re.DOTALL)
    new_py = new_py.replace(needdel.group(1),"")
    new_py = re.sub("input = cms.untracked.int32(.*)",
                    "input = cms.untracked.int32(-1)",
                    new_py)
    for dataset_ in DATALIST:
        dirname_=dataset_.split("/")
        if "Run20" not in dataset_:
            jobcontrol_='''
total_number_of_events = -1
number_of_jobs = 128
'''
            dirname_ = re.sub("_Tune.*", "",dirname_[1])
            dirname_=time+"_"+dirname_
            new_py = re.sub("process.GlobalTag.globaltag = autoCond\[.*\]",
                            "process.GlobalTag.globaltag = autoCond['startup']",
                            new_py)
        else:
            jobcontrol_='''
lumi_mask=/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions11/7TeV/Prompt/Cert_160404-180252_7TeV_PromptReco_Collisions11_JSON.txt
total_number_of_lumis = -1
number_of_jobs = 300
'''
            dirname_=time+"_"+dirname_[1]+"_"+dirname_[2]
            new_py = re.sub("process.GlobalTag.globaltag = autoCond\[.*\]",
                            "process.GlobalTag.globaltag = autoCond['com10']",
                            new_py)
            new_py = new_py.replace("  process.flavorHistorySeq +\n","")
            new_py = new_py.replace("  process.flavourSeq *\n","")
            new_py = new_py.replace("  process.patJetGenJetMatch *\n","")
        crab_cfg = '''
[CRAB]
jobtype = cmssw
scheduler = glite

[CMSSW]
datasetpath = %(dataset_)s
pset = bTagNtupleMaker_crab.py
output_file = standardPFNtuple.root
%(jobcontrol_)s

[USER]
ui_working_dir = %(home_)s/scratch0/crab_bTaggingNtuple_%(dirname_)s
return_data = 0
copy_data = 1
storage_element=srm-cms.cern.ch
storage_path=/srm/managerv2?SFN=/castor/cern.ch
user_remote_dir = %(castorhome_)s/bTaggingNtuple_%(dirname_)s
publish_data=0
''' % locals()
        open('crab.cfg', 'wt').write(crab_cfg)
        open('bTagNtupleMaker_crab.py', 'wt').write(new_py)
        if 'test' not in sys.argv:
            os.system('crab -create -submit all')
            os.system('rm crab.cfg')
            os.system('rm bTagNtupleMaker_crab.py')



