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
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  void getSharedHitsInfo(unsigned int layer, const reco::TrackRefVector & tracks, int &nSharedHits, int &nTotalHits);
  int  hasSharedHit(unsigned int layer, size_t location, const reco::TrackRefVector & tracks);      
  // ----------member data ---------------------------
  
  bool getMCTruth_;
  
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
  std::vector< edm::ParameterSet > bTag_Config_;
  std::string label_;
  
  // data formats
  TTree *tree;
  TFile *file;
  
  bool triggerHLTL1Jet6U, triggerHLTL1Jet10U, triggerHLTJet15U;
  bool triggerHLTJet30U, triggerHLTJet50U, triggerHLTJet70U, triggerHLTJet100U ;
  bool triggerHLTBTagIPJet50U, triggerHLTBTagMuJet10U, triggerHLTBTagMuJet20U;
  bool triggerHLTBTagMuDiJet10U, triggerHLTBTagMuDiJet20U, triggerHLTBTagMuDiJet20UMu5;

  unsigned int eventNumber ;
  unsigned int runNumber ;
  unsigned int lumiBlockNumber ;

  unsigned int numberOfPrimaryVertices ;
  unsigned int numberOfTracksAtPV;
  float PVx;
  float PVy;
  float PVz;
  float PVNormalizedChi2;

  float pthat;
  bool isGluonSplitting;

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
  float electronPt[MAXJETS];   			       
  float electronEta[MAXJETS];  			       
  float electronPhi[MAXJETS];  			       
  int electronNHits[MAXJETS];   		     
  int electronNExpectedOuterHits[MAXJETS];   		       
  int electronNPixelHits[MAXJETS];   		       
  float electronNChi2[MAXJETS];			       
  float electronPtRel[MAXJETS];   		       
  float electronSip2d[MAXJETS];   		       
  float electronIp2d[MAXJETS];   		       
  float electronIpe2d[MAXJETS];   		       
  float electronSip3d[MAXJETS];
  float electronIp3d[MAXJETS];
  float electronIpe3d[MAXJETS];   		          		          		       
  float electronP0Par[MAXJETS];   		       
  float electronDeltaR[MAXJETS];  		       
  float electronEtaRel[MAXJETS];  		       
  float electronRatio[MAXJETS];   		     
  int electronTrackQuality[MAXJETS];   		       
  float electronRatioRel[MAXJETS];                      
						       
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

