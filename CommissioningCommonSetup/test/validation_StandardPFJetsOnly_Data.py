import FWCore.ParameterSet.Config as cms

import RecoBTag.SoftLepton.muonSelection
from DQMOffline.RecoB.bTagCombinedSVVariables_cff import *
#includes added because of block refactoring replacing simple includes by using statements
from DQMOffline.RecoB.bTagTrackIPAnalysis_cff import *
from DQMOffline.RecoB.bTagCombinedSVAnalysis_cff import *
from DQMOffline.RecoB.bTagTrackCountingAnalysis_cff import *
from DQMOffline.RecoB.bTagTrackProbabilityAnalysis_cff import *
from DQMOffline.RecoB.bTagTrackBProbabilityAnalysis_cff import *
from DQMOffline.RecoB.bTagGenericAnalysis_cff import *
from DQMOffline.RecoB.bTagSimpleSVAnalysis_cff import *
from DQMOffline.RecoB.bTagSoftLeptonAnalysis_cff import *
from DQMOffline.RecoB.bTagSoftLeptonByPtAnalysis_cff import *
from DQMOffline.RecoB.bTagSoftLeptonByIPAnalysis_cff import *

process = cms.Process("validation")
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.load("DQMServices.Components.DQMEnvironment_cfi")

#keep the logging output to a nice level
process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("DQMServices.Core.DQM_cfg")

process.load("RecoBTag.Configuration.RecoBTag_cff")

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#Global tag for 3_6_1
process.GlobalTag.globaltag = 'GR_R_36X_V12A::All'

process.load('L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff')
from HLTrigger.HLTfilters.hltLevel1GTSeed_cfi import hltLevel1GTSeed
#Good Bunch Crossings
process.bptxAnd = hltLevel1GTSeed.clone(L1TechTriggerSeeding = cms.bool(True), L1SeedsLogicalExpression = cms.string('0'))
#BSCNOBEAMHALO
process.bit40 = hltLevel1GTSeed.clone(L1TechTriggerSeeding = cms.bool(True), L1SeedsLogicalExpression = cms.string('(40 OR 41) AND NOT (36 OR 37 OR 38 OR 39) AND NOT ((42 AND NOT 43) OR (43 AND NOT 42))'))

#Physics-declared Bit
from HLTrigger.HLTfilters.hltHighLevelDev_cfi import hltHighLevelDev
process.physDecl = hltHighLevelDev.clone(HLTPaths = ['HLT_PhysicsDeclared'], HLTPathsPrescales = [1])

#Select events based on the HLT triggers (HLT_L1Jet6U || HLT_L1Jet10U || HLT_Jet15U)
# Use the instructions provided at:
# http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/CMSSW/HLTrigger/HLTfilters/python/hltHighLevel_cfi.py?hideattic=1&revision=1.5&view=markup
import HLTrigger.HLTfilters.hltHighLevel_cfi
process.singleJetHLTFilter = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.singleJetHLTFilter.TriggerResultsTag = cms.InputTag("TriggerResults","","HLT")
process.singleJetHLTFilter.HLTPaths = ["HLT_L1Jet6U", "HLT_L1Jet10U", "HLT_Jet15U"]
process.singleJetHLTFilter.andOr = cms.bool(True) # how to deal with multiple triggers: True (OR) accept if ANY is true, False (AND) accept if ALL are true

import HLTrigger.HLTfilters.hltHighLevel_cfi
process.HLT_Jet15U = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.HLT_Jet15U.TriggerResultsTag = cms.InputTag("TriggerResults","","HLT")
process.HLT_Jet15U.HLTPaths = ["HLT_Jet15U"]
process.HLT_Jet15U.andOr = cms.bool(True) # how to deal with multiple triggers: True (OR) accept if ANY is true, False (AND) accept if ALL are true

#Require a good vertex
process.oneGoodVertexFilter = cms.EDFilter("VertexSelector",
   src = cms.InputTag("offlinePrimaryVertices"),
   cut = cms.string("!isFake && ndof > 4 && abs(z) <= 15 && position.Rho <= 2"),
   filter = cms.bool(True),   # otherwise it won't filter the events, just produce an empty vertex collection.
)

# JEC for both ak5PF and Calo jets
process.load('JetMETCorrections.Configuration.DefaultJEC_cff')

#Filter for PFJets
process.PFJetsFilter = cms.EDFilter("PFJetSelector",
  src = cms.InputTag("ak5PFJetsL2L3"),
  cut = cms.string("pt > 10.0 && abs(eta) < 2.5 && neutralHadronEnergyFraction < 1.0 && neutralEmEnergyFraction < 1.0 && nConstituents > 1 && chargedHadronEnergyFraction > 0.0 && chargedMultiplicity > 0.0 && chargedEmEnergyFraction < 1.0"),
  filter = cms.bool(True)
)



#Filter for removing scraping events
process.noscraping = cms.EDFilter("FilterOutScraping",
                                applyfilter = cms.untracked.bool(True),
                                debugOn = cms.untracked.bool(False),
                                numtrack = cms.untracked.uint32(10),
                                thresh = cms.untracked.double(0.25)
                                )

