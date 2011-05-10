// system include files
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <sstream>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/Common/interface/TriggerResults.h"
//#include "FWCore/Framework/interface/TriggerNames.h"
#include "FWCore/Common/interface/TriggerNames.h"
// added by Caroline
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
// end add

#include "DataFormats/BTauReco/interface/SoftLeptonTagInfo.h"
#include "DataFormats/BTauReco/interface/SecondaryVertexTagInfo.h"
#include "DataFormats/BTauReco/interface/TrackIPTagInfo.h"
#include "DataFormats/BTauReco/interface/JetTag.h"

#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/JetCollection.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/JetTracksAssociation.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/Measurement1D.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonTrackLinks.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"

#include <DataFormats/EgammaCandidates/interface/GsfElectron.h>
//#include "DataFormats/EgammaCandidates/interface/ElectronTrackLinks.h"
#include <DataFormats/EgammaCandidates/interface/GsfElectronFwd.h>

#include "DataFormats/Math/interface/deltaR.h"
#include "Math/GenVector/VectorUtil.h"
#include "DataFormats/GeometryVector/interface/VectorUtil.h"

#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "RecoVertex/VertexPrimitives/interface/ConvertToFromReco.h"

#include "SimDataFormats/JetMatching/interface/JetFlavour.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourMatching.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include <DataFormats/GsfTrackReco/interface/GsfTrack.h>
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/IPTools/interface/IPTools.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"

#include "RecoBTau/JetTagComputer/interface/GenericMVAJetTagComputer.h"
#include "RecoBTau/JetTagComputer/interface/GenericMVAJetTagComputerWrapper.h"
#include "RecoBTau/JetTagComputer/interface/JetTagComputer.h"
#include "RecoBTau/JetTagComputer/interface/JetTagComputerRecord.h"
#include "RecoBTag/SecondaryVertex/interface/CombinedSVComputer.h"
#include "RecoBTag/SecondaryVertex/interface/TrackKinematics.h"

#include "DataFormats/SiPixelDetId/interface/PXBDetId.h"
#include "DataFormats/SiPixelDetId/interface/PXFDetId.h"
#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHit.h"

#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

//added by Caroline
#include "DataFormats/GeometrySurface/interface/Line.h"
//end add

#include <TTree.h>
#include <TFile.h>

// maximum array size (the arrays are stored with variable size in the root tree)
const unsigned int MAXJETS = 40;
const unsigned int MAXTRACKS = 300;


class TagNtupleProducer : public edm::EDAnalyzer {

public:
  explicit TagNtupleProducer(const edm::ParameterSet&);
  ~TagNtupleProducer();
  
  
  virtual void beginJob() ;
  virtual void beginRun(const edm::Run&, const edm::EventSetup&);
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endRun(const edm::Run&, const edm::EventSetup&);
  virtual void endJob() ;
  
  void getSharedHitsInfo(unsigned int layer, const reco::TrackRefVector & tracks, int &nSharedHits, int &nTotalHits);
  int  hasSharedHit(unsigned int layer, size_t location, const reco::TrackRefVector & tracks);      
  // ----------member data ---------------------------
  
  //Input from python config
  bool getMCTruth_;
  bool getMCPUInfo_;
  bool getSharedHitInfo_;  
  edm::InputTag jet_src_;
  edm::InputTag SVComputer_;
  edm::InputTag triggerTag_;
  edm::InputTag jet_MC_src_;
  edm::InputTag jet_tracks_;
  edm::InputTag primaryVertexProducer_;
  edm::InputTag SV_tag_infos_;
  edm::InputTag IP_tag_infos_;  
  edm::InputTag electron_tag_infos_;
  edm::InputTag muon_tag_infos_;
  std::string label_;
  std::string filename_;
  std::vector< edm::ParameterSet > bTag_Config_;
  
  // data formats
  TTree *tree;
  TFile *file;
  
  bool triggerHLTL1Jet6U, triggerHLTL1Jet10U, triggerHLTJet15U;
  bool triggerHLTJet30U, triggerHLTJet50U, triggerHLTJet70U, triggerHLTJet100U ;
  bool triggerHLTBTagIPJet50U, triggerHLTBTagMuJet10U, triggerHLTBTagMuJet20U;
  bool triggerHLTBTagMuDiJet10U, triggerHLTBTagMuDiJet20U, triggerHLTBTagMuDiJet20UMu5, triggerHLTBTagMuDiJet30U, triggerHLTBTagMuDiJet30UMu5;

  // added by Caroline
  int prescaleHLTL1Jet6U, prescaleHLTL1Jet10U, prescaleHLTJet15U;
  int prescaleHLTJet30U, prescaleHLTJet50U, prescaleHLTJet70U, prescaleHLTJet100U ;
  int prescaleHLTBTagIPJet50U, prescaleHLTBTagMuJet10U, prescaleHLTBTagMuJet20U;
  int prescaleHLTBTagMuDiJet10U, prescaleHLTBTagMuDiJet20U, prescaleHLTBTagMuDiJet20UMu5, prescaleHLTBTagMuDiJet30U, prescaleHLTBTagMuDiJet30UMu5;
  // end add

  //added by Caroline (4_1_2_patch1)
  bool triggerHLT_L1SingleJet36, triggerHLT_Jet30, triggerHLT_Jet60, triggerHLT_Jet80, triggerHLT_Jet110, triggerHLT_Jet150;
  bool triggerHLT_Jet190, triggerHLT_Jet240, triggerHLT_Jet370, triggerHLT_Jet370_NoJetID;
  int prescaleHLT_L1SingleJet36, prescaleHLT_Jet30, prescaleHLT_Jet60, prescaleHLT_Jet80, prescaleHLT_Jet110, prescaleHLT_Jet150;
  int prescaleHLT_Jet190, prescaleHLT_Jet240, prescaleHLT_Jet370, prescaleHLT_Jet370_NoJetID;


  bool triggerHLT_DiJetAve15U_v4           ;
  bool triggerHLT_DiJetAve30U_v4           ;
  bool triggerHLT_DiJetAve50U_v4           ;
  bool triggerHLT_DiJetAve70U_v4           ;
  bool triggerHLT_DiJetAve100U_v4          ;
  bool triggerHLT_DiJetAve140U_v4          ;
  bool triggerHLT_DiJetAve180U_v4          ;
  bool triggerHLT_DiJetAve300U_v4          ;
  bool triggerHLT_BTagMu_DiJet20_Mu5       ;
  bool triggerHLT_BTagMu_DiJet40_Mu5       ;
  bool triggerHLT_BTagMu_DiJet70_Mu5       ;
  bool triggerHLT_BTagMu_DiJet110_Mu5      ;
  bool triggerHLT_BTagMu_DiJet60_Mu7_v2    ;
  bool triggerHLT_BTagMu_DiJet80_Mu9_v2    ;
  bool triggerHLT_BTagMu_DiJet100_Mu9_v2   ;
  
  int prescaleHLT_DiJetAve15U_v4           ;
  int prescaleHLT_DiJetAve30U_v4           ;
  int prescaleHLT_DiJetAve50U_v4           ;
  int prescaleHLT_DiJetAve70U_v4           ;
  int prescaleHLT_DiJetAve100U_v4          ;
  int prescaleHLT_DiJetAve140U_v4          ;
  int prescaleHLT_DiJetAve180U_v4          ;
  int prescaleHLT_DiJetAve300U_v4          ;
  int prescaleHLT_BTagMu_DiJet20_Mu5       ;
  int prescaleHLT_BTagMu_DiJet40_Mu5       ;
  int prescaleHLT_BTagMu_DiJet70_Mu5       ;
  int prescaleHLT_BTagMu_DiJet110_Mu5      ;
  int prescaleHLT_BTagMu_DiJet60_Mu7_v2    ;
  int prescaleHLT_BTagMu_DiJet80_Mu9_v2    ;
  int prescaleHLT_BTagMu_DiJet100_Mu9_v2   ;

  unsigned int eventNumber ;
  unsigned int runNumber ;
  unsigned int lumiBlockNumber ;

  unsigned int numberOfPUVertices;
  unsigned int numberOfPrimaryVertices ;
  unsigned int numberOfTracksAtPV;
  float PVx;
  float PVy;
  float PVz;
  float PVChi2;
  float PVndof;
  float PVNormalizedChi2;

  float pthat;
  bool isBGluonSplitting;
  bool isCGluonSplitting;

  //Basic Jet Information
  int nJets;

  math::XYZTLorentzVector jetP4[MAXJETS];               
  float jetPt[MAXJETS];                                 
  float jetEta[MAXJETS];                                
  float jetPhi[MAXJETS];                                
  float jetEMFraction[MAXJETS];        
  float jetChargedEmEnergyFraction[MAXJETS];
  float jetNeutralEmEnergyFraction[MAXJETS];
  float jetChargedHadronEnergyFraction[MAXJETS];
  float jetNeutralHadronEnergyFraction[MAXJETS];
  float jetChargedMultiplicity[MAXJETS];
  float jetMass[MAXJETS];                               
  int jetnConstituents[MAXJETS];  
  int jetnTracks[MAXJETS];                           
  //  int jetnElectrons[MAXJETS];                              
  //  int jetnMuons[MAXJETS];                                  
  math::XYZVector jetVertex[MAXJETS];                   
  float jetVertexChi2[MAXJETS];               
  float jetVertexChi2Ndof[MAXJETS];           
  float jetVertexNormalizedChi2[MAXJETS];    

  //Track Information
  int nTracks;

  int trackJetIndex[MAXTRACKS];
  bool trackSelected[MAXTRACKS];
  math::XYZVector track3Momentum[MAXTRACKS];
  float trackTransverseMomentum[MAXTRACKS];
  float trackEta[MAXTRACKS];
  float trackPhi[MAXTRACKS];
  float trackMomentum[MAXTRACKS];
  int trackNHits[MAXTRACKS];
  int trackNPixelHits[MAXTRACKS];
  float trackChi2[MAXTRACKS];
  float trackNormChi2[MAXTRACKS];
  int trackQuality[MAXTRACKS];
  float trackLongitudinalImpactParameter[MAXTRACKS];
  float trackIP[MAXTRACKS];
  float trackDecayLength[MAXTRACKS];
  float trackDistJetAxis[MAXTRACKS];
  float trackDeltaR[MAXTRACKS];
  float trackIP3d[MAXTRACKS];
  float trackIP2d[MAXTRACKS];
  float trackIP3dError[MAXTRACKS];
  float trackIP2dError[MAXTRACKS];
  int trackHasSharedPix1[MAXTRACKS];
  int trackHasSharedPix2[MAXTRACKS];
  int trackHasSharedPix3[MAXTRACKS];
  int trackHasSharedPixAll[MAXTRACKS];
  bool trackIsVertexTrack[MAXTRACKS];

  //MC Truth Information
  int MCTrueFlavor[MAXJETS];                          
 				       
  //secondaryVertexTagInfos:			       
  math::XYZVector SecondaryVertex[MAXJETS];             
  float SV3dDistance[MAXJETS];                          
  float SV3dDistanceError[MAXJETS];                     
  float SV2dDistance[MAXJETS];                          
  float SV2dDistanceError[MAXJETS];                     
  float SVChi2[MAXJETS];                
  float SVIPFirstAboveCharm[MAXJETS];                                
  float SVDegreesOfFreedom[MAXJETS];                    
  float SVNormChi2[MAXJETS];                            
  int SVnSelectedTracks[MAXJETS];                               
  float SVMass[MAXJETS];                                
  float SVEnergyRatio[MAXJETS];                                
  int SVnVertices[MAXJETS];                             
  int   SVnVertexTracks[MAXJETS];         
  int   SVnVertexTracksAll[MAXJETS];         
  int   SVnFirstVertexTracks[MAXJETS];         
  int   SVnFirstVertexTracksAll[MAXJETS];         
  float SVjetDeltaR[MAXJETS];
  float SVvtxSumVtxDirDeltaR[MAXJETS];
  float SVvtxSumJetDeltaR[MAXJETS];
  float SVvtxPt[MAXJETS];
  float SVvtxSumDirEta[MAXJETS];
  float SVvtxSumDirPhi[MAXJETS];
  float SVvtxDirEta[MAXJETS];
  float SVvtxDirPhi[MAXJETS];
  // added by Caroline
  float SVvtxSumPTrel[MAXJETS];
  float SVvtxDirPTrel[MAXJETS];
  float SVvtxDistJetAxis[MAXJETS];
  int   SVtotCharge[MAXJETS];
  // end add
               
  //impactParameterTagInfos
  int IPnSelectedTracks[MAXJETS];                       
  math::XYZVector IPghostTrackP3[MAXJETS];      
  float IPghostTrackPt[MAXJETS];                        
  float IPghostTrackPtRel[MAXJETS];                        
  float IPghostTrackEta[MAXJETS];                       
  float IPghostTrackPhi[MAXJETS];                       
  float IPghostTrackDeltaR[MAXJETS];        
  int   IPPix1SharedHits[MAXJETS];
  int   IPPix1TotalHits[MAXJETS];
  int   IPPix2SharedHits[MAXJETS];
  int   IPPix2TotalHits[MAXJETS];
  int   IPPix3SharedHits[MAXJETS];
  int   IPPix3TotalHits[MAXJETS];
  int   IPPixAllSharedHits[MAXJETS];
  int   IPPixAllTotalHits[MAXJETS];

  std::vector< int* > IP3dTrackQuality;    
  std::vector< int* > IP3dHasSharedPix1;
  std::vector< int* > IP3dHasSharedPix2;
  std::vector< int* > IP3dHasSharedPix3;
  std::vector< int* > IP3dHasSharedPixAll;
  std::vector< float* > IP3d;
  std::vector< float* > IP3dError;
  std::vector< float* > IP3dProbability;
  std::vector< float* > IP3dTrackPtRel;
  std::vector< float* > IP3dDistJetAxis;
  std::vector< float* > IP3dDecayLength;
  std::vector< float* > IP3dDeltaR;
  std::vector< float* > IP3dMomentum;
  std::vector< float* > IP3dTransverseMomentum;
  std::vector< float* > IP3dEta;
  std::vector< float* > IP3dPhi;
  std::vector< int* >   IP3dNHits;
  std::vector< int* >   IP3dNPixelHits;
  std::vector< float* > IP3dNormChi2;
  std::vector< int* >   IP2dTrackQuality;    
  std::vector< float* > IP2d;
  std::vector< float* > IP2dError;
  std::vector< float* > IP2dProbability;
  std::vector< float* > IP2dTrackPtRel;

  //softElectronTagInfos
  int nElectrons[MAXJETS]; 
                           
  float electron1Pt[MAXJETS];   			       
  float electron1Eta[MAXJETS];  			       
  float electron1Phi[MAXJETS];  			       
  int electron1NHits[MAXJETS];   		     
  int electron1NExpectedOuterHits[MAXJETS];   		       
  int electron1NPixelHits[MAXJETS];   		       
  float electron1NChi2[MAXJETS];			       
  float electron1PtRel[MAXJETS];   		       
  float electron1Sip2d[MAXJETS];   		       
  float electron1Ip2d[MAXJETS];   		       
  float electron1Ipe2d[MAXJETS];   		       
  float electron1Sip3d[MAXJETS];
  float electron1Ip3d[MAXJETS];
  float electron1Ipe3d[MAXJETS];   		          		          		       
  float electron1P0Par[MAXJETS];   		       
  float electron1DeltaR[MAXJETS];  		       
  float electron1EtaRel[MAXJETS];  		       
  float electron1Ratio[MAXJETS];   		     
  int electron1TrackQuality[MAXJETS];   		       
  float electron1RatioRel[MAXJETS];  
  float electron1eSuperClusterOverP[MAXJETS];
  float electron1eSeedClusterOverP[MAXJETS];
  float electron1eSeedClusterOverPout[MAXJETS];
  float electron1eEleClusterOverPout[MAXJETS];
  float electron1deltaEtaSuperClusterTrackAtVtx[MAXJETS];
  float electron1deltaEtaSeedClusterTrackAtCalo[MAXJETS];
  float electron1deltaEtaEleClusterTrackAtCalo[MAXJETS];
  float electron1deltaPhiSuperClusterTrackAtVtx[MAXJETS];
  float electron1deltaPhiSeedClusterTrackAtCalo[MAXJETS];
  float electron1deltaPhiEleClusterTrackAtCalo[MAXJETS];                  

  float electron2Pt[MAXJETS];   			       
  float electron2Eta[MAXJETS];  			       
  float electron2Phi[MAXJETS];  			       
  int electron2NHits[MAXJETS];   		     
  int electron2NExpectedOuterHits[MAXJETS];   		       
  int electron2NPixelHits[MAXJETS];   		       
  float electron2NChi2[MAXJETS];			       
  float electron2PtRel[MAXJETS];   		       
  float electron2Sip2d[MAXJETS];   		       
  float electron2Ip2d[MAXJETS];   		       
  float electron2Ipe2d[MAXJETS];   		       
  float electron2Sip3d[MAXJETS];
  float electron2Ip3d[MAXJETS];
  float electron2Ipe3d[MAXJETS];   		          		          		       
  float electron2P0Par[MAXJETS];   		       
  float electron2DeltaR[MAXJETS];  		       
  float electron2EtaRel[MAXJETS];  		       
  float electron2Ratio[MAXJETS];   		     
  int electron2TrackQuality[MAXJETS];   		       
  float electron2RatioRel[MAXJETS];
  float electron2eSuperClusterOverP[MAXJETS];
  float electron2eSeedClusterOverP[MAXJETS];
  float electron2eSeedClusterOverPout[MAXJETS];
  float electron2eEleClusterOverPout[MAXJETS];
  float electron2deltaEtaSuperClusterTrackAtVtx[MAXJETS];
  float electron2deltaEtaSeedClusterTrackAtCalo[MAXJETS];
  float electron2deltaEtaEleClusterTrackAtCalo[MAXJETS];
  float electron2deltaPhiSuperClusterTrackAtVtx[MAXJETS];
  float electron2deltaPhiSeedClusterTrackAtCalo[MAXJETS];
  float electron2deltaPhiEleClusterTrackAtCalo[MAXJETS];

  float electron3Pt[MAXJETS];   			       
  float electron3Eta[MAXJETS];  			       
  float electron3Phi[MAXJETS];  			       
  int electron3NHits[MAXJETS];   		     
  int electron3NExpectedOuterHits[MAXJETS];   		       
  int electron3NPixelHits[MAXJETS];   		       
  float electron3NChi2[MAXJETS];			       
  float electron3PtRel[MAXJETS];   		       
  float electron3Sip2d[MAXJETS];   		       
  float electron3Ip2d[MAXJETS];   		       
  float electron3Ipe2d[MAXJETS];   		       
  float electron3Sip3d[MAXJETS];
  float electron3Ip3d[MAXJETS];
  float electron3Ipe3d[MAXJETS];   		          		          		       
  float electron3P0Par[MAXJETS];   		       
  float electron3DeltaR[MAXJETS];  		       
  float electron3EtaRel[MAXJETS];  		       
  float electron3Ratio[MAXJETS];   		     
  int electron3TrackQuality[MAXJETS];   		       
  float electron3RatioRel[MAXJETS];
  float electron3eSuperClusterOverP[MAXJETS];
  float electron3eSeedClusterOverP[MAXJETS];
  float electron3eSeedClusterOverPout[MAXJETS];
  float electron3eEleClusterOverPout[MAXJETS];
  float electron3deltaEtaSuperClusterTrackAtVtx[MAXJETS];
  float electron3deltaEtaSeedClusterTrackAtCalo[MAXJETS];
  float electron3deltaEtaEleClusterTrackAtCalo[MAXJETS];
  float electron3deltaPhiSuperClusterTrackAtVtx[MAXJETS];
  float electron3deltaPhiSeedClusterTrackAtCalo[MAXJETS];
  float electron3deltaPhiEleClusterTrackAtCalo[MAXJETS];

  float electron4Pt[MAXJETS];   			       
  float electron4Eta[MAXJETS];  			       
  float electron4Phi[MAXJETS];  			       
  int electron4NHits[MAXJETS];   		     
  int electron4NExpectedOuterHits[MAXJETS];   		       
  int electron4NPixelHits[MAXJETS];   		       
  float electron4NChi2[MAXJETS];			       
  float electron4PtRel[MAXJETS];   		       
  float electron4Sip2d[MAXJETS];   		       
  float electron4Ip2d[MAXJETS];   		       
  float electron4Ipe2d[MAXJETS];   		       
  float electron4Sip3d[MAXJETS];
  float electron4Ip3d[MAXJETS];
  float electron4Ipe3d[MAXJETS];   		          		          		       
  float electron4P0Par[MAXJETS];   		       
  float electron4DeltaR[MAXJETS];  		       
  float electron4EtaRel[MAXJETS];  		       
  float electron4Ratio[MAXJETS];   		     
  int electron4TrackQuality[MAXJETS];   		       
  float electron4RatioRel[MAXJETS];
  float electron4eSuperClusterOverP[MAXJETS];
  float electron4eSeedClusterOverP[MAXJETS];
  float electron4eSeedClusterOverPout[MAXJETS];
  float electron4eEleClusterOverPout[MAXJETS];
  float electron4deltaEtaSuperClusterTrackAtVtx[MAXJETS];
  float electron4deltaEtaSeedClusterTrackAtCalo[MAXJETS];
  float electron4deltaEtaEleClusterTrackAtCalo[MAXJETS];
  float electron4deltaPhiSuperClusterTrackAtVtx[MAXJETS];
  float electron4deltaPhiSeedClusterTrackAtCalo[MAXJETS];
  float electron4deltaPhiEleClusterTrackAtCalo[MAXJETS];

  std::vector<float*> electronPt;   			       
  std::vector<float*> electronEta;  			       
  std::vector<float*> electronPhi;  			       
  std::vector<int*> electronNHits;   		     
  std::vector<int*> electronNExpectedOuterHits;   		       
  std::vector<int*> electronNPixelHits;   		       
  std::vector<float*> electronNChi2;			       
  std::vector<float*> electronPtRel;   		       
  std::vector<float*> electronSip2d;   		       
  std::vector<float*> electronIp2d;   		       
  std::vector<float*> electronIpe2d;   		       
  std::vector<float*> electronSip3d;
  std::vector<float*> electronIp3d;
  std::vector<float*> electronIpe3d;   		          		          		       
  std::vector<float*> electronP0Par;   		       
  std::vector<float*> electronDeltaR;  		       
  std::vector<float*> electronEtaRel;  		       
  std::vector<float*> electronRatio;   		     
  std::vector<int*> electronTrackQuality;   		       
  std::vector<float*> electronRatioRel;
  std::vector<float*> electroneSuperClusterOverP;
  std::vector<float*> electroneSeedClusterOverP;
  std::vector<float*> electroneSeedClusterOverPout;
  std::vector<float*> electroneEleClusterOverPout;
  std::vector<float*> electrondeltaEtaSuperClusterTrackAtVtx;
  std::vector<float*> electrondeltaEtaSeedClusterTrackAtCalo;
  std::vector<float*> electrondeltaEtaEleClusterTrackAtCalo;
  std::vector<float*> electrondeltaPhiSuperClusterTrackAtVtx;
  std::vector<float*> electrondeltaPhiSeedClusterTrackAtCalo;
  std::vector<float*> electrondeltaPhiEleClusterTrackAtCalo;
						       
