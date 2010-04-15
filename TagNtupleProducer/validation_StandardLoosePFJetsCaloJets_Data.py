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
#Include these for the simpleSecondaryVertexHighPurity tagger
process.load("RecoBTag.SecondaryVertex.simpleSecondaryVertex3TrkES_cfi")
process.load("RecoBTag.SecondaryVertex.simpleSecondaryVertexHighPurBJetTags_cfi")

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
#For use with propt reco
#process.GlobalTag.globaltag = 'GR10_P_V4::All'
#For use with April 1st rereco
process.GlobalTag.globaltag = 'GR_R_35X_V6::All'

process.load('L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff')
from HLTrigger.HLTfilters.hltLevel1GTSeed_cfi import hltLevel1GTSeed
#Good Bunch Crossings
process.bptxAnd = hltLevel1GTSeed.clone(L1TechTriggerSeeding = cms.bool(True), L1SeedsLogicalExpression = cms.string('0'))
#BSCNOBEAMHALO
process.bit40 = hltLevel1GTSeed.clone(L1TechTriggerSeeding = cms.bool(True), L1SeedsLogicalExpression = cms.string('(40 OR 41) AND NOT (36 OR 37 OR 38 OR 39) AND NOT ((42 AND NOT 43) OR (43 AND NOT 42))'))

#Physics-declared Bit
from HLTrigger.HLTfilters.hltHighLevelDev_cfi import hltHighLevelDev
process.physDecl = hltHighLevelDev.clone(HLTPaths = ['HLT_PhysicsDeclared'], HLTPathsPrescales = [1])

#Require a good vertex
process.oneGoodVertexFilter = cms.EDFilter("VertexSelector",
   src = cms.InputTag("offlinePrimaryVertices"),
   cut = cms.string("!isFake && ndof > 4 && abs(z) <= 15 && position.Rho <= 2"),
   filter = cms.bool(True),   # otherwise it won't filter the events, just produce an empty vertex collection.
)

#Filter for PFJets
process.PFJetsFilter = cms.EDFilter("PFJetSelector",
  src = cms.InputTag("ak5PFJets"),
  cut = cms.string("pt > 10.0 && abs(eta) < 2.4 && neutralHadronEnergyFraction < 1.0 && neutralEmEnergyFraction < 1.0 && nConstituents > 0 && chargedHadronEnergyFraction > 0.0 && chargedMultiplicity > 0.0 && chargedEmEnergyFraction < 1.0"),
  filter = cms.bool(True)
)

#Filter for CaloJets
process.CaloJetsFilter = cms.EDFilter("CaloJetSelector",
  src = cms.InputTag("ak5CaloJets"),
  cut = cms.string("pt > 10.0 && abs(eta) < 2.4 && emEnergyFraction > 0.01"),
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

process.ak5CaloJetTracksAssociatorAtVertex = cms.EDProducer("JetTracksAssociatorAtVertex",
   process.j2tParametersVX,
   jets = cms.InputTag("CaloJetsFilter")
)

process.ak5PFJetTracksAssociatorAtVertex = process.ak5CaloJetTracksAssociatorAtVertex.clone(
  jets = "PFJetsFilter"
)

process.standardImpactParameterCaloTagInfos = process.impactParameterTagInfos.clone(
  jetTracks = "ak5CaloJetTracksAssociatorAtVertex"
)

process.looseImpactParameterCaloTagInfos = process.impactParameterTagInfos.clone(
   jetTracks = "ak5CaloJetTracksAssociatorAtVertex",
   minimumNumberOfHits = 7,
   maximumTransverseImpactParameter = 0.2,
   minimumTransverseMomentum = 0.0,
   maximumChiSquared = 10.0,
   useTrackQuality = False,
   ghostTrackPriorDeltaR = 0.1
)

process.standardImpactParameterPFTagInfos = process.standardImpactParameterCaloTagInfos.clone(
  jetTracks = "ak5PFJetTracksAssociatorAtVertex"
)

process.looseImpactParameterPFTagInfos = process.looseImpactParameterCaloTagInfos.clone(
  jetTracks = "ak5PFJetTracksAssociatorAtVertex"
)

process.standardSecondaryVertexCaloTagInfos = process.secondaryVertexTagInfos.clone(
  trackIPTagInfos = "standardImpactParameterCaloTagInfos"
)

process.looseSecondaryVertexCaloTagInfos = process.secondaryVertexTagInfos.clone(
  trackIPTagInfos = "looseImpactParameterCaloTagInfos",
  constraint = "PVErrorScaled",
  pvErrorScaling = cms.double(2.0)
)
process.looseSecondaryVertexCaloTagInfos.vertexCuts.v0Filter = cms.PSet(k0sMassWindow = cms.double(0.015))
process.looseSecondaryVertexCaloTagInfos.vertexCuts.maxDeltaRToJetAxis = 1.0
process.looseSecondaryVertexCaloTagInfos.vertexReco.smoothing = cms.bool(True)
process.looseSecondaryVertexCaloTagInfos.trackSelection.maxDistToAxis = 0.1
process.looseSecondaryVertexCaloTagInfos.trackSelection.jetDeltaRMax = 0.5
process.looseSecondaryVertexCaloTagInfos.trackSelection.qualityClass = "tight"

process.standardSecondaryVertexPFTagInfos = process.standardSecondaryVertexCaloTagInfos.clone(
  trackIPTagInfos = "standardImpactParameterPFTagInfos"
)

process.looseSecondaryVertexPFTagInfos = process.looseSecondaryVertexCaloTagInfos.clone(
  trackIPTagInfos = "looseImpactParameterPFTagInfos"
)

process.standardTrackCountingHighEffCaloBJetTags = process.trackCountingHighEffBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterCaloTagInfos"))
)