TagNtupleProducer::TagNtupleProducer(const edm::ParameterSet& iConfig)
{
  string alias;
  getMCTruth_     = iConfig.getParameter<bool>( "getMCTruth" );
  
  jet_src_        = iConfig.getParameter<edm::InputTag>( "jetSrc" );
  SVComputer_     = iConfig.getParameter<edm::InputTag>( "svComputer");
  triggerTag_ = iConfig.getParameter<edm::InputTag>("TriggerTag");
  jet_MC_src_     = iConfig.getParameter<edm::InputTag>( "jetMCSrc" );
  jet_tracks_     = iConfig.getParameter<edm::InputTag>( "jetTracks" ); 
  primaryVertexProducer_   = iConfig.getParameter<InputTag>("primaryVertex"); 
  SV_tag_infos_   = iConfig.getParameter<edm::InputTag>( "SVTagInfos" );
  IP_tag_infos_   = iConfig.getParameter<edm::InputTag>( "IPTagInfos" );
  
  electron_tag_infos_ = iConfig.getParameter<edm::InputTag>( "ElectronTagInfos" );
  muon_tag_infos_ = iConfig.getParameter<edm::InputTag>( "MuonTagInfos" );
  label_ = iConfig.getParameter<string>( "Label" );

  std::string filename = iConfig.getParameter<string>( "filename" );
  
  //b tagger outputs configured in python file
  bTag_Config_ = iConfig.getParameter< vector<edm::ParameterSet> >("bTagConfig");
  
  file = new TFile (filename.c_str(), "RECREATE" );
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
  
  muonIsGlobal.push_back(muon1IsGlobal); 
  muonIsGlobal.push_back(muon2IsGlobal);
  
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


  tree->Branch(  "eventNumber"             , &eventNumber             , "eventNumber/i"            );
  tree->Branch(  "runNumber"		    , &runNumber               , "runNumber/i"   	    );
  tree->Branch(  "lumiBlockNumber" 	    , &lumiBlockNumber         , "lumiBlockNumber/i" 	    );
  tree->Branch(  "numberOfPrimaryVertices" , &numberOfPrimaryVertices , "numberOfPrimaryVertices/i"); 
  tree->Branch(  "numberOfTracksAtPV" , &numberOfTracksAtPV , "numberOfTracksAtPV/i"); 
  tree->Branch(  "PVx" , &PVx , "PVx/F"); 
  tree->Branch(  "PVy" , &PVy , "PVy/F"); 
  tree->Branch(  "PVz" , &PVz , "PVz/F"); 
  tree->Branch(  "PVNormalizedChi2" , &PVNormalizedChi2 , "PVNormalizedChi2/F"); 

  tree->Branch(  "pthat" , &pthat, "pthat/F");
  tree->Branch(  "isGluonSplitting" , &isGluonSplitting, "isGluonSplitting/O");

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
  tree->Branch(  "electronPt",  electronPt, "electronPt[nJets]/F");   			       
  tree->Branch(  "electronEta", electronEta, "electronEta[nJets]/F");  			       
  tree->Branch(  "electronPhi",  electronPhi, "electronPhi[nJets]/F");  			       
  tree->Branch(  "electronNHits", electronNHits, "electronNHits[nJets]/I");   		     
  tree->Branch(  "electronNExpectedOuterHits", electronNExpectedOuterHits, "electronNExpectedOuterHits[nJets]/I");   		       
  tree->Branch(  "electronNPixelHits",  electronNPixelHits, "electronNPixelHits[nJets]/I");   		       
  tree->Branch(  "electronNChi2", electronNChi2, "electronNChi2[nJets]/F");			       
  tree->Branch(  "electronPtRel", electronPtRel, "electronPtRel[nJets]/F");   		       
  tree->Branch(  "electronSip2d", electronSip2d, "electronSip2d[nJets]/F");   		       
  tree->Branch(  "electronIp2d", electronIp2d, "electronIp2d[nJets]/F");   		       
  tree->Branch(  "electronIpe2d", electronIpe2d, "electronIpe2d[nJets]/F");   		       
  tree->Branch(  "electronSip3d", electronSip3d, "electronSip3d[nJets]/F");
  tree->Branch(  "electronIp3d", electronIp3d, "electronIp3d[nJets]/F");
  tree->Branch(  "electronIpe3d", electronIpe3d, "electronIpe3d[nJets]/F");   		          		          		       
  tree->Branch(  "electronP0Par", electronP0Par, "electronP0Par[nJets]/F");   		       
  tree->Branch(  "electronDeltaR", electronDeltaR, "electronDeltaR[nJets]/F");  		       
  tree->Branch(  "electronEtaRel", electronEtaRel, "electronEtaRel[nJets]/F");  		       
  tree->Branch(  "electronRatio", electronRatio, "electronRatio[nJets]/F");   		     
  tree->Branch(  "electronTrackQuality", electronTrackQuality, "electronTrackQuality[nJets]/I");   		       
  tree->Branch(  "electronRatioRel", electronRatioRel, "electronRatioRel[nJets]/F");                      
  
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
  triggerHLTBTagMuDiJet10U = triggerHLTBTagMuDiJet20U = triggerHLTBTagMuDiJet20UMu5 = 0;

  //Get The Various collections defined in the configuration file
  edm::Handle<edm::TriggerResults>  hltresults;
  iEvent.getByLabel(triggerTag_, hltresults);
  
  const edm::TriggerNames & triggerNames_ = iEvent.triggerNames(*hltresults);  

  int ntrigs = hltresults->size();


  for (int itrig = 0; itrig != ntrigs; ++itrig){
    string trigName=triggerNames_.triggerName(itrig);
    if (trigName=="HLT_L1Jet6U")               triggerHLTL1Jet6U  = hltresults->accept(itrig) ;
    if (trigName=="HLT_L1Jet10U")              triggerHLTL1Jet10U = hltresults->accept(itrig) ; 
    if (trigName=="HLT_Jet15U")                triggerHLTJet15U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet30U")                triggerHLTJet30U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet50U")                triggerHLTJet50U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet70U")                triggerHLTJet70U   = hltresults->accept(itrig) ;
    if (trigName=="HLT_Jet100U")               triggerHLTJet100U   = hltresults->accept(itrig) ; 
    if (trigName=="HLT_BTagIP_Jet50U")         triggerHLTBTagIPJet50U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_Jet10U")         triggerHLTBTagMuJet10U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_Jet20U")         triggerHLTBTagMuJet20U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_DiJet10U")       triggerHLTBTagMuDiJet10U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_DiJet20U")       triggerHLTBTagMuDiJet20U = hltresults->accept(itrig) ;
    if (trigName=="HLT_BTagMu_DiJet20U_Mu5")   triggerHLTBTagMuDiJet20UMu5 = hltresults->accept(itrig) ;
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

  numberOfPrimaryVertices = primaryVertex->size();

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
  isGluonSplitting = 0;
  if(getMCTruth_) {
    bool bFoundS3BQuark = false;
    bool bFoundS2BQuark = false;
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
    }
    // if no status 3 b quark but status 2
    if( (!bFoundS3BQuark) && bFoundS2BQuark  ) isGluonSplitting  = 1;
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
	  int tsharedP1, tsharedP2, tsharedP3;
	  trackHasSharedPix1[iTotalTracksCounter] = ( tsharedP1 = hasSharedHit(1, counter, (*jetTracks)[thisJetRef]));
	  trackHasSharedPix2[iTotalTracksCounter] = ( tsharedP2 = hasSharedHit(2, counter, (*jetTracks)[thisJetRef]));
	  trackHasSharedPix3[iTotalTracksCounter] = ( tsharedP3 = hasSharedHit(3, counter, (*jetTracks)[thisJetRef]));
	  trackHasSharedPixAll[iTotalTracksCounter] = ( tsharedP1 || tsharedP2 || tsharedP3 );
	  
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
		  
	    } else {
	      vertexKinematics.add(**track, w);
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
	      int sharedP1, sharedP2, sharedP3;
	      IP3dHasSharedPix1[iTrack][iJet] = (sharedP1=hasSharedHit(1, location3D,  ipTagInfo[thisJetRef]->selectedTracks()));
	      IP3dHasSharedPix2[iTrack][iJet] = (sharedP2=hasSharedHit(2, location3D,  ipTagInfo[thisJetRef]->selectedTracks()));
	      IP3dHasSharedPix3[iTrack][iJet] = (sharedP3=hasSharedHit(3, location3D,  ipTagInfo[thisJetRef]->selectedTracks()));
	      IP3dHasSharedPixAll[iTrack][iJet] = ( sharedP1 || sharedP2 || sharedP3  );

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
  
      bool hasLeptons = softElectronTagInfo[thisJetRef]->leptons() > 0;
      if(hasLeptons)
	{
	  nElectrons[iJet] = (softElectronTagInfo[thisJetRef]->leptons());
	  unsigned int maxPtElectron = 0;
	  for(unsigned int iElectron = 0; iElectron < softElectronTagInfo[thisJetRef]->leptons(); iElectron++)
	    {
	      if(softElectronTagInfo[thisJetRef]->lepton(iElectron)->pt() > softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->pt() )
		maxPtElectron = iElectron;
	    }
	  electronPt[iJet] = (softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->pt());   			       
	  electronEta[iJet] = (softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->eta());  			       
	  electronPhi[iJet] = (softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->phi());  			       
	  electronNHits[iJet] = (softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->hitPattern().numberOfValidHits() );   
	  electronNExpectedOuterHits[iJet] = ( softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->trackerExpectedHitsOuter().numberOfHits() );   
	  electronNPixelHits[iJet] = (softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->hitPattern().numberOfValidPixelHits() );   
	  electronNChi2[iJet] = (softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->normalizedChi2());			       
	  electronPtRel[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).ptRel);   
	      
	  for(int i = 2; i>-2; i--){
	    if( (*softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)).quality(reco::TrackBase::TrackQuality(i))){
	      electronTrackQuality[iJet] = (i);
	      break;
	    }
	  }

	  TransientTrack transientTrack = builder->build( *softElectronTagInfo[thisJetRef]->lepton(maxPtElectron) );
	  GlobalVector direction(thisJetRef->momentum().x(), thisJetRef->momentum().y(), thisJetRef->momentum().z());
	  Measurement1D ip3d = IPTools::signedImpactParameter3D(transientTrack, direction, *pv).second;
	  Measurement1D ip2d = IPTools::signedTransverseImpactParameter(transientTrack, direction, *pv).second;
		       
	  electronSip2d[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).sip2d);   
	  electronIp2d[iJet] = ( ip2d.value() );   
	  electronIpe2d[iJet] = ( ip2d.error() );   		       
   

	  electronSip3d[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).sip3d);   
	  electronIp3d[iJet] = ( ip3d.value() );   
	  electronIpe3d[iJet] = ( ip3d.error() );   
	   

	  electronP0Par[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).p0Par);   		       
	  electronDeltaR[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).deltaR);  		       
	  electronEtaRel[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).etaRel);  		       
	  electronRatio[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).ratio);   		       
	  electronRatioRel[iJet] = (softElectronTagInfo[thisJetRef]->properties(maxPtElectron).ratioRel);                      
	}
      else{
	nElectrons[iJet] = ( 0 );
	electronPt[iJet] = (-9999 );   			       
	electronEta[iJet] = (-9999);  			       
	electronPhi[iJet] = (-9999);  			       
	electronNHits[iJet] = (-9999 );   
	electronNExpectedOuterHits[iJet] = ( -9999 );
	electronNPixelHits[iJet] = (-9999 );   
	electronNChi2[iJet] = (-9999);			       
	electronPtRel[iJet] = (-9999);   
	electronTrackQuality[iJet] = (-9999 );
	electronSip2d[iJet] = (-9999);   
	electronIp2d[iJet] = (-9999 );   
	electronIpe2d[iJet] = ( -9999 );   		       
	electronSip3d[iJet] = (-9999);   
	electronIp3d[iJet] = (-9999 );   
	electronIpe3d[iJet] = ( -9999 );   
	electronP0Par[iJet] = (-9999);   		       
	electronDeltaR[iJet] = (-9999);  		       
	electronEtaRel[iJet] = (-9999);  		       
	electronRatio[iJet] = (-9999);   		       
	electronRatioRel[iJet] = (-9999);  
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

	    muonIsGlobal[iMuMapCounter][iJet] =           mu->isGlobalMuon();                
	    muonIsTracker[iMuMapCounter][iJet] =                          mu->isTrackerMuon();
	    muonIsStandalone[iMuMapCounter][iJet] =                       mu->isStandAloneMuon();
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