  //softMuonTagInfos	
  int nMuons[MAXJETS];                                

  bool  muon1IsGlobal[MAXJETS];
  bool  muon1IsTracker[MAXJETS];
  bool  muon1IsStandalone[MAXJETS];
  float muon1Pt[MAXJETS];   			       
  float muon1Eta[MAXJETS];  			       
  float muon1Phi[MAXJETS];  	
  int   muon1NumberOfMatches[MAXJETS];
  int   muon1GlobalMuonHits[MAXJETS];
  int   muon1InnerValidHits[MAXJETS];
  int   muon1NExpectedOuterHits[MAXJETS];   			       
  int   muon1NPixelHits[MAXJETS];
  float muon1InnerNChi2[MAXJETS];
  float muon1GlobalNChi2[MAXJETS];
  float muon1VzPVDist[MAXJETS];
  float muon1PtRel[MAXJETS];   
  float muon1Sip2d[MAXJETS];   		       
  float muon1Ip2d[MAXJETS];   		       
  float muon1Ipe2d[MAXJETS];   		       
  float muon1Sip3d[MAXJETS];
  float muon1Ip3d[MAXJETS];
  float muon1Ipe3d[MAXJETS];   	
  float muon1P0Par[MAXJETS];   			       
  float muon1DeltaR[MAXJETS];  			       
  float muon1EtaRel[MAXJETS];  			       
  float muon1Ratio[MAXJETS];   			    
  int   muon1TrackQuality[MAXJETS];   			       
  float muon1RatioRel[MAXJETS];                          

  bool  muon2IsGlobal[MAXJETS];
  bool  muon2IsTracker[MAXJETS];
  bool  muon2IsStandalone[MAXJETS];
  float muon2Pt[MAXJETS];   			       
  float muon2Eta[MAXJETS];  			       
  float muon2Phi[MAXJETS];  	
  int   muon2NumberOfMatches[MAXJETS];
  int   muon2GlobalMuonHits[MAXJETS];
  int   muon2InnerValidHits[MAXJETS];
  int   muon2NExpectedOuterHits[MAXJETS];   			       
  int   muon2NPixelHits[MAXJETS];
  float muon2InnerNChi2[MAXJETS];
  float muon2GlobalNChi2[MAXJETS];
  float muon2VzPVDist[MAXJETS];
  float muon2PtRel[MAXJETS];   
  float muon2Sip2d[MAXJETS];   		       
  float muon2Ip2d[MAXJETS];   		       
  float muon2Ipe2d[MAXJETS];   		       
  float muon2Sip3d[MAXJETS];
  float muon2Ip3d[MAXJETS];
  float muon2Ipe3d[MAXJETS];   	
  float muon2P0Par[MAXJETS];   			       
  float muon2DeltaR[MAXJETS];  			       
  float muon2EtaRel[MAXJETS];  			       
  float muon2Ratio[MAXJETS];   			    
  int   muon2TrackQuality[MAXJETS];   			       
  float muon2RatioRel[MAXJETS];                          

  bool  muon3IsGlobal[MAXJETS];
  bool  muon3IsTracker[MAXJETS];
  bool  muon3IsStandalone[MAXJETS];
  float muon3Pt[MAXJETS];   			       
  float muon3Eta[MAXJETS];  			       
  float muon3Phi[MAXJETS];  	
  int   muon3NumberOfMatches[MAXJETS];
  int   muon3GlobalMuonHits[MAXJETS];
  int   muon3InnerValidHits[MAXJETS];
  int   muon3NExpectedOuterHits[MAXJETS];   			       
  int   muon3NPixelHits[MAXJETS];
  float muon3InnerNChi2[MAXJETS];
  float muon3GlobalNChi2[MAXJETS];
  float muon3VzPVDist[MAXJETS];
  float muon3PtRel[MAXJETS];   
  float muon3Sip2d[MAXJETS];   		       
  float muon3Ip2d[MAXJETS];   		       
  float muon3Ipe2d[MAXJETS];   		       
  float muon3Sip3d[MAXJETS];
  float muon3Ip3d[MAXJETS];
  float muon3Ipe3d[MAXJETS];   	
  float muon3P0Par[MAXJETS];   			       
  float muon3DeltaR[MAXJETS];  			       
  float muon3EtaRel[MAXJETS];  			       
  float muon3Ratio[MAXJETS];   			    
  int   muon3TrackQuality[MAXJETS];   			       
  float muon3RatioRel[MAXJETS];                          

  bool  muon4IsGlobal[MAXJETS];
  bool  muon4IsTracker[MAXJETS];
  bool  muon4IsStandalone[MAXJETS];
  float muon4Pt[MAXJETS];   			       
  float muon4Eta[MAXJETS];  			       
  float muon4Phi[MAXJETS];  	
  int   muon4NumberOfMatches[MAXJETS];
  int   muon4GlobalMuonHits[MAXJETS];
  int   muon4InnerValidHits[MAXJETS];
  int   muon4NExpectedOuterHits[MAXJETS];   			       
  int   muon4NPixelHits[MAXJETS];
  float muon4InnerNChi2[MAXJETS];
  float muon4GlobalNChi2[MAXJETS];
  float muon4VzPVDist[MAXJETS];
  float muon4PtRel[MAXJETS];   
  float muon4Sip2d[MAXJETS];   		       
  float muon4Ip2d[MAXJETS];   		       
  float muon4Ipe2d[MAXJETS];   		       
  float muon4Sip3d[MAXJETS];
  float muon4Ip3d[MAXJETS];
  float muon4Ipe3d[MAXJETS];   	
  float muon4P0Par[MAXJETS];   			       
  float muon4DeltaR[MAXJETS];  			       
  float muon4EtaRel[MAXJETS];  			       
  float muon4Ratio[MAXJETS];   			    
  int   muon4TrackQuality[MAXJETS];   			       
  float muon4RatioRel[MAXJETS];                          



  std::vector< bool* > muonIsGlobal;
  std::vector< bool* >  muonIsTracker;
  std::vector<bool*>  muonIsStandalone;
  std::vector<float*> muonPt;   			       
  std::vector<float*> muonEta;  			       
  std::vector<float*> muonPhi;  	
  std::vector<int*>   muonNumberOfMatches;
  std::vector<int*>   muonGlobalMuonHits;
  std::vector<int*>   muonInnerValidHits;
  std::vector<int*>   muonNExpectedOuterHits;   			       
  std::vector<int*>   muonNPixelHits;
  std::vector<float*> muonInnerNChi2;
  std::vector<float*> muonGlobalNChi2;
  std::vector<float*> muonVzPVDist;
  std::vector<float*> muonPtRel;   
  std::vector<float*> muonSip2d;   		       
  std::vector<float*> muonIp2d;   		       
  std::vector<float*> muonIpe2d;   		       
  std::vector<float*> muonSip3d;
  std::vector<float*> muonIp3d;
  std::vector<float*> muonIpe3d;   	
  std::vector<float*> muonP0Par;   			       
  std::vector<float*> muonDeltaR;  			       
  std::vector<float*> muonEtaRel;  			       
  std::vector<float*> muonRatio;   			    
  std::vector<int*>   muonTrackQuality;   			       
  std::vector<float*> muonRatioRel; 



  std::map< std::string, float* > bTagArrays;