process.looseTrackCountingHighEffCaloBJetTags = process.trackCountingHighEffBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterCaloTagInfos"))
)

process.standardTrackCountingHighEffPFBJetTags = process.trackCountingHighEffBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"))
)

process.looseTrackCountingHighEffPFBJetTags = process.trackCountingHighEffBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterPFTagInfos"))
)

process.standardTrackCountingHighPurCaloBJetTags = process.trackCountingHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterCaloTagInfos"))
)

process.looseTrackCountingHighPurCaloBJetTags = process.trackCountingHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterCaloTagInfos"))
)

process.standardTrackCountingHighPurPFBJetTags = process.trackCountingHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"))
)

process.looseTrackCountingHighPurPFBJetTags = process.trackCountingHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterPFTagInfos"))
)

process.standardJetProbabilityCaloBJetTags = process.jetProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterCaloTagInfos")) 
)

process.looseJetProbabilityCaloBJetTags = process.jetProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterCaloTagInfos")) 
)

process.standardJetProbabilityPFBJetTags = process.jetProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos")) 
)

process.looseJetProbabilityPFBJetTags = process.jetProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterPFTagInfos")) 
)

process.standardJetBProbabilityCaloBJetTags = process.jetBProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterCaloTagInfos")) 
)

process.looseJetBProbabilityCaloBJetTags = process.jetBProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterCaloTagInfos")) 
)

process.standardJetBProbabilityPFBJetTags = process.jetBProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos")) 
)

process.looseJetBProbabilityPFBJetTags = process.jetBProbabilityBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterPFTagInfos")) 
)

process.standardSimpleSecondaryVertexCaloBJetTags = process.simpleSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSecondaryVertexCaloTagInfos"))
)

process.looseSimpleSecondaryVertexCaloBJetTags = process.simpleSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSecondaryVertexCaloTagInfos"))
)

process.standardSimpleSecondaryVertexPFBJetTags = process.simpleSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.looseSimpleSecondaryVertexPFBJetTags = process.simpleSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSecondaryVertexPFTagInfos"))
)

process.standardSimpleSecondaryVertexHighPurCaloBJetTags = process.simpleSecondaryVertexHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSecondaryVertexCaloTagInfos"))
)

process.looseSimpleSecondaryVertexHighPurCaloBJetTags = process.simpleSecondaryVertexHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSecondaryVertexCaloTagInfos"))
)

process.standardSimpleSecondaryVertexHighPurPFBJetTags = process.simpleSecondaryVertexHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.looseSimpleSecondaryVertexHighPurPFBJetTags = process.simpleSecondaryVertexHighPurBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSecondaryVertexPFTagInfos"))
)

process.standardCombinedSecondaryVertexCaloBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterCaloTagInfos"),
                           cms.InputTag("standardSecondaryVertexCaloTagInfos"))
)

process.looseCombinedSecondaryVertexCaloBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterCaloTagInfos"),
                           cms.InputTag("looseSecondaryVertexCaloTagInfos"))
)

process.standardCombinedSecondaryVertexPFBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"),
                           cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.looseCombinedSecondaryVertexPFBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterPFTagInfos"),
                           cms.InputTag("looseSecondaryVertexPFTagInfos"))
)

process.standardCombinedSecondaryVertexMVACaloBJetTags = process.combinedSecondaryVertexMVABJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterCaloTagInfos"),
                           cms.InputTag("standardSecondaryVertexCaloTagInfos"))
)

process.looseCombinedSecondaryVertexMVACaloBJetTags = process.combinedSecondaryVertexMVABJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterCaloTagInfos"),
                           cms.InputTag("looseSecondaryVertexCaloTagInfos"))
)

process.standardCombinedSecondaryVertexMVAPFBJetTags = process.combinedSecondaryVertexMVABJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"),
                           cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.looseCombinedSecondaryVertexMVAPFBJetTags = process.combinedSecondaryVertexMVABJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterPFTagInfos"),
                           cms.InputTag("looseSecondaryVertexPFTagInfos"))
)

