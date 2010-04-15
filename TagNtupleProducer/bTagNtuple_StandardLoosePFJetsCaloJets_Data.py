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