  //added by Caroline for prescale
  bool isValidHltConfig_;
  HLTConfigProvider  hltConfigProvider_;
  //end add

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//

using namespace edm;
using namespace std;
using namespace reco;
using namespace ROOT::Math::VectorUtil;

namespace{
  struct JetRefCompare : public binary_function<RefToBase<Jet>, RefToBase<Jet>, bool> {
    inline bool operator () (const RefToBase<Jet> &j1,
			     const RefToBase<Jet> &j2) const
    { return j1.id() < j2.id() || (j1.id() == j2.id() && j1.key() < j2.key()); }
  };
}

TagNtupleProducer::TagNtupleProducer(const edm::ParameterSet& iConfig):
  getMCTruth_ (iConfig.getParameter<bool>( "getMCTruth" )),
  getMCPUInfo_ (iConfig.getParameter<bool>( "getMCPUInfo" )),
  getSharedHitInfo_(iConfig.getParameter<bool>( "getSharedHitInfo" )),
  jet_src_(iConfig.getParameter<edm::InputTag>( "jetSrc" )),
  SVComputer_ (iConfig.getParameter<edm::InputTag>( "svComputer")),
  triggerTag_(iConfig.getParameter<edm::InputTag>("TriggerTag")),
  jet_MC_src_(iConfig.getParameter<edm::InputTag>( "jetMCSrc" )),
  jet_tracks_(iConfig.getParameter<edm::InputTag>( "jetTracks" )),
  primaryVertexProducer_  (iConfig.getParameter<InputTag>("primaryVertex")),
  SV_tag_infos_(iConfig.getParameter<edm::InputTag>( "SVTagInfos" )),
  IP_tag_infos_(iConfig.getParameter<edm::InputTag>( "IPTagInfos" )),
  electron_tag_infos_(iConfig.getParameter<edm::InputTag>( "ElectronTagInfos" )),
  muon_tag_infos_(iConfig.getParameter<edm::InputTag>( "MuonTagInfos" )),
  label_(iConfig.getParameter<string>( "Label" )),
  filename_(iConfig.getParameter<string>( "filename" )),
  bTag_Config_(iConfig.getParameter< vector<edm::ParameterSet> >("bTagConfig"))  //b tagger outputs configured in python file
{
  string alias;
  
  file = new TFile (filename_.c_str(), "RECREATE" );
  // create tree structure
  tree = new TTree("t","t");
    
  
  for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
    {
      bTagArrays[ibTag->getParameter<string>("alias")] = new float[MAXJETS];
    }
  
  for(int i=0; i<4; i++){
    IP3dTrackQuality.push_back( new int[MAXJETS]);    
    IP3dHasSharedPix1.push_back(  new int[MAXJETS]);
    IP3dHasSharedPix2.push_back( new int[MAXJETS]);
    IP3dHasSharedPix3.push_back( new int[MAXJETS]);
    IP3dHasSharedPixAll.push_back( new int[MAXJETS]);
    IP3d.push_back( new float[MAXJETS]);
    IP3dError.push_back( new float[MAXJETS]);
    IP3dProbability.push_back( new float[MAXJETS]);
    IP3dTrackPtRel.push_back( new float[MAXJETS]);
    IP3dDistJetAxis.push_back( new float[MAXJETS]);
    IP3dDecayLength.push_back(new float[MAXJETS] );
    IP3dDeltaR.push_back( new float[MAXJETS]);
    IP3dMomentum.push_back( new float[MAXJETS]);
    IP3dTransverseMomentum.push_back( new float[MAXJETS]);
    IP3dEta.push_back( new float[MAXJETS]);
    IP3dPhi.push_back( new float[MAXJETS]);
    IP3dNHits.push_back( new int[MAXJETS]);
    IP3dNPixelHits.push_back( new int[MAXJETS]);
    IP3dNormChi2.push_back( new float[MAXJETS]);
    IP2dTrackQuality.push_back( new int[MAXJETS]);    
    IP2d.push_back( new float[MAXJETS]);
    IP2dError.push_back( new float[MAXJETS]);
    IP2dProbability.push_back( new float[MAXJETS]);
    IP2dTrackPtRel.push_back( new float[MAXJETS]);
  }
  
  muonIsGlobal            .push_back(muon1IsGlobal           ); muonIsGlobal            .push_back(muon2IsGlobal);
  muonIsTracker           .push_back(muon1IsTracker          ); muonIsTracker           .push_back(muon2IsTracker          ); 
  muonIsStandalone        .push_back(muon1IsStandalone       ); muonIsStandalone        .push_back(muon2IsStandalone       ); 
  muonPt                  .push_back(muon1Pt                 ); muonPt                  .push_back(muon2Pt                 );       
  muonEta                 .push_back(muon1Eta                ); muonEta                 .push_back(muon2Eta                );       
  muonPhi                 .push_back(muon1Phi                ); muonPhi                 .push_back(muon2Phi                ); 
  muonNumberOfMatches     .push_back(muon1NumberOfMatches    ); muonNumberOfMatches     .push_back(muon2NumberOfMatches    ); 
  muonGlobalMuonHits      .push_back(muon1GlobalMuonHits     ); muonGlobalMuonHits      .push_back(muon2GlobalMuonHits     ); 
  muonInnerValidHits      .push_back(muon1InnerValidHits     ); muonInnerValidHits      .push_back(muon2InnerValidHits     ); 
  muonNExpectedOuterHits  .push_back(muon1NExpectedOuterHits ); muonNExpectedOuterHits  .push_back(muon2NExpectedOuterHits ); 
  muonNPixelHits          .push_back(muon1NPixelHits         ); muonNPixelHits          .push_back(muon2NPixelHits         ); 
  muonInnerNChi2          .push_back(muon1InnerNChi2         ); muonInnerNChi2          .push_back(muon2InnerNChi2         ); 
  muonGlobalNChi2         .push_back(muon1GlobalNChi2        ); muonGlobalNChi2         .push_back(muon2GlobalNChi2        ); 
  muonVzPVDist            .push_back(muon1VzPVDist           ); muonVzPVDist            .push_back(muon2VzPVDist           ); 
  muonPtRel               .push_back(muon1PtRel              ); muonPtRel               .push_back(muon2PtRel              ); 
  muonSip2d               .push_back(muon1Sip2d              ); muonSip2d               .push_back(muon2Sip2d              ); 
  muonIp2d                .push_back(muon1Ip2d               ); muonIp2d                .push_back(muon2Ip2d               ); 
  muonIpe2d               .push_back(muon1Ipe2d              ); muonIpe2d               .push_back(muon2Ipe2d              ); 
  muonSip3d               .push_back(muon1Sip3d              ); muonSip3d               .push_back(muon2Sip3d              ); 
  muonIp3d                .push_back(muon1Ip3d               ); muonIp3d                .push_back(muon2Ip3d               ); 
  muonIpe3d               .push_back(muon1Ipe3d              ); muonIpe3d               .push_back(muon2Ipe3d              ); 
  muonP0Par               .push_back(muon1P0Par              ); muonP0Par               .push_back(muon2P0Par              );       
  muonDeltaR              .push_back(muon1DeltaR             ); muonDeltaR              .push_back(muon2DeltaR             );       
  muonEtaRel              .push_back(muon1EtaRel             ); muonEtaRel              .push_back(muon2EtaRel             );       
  muonRatio               .push_back(muon1Ratio              ); muonRatio               .push_back(muon2Ratio              );       
  muonTrackQuality        .push_back(muon1TrackQuality       ); muonTrackQuality        .push_back(muon2TrackQuality       );       
  muonRatioRel            .push_back(muon1RatioRel           ); muonRatioRel            .push_back(muon2RatioRel           ); 
  
  muonIsGlobal            .push_back(muon3IsGlobal           ); muonIsGlobal            .push_back(muon4IsGlobal           ); 
  muonIsTracker           .push_back(muon3IsTracker          ); muonIsTracker           .push_back(muon4IsTracker          ); 
  muonIsStandalone        .push_back(muon3IsStandalone       ); muonIsStandalone        .push_back(muon4IsStandalone       ); 
  muonPt                  .push_back(muon3Pt                 ); muonPt                  .push_back(muon4Pt                 );       
  muonEta                 .push_back(muon3Eta                ); muonEta                 .push_back(muon4Eta                );       
  muonPhi                 .push_back(muon3Phi                ); muonPhi                 .push_back(muon4Phi                ); 
  muonNumberOfMatches     .push_back(muon3NumberOfMatches    ); muonNumberOfMatches     .push_back(muon4NumberOfMatches    ); 
  muonGlobalMuonHits      .push_back(muon3GlobalMuonHits     ); muonGlobalMuonHits      .push_back(muon4GlobalMuonHits     ); 
  muonInnerValidHits      .push_back(muon3InnerValidHits     ); muonInnerValidHits      .push_back(muon4InnerValidHits     ); 
  muonNExpectedOuterHits  .push_back(muon3NExpectedOuterHits ); muonNExpectedOuterHits  .push_back(muon4NExpectedOuterHits ); 
  muonNPixelHits          .push_back(muon3NPixelHits         ); muonNPixelHits          .push_back(muon4NPixelHits         ); 
  muonInnerNChi2          .push_back(muon3InnerNChi2         ); muonInnerNChi2          .push_back(muon4InnerNChi2         ); 
  muonGlobalNChi2         .push_back(muon3GlobalNChi2        ); muonGlobalNChi2         .push_back(muon4GlobalNChi2        ); 
  muonVzPVDist            .push_back(muon3VzPVDist           ); muonVzPVDist            .push_back(muon4VzPVDist           ); 
  muonPtRel               .push_back(muon3PtRel              ); muonPtRel               .push_back(muon4PtRel              ); 
  muonSip2d               .push_back(muon3Sip2d              ); muonSip2d               .push_back(muon4Sip2d              ); 
  muonIp2d                .push_back(muon3Ip2d               ); muonIp2d                .push_back(muon4Ip2d               ); 
  muonIpe2d               .push_back(muon3Ipe2d              ); muonIpe2d               .push_back(muon4Ipe2d              ); 
  muonSip3d               .push_back(muon3Sip3d              ); muonSip3d               .push_back(muon4Sip3d              ); 
  muonIp3d                .push_back(muon3Ip3d               ); muonIp3d                .push_back(muon4Ip3d               ); 
  muonIpe3d               .push_back(muon3Ipe3d              ); muonIpe3d               .push_back(muon4Ipe3d              ); 
  muonP0Par               .push_back(muon3P0Par              ); muonP0Par               .push_back(muon4P0Par              );       
  muonDeltaR              .push_back(muon3DeltaR             ); muonDeltaR              .push_back(muon4DeltaR             );       
  muonEtaRel              .push_back(muon3EtaRel             ); muonEtaRel              .push_back(muon4EtaRel             );       
  muonRatio               .push_back(muon3Ratio              ); muonRatio               .push_back(muon4Ratio              );       
  muonTrackQuality        .push_back(muon3TrackQuality       ); muonTrackQuality        .push_back(muon4TrackQuality       );       
  muonRatioRel            .push_back(muon3RatioRel           ); muonRatioRel            .push_back(muon4RatioRel           ); 


  electronPt                 .push_back(electron1Pt                   );  electronPt                 .push_back(electron2Pt                   );
  electronEta                .push_back(electron1Eta                  );  electronEta                .push_back(electron2Eta                  );			
  electronPhi                .push_back(electron1Phi                  );  electronPhi                .push_back(electron2Phi                  );			
  electronNHits              .push_back(electron1NHits                );  electronNHits              .push_back(electron2NHits                );		
  electronNExpectedOuterHits .push_back(electron1NExpectedOuterHits   );  electronNExpectedOuterHits .push_back(electron2NExpectedOuterHits   );		
  electronNPixelHits         .push_back(electron1NPixelHits           );  electronNPixelHits         .push_back(electron2NPixelHits           );		
  electronNChi2              .push_back(electron1NChi2                );  electronNChi2              .push_back(electron2NChi2                );			
  electronPtRel              .push_back(electron1PtRel                );  electronPtRel              .push_back(electron2PtRel                );		
  electronSip2d              .push_back(electron1Sip2d                );  electronSip2d              .push_back(electron2Sip2d                );		
  electronIp2d               .push_back(electron1Ip2d                 );  electronIp2d               .push_back(electron2Ip2d                 );		
  electronIpe2d              .push_back(electron1Ipe2d                );  electronIpe2d              .push_back(electron2Ipe2d                );		
  electronSip3d              .push_back(electron1Sip3d                );  electronSip3d              .push_back(electron2Sip3d                );
  electronIp3d               .push_back(electron1Ip3d                 );  electronIp3d               .push_back(electron2Ip3d                 );
  electronIpe3d              .push_back(electron1Ipe3d                );  electronIpe3d              .push_back(electron2Ipe3d                );
  electronP0Par              .push_back(electron1P0Par                );  electronP0Par              .push_back(electron2P0Par                );		
  electronDeltaR             .push_back(electron1DeltaR               );  electronDeltaR             .push_back(electron2DeltaR               );		
  electronEtaRel             .push_back(electron1EtaRel               );  electronEtaRel             .push_back(electron2EtaRel               );		
  electronRatio              .push_back(electron1Ratio                );  electronRatio              .push_back(electron2Ratio                );		
  electronTrackQuality       .push_back(electron1TrackQuality         );  electronTrackQuality       .push_back(electron2TrackQuality         );	    
  electronRatioRel           .push_back(electron1RatioRel             );  electronRatioRel           .push_back(electron2RatioRel             );

  electronPt                 .push_back(electron3Pt                   );  electronPt                 .push_back(electron4Pt                   );
  electronEta                .push_back(electron3Eta                  );  electronEta                .push_back(electron4Eta                  );			
  electronPhi                .push_back(electron3Phi                  );  electronPhi                .push_back(electron4Phi                  );			
  electronNHits              .push_back(electron3NHits                );  electronNHits              .push_back(electron4NHits                );		
  electronNExpectedOuterHits .push_back(electron3NExpectedOuterHits   );  electronNExpectedOuterHits .push_back(electron4NExpectedOuterHits   );		
  electronNPixelHits         .push_back(electron3NPixelHits           );  electronNPixelHits         .push_back(electron4NPixelHits           );		
  electronNChi2              .push_back(electron3NChi2                );  electronNChi2              .push_back(electron4NChi2                );			
  electronPtRel              .push_back(electron3PtRel                );  electronPtRel              .push_back(electron4PtRel                );		
  electronSip2d              .push_back(electron3Sip2d                );  electronSip2d              .push_back(electron4Sip2d                );		
  electronIp2d               .push_back(electron3Ip2d                 );  electronIp2d               .push_back(electron4Ip2d                 );		
  electronIpe2d              .push_back(electron3Ipe2d                );  electronIpe2d              .push_back(electron4Ipe2d                );		
  electronSip3d              .push_back(electron3Sip3d                );  electronSip3d              .push_back(electron4Sip3d                );
  electronIp3d               .push_back(electron3Ip3d                 );  electronIp3d               .push_back(electron4Ip3d                 );
  electronIpe3d              .push_back(electron3Ipe3d                );  electronIpe3d              .push_back(electron4Ipe3d                );
  electronP0Par              .push_back(electron3P0Par                );  electronP0Par              .push_back(electron4P0Par                );		
  electronDeltaR             .push_back(electron3DeltaR               );  electronDeltaR             .push_back(electron4DeltaR               );		
  electronEtaRel             .push_back(electron3EtaRel               );  electronEtaRel             .push_back(electron4EtaRel               );		
  electronRatio              .push_back(electron3Ratio                );  electronRatio              .push_back(electron4Ratio                );		
  electronTrackQuality       .push_back(electron3TrackQuality         );  electronTrackQuality       .push_back(electron4TrackQuality         );	    
  electronRatioRel           .push_back(electron3RatioRel             );  electronRatioRel           .push_back(electron4RatioRel             );

  //Some Electron Information on gsfTrack/ClusterMatching
  electroneSuperClusterOverP.            push_back(electron1eSuperClusterOverP);
  electroneSeedClusterOverP.             push_back(electron1eSeedClusterOverP);
  electroneSeedClusterOverPout.          push_back(electron1eSeedClusterOverPout);
  electroneEleClusterOverPout.           push_back(electron1eEleClusterOverPout);
  electrondeltaEtaSuperClusterTrackAtVtx.push_back(electron1deltaEtaSuperClusterTrackAtVtx);
  electrondeltaEtaSeedClusterTrackAtCalo.push_back(electron1deltaEtaSeedClusterTrackAtCalo);
  electrondeltaEtaEleClusterTrackAtCalo. push_back(electron1deltaEtaEleClusterTrackAtCalo);
  electrondeltaPhiSuperClusterTrackAtVtx.push_back(electron1deltaPhiSuperClusterTrackAtVtx);
  electrondeltaPhiSeedClusterTrackAtCalo.push_back(electron1deltaPhiSeedClusterTrackAtCalo);
  electrondeltaPhiEleClusterTrackAtCalo. push_back(electron1deltaPhiEleClusterTrackAtCalo);

  electroneSuperClusterOverP.            push_back(electron2eSuperClusterOverP);
  electroneSeedClusterOverP.             push_back(electron2eSeedClusterOverP);
  electroneSeedClusterOverPout.          push_back(electron2eSeedClusterOverPout);
  electroneEleClusterOverPout.           push_back(electron2eEleClusterOverPout);
  electrondeltaEtaSuperClusterTrackAtVtx.push_back(electron2deltaEtaSuperClusterTrackAtVtx);
  electrondeltaEtaSeedClusterTrackAtCalo.push_back(electron2deltaEtaSeedClusterTrackAtCalo);
  electrondeltaEtaEleClusterTrackAtCalo. push_back(electron2deltaEtaEleClusterTrackAtCalo);
  electrondeltaPhiSuperClusterTrackAtVtx.push_back(electron2deltaPhiSuperClusterTrackAtVtx);
  electrondeltaPhiSeedClusterTrackAtCalo.push_back(electron2deltaPhiSeedClusterTrackAtCalo);
  electrondeltaPhiEleClusterTrackAtCalo. push_back(electron2deltaPhiEleClusterTrackAtCalo);

  electroneSuperClusterOverP.            push_back(electron3eSuperClusterOverP);
  electroneSeedClusterOverP.             push_back(electron3eSeedClusterOverP);
  electroneSeedClusterOverPout.          push_back(electron3eSeedClusterOverPout);
  electroneEleClusterOverPout.           push_back(electron3eEleClusterOverPout);
  electrondeltaEtaSuperClusterTrackAtVtx.push_back(electron3deltaEtaSuperClusterTrackAtVtx);
  electrondeltaEtaSeedClusterTrackAtCalo.push_back(electron3deltaEtaSeedClusterTrackAtCalo);
  electrondeltaEtaEleClusterTrackAtCalo. push_back(electron3deltaEtaEleClusterTrackAtCalo);
  electrondeltaPhiSuperClusterTrackAtVtx.push_back(electron3deltaPhiSuperClusterTrackAtVtx);
  electrondeltaPhiSeedClusterTrackAtCalo.push_back(electron3deltaPhiSeedClusterTrackAtCalo);
  electrondeltaPhiEleClusterTrackAtCalo. push_back(electron3deltaPhiEleClusterTrackAtCalo);

  electroneSuperClusterOverP.            push_back(electron4eSuperClusterOverP);
  electroneSeedClusterOverP.             push_back(electron4eSeedClusterOverP);
  electroneSeedClusterOverPout.          push_back(electron4eSeedClusterOverPout);
  electroneEleClusterOverPout.           push_back(electron4eEleClusterOverPout);
  electrondeltaEtaSuperClusterTrackAtVtx.push_back(electron4deltaEtaSuperClusterTrackAtVtx);
  electrondeltaEtaSeedClusterTrackAtCalo.push_back(electron4deltaEtaSeedClusterTrackAtCalo);
  electrondeltaEtaEleClusterTrackAtCalo. push_back(electron4deltaEtaEleClusterTrackAtCalo);
  electrondeltaPhiSuperClusterTrackAtVtx.push_back(electron4deltaPhiSuperClusterTrackAtVtx);
  electrondeltaPhiSeedClusterTrackAtCalo.push_back(electron4deltaPhiSeedClusterTrackAtCalo);
  electrondeltaPhiEleClusterTrackAtCalo. push_back(electron4deltaPhiEleClusterTrackAtCalo);

  tree->Branch(  "triggerHLTL1Jet6U", &triggerHLTL1Jet6U, "triggerHLTL1Jet6U/O"); 
  tree->Branch(  "triggerHLTL1Jet10U", &triggerHLTL1Jet10U, "triggerHLTL1Jet10U/O"); 
  tree->Branch(  "triggerHLTJet15U",  &triggerHLTJet15U, "triggerHLTJet15U/O");
  tree->Branch(  "triggerHLTJet30U",  &triggerHLTJet30U, "triggerHLTJet30U/O");
  tree->Branch(  "triggerHLTJet50U",  &triggerHLTJet50U, "triggerHLTJet50U/O");
  tree->Branch(  "triggerHLTJet70U",  &triggerHLTJet70U, "triggerHLTJet70U/O");
  tree->Branch(  "triggerHLTJet100U",  &triggerHLTJet100U, "triggerHLTJet100U/O");
  tree->Branch(  "triggerHLTBTagIPJet50U", &triggerHLTBTagIPJet50U, "triggerHLTBTagIPJet50U/O");
  tree->Branch(  "triggerHLTBTagMuJet10U", &triggerHLTBTagMuJet10U, "triggerHLTBTagMuJet10U/O");
  tree->Branch(  "triggerHLTBTagMuJet20U", &triggerHLTBTagMuJet20U, "triggerHLTBTagMuJet20U/O");
  tree->Branch(  "triggerHLTBTagMuDiJet10U", &triggerHLTBTagMuDiJet10U, "triggerHLTBTagMuDiJet10U/O");
  tree->Branch(  "triggerHLTBTagMuDiJet20U", &triggerHLTBTagMuDiJet20U, "triggerHLTBTagMuDiJet20U/O");
  tree->Branch(  "triggerHLTBTagMuDiJet20UMu5", &triggerHLTBTagMuDiJet20UMu5, "triggerHLTBTagMuDiJet20UMu5/O");
  tree->Branch(  "triggerHLTBTagMuDiJet30U", &triggerHLTBTagMuDiJet30U, "triggerHLTBTagMuDiJet30U/O");
  tree->Branch(  "triggerHLTBTagMuDiJet30UMu5", &triggerHLTBTagMuDiJet30UMu5, "triggerHLTBTagMuDiJet30UMu5/O");

  tree->Branch(  "prescaleHLTL1Jet6U", &prescaleHLTL1Jet6U, "prescaleHLTL1Jet6U/I"); 
  tree->Branch(  "prescaleHLTL1Jet10U", &prescaleHLTL1Jet10U, "prescaleHLTL1Jet10U/I"); 
  tree->Branch(  "prescaleHLTJet15U",  &prescaleHLTJet15U, "prescaleHLTJet15U/I");
  tree->Branch(  "prescaleHLTJet30U",  &prescaleHLTJet30U, "prescaleHLTJet30U/I");
  tree->Branch(  "prescaleHLTJet50U",  &prescaleHLTJet50U, "prescaleHLTJet50U/I");
  tree->Branch(  "prescaleHLTJet70U",  &prescaleHLTJet70U, "prescaleHLTJet70U/I");
  tree->Branch(  "prescaleHLTJet100U",  &prescaleHLTJet100U, "prescaleHLTJet100U/I");
  tree->Branch(  "prescaleHLTBTagIPJet50U", &prescaleHLTBTagIPJet50U, "prescaleHLTBTagIPJet50U/I");
  tree->Branch(  "prescaleHLTBTagMuJet10U", &prescaleHLTBTagMuJet10U, "prescaleHLTBTagMuJet10U/I");
  tree->Branch(  "prescaleHLTBTagMuJet20U", &prescaleHLTBTagMuJet20U, "prescaleHLTBTagMuJet20U/I");
  tree->Branch(  "prescaleHLTBTagMuDiJet10U", &prescaleHLTBTagMuDiJet10U, "prescaleHLTBTagMuDiJet10U/I");
  tree->Branch(  "prescaleHLTBTagMuDiJet20U", &prescaleHLTBTagMuDiJet20U, "prescaleHLTBTagMuDiJet20U/I");
  tree->Branch(  "prescaleHLTBTagMuDiJet20UMu5", &prescaleHLTBTagMuDiJet20UMu5, "prescaleHLTBTagMuDiJet20UMu5/I");
  tree->Branch(  "prescaleHLTBTagMuDiJet30U", &prescaleHLTBTagMuDiJet30U, "prescaleHLTBTagMuDiJet30U/I");
  tree->Branch(  "prescaleHLTBTagMuDiJet30UMu5", &prescaleHLTBTagMuDiJet30UMu5, "prescaleHLTBTagMuDiJet30UMu5/I");


// added (4_1_2_patch1)
  tree->Branch(  "triggerHLT_L1SingleJet36", &triggerHLT_L1SingleJet36, "triggerHLT_L1SingleJet36/O");
  tree->Branch(  "triggerHLT_Jet30", &triggerHLT_Jet30, "triggerHLT_Jet30/O");
  tree->Branch(  "triggerHLT_Jet60", &triggerHLT_Jet60, "triggerHLT_Jet50/O");
  tree->Branch(  "triggerHLT_Jet80", &triggerHLT_Jet80, "triggerHLT_Jet80/O");
  tree->Branch(  "triggerHLT_Jet110", &triggerHLT_Jet110, "triggerHLT_Jet110/O");
  tree->Branch(  "triggerHLT_Jet150", &triggerHLT_Jet150, "triggerHLT_Jet150/O");
  tree->Branch(  "triggerHLT_Jet190", &triggerHLT_Jet190, "triggerHLT_Jet190/O");
  tree->Branch(  "triggerHLT_Jet240", &triggerHLT_Jet240, "triggerHLT_Jet240/O");
  tree->Branch(  "triggerHLT_Jet370", &triggerHLT_Jet370, "triggerHLT_Jet370/O");
  tree->Branch(  "triggerHLT_Jet370_NoJetID", &triggerHLT_Jet370_NoJetID, "triggerHLT_Je370_NoJetID/O");

  tree->Branch(  "prescaleHLT_L1SingleJet36", &prescaleHLT_L1SingleJet36, "prescaleHLT_L1SingleJet36/I");
  tree->Branch(  "prescaleHLT_Jet30", &prescaleHLT_Jet30, "prescaleHLT_Jet30/I");
  tree->Branch(  "prescaleHLT_Jet60", &prescaleHLT_Jet60, "prescaleHLT_Jet50/I");
  tree->Branch(  "prescaleHLT_Jet80", &prescaleHLT_Jet80, "prescaleHLT_Jet80/I");
  tree->Branch(  "prescaleHLT_Jet110", &prescaleHLT_Jet110, "prescaleHLT_Jet110/I");
  tree->Branch(  "prescaleHLT_Jet150", &prescaleHLT_Jet150, "prescaleHLT_Jet150/I");
  tree->Branch(  "prescaleHLT_Jet190", &prescaleHLT_Jet190, "prescaleHLT_Jet190/I");
  tree->Branch(  "prescaleHLT_Jet240", &prescaleHLT_Jet240, "prescaleHLT_Jet240/I");
  tree->Branch(  "prescaleHLT_Jet370", &prescaleHLT_Jet370, "prescaleHLT_Jet370/I");
  tree->Branch(  "prescaleHLT_Jet370_NoJetID", &prescaleHLT_Jet370_NoJetID, "prescaleHLT_Je370_NoJetID/I");

 
  tree->Branch( "triggerHLT_DiJetAve15U_v4",                  &triggerHLT_DiJetAve15U_v4                , "triggerHLT_DiJetAve15U_v4/O");             ;
  tree->Branch( "triggerHLT_DiJetAve30U_v4",                  &triggerHLT_DiJetAve30U_v4                , "triggerHLT_DiJetAve30U_v4/O");            
  tree->Branch( "triggerHLT_DiJetAve50U_v4",                  &triggerHLT_DiJetAve50U_v4                , "triggerHLT_DiJetAve50U_v4/O");            
  tree->Branch( "triggerHLT_DiJetAve70U_v4",                  &triggerHLT_DiJetAve70U_v4                , "triggerHLT_DiJetAve70U_v4/O");            
  tree->Branch( "triggerHLT_DiJetAve100U_v4",                 &triggerHLT_DiJetAve100U_v4               , "triggerHLT_DiJetAve100U_v4/O");           
  tree->Branch( "triggerHLT_DiJetAve140U_v4",                 &triggerHLT_DiJetAve140U_v4               , "triggerHLT_DiJetAve140U_v4/O");           
  tree->Branch( "triggerHLT_DiJetAve180U_v4",                 &triggerHLT_DiJetAve180U_v4               , "triggerHLT_DiJetAve180U_v4/O");           
  tree->Branch( "triggerHLT_DiJetAve300U_v4",                 &triggerHLT_DiJetAve300U_v4               , "triggerHLT_DiJetAve300U_v4/O");           
  tree->Branch( "triggerHLT_BTagMu_DiJet20_Mu5",              &triggerHLT_BTagMu_DiJet20_Mu5            , "triggerHLT_BTagMu_DiJet20_Mu5/O");     
  tree->Branch( "triggerHLT_BTagMu_DiJet110_Mu5",             &triggerHLT_BTagMu_DiJet110_Mu5           , "triggerHLT_BTagMu_DiJet110_Mu5/O");     
  tree->Branch( "triggerHLT_BTagMu_DiJet40_Mu5",              &triggerHLT_BTagMu_DiJet40_Mu5            , "triggerHLT_BTagMu_DiJet40_Mu5/O");     
  tree->Branch( "triggerHLT_BTagMu_DiJet70_Mu5",              &triggerHLT_BTagMu_DiJet70_Mu5            , "triggerHLT_BTagMu_DiJet70_Mu5/O");     
  tree->Branch( "triggerHLT_BTagMu_DiJet60_Mu7_v2",           &triggerHLT_BTagMu_DiJet60_Mu7_v2         , "triggerHLT_BTagMu_DiJet60_Mu7_v2/O");     
  tree->Branch( "triggerHLT_BTagMu_DiJet80_Mu9_v2",           &triggerHLT_BTagMu_DiJet80_Mu9_v2         , "triggerHLT_BTagMu_DiJet80_Mu9_v2/O");     
  tree->Branch( "triggerHLT_BTagMu_DiJet100_Mu9_v2",          &triggerHLT_BTagMu_DiJet100_Mu9_v2        , "triggerHLT_BTagMu_DiJet100_Mu9_v2/O");    
  tree->Branch( "prescaleHLT_DiJetAve15U_v4",          &prescaleHLT_DiJetAve15U_v4        , "prescaleHLT_DiJetAve15U_v4/I");          
  tree->Branch( "prescaleHLT_DiJetAve30U_v4",          &prescaleHLT_DiJetAve30U_v4        , "prescaleHLT_DiJetAve30U_v4/I");          
  tree->Branch( "prescaleHLT_DiJetAve50U_v4",          &prescaleHLT_DiJetAve50U_v4        , "prescaleHLT_DiJetAve50U_v4/I");          
  tree->Branch( "prescaleHLT_DiJetAve70U_v4",          &prescaleHLT_DiJetAve70U_v4        , "prescaleHLT_DiJetAve70U_v4/I");          
  tree->Branch( "prescaleHLT_DiJetAve100U_v4",         &prescaleHLT_DiJetAve100U_v4       , "prescaleHLT_DiJetAve100U_v4/I");         
  tree->Branch( "prescaleHLT_DiJetAve140U_v4",         &prescaleHLT_DiJetAve140U_v4       , "prescaleHLT_DiJetAve140U_v4/I");         
  tree->Branch( "prescaleHLT_DiJetAve180U_v4",         &prescaleHLT_DiJetAve180U_v4       , "prescaleHLT_DiJetAve180U_v4/I");         
  tree->Branch( "prescaleHLT_DiJetAve300U_v4",         &prescaleHLT_DiJetAve300U_v4       , "prescaleHLT_DiJetAve300U_v4/I");         
  tree->Branch( "prescaleHLT_BTagMu_DiJet20_Mu5",      &prescaleHLT_BTagMu_DiJet20_Mu5    , "prescaleHLT_BTagMu_DiJet20_Mu5/I");   
  tree->Branch( "prescaleHLT_BTagMu_DiJet40_Mu5",      &prescaleHLT_BTagMu_DiJet40_Mu5    , "prescaleHLT_BTagMu_DiJet40_Mu5/I");   
  tree->Branch( "prescaleHLT_BTagMu_DiJet70_Mu5",      &prescaleHLT_BTagMu_DiJet70_Mu5    , "prescaleHLT_BTagMu_DiJet70_Mu5/I");   
  tree->Branch( "prescaleHLT_BTagMu_DiJet110_Mu5",     &prescaleHLT_BTagMu_DiJet110_Mu5   , "prescaleHLT_BTagMu_DiJet110_Mu5/I");   
  tree->Branch( "prescaleHLT_BTagMu_DiJet60_Mu7_v2",   &prescaleHLT_BTagMu_DiJet60_Mu7_v2 , "prescaleHLT_BTagMu_DiJet60_Mu7_v2/I");   
  tree->Branch( "prescaleHLT_BTagMu_DiJet80_Mu9_v2",   &prescaleHLT_BTagMu_DiJet80_Mu9_v2 , "prescaleHLT_BTagMu_DiJet80_Mu9_v2/I");   
  tree->Branch( "prescaleHLT_BTagMu_DiJet100_Mu9_v2",  &prescaleHLT_BTagMu_DiJet100_Mu9_v2, "prescaleHLT_BTagMu_DiJet100_Mu9_v2/I");  



  tree->Branch(  "eventNumber"             , &eventNumber             , "eventNumber/i"            );
  tree->Branch(  "runNumber"		    , &runNumber               , "runNumber/i"   	    );
  tree->Branch(  "lumiBlockNumber" 	    , &lumiBlockNumber         , "lumiBlockNumber/i" 	    );

  tree->Branch(  "numberOfPUVertices",       &numberOfPUVertices, "numberOfPUVertices/i");
  tree->Branch(  "numberOfPrimaryVertices" , &numberOfPrimaryVertices , "numberOfPrimaryVertices/i"); 
  tree->Branch(  "numberOfTracksAtPV" , &numberOfTracksAtPV , "numberOfTracksAtPV/i"); 
  tree->Branch(  "PVx" , &PVx , "PVx/F"); 
  tree->Branch(  "PVy" , &PVy , "PVy/F"); 
  tree->Branch(  "PVz" , &PVz , "PVz/F"); 
  tree->Branch(  "PVChi2" , &PVChi2 , "PVChi2/F"); 
  tree->Branch(  "PVndof" , &PVndof , "PVndof/F"); 
  tree->Branch(  "PVNormalizedChi2" , &PVNormalizedChi2 , "PVNormalizedChi2/F"); 

  tree->Branch(  "pthat" , &pthat, "pthat/F");
  tree->Branch(  "isBGluonSplitting" , &isBGluonSplitting, "isBGluonSplitting/O");
  tree->Branch(  "isCGluonSplitting" , &isCGluonSplitting, "isCGluonSplitting/O");


  //Basic Jet Information
  //  math::XYZTLorentzVector jetP4[nJets];    
  tree->Branch(  "nJets", &nJets, "nJets/I");
           
  tree->Branch(  "jetPt", jetPt , "jetPt[nJets]/F");                                 
  tree->Branch(  "jetEta", jetEta, "jetEta[nJets]/F");                                
  tree->Branch(  "jetPhi", jetPhi, "jetPhi[nJets]/F");                                
  tree->Branch(  "jetEMFraction", jetEMFraction, "jetEMFraction[nJets]/F");        
  tree->Branch(  "jetChargedEmEnergyFraction", jetChargedEmEnergyFraction, "jetChargedEmEnergyFraction[nJets]/F");
  tree->Branch(  "jetNeutralEmEnergyFraction",  jetNeutralEmEnergyFraction, "jetNeutralEmEnergyFraction[nJets]/F");
  tree->Branch(  "jetChargedHadronEnergyFraction", jetChargedHadronEnergyFraction, "jetChargedHadronEnergyFraction[nJets]/F");
  tree->Branch(  "jetNeutralHadronEnergyFraction", jetNeutralHadronEnergyFraction, "jetNeutralHadronEnergyFraction[nJets]/F");
  tree->Branch(  "jetChargedMultiplicity", jetChargedMultiplicity , "jetChargedMultiplicity[nJets]/F");
  tree->Branch(  "jetMass", jetMass , "jetMass[nJets]/F");                               
  tree->Branch(  "jetnConstituents", jetnConstituents ,"jetnConstituents[nJets]/I");  
  tree->Branch(  "jetnTracks", jetnTracks, "jetnTracks[nJets]/I");                           
  //   tree->Branch(  "jetnElectrons", jetnElectrons   [nJets];                              
  //   tree->Branch(  "jetnMuons", jetnMuons   [nJets];                                  
  //   math::XYZVector "jetVertex", jetVertex , "jetVertex[nJets]/F");                   
  tree->Branch(  "jetVertexChi2", jetVertexChi2 , "jetVertexChi2[nJets]/F");               
  tree->Branch(  "jetVertexChi2Ndof", jetVertexChi2Ndof , "jetVertexChi2Ndof[nJets]/F");           
  tree->Branch(  "jetVertexNormalizedChi2", jetVertexNormalizedChi2 , "jetVertexNormalizedChi2[nJets]/F");    

  //Track Information
  tree->Branch(  "nTracks", &nTracks, "nTracks/I");

  tree->Branch(  "trackJetIndex", trackJetIndex, "trackJetIndex[nTracks]/I");
  tree->Branch( "trackSelected", trackSelected, "trackSelected[nTracks]/O") ;
  //				 math::XYZVector "track3Momentum", track3Momentum,   [nTracks];
  tree->Branch(  "trackTransverseMomentum", trackTransverseMomentum,  "trackTransverseMomentum[nTracks]/F");
  tree->Branch(  "trackEta", trackEta, "trackEta[nTracks]/F");
  tree->Branch(  "trackPhi", trackPhi, "trackPhi[nTracks]/F");
  tree->Branch(  "trackMomentum",  trackMomentum, "trackMomentum[nTracks]/F");
  tree->Branch(  "trackNHits", trackNHits, "trackNHits[nTracks]/I");
  tree->Branch(  "trackNPixelHits",  trackNPixelHits, "trackNPixelHits[nTracks]/I");
  tree->Branch(  "trackChi2",  trackChi2, "trackChi2[nTracks]/F");
  tree->Branch(  "trackNormChi2", trackNormChi2, "trackNormChi2[nTracks]/F");
  tree->Branch(  "trackQuality",  trackQuality, "trackQuality[nTracks]/I");
  tree->Branch(  "trackLongitudinalImpactParameter",  trackLongitudinalImpactParameter, "trackLongitudinalImpactParameter[nTracks]/F");
  tree->Branch(  "trackIP", trackIP, "trackIP[nTracks]/F");
  tree->Branch(  "trackDecayLength", trackDecayLength, "trackDecayLength[nTracks]/F");
  tree->Branch(  "trackDistJetAxis",  trackDistJetAxis, "trackDistJetAxis[nTracks]/F");
  tree->Branch(  "trackDeltaR", trackDeltaR, "trackDeltaR[nTracks]/F");
  tree->Branch(  "trackIP3d", trackIP3d, "trackIP3d[nTracks]/F");
  tree->Branch(  "trackIP2d",  trackIP2d, "trackIP2d[nTracks]/F");
  tree->Branch(  "trackIP3dError",  trackIP3dError, "trackIP3dError[nTracks]/F");
  tree->Branch(  "trackIP2dError",  trackIP2dError, "trackIP2dError[nTracks]/F");
  tree->Branch(  "trackHasSharedPix1",  trackHasSharedPix1, "trackHasSharedPix1[nTracks]/I");
  tree->Branch(  "trackHasSharedPix2",  trackHasSharedPix2, "trackHasSharedPix2[nTracks]/I");
  tree->Branch(  "trackHasSharedPix3",  trackHasSharedPix3, "trackHasSharedPix3[nTracks]/I");
  tree->Branch(  "trackHasSharedPixAll",  trackHasSharedPixAll, "trackHasSharedPixAll[nTracks]/I");
  tree->Branch( "trackIsVertexTrack", trackIsVertexTrack, "trackIsVertexTrack[nTracks]/O") ;

  //MC Truth Information
  tree->Branch(  "MCTrueFlavor", MCTrueFlavor, "MCTrueFlavor[nJets]/I");                          
 				       
  //secondaryVertexTagInfos:			       
  //  math::XYZVector "SecondaryVertex",    [nJets];             
  tree->Branch(  "SV3dDistance", SV3dDistance, "SV3dDistance[nJets]/F");                          
  tree->Branch(  "SV3dDistanceError",  SV3dDistanceError, "SV3dDistanceError[nJets]/F");                     
  tree->Branch(  "SV2dDistance", SV2dDistance, "SV2dDistance[nJets]/F");                          
  tree->Branch(  "SV2dDistanceError",  SV2dDistanceError, "SV2dDistanceError[nJets]/F");                     
  tree->Branch(  "SVChi2",  SVChi2, "SVChi2[nJets]/F");                
  tree->Branch(  "SVIPFirstAboveCharm",  SVIPFirstAboveCharm, "SVIPFirstAboveCharm[nJets]/F");                                
  tree->Branch(  "SVDegreesOfFreedom",  SVDegreesOfFreedom, "SVDegreesOfFreedom[nJets]/F");                    
  tree->Branch(  "SVNormChi2", SVNormChi2, "SVNormChi2[nJets]/F");                            
  tree->Branch(  "SVnSelectedTracks",  SVnSelectedTracks, "SVnSelectedTracks[nJets]/I");                               
  tree->Branch(  "SVMass",  SVMass, "SVMass[nJets]/F");                                
  tree->Branch(  "SVEnergyRatio",  SVEnergyRatio, "SVEnergyRatio[nJets]/F");                                
  tree->Branch(  "SVnVertices",  SVnVertices, "SVnVertices[nJets]/I");                             
  tree->Branch(  "SVnVertexTracks", SVnVertexTracks, "SVnVertexTracks[nJets]/I");         
  tree->Branch(  "SVnVertexTracksAll",  SVnVertexTracksAll, "SVnVertexTracksAll[nJets]/I");         
  tree->Branch(  "SVnFirstVertexTracks", SVnFirstVertexTracks, "SVnFirstVertexTracks[nJets]/I");         
  tree->Branch(  "SVnFirstVertexTracksAll",  SVnFirstVertexTracksAll, "SVnFirstVertexTracksAll[nJets]/I");         
  tree->Branch(  "SVjetDeltaR",  SVjetDeltaR, "SVjetDeltaR[nJets]/F");
  tree->Branch(  "SVvtxSumVtxDirDeltaR", SVvtxSumVtxDirDeltaR, "SVvtxSumVtxDirDeltaR[nJets]/F");
  tree->Branch(  "SVvtxSumJetDeltaR",  SVvtxSumJetDeltaR, "SVvtxSumJetDeltaR[nJets]/F");

  tree->Branch(  "SVvtxPt",  SVvtxPt, "SVvtxPt[nJets]/F");
  tree->Branch(  "SVvtxSumDirEta",  SVvtxSumDirEta, "SVvtxSumDirEta[nJets]/F");
  tree->Branch(  "SVvtxSumDirPhi",  SVvtxSumDirPhi, "SVvtxSumDirPhi[nJets]/F");
  tree->Branch(  "SVvtxDirEta",  SVvtxDirEta, "SVvtxDirEta[nJets]/F");
  tree->Branch(  "SVvtxDirPhi",  SVvtxDirPhi, "SVvtxDirPhi[nJets]/F");

  // added by Caroline
   tree->Branch(  "SVvtxSumPTrel",  SVvtxSumPTrel, "SVvtxSumPTrel[nJets]/F");
   tree->Branch(  "SVvtxDirPTrel",  SVvtxDirPTrel, "SVvtxDirPTrel[nJets]/F");
   tree->Branch(  "SVvtxDistJetAxis",  SVvtxDistJetAxis, "SVvtxDistJetAxis[nJets]/F");
   tree->Branch(  "SVtotCharge",  SVtotCharge, "SVtotCharge[nJets]/I");
  // end add
               
  //impactParameterTagInfos
  tree->Branch(  "IPnSelectedTracks",  IPnSelectedTracks, "IPnSelectedTracks[nJets]/I");                       
  //  math::XYZVector "IPghostTrackP3",    [nJets];      
  tree->Branch(  "IPghostTrackPt",  IPghostTrackPt, "IPghostTrackPt[nJets]/F");                        
  tree->Branch(  "IPghostTrackPtRel", IPghostTrackPtRel, "IPghostTrackPtRel[nJets]/F");                        
  tree->Branch(  "IPghostTrackEta",  IPghostTrackEta, "IPghostTrackEta[nJets]/F");                       
  tree->Branch(  "IPghostTrackPhi",  IPghostTrackPhi, "IPghostTrackPhi[nJets]/F");                       
  tree->Branch(  "IPghostTrackDeltaR", IPghostTrackDeltaR, "IPghostTrackDeltaR[nJets]/F");
  tree->Branch(  "IPPix1SharedHits",  IPPix1SharedHits, "IPPix1SharedHits[nJets]/I");
  tree->Branch(  "IPPix1TotalHits",  IPPix1TotalHits, "IPPix1TotalHits[nJets]/I");
  tree->Branch(  "IPPix2SharedHits", IPPix2SharedHits, "IPPix2SharedHits[nJets]/I");
  tree->Branch(  "IPPix2TotalHits", IPPix2TotalHits, "IPPix2TotalHits[nJets]/I");
  tree->Branch(  "IPPix3SharedHits",  IPPix3SharedHits, "IPPix3SharedHits[nJets]/I");
  tree->Branch(  "IPPix3TotalHits", IPPix3TotalHits, "IPPix3TotalHits[nJets]/I");
  tree->Branch(  "IPPixAllSharedHits", IPPixAllSharedHits, "IPPixAllSharedHits[nJets]/I");
  tree->Branch(  "IPPixAllTotalHits", IPPixAllTotalHits, "IPPixAllTotalHits[nJets]/I");

  for(int i=0; i<4; i++){
    TString name = "IP3dTrackQuality"; name += (i+1);
    tree->Branch( name, IP3dTrackQuality[i], name + "[nJets]/I");
    name = "IP3dHasSharedPix1"; name += (i+1);
    tree->Branch( name, IP3dHasSharedPix1[i], name + "[nJets]/I");
    name = "IP3dHasSharedPix2"; name += (i+1);
    tree->Branch( name, IP3dHasSharedPix2[i], name + "[nJets]/I");
    name = "IP3dHasSharedPix3"; name += (i+1);
    tree->Branch( name, IP3dHasSharedPix3[i], name + "[nJets]/I");
    name = "IP3dHasSharedPixAll"; name += (i+1);
    tree->Branch( name, IP3dHasSharedPixAll[i], name + "[nJets]/I");
    name = "IP3d"; name += (i+1);
    tree->Branch( name, IP3d[i], name + "[nJets]/F");
    name = "IP3dError"; name += (i+1);
    tree->Branch( name, IP3dError[i], name + "[nJets]/F");
    name = "IP3dProbability"; name += (i+1);
    tree->Branch( name, IP3dProbability[i], name + "[nJets]/F");
    name = "IP3dTrackPtRel"; name += (i+1);
    tree->Branch( name, IP3dTrackPtRel[i], name + "[nJets]/F");
    name = "IP3dDistJetAxis"; name += (i+1);
    tree->Branch( name, IP3dDistJetAxis[i], name + "[nJets]/F");
    name = "IP3dDecayLength"; name += (i+1);
    tree->Branch( name, IP3dDecayLength[i], name + "[nJets]/F");
    name = "IP3dDeltaR"; name += (i+1);
    tree->Branch( name, IP3dDeltaR[i], name + "[nJets]/F");
    name = "IP3dMomentum"; name += (i+1);
    tree->Branch( name, IP3dMomentum[i], name + "[nJets]/F");
    name = "IP3dTransverseMomentum"; name += (i+1);
    tree->Branch( name, IP3dTransverseMomentum[i], name + "[nJets]/F");
    name = "IP3dEta"; name += (i+1);
    tree->Branch( name, IP3dEta[i], name + "[nJets]/F");
    name = "IP3dPhi"; name += (i+1);
    tree->Branch( name, IP3dPhi[i], name + "[nJets]/F");
    name = "IP3dNHits"; name += (i+1);
    tree->Branch( name, IP3dNHits[i], name + "[nJets]/I");
    name = "IP3dNPixelHits"; name += (i+1);
    tree->Branch( name, IP3dNPixelHits[i], name + "[nJets]/I");
    name = "IP3dNormChi2"; name += (i+1);
    tree->Branch( name, IP3dNormChi2[i], name + "[nJets]/F");
    name = "IP2dTrackQuality"; name += (i+1);
    tree->Branch( name, IP2dTrackQuality[i], name + "[nJets]/I");
    name = "IP2d"; name += (i+1);
    tree->Branch( name, IP2d[i], name + "[nJets]/F");
    name = "IP2dError"; name += (i+1);
    tree->Branch( name, IP2dError[i], name + "[nJets]/F");
    name = "IP2dProbability"; name += (i+1);
    tree->Branch( name, IP2dProbability[i], name + "[nJets]/F");
    name = "IP2dTrackPtRel"; name += (i+1);
    tree->Branch( name, IP2dTrackPtRel[i], name + "[nJets]/F");

  }

  //softElectronTagInfos
  tree->Branch(  "nElectrons",  nElectrons, "nElectrons[nJets]/I");  
                          
  tree->Branch(  "electron1Pt",                  electron1Pt,                 "electron1Pt[nJets]/F");   			       
  tree->Branch(  "electron1Eta",                 electron1Eta,                "electron1Eta[nJets]/F");  			       
  tree->Branch(  "electron1Phi",                 electron1Phi,                "electron1Phi[nJets]/F");  			       
  tree->Branch(  "electron1NHits",               electron1NHits,              "electron1NHits[nJets]/I");   		     
  tree->Branch(  "electron1NExpectedOuterHits",  electron1NExpectedOuterHits, "electron1NExpectedOuterHits[nJets]/I");   		       
  tree->Branch(  "electron1NPixelHits",          electron1NPixelHits,         "electron1NPixelHits[nJets]/I");   		       
  tree->Branch(  "electron1NChi2",               electron1NChi2,              "electron1NChi2[nJets]/F");			       
  tree->Branch(  "electron1PtRel",               electron1PtRel,              "electron1PtRel[nJets]/F");   		       
  tree->Branch(  "electron1Sip2d",               electron1Sip2d,              "electron1Sip2d[nJets]/F");   		       
  tree->Branch(  "electron1Ip2d",                electron1Ip2d,               "electron1Ip2d[nJets]/F");   		       
  tree->Branch(  "electron1Ipe2d",               electron1Ipe2d,              "electron1Ipe2d[nJets]/F");   		       
  tree->Branch(  "electron1Sip3d",               electron1Sip3d,              "electron1Sip3d[nJets]/F");
  tree->Branch(  "electron1Ip3d",                electron1Ip3d,               "electron1Ip3d[nJets]/F");
  tree->Branch(  "electron1Ipe3d",               electron1Ipe3d,              "electron1Ipe3d[nJets]/F");   		          		          		       
  tree->Branch(  "electron1P0Par",               electron1P0Par,              "electron1P0Par[nJets]/F");   		       
  tree->Branch(  "electron1DeltaR",              electron1DeltaR,             "electron1DeltaR[nJets]/F");  		       
  tree->Branch(  "electron1EtaRel",              electron1EtaRel,             "electron1EtaRel[nJets]/F");  		       
  tree->Branch(  "electron1Ratio",               electron1Ratio,              "electron1Ratio[nJets]/F");   		     
  tree->Branch(  "electron1TrackQuality",        electron1TrackQuality,       "electron1TrackQuality[nJets]/I");   		       
  tree->Branch(  "electron1RatioRel",            electron1RatioRel,           "electron1RatioRel[nJets]/F");                      
  tree->Branch(  "electron1eSuperClusterOverP",             electron1eSuperClusterOverP,             "electron1eSuperClusterOverP[nJets]/F");
  tree->Branch(  "electron1eSeedClusterOverP",              electron1eSeedClusterOverP,              "electron1eSeedClusterOverP[nJets]/F");
  tree->Branch(  "electron1eSeedClusterOverPout",           electron1eSeedClusterOverPout,           "electron1eSeedClusterOverPout[nJets]/F");
  tree->Branch(  "electron1eEleClusterOverPout",            electron1eEleClusterOverPout,            "electron1eEleClusterOverPout[nJets]/F");
  tree->Branch(  "electron1deltaEtaSuperClusterTrackAtVtx", electron1deltaEtaSuperClusterTrackAtVtx, "electron1deltaEtaSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron1deltaEtaSeedClusterTrackAtCalo", electron1deltaEtaSeedClusterTrackAtCalo, "electron1deltaEtaSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron1deltaEtaEleClusterTrackAtCalo",  electron1deltaEtaEleClusterTrackAtCalo,  "electron1deltaEtaEleClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron1deltaPhiSuperClusterTrackAtVtx", electron1deltaPhiSuperClusterTrackAtVtx, "electron1deltaPhiSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron1deltaPhiSeedClusterTrackAtCalo", electron1deltaPhiSeedClusterTrackAtCalo, "electron1deltaPhiSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron1deltaPhiEleClusterTrackAtCalo",  electron1deltaPhiEleClusterTrackAtCalo,  "electron1deltaPhiEleClusterTrackAtCalo[nJets]/F");
            
  tree->Branch(  "electron2Pt",                  electron2Pt,                 "electron2Pt[nJets]/F");   			       
  tree->Branch(  "electron2Eta",                 electron2Eta,                "electron2Eta[nJets]/F");  			       
  tree->Branch(  "electron2Phi",                 electron2Phi,                "electron2Phi[nJets]/F");  			       
  tree->Branch(  "electron2NHits",               electron2NHits,              "electron2NHits[nJets]/I");   		     
  tree->Branch(  "electron2NExpectedOuterHits",  electron2NExpectedOuterHits, "electron2NExpectedOuterHits[nJets]/I");   		       
  tree->Branch(  "electron2NPixelHits",          electron2NPixelHits,         "electron2NPixelHits[nJets]/I");   		       
  tree->Branch(  "electron2NChi2",               electron2NChi2,              "electron2NChi2[nJets]/F");			       
  tree->Branch(  "electron2PtRel",               electron2PtRel,              "electron2PtRel[nJets]/F");   		       
  tree->Branch(  "electron2Sip2d",               electron2Sip2d,              "electron2Sip2d[nJets]/F");   		       
  tree->Branch(  "electron2Ip2d",                electron2Ip2d,               "electron2Ip2d[nJets]/F");   		       
  tree->Branch(  "electron2Ipe2d",               electron2Ipe2d,              "electron2Ipe2d[nJets]/F");   		       
  tree->Branch(  "electron2Sip3d",               electron2Sip3d,              "electron2Sip3d[nJets]/F");
  tree->Branch(  "electron2Ip3d",                electron2Ip3d,               "electron2Ip3d[nJets]/F");
  tree->Branch(  "electron2Ipe3d",               electron2Ipe3d,              "electron2Ipe3d[nJets]/F");   		          		          		       
  tree->Branch(  "electron2P0Par",               electron2P0Par,              "electron2P0Par[nJets]/F");   		       
  tree->Branch(  "electron2DeltaR",              electron2DeltaR,             "electron2DeltaR[nJets]/F");  		       
  tree->Branch(  "electron2EtaRel",              electron2EtaRel,             "electron2EtaRel[nJets]/F");  		       
  tree->Branch(  "electron2Ratio",               electron2Ratio,              "electron2Ratio[nJets]/F");   		     
  tree->Branch(  "electron2TrackQuality",        electron2TrackQuality,       "electron2TrackQuality[nJets]/I");   		       
  tree->Branch(  "electron2RatioRel",            electron2RatioRel,           "electron2RatioRel[nJets]/F"); 
  tree->Branch(  "electron2eSuperClusterOverP",             electron2eSuperClusterOverP,             "electron2eSuperClusterOverP[nJets]/F");
  tree->Branch(  "electron2eSeedClusterOverP",              electron2eSeedClusterOverP,              "electron2eSeedClusterOverP[nJets]/F");
  tree->Branch(  "electron2eSeedClusterOverPout",           electron2eSeedClusterOverPout,           "electron2eSeedClusterOverPout[nJets]/F");
  tree->Branch(  "electron2eEleClusterOverPout",            electron2eEleClusterOverPout,            "electron2eEleClusterOverPout[nJets]/F");
  tree->Branch(  "electron2deltaEtaSuperClusterTrackAtVtx", electron2deltaEtaSuperClusterTrackAtVtx, "electron2deltaEtaSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron2deltaEtaSeedClusterTrackAtCalo", electron2deltaEtaSeedClusterTrackAtCalo, "electron2deltaEtaSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron2deltaEtaEleClusterTrackAtCalo",  electron2deltaEtaEleClusterTrackAtCalo,  "electron2deltaEtaEleClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron2deltaPhiSuperClusterTrackAtVtx", electron2deltaPhiSuperClusterTrackAtVtx, "electron2deltaPhiSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron2deltaPhiSeedClusterTrackAtCalo", electron2deltaPhiSeedClusterTrackAtCalo, "electron2deltaPhiSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron2deltaPhiEleClusterTrackAtCalo",  electron2deltaPhiEleClusterTrackAtCalo,  "electron2deltaPhiEleClusterTrackAtCalo[nJets]/F");
                          
  tree->Branch(  "electron3Pt",                  electron3Pt,                 "electron3Pt[nJets]/F");   			       
  tree->Branch(  "electron3Eta",                 electron3Eta,                "electron3Eta[nJets]/F");  			       
  tree->Branch(  "electron3Phi",                 electron3Phi,                "electron3Phi[nJets]/F");  			       
  tree->Branch(  "electron3NHits",               electron3NHits,              "electron3NHits[nJets]/I");   		     
  tree->Branch(  "electron3NExpectedOuterHits",  electron3NExpectedOuterHits, "electron3NExpectedOuterHits[nJets]/I");   		       
  tree->Branch(  "electron3NPixelHits",          electron3NPixelHits,         "electron3NPixelHits[nJets]/I");   		       
  tree->Branch(  "electron3NChi2",               electron3NChi2,              "electron3NChi2[nJets]/F");			       
  tree->Branch(  "electron3PtRel",               electron3PtRel,              "electron3PtRel[nJets]/F");   		       
  tree->Branch(  "electron3Sip2d",               electron3Sip2d,              "electron3Sip2d[nJets]/F");   		       
  tree->Branch(  "electron3Ip2d",                electron3Ip2d,               "electron3Ip2d[nJets]/F");   		       
  tree->Branch(  "electron3Ipe2d",               electron3Ipe2d,              "electron3Ipe2d[nJets]/F");   		       
  tree->Branch(  "electron3Sip3d",               electron3Sip3d,              "electron3Sip3d[nJets]/F");
  tree->Branch(  "electron3Ip3d",                electron3Ip3d,               "electron3Ip3d[nJets]/F");
  tree->Branch(  "electron3Ipe3d",               electron3Ipe3d,              "electron3Ipe3d[nJets]/F");   		          		          		       
  tree->Branch(  "electron3P0Par",               electron3P0Par,              "electron3P0Par[nJets]/F");   		       
  tree->Branch(  "electron3DeltaR",              electron3DeltaR,             "electron3DeltaR[nJets]/F");  		       
  tree->Branch(  "electron3EtaRel",              electron3EtaRel,             "electron3EtaRel[nJets]/F");  		       
  tree->Branch(  "electron3Ratio",               electron3Ratio,              "electron3Ratio[nJets]/F");   		     
  tree->Branch(  "electron3TrackQuality",        electron3TrackQuality,       "electron3TrackQuality[nJets]/I");   		       
  tree->Branch(  "electron3RatioRel",            electron3RatioRel,           "electron3RatioRel[nJets]/F");  
  tree->Branch(  "electron3eSuperClusterOverP",             electron3eSuperClusterOverP,             "electron3eSuperClusterOverP[nJets]/F");
  tree->Branch(  "electron3eSeedClusterOverP",              electron3eSeedClusterOverP,              "electron3eSeedClusterOverP[nJets]/F");
  tree->Branch(  "electron3eSeedClusterOverPout",           electron3eSeedClusterOverPout,           "electron3eSeedClusterOverPout[nJets]/F");
  tree->Branch(  "electron3eEleClusterOverPout",            electron3eEleClusterOverPout,            "electron3eEleClusterOverPout[nJets]/F");
  tree->Branch(  "electron3deltaEtaSuperClusterTrackAtVtx", electron3deltaEtaSuperClusterTrackAtVtx, "electron3deltaEtaSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron3deltaEtaSeedClusterTrackAtCalo", electron3deltaEtaSeedClusterTrackAtCalo, "electron3deltaEtaSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron3deltaEtaEleClusterTrackAtCalo",  electron3deltaEtaEleClusterTrackAtCalo,  "electron3deltaEtaEleClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron3deltaPhiSuperClusterTrackAtVtx", electron3deltaPhiSuperClusterTrackAtVtx, "electron3deltaPhiSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron3deltaPhiSeedClusterTrackAtCalo", electron3deltaPhiSeedClusterTrackAtCalo, "electron3deltaPhiSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron3deltaPhiEleClusterTrackAtCalo",  electron3deltaPhiEleClusterTrackAtCalo,  "electron3deltaPhiEleClusterTrackAtCalo[nJets]/F"); 
                          
  tree->Branch(  "electron4Pt",                  electron4Pt,                 "electron4Pt[nJets]/F");   			       
  tree->Branch(  "electron4Eta",                 electron4Eta,                "electron4Eta[nJets]/F");  			       
  tree->Branch(  "electron4Phi",                 electron4Phi,                "electron4Phi[nJets]/F");  			       
  tree->Branch(  "electron4NHits",               electron4NHits,              "electron4NHits[nJets]/I");   		     
  tree->Branch(  "electron4NExpectedOuterHits",  electron4NExpectedOuterHits, "electron4NExpectedOuterHits[nJets]/I");   		       
  tree->Branch(  "electron4NPixelHits",          electron4NPixelHits,         "electron4NPixelHits[nJets]/I");   		       
  tree->Branch(  "electron4NChi2",               electron4NChi2,              "electron4NChi2[nJets]/F");			       
  tree->Branch(  "electron4PtRel",               electron4PtRel,              "electron4PtRel[nJets]/F");   		       
  tree->Branch(  "electron4Sip2d",               electron4Sip2d,              "electron4Sip2d[nJets]/F");   		       
  tree->Branch(  "electron4Ip2d",                electron4Ip2d,               "electron4Ip2d[nJets]/F");   		       
  tree->Branch(  "electron4Ipe2d",               electron4Ipe2d,              "electron4Ipe2d[nJets]/F");   		       
  tree->Branch(  "electron4Sip3d",               electron4Sip3d,              "electron4Sip3d[nJets]/F");
  tree->Branch(  "electron4Ip3d",                electron4Ip3d,               "electron4Ip3d[nJets]/F");
  tree->Branch(  "electron4Ipe3d",               electron4Ipe3d,              "electron4Ipe3d[nJets]/F");   		          		          		       
  tree->Branch(  "electron4P0Par",               electron4P0Par,              "electron4P0Par[nJets]/F");   		       
  tree->Branch(  "electron4DeltaR",              electron4DeltaR,             "electron4DeltaR[nJets]/F");  		       
  tree->Branch(  "electron4EtaRel",              electron4EtaRel,             "electron4EtaRel[nJets]/F");  		       
  tree->Branch(  "electron4Ratio",               electron4Ratio,              "electron4Ratio[nJets]/F");   		     
  tree->Branch(  "electron4TrackQuality",        electron4TrackQuality,       "electron4TrackQuality[nJets]/I");   		       
  tree->Branch(  "electron4RatioRel",            electron4RatioRel,           "electron4RatioRel[nJets]/F"); 
  tree->Branch(  "electron4eSuperClusterOverP",             electron4eSuperClusterOverP,             "electron4eSuperClusterOverP[nJets]/F");
  tree->Branch(  "electron4eSeedClusterOverP",              electron4eSeedClusterOverP,              "electron4eSeedClusterOverP[nJets]/F");
  tree->Branch(  "electron4eSeedClusterOverPout",           electron4eSeedClusterOverPout,           "electron4eSeedClusterOverPout[nJets]/F");
  tree->Branch(  "electron4eEleClusterOverPout",            electron4eEleClusterOverPout,            "electron4eEleClusterOverPout[nJets]/F");
  tree->Branch(  "electron4deltaEtaSuperClusterTrackAtVtx", electron4deltaEtaSuperClusterTrackAtVtx, "electron4deltaEtaSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron4deltaEtaSeedClusterTrackAtCalo", electron4deltaEtaSeedClusterTrackAtCalo, "electron4deltaEtaSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron4deltaEtaEleClusterTrackAtCalo",  electron4deltaEtaEleClusterTrackAtCalo,  "electron4deltaEtaEleClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron4deltaPhiSuperClusterTrackAtVtx", electron4deltaPhiSuperClusterTrackAtVtx, "electron4deltaPhiSuperClusterTrackAtVtx[nJets]/F");
  tree->Branch(  "electron4deltaPhiSeedClusterTrackAtCalo", electron4deltaPhiSeedClusterTrackAtCalo, "electron4deltaPhiSeedClusterTrackAtCalo[nJets]/F");
  tree->Branch(  "electron4deltaPhiEleClusterTrackAtCalo",  electron4deltaPhiEleClusterTrackAtCalo,  "electron4deltaPhiEleClusterTrackAtCalo[nJets]/F");

  //softMuonTagInfos	
  tree->Branch(  "nMuons", nMuons, "nMuons[nJets]/I");                                
  
  tree->Branch(  "muon1IsGlobal",          muon1IsGlobal,            "muon1IsGlobal[nJets]/O");            
  tree->Branch(  "muon1IsTracker", 	   muon1IsTracker,           "muon1IsTracker[nJets]/O");           
  tree->Branch(  "muon1IsStandalone", 	   muon1IsStandalone,        "muon1IsStandalone[nJets]/O");        
  tree->Branch(  "muon1Pt",    		   muon1Pt,                  "muon1Pt[nJets]/F");                     	       
  tree->Branch(  "muon1Eta",   		   muon1Eta,                 "muon1Eta[nJets]/F");                    	       
  tree->Branch(  "muon1Phi",   		   muon1Phi,                 "muon1Phi[nJets]/F");                 
  tree->Branch(  "muon1NumberOfMatches",   muon1NumberOfMatches,     "muon1NumberOfMatches[nJets]/I");     
  tree->Branch(  "muon1GlobalMuonHits",    muon1GlobalMuonHits,      "muon1GlobalMuonHits[nJets]/I");      
  tree->Branch(  "muon1InnerValidHits",    muon1InnerValidHits,      "muon1InnerValidHits[nJets]/I");      
  tree->Branch(  "muon1NExpectedOuterHits",muon1NExpectedOuterHits,  "muon1NExpectedOuterHits[nJets]/I");    			       
  tree->Branch(  "muon1NPixelHits", 	   muon1NPixelHits,          "muon1NPixelHits[nJets]/I");          
  tree->Branch(  "muon1InnerNChi2", 	   muon1InnerNChi2,          "muon1InnerNChi2[nJets]/F");          
  tree->Branch(  "muon1GlobalNChi2", 	   muon1GlobalNChi2,         "muon1GlobalNChi2[nJets]/F");         
  tree->Branch(  "muon1VzPVDist", 	   muon1VzPVDist,            "muon1VzPVDist[nJets]/F");            
  tree->Branch(  "muon1PtRel",    	   muon1PtRel,               "muon1PtRel[nJets]/F");               
  tree->Branch(  "muon1Sip2d",    	   muon1Sip2d,               "muon1Sip2d[nJets]/F");                  	       
  tree->Branch(  "muon1Ip2d",    	   muon1Ip2d,                "muon1Ip2d[nJets]/F");                    
  tree->Branch(  "muon1Ipe2d",    	   muon1Ipe2d,               "muon1Ipe2d[nJets]/F");                  	       
  tree->Branch(  "muon1Sip3d", 		   muon1Sip3d,               "muon1Sip3d[nJets]/F");               
  tree->Branch(  "muon1Ip3d", 		   muon1Ip3d,                "muon1Ip3d[nJets]/F");                
  tree->Branch(  "muon1Ipe3d",    	   muon1Ipe3d,               "muon1Ipe3d[nJets]/F");               
  tree->Branch(  "muon1P0Par",    	   muon1P0Par,               "muon1P0Par[nJets]/F");                  		       
  tree->Branch(  "muon1DeltaR",   	   muon1DeltaR,              "muon1DeltaR[nJets]/F");                 		       
  tree->Branch(  "muon1EtaRel",   	   muon1EtaRel,              "muon1EtaRel[nJets]/F");                 		       
  tree->Branch(  "muon1Ratio",    	   muon1Ratio,               "muon1Ratio[nJets]/F");                  		    
  tree->Branch(  "muon1TrackQuality",      muon1TrackQuality,        "muon1TrackQuality[nJets]/I");           		       
  tree->Branch(  "muon1RatioRel",          muon1RatioRel,            "muon1RatioRel[nJets]/F");                           


  tree->Branch(  "muon2IsGlobal",          muon2IsGlobal,            "muon2IsGlobal[nJets]/O");            
  tree->Branch(  "muon2IsTracker", 	   muon2IsTracker,           "muon2IsTracker[nJets]/O");           
  tree->Branch(  "muon2IsStandalone", 	   muon2IsStandalone,        "muon2IsStandalone[nJets]/O");        
  tree->Branch(  "muon2Pt",    		   muon2Pt,                  "muon2Pt[nJets]/F");                     	       
  tree->Branch(  "muon2Eta",   		   muon2Eta,                 "muon2Eta[nJets]/F");                    	       
  tree->Branch(  "muon2Phi",   		   muon2Phi,                 "muon2Phi[nJets]/F");                 
  tree->Branch(  "muon2NumberOfMatches",   muon2NumberOfMatches,     "muon2NumberOfMatches[nJets]/I");     
  tree->Branch(  "muon2GlobalMuonHits",    muon2GlobalMuonHits,      "muon2GlobalMuonHits[nJets]/I");      
  tree->Branch(  "muon2InnerValidHits",    muon2InnerValidHits,      "muon2InnerValidHits[nJets]/I");      
  tree->Branch(  "muon2NExpectedOuterHits",muon2NExpectedOuterHits,  "muon2NExpectedOuterHits[nJets]/I");    			       
  tree->Branch(  "muon2NPixelHits", 	   muon2NPixelHits,          "muon2NPixelHits[nJets]/I");          
  tree->Branch(  "muon2InnerNChi2", 	   muon2InnerNChi2,          "muon2InnerNChi2[nJets]/F");          
  tree->Branch(  "muon2GlobalNChi2", 	   muon2GlobalNChi2,         "muon2GlobalNChi2[nJets]/F");         
  tree->Branch(  "muon2VzPVDist", 	   muon2VzPVDist,            "muon2VzPVDist[nJets]/F");            
  tree->Branch(  "muon2PtRel",    	   muon2PtRel,               "muon2PtRel[nJets]/F");               
  tree->Branch(  "muon2Sip2d",    	   muon2Sip2d,               "muon2Sip2d[nJets]/F");                  	       
  tree->Branch(  "muon2Ip2d",    	   muon2Ip2d,                "muon2Ip2d[nJets]/F");                    
  tree->Branch(  "muon2Ipe2d",    	   muon2Ipe2d,               "muon2Ipe2d[nJets]/F");                  	       
  tree->Branch(  "muon2Sip3d", 		   muon2Sip3d,               "muon2Sip3d[nJets]/F");               
  tree->Branch(  "muon2Ip3d", 		   muon2Ip3d,                "muon2Ip3d[nJets]/F");                
  tree->Branch(  "muon2Ipe3d",    	   muon2Ipe3d,               "muon2Ipe3d[nJets]/F");               
  tree->Branch(  "muon2P0Par",    	   muon2P0Par,               "muon2P0Par[nJets]/F");                  		       
  tree->Branch(  "muon2DeltaR",   	   muon2DeltaR,              "muon2DeltaR[nJets]/F");                 		       
  tree->Branch(  "muon2EtaRel",   	   muon2EtaRel,              "muon2EtaRel[nJets]/F");                 		       
  tree->Branch(  "muon2Ratio",    	   muon2Ratio,               "muon2Ratio[nJets]/F");                  		    
  tree->Branch(  "muon2TrackQuality",      muon2TrackQuality,        "muon2TrackQuality[nJets]/I");           		       
  tree->Branch(  "muon2RatioRel",          muon2RatioRel,            "muon2RatioRel[nJets]/F");                           


  tree->Branch(  "muon3IsGlobal",          muon3IsGlobal,            "muon3IsGlobal[nJets]/O");            
  tree->Branch(  "muon3IsTracker", 	   muon3IsTracker,           "muon3IsTracker[nJets]/O");           
  tree->Branch(  "muon3IsStandalone", 	   muon3IsStandalone,        "muon3IsStandalone[nJets]/O");        
  tree->Branch(  "muon3Pt",    		   muon3Pt,                  "muon3Pt[nJets]/F");                     	       
  tree->Branch(  "muon3Eta",   		   muon3Eta,                 "muon3Eta[nJets]/F");                    	       
  tree->Branch(  "muon3Phi",   		   muon3Phi,                 "muon3Phi[nJets]/F");                 
  tree->Branch(  "muon3NumberOfMatches",   muon3NumberOfMatches,     "muon3NumberOfMatches[nJets]/I");     
  tree->Branch(  "muon3GlobalMuonHits",    muon3GlobalMuonHits,      "muon3GlobalMuonHits[nJets]/I");      
  tree->Branch(  "muon3InnerValidHits",    muon3InnerValidHits,      "muon3InnerValidHits[nJets]/I");      
  tree->Branch(  "muon3NExpectedOuterHits",muon3NExpectedOuterHits,  "muon3NExpectedOuterHits[nJets]/I");    			       
  tree->Branch(  "muon3NPixelHits", 	   muon3NPixelHits,          "muon3NPixelHits[nJets]/I");          
  tree->Branch(  "muon3InnerNChi2", 	   muon3InnerNChi2,          "muon3InnerNChi2[nJets]/F");          
  tree->Branch(  "muon3GlobalNChi2", 	   muon3GlobalNChi2,         "muon3GlobalNChi2[nJets]/F");         
  tree->Branch(  "muon3VzPVDist", 	   muon3VzPVDist,            "muon3VzPVDist[nJets]/F");            
  tree->Branch(  "muon3PtRel",    	   muon3PtRel,               "muon3PtRel[nJets]/F");               
  tree->Branch(  "muon3Sip2d",    	   muon3Sip2d,               "muon3Sip2d[nJets]/F");                  	       
  tree->Branch(  "muon3Ip2d",    	   muon3Ip2d,                "muon3Ip2d[nJets]/F");                    
  tree->Branch(  "muon3Ipe2d",    	   muon3Ipe2d,               "muon3Ipe2d[nJets]/F");                  	       
  tree->Branch(  "muon3Sip3d", 		   muon3Sip3d,               "muon3Sip3d[nJets]/F");               
  tree->Branch(  "muon3Ip3d", 		   muon3Ip3d,                "muon3Ip3d[nJets]/F");                
  tree->Branch(  "muon3Ipe3d",    	   muon3Ipe3d,               "muon3Ipe3d[nJets]/F");               
  tree->Branch(  "muon3P0Par",    	   muon3P0Par,               "muon3P0Par[nJets]/F");                  		       
  tree->Branch(  "muon3DeltaR",   	   muon3DeltaR,              "muon3DeltaR[nJets]/F");                 		       
  tree->Branch(  "muon3EtaRel",   	   muon3EtaRel,              "muon3EtaRel[nJets]/F");                 		       
  tree->Branch(  "muon3Ratio",    	   muon3Ratio,               "muon3Ratio[nJets]/F");                  		    
  tree->Branch(  "muon3TrackQuality",      muon3TrackQuality,        "muon3TrackQuality[nJets]/I");           		       
  tree->Branch(  "muon3RatioRel",          muon3RatioRel,            "muon3RatioRel[nJets]/F");                           


  tree->Branch(  "muon4IsGlobal",          muon4IsGlobal,            "muon4IsGlobal[nJets]/O");            
  tree->Branch(  "muon4IsTracker", 	   muon4IsTracker,           "muon4IsTracker[nJets]/O");           
  tree->Branch(  "muon4IsStandalone", 	   muon4IsStandalone,        "muon4IsStandalone[nJets]/O");        
  tree->Branch(  "muon4Pt",    		   muon4Pt,                  "muon4Pt[nJets]/F");                     	       
  tree->Branch(  "muon4Eta",   		   muon4Eta,                 "muon4Eta[nJets]/F");                    	       
  tree->Branch(  "muon4Phi",   		   muon4Phi,                 "muon4Phi[nJets]/F");                 
  tree->Branch(  "muon4NumberOfMatches",   muon4NumberOfMatches,     "muon4NumberOfMatches[nJets]/I");     
  tree->Branch(  "muon4GlobalMuonHits",    muon4GlobalMuonHits,      "muon4GlobalMuonHits[nJets]/I");      
  tree->Branch(  "muon4InnerValidHits",    muon4InnerValidHits,      "muon4InnerValidHits[nJets]/I");      
  tree->Branch(  "muon4NExpectedOuterHits",muon4NExpectedOuterHits,  "muon4NExpectedOuterHits[nJets]/I");    			       
  tree->Branch(  "muon4NPixelHits", 	   muon4NPixelHits,          "muon4NPixelHits[nJets]/I");          
  tree->Branch(  "muon4InnerNChi2", 	   muon4InnerNChi2,          "muon4InnerNChi2[nJets]/F");          
  tree->Branch(  "muon4GlobalNChi2", 	   muon4GlobalNChi2,         "muon4GlobalNChi2[nJets]/F");         
  tree->Branch(  "muon4VzPVDist", 	   muon4VzPVDist,            "muon4VzPVDist[nJets]/F");            
  tree->Branch(  "muon4PtRel",    	   muon4PtRel,               "muon4PtRel[nJets]/F");               
  tree->Branch(  "muon4Sip2d",    	   muon4Sip2d,               "muon4Sip2d[nJets]/F");                  	       
  tree->Branch(  "muon4Ip2d",    	   muon4Ip2d,                "muon4Ip2d[nJets]/F");                    
  tree->Branch(  "muon4Ipe2d",    	   muon4Ipe2d,               "muon4Ipe2d[nJets]/F");                  	       
  tree->Branch(  "muon4Sip3d", 		   muon4Sip3d,               "muon4Sip3d[nJets]/F");               
  tree->Branch(  "muon4Ip3d", 		   muon4Ip3d,                "muon4Ip3d[nJets]/F");                
  tree->Branch(  "muon4Ipe3d",    	   muon4Ipe3d,               "muon4Ipe3d[nJets]/F");               
  tree->Branch(  "muon4P0Par",    	   muon4P0Par,               "muon4P0Par[nJets]/F");                  		       
  tree->Branch(  "muon4DeltaR",   	   muon4DeltaR,              "muon4DeltaR[nJets]/F");                 		       
  tree->Branch(  "muon4EtaRel",   	   muon4EtaRel,              "muon4EtaRel[nJets]/F");                 		       
  tree->Branch(  "muon4Ratio",    	   muon4Ratio,               "muon4Ratio[nJets]/F");                  		    
  tree->Branch(  "muon4TrackQuality",      muon4TrackQuality,        "muon4TrackQuality[nJets]/I");           		       
  tree->Branch(  "muon4RatioRel",          muon4RatioRel,            "muon4RatioRel[nJets]/F");                           



  for(map< string, float* >::iterator it = bTagArrays.begin(); it!= bTagArrays.end(); it++){
    TString name = it->first;
    TString nameExt = name;
    nameExt += "[nJets]/F";
    tree->Branch(  name, it->second, nameExt ); 
  }

  isValidHltConfig_ = false;
}


TagNtupleProducer::~TagNtupleProducer()
{
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
}

//
// member functions
//

// ------------ method called to produce the data  ------------
void TagNtupleProducer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
  