process.looseSoftPFElectrons = process.softPFElectrons.clone(
  BarrelPtCuts = cms.vdouble(0.0, 9999.0),
  BarreldRGsfTrackElectronCuts = cms.vdouble(0.0, 0.005),
  BarrelEemPinRatioCuts = cms.vdouble(-0.2, 0.2),
  BarrelMVACuts = cms.vdouble(-0.4, 1.0),
  BarrelInversedRFirstLastHitCuts = cms.vdouble(0.0, 4.0),
  BarrelRadiusFirstHitCuts = cms.vdouble(0.0, 5.0),
  BarrelZFirstHitCuts = cms.vdouble(-20.0, 20.0),
  ForwardPtCuts = cms.vdouble(0.0, 9999.0),
  ForwardInverseFBremCuts = cms.vdouble(1.0, 7.01),
  ForwarddRGsfTrackElectronCuts = cms.vdouble(0.0, 0.01),
  ForwardRadiusFirstHitCuts = cms.vdouble(0.0, 6.35),
  ForwardZFirstHitCuts = cms.vdouble(-50.0, 50.0),
  ForwardMVACuts = cms.vdouble(-0.4, 1.0)
)
process.standardSoftMuonCaloTagInfos = process.softMuonTagInfos.clone(
  jets = "CaloJetsFilter"
)
process.looseSoftMuonCaloTagInfos = process.softMuonTagInfos.clone(
  jets = "CaloJetsFilter",
  leptonChi2Cut = 10.0,
  muonSelection = RecoBTag.SoftLepton.muonSelection.AllTrackerMuons
)
process.standardSoftMuonPFTagInfos = process.standardSoftMuonCaloTagInfos.clone(
  jets = "PFJetsFilter"
)
process.looseSoftMuonPFTagInfos = process.looseSoftMuonCaloTagInfos.clone(
  jets = "PFJetsFilter"
)
process.standardSoftElectronCaloTagInfos = process.softElectronTagInfos.clone(
  jets = "CaloJetsFilter"
)
process.looseSoftElectronCaloTagInfos = process.softElectronTagInfos.clone(
  jets = "CaloJetsFilter",
  leptons = "looseSoftPFElectrons"
)
process.standardSoftElectronPFTagInfos = process.standardSoftElectronCaloTagInfos.clone(
  jets = "PFJetsFilter"
)
process.looseSoftElectronPFTagInfos = process.looseSoftElectronCaloTagInfos.clone(
  jets = "PFJetsFilter"
)

process.standardSoftMuonCaloBJetTags = process.softMuonBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonCaloTagInfos"))
)

process.looseSoftMuonCaloBJetTags = process.softMuonBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftMuonCaloTagInfos"))
)

process.standardSoftMuonPFBJetTags = process.softMuonBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonPFTagInfos"))
)

process.looseSoftMuonPFBJetTags = process.softMuonBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftMuonPFTagInfos"))
)

process.standardSoftMuonByPtCaloBJetTags = process.softMuonByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonCaloTagInfos"))
)

process.looseSoftMuonByPtCaloBJetTags = process.softMuonByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftMuonCaloTagInfos"))
)

process.standardSoftMuonByPtPFBJetTags = process.softMuonByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonPFTagInfos"))
)

process.looseSoftMuonByPtPFBJetTags = process.softMuonByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftMuonPFTagInfos"))
)

process.standardSoftMuonByIP3dCaloBJetTags = process.softMuonByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonCaloTagInfos"))
)

process.looseSoftMuonByIP3dCaloBJetTags = process.softMuonByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftMuonCaloTagInfos"))
)

process.standardSoftMuonByIP3dPFBJetTags = process.softMuonByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftMuonPFTagInfos"))
)

process.looseSoftMuonByIP3dPFBJetTags = process.softMuonByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftMuonPFTagInfos"))
)

process.standardSoftElectronByPtCaloBJetTags = process.softElectronByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftElectronCaloTagInfos"))
)

process.looseSoftElectronByPtCaloBJetTags = process.softElectronByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftElectronCaloTagInfos"))
)

process.standardSoftElectronByPtPFBJetTags = process.softElectronByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftElectronPFTagInfos"))
)

process.looseSoftElectronByPtPFBJetTags = process.softElectronByPtBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftElectronPFTagInfos"))
)

process.standardSoftElectronByIP3dCaloBJetTags = process.softElectronByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftElectronCaloTagInfos"))
)

process.looseSoftElectronByIP3dCaloBJetTags = process.softElectronByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftElectronCaloTagInfos"))
)

process.standardSoftElectronByIP3dPFBJetTags = process.softElectronByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("standardSoftElectronPFTagInfos"))
)

