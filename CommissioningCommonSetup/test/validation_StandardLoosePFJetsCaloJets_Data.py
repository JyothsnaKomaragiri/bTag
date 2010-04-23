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
process.GlobalTag.globaltag = 'GR10_P_V4::All'
#For use with April 1st rereco
#process.GlobalTag.globaltag = 'GR_R_35X_V6::All'

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
  cut = cms.string("pt > 10.0 && abs(eta) < 2.5 && neutralHadronEnergyFraction < 1.0 && neutralEmEnergyFraction < 1.0 && nConstituents > 0 && chargedHadronEnergyFraction > 0.0 && chargedMultiplicity > 0.0 && chargedEmEnergyFraction < 1.0"),
  filter = cms.bool(True)
)

#Filter for CaloJets
process.load("bTag.CommissioningCommonSetup.caloJetIDFilter_cff")

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
   jets = cms.InputTag("caloJetIDFilter")
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

process.standardCombinedSecondaryVertexCalo = process.combinedSecondaryVertex.clone()

process.looseCombinedSecondaryVertexCalo = process.combinedSecondaryVertex.clone()
process.looseCombinedSecondaryVertexCalo.correctVertexMass = False
process.looseCombinedSecondaryVertexCalo.trackPairV0Filter = cms.PSet(k0sMassWindow = cms.double(0.015))
process.looseCombinedSecondaryVertexCalo.pseudoVertexV0Filter = cms.PSet(k0sMassWindow = cms.double(0.015))
process.looseCombinedSecondaryVertexCalo.trackMultiplicityMin = 2
process.looseCombinedSecondaryVertexCalo.trackSelection.maxDistToAxis = 999
process.looseCombinedSecondaryVertexCalo.trackSelection.qualityClass = 'tight'
process.looseCombinedSecondaryVertexCalo.trackSelection.maxDecayLen = 999
process.looseCombinedSecondaryVertexCalo.trackSelection.jetDeltaRMax = 999
process.looseCombinedSecondaryVertexCalo.trackPseudoSelection.maxDistToAxis = 999
process.looseCombinedSecondaryVertexCalo.trackPseudoSelection.qualityClass = 'tight'
process.looseCombinedSecondaryVertexCalo.trackPseudoSelection.maxDecayLen = 999
process.looseCombinedSecondaryVertexCalo.trackPseudoSelection.jetDeltaRMax = 999

process.standardCombinedSecondaryVertexPF = process.standardCombinedSecondaryVertexCalo.clone()
process.looseCombinedSecondaryVertexPF = process.looseCombinedSecondaryVertexCalo.clone()

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
  jetTagComputer = cms.string('standardCombinedSecondaryVertexCalo'),
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterCaloTagInfos"),
                           cms.InputTag("standardSecondaryVertexCaloTagInfos"))
)

process.looseCombinedSecondaryVertexCaloBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  jetTagComputer = cms.string('looseCombinedSecondaryVertexCalo'),
  tagInfos = cms.VInputTag(cms.InputTag("looseImpactParameterCaloTagInfos"),
                           cms.InputTag("looseSecondaryVertexCaloTagInfos"))
)

process.standardCombinedSecondaryVertexPFBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  jetTagComputer = cms.string('standardCombinedSecondaryVertexPF'),
  tagInfos = cms.VInputTag(cms.InputTag("standardImpactParameterPFTagInfos"),
                           cms.InputTag("standardSecondaryVertexPFTagInfos"))
)

process.looseCombinedSecondaryVertexPFBJetTags = process.combinedSecondaryVertexBJetTags.clone(
  jetTagComputer = cms.string('looseCombinedSecondaryVertexPF'),
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
  jets = "caloJetIDFilter"
)
process.looseSoftMuonCaloTagInfos = process.softMuonTagInfos.clone(
  jets = "caloJetIDFilter",
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
  jets = "caloJetIDFilter"
)
process.looseSoftElectronCaloTagInfos = process.softElectronTagInfos.clone(
  jets = "caloJetIDFilter",
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
process.caloBTagAnalysis.ptRanges = cms.vdouble(10.0, 20.0, 40.0, 99999.0)
process.caloBTagAnalysis.etaRanges = cms.vdouble(0.0, 1.5, 2.5)
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
            label = cms.InputTag("standardCombinedSecondaryVertexCalo")
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
            label = cms.InputTag("looseCombinedSecondaryVertexCalo")
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
            label = cms.InputTag("standardCombinedSecondaryVertexPF")
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
            label = cms.InputTag("looseCombinedSecondaryVertexPF")
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

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    '/store/data/Commissioning10/MinimumBias/RECO/Apr1ReReco-v2/0139/F26CDE14-933E-DF11-B693-001A92971B04.root'
    )
)
process.evtLumiFilter = cms.EDFilter("EventLumiFilter",
  lumisToProcess = cms.VLuminosityBlockRange(
	'132440:85-132440:138',
	'132440:141-132440:401',
	'132473:1-132473:29',
	'132476:23-132476:28',
	'132476:54-132476:57',
	'132477:1-132477:5',
	'132477:34-132477:35',
	'132477:63-132477:64',
	'132477:90-132477:93',
	'132477:118-132477:121',
	'132477:148-132477:149',
	'132477:176-132477:179',
	'132477:225-132477:236',
	'132477:368-132477:384',
	'132477:517-132477:520',
	'132596:382-132596:383',
	'132596:447-132596:453',
	'132598:80-132598:82',
	'132598:174-132598:188',
	'132599:1-132599:379',
	'132599:381-132599:538',
	'132601:1-132601:207',
	'132601:209-132601:259',
	'132601:261-132601:1131',
	'132602:1-132602:83',
	'132605:1-132605:444',
	'132605:446-132605:622',
	'132605:624-132605:829',
	'132605:831-132605:968',
	'132606:1-132606:37',
	'132656:1-132656:140',
	'132658:1-132658:177',
	'132659:1-132659:84',
	'132661:1-132661:130',
	'132662:1-132662:130',
	'132662:132-132662:217',
	'132716:220-132716:591',
	'132716:593-132716:640',
	'132959:1-132959:276',
	'132959:278-132959:417',
	'132960:1-132960:190',
	'132961:1-132961:427',
	'132965:1-132965:107',
	'132968:1-132968:173',
	'133029:101-133029:115',
	'133029:129-133029:350',
	'133031:1-133031:18',
	'133034:131-133034:325',
	'133046:1-133046:43',
	'133046:45-133046:323',
	'133082:1-133082:336',
	'133082:523-133082:592',
	'133082:595-133082:608',
	'133158:65-133158:786',
	'133321:1-133321:383',
	'133450:1-133450:329',
	'133450:332-133450:658',
	'133472:92-133472:106',
	'133474:1-133474:95',
	'133474:157-133474:189',
	'133483:94-133483:159',
	'133483:161-133483:591',
	'133483:652-133483:658',
	'133509:60-133509:75'
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
    SelectEvents = cms.untracked.PSet(
       SelectEvents = cms.vstring("plots")
    )
)

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
  process.evtLumiFilter +
  process.bit40 +
  process.bptxAnd +
  process.physDecl +
  process.noscraping +
  process.oneGoodVertexFilter +
  cms.ignore(process.PFJetsFilter) *
  process.ak5JetID *
  cms.ignore(process.caloJetIDFilter) *
  process.trackAssociation *
  process.ipTagInfos *
  process.svTagInfos *
  process.ipTaggers *
  process.svTaggers *
  process.slTagInfos *
  process.slTaggers *
  process.bTagValidation * 
  process.MEtoEDMConverter
)

process.outpath = cms.EndPath(process.EDM)
