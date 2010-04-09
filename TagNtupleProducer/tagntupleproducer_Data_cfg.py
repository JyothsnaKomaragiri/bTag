import FWCore.ParameterSet.Config as cms

process = cms.Process("OWNPARTICLES")

### Standard settings
process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.GeometryExtended_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

### Use proper Global tag corresponding to the dataset used
process.GlobalTag.globaltag = 'GR10_E_V4::All'

process.load("L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff")
process.load("HLTrigger.HLTfilters.hltLevel1GTSeed_cfi")

process.hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
process.hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('(40 OR41) AND NOT (36 OR 37 OR 38 OR 39) AND NOT ((42 AND NOT 43) OR (43 ANDNOT 42))')


process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("bTagAnalysis.TagNtupleProducer.tagntupleproducer_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.bTagNtuple.getMCTruth = cms.bool(False)

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
                            fileNames = cms.untracked.vstring()
                            )


                            

#process.bTagNtuple = cms.EDProducer('TagNtupleProducer'
#                                    jetSrc = cms.InputTag( "ak7CaloJets" ),
#                                    jetMCSrc = cms.InputTag( "AK7byValAlgo" ),
#                                    )

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('bTagNtuple_Data_Reco.root')
)
process.monsterEventFilter = cms.EDFilter("FilterOutScraping",
                                          applyfilter = cms.untracked.bool(True),
                                          debugOn = cms.untracked.bool(False),
                                          numtrack = cms.untracked.uint32(10),
                                          thresh = cms.untracked.double(0.2))
  
process.p = cms.Path(process.hltLevel1GTSeed * process.monsterEventFilter * process.bTagNtuple)


process.out.outputCommands = cms.untracked.vstring(
      "drop *",
      "keep *_bTagNtuple_*_*")

process.e = cms.EndPath(process.out)
