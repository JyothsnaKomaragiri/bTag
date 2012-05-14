#########################
#####    Settings   #####
#########################
DATALIST=[
#"/QCD_Pt-15to30_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v3/AODSIM",
#"/QCD_Pt-30to50_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v3/AODSIM",
#"/QCD_Pt-50to80_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v2/AODSIM"
#"/QCD_Pt-80to120_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v3/AODSIM",
#"/QCD_Pt-120to170_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM",
#"/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM",
#"/QCD_Pt-300to470_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM",
#"/QCD_Pt-470to600_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM",
#"/QCD_Pt-600to800_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM",
#"/QCD_Pt-800to1000_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM"
#"/QCD_Pt-15to30_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-30to50_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-50to80_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-80to120_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-120to170_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-300to470_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-470to600_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-600to800_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG",
#"/QCD_Pt-800to1000_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START44_V5-v1/GEN-SIM-RECODEBUG"
#"/QCD_Pt-120to170_TuneZ2_7TeV_pythia6/Fall11-PU_S6-START44_V5-v1/AODSIM",
#"/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/Fall11-PU_S6_START42_V14B-v1/AODSIM",
#"/QCD_Pt-300to470_TuneZ2_7TeV_pythia6/Fall11-PU_S6-START44_V5-v1/AODSIM",
#"/QCD_Pt-15to3000_TuneZ2_Flat_7TeV_pythia6/Fall11-Peak32PU_START42_V14B-v1/GEN-SIM-RECO",
#"/Jet/Run2011B-PromptReco-v1/AOD",
#"/Jet/Run2012A-PromptReco-v1/AOD",
#"/BTag/Run2012A-PromptReco-v1/AOD",
"/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/Summer12-NoPileUp_START52_V9-v5/AODSIM",
"/QCD_Pt-15to3000_TuneZ2star_Flat_8TeV_pythia6/Summer12-PU_S7_START52_V5-v1/AODSIM"
          ]
HLTProc="HLT"
runOnMC = True
usePFnoPU = True

import FWCore.ParameterSet.Config as cms

#JetSelection
JetCut=cms.string("pt > 30.0 && abs(eta) < 2.4 && neutralHadronEnergyFraction < 0.99 && neutralEmEnergyFraction < 0.99 && nConstituents > 1 && chargedHadronEnergyFraction > 0.0 && chargedMultiplicity > 0.0 && chargedEmEnergyFraction < 0.99")

# It will select the events based on the TriggerSelections. The ntuple will only save the triggers whose name matches any entry in TriggerSelections
TriggerSelections=cms.vstring("HLT_*Jet*")

############################
###    Main Program   ######
############################
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
#from Configuration.PyReleaseValidation.autoCond import autoCond  # for <CMSSW_4_3_0
from Configuration.AlCa.autoCond import autoCond # for >=CMSSW_4_3_0

if runOnMC:
  process.GlobalTag.globaltag = autoCond['startup']
else:
  process.GlobalTag.globaltag = autoCond['com10']