process.load("RecoJets.JetAssociationProducers.ak5JTA_cff")

process.ak5PFJetTracksAssociatorAtVertex = cms.EDProducer("JetTracksAssociatorAtVertex",
   process.j2tParametersVX,
   jets = cms.InputTag("PFJetsFilter")
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
  jets = "PFJetsFilter"
)


process.standardSoftElectronPFTagInfos = process.softElectronTagInfos.clone(
  jets = "PFJetsFilter"
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

process.load("DQMOffline.RecoB.bTagAnalysisData_cfi")
process.pfBTagAnalysis = process.bTagAnalysis.clone()
process.pfBTagAnalysis.tagConfig = cms.VPSet(
        cms.PSet(
            bTagTrackIPAnalysisBlock,
            type = cms.string('TrackIP'),
            label = cms.InputTag("standardImpactParameterPFTagInfos")
        ), 
        cms.PSet(
            bTagCombinedSVAnalysisBlock,
            ipTagInfos = cms.InputTag("standardImpactParameterPFTagInfos"),
            type = cms.string('GenericMVA'),
            svTagInfos = cms.InputTag("standardSecondaryVertexPFTagInfos"),
            label = cms.InputTag("standardCombinedSecondaryVertexPF")
        ), 
        cms.PSet(
            bTagCombinedSVAnalysisBlock,
            ipTagInfos = cms.InputTag("standardImpactParameterPFTagInfos"),
            type = cms.string('GenericMVA'),
            svTagInfos = cms.InputTag("standardSecondaryVertexV0PFTagInfos"),
            label = cms.InputTag("standardCombinedSecondaryVertexV0PF")
        ), 
        cms.PSet(
            bTagCombinedSVAnalysisBlock,
            ipTagInfos = cms.InputTag("standardImpactParameterPFTagInfos"),
            type = cms.string('GenericMVA'),
            svTagInfos = cms.InputTag("standardSecondaryVertex3TrkPFTagInfos"),
            label = cms.InputTag("standardCombinedSecondaryVertex3TrkPF")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("standardTrackCountingHighEffPFBJetTags")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("standardTrackCountingHighPurPFBJetTags")
        ), 
        cms.PSet(
            bTagProbabilityAnalysisBlock,
            label = cms.InputTag("standardJetProbabilityPFBJetTags")
        ), 
        cms.PSet(
            bTagBProbabilityAnalysisBlock,
            label = cms.InputTag("standardJetBProbabilityPFBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("standardSimpleSecondaryVertexHighEffPFBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("standardSimpleSecondaryVertexHighPurPFBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("standardGhostTrackPFBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("standardCombinedSecondaryVertexPFBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("standardCombinedSecondaryVertexMVAPFBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            label = cms.InputTag("standardSoftMuonPFBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("standardSoftMuonByIP3dPFBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("standardSoftMuonByPtPFBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("standardSoftElectronByIP3dPFBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("standardSoftElectronByPtPFBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("standardSoftMuonPFTagInfos")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("standardSoftElectronPFTagInfos")
        ) 
)
process.pfBTagAnalysis.tagConfig[2].parameters.categories[0].vertexMass.min = 0.3
process.pfBTagAnalysis.tagConfig[2].parameters.categories[0].vertexMass.max = 0.8
process.pfBTagAnalysis.tagConfig[2].parameters.categories[1].vertexMass.min = 0.3
process.pfBTagAnalysis.tagConfig[2].parameters.categories[1].vertexMass.max = 0.8
process.pfBTagAnalysis.tagConfig[2].parameters.categories[2].vertexMass.min = 0.3
process.pfBTagAnalysis.tagConfig[2].parameters.categories[2].vertexMass.max = 0.8
for i in range(4, 17):
  for j in range(i + 1, 17):
    process.pfBTagAnalysis.tagConfig.append(
      cms.PSet(
        type = cms.string("TagCorrelation"),
        label1 = process.pfBTagAnalysis.tagConfig[i].label,
        label2 = process.pfBTagAnalysis.tagConfig[j].label,
        parameters = cms.PSet(
          CreateProfile = cms.bool(True),
          Discr1Start = process.pfBTagAnalysis.tagConfig[i].parameters.discriminatorStart,
          Discr1End = process.pfBTagAnalysis.tagConfig[i].parameters.discriminatorEnd,
          Discr2Start = process.pfBTagAnalysis.tagConfig[j].parameters.discriminatorStart,
          Discr2End = process.pfBTagAnalysis.tagConfig[j].parameters.discriminatorEnd
        )
      )
    )

process.load("bTag.CommissioningCommonSetup.tagntupleproducer_cfi")


process.standardPFBTagNtuple = process.bTagNtuple.clone()
process.standardPFBTagNtuple.getMCTruth = cms.bool(False)
process.standardPFBTagNtuple.jetSrc = cms.InputTag( "PFJetsFilter" )
process.standardPFBTagNtuple.svComputer = cms.InputTag( "standardCombinedSecondaryVertexPF" )
process.standardPFBTagNtuple.TriggerTag = cms.InputTag( "TriggerResults::HLT")
process.standardPFBTagNtuple.jetMCSrc = cms.InputTag( "" )
process.standardPFBTagNtuple.jetTracks = cms.InputTag( "ak5PFJetTracksAssociatorAtVertex" )
process.standardPFBTagNtuple.SVTagInfos = cms.InputTag( "standardSecondaryVertexPFTagInfos" )
process.standardPFBTagNtuple.IPTagInfos = cms.InputTag( "standardImpactParameterPFTagInfos" )
process.standardPFBTagNtuple.ElectronTagInfos = cms.InputTag( "standardSoftElectronPFTagInfos" )
process.standardPFBTagNtuple.MuonTagInfos = cms.InputTag( "standardSoftMuonPFTagInfos" )
process.standardPFBTagNtuple.Label = cms.string("standardPF")
process.standardPFBTagNtuple.filename = cms.string("standardPFNtuple.root")
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
    alias = cms.string("standardGhostTrackPFBJetTags"),
    label = cms.InputTag("standardGhostTrackPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardCombinedSecondaryVertexPFBJetTags"),
    label = cms.InputTag("standardCombinedSecondaryVertexPFBJetTags")
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


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(

'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile1.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile2.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile3.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile4.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile5.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile6.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile7.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile8.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile9.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile10.root',
'file:/nfs/data6/alschmid/SVAnalysis/OnData/CMSSW_3_6_1_patch4/src/bTag/CommissioningCommonSetup/test/DataTestFile11.root'
  
#   '/store/data/Commissioning10/MinimumBias/RECO/May27thReReco_of_valskim_PreProduction_v2/0165/FEA3BECA-7569-DF11-86FA-002354EF3BD2.root',
#        '/store/data/Commissioning10/MinimumBias/RECO/May27thReReco_of_valskim_PreProduction_v2/0165/FE6FE723-7369-DF11-AF74-0026189438ED.root',
#        '/store/data/Commissioning10/MinimumBias/RECO/May27thReReco_of_valskim_PreProduction_v2/0165/FE4EF777-7669-DF11-8546-0018F3D09636.root',
#        '/store/data/Commissioning10/MinimumBias/RECO/May27thReReco_of_valskim_PreProduction_v2/0165/FE243325-7669-DF11-8CA4-0018F3D09636.root',
#        '/store/data/Commissioning10/MinimumBias/RECO/May27thReReco_of_valskim_PreProduction_v2/0165/FE18F74E-7669-DF11-943A-0026189438A5.root',
#        '/store/data/Commissioning10/MinimumBias/RECO/May27thReReco_of_valskim_PreProduction_v2/0165/FCC4F3A4-7469-DF11-9882-002618943977.root' 
  )
)

process.EDM = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('drop *',
                       "keep *_*_*_validation",
                       "keep recoTracks_generalTracks_*_*",
                       "keep recoTracks_globalMuons_*_*",
                       "keep *_offlineBeamSpot_*_*",
                       "keep *_gsfElectrons_*_*",
                       "keep recoMuons_muons_*_*",
                       "keep *_softPFElectrons_*_*",
                       "keep recoGsfTracks_electronGsfTracks_*_*",
                       "keep *_TriggerResults_*_*",
                       "keep *_offlinePrimaryVertices_*_*"
    ),
    fileName = cms.untracked.string('BTagCommissioning2010_April20_7TeV_Data_PromptReco_v8.root'),
#    SelectEvents = cms.untracked.PSet(
#       SelectEvents = cms.vstring("plots")
#    )
)

process.load("DQMServices.Components.MEtoEDMConverter_cfi")


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
    process.softElectronCands * (
    process.standardSoftElectronPFTagInfos 
    )
)

process.slTaggers = cms.Sequence(
    process.standardSoftMuonPFBJetTags +
    process.standardSoftMuonByPtPFBJetTags +
    process.standardSoftMuonByIP3dPFBJetTags +
    process.standardSoftElectronByPtPFBJetTags +
    process.standardSoftElectronByIP3dPFBJetTags 
)


process.plots = cms.Path(
  process.bit40 +
  process.bptxAnd +
#  process.physDecl +
  process.singleJetHLTFilter +
  process.noscraping +
  process.oneGoodVertexFilter +
  process.ak5PFJetsL2L3 *
  cms.ignore(process.PFJetsFilter) *
  process.ak5PFJetTracksAssociatorAtVertex  *
  process.standardImpactParameterPFTagInfos  *
  process.svTagInfos *
  process.ipTaggers *
  process.svTaggers *
  process.slTagInfos *
  process.slTaggers *
  process.standardPFBTagNtuple *
  process.HLT_Jet15U *
  process.pfBTagAnalysis  * 
  process.MEtoEDMConverter
)

process.outpath = cms.EndPath(process.EDM)

## Added for getting the L1 and HLT summary report
process.options = cms.untracked.PSet(
  wantSummary = cms.untracked.bool(True)
)

process.MessageLogger.categories.append('L1GtTrigReport')
process.MessageLogger.categories.append('HLTrigReport')