  triggerHLTL1Jet6U= triggerHLTL1Jet10U= triggerHLTJet15U = 0;
  triggerHLTJet30U = triggerHLTJet50U = triggerHLTJet70U= triggerHLTJet100U = 0;
  triggerHLTBTagIPJet50U = triggerHLTBTagMuJet10U = triggerHLTBTagMuJet20U = 0;
  //BTagMu paths in 6E31 and 2E32 menu
  triggerHLTBTagMuDiJet10U = triggerHLTBTagMuDiJet20U = triggerHLTBTagMuDiJet20UMu5 = triggerHLTBTagMuDiJet30U = triggerHLTBTagMuDiJet30UMu5 = 0;

  // added by Caroline
  prescaleHLTL1Jet6U= prescaleHLTL1Jet10U= prescaleHLTJet15U = 0;
  prescaleHLTJet30U = prescaleHLTJet50U = prescaleHLTJet70U= prescaleHLTJet100U = 0;
  prescaleHLTBTagIPJet50U = prescaleHLTBTagMuJet10U = prescaleHLTBTagMuJet20U = 0;
  prescaleHLTBTagMuDiJet10U = prescaleHLTBTagMuDiJet20U = prescaleHLTBTagMuDiJet20UMu5 = prescaleHLTBTagMuDiJet30U = prescaleHLTBTagMuDiJet30UMu5 = 0;