process.source = cms.Source("PoolSource",
#    fileNames = cms.untracked.vstring("rfio:/castor/cern.ch/user/z/zhangjin/Test_Chamonix_TTbar_AODSIM.root")
#                            fileNames = cms.untracked.vstring("rfio:/castor/cern.ch/user/k/kkaadze/BTagging/QCD_Fall11_44_Pt80to120_RECODEBUG.root")
                           fileNames = cms.untracked.vstring("file:/afs/cern.ch/user/z/zhangjin/MetaData/Test_Summer12_QCD15to3000.root")
#    fileNames = cms.untracked.vstring("rfio:/dpm/in2p3.fr/home/cms/phedex/store/data/Run2012A/Jet/AOD/PromptReco-v1/000/190/934/304B8EF5-CE85-E111-B4DF-003048F110BE.root")
#    fileNames = cms.untracked.vstring("file:/storage1/cms/jandrea/425MC/TTJets_TuneZ2_7TeV/TTJets_TuneZ2_7TeV/NTuple_67_1_HhM.root")
#fileNames = cms.untracked.vstring("file:/afs/cern.ch/user/z/zhangjin/MetaData/Test_Jet_Run2011B_AOD.root",
#                                  "file:/afs/cern.ch/user/z/zhangjin/MetaData/Test_Jet_Run2011B_AOD_2.root")
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
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

########### Event cleaning ###########
#Require a good vertex

from PhysicsTools.SelectorUtils.pvSelector_cfi import pvSelector

process.goodOfflinePrimaryVertices = cms.EDFilter(
    "PrimaryVertexObjectFilter",
    filterParams = pvSelector.clone( minNdof = cms.double(4.0), maxZ = cms.double(24.0) ),
    src=cms.InputTag('offlinePrimaryVertices')
    )
    
    
process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi")
process.primaryVertexFilter = cms.EDFilter("GoodVertexFilter",
                      vertexCollection = cms.InputTag('offlinePrimaryVertices'),
                      minimumNDOF = cms.uint32(4) ,
 		      maxAbsZ = cms.double(24), 
 		      maxd0 = cms.double(2)	
                     )


#Filter for removing scraping events
process.noscraping = cms.EDFilter("FilterOutScraping",
                                applyfilter = cms.untracked.bool(True),
                                debugOn = cms.untracked.bool(False),
                                numtrack = cms.untracked.uint32(10),
                                thresh = cms.untracked.double(0.25)
                                )
				
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')

process.ak5PFJetsJEC = process.ak5PFJetsL2L3.clone(
    src = 'ak5PFJets', 
    correctors = ['ak5PFL2L3']
)

process.PFJetsFilter = cms.EDFilter("PFJetSelector",
  src = cms.InputTag("ak5PFJetsJEC"),
  cut = JetCut,
  filter = cms.bool(True)
)

#Filter to remove pthat>15 events in MinBias samples
process.pthat_filter = cms.EDFilter("MCProcessFilter",
	  MaxPthat = cms.untracked.vdouble(15.0),
	  ProcessID = cms.untracked.vint32(0),
	  MinPthat = cms.untracked.vdouble(1.0)
)

process.load("PhysicsTools.HepMCCandAlgos.flavorHistoryPaths_cfi")

########### Jet selection and JEC use PFtoPAT and PFnoPU ###########
#JetID

if usePFnoPU :
    process.out = cms.OutputModule("PoolOutputModule",
                                   outputCommands = cms.untracked.vstring('drop *'),
                                   fileName = cms.untracked.string('EmptyFile.root')
                                   )
    process.load("PhysicsTools.PatAlgos.patSequences_cff")
    from PhysicsTools.PatAlgos.tools.pfTools import *
    postfix="PF2PAT"
    usePF2PAT(process,runPF2PAT=True, jetAlgo="AK5", runOnMC=runOnMC, postfix=postfix) 
    applyPostfix(process,"patJetCorrFactors",postfix).payload = cms.string('AK5PFchs')
    process.pfPileUpPF2PAT.Enable = True
    process.pfPileUpPF2PAT.Vertices = cms.InputTag('goodOfflinePrimaryVertices')
    process.selectedPatJetsPF2PAT.cut = JetCut
    process.JECAlgo = cms.Sequence( getattr(process,"patPF2PATSequence"+postfix) )
    JetID=cms.InputTag("selectedPatJetsPF2PAT")
else:
    process.JECAlgo = cms.Sequence( process.ak5PFJetsJEC*process.PFJetsFilter )
    JetID=cms.InputTag("PFJetsFilter")

########### Rerun b-tagging for PF Jets ###########
process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")

process.ak5PFJetTracksAssociatorAtVertex = cms.EDProducer("JetTracksAssociatorAtVertex",
   process.j2tParametersVX,
   jets = JetID
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
  jets = JetID
)

process.standardSoftElectronPFTagInfos = process.softElectronTagInfos.clone(
  jets = JetID
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
  jets = JetID
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
process.patJetGenJetMatch.src = JetID

########### Dump contents into ntuple ###########
process.load("bTag.CommissioningCommonSetup.tagntupleproducer_cfi")

process.standardPFBTagNtuple = process.bTagNtuple.clone()
process.standardPFBTagNtuple.jetSrc = JetID
process.standardPFBTagNtuple.svComputer = cms.InputTag( "standardCombinedSecondaryVertexPF" )
process.standardPFBTagNtuple.TriggerTag = cms.InputTag( "TriggerResults::"+HLTProc)
process.standardPFBTagNtuple.TriggerSelection = TriggerSelections
process.standardPFBTagNtuple.flavorHistory = cms.InputTag("flavorHistoryFilter")
process.standardPFBTagNtuple.getSharedHitInfo = cms.bool(False)
process.standardPFBTagNtuple.jetMCSrc = cms.InputTag( "AK5PFbyValAlgo" )
#set this to FALSE for 39X samples, set it to TRUE for 3_11 samplesstandardPFNtuple.root
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
process.standardPFBTagNtuple.TrackMCTruthMatchChi2Cut = cms.double(25)
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

if runOnMC:
  process.GenHistory = cms.Sequence(
#    process.pthat_filter+
    process.flavorHistorySeq *
    process.flavourSeq *
    process.patJetGenJetMatch
    )
else:
  process.GenHistory = cms.Sequence()

process.plots = cms.Path( 
  process.noscraping + 
  process.JetHLTFilter + 
  process.offlinePrimaryVertices *
  process.goodOfflinePrimaryVertices *
  process.primaryVertexFilter +
  process.JECAlgo*
  process.GenHistory +
  process.ak5PFJetTracksAssociatorAtVertex  *
  process.standardImpactParameterPFTagInfos  *
  process.svTagInfos *
  process.ipTaggers *
  process.svTaggers *
  process.slTagInfos *
  process.slTaggers *
  process.standardPFBTagNtuple 
  )

## Added for getting the L1 and HLT summary report
process.options = cms.untracked.PSet(
  wantSummary = cms.untracked.bool(True)
)

process.MessageLogger.categories.append('L1GtTrigReport')
process.MessageLogger.categories.append('HLTrigReport')
process.MessageLogger.cerr.FwkReport.reportEvery = 500
process.MessageLogger.cerr.threshold = cms.untracked.string('WARNING')

import sys,os,datetime,re

if sys.argv[0] != "cmsRun":
    castorhome_=os.getenv("CASTOR_HOME")
    home_=os.getenv("HOME")
    castorhome_=castorhome_.replace("/castor/cern.ch/","")
    time=datetime.datetime.now().strftime("%d%b%Y")
    for dataset_ in DATALIST:
        new_py = open('bTagNtupleMaker.py').read()
        needdel = re.match(r".*(\nimport sys,os,datetime,re.*)", new_py, re.DOTALL)
        new_py = new_py.replace(needdel.group(1),"")
        crab_py_start_index=new_py.find(']')
        crab_py_end_index=new_py.rfind("\nimport sys,os,datetime,re")
        new_py = new_py[crab_py_start_index+1:crab_py_end_index]
        new_py = re.sub("input = cms.untracked.int32(.*)",
                        "input = cms.untracked.int32(-1)",
                        new_py)
        dirname_=dataset_.split("/")
        if "Run20" not in dataset_:
            print 'Submitting %s as MC' % dataset_
            jobcontrol_='''
total_number_of_events = -1
number_of_jobs = 128
'''
#            dirname_ = re.sub("_Tune.*", "",dirname_[1])
            dirname_=time+"_"+dirname_[1]+"_"+dirname_[2]
            new_py = re.sub("runOnMC = .*\n",
                            "runOnMC = True\n",
                            new_py)
        else:
            print 'Submitting %s as DATA' % dataset_
            jobcontrol_='''
lumi_mask=/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions12/8TeV/DCSOnly/json_DCSONLY.txt
/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions11/7TeV/Prompt/Cert_160404-180252_7TeV_PromptReco_Collisions11_JSON.txt
total_number_of_lumis = -1
number_of_jobs = 40
'''
            dirname_=time+"_"+dirname_[1]+"_"+dirname_[2]
            new_py = re.sub("runOnMC = .*\n",
                            "runOnMC = False\n",
                            new_py)
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
        if 'submit' in sys.argv:
            os.system('crab -create -submit all')
            os.system('rm crab.cfg')
            os.system('rm bTagNtupleMaker_crab.py')
