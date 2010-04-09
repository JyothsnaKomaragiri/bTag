import FWCore.ParameterSet.Config as cms

process = cms.Process("OWNPARTICLES")

### Standard settings
process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

### Use proper Global tag corresponding to the dataset used
process.GlobalTag.globaltag = 'START3X_V26A::ALL'

process.load("L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff")
process.load("HLTrigger.HLTfilters.hltLevel1GTSeed_cfi")

process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('(40 OR41) AND NOT (36 OR 37 OR 38 OR 39) AND NOT ((42 AND NOT 43) OR (43 ANDNOT 42))')

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("PhysicsTools.JetMCAlgos.CaloJetsMCFlavour_cfi")
process.load("bTagAnalysis.TagNtupleProducer.tagntupleproducer_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
                            fileNames = cms.untracked.vstring(
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/0060E652-822B-DF11-BA47-002618943972.root',
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/2099CCE3-7F2B-DF11-8F1E-003048679076.root',
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/420EA375-7B2B-DF11-AA9C-00261894396F.root',
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/948BEDFA-862B-DF11-B7F3-003048678B36.root',
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/B0C10537-812B-DF11-8F48-0018F3D096F8.root',
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/DC1B72F7-822B-DF11-9904-001731A28ACD.root',
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/DE8F5411-7A2B-DF11-830C-003048678A80.root',
                                '/store/relval/CMSSW_3_5_4/RelValTTbar/GEN-SIM-RECO/START3X_V24-v1/0003/E2767CCF-802B-DF11-97B5-001A92811706.root'
                                )
                            )

process.monsterEventFilter = cms.EDFilter("FilterOutScraping",
                                          applyfilter = cms.untracked.bool(True),
                                          debugOn = cms.untracked.bool(False),
                                          numtrack = cms.untracked.uint32(10),
                                          thresh = cms.untracked.double(0.2))

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('bTagNtuple_MC_Reco.root')
)

process.p = cms.Path(process.hltLevel1GTSeed* process.monsterEventFilter*process.myPartons*process.AK5Flavour*process.bTagNtuple)

process.out.outputCommands = cms.untracked.vstring(
      "drop *",
      "keep *_bTagNtuple_*_*")

process.e = cms.EndPath(process.out)