  // 4_1_2_patch1
  triggerHLT_L1SingleJet36= triggerHLT_Jet30= triggerHLT_Jet60= triggerHLT_Jet80= triggerHLT_Jet110= triggerHLT_Jet150=0;
  triggerHLT_Jet190 = triggerHLT_Jet240 = triggerHLT_Jet370 = triggerHLT_Jet370_NoJetID =0;
  prescaleHLT_L1SingleJet36= prescaleHLT_Jet30= prescaleHLT_Jet60= prescaleHLT_Jet80= prescaleHLT_Jet110= prescaleHLT_Jet150=0;
  prescaleHLT_Jet190 = prescaleHLT_Jet240 = prescaleHLT_Jet370 = prescaleHLT_Jet370_NoJetID =0;
  // end add
   triggerHLT_DiJetAve15U_v4          =0 ;
   triggerHLT_DiJetAve30U_v4          =0 ;
   triggerHLT_DiJetAve50U_v4          =0 ;
   triggerHLT_DiJetAve70U_v4          =0 ;
   triggerHLT_DiJetAve100U_v4         =0 ;
   triggerHLT_DiJetAve140U_v4         =0 ;
   triggerHLT_DiJetAve180U_v4         =0 ;
   triggerHLT_DiJetAve300U_v4         =0 ;
   triggerHLT_BTagMu_DiJet20_Mu5      =0 ;
   triggerHLT_BTagMu_DiJet40_Mu5      =0 ;
   triggerHLT_BTagMu_DiJet70_Mu5      =0 ;
   triggerHLT_BTagMu_DiJet110_Mu5      =0 ;
   triggerHLT_BTagMu_DiJet60_Mu7_v2   =0 ;
   triggerHLT_BTagMu_DiJet80_Mu9_v2   =0 ;
   triggerHLT_BTagMu_DiJet100_Mu9_v2  =0 ;
  
   prescaleHLT_DiJetAve15U_v4          =0 ;
   prescaleHLT_DiJetAve30U_v4          =0 ;
   prescaleHLT_DiJetAve50U_v4          =0 ;
   prescaleHLT_DiJetAve70U_v4          =0 ;
   prescaleHLT_DiJetAve100U_v4         =0 ;
   prescaleHLT_DiJetAve140U_v4         =0 ;
   prescaleHLT_DiJetAve180U_v4         =0 ;
   prescaleHLT_DiJetAve300U_v4         =0 ;
   prescaleHLT_BTagMu_DiJet20_Mu5      =0 ;
   prescaleHLT_BTagMu_DiJet40_Mu5      =0 ;
   prescaleHLT_BTagMu_DiJet70_Mu5      =0 ;
   prescaleHLT_BTagMu_DiJet110_Mu5     =0 ;
   prescaleHLT_BTagMu_DiJet60_Mu7_v2   =0 ;
   prescaleHLT_BTagMu_DiJet80_Mu9_v2   =0 ;
   prescaleHLT_BTagMu_DiJet100_Mu9_v2  =0 ;