process.looseSoftElectronByIP3dPFBJetTags = process.softElectronByIP3dBJetTags.clone(
  tagInfos = cms.VInputTag(cms.InputTag("looseSoftElectronPFTagInfos"))
)

process.load("DQMOffline.RecoB.bTagAnalysisData_cfi")
#process.bTagAnalysis.allHistograms = True
process.caloBTagAnalysis = process.bTagAnalysis.clone() 
process.caloBTagAnalysis.finalizePlots = False 
process.caloBTagAnalysis.finalizeOnly = False 
process.caloBTagAnalysis.ptRecJetMin = 10.0
process.caloBTagAnalysis.ptRanges = cms.vdouble(9999.0)
process.caloBTagAnalysis.etaRanges = cms.vdouble(2.4)
process.caloBTagAnalysis.tagConfig = cms.VPSet(
        cms.PSet(
            bTagTrackIPAnalysisBlock,
            type = cms.string('TrackIP'),
            label = cms.InputTag("standardImpactParameterCaloTagInfos")
        ), 
        cms.PSet(
            bTagCombinedSVAnalysisBlock,
            ipTagInfos = cms.InputTag("standardImpactParameterCaloTagInfos"),
            type = cms.string('GenericMVA'),
            svTagInfos = cms.InputTag("standardSecondaryVertexCaloTagInfos"),
            label = cms.InputTag("combinedSecondaryVertex")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("standardTrackCountingHighEffCaloBJetTags")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("standardTrackCountingHighPurCaloBJetTags")
        ), 
        cms.PSet(
            bTagProbabilityAnalysisBlock,
            label = cms.InputTag("standardJetProbabilityCaloBJetTags")
        ), 
        cms.PSet(
            bTagBProbabilityAnalysisBlock,
            label = cms.InputTag("standardJetBProbabilityCaloBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("standardSimpleSecondaryVertexCaloBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("standardSimpleSecondaryVertexHighPurCaloBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("standardCombinedSecondaryVertexCaloBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("standardCombinedSecondaryVertexMVACaloBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            label = cms.InputTag("standardSoftMuonCaloBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("standardSoftMuonByIP3dCaloBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("standardSoftMuonByPtCaloBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("standardSoftElectronByIP3dCaloBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("standardSoftElectronByPtCaloBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("standardSoftMuonCaloTagInfos")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("standardSoftElectronCaloTagInfos")
        ), 
        cms.PSet(
            bTagTrackIPAnalysisBlock,
            type = cms.string('TrackIP'),
            label = cms.InputTag("looseImpactParameterCaloTagInfos")
        ), 
        cms.PSet(
            bTagCombinedSVAnalysisBlock,
            ipTagInfos = cms.InputTag("looseImpactParameterCaloTagInfos"),
            type = cms.string('GenericMVA'),
            svTagInfos = cms.InputTag("looseSecondaryVertexCaloTagInfos"),
            label = cms.InputTag("combinedSecondaryVertex")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("looseTrackCountingHighEffCaloBJetTags")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("looseTrackCountingHighPurCaloBJetTags")
        ), 
        cms.PSet(
            bTagProbabilityAnalysisBlock,
            label = cms.InputTag("looseJetProbabilityCaloBJetTags")
        ), 
        cms.PSet(
            bTagBProbabilityAnalysisBlock,
            label = cms.InputTag("looseJetBProbabilityCaloBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("looseSimpleSecondaryVertexCaloBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("looseSimpleSecondaryVertexHighPurCaloBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("looseCombinedSecondaryVertexCaloBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("looseCombinedSecondaryVertexMVACaloBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            label = cms.InputTag("looseSoftMuonCaloBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("looseSoftMuonByIP3dCaloBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("looseSoftMuonByPtCaloBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("looseSoftElectronByIP3dCaloBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("looseSoftElectronByPtCaloBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("looseSoftMuonCaloTagInfos")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("looseSoftElectronCaloTagInfos")
        ) 
)

process.pfBTagAnalysis = process.caloBTagAnalysis.clone()
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
            label = cms.InputTag("combinedSecondaryVertex")
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
            label = cms.InputTag("standardSimpleSecondaryVertexPFBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("standardSimpleSecondaryVertexHighPurPFBJetTags")
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
        ), 
        cms.PSet(
            bTagTrackIPAnalysisBlock,
            type = cms.string('TrackIP'),
            label = cms.InputTag("looseImpactParameterPFTagInfos")
        ), 
        cms.PSet(
            bTagCombinedSVAnalysisBlock,
            ipTagInfos = cms.InputTag("looseImpactParameterPFTagInfos"),
            type = cms.string('GenericMVA'),
            svTagInfos = cms.InputTag("looseSecondaryVertexPFTagInfos"),
            label = cms.InputTag("combinedSecondaryVertex")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("looseTrackCountingHighEffPFBJetTags")
        ), 
        cms.PSet(
            bTagTrackCountingAnalysisBlock,
            label = cms.InputTag("looseTrackCountingHighPurPFBJetTags")
        ), 
        cms.PSet(
            bTagProbabilityAnalysisBlock,
            label = cms.InputTag("looseJetProbabilityPFBJetTags")
        ), 
        cms.PSet(
            bTagBProbabilityAnalysisBlock,
            label = cms.InputTag("looseJetBProbabilityPFBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("looseSimpleSecondaryVertexPFBJetTags")
        ), 
        cms.PSet(
            bTagSimpleSVAnalysisBlock,
            label = cms.InputTag("looseSimpleSecondaryVertexHighPurPFBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("looseCombinedSecondaryVertexPFBJetTags")
        ), 
        cms.PSet(
            bTagGenericAnalysisBlock,
            label = cms.InputTag("looseCombinedSecondaryVertexMVAPFBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            label = cms.InputTag("looseSoftMuonPFBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("looseSoftMuonByIP3dPFBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("looseSoftMuonByPtPFBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonByIPAnalysisBlock,
            label = cms.InputTag("looseSoftElectronByIP3dPFBJetTags")
        ), 
        cms.PSet(
            bTagSoftLeptonByPtAnalysisBlock,
            label = cms.InputTag("looseSoftElectronByPtPFBJetTags")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("looseSoftMuonPFTagInfos")
        ),
        cms.PSet(
            bTagSoftLeptonAnalysisBlock,
            type = cms.string("SoftLepton"),
            label = cms.InputTag("looseSoftElectronPFTagInfos")
        ) 
)

process.load("bTagAnalysis.TagNtupleProducer.tagntupleproducer_cfi")

process.standardCaloBTagNtuple = process.bTagNtuple.clone()
process.standardCaloBTagNtuple.getMCTruth = cms.bool(False)
process.standardCaloBTagNtuple.jetSrc = cms.InputTag( "CaloJetsFilter" )
process.standardCaloBTagNtuple.jetMCSrc = cms.InputTag( "" )
process.standardCaloBTagNtuple.jetTracks = cms.InputTag( "ak5CaloJetTracksAssociatorAtVertex" )
process.standardCaloBTagNtuple.getSVTagInfo = cms.bool(True)
process.standardCaloBTagNtuple.getIPTagInfo = cms.bool(True)
process.standardCaloBTagNtuple.getSETagInfo = cms.bool(True)
process.standardCaloBTagNtuple.getSMTagInfo = cms.bool(True)
process.standardCaloBTagNtuple.SVTagInfos = cms.InputTag( "standardSecondaryVertexCaloTagInfos" )
process.standardCaloBTagNtuple.IPTagInfos = cms.InputTag( "standardImpactParameterCaloTagInfos" )
process.standardCaloBTagNtuple.ElectronTagInfos = cms.InputTag( "standardSoftElectronCaloTagInfos" )
process.standardCaloBTagNtuple.MuonTagInfos = cms.InputTag( "standardSoftMuonCaloTagInfos" )
process.standardCaloBTagNtuple.Label = cms.string("standardCalo")
process.standardCaloBTagNtuple.bTagConfig = cms.VPSet(
    cms.PSet(
    alias = cms.string("standardTrackCountingHighEffCaloBJetTags"),
    label = cms.InputTag("standardTrackCountingHighEffCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardTrackCountingHighPurCaloBJetTags"),
    label = cms.InputTag("standardTrackCountingHighPurCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardJetProbabilityCaloBJetTags"),
    label = cms.InputTag("standardJetProbabilityCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardJetBProbabilityCaloBJetTags"),
    label = cms.InputTag("standardJetBProbabilityCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSimpleSecondaryVertexCaloBJetTags"),
    label = cms.InputTag("standardSimpleSecondaryVertexCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSimpleSecondaryVertexHighPurCaloBJetTags"),
    label = cms.InputTag("standardSimpleSecondaryVertexHighPurCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardCombinedSecondaryVertexCaloBJetTags"),
    label = cms.InputTag("standardCombinedSecondaryVertexCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardCombinedSecondaryVertexMVACaloBJetTags"),
    label = cms.InputTag("standardCombinedSecondaryVertexMVACaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSoftMuonCaloBJetTags"),
    label = cms.InputTag("standardSoftMuonCaloBJetTags")
    ),
    cms.PSet(
    alias = cms.string("standardSoftMuonByIP3dCaloBJetTags"),
    label = cms.InputTag("standardSoftMuonByIP3dCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSoftMuonByPtCaloBJetTags"),
    label = cms.InputTag("standardSoftMuonByPtCaloBJetTags")
    ),
    cms.PSet(
    alias = cms.string("standardSoftElectronByIP3dCaloBJetTags"),
    label = cms.InputTag("standardSoftElectronByIP3dCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("standardSoftElectronByPtCaloBJetTags"),
    label = cms.InputTag("standardSoftElectronByPtCaloBJetTags")
    )
    )

process.looseCaloBTagNtuple = process.bTagNtuple.clone()
process.looseCaloBTagNtuple.getMCTruth = cms.bool(False)
process.looseCaloBTagNtuple.jetSrc = cms.InputTag( "CaloJetsFilter" )
process.looseCaloBTagNtuple.jetMCSrc = cms.InputTag( "" )
process.looseCaloBTagNtuple.jetTracks = cms.InputTag( "ak5CaloJetTracksAssociatorAtVertex" )
process.looseCaloBTagNtuple.getSVTagInfo = cms.bool(True)
process.looseCaloBTagNtuple.getIPTagInfo = cms.bool(True)
process.looseCaloBTagNtuple.getSETagInfo = cms.bool(True)
process.looseCaloBTagNtuple.getSMTagInfo = cms.bool(True)
process.looseCaloBTagNtuple.SVTagInfos = cms.InputTag( "looseSecondaryVertexCaloTagInfos" )
process.looseCaloBTagNtuple.IPTagInfos = cms.InputTag( "looseImpactParameterCaloTagInfos" )
process.looseCaloBTagNtuple.ElectronTagInfos = cms.InputTag( "looseSoftElectronCaloTagInfos" )
process.looseCaloBTagNtuple.MuonTagInfos = cms.InputTag( "looseSoftMuonCaloTagInfos" )
process.looseCaloBTagNtuple.Label = cms.string("looseCalo")
process.looseCaloBTagNtuple.bTagConfig = cms.VPSet(
    cms.PSet(
    alias = cms.string("looseTrackCountingHighEffCaloBJetTags"),
    label = cms.InputTag("looseTrackCountingHighEffCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseTrackCountingHighPurCaloBJetTags"),
    label = cms.InputTag("looseTrackCountingHighPurCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseJetProbabilityCaloBJetTags"),
    label = cms.InputTag("looseJetProbabilityCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseJetBProbabilityCaloBJetTags"),
    label = cms.InputTag("looseJetBProbabilityCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSimpleSecondaryVertexCaloBJetTags"),
    label = cms.InputTag("looseSimpleSecondaryVertexCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSimpleSecondaryVertexHighPurCaloBJetTags"),
    label = cms.InputTag("looseSimpleSecondaryVertexHighPurCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseCombinedSecondaryVertexCaloBJetTags"),
    label = cms.InputTag("looseCombinedSecondaryVertexCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseCombinedSecondaryVertexMVACaloBJetTags"),
    label = cms.InputTag("looseCombinedSecondaryVertexMVACaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSoftMuonCaloBJetTags"),
    label = cms.InputTag("looseSoftMuonCaloBJetTags")
    ),
    cms.PSet(
    alias = cms.string("looseSoftMuonByIP3dCaloBJetTags"),
    label = cms.InputTag("looseSoftMuonByIP3dCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSoftMuonByPtCaloBJetTags"),
    label = cms.InputTag("looseSoftMuonByPtCaloBJetTags")
    ),
    cms.PSet(
    alias = cms.string("looseSoftElectronByIP3dCaloBJetTags"),
    label = cms.InputTag("looseSoftElectronByIP3dCaloBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSoftElectronByPtCaloBJetTags"),
    label = cms.InputTag("looseSoftElectronByPtCaloBJetTags")
    )
    )

process.standardPFBTagNtuple = process.bTagNtuple.clone()
process.standardPFBTagNtuple.getMCTruth = cms.bool(False)
process.standardPFBTagNtuple.jetSrc = cms.InputTag( "PFJetsFilter" )
process.standardPFBTagNtuple.jetMCSrc = cms.InputTag( "" )
process.standardPFBTagNtuple.jetTracks = cms.InputTag( "ak5PFJetTracksAssociatorAtVertex" )
process.standardPFBTagNtuple.getSVTagInfo = cms.bool(True)
process.standardPFBTagNtuple.getIPTagInfo = cms.bool(True)
process.standardPFBTagNtuple.getSETagInfo = cms.bool(True)
process.standardPFBTagNtuple.getSMTagInfo = cms.bool(True)
process.standardPFBTagNtuple.SVTagInfos = cms.InputTag( "standardSecondaryVertexPFTagInfos" )
process.standardPFBTagNtuple.IPTagInfos = cms.InputTag( "standardImpactParameterPFTagInfos" )
process.standardPFBTagNtuple.ElectronTagInfos = cms.InputTag( "standardSoftElectronPFTagInfos" )
process.standardPFBTagNtuple.MuonTagInfos = cms.InputTag( "standardSoftMuonPFTagInfos" )
process.standardPFBTagNtuple.Label = cms.string("standardPF")
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
    alias = cms.string("standardSimpleSecondaryVertexPFBJetTags"),
    label = cms.InputTag("standardSimpleSecondaryVertexPFBJetTags")
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

process.loosePFBTagNtuple = process.bTagNtuple.clone()
process.loosePFBTagNtuple.getMCTruth = cms.bool(False)
process.loosePFBTagNtuple.jetSrc = cms.InputTag( "PFJetsFilter" )
process.loosePFBTagNtuple.jetMCSrc = cms.InputTag( "" )
process.loosePFBTagNtuple.jetTracks = cms.InputTag( "ak5PFJetTracksAssociatorAtVertex" )
process.loosePFBTagNtuple.getSVTagInfo = cms.bool(True)
process.loosePFBTagNtuple.getIPTagInfo = cms.bool(True)
process.loosePFBTagNtuple.getSETagInfo = cms.bool(True)
process.loosePFBTagNtuple.getSMTagInfo = cms.bool(True)
process.loosePFBTagNtuple.SVTagInfos = cms.InputTag( "looseSecondaryVertexPFTagInfos" )
process.loosePFBTagNtuple.IPTagInfos = cms.InputTag( "looseImpactParameterPFTagInfos" )
process.loosePFBTagNtuple.ElectronTagInfos = cms.InputTag( "looseSoftElectronPFTagInfos" )
process.loosePFBTagNtuple.MuonTagInfos = cms.InputTag( "looseSoftMuonPFTagInfos" )
process.loosePFBTagNtuple.Label = cms.string("loosePF")
process.loosePFBTagNtuple.bTagConfig = cms.VPSet(
    cms.PSet(
    alias = cms.string("looseTrackCountingHighEffPFBJetTags"),
    label = cms.InputTag("looseTrackCountingHighEffPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseTrackCountingHighPurPFBJetTags"),
    label = cms.InputTag("looseTrackCountingHighPurPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseJetProbabilityPFBJetTags"),
    label = cms.InputTag("looseJetProbabilityPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseJetBProbabilityPFBJetTags"),
    label = cms.InputTag("looseJetBProbabilityPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSimpleSecondaryVertexPFBJetTags"),
    label = cms.InputTag("looseSimpleSecondaryVertexPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSimpleSecondaryVertexHighPurPFBJetTags"),
    label = cms.InputTag("looseSimpleSecondaryVertexHighPurPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseCombinedSecondaryVertexPFBJetTags"),
    label = cms.InputTag("looseCombinedSecondaryVertexPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseCombinedSecondaryVertexMVAPFBJetTags"),
    label = cms.InputTag("looseCombinedSecondaryVertexMVAPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSoftMuonPFBJetTags"),
    label = cms.InputTag("looseSoftMuonPFBJetTags")
    ),
    cms.PSet(
    alias = cms.string("looseSoftMuonByIP3dPFBJetTags"),
    label = cms.InputTag("looseSoftMuonByIP3dPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSoftMuonByPtPFBJetTags"),
    label = cms.InputTag("looseSoftMuonByPtPFBJetTags")
    ),
    cms.PSet(
    alias = cms.string("looseSoftElectronByIP3dPFBJetTags"),
    label = cms.InputTag("looseSoftElectronByIP3dPFBJetTags")
    ), 
    cms.PSet(
    alias = cms.string("looseSoftElectronByPtPFBJetTags"),
    label = cms.InputTag("looseSoftElectronByPtPFBJetTags")
    )
    )

process.bTagNtuples = cms.Sequence(
    process.standardCaloBTagNtuple + process.looseCaloBTagNtuple + process.standardPFBTagNtuple + process.loosePFBTagNtuple
    )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    '/store/data/Commissioning10/MinimumBias/RECO/Apr1ReReco-v2/0139/F26CDE14-933E-DF11-B693-001A92971B04.root'
    )
)

#process.EDM = cms.OutputModule("PoolOutputModule",
#    outputCommands = cms.untracked.vstring('drop *',
#                       "keep *_MEtoEDMConverter_*_validation"
#    ),
#    fileName = cms.untracked.string('MEtoEDMConverter.root'),
#    SelectEvents = cms.untracked.PSet(
#       SelectEvents = cms.vstring("plots")
#    )
#)

process.load("DQMServices.Components.MEtoEDMConverter_cfi")

process.trackAssociation = cms.Sequence(
     process.ak5CaloJetTracksAssociatorAtVertex +
     process.ak5PFJetTracksAssociatorAtVertex 
)

process.ipTagInfos = cms.Sequence(
    process.standardImpactParameterCaloTagInfos +
    process.looseImpactParameterCaloTagInfos +
    process.standardImpactParameterPFTagInfos +
    process.looseImpactParameterPFTagInfos
)

process.svTagInfos = cms.Sequence(
    process.standardSecondaryVertexCaloTagInfos +
    process.looseSecondaryVertexCaloTagInfos +
    process.standardSecondaryVertexPFTagInfos +
    process.looseSecondaryVertexPFTagInfos 
)

process.ipTaggers = cms.Sequence(
    process.standardTrackCountingHighEffCaloBJetTags +
    process.looseTrackCountingHighEffCaloBJetTags +
    process.standardTrackCountingHighEffPFBJetTags +
    process.looseTrackCountingHighEffPFBJetTags +
    process.standardTrackCountingHighPurCaloBJetTags +
    process.looseTrackCountingHighPurCaloBJetTags +
    process.standardTrackCountingHighPurPFBJetTags +
    process.looseTrackCountingHighPurPFBJetTags +
    process.standardJetProbabilityCaloBJetTags +
    process.looseJetProbabilityCaloBJetTags +
    process.standardJetProbabilityPFBJetTags +
    process.looseJetProbabilityPFBJetTags +
    process.standardJetBProbabilityCaloBJetTags +
    process.looseJetBProbabilityCaloBJetTags +
    process.standardJetBProbabilityPFBJetTags +
    process.looseJetBProbabilityPFBJetTags 
)

process.svTaggers = cms.Sequence(
    process.standardSimpleSecondaryVertexCaloBJetTags +
    process.looseSimpleSecondaryVertexCaloBJetTags +
    process.standardSimpleSecondaryVertexPFBJetTags +
    process.looseSimpleSecondaryVertexPFBJetTags +
    process.standardSimpleSecondaryVertexHighPurCaloBJetTags +
    process.looseSimpleSecondaryVertexHighPurCaloBJetTags +
    process.standardSimpleSecondaryVertexHighPurPFBJetTags +
    process.looseSimpleSecondaryVertexHighPurPFBJetTags +
    process.standardCombinedSecondaryVertexCaloBJetTags +
    process.looseCombinedSecondaryVertexCaloBJetTags +
    process.standardCombinedSecondaryVertexPFBJetTags +
    process.looseCombinedSecondaryVertexPFBJetTags +
    process.standardCombinedSecondaryVertexMVACaloBJetTags +
    process.looseCombinedSecondaryVertexMVACaloBJetTags +
    process.standardCombinedSecondaryVertexMVAPFBJetTags +
    process.looseCombinedSecondaryVertexMVAPFBJetTags 
)

process.slTagInfos = cms.Sequence(
    process.standardSoftMuonCaloTagInfos +
    process.looseSoftMuonCaloTagInfos +
    process.standardSoftMuonPFTagInfos +
    process.looseSoftMuonPFTagInfos +
    process.standardSoftElectronCaloTagInfos +
    process.standardSoftElectronPFTagInfos +
    process.looseSoftPFElectrons *  
    (
      process.looseSoftElectronCaloTagInfos +
      process.looseSoftElectronPFTagInfos
    )
)

process.slTaggers = cms.Sequence(
    process.standardSoftMuonCaloBJetTags +
    process.looseSoftMuonCaloBJetTags +
    process.standardSoftMuonPFBJetTags +
    process.looseSoftMuonPFBJetTags +
    process.standardSoftMuonByPtCaloBJetTags +
    process.looseSoftMuonByPtCaloBJetTags +
    process.standardSoftMuonByPtPFBJetTags +
    process.looseSoftMuonByPtPFBJetTags +
    process.standardSoftMuonByIP3dCaloBJetTags +
    process.looseSoftMuonByIP3dCaloBJetTags +
    process.standardSoftMuonByIP3dPFBJetTags +
    process.looseSoftMuonByIP3dPFBJetTags +
    process.standardSoftElectronByPtCaloBJetTags +
    process.looseSoftElectronByPtCaloBJetTags +
    process.standardSoftElectronByPtPFBJetTags +
    process.looseSoftElectronByPtPFBJetTags +
    process.standardSoftElectronByIP3dCaloBJetTags +
    process.looseSoftElectronByIP3dCaloBJetTags +
    process.standardSoftElectronByIP3dPFBJetTags +
    process.looseSoftElectronByIP3dPFBJetTags 
)

process.bTagValidation = cms.Sequence(
    process.caloBTagAnalysis +
    process.pfBTagAnalysis 
)

process.plots = cms.Path(
  process.bit40 +
  process.bptxAnd +
  process.physDecl +
  process.noscraping +
  process.oneGoodVertexFilter +
  cms.ignore(process.PFJetsFilter) +
  cms.ignore(process.CaloJetsFilter) +
  process.trackAssociation *
  process.ipTagInfos *
  process.svTagInfos *
  process.ipTaggers *
  process.svTaggers *
  process.slTagInfos *
  process.slTaggers *
#  process.bTagValidation * 
#  process.MEtoEDMConverter
  process.bTagNtuples
)

process.out = cms.OutputModule("PoolOutputModule",
        fileName = cms.untracked.string("bTagNtuple_Data.root")
)

process.out.outputCommands = cms.untracked.vstring(
      "drop *",
      "keep *_*bTagNtuple_*_*")

process.e = cms.EndPath(process.out)