  //Get The Various collections defined in the configuration file
  edm::Handle<edm::TriggerResults>  hltresults;
  iEvent.getByLabel(triggerTag_, hltresults);
  
  const edm::TriggerNames & triggerNames_ = iEvent.triggerNames(*hltresults);  

  int ntrigs = hltresults->size();


  for (int itrig = 0; itrig != ntrigs; ++itrig){

    string trigName=triggerNames_.triggerName(itrig);

    if (trigName=="HLT_L1Jet6U")               triggerHLTL1Jet6U  = hltresults->accept(itrig) ;
    if (trigName=="HLT_L1Jet10U")              triggerHLTL1Jet10U = hltresults->accept(itrig) ; 

    //Take care of versioning even for the single jet triggers
    if (trigName=="HLT_Jet15U" || trigName=="HLT_Jet15U_v1" || trigName=="HLT_Jet15U_v2" || trigName=="HLT_Jet15U_v3")
      triggerHLTJet15U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet30U" || trigName=="HLT_Jet30U_v1" || trigName=="HLT_Jet30U_v2" || trigName=="HLT_Jet30U_v3")
      triggerHLTJet30U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet50U" || trigName=="HLT_Jet50U_v1" || trigName=="HLT_Jet50U_v2" || trigName=="HLT_Jet50U_v3")
      triggerHLTJet50U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet70U" || trigName=="HLT_Jet70U_v1" || trigName=="HLT_Jet70U_v2" || trigName=="HLT_Jet70U_v3")
      triggerHLTJet70U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet100U" || trigName=="HLT_Jet100U_v1" || trigName=="HLT_Jet100U_v2" || trigName=="HLT_Jet100U_v3")
      triggerHLTJet100U   = hltresults->accept(itrig) ; 

    //BTagIP path till 2E31 menu
    if (trigName=="HLT_BTagIP_Jet50U")         triggerHLTBTagIPJet50U = hltresults->accept(itrig) ;
    
    //BTagMu paths till 2E31 menu
    if (trigName=="HLT_BTagMu_Jet10U")         triggerHLTBTagMuJet10U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_Jet20U")         triggerHLTBTagMuJet20U = hltresults->accept(itrig) ;

    //BTagMu paths in 6E31 and 2E32 menu
    if (trigName=="HLT_BTagMu_DiJet10U" || trigName=="HLT_BTagMu_DiJet10U_v1" || trigName=="HLT_BTagMu_DiJet10U_v2" || trigName=="HLT_BTagMu_DiJet10U_v3")
      triggerHLTBTagMuDiJet10U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_DiJet20U" || trigName=="HLT_BTagMu_DiJet20U_v1" || trigName=="HLT_BTagMu_DiJet20U_v2" || trigName=="HLT_BTagMu_DiJet20U_v3")
      triggerHLTBTagMuDiJet20U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_DiJet20U_Mu5" || trigName=="HLT_BTagMu_DiJet20U_Mu5_v1" || trigName=="HLT_BTagMu_DiJet20U_Mu5_v2" || trigName=="HLT_BTagMu_DiJet20U_Mu5_v3")
      triggerHLTBTagMuDiJet20UMu5 = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_DiJet30U" || trigName=="HLT_BTagMu_DiJet30U_v1" || trigName=="HLT_BTagMu_DiJet30U_v2" || trigName=="HLT_BTagMu_DiJet30U_v3")
      triggerHLTBTagMuDiJet30U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_DiJet30U_Mu5" || trigName=="HLT_BTagMu_DiJet30U_Mu5_v1" || trigName=="HLT_BTagMu_DiJet30U_Mu5_v2" || trigName=="HLT_BTagMu_DiJet30U_Mu5_v3")
      triggerHLTBTagMuDiJet30UMu5 = hltresults->accept(itrig) ;

    // added by Caroline for prescale
    int prescaleval=  hltConfigProvider_.prescaleValue(iEvent, iSetup, trigName);

    if (trigName=="HLT_L1Jet6U")               prescaleHLTL1Jet6U  = prescaleval ;
    if (trigName=="HLT_L1Jet10U")              prescaleHLTL1Jet10U = prescaleval ; 

    //Take care of versioning even for the single jet prescales
    if (trigName=="HLT_Jet15U" || trigName=="HLT_Jet15U_v1" || trigName=="HLT_Jet15U_v2" || trigName=="HLT_Jet15U_v3")
      prescaleHLTJet15U   = prescaleval ;
    if (trigName=="HLT_Jet30U" || trigName=="HLT_Jet30U_v1" || trigName=="HLT_Jet30U_v2" || trigName=="HLT_Jet30U_v3")
      prescaleHLTJet30U   = prescaleval ;
    if (trigName=="HLT_Jet50U" || trigName=="HLT_Jet50U_v1" || trigName=="HLT_Jet50U_v2" || trigName=="HLT_Jet50U_v3")
      prescaleHLTJet50U   = prescaleval ;
    if (trigName=="HLT_Jet70U" || trigName=="HLT_Jet70U_v1" || trigName=="HLT_Jet70U_v2" || trigName=="HLT_Jet70U_v3")
      prescaleHLTJet70U   = prescaleval ;
    if (trigName=="HLT_Jet100U" || trigName=="HLT_Jet100U_v1" || trigName=="HLT_Jet100U_v2" || trigName=="HLT_Jet100U_v3")
      prescaleHLTJet100U   = prescaleval ; 

    //BTagIP path till 2E31 menu
    if (trigName=="HLT_BTagIP_Jet50U")         prescaleHLTBTagIPJet50U = prescaleval ;
    
    //BTagMu paths till 2E31 menu
    if (trigName=="HLT_BTagMu_Jet10U")         prescaleHLTBTagMuJet10U = prescaleval ;
    if (trigName=="HLT_BTagMu_Jet20U")         prescaleHLTBTagMuJet20U = prescaleval ;

    //BTagMu paths in 6E31 and 2E32 menu
    if (trigName=="HLT_BTagMu_DiJet10U" || trigName=="HLT_BTagMu_DiJet10U_v1" || trigName=="HLT_BTagMu_DiJet10U_v2" || trigName=="HLT_BTagMu_DiJet10U_v3")
      prescaleHLTBTagMuDiJet10U = prescaleval ;
    if (trigName=="HLT_BTagMu_DiJet20U" || trigName=="HLT_BTagMu_DiJet20U_v1" || trigName=="HLT_BTagMu_DiJet20U_v2" || trigName=="HLT_BTagMu_DiJet20U_v3")
      prescaleHLTBTagMuDiJet20U = prescaleval ;
    if (trigName=="HLT_BTagMu_DiJet20U_Mu5" || trigName=="HLT_BTagMu_DiJet20U_Mu5_v1" || trigName=="HLT_BTagMu_DiJet20U_Mu5_v2" || trigName=="HLT_BTagMu_DiJet20U_Mu5_v3")
      prescaleHLTBTagMuDiJet20UMu5 = prescaleval ;
    if (trigName=="HLT_BTagMu_DiJet30U" || trigName=="HLT_BTagMu_DiJet30U_v1" || trigName=="HLT_BTagMu_DiJet30U_v2" || trigName=="HLT_BTagMu_DiJet30U_v3")
      prescaleHLTBTagMuDiJet30U = prescaleval ;
    if (trigName=="HLT_BTagMu_DiJet30U_Mu5" || trigName=="HLT_BTagMu_DiJet30U_Mu5_v1" || trigName=="HLT_BTagMu_DiJet30U_Mu5_v2" || trigName=="HLT_BTagMu_DiJet30U_Mu5_v3")
      prescaleHLTBTagMuDiJet30UMu5 = prescaleval ;
    //end add

    //Single Jet trigger in 4_1_2_patch1
    if (trigName=="HLT_L1SingleJet36_v1" || trigName=="HLT_L1SingleJet36_v2") {
        triggerHLT_L1SingleJet36=hltresults->accept(itrig) ;
        prescaleHLT_L1SingleJet36= prescaleval;
    }
    if (trigName=="HLT_Jet30_v1" || trigName=="HLT_Jet30_v2") {
        triggerHLT_Jet30=hltresults->accept(itrig) ;
        prescaleHLT_Jet30= prescaleval;
    }
    if (trigName=="HLT_Jet60_v1" || trigName=="HLT_Jet60_v2") {
        triggerHLT_Jet60=hltresults->accept(itrig) ;
        prescaleHLT_Jet60= prescaleval;
    }
    if (trigName=="HLT_Jet80_v1" || trigName=="HLT_Jet80_v2") {
        triggerHLT_Jet80=hltresults->accept(itrig) ;
        prescaleHLT_Jet80= prescaleval;
    }
    if (trigName=="HLT_Jet110_v1" || trigName=="HLT_Jet110_v2") {
        triggerHLT_Jet110=hltresults->accept(itrig) ;
        prescaleHLT_Jet110= prescaleval;
    }
    if (trigName=="HLT_Jet150_v1" || trigName=="HLT_Jet150_v2") {
        triggerHLT_Jet150=hltresults->accept(itrig) ;
        prescaleHLT_Jet150= prescaleval;
    }
    if (trigName=="HLT_Jet190_v1" || trigName=="HLT_Jet190_v2") {
        triggerHLT_Jet190=hltresults->accept(itrig) ;
        prescaleHLT_Jet190= prescaleval;
    }
    if (trigName=="HLT_Jet240_v1" || trigName=="HLT_Jet240_v2") {
        triggerHLT_Jet240=hltresults->accept(itrig) ;
        prescaleHLT_Jet240= prescaleval;
    }
    if (trigName=="HLT_Jet370_v1") {
        triggerHLT_Jet370=hltresults->accept(itrig) ;
        prescaleHLT_Jet370= prescaleval;
    }
    if (trigName=="HLT_Jet370_NoJetID_v1") {
        triggerHLT_Jet370_NoJetID=hltresults->accept(itrig) ;
        prescaleHLT_Jet370_NoJetID= prescaleval;
    }
    if(trigName=="HLT_DiJetAve15U_v4" ) { 
      triggerHLT_DiJetAve15U_v4  = hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve15U_v4 = prescaleval;               
    }
    
    if(trigName=="HLT_DiJetAve30U_v4" ) { 
      triggerHLT_DiJetAve30U_v4  = hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve30U_v4 = prescaleval;               
    }        
    if(trigName=="HLT_DiJetAve50U_v4" ) { 
      triggerHLT_DiJetAve50U_v4= hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve50U_v4= prescaleval;               
    }
    if(trigName=="HLT_DiJetAve70U_v4" ) { 
      triggerHLT_DiJetAve70U_v4= hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve70U_v4= prescaleval;               
    }        
    if(trigName=="HLT_DiJetAve100U_v4") {
      triggerHLT_DiJetAve100U_v4= hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve100U_v4= prescaleval;               
    }         
    if(trigName=="HLT_DiJetAve140U_v4") {
      triggerHLT_DiJetAve140U_v4= hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve140U_v4= prescaleval;               
    }         
    if(trigName=="HLT_DiJetAve180U_v4") {
      triggerHLT_DiJetAve180U_v4= hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve180U_v4= prescaleval;               
    }         
    if(trigName=="HLT_DiJetAve300U_v4") {  
      triggerHLT_DiJetAve300U_v4= hltresults->accept(itrig) ;
      prescaleHLT_DiJetAve300U_v4= prescaleval;               
    }       
    if(trigName=="HLT_BTagMu_DiJet20_Mu5_v2" || trigName=="HLT_BTagMu_DiJet20_Mu5_v3") { 
      triggerHLT_BTagMu_DiJet20_Mu5= hltresults->accept(itrig) ;
      prescaleHLT_BTagMu_DiJet20_Mu5= prescaleval;               
    }  
    if(trigName=="HLT_BTagMu_DiJet40_Mu5_v3") { 
      triggerHLT_BTagMu_DiJet40_Mu5= hltresults->accept(itrig) ;
      prescaleHLT_BTagMu_DiJet40_Mu5= prescaleval;               
    }  
    if(trigName=="HLT_BTagMu_DiJet60_Mu7_v2") {
      triggerHLT_BTagMu_DiJet60_Mu7_v2= hltresults->accept(itrig) ;
      prescaleHLT_BTagMu_DiJet60_Mu7_v2= prescaleval;               
    }   
    if(trigName=="HLT_BTagMu_DiJet70_Mu5_v3") { 
      triggerHLT_BTagMu_DiJet70_Mu5= hltresults->accept(itrig) ;
      prescaleHLT_BTagMu_DiJet70_Mu5= prescaleval;               
    }  
    if(trigName=="HLT_BTagMu_DiJet80_Mu9_v2") { 
      triggerHLT_BTagMu_DiJet80_Mu9_v2= hltresults->accept(itrig) ;
      prescaleHLT_BTagMu_DiJet80_Mu9_v2= prescaleval;               
    }  
    if(trigName=="HLT_BTagMu_DiJet100_Mu9_v2") {
      triggerHLT_BTagMu_DiJet100_Mu9_v2= hltresults->accept(itrig) ;
      prescaleHLT_BTagMu_DiJet100_Mu9_v2= prescaleval;               
    }  
    if(trigName=="HLT_BTagMu_DiJet110_Mu5_v3") {
      triggerHLT_BTagMu_DiJet110_Mu5= hltresults->accept(itrig) ;
      prescaleHLT_BTagMu_DiJet110_Mu5= prescaleval;               
    }
  }  
  
  
  eventNumber = iEvent.eventAuxiliary().event();
  runNumber = iEvent.eventAuxiliary().run();
  lumiBlockNumber = iEvent.eventAuxiliary().luminosityBlock();

  Handle< View<Jet> > jets;
  iEvent.getByLabel(jet_src_,jets);

  Handle<JetTracksAssociation::Container > jetTracks;
  iEvent.getByLabel(jet_tracks_,jetTracks);

  Handle<reco::VertexCollection> primaryVertex;
  iEvent.getByLabel(primaryVertexProducer_, primaryVertex);

  // offlinePrimaryVertices are already selected with
  // ndof > 4 && abs(z) <= 24 && position.Rho <= 2
  numberOfPrimaryVertices = primaryVertex->size();
  
  if(getMCPUInfo_) {
    edm::InputTag PileupSrc_("addPileupInfo");
    Handle<std::vector< PileupSummaryInfo > >  puInfo;
    bool bPuInfo=iEvent.getByLabel(PileupSrc_, puInfo);
    
    if (bPuInfo) {
      numberOfPUVertices = (*puInfo)[0].getPU_NumInteractions();

      //   std::cout<<" numberOfPUVertices = " << numberOfPUVertices << std::endl;

    }
  }
  
  edm::ESHandle<TransientTrackBuilder> builder;
  iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder", builder);

  //Get the TagInfo stuff and make is accesible with a map to a RefToBase<Jet>, since that's apparently what the JetTags use
  typedef RefToBase<Jet> JetRef;
  typedef map<JetRef, const SoftLeptonTagInfo*, JetRefCompare> slTagInfoMap;
  slTagInfoMap softElectronTagInfo;
  edm::Handle< View < reco::SoftLeptonTagInfo > > SoftElectronTagInfoVector;
 
  iEvent.getByLabel(electron_tag_infos_,SoftElectronTagInfoVector);
  for(View< reco::SoftLeptonTagInfo >::const_iterator iTagInfo = SoftElectronTagInfoVector->begin(); iTagInfo != SoftElectronTagInfoVector->end(); iTagInfo++) 
    {
      softElectronTagInfo[iTagInfo->jet()] = &*iTagInfo;
    }
    

  slTagInfoMap softMuonTagInfo;
  edm::Handle< View < reco::SoftLeptonTagInfo > > SoftMuonTagInfoVector;
 
  iEvent.getByLabel(muon_tag_infos_,SoftMuonTagInfoVector);
  for(View< reco::SoftLeptonTagInfo >::const_iterator iTagInfo = SoftMuonTagInfoVector->begin(); iTagInfo != SoftMuonTagInfoVector->end(); iTagInfo++) 
    {
      softMuonTagInfo[iTagInfo->jet()] = &*iTagInfo;
    }
    

  typedef map< JetRef, const SecondaryVertexTagInfo*, JetRefCompare > svTagInfoMap;
  svTagInfoMap svTagInfo;
  edm::Handle< View < reco::SecondaryVertexTagInfo > > svTagInfoVector;

  iEvent.getByLabel(SV_tag_infos_,svTagInfoVector);
  for(View< reco::SecondaryVertexTagInfo >::const_iterator iTagInfo = svTagInfoVector->begin(); iTagInfo != svTagInfoVector->end(); iTagInfo++) 
    {
      svTagInfo[iTagInfo->jet()] = &*iTagInfo;
    }
    
  typedef map<JetRef, const TrackIPTagInfo*, JetRefCompare> ipTagInfoMap;
  ipTagInfoMap ipTagInfo;
  edm::Handle< View < reco::TrackIPTagInfo > > ipTagInfoVector;

  iEvent.getByLabel(IP_tag_infos_,ipTagInfoVector);  
  for(View< reco::TrackIPTagInfo >::const_iterator iTagInfo = ipTagInfoVector->begin(); iTagInfo != ipTagInfoVector->end(); iTagInfo++) 
    {
      ipTagInfo[iTagInfo->jet()] = &*iTagInfo;
    }
    
  //Get the MC Truth Matching (if requested) and define a map from RefToBase<Jet> to the flavor; if MC Truth not requested, fill with -1

  typedef map<JetRef, int, JetRefCompare> FlavorMap;
  FlavorMap flavor;

  edm::Handle<JetFlavourMatchingCollection> jetMC;

  if(getMCTruth_)
    {
      iEvent.getByLabel(jet_MC_src_, jetMC);      
      for (JetFlavourMatchingCollection::const_iterator iFlav = jetMC->begin(); iFlav != jetMC->end(); iFlav++) 
	{
	  int fl = std::abs(iFlav->second.getFlavour());
	  flavor[iFlav->first] = fl;
	}

      // fill pt hat
      pthat = -1;
      Handle< GenEventInfoProduct   > genInfo;
      iEvent.getByLabel("generator", genInfo  );      
      if (genInfo.isValid()) {
	if( genInfo->hasBinningValues() )
	  if( genInfo->binningValues().size() > 0 ){
	    pthat = genInfo->binningValues()[0];  
	  }
      }
    } 
  else 
    {
      int fl = -1;
      for (unsigned int iJet = 0; iJet < jets->size(); iJet++)
	{
	  flavor[RefToBase<Jet>(jets, iJet)] = fl;
	}
      pthat = -2;
    }

  // determine gluon splitting
  isBGluonSplitting = 0;
  isCGluonSplitting = 0;
  if(getMCTruth_) {
    bool bFoundS3BQuark = false;
    bool bFoundS2BQuark = false;
    bool bFoundS3CQuark = false;
    bool bFoundS2CQuark = false;
    edm::Handle<GenParticleCollection> genParticles;
    iEvent.getByLabel("genParticles" , genParticles );
    for( size_t i = 0; i < genParticles->size(); ++ i ) {
      const GenParticle & genCand = (*genParticles)[ i ];
      int MC_particleID=abs(genCand.pdgId());
      if(genCand.status() == 3 && MC_particleID ==5){
	bFoundS3BQuark = true;
      }
      if(genCand.status() == 2 && MC_particleID ==5){
	bFoundS2BQuark = true;
      }


      if(genCand.status() == 3 && MC_particleID ==4){
	bFoundS3CQuark = true;
      }
      if(genCand.status() == 2 && MC_particleID ==4){
	bFoundS2CQuark = true;
      }
    }
    // if no status 3 b quark but status 2
    if( (!bFoundS3BQuark) && bFoundS2BQuark  ) isBGluonSplitting  = 1;
    // if no status 3 c quark but status 2
    if( (!bFoundS3CQuark) && bFoundS2CQuark  ) isCGluonSplitting  = 1;
  }

  //Get the btaggers that are defined in the configuration file

  map< string, reco::JetTagCollection > bTags;

  for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
    {
      edm::Handle<reco::JetTagCollection> bTagHandle;
      iEvent.getByLabel(ibTag->getParameter<InputTag>("label"), bTagHandle);
      bTags[ibTag->getParameter<string>("alias")] = *bTagHandle;
    }

  
  //instantiate a tagging variable computer for unification of some calculations like vertex mass corrections
  edm::ESHandle<JetTagComputer> computerHandle;;
  iSetup.get<JetTagComputerRecord>().get(SVComputer_.label(), computerHandle);
  const GenericMVAJetTagComputer *computer =
    dynamic_cast<const GenericMVAJetTagComputer*>(
						  computerHandle.product());
  if (!computer){
    std::cout<<" computer missing !!!"<< std::endl;
    exit(1);
  }
  computer->passEventSetup(iSetup);
  
  int iTotalTracksCounter = 0;
  nJets = jets->size();
  //Begin Loop over Jets and record the various information
  for (int iJet = 0; iJet<nJets; iJet++)
    {
      if(iJet >= (int)MAXJETS) return;

      JetRef thisJetRef = RefToBase<Jet>(jets, iJet);
 
      //Basic Jet Information
      jetP4[iJet] = (thisJetRef->p4());               
      jetPt[iJet] = thisJetRef->p4().Pt();                              
      jetEta[iJet] = (thisJetRef->p4().Eta());
      jetPhi[iJet] = (thisJetRef->p4().Phi());
      //Store some Calo Jet Information:
      if(const CaloJet* caloJet = dynamic_cast<const CaloJet*>(&(*(thisJetRef.get()) )))
	{
	  jetEMFraction[iJet] = (caloJet->emEnergyFraction());
	}
      else
	{
	  jetEMFraction[iJet] = (-1.0);
	}
      //Store some Particle Flow Jet Information
      if(const PFJet* pfJet = dynamic_cast<const PFJet*>(&(*(thisJetRef.get()) )))
	{
	  jetChargedEmEnergyFraction[iJet] = (pfJet->chargedEmEnergyFraction());
	  jetNeutralEmEnergyFraction[iJet] = (pfJet->neutralEmEnergyFraction());
	  jetChargedHadronEnergyFraction[iJet] = (pfJet->chargedHadronEnergyFraction());
	  jetNeutralHadronEnergyFraction[iJet] = (pfJet->neutralHadronEnergyFraction());
	  jetChargedMultiplicity[iJet] = (pfJet->chargedMultiplicity());
	}
      else
	{
	  jetChargedEmEnergyFraction[iJet] = (-1.0);
	  jetNeutralEmEnergyFraction[iJet] = (-1.0);
	  jetChargedHadronEnergyFraction[iJet] = (-1.0);
	  jetNeutralHadronEnergyFraction[iJet] = (-1.0);
	  jetChargedMultiplicity[iJet] = (-1.0);
	}
      jetMass[iJet] = (thisJetRef->p4().M());
      jetnConstituents[iJet] = (thisJetRef->nConstituents());
      jetnTracks[iJet] = ((*jetTracks)[thisJetRef].size());

      jetVertex[iJet] = (math::XYZVector(thisJetRef->vx(),thisJetRef->vy(),thisJetRef->vz()));
      jetVertexChi2[iJet] = (thisJetRef->vertexChi2());
      jetVertexChi2Ndof[iJet] = (thisJetRef->vertexNdof());
      jetVertexNormalizedChi2[iJet] = (thisJetRef->vertexNormalizedChi2());

      //Track Information


      //Stolen from CMSSW/RecoBTag/ImpactParameter/plugins/TrackIPProducer.cc
      Vertex dummy;
      const Vertex *pv = &dummy;
      edm::Ref<VertexCollection> pvRef;
      if (primaryVertex->size() != 0) {
	pv = &*primaryVertex->begin();
	// we always use the first vertex (at the moment)
	pvRef = edm::Ref<VertexCollection>(primaryVertex, 0);
      } else { // create a dummy PV
	Vertex::Error e;
	e(0, 0) = 0.0015 * 0.0015;
	e(1, 1) = 0.0015 * 0.0015;
	e(2, 2) = 15. * 15.;
	Vertex::Point p(0, 0, 0);
	dummy = Vertex(p, e, 0, 0, 0);
      }
      //End Stealing
      
      // vertex properties
      numberOfTracksAtPV = pv->nTracks();
      PVx = pv->x();
      PVy = pv->y();
      PVz = pv->z();
      PVChi2 = pv->chi2();
      PVndof = pv->ndof();
      PVNormalizedChi2 = pv->normalizedChi2();

      //some counters
      size_t nSelectedTracks=0;
      size_t nSelectedAndDecayLengthAndJetAsixTracks=0;

      size_t counter=0;
    
      for(track_iterator iTrack = (*jetTracks)[thisJetRef].begin(); iTrack != (*jetTracks)[thisJetRef].end(); iTrack++)
	{ 
	  if(iTotalTracksCounter >= (int)MAXTRACKS) return;

	  trackJetIndex[iTotalTracksCounter] = iJet;
	  bool isSelected = false;
	  for(track_iterator jTrack = ipTagInfo[thisJetRef]->selectedTracks().begin(); jTrack != ipTagInfo[thisJetRef]->selectedTracks().end(); jTrack++)
	    {
	      if((*iTrack)==(*jTrack)) {
		isSelected = true;
		break;
	      }
	    }
	
	  if(isSelected) nSelectedTracks++;


	  // check if track is attached to a vertex
	  trackIsVertexTrack[iTotalTracksCounter] = false;
	  bool hasVertex = svTagInfo[thisJetRef]->nVertices() > 0;
	  if(hasVertex)
	    {
	      const Vertex &sv = svTagInfo[thisJetRef]->secondaryVertex(0);
	      for(Vertex::trackRef_iterator iter = sv.tracks_begin();
		  iter != sv.tracks_end(); iter++) {
		if (sv.trackWeight(*iter) < 0.5)
		  continue;
		
		TrackRef vtxTrackRef =  (*iter).castTo<TrackRef>();

		if( vtxTrackRef == (*iTrack) ){
		  trackIsVertexTrack[iTotalTracksCounter] = true;
		}
	      }
	    }

	  trackSelected[iTotalTracksCounter] = (isSelected);
	  track3Momentum[iTotalTracksCounter] = (math::XYZVector((*iTrack)->px(),(*iTrack)->py(),(*iTrack)->pz()));
	  trackTransverseMomentum[iTotalTracksCounter] = ((*iTrack)->pt());
	  trackEta[iTotalTracksCounter] = ((*iTrack)->eta());
	  trackPhi[iTotalTracksCounter] = ((*iTrack)->phi());
	  trackMomentum[iTotalTracksCounter] = ((*iTrack)->p());
	  trackNHits[iTotalTracksCounter] = ((*iTrack)->hitPattern().numberOfValidHits());
	  trackNPixelHits[iTotalTracksCounter] = ((*iTrack)->hitPattern().numberOfValidPixelHits());
	  trackChi2[iTotalTracksCounter] = ((*iTrack)->chi2());
	  trackNormChi2[iTotalTracksCounter] = ((*iTrack)->normalizedChi2());
	  //trackQuality[iTotalTracksCounter] = ((*iTrack)->qualityMask());
	  //cout << (*iTrack)->qualityMask() << endl;
	  for(int i = 2; i>-2; i--){
	    if((*iTrack)->quality(reco::TrackBase::TrackQuality(i))){
	      trackQuality[iTotalTracksCounter] = (i);
	      break;
	    }
	  }
	  trackLongitudinalImpactParameter[iTotalTracksCounter] = ((*iTrack)->dz(pv->position()));
  	  TransientTrack transientTrack = builder->build(*iTrack);
  	  GlobalVector direction(thisJetRef->momentum().x(), thisJetRef->momentum().y(), thisJetRef->momentum().z());
  	  Measurement1D ip3d = IPTools::signedImpactParameter3D(transientTrack, direction, *pv).second;
  	  Measurement1D ip2d = IPTools::signedTransverseImpactParameter(transientTrack, direction, *pv).second;
  	  trackIP3d[iTotalTracksCounter] = (ip3d.value());
  	  trackIP2d[iTotalTracksCounter] = (ip2d.value());
  	  trackIP3dError[iTotalTracksCounter] = (ip3d.error());
  	  trackIP2dError[iTotalTracksCounter] = (ip2d.error());
	  double decayLength=-1;
	  TrajectoryStateOnSurface closest =
	    IPTools::closestApproachToJet(transientTrack.impactPointState(),
					  *pv, direction,
					  transientTrack.field());
	  if (closest.isValid()){
	    decayLength =  (closest.globalPosition()-   RecoVertex::convertPos(pv->position())).mag() ;
	  }
	  else{
	    decayLength = -1;
	  }
	  trackDecayLength[iTotalTracksCounter] = (decayLength);

	  double distJetAxis =  IPTools::jetTrackDistance(transientTrack, direction, *pv).second.value();
	  trackDistJetAxis[iTotalTracksCounter] = ( distJetAxis );
	  trackDeltaR[iTotalTracksCounter] = ( ROOT::Math::VectorUtil::DeltaR(thisJetRef->momentum(),(*iTrack)->momentum()) );

	  if(getSharedHitInfo_) {
	    int tsharedP1, tsharedP2, tsharedP3;
	    trackHasSharedPix1[iTotalTracksCounter] = ( tsharedP1 = hasSharedHit(1, counter, (*jetTracks)[thisJetRef]));
	    trackHasSharedPix2[iTotalTracksCounter] = ( tsharedP2 = hasSharedHit(2, counter, (*jetTracks)[thisJetRef]));
	    trackHasSharedPix3[iTotalTracksCounter] = ( tsharedP3 = hasSharedHit(3, counter, (*jetTracks)[thisJetRef]));
	    trackHasSharedPixAll[iTotalTracksCounter] = ( tsharedP1 || tsharedP2 || tsharedP3 );
	  }
	  
	  if(isSelected && decayLength < 5 && fabs(distJetAxis) < 0.07) nSelectedAndDecayLengthAndJetAsixTracks++;   //cut is hardcoded for now

	  counter++;
	  iTotalTracksCounter++;
	}       


      //MC Truth Information
      MCTrueFlavor[iJet] = (flavor[thisJetRef]);                          
      //secondaryVertexTagInfos:
      
      SVnSelectedTracks[iJet] = (svTagInfo[thisJetRef]->nSelectedTracks());  
      bool hasVertex = svTagInfo[thisJetRef]->nVertices() > 0;
      if(hasVertex)
	{
	  // Compute tagging variables
	  std::vector<const reco::BaseTagInfo*>  baseTagInfos;
	  baseTagInfos.push_back( &(*ipTagInfo[thisJetRef]) ); 
	  baseTagInfos.push_back( &(*svTagInfo[thisJetRef]) );
	  JetTagComputer::TagInfoHelper helper(baseTagInfos);
	  TaggingVariableList vars = computer->taggingVariables(helper);
	  math::XYZVector thisVertex(svTagInfo[thisJetRef]->secondaryVertex(0).x(),svTagInfo[thisJetRef]->secondaryVertex(0).y(),svTagInfo[thisJetRef]->secondaryVertex(0).z());
	  
	  edm::RefToBase<Jet> jet = ipTagInfo[thisJetRef]->jet();
	  math::XYZVector jetDir = jet->momentum().Unit();
	  
	  SVnVertices[iJet] = (svTagInfo[thisJetRef]->nVertices());
	  SecondaryVertex[iJet] = (thisVertex);
	  SV3dDistance[iJet] = (svTagInfo[thisJetRef]->flightDistance(0).value());                          
	  SV3dDistanceError[iJet] = (svTagInfo[thisJetRef]->flightDistance(0).error());                     
	  SV2dDistance[iJet] = (svTagInfo[thisJetRef]->flightDistance(0, true).value());                          
	  SV2dDistanceError[iJet] = (svTagInfo[thisJetRef]->flightDistance(0, true).error());                     
	  SVChi2[iJet] = (svTagInfo[thisJetRef]->secondaryVertex(0).chi2());                                
	  SVDegreesOfFreedom[iJet] = (svTagInfo[thisJetRef]->secondaryVertex(0).ndof());                    
	  SVNormChi2[iJet] = (svTagInfo[thisJetRef]->secondaryVertex(0).normalizedChi2());
	  SVnFirstVertexTracksAll[iJet] = (svTagInfo[thisJetRef]->secondaryVertex(0).tracksSize());
	  SVnFirstVertexTracks[iJet] = ( svTagInfo[thisJetRef]->nVertexTracks(0)  );
	  SVnVertexTracks[iJet] = ( svTagInfo[thisJetRef]->nVertexTracks()  );
	  int nVertexTrackSize = 0;
	  for(unsigned int i=0; i< svTagInfo[thisJetRef]->nVertices(); i++) nVertexTrackSize+= svTagInfo[thisJetRef]->secondaryVertex(i).tracksSize();
	  SVnVertexTracksAll[iJet] = ( nVertexTrackSize );
	  if(vars.checkTag(reco::btau::vertexMass)) SVMass[iJet] = ( vars.get( reco::btau::vertexMass));
	  else  SVMass[iJet] = ( -9999 );
	  if(vars.checkTag(reco::btau::vertexEnergyRatio)) SVEnergyRatio[iJet] = ( vars.get(reco::btau::vertexEnergyRatio) );
	  else SVEnergyRatio[iJet] = ( -9999 );
	  
	  if(vars.checkTag(reco::btau::vertexJetDeltaR)) SVjetDeltaR[iJet] = (  vars.get( reco::btau::vertexJetDeltaR) );
	  else SVjetDeltaR[iJet] = ( -9999 );

	  if(vars.checkTag(reco::btau::trackSip3dSigAboveCharm) ) SVIPFirstAboveCharm[iJet] = (  vars.get( reco::btau::trackSip3dSigAboveCharm ));
	  else SVIPFirstAboveCharm[iJet] = (  -9999 );
	  
//        added by Caroline
          int totcharge=0;
//        end add

	  TrackKinematics vertexKinematics;
	  const Vertex &vertex = svTagInfo[thisJetRef]->secondaryVertex(0);
	  bool hasRefittedTracks = vertex.hasRefittedTracks();
	  TrackRefVector tracks = svTagInfo[thisJetRef]->vertexTracks(0);
	  for(TrackRefVector::const_iterator track = tracks.begin();
	      track != tracks.end(); track++) {
	    double w = svTagInfo[thisJetRef]->trackWeight(0, *track);
	    if (w < 0.5)
	      continue;
	    if (hasRefittedTracks) {
	      Track actualTrack = vertex.refittedTrack(*track);
	      vertexKinematics.add(actualTrack, w);

              // added Caroline
              totcharge+=actualTrack.charge();
              // end add
		  
	    } else {
	      vertexKinematics.add(**track, w);

              // added Caroline
              const reco::Track& mytrack = **track;
              totcharge+=mytrack.charge();
              // end add
	    }
	  }
	  bool useTrackWeights = true;
	  math::XYZTLorentzVector vertexSum = useTrackWeights
	    ? vertexKinematics.weightedVectorSum()
	    : vertexKinematics.vectorSum();
	  
	  math::XYZTLorentzVector flightDir( svTagInfo[thisJetRef]->flightDirection(0).x(), svTagInfo[thisJetRef]->flightDirection(0).y(), svTagInfo[thisJetRef]->flightDirection(0).z(), 0  );
	  SVvtxSumJetDeltaR[iJet] = ( Geom::deltaR(vertexSum, jetDir) );
	  SVvtxSumVtxDirDeltaR[iJet] = ( Geom::deltaR( flightDir, vertexSum ) );
	  
	  SVvtxPt[iJet] = vertex.p4().pt();
	  SVvtxSumDirEta[iJet] = vertex.p4().eta();
	  SVvtxSumDirPhi[iJet] = vertex.p4().phi();
	  SVvtxDirEta[iJet] =  flightDir.eta();
	  SVvtxDirPhi[iJet] =  flightDir.phi();

          // new variables (added by Caroline)
          // PTrel info
          math::XYZVector flightDir2=math::XYZVector(flightDir.x(),flightDir.y(),flightDir.z());
          //math::XYZVector vertexSum2=math::XYZVector(vertex.p4().px(),vertex.p4().py(),vertex.p4().pz());
          math::XYZVector vertexSum2=math::XYZVector(vertexSum.x(),vertexSum.y(),vertexSum.z());
          SVvtxSumPTrel[iJet]=Perp(vertexSum2, jetDir);
          SVvtxDirPTrel[iJet]=Perp(flightDir2, jetDir);

          // Distance to Jet Axis (inspired from RecoBTag/BTagTools/src/SignedImpactParameter3D.cc (l 141 -> 154)

          //get the  secondary vertex line
          //Line::PositionType pos(GlobalPoint(vertexSum.x(),vertexSum.y(),vertexSum.z()));
          Line::PositionType pos(GlobalPoint(vertex.p4().x(),vertex.p4().y(),vertex.p4().z()));
          Line::DirectionType dir(GlobalVector(flightDir.px(),flightDir.py(),flightDir.pz()));
          Line trackline(pos,dir);
          // get the Jet  line 
          Line::PositionType pos2(GlobalPoint(jetVertex[iJet].x(),jetVertex[iJet].y(),jetVertex[iJet].z()));
          Line::DirectionType dir2(GlobalVector(jetDir.x(),jetDir.y(),jetDir.z()));
          Line jetline(pos2,dir2);
          // now compute the distance between the two lines
          SVvtxDistJetAxis[iJet] = (jetline.distance(trackline)).mag();


          // total charge at the secondary vertex
          SVtotCharge[iJet]=totcharge;

          //end add
	  
	}
      else
	{
	  SVnVertices[iJet] = (0);
	  SecondaryVertex[iJet] = (math::XYZVector(0,0,0));             
	  SV3dDistance[iJet] = (-1);                          
	  SV3dDistanceError[iJet] = (-1);                     
	  SV2dDistance[iJet] = (-1);                          
	  SV2dDistanceError[iJet] = (-1);                     
	  SVChi2[iJet] = (-1);                                
	  SVDegreesOfFreedom[iJet] = (-1);                    
	  SVNormChi2[iJet] = (-1);                                                           
	  SVnVertexTracks[iJet] = (-1);
	  SVnVertexTracksAll[iJet] = (-1);
	  SVnFirstVertexTracksAll[iJet] = (-1);
	  SVnFirstVertexTracks[iJet] = (-1);
	  SVMass[iJet] = (-1);
	  SVEnergyRatio[iJet] = (-1);
	  SVjetDeltaR[iJet] = (-1);
	  
	  SVIPFirstAboveCharm[iJet] = (  -9999 );
	  SVvtxSumVtxDirDeltaR[iJet] = ( -9999 );
	  SVvtxSumJetDeltaR[iJet] =  ( -9999 );

	  SVvtxPt[iJet] = (-1 );
	  SVvtxSumDirEta[iJet] = (-9999 );
	  SVvtxSumDirPhi[iJet] = (-9999 );
	  SVvtxDirEta[iJet] = (-9999 );
	  SVvtxDirPhi[iJet] = (-9999 );

          SVvtxSumPTrel[iJet] = (-9999 );
          SVvtxDirPTrel[iJet] = (-9999 );
          SVvtxDistJetAxis[iJet] =  (-9999 );
          SVtotCharge[iJet] = (-9999 );

	}
      
      
      //impactParameterTagInfos
   
      const GlobalVector jetAxis = ipTagInfo[thisJetRef]->axis();
      const math::XYZVector axis( jetAxis.x(), jetAxis.y(), jetAxis.z());
      const math::XYZVector ghostTrack(ipTagInfo[thisJetRef]->ghostTrack()->px(),ipTagInfo[thisJetRef]->ghostTrack()->py(),ipTagInfo[thisJetRef]->ghostTrack()->pz());

      //	  IPnSelectedTracks.push_back(ipTagInfo[thisJetRef]->selectedTracks().size());                       
      IPnSelectedTracks[iJet] = ( nSelectedAndDecayLengthAndJetAsixTracks );                       
      IPghostTrackP3[iJet] = (ghostTrack);
      IPghostTrackPt[iJet] = (ipTagInfo[thisJetRef]->ghostTrack()->pt());                        
      IPghostTrackPtRel[iJet] = (Perp(ghostTrack,axis));
      IPghostTrackEta[iJet] = (ipTagInfo[thisJetRef]->ghostTrack()->eta());                       
      IPghostTrackPhi[iJet] = (ipTagInfo[thisJetRef]->ghostTrack()->phi());                       
      IPghostTrackDeltaR[iJet] = (deltaR(thisJetRef->eta(), thisJetRef->phi(), ipTagInfo[thisJetRef]->ghostTrack()->eta(), ipTagInfo[thisJetRef]->ghostTrack()->phi()));                    

      if(getSharedHitInfo_) {
	int nPix1Shared, nPix1Total;
	int nPix2Shared, nPix2Total;
	int nPix3Shared, nPix3Total;
	getSharedHitsInfo(1, ipTagInfo[thisJetRef]->selectedTracks(), nPix1Shared, nPix1Total);
	getSharedHitsInfo(2, ipTagInfo[thisJetRef]->selectedTracks(), nPix2Shared, nPix2Total);
	getSharedHitsInfo(3, ipTagInfo[thisJetRef]->selectedTracks(), nPix3Shared, nPix3Total);
	
	IPPix1TotalHits[iJet] = (nPix1Total); IPPix1SharedHits[iJet] = (nPix1Shared);
	IPPix2TotalHits[iJet] = (nPix2Total); IPPix2SharedHits[iJet] = (nPix2Shared);
	IPPix3TotalHits[iJet] = (nPix3Total); IPPix3SharedHits[iJet] = (nPix3Shared);
	IPPixAllTotalHits[iJet] = (nPix1Total + nPix2Total + nPix3Total); IPPixAllSharedHits[iJet] = (nPix1Shared + nPix2Shared + nPix3Shared);
      }
      
      for(unsigned int iTrack = 0; iTrack < 4; iTrack++)
	{
	  if(iTrack <  ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP3DSig).size())
	    {
	      size_t location3D = ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP3DSig)[iTrack];
	      for(int i = 2; i>-2; i--){
		if(ipTagInfo[thisJetRef]->selectedTracks()[location3D]->quality(reco::TrackBase::TrackQuality(i))){
		  IP3dTrackQuality[iTrack][iJet] = (i);
		  break;
		}
	      }

	      if(getSharedHitInfo_) {
		int sharedP1, sharedP2, sharedP3;
		IP3dHasSharedPix1[iTrack][iJet] = (sharedP1=hasSharedHit(1, location3D,  ipTagInfo[thisJetRef]->selectedTracks()));
		IP3dHasSharedPix2[iTrack][iJet] = (sharedP2=hasSharedHit(2, location3D,  ipTagInfo[thisJetRef]->selectedTracks()));
		IP3dHasSharedPix3[iTrack][iJet] = (sharedP3=hasSharedHit(3, location3D,  ipTagInfo[thisJetRef]->selectedTracks()));
		IP3dHasSharedPixAll[iTrack][iJet] = ( sharedP1 || sharedP2 || sharedP3  );
	      }
	      
	      IP3d[iTrack][iJet] = (ipTagInfo[thisJetRef]->impactParameterData()[location3D].ip3d.value());
	      IP3dError[iTrack][iJet] = (ipTagInfo[thisJetRef]->impactParameterData()[location3D].ip3d.error());
	      IP3dProbability[iTrack][iJet] = (ipTagInfo[thisJetRef]->probabilities(0)[location3D]);
	      const math::XYZVector thisTrack(ipTagInfo[thisJetRef]->selectedTracks()[location3D]->px(),
					      ipTagInfo[thisJetRef]->selectedTracks()[location3D]->py(),
					      ipTagInfo[thisJetRef]->selectedTracks()[location3D]->pz());
	      IP3dTrackPtRel[iTrack][iJet] = ( Perp(thisTrack,axis ) );
	      IP3dDistJetAxis[iTrack][iJet] = (ipTagInfo[thisJetRef]->impactParameterData()[location3D].distanceToJetAxis.value());
	      IP3dDecayLength[iTrack][iJet] = ( (ipTagInfo[thisJetRef]->impactParameterData()[location3D].closestToJetAxis 
						 -  RecoVertex::convertPos(pv->position())).mag() );
	      IP3dDeltaR[iTrack][iJet] = (  ROOT::Math::VectorUtil::DeltaR(thisJetRef->momentum(),ipTagInfo[thisJetRef]->selectedTracks()[location3D]->momentum()) );
	      IP3dMomentum[iTrack][iJet] = (ipTagInfo[thisJetRef]->selectedTracks()[location3D]->p() );
	      IP3dTransverseMomentum[iTrack][iJet] = ( ipTagInfo[thisJetRef]->selectedTracks()[location3D]->pt() );
	      IP3dEta[iTrack][iJet] = ( ipTagInfo[thisJetRef]->selectedTracks()[location3D]->eta() );
	      IP3dPhi[iTrack][iJet] = ( ipTagInfo[thisJetRef]->selectedTracks()[location3D]->phi() );
	      IP3dNHits[iTrack][iJet] = ( ipTagInfo[thisJetRef]->selectedTracks()[location3D]->hitPattern().numberOfValidHits() ); 
	      IP3dNPixelHits[iTrack][iJet] = ( ipTagInfo[thisJetRef]->selectedTracks()[location3D]->hitPattern().numberOfValidPixelHits() ); 
	      IP3dNormChi2[iTrack][iJet] = (  ipTagInfo[thisJetRef]->selectedTracks()[location3D]->normalizedChi2() );
	    }
	  else
	    {
	      IP3dHasSharedPix1[iTrack][iJet] = (-1);
	      IP3dHasSharedPix2[iTrack][iJet] = (-1);
	      IP3dHasSharedPix3[iTrack][iJet] = (-1);
	      IP3dHasSharedPixAll[iTrack][iJet] = (-1);

	      IP3dTrackQuality[iTrack][iJet] = (-100);
	      IP3d[iTrack][iJet] = (-100.0);
	      IP3dError[iTrack][iJet] = (-1.0);
	      IP3dProbability[iTrack][iJet] = (-1.0);
	      IP3dTrackPtRel[iTrack][iJet] = (-1.0);
	      IP3dDistJetAxis[iTrack][iJet] = (-100);
	      IP3dDecayLength[iTrack][iJet] = (-100);
	      IP3dDeltaR[iTrack][iJet] = (-100);
	      IP3dMomentum[iTrack][iJet] = (-100);
	      IP3dTransverseMomentum[iTrack][iJet] = (-100);
	      IP3dEta[iTrack][iJet] = (-100);
	      IP3dPhi[iTrack][iJet] = (-100);
	      IP3dNHits[iTrack][iJet] = ( -100);
	      IP3dNPixelHits[iTrack][iJet] = (-100);
	      IP3dNormChi2[iTrack][iJet] = ( -100 );
	    }
	  if(iTrack <  ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP3DSig).size())
	    {
	      size_t location2D = ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP2DSig)[iTrack];
	      for(int i = 2; i>-2; i--){
		if(ipTagInfo[thisJetRef]->selectedTracks()[location2D]->quality(reco::TrackBase::TrackQuality(i))){
		  IP2dTrackQuality[iTrack][iJet] = (i);
		  break;
		}
	      }
	      IP2d[iTrack][iJet] = (ipTagInfo[thisJetRef]->impactParameterData()[location2D].ip2d.value());
	      IP2dError[iTrack][iJet] = (ipTagInfo[thisJetRef]->impactParameterData()[location2D].ip2d.error());
	      IP2dProbability[iTrack][iJet] = (ipTagInfo[thisJetRef]->probabilities(1)[location2D]);
	      const math::XYZVector thisTrack(ipTagInfo[thisJetRef]->selectedTracks()[location2D]->px(),
					      ipTagInfo[thisJetRef]->selectedTracks()[location2D]->py(),
					      ipTagInfo[thisJetRef]->selectedTracks()[location2D]->pz());
	      IP2dTrackPtRel[iTrack][iJet] = ( Perp(thisTrack,axis ) );

	    }
	  else
	    {
	      IP2dTrackQuality[iTrack][iJet] = (-100);
	      IP2d[iTrack][iJet] = (-100.0);
	      IP2dError[iTrack][iJet] = (-1.0);
	      IP2dProbability[iTrack][iJet] = (-1.0);
	      IP2dTrackPtRel[iTrack][iJet] = (-1.0);
	    }
	} 
      

      //softElectronTagInfos

      for(unsigned int i=0; i<4; i++){
	nElectrons[iJet] = ( 0 );
	electronPt[i][iJet] = (-9999 );   			       
	electronEta[i][iJet] = (-9999);  			       
	electronPhi[i][iJet] = (-9999);  			       
	electronNHits[i][iJet] = (-9999 );   
	electronNExpectedOuterHits[i][iJet] = ( -9999 );
	electronNPixelHits[i][iJet] = (-9999 );   
	electronNChi2[i][iJet] = (-9999);			       
	electronPtRel[i][iJet] = (-9999);   
	electronTrackQuality[i][iJet] = (-9999 );
	electronSip2d[i][iJet] = (-9999);   
	electronIp2d[i][iJet] = (-9999 );   
	electronIpe2d[i][iJet] = ( -9999 );   		       
	electronSip3d[i][iJet] = (-9999);   
	electronIp3d[i][iJet] = (-9999 );   
	electronIpe3d[i][iJet] = ( -9999 );   
	electronP0Par[i][iJet] = (-9999);   		       
	electronDeltaR[i][iJet] = (-9999);  		       
	electronEtaRel[i][iJet] = (-9999);  		       
	electronRatio[i][iJet] = (-9999);   		       
	electronRatioRel[i][iJet] = (-9999);
	electroneSuperClusterOverP[i][iJet] = (-9999);
	electroneSeedClusterOverP[i][iJet] = (-9999);
	electroneSeedClusterOverPout[i][iJet] = (-9999);
	electroneEleClusterOverPout[i][iJet] = (-9999);
	electrondeltaEtaSuperClusterTrackAtVtx[i][iJet] = (-9999);
	electrondeltaEtaSeedClusterTrackAtCalo[i][iJet] = (-9999);
	electrondeltaEtaEleClusterTrackAtCalo[i][iJet] = (-9999);
	electrondeltaPhiSuperClusterTrackAtVtx[i][iJet] = (-9999);
	electrondeltaPhiSeedClusterTrackAtCalo[i][iJet] = (-9999);
	electrondeltaPhiEleClusterTrackAtCalo[i][iJet] = (-9999);
      } 

      bool hasLeptons = softElectronTagInfo[thisJetRef]->leptons() > 0;
      if(hasLeptons)
	{
	  nElectrons[iJet] = (softElectronTagInfo[thisJetRef]->leptons());


	  edm::Handle<reco::GsfElectronCollection> allelectrons;
	  iEvent.getByLabel("gsfElectrons",allelectrons);
	  // loop over all electrons in tag info and match them to gsfelectron collection 
	  // create pt sorted map of electrons
	  std::map<double, const GsfElectron*> elMap;
	  std::map<const GsfElectron*, unsigned int> tagInfoMap;

	  for(unsigned int iElectron = 0; iElectron < softElectronTagInfo[thisJetRef]->leptons(); iElectron++)
	    {
	      //loop on electron collection
	      //count electrons
	      unsigned int iElCounter = 0;
	      for(size_t i=0; i < allelectrons->size(); ++i){
		const GsfElectron & el = (*allelectrons)[i];
		GsfTrackRef gsftrack = el.gsfTrack();
 		if(gsftrack.isNull() && !gsftrack.isAvailable()){
 		  std::cout<<"track is null"<<std::endl;
 		  continue;
 		}
 		reco::GsfTrackRef softLepTrack =  (softElectronTagInfo[thisJetRef]->lepton(iElectron)).castTo<GsfTrackRef>();
		if( gsftrack == softLepTrack){
 		  iElCounter++;
		  elMap[gsftrack->pt()] = &el ;
		  tagInfoMap[&el] = iElectron;
		}
	      }
		
	      if(iElCounter != 1){
		std::cout<<"ERROR: iElCounter= "<<iElCounter<<"this should never happen" << std::endl;
		exit(1);
	      }	      
	    }

	
	  if( elMap.size() != softElectronTagInfo[thisJetRef]->leptons()){
	    std::cout<<"ERROR: softElectronTagInfo[thisJetRef]->leptons():  this should never happen"<< std::endl;
	    exit(1);
	  }

	  // now loop over el map and fill info
	  int iElMapCounter = 0;
	  for(std::map<double, const GsfElectron*>::reverse_iterator it= elMap.rbegin(); it != elMap.rend(); it++){

	    const GsfElectron * el =  it->second;

	    electronPt[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])->pt());   			       
	    electronEta[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])->eta());  			       
	    electronPhi[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])->phi());  			       
	    electronNHits[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])->hitPattern().numberOfValidHits() );   
	    electronNExpectedOuterHits[iElMapCounter][iJet] = ( softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])->trackerExpectedHitsOuter().numberOfHits() );   
	    electronNPixelHits[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])->hitPattern().numberOfValidPixelHits() );   
	    electronNChi2[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])->normalizedChi2());			       
	    electronPtRel[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).ptRel);   
	      
	    TransientTrack transientTrack = builder->build( *softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el]) );
	    GlobalVector direction(thisJetRef->momentum().x(), thisJetRef->momentum().y(), thisJetRef->momentum().z());
	    Measurement1D ip3d = IPTools::signedImpactParameter3D(transientTrack, direction, *pv).second;
	    Measurement1D ip2d = IPTools::signedTransverseImpactParameter(transientTrack, direction, *pv).second;

	    electronSip2d[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).sip2d);   
	    electronIp2d[iElMapCounter][iJet] = ( ip2d.value() );   
	    electronIpe2d[iElMapCounter][iJet] = ( ip2d.error() );   		       
	    electronSip3d[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).sip3d);   
	    electronIp3d[iElMapCounter][iJet] = ( ip3d.value() );   
	    electronIpe3d[iElMapCounter][iJet] = ( ip3d.error() );   
	    electronP0Par[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).p0Par);   		       
	    electronDeltaR[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).deltaR);  		       
	    electronEtaRel[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).etaRel);  		       
	    electronRatio[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).ratio);   		       
	    electronRatioRel[iElMapCounter][iJet] = (softElectronTagInfo[thisJetRef]->properties(tagInfoMap[el]).ratioRel);

	    electroneSuperClusterOverP[iElMapCounter][iJet] = el->eSuperClusterOverP();
	    electroneSeedClusterOverP[iElMapCounter][iJet] = el->eSeedClusterOverP();
	    electroneSeedClusterOverPout[iElMapCounter][iJet] = el->eSeedClusterOverPout();
	    electroneEleClusterOverPout[iElMapCounter][iJet] = el->eEleClusterOverPout();
	    electrondeltaEtaSuperClusterTrackAtVtx[iElMapCounter][iJet] = el->deltaEtaSuperClusterTrackAtVtx();
	    electrondeltaEtaSeedClusterTrackAtCalo[iElMapCounter][iJet] = el->deltaEtaSeedClusterTrackAtCalo();
	    electrondeltaEtaEleClusterTrackAtCalo[iElMapCounter][iJet] = el->deltaEtaEleClusterTrackAtCalo();
	    electrondeltaPhiSuperClusterTrackAtVtx[iElMapCounter][iJet] = el->deltaPhiSuperClusterTrackAtVtx();
	    electrondeltaPhiSeedClusterTrackAtCalo[iElMapCounter][iJet] = el->deltaPhiSeedClusterTrackAtCalo();
	    electrondeltaPhiEleClusterTrackAtCalo[iElMapCounter][iJet] = el->deltaPhiEleClusterTrackAtCalo();

	    for(int i = 2; i>-2; i--){
	      if( (*softElectronTagInfo[thisJetRef]->lepton(tagInfoMap[el])).quality(reco::TrackBase::TrackQuality(i))){
		electronTrackQuality[iElMapCounter][iJet] = (i);
		break;
	      }
	    }
	  }
	}
	
      
      //softMuonTagInfos
      for(unsigned int i=0; i<4; i++){
	nMuons[iJet] = 0;
	muonIsGlobal[i][iJet] = 0;             
	muonIsTracker[i][iJet] = 0;            
	muonIsStandalone[i][iJet] = 0;         
	muonPt[i][iJet] = -999;                        
	muonEta[i][iJet] = -999;                       
	muonPhi[i][iJet] = -999;                  
	muonNumberOfMatches[i][iJet] = -999;      
	muonGlobalMuonHits[i][iJet] = -999;       
	muonInnerValidHits[i][iJet] = -999;       
	muonNExpectedOuterHits[i][iJet] = -999;   
	muonNPixelHits[i][iJet] = -999;           
	muonInnerNChi2[i][iJet] = -999;           
	muonGlobalNChi2[i][iJet] = -999;          
	muonVzPVDist[i][iJet] = -999;             
	muonPtRel[i][iJet] = -999;                
	muonSip2d[i][iJet] = -999;                
	muonIp2d[i][iJet] = -999;                 
	muonIpe2d[i][iJet] = -999;                
	muonSip3d[i][iJet] = -999;                
	muonIp3d[i][iJet] = -999;                 
	muonIpe3d[i][iJet] = -999;                
	muonP0Par[i][iJet] = -999;                     
	muonDeltaR[i][iJet] = -999;                    
	muonEtaRel[i][iJet] = -999;                    
	muonRatio[i][iJet] = -999;                     
	muonTrackQuality[i][iJet] = -999;              
	muonRatioRel[i][iJet] = -999;             

      }

      hasLeptons = softMuonTagInfo[thisJetRef]->leptons() > 0;
      if(hasLeptons)
	{
	  nMuons[iJet] = (softMuonTagInfo[thisJetRef]->leptons());
	      
	  edm::Handle<reco::MuonCollection> allmuons;
	  iEvent.getByLabel("muons",allmuons);
	  // loop over all muons in tag info and match them to muon collection 
	  // create pt sorted map of muons
	  std::map<double, const Muon*> muMap;
	  std::map<const Muon*, unsigned int> tagInfoMap;

	  for(unsigned int iMuon = 0; iMuon < softMuonTagInfo[thisJetRef]->leptons(); iMuon++)
	    {
	      //loop on muon collection
	      //count muons
	      unsigned int iMuCounter = 0;
	      for(size_t i=0; i < allmuons->size(); ++i){
		const Muon & mu = (*allmuons)[i];
		TrackRef globTrack = mu.globalTrack();
		TrackRef softLepTrackRef =  (softMuonTagInfo[thisJetRef]->lepton(iMuon)).castTo<TrackRef>();
		if( globTrack == softLepTrackRef ){   // found a matched muon
		  iMuCounter++;
		  muMap[mu.globalTrack()->pt()] = &mu ;
		  tagInfoMap[&mu] = iMuon;
		}
		    
	      }
	      if(iMuCounter != 1){
		std::cout<<"ERROR: iMuCounter != 1 this should never happen" << std::endl;
		exit(1);
	      }
	    }

	  if( muMap.size() != softMuonTagInfo[thisJetRef]->leptons()){
	    std::cout<<"ERROR: softMuonTagInfo[thisJetRef]->leptons():  this should never happen"<< std::endl;
	    exit(1);
	  }

	  // now loop over mu map and fill info
	  int iMuMapCounter = 0;
	  for(std::map<double, const Muon*>::reverse_iterator it= muMap.rbegin(); it != muMap.rend(); it++){

	    const Muon * mu =  it->second;

	    muonIsGlobal[iMuMapCounter][iJet] =  mu->isGlobalMuon();                
	    muonIsTracker[iMuMapCounter][iJet] =  mu->isTrackerMuon();
	    muonIsStandalone[iMuMapCounter][iJet] =  mu->isStandAloneMuon();
	    muonPt[iMuMapCounter][iJet] = softMuonTagInfo[thisJetRef]->lepton(tagInfoMap[mu])->pt(); 
	    muonEta[iMuMapCounter][iJet] = softMuonTagInfo[thisJetRef]->lepton(tagInfoMap[mu])->eta(); 
	    muonPhi[iMuMapCounter][iJet] = softMuonTagInfo[thisJetRef]->lepton(tagInfoMap[mu])->phi(); 
	    muonNumberOfMatches[iMuMapCounter][iJet] =  mu->numberOfMatches();
	    muonGlobalMuonHits[iMuMapCounter][iJet] = mu->globalTrack()->hitPattern().numberOfValidMuonHits();
	    muonInnerValidHits[iMuMapCounter][iJet] = mu->innerTrack()->numberOfValidHits();        
	    muonNExpectedOuterHits[iMuMapCounter][iJet] = mu->innerTrack()->trackerExpectedHitsOuter().numberOfHits();
	    muonNPixelHits[iMuMapCounter][iJet] = mu->innerTrack()->hitPattern().numberOfValidPixelHits();
	    muonInnerNChi2[iMuMapCounter][iJet] = mu->innerTrack()->normalizedChi2();    
	    muonGlobalNChi2[iMuMapCounter][iJet] = mu->globalTrack()->normalizedChi2();
	    muonVzPVDist[iMuMapCounter][iJet] = mu->vz() - pv->z();
	    muonPtRel[iMuMapCounter][iJet] = softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).ptRel;

	    TransientTrack transientTrack = builder->build( *softMuonTagInfo[thisJetRef]->lepton(tagInfoMap[mu]) );
	    GlobalVector direction(thisJetRef->momentum().x(), thisJetRef->momentum().y(), thisJetRef->momentum().z());
	    Measurement1D ip3d = IPTools::signedImpactParameter3D(transientTrack, direction, *pv).second;
	    Measurement1D ip2d = IPTools::signedTransverseImpactParameter(transientTrack, direction, *pv).second;  	
		
		
	    muonSip2d[iMuMapCounter][iJet] = softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).sip2d;
	    muonIp2d[iMuMapCounter][iJet] = ip2d.value();
	    muonIpe2d[iMuMapCounter][iJet] = ip2d.error();   
	    muonSip3d[iMuMapCounter][iJet] = softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).sip3d;
	    muonIp3d[iMuMapCounter][iJet] = ip3d.value();
	    muonIpe3d[iMuMapCounter][iJet] = ip3d.error();   
	    muonP0Par[iMuMapCounter][iJet] =        (softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).p0Par);
	    muonDeltaR[iMuMapCounter][iJet] =       (softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).deltaR); 
	    muonEtaRel[iMuMapCounter][iJet] =       (softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).etaRel); 
	    muonRatio[iMuMapCounter][iJet] =        (softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).ratio);
	    muonRatioRel[iMuMapCounter][iJet] =  (softMuonTagInfo[thisJetRef]->properties(tagInfoMap[mu]).ratioRel);  
		
		
	    for(int i = 2; i>-2; i--){
	      if( (*softMuonTagInfo[thisJetRef]->lepton(tagInfoMap[mu])).quality(reco::TrackBase::TrackQuality(i))){
		muonTrackQuality[iMuMapCounter][iJet] = (i);
		break;
	      }
	    }
	    iMuMapCounter++;
	    if(iMuMapCounter>=4) break;
	  }
	}

       

      
      for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
	{
	  bTagArrays[ibTag->getParameter<string>("alias")][iJet] = ((bTags[ibTag->getParameter<string>("alias")])[thisJetRef]);
	}
    } // end loop over jets
  
  nTracks = iTotalTracksCounter;

  // fill the tree
  tree->Fill();  

}

// ------------ method called once each job just before starting event loop  ------------
void TagNtupleProducer::beginJob()
{
}

//added by Caroline for prescale
// ------------ method called at the beginning of the run  ------------
void TagNtupleProducer::beginRun(const Run& r, const EventSetup& iSet)
{
     // passed as parameter to HLTConfigProvider::init(), not yet used
      bool isConfigChanged = false;
      // isValidHltConfig_ used to short-circuit analyze() in case of problems
      isValidHltConfig_ = hltConfigProvider_.init( r, iSet, "HLT", isConfigChanged );

     if (isValidHltConfig_) {
      // if init returns TRUE, initialisation has succeeded!
      if (isConfigChanged) {
       // The HLT config has actually changed wrt the previous Run, hence rebook your
      // histograms or do anything else dependent on the revised HLT config
      std::cout << "Initalizing HLTConfigProvider"  << std::endl;
      }
     } else {
      // if init returns FALSE, initialisation has NOT succeeded, which indicates a problem
      // with the file and/or code and needs to be investigated!
      std::cout << " HLT config extraction failure with process name HLT "  << std::endl;
      // In this case, all access methods will return empty values!
     }


}


// ------------ method called at the end of the run  ------------
void TagNtupleProducer::endRun(const Run& r, const EventSetup& iSet)
{
}

// end add

// ------------ method called once each job just after ending the event loop  ------------
void TagNtupleProducer::endJob() {

  file ->Write();
  file->Close();
}


void TagNtupleProducer::getSharedHitsInfo(unsigned int layer, const reco::TrackRefVector & tracks, int &nSharedHits, int &nTotalHits){

  nSharedHits=0;
  nTotalHits=0;

  //iterate over tracks
  for(track_iterator itTrack = tracks.begin(); itTrack!=tracks.end(); itTrack++){
    //iterate over hits of this track
    for(trackingRecHit_iterator hitIt = (*itTrack)->recHitsBegin(); hitIt != (*itTrack)->recHitsEnd(); hitIt++  ){
      if( !(*hitIt)->isValid() ) continue;
      DetId detid = (*hitIt)->geographicalId();
      unsigned int subdet = detid.subdetId();

      unsigned int thislayer = -1;
      if(subdet==PixelSubdetector::PixelBarrel){//PXB
	PXBDetId pxbdet=(detid);
	thislayer=pxbdet.layer();

      }
      else if(subdet==PixelSubdetector::PixelEndcap){
	PXFDetId pxfdet(detid);
	thislayer=pxfdet.disk();
      }

      // if they are on the desired layer
      if(layer == thislayer){
	nTotalHits++;
	//iterate over all other tracks avoiding double counting
	track_iterator itTrack2 = itTrack;
	itTrack2++;
	if(itTrack2 == tracks.end()) continue;
	for(; itTrack2!=tracks.end(); itTrack2++){
	  // iterate again over hits
	  for(trackingRecHit_iterator hitIt2 = (*itTrack2)->recHitsBegin(); hitIt2 != (*itTrack2)->recHitsEnd(); hitIt2++  ){
	    if( !(*hitIt2)->isValid() ) continue;
	    DetId detid2 = (*hitIt2)->geographicalId();
	    if( detid.rawId() == detid2.rawId()  ){
	      // check identity via
	      if( (*hitIt)->sharesInput( &(**hitIt2), TrackingRecHit::some )) nSharedHits++; 
	    }
	  }
	}
      }
    }
  }
}


int TagNtupleProducer::hasSharedHit(unsigned int layer, size_t location, const reco::TrackRefVector & tracks){

  int bFoundHit=0;

  //iterate over hits of this track 
  for(trackingRecHit_iterator hitIt = tracks[location]->recHitsBegin(); hitIt != tracks[location]->recHitsEnd(); hitIt++  ){
    if( !(*hitIt)->isValid() ) continue;
   

    DetId detid = (*hitIt)->geographicalId();
    unsigned int subdet = detid.subdetId();
    
    unsigned int thislayer = -1;
    if(subdet==PixelSubdetector::PixelBarrel){//PXB
      PXBDetId pxbdet=(detid);
      thislayer=pxbdet.layer();
      
    }
    else if(subdet==PixelSubdetector::PixelEndcap){
      PXFDetId pxfdet(detid);
      thislayer=pxfdet.disk();
    }
    
    // if they are on the desired layer
    if(layer == thislayer){
      //iterate over all other tracks avoiding double counting
      size_t counter = 0;
       
      for(track_iterator itTrack2 = tracks.begin(); itTrack2!=tracks.end(); itTrack2++){
	if(counter==location){ counter++; continue;}  //avoid double counting track 
	// iterate again over hits
	for(trackingRecHit_iterator hitIt2 = (*itTrack2)->recHitsBegin(); hitIt2 != (*itTrack2)->recHitsEnd(); hitIt2++  ){
	  if( !(*hitIt2)->isValid() ) continue;
	  DetId detid2 = (*hitIt2)->geographicalId();
	  if( detid.rawId() == detid2.rawId()  ){
	    // check identity via
	    if( (*hitIt)->sharesInput( &(**hitIt2), TrackingRecHit::some )) bFoundHit=1; 
	  }
	}
	counter++;
      }
    }
  }

  return bFoundHit;
}


//define this as a plug-in
DEFINE_FWK_MODULE(TagNtupleProducer);
