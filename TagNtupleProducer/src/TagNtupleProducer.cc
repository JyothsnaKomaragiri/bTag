// -*- C++ -*-
//
// Package:    TagNtupleProducer
// Class:      TagNtupleProducer
// 
/**\class TagNtupleProducer TagNtupleProducer.cc bTagAnalysis/TagNtupleProducer/src/TagNtupleProducer.cc

 Description: Creates a simple ntuple that stores b-tagging information

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Lucas Olen Winstrom,6 R-029,+41227678914,
//         Created:  Tue Mar 23 13:40:46 CET 2010
// $Id: TagNtupleProducer.cc,v 1.5 2010/04/15 23:16:07 winstrom Exp $
//
//


// system include files
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <sstream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

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

#include "DataFormats/Math/interface/deltaR.h"
#include "Math/GenVector/VectorUtil.h"

#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "SimDataFormats/JetMatching/interface/JetFlavour.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourMatching.h"

#include "DataFormats/TrackReco/interface/Track.h"

#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/IPTools/interface/IPTools.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"


//
// class declaration
//

class TagNtupleProducer : public edm::EDProducer {
   public:
      explicit TagNtupleProducer(const edm::ParameterSet&);
      ~TagNtupleProducer();

   private:
      virtual void beginJob() ;
      virtual void produce(edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      
      // ----------member data ---------------------------

      bool getMCTruth_;
      bool get_SV_tag_infos_;
      bool get_IP_tag_infos_;
      bool get_SE_tag_infos_;
      bool get_SM_tag_infos_;
      edm::InputTag jet_src_;
      edm::InputTag jet_MC_src_;
      edm::InputTag jet_tracks_;
      edm::InputTag primaryVertexProducer_;
      edm::InputTag SV_tag_infos_;
      edm::InputTag IP_tag_infos_;
      unsigned int IP_n_saved_tracks_;
      edm::InputTag electron_tag_infos_;
      edm::InputTag muon_tag_infos_;
      std::vector< edm::ParameterSet > bTag_Config_;
      std::string label_;
  
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
  get_SV_tag_infos_= iConfig.getParameter<bool>( "getSVTagInfo" );
  get_IP_tag_infos_= iConfig.getParameter<bool>( "getIPTagInfo" );
  get_SE_tag_infos_= iConfig.getParameter<bool>( "getSETagInfo" );
  get_SM_tag_infos_= iConfig.getParameter<bool>( "getSMTagInfo" );
  jet_src_        = iConfig.getParameter<edm::InputTag>( "jetSrc" );
  jet_MC_src_     = iConfig.getParameter<edm::InputTag>( "jetMCSrc" );
  jet_tracks_     = iConfig.getParameter<edm::InputTag>( "jetTracks" ); 
  primaryVertexProducer_   = iConfig.getParameter<InputTag>("primaryVertex"); 
  SV_tag_infos_   = iConfig.getParameter<edm::InputTag>( "SVTagInfos" );
  IP_tag_infos_   = iConfig.getParameter<edm::InputTag>( "IPTagInfos" );
  IP_n_saved_tracks_ = iConfig.getParameter<unsigned int>( "IPnSavedTracks" );
  electron_tag_infos_ = iConfig.getParameter<edm::InputTag>( "ElectronTagInfos" );
  muon_tag_infos_ = iConfig.getParameter<edm::InputTag>( "MuonTagInfos" );
  label_ = iConfig.getParameter<string>( "Label" );
  
  //Basic Jet Information
  produces<vector<math::XYZTLorentzVector> >( alias = label_ + "jetP4"                  ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetPt"                                    ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetEta"                                   ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetPhi"                                   ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetEMFraction"                            ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetChargedEmEnergyFraction"               ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetNeutralEmEnergyFraction"               ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetChargedHadronEnergyFraction"           ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetNeutralHadronEnergyFraction"           ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetChargedMultiplicity"                   ).setBranchAlias( alias );
  produces<vector<float> >( alias = label_ + "jetMass"                                  ).setBranchAlias( alias );
  produces<vector<int> >( alias = label_ + "jetnConstituents"                           ).setBranchAlias( alias ); 
  produces<vector<int> >( alias = label_ + "jetnTracks"                                 ).setBranchAlias( alias );  
  produces<vector<math::XYZVector> >(alias = label_ + "jetVertex"                       ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "jetVertexChi2"                             ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "jetVertexChi2Ndof"                         ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "jetVertexNormalizedChi2"                   ).setBranchAlias( alias );

  //Track Information
  produces<vector<int> >  (alias = label_ + "trackJetIndex"                   ).setBranchAlias( alias );
  produces<vector<bool> >  (alias = label_ + "trackSelected"                  ).setBranchAlias( alias );
  produces<vector<math::XYZVector> >( alias = label_ + "track3Momentum"                ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackTransverseMomentum"                 ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackMomentum"                   ).setBranchAlias( alias );
  produces<vector<int> >(alias = label_ + "trackNHits"                   ).setBranchAlias( alias );
  produces<vector<int> >(alias = label_ + "trackNPixelHits"                   ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackChi2"                   ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackNormChi2"                   ).setBranchAlias( alias );
  produces<vector<int> >(alias = label_ + "trackQuality"                   ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackLongitudinalImpactParameter"          ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackDecayLength"          ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackIP3d" ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackIP2d" ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackIP3dError" ).setBranchAlias( alias );
  produces<vector<float> >(alias = label_ + "trackIP2dError" ).setBranchAlias( alias );


  if(getMCTruth_)
    {
      //MC Truth Information
      produces<vector<float> >( alias = label_ + "MCTrueFlavor"                             ).setBranchAlias( alias ); 
    }

  if(get_SV_tag_infos_)
    {
      //secondaryVertexTagInfos:					               
      produces<vector<math::XYZVector> >( alias = label_ + "SecondaryVertex"                ).setBranchAlias( alias );  
      produces<vector<float> >( alias = label_ + "SV3dDistance"                             ).setBranchAlias( alias ); 
      produces<vector<float> >( alias = label_ + "SV3dDistanceError"                        ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SV2dDistance"                             ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SV2dDistanceError"                        ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SVChi2"                                   ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SVDegreesOfFreedom"                       ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SVNormChi2"                               ).setBranchAlias( alias );   
      produces<vector<int> >( alias = label_ + "SVnSelectedTracks"                                  ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SVMass"                                   ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SVMasspiHyp"                                   ).setBranchAlias( alias );   
      produces<vector<int> >( alias = label_ + "SVnVertices"                                ).setBranchAlias( alias );   
      produces<vector<int> >( alias = label_ + "SVnVertexTracks"                            ).setBranchAlias( alias ); 
      produces<vector<float> >( alias = label_ + "SVjetDeltaR"                            ).setBranchAlias( alias ); 
      produces<vector<float> >( alias = label_ + "SVjetAngle"                            ).setBranchAlias( alias ); 
      produces<vector<float> >( alias = label_ + "SVjetCosAngle"                            ).setBranchAlias( alias ); 
      produces<vector<float> >( alias = label_ + "SVdeltaCosAngle"                            ).setBranchAlias( alias );   
      produces<vector<float> >( alias = label_ + "SVdeltaAngle"                            ).setBranchAlias( alias );   
    } 
  if(get_IP_tag_infos_)
    {
      //impactParameterTagInfos
      produces<vector<int> >( alias = label_ + "IPnSelectedTracks"                          ).setBranchAlias( alias );  
      produces<vector<math::XYZVector> >( alias = label_ + "IPghostTrackP3"         ).setBranchAlias( alias );
      produces<vector<float> >( alias = label_ + "IPghostTrackPt"                           ).setBranchAlias( alias );
      produces<vector<float> >( alias = label_ + "IPghostTrackPtRel"                        ).setBranchAlias( alias );
      produces<vector<float> >( alias = label_ + "IPghostTrackEta"                          ).setBranchAlias( alias );
      produces<vector<float> >( alias = label_ + "IPghostTrackPhi"                          ).setBranchAlias( alias );
      produces<vector<float> >( alias = label_ + "IPghostTrackDeltaR"                       ).setBranchAlias( alias );
      for(unsigned int iTrack = 0; iTrack < IP_n_saved_tracks_; iTrack++)
	{
	  stringstream trackNum;
	  trackNum << (iTrack+1);
	  alias = label_ + "IP3dTrackQuality"+trackNum.str();
	  produces<vector<int> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP3d"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP3dError"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP3dProbability"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP3dTrackPtRel"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP2dTrackQuality"+trackNum.str();
	  produces<vector<int> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP2d"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP2dError"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP2dProbability"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	  alias = label_ + "IP2dTrackPtRel"+trackNum.str();
	  produces<vector<float> >( alias                    ).setBranchAlias( alias );
	}
    }
  if(get_SE_tag_infos_)
    {
      //softElectronTagInfos
      produces<vector<int> >(alias = label_ + "nElectrons"                                ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronPt"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronEta"  			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronPhi"  			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronNHits"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronNChi2"			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronPtRel"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronSip2d"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronSip3d"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronP0Par"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronDeltaR"  			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronEtaRel"  			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronRatio"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "electronRatioRel"                          ).setBranchAlias( alias );
    }
  if(get_SM_tag_infos_)
    {
      //softMuonTagInfos	
      produces<vector<int> >(alias = label_ + "nMuons"                                    ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonPt"   			               ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonEta"  			               ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonPhi"  			               ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonNHits"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonNChi2"	         		       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonPtRel"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonSip2d"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonSip3d"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonP0Par"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonDeltaR"  			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonEtaRel"  			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonRatio"   			       ).setBranchAlias( alias );
      produces<vector<float> >(alias = label_ + "muonRatioRel"                              ).setBranchAlias( alias );
    }
  //b tagger outputs configured in python file
  bTag_Config_ = iConfig.getParameter< vector<edm::ParameterSet> >("bTagConfig");
  for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
    {
      alias = ibTag->getParameter<string>("alias");
      produces<vector<float> >( alias ).setBranchAlias( alias ); 
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
void
TagNtupleProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
  
  //Get The Various collections defined in the configuration file
  
  Handle< View<Jet> > jets;
  iEvent.getByLabel(jet_src_,jets);

  Handle<JetTracksAssociation::Container > jetTracks;
  iEvent.getByLabel(jet_tracks_,jetTracks);

  Handle<reco::VertexCollection> primaryVertex;
  iEvent.getByLabel(primaryVertexProducer_, primaryVertex);

  edm::ESHandle<TransientTrackBuilder> builder;
  iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder", builder);

  //Get the TagInfo stuff and make is accesible with a map to a RefToBase<Jet>, since that's apparently what the JetTags use
  typedef RefToBase<Jet> JetRef;
  typedef map<JetRef, const SoftLeptonTagInfo*, JetRefCompare> slTagInfoMap;
  slTagInfoMap softElectronTagInfo;
  edm::Handle< View < reco::SoftLeptonTagInfo > > SoftElectronTagInfoVector;
  if(get_SE_tag_infos_)
    {
      iEvent.getByLabel(electron_tag_infos_,SoftElectronTagInfoVector);
      for(View< reco::SoftLeptonTagInfo >::const_iterator iTagInfo = SoftElectronTagInfoVector->begin(); iTagInfo != SoftElectronTagInfoVector->end(); iTagInfo++) 
	{
	  softElectronTagInfo[iTagInfo->jet()] = &*iTagInfo;
	}
    }

  slTagInfoMap softMuonTagInfo;
  edm::Handle< View < reco::SoftLeptonTagInfo > > SoftMuonTagInfoVector;
  if(get_SM_tag_infos_)
    {
      iEvent.getByLabel(muon_tag_infos_,SoftMuonTagInfoVector);
      for(View< reco::SoftLeptonTagInfo >::const_iterator iTagInfo = SoftMuonTagInfoVector->begin(); iTagInfo != SoftMuonTagInfoVector->end(); iTagInfo++) 
	{
	  softMuonTagInfo[iTagInfo->jet()] = &*iTagInfo;
	}
    }

  typedef map< JetRef, const SecondaryVertexTagInfo*, JetRefCompare > svTagInfoMap;
  svTagInfoMap svTagInfo;
  edm::Handle< View < reco::SecondaryVertexTagInfo > > svTagInfoVector;
  if(get_SV_tag_infos_)
    {
      iEvent.getByLabel(SV_tag_infos_,svTagInfoVector);
      for(View< reco::SecondaryVertexTagInfo >::const_iterator iTagInfo = svTagInfoVector->begin(); iTagInfo != svTagInfoVector->end(); iTagInfo++) 
	{
	  svTagInfo[iTagInfo->jet()] = &*iTagInfo;
	}
    }
  typedef map<JetRef, const TrackIPTagInfo*, JetRefCompare> ipTagInfoMap;
  ipTagInfoMap ipTagInfo;
  edm::Handle< View < reco::TrackIPTagInfo > > ipTagInfoVector;
  if(get_IP_tag_infos_)
    {
      iEvent.getByLabel(IP_tag_infos_,ipTagInfoVector);  
      for(View< reco::TrackIPTagInfo >::const_iterator iTagInfo = ipTagInfoVector->begin(); iTagInfo != ipTagInfoVector->end(); iTagInfo++) 
	{
	  ipTagInfo[iTagInfo->jet()] = &*iTagInfo;
	}
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
    } 
  else 
    {
      int fl = -1;
	for (unsigned int iJet = 0; iJet < jets->size(); iJet++)
	{
	  flavor[RefToBase<Jet>(jets, iJet)] = fl;
	}
    }

  //Get the btaggers that are defined in the configuration file

  map< string, reco::JetTagCollection > bTags;

  for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
    {
      edm::Handle<reco::JetTagCollection> bTagHandle;
      iEvent.getByLabel(ibTag->getParameter<InputTag>("label"), bTagHandle);
      bTags[ibTag->getParameter<string>("alias")] = *bTagHandle;
    }

  //Defining Data Storage:
  
  //Basic Jet Information
  vector<math::XYZTLorentzVector> jetP4;               
  vector<float> jetPt;                                 
  vector<float> jetEta;                                
  vector<float> jetPhi;                                
  vector<float> jetEMFraction;        
  vector<float> jetChargedEmEnergyFraction;
  vector<float> jetNeutralEmEnergyFraction;
  vector<float> jetChargedHadronEnergyFraction;
  vector<float> jetNeutralHadronEnergyFraction;
  vector<float> jetChargedMultiplicity;
  vector<float> jetMass;                               
  vector<int> jetnConstituents;  
  vector<int> jetnTracks;                           
//  vector<int> jetnElectrons;                              
//  vector<int> jetnMuons;                                  
  vector<math::XYZVector> jetVertex;                   
  vector<float> jetVertexChi2;               
  vector<float> jetVertexChi2Ndof;           
  vector<float> jetVertexNormalizedChi2;    

  //Track Information

  vector<int> trackJetIndex;
  vector<bool> trackSelected;
  vector<math::XYZVector> track3Momentum;
  vector<float> trackTransverseMomentum;
  vector<float> trackMomentum;
  vector<int> trackNHits;
  vector<int> trackNPixelHits;
  vector<float> trackChi2;
  vector<float> trackNormChi2;
  vector<int> trackQuality;
  vector<float> trackLongitudinalImpactParameter;
  vector<float> trackIP;
  vector<float> trackDecayLength;
  vector<float> trackIP3d;
  vector<float> trackIP2d;
  vector<float> trackIP3dError;
  vector<float> trackIP2dError;

  //MC Truth Information
  vector<float> MCTrueFlavor;                          
						       
  //secondaryVertexTagInfos:			       
  vector<math::XYZVector> SecondaryVertex;             
  vector<float> SV3dDistance;                          
  vector<float> SV3dDistanceError;                     
  vector<float> SV2dDistance;                          
  vector<float> SV2dDistanceError;                     
  vector<float> SVChi2;                                
  vector<float> SVDegreesOfFreedom;                    
  vector<float> SVNormChi2;                            
  vector<int> SVnSelectedTracks;                               
  vector<float> SVMass;                                
  vector<float> SVMasspiHyp;                                
  vector<int> SVnVertices;                             
  vector<int>   SVnVertexTracks;         
  vector<float> SVjetDeltaR;
  vector<float> SVjetAngle;
  vector<float> SVjetCosAngle;
  vector<float> SVdeltaCosAngle;
  vector<float> SVdeltaAngle;
               
  //impactParameterTagInfos
  vector<int> IPnSelectedTracks;                       
  vector<math::XYZVector> IPghostTrackP3;      
  vector<float> IPghostTrackPt;                        
  vector<float> IPghostTrackPtRel;                        
  vector<float> IPghostTrackEta;                       
  vector<float> IPghostTrackPhi;                       
  vector<float> IPghostTrackDeltaR;                
  vector< vector<int> > IP3dTrackQuality(IP_n_saved_tracks_);    
  vector< vector<float> > IP3d(IP_n_saved_tracks_);
  vector< vector<float> > IP3dError(IP_n_saved_tracks_);
  vector< vector<float> > IP3dProbability(IP_n_saved_tracks_);
  vector< vector<float> > IP3dTrackPtRel(IP_n_saved_tracks_);
  vector< vector<int> > IP2dTrackQuality(IP_n_saved_tracks_);    
  vector< vector<float> > IP2d(IP_n_saved_tracks_);
  vector< vector<float> > IP2dError(IP_n_saved_tracks_);
  vector< vector<float> > IP2dProbability(IP_n_saved_tracks_);
  vector< vector<float> > IP2dTrackPtRel(IP_n_saved_tracks_);

  //softElectronTagInfos
  vector<int> nElectrons;                            
  vector<float> electronPt;   			       
  vector<float> electronEta;  			       
  vector<float> electronPhi;  			       
  vector<float> electronNHits;   		       
  vector<float> electronNChi2;			       
  vector<float> electronPtRel;   		       
  vector<float> electronSip2d;   		       
  vector<float> electronSip3d;   		       
  vector<float> electronP0Par;   		       
  vector<float> electronDeltaR;  		       
  vector<float> electronEtaRel;  		       
  vector<float> electronRatio;   		       
  vector<float> electronRatioRel;                      
						       
  //softMuonTagInfos	
  vector<int> nMuons;                                
  vector<float> muonPt;   			       
  vector<float> muonEta;  			       
  vector<float> muonPhi;  			       
  vector<float> muonNHits;   			       
  vector<float> muonNChi2;	         	       
  vector<float> muonPtRel;   			       
  vector<float> muonSip2d;   			       
  vector<float> muonSip3d;   			       
  vector<float> muonP0Par;   			       
  vector<float> muonDeltaR;  			       
  vector<float> muonEtaRel;  			       
  vector<float> muonRatio;   			       
  vector<float> muonRatioRel;                          

  map< string, vector< float > > bTagVectors;
  for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
    {
      vector<float> vect;
      bTagVectors[ibTag->getParameter<string>("alias")] = vect;
    }

  //Begin Loop over Jets and record the various information
  for (unsigned int iJet = 0; iJet<jets->size(); iJet++)
    {
      JetRef thisJetRef = RefToBase<Jet>(jets, iJet);
 
      //Basic Jet Information
      jetP4.push_back(thisJetRef->p4());               
      jetPt.push_back(thisJetRef->p4().Pt());                              
      jetEta.push_back(thisJetRef->p4().Eta());
      jetPhi.push_back(thisJetRef->p4().Phi());
      //Store some Calo Jet Information:
      if(const CaloJet* caloJet = dynamic_cast<const CaloJet*>(&(*(thisJetRef.get()) )))
	{
	  jetEMFraction.push_back(caloJet->emEnergyFraction());
	}
      else
	{
	  jetEMFraction.push_back(-1.0);
	}
      //Store some Particle Flow Jet Information
      if(const PFJet* pfJet = dynamic_cast<const PFJet*>(&(*(thisJetRef.get()) )))
	{
	  jetChargedEmEnergyFraction.push_back(pfJet->chargedEmEnergyFraction());
	  jetNeutralEmEnergyFraction.push_back(pfJet->neutralEmEnergyFraction());
	  jetChargedHadronEnergyFraction.push_back(pfJet->chargedHadronEnergyFraction());
	  jetNeutralHadronEnergyFraction.push_back(pfJet->neutralHadronEnergyFraction());
	  jetChargedMultiplicity.push_back(pfJet->chargedMultiplicity());
	}
      else
	{
	  jetChargedEmEnergyFraction.push_back(-1.0);
	  jetNeutralEmEnergyFraction.push_back(-1.0);
	  jetChargedHadronEnergyFraction.push_back(-1.0);
	  jetNeutralHadronEnergyFraction.push_back(-1.0);
	  jetChargedMultiplicity.push_back(-1.0);
	}
      jetMass.push_back(thisJetRef->p4().M());
      jetnConstituents.push_back(thisJetRef->nConstituents());
      jetnTracks.push_back((*jetTracks)[thisJetRef].size());

      jetVertex.push_back(math::XYZVector(thisJetRef->vx(),thisJetRef->vy(),thisJetRef->vz()));
      jetVertexChi2.push_back(thisJetRef->vertexChi2());
      jetVertexChi2Ndof.push_back(thisJetRef->vertexNdof());
      jetVertexNormalizedChi2.push_back(thisJetRef->vertexNormalizedChi2());

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

      for(track_iterator iTrack = (*jetTracks)[thisJetRef].begin(); iTrack != (*jetTracks)[thisJetRef].end(); iTrack++)
	{ 
	  trackJetIndex.push_back(iJet);
	  bool isSelected = false;
	  if(get_IP_tag_infos_)
	    {
	      for(track_iterator jTrack = ipTagInfo[thisJetRef]->selectedTracks().begin(); jTrack != ipTagInfo[thisJetRef]->selectedTracks().end(); jTrack++)
		{
		  if((*iTrack)==(*jTrack)) {
		    isSelected = true;
		    continue;
		  }
		}
	    }
	  trackSelected.push_back(isSelected);
	  track3Momentum.push_back(math::XYZVector((*iTrack)->px(),(*iTrack)->py(),(*iTrack)->pz()));
	  trackTransverseMomentum.push_back((*iTrack)->pt());
	  trackMomentum.push_back((*iTrack)->p());
	  trackNHits.push_back((*iTrack)->hitPattern().numberOfValidHits());
	  trackNPixelHits.push_back((*iTrack)->hitPattern().numberOfValidPixelHits());
	  trackChi2.push_back((*iTrack)->chi2());
	  trackNormChi2.push_back((*iTrack)->normalizedChi2());
	  //trackQuality.push_back((*iTrack)->qualityMask());
	  //cout << (*iTrack)->qualityMask() << endl;
	  for(int i = 2; i>-2; i--){
	    if((*iTrack)->quality(reco::TrackBase::TrackQuality(i))){
	      trackQuality.push_back(i);
	      continue;
	    }
	  }
	  trackLongitudinalImpactParameter.push_back((*iTrack)->dz(pv->position()));
  	  TransientTrack transientTrack = builder->build(*iTrack);
  	  GlobalVector direction(thisJetRef->momentum().x(), thisJetRef->momentum().y(), thisJetRef->momentum().z());
  	  Measurement1D ip3d = IPTools::signedImpactParameter3D(transientTrack, direction, *pv).second;
  	  Measurement1D ip2d = IPTools::signedTransverseImpactParameter(transientTrack, direction, *pv).second;
  	  trackIP3d.push_back(ip3d.value());
  	  trackIP2d.push_back(ip2d.value());
  	  trackIP3dError.push_back(ip3d.error());
  	  trackIP2dError.push_back(ip2d.error());
	  //trackDecayLength.push_back();
      	}       

      //MC Truth Information
      MCTrueFlavor.push_back(flavor[thisJetRef]);                          
      //secondaryVertexTagInfos:
      if(get_SV_tag_infos_)
	{
	  SVnSelectedTracks.push_back(svTagInfo[thisJetRef]->nSelectedTracks());  
	  bool hasVertex = svTagInfo[thisJetRef]->nVertices() > 0;
	  if(hasVertex)
	    {
	      math::XYZVector thisVertex(svTagInfo[thisJetRef]->secondaryVertex(0).x(),svTagInfo[thisJetRef]->secondaryVertex(0).y(),svTagInfo[thisJetRef]->secondaryVertex(0).z());
	      math::XYZVector jetVertex(thisJetRef->vx(),thisJetRef->vy(),thisJetRef->vz());
	      math::XYZVector vertexDirection(thisVertex-jetVertex);
	      math::XYZVector jetVector(thisJetRef->p4().x(),thisJetRef->p4().y(),thisJetRef->p4().z());
	      math::XYZVector addTracksVertex(0,0,0);
	      SVnVertices.push_back(svTagInfo[thisJetRef]->nVertices());
	      SecondaryVertex.push_back(thisVertex);
	      SV3dDistance.push_back(svTagInfo[thisJetRef]->flightDistance(0).value());                          
	      SV3dDistanceError.push_back(svTagInfo[thisJetRef]->flightDistance(0).error());                     
	      SV2dDistance.push_back(svTagInfo[thisJetRef]->flightDistance(0, true).value());                          
	      SV2dDistanceError.push_back(svTagInfo[thisJetRef]->flightDistance(0, true).error());                     
	      SVChi2.push_back(svTagInfo[thisJetRef]->secondaryVertex(0).chi2());                                
	      SVDegreesOfFreedom.push_back(svTagInfo[thisJetRef]->secondaryVertex(0).ndof());                    
	      SVNormChi2.push_back(svTagInfo[thisJetRef]->secondaryVertex(0).normalizedChi2());
  	      SVnVertexTracks.push_back(svTagInfo[thisJetRef]->secondaryVertex(0).tracksSize());
	      math::XYZTLorentzVector vertexP4(0,0,0,0);
	      math::XYZTLorentzVector vertexP4piHyp(0,0,0,0);
	      //	      for(vector<Track >::const_iterator iTrack = svTagInfo[thisJetRef]->secondaryVertex(0).refittedTracks().begin(); iTrack != svTagInfo[thisJetRef]->secondaryVertex(0).refittedTracks().end(); iTrack++)
	      for(Vertex::trackRef_iterator iTrack = svTagInfo[thisJetRef]->secondaryVertex(0).tracks_begin(); iTrack != svTagInfo[thisJetRef]->secondaryVertex(0).tracks_end(); iTrack++)
		{
		  Track thisTrack = *(iTrack->get());
		  addTracksVertex+=math::XYZVector(thisTrack.px(), thisTrack.py(), thisTrack.pz());
		  vertexP4+=math::XYZTLorentzVector(thisTrack.px(), thisTrack.py(), thisTrack.pz(), thisTrack.p()); // massless hypothesis
		  vertexP4piHyp+=math::XYZTLorentzVector(thisTrack.px(), thisTrack.py(), thisTrack.pz(), sqrt(0.01948816 + thisTrack.p() * thisTrack.p()) ); // pion mass hypothesis
		}
	      SVMass.push_back(vertexP4.M());
	      SVMasspiHyp.push_back(vertexP4piHyp.M());
	      SVjetDeltaR.push_back(deltaR(thisJetRef->eta(), thisJetRef->phi(), addTracksVertex.eta(), addTracksVertex.phi()) );	      
	      double cosAngle = addTracksVertex.Dot(jetVector)/sqrt(addTracksVertex.mag2()*jetVector.mag2());
	      SVjetAngle.push_back(cosAngle);
	      SVjetCosAngle.push_back(acos(cosAngle));
	      cosAngle = addTracksVertex.Dot(vertexDirection)/sqrt(addTracksVertex.mag2()*vertexDirection.mag2());
	      SVdeltaCosAngle.push_back(cosAngle);
	      SVdeltaAngle.push_back(acos(cosAngle));
	    }
	  else
	    {
	      SVnVertices.push_back(0);
	      SecondaryVertex.push_back(math::XYZVector(0,0,0));             
	      SV3dDistance.push_back(-1);                          
	      SV3dDistanceError.push_back(-1);                     
	      SV2dDistance.push_back(-1);                          
	      SV2dDistanceError.push_back(-1);                     
	      SVChi2.push_back(-1);                                
	      SVDegreesOfFreedom.push_back(-1);                    
	      SVNormChi2.push_back(-1);                                                           
	      SVnVertexTracks.push_back(-1);
	      SVMass.push_back(-1);
	      SVMasspiHyp.push_back(-1);
	      SVjetDeltaR.push_back(-1);
	      SVjetAngle.push_back(-10);
	      SVjetCosAngle.push_back(-10);
	      SVdeltaCosAngle.push_back(-10);
	      SVdeltaAngle.push_back(-10);
	    }
	}

      //impactParameterTagInfos
      if(get_IP_tag_infos_)
	{
	  const GlobalVector jetAxis = ipTagInfo[thisJetRef]->axis();
	  const math::XYZVector axis( jetAxis.x(), jetAxis.y(), jetAxis.z());
	  const math::XYZVector ghostTrack(ipTagInfo[thisJetRef]->ghostTrack()->px(),ipTagInfo[thisJetRef]->ghostTrack()->py(),ipTagInfo[thisJetRef]->ghostTrack()->pz());
	  IPnSelectedTracks.push_back(ipTagInfo[thisJetRef]->selectedTracks().size());                       
	  IPghostTrackP3.push_back(ghostTrack);
	  IPghostTrackPt.push_back(ipTagInfo[thisJetRef]->ghostTrack()->pt());                        
	  IPghostTrackPtRel.push_back(Perp(ghostTrack,axis));
	  IPghostTrackEta.push_back(ipTagInfo[thisJetRef]->ghostTrack()->eta());                       
	  IPghostTrackPhi.push_back(ipTagInfo[thisJetRef]->ghostTrack()->phi());                       
	  IPghostTrackDeltaR.push_back(deltaR(thisJetRef->eta(), thisJetRef->phi(), ipTagInfo[thisJetRef]->ghostTrack()->eta(), ipTagInfo[thisJetRef]->ghostTrack()->phi()));                    
	  for(unsigned int iTrack = 0; iTrack < IP_n_saved_tracks_; iTrack++)
	    {
	      if(iTrack <  ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP3DSig).size())
		{
		  size_t location3D = ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP3DSig)[iTrack];
		  for(int i = 2; i>-2; i--){
		    if(ipTagInfo[thisJetRef]->selectedTracks()[location3D]->quality(reco::TrackBase::TrackQuality(i))){
		      IP3dTrackQuality[iTrack].push_back(i);
		      continue;
		    }
		  }
		  IP3d[iTrack].push_back(ipTagInfo[thisJetRef]->impactParameterData()[location3D].ip3d.value());
		  IP3dError[iTrack].push_back(ipTagInfo[thisJetRef]->impactParameterData()[location3D].ip3d.error());
		  IP3dProbability[iTrack].push_back(ipTagInfo[thisJetRef]->probabilities(0)[location3D]);
		  const math::XYZVector thisTrack(ipTagInfo[thisJetRef]->selectedTracks()[location3D]->px(),
						  ipTagInfo[thisJetRef]->selectedTracks()[location3D]->py(),
						  ipTagInfo[thisJetRef]->selectedTracks()[location3D]->pz());
		  IP3dTrackPtRel[iTrack].push_back( Perp(thisTrack,axis ) );
		}
	      else
		{
		  IP3dTrackQuality[iTrack].push_back(-100);
		  IP3d[iTrack].push_back(-100.0);
		  IP3dError[iTrack].push_back(-1.0);
		  IP3dProbability[iTrack].push_back(-1.0);
		  IP3dTrackPtRel[iTrack].push_back(-1.0);
		}
	      if(iTrack <  ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP3DSig).size())
		{
		  size_t location2D = ipTagInfo[thisJetRef]->sortedIndexes(TrackIPTagInfo::IP2DSig)[iTrack];
		  for(int i = 2; i>-2; i--){
		    if(ipTagInfo[thisJetRef]->selectedTracks()[location2D]->quality(reco::TrackBase::TrackQuality(i))){
		      IP2dTrackQuality[iTrack].push_back(i);
		      continue;
		    }
		  }
		  IP2d[iTrack].push_back(ipTagInfo[thisJetRef]->impactParameterData()[location2D].ip2d.value());
		  IP2dError[iTrack].push_back(ipTagInfo[thisJetRef]->impactParameterData()[location2D].ip2d.error());
		  IP2dProbability[iTrack].push_back(ipTagInfo[thisJetRef]->probabilities(1)[location2D]);
		  const math::XYZVector thisTrack(ipTagInfo[thisJetRef]->selectedTracks()[location2D]->px(),
						  ipTagInfo[thisJetRef]->selectedTracks()[location2D]->py(),
						  ipTagInfo[thisJetRef]->selectedTracks()[location2D]->pz());
		  IP2dTrackPtRel[iTrack].push_back( Perp(thisTrack,axis ) );

		}
	      else
		{
		  IP2dTrackQuality[iTrack].push_back(-100);
		  IP2d[iTrack].push_back(-100.0);
		  IP2dError[iTrack].push_back(-1.0);
		  IP2dProbability[iTrack].push_back(-1.0);
		  IP2dTrackPtRel[iTrack].push_back(-1.0);
		}
	    } 
	}

      //softElectronTagInfos
      if(get_SE_tag_infos_)
	{
	  bool hasLeptons = softElectronTagInfo[thisJetRef]->leptons() > 0;
	  if(hasLeptons)
	    {
	      nElectrons.push_back(softElectronTagInfo[thisJetRef]->leptons());
	      unsigned int maxPtElectron = 0;
	      for(unsigned int iElectron = 0; iElectron < softElectronTagInfo[thisJetRef]->leptons(); iElectron++)
		{
		  if(softElectronTagInfo[thisJetRef]->lepton(iElectron)->pt() > softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->pt() )
		    maxPtElectron = iElectron;
		}
	      electronPt.push_back(softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->pt());   			       
	      electronEta.push_back(softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->eta());  			       
	      electronPhi.push_back(softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->phi());  			       
	      electronNHits.push_back(softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->found());   		       
	      electronNChi2.push_back(softElectronTagInfo[thisJetRef]->lepton(maxPtElectron)->normalizedChi2());			       
	      electronPtRel.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).ptRel);   		       
	      electronSip2d.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).sip2d);   		       
	      electronSip3d.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).sip3d);   		       
	      electronP0Par.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).p0Par);   		       
	      electronDeltaR.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).deltaR);  		       
	      electronEtaRel.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).etaRel);  		       
	      electronRatio.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).ratio);   		       
	      electronRatioRel.push_back(softElectronTagInfo[thisJetRef]->properties(maxPtElectron).ratioRel);                      
	    }	       
	}
      //softMuonTagInfos
      if(get_SM_tag_infos_)
	{
	  bool hasLeptons = softMuonTagInfo[thisJetRef]->leptons() > 0;
	  if(hasLeptons)
	    {
	      nMuons.push_back(softMuonTagInfo[thisJetRef]->leptons());
	      unsigned int maxPtMuon = 0;
	      for(unsigned int iMuon = 0; iMuon < softMuonTagInfo[thisJetRef]->leptons(); iMuon++)
		{
		  if(softMuonTagInfo[thisJetRef]->lepton(iMuon)->pt() > softMuonTagInfo[thisJetRef]->lepton(maxPtMuon)->pt() )
		    maxPtMuon = iMuon;
		}
	      muonPt.push_back(softMuonTagInfo[thisJetRef]->lepton(maxPtMuon)->pt());   			       
	      muonEta.push_back(softMuonTagInfo[thisJetRef]->lepton(maxPtMuon)->eta());  			       
	      muonPhi.push_back(softMuonTagInfo[thisJetRef]->lepton(maxPtMuon)->phi());  			       
	      muonNHits.push_back(softMuonTagInfo[thisJetRef]->lepton(maxPtMuon)->found());   		       
	      muonNChi2.push_back(softMuonTagInfo[thisJetRef]->lepton(maxPtMuon)->normalizedChi2());			       
	      muonPtRel.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).ptRel);   		       
	      muonSip2d.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).sip2d);   		       
	      muonSip3d.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).sip3d);   		       
	      muonP0Par.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).p0Par);   		       
	      muonDeltaR.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).deltaR);  		       
	      muonEtaRel.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).etaRel);  		       
	      muonRatio.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).ratio);   		       
	      muonRatioRel.push_back(softMuonTagInfo[thisJetRef]->properties(maxPtMuon).ratioRel);                      
	    }	 
	}      
      for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
	{
	  bTagVectors[ibTag->getParameter<string>("alias")].push_back((bTags[ibTag->getParameter<string>("alias")])[thisJetRef]);
	}
    }

  //Putting Information into the Event

  //Basic Jet Information
  iEvent.put(auto_ptr< vector< math::XYZTLorentzVector> >(new vector< math::XYZTLorentzVector>(jetP4)),label_+"jetP4");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetPt)),label_+"jetPt");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetEta)),label_+"jetEta");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetPhi)),label_+"jetPhi");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetEMFraction)),label_+"jetEMFraction");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetChargedEmEnergyFraction)),label_+"jetChargedEmEnergyFraction");    
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetNeutralEmEnergyFraction)),label_+"jetNeutralEmEnergyFraction");    
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetChargedHadronEnergyFraction)),label_+"jetChargedHadronEnergyFraction");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetNeutralHadronEnergyFraction)),label_+"jetNeutralHadronEnergyFraction");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetChargedMultiplicity)),label_+"jetChargedMultiplicity");        
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetMass)),label_+"jetMass");
  iEvent.put(auto_ptr< vector<int> >(new vector<int>(jetnConstituents)),label_+"jetnConstituents");
  iEvent.put(auto_ptr< vector<int> >(new vector<int>(jetnTracks)),label_+"jetnTracks");
  iEvent.put(auto_ptr< vector<math::XYZVector> >(new vector<math::XYZVector>(jetVertex)),label_+"jetVertex");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetVertexChi2)),label_+"jetVertexChi2");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetVertexChi2Ndof)),label_+"jetVertexChi2Ndof");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(jetVertexNormalizedChi2)),label_+"jetVertexNormalizedChi2");

  //Track Information

  iEvent.put(auto_ptr< vector<int> >(new vector<int>(trackJetIndex)), label_ + "trackJetIndex" );
  iEvent.put(auto_ptr< vector<bool> >(new vector<bool>(trackSelected)), label_ + "trackSelected" );
  iEvent.put(auto_ptr< vector<math::XYZVector> >(new vector<math::XYZVector>(track3Momentum)),label_ + "track3Momentum");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackTransverseMomentum)),label_ + "trackTransverseMomentum" );
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackMomentum)),label_ + "trackMomentum");
  iEvent.put(auto_ptr< vector<int> >(new vector<int>(trackNHits)),label_ + "trackNHits");
  iEvent.put(auto_ptr< vector<int> >(new vector<int>(trackNPixelHits)),label_ + "trackNPixelHits");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackChi2)),label_ + "trackChi2");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackNormChi2)),label_ + "trackNormChi2");
  iEvent.put(auto_ptr< vector<int> >(new vector<int>(trackQuality)),label_ + "trackQuality" );
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackLongitudinalImpactParameter)),label_ + "trackLongitudinalImpactParameter");
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackDecayLength)),label_ + "trackDecayLength" );
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackIP3d)),label_ + "trackIP3d" );
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackIP2d)),label_ + "trackIP2d" );
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackIP3dError)),label_ + "trackIP3dError" );
  iEvent.put(auto_ptr< vector<float> >(new vector<float>(trackIP2dError)),label_ + "trackIP2dError" );

  //MC Truth Information
  if(getMCTruth_)
    {
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(MCTrueFlavor)),label_+"MCTrueFlavor");
    }
			               
  //secondaryVertexTagInfos:					               
  if(get_SV_tag_infos_)
    {
      iEvent.put(auto_ptr< vector<math::XYZVector> >(new vector<math::XYZVector>(SecondaryVertex)),label_+"SecondaryVertex");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SV3dDistance)),label_+"SV3dDistance");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SV3dDistanceError)),label_+"SV3dDistanceError");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SV2dDistance)),label_+"SV2dDistance");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SV2dDistanceError)),label_+"SV2dDistanceError");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVChi2)),label_+"SVChi2");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVDegreesOfFreedom)),label_+"SVDegreesOfFreedom");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVNormChi2)),label_+"SVNormChi2");
      iEvent.put(auto_ptr< vector<int> >(new vector<int>(SVnSelectedTracks)),label_+"SVnSelectedTracks");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVMass)),label_+"SVMass");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVMasspiHyp)),label_+"SVMasspiHyp");
      iEvent.put(auto_ptr< vector<int> >(new vector<int>(SVnVertices)),label_+"SVnVertices");
      iEvent.put(auto_ptr< vector<int> >(new vector<int>(SVnVertexTracks)),label_+"SVnVertexTracks");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVjetDeltaR)),label_+"SVjetDeltaR");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVjetAngle)),label_+"SVjetAngle");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVjetCosAngle)),label_+"SVjetCosAngle");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVdeltaCosAngle)),label_+"SVdeltaCosAngle");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(SVdeltaAngle)),label_+"SVdeltaAngle");
    }          
  //impactParameterTagInfos
  if(get_IP_tag_infos_)
    {
      iEvent.put(auto_ptr< vector<int> >(new vector<int>(IPnSelectedTracks)),label_+"IPnSelectedTracks");
      iEvent.put(auto_ptr< vector<math::XYZVector> >(new vector<math::XYZVector>(IPghostTrackP3)),label_+"IPghostTrackP3");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(IPghostTrackPt)),label_+"IPghostTrackPt");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(IPghostTrackPtRel)),label_+"IPghostTrackPtRel");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(IPghostTrackEta)),label_+"IPghostTrackEta");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(IPghostTrackPhi)),label_+"IPghostTrackPhi");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(IPghostTrackDeltaR)),label_+"IPghostTrackDeltaR");
      for(unsigned int iTrack = 0; iTrack < IP_n_saved_tracks_; iTrack++)
	{
	  string alias;
	  stringstream trackNum;
	  trackNum << (iTrack+1);
	  alias = label_ + "IP3dTrackQuality"+trackNum.str();
	  iEvent.put(auto_ptr< vector<int> >(new vector<int>(IP3dTrackQuality[iTrack])),alias);
	  alias = label_ + "IP3d"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP3d[iTrack])),alias);
	  alias = label_ + "IP3dError"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP3dError[iTrack])),alias);
	  alias = label_ + "IP3dProbability"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP3dProbability[iTrack])),alias);
	  alias = label_ + "IP3dTrackPtRel"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP3dTrackPtRel[iTrack])),alias);
	  alias = label_ + "IP2dTrackQuality"+trackNum.str();
	  iEvent.put(auto_ptr< vector<int> >(new vector<int>(IP2dTrackQuality[iTrack])),alias);
	  alias = label_ + "IP2d"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP2d[iTrack])),alias);
	  alias = label_ + "IP2dError"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP2dError[iTrack])),alias);
	  alias = label_ + "IP2dProbability"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP2dProbability[iTrack])),alias);
	  alias = label_ + "IP2dTrackPtRel"+trackNum.str();
	  iEvent.put(auto_ptr< vector<float> >(new vector<float>(IP2dTrackPtRel[iTrack])),alias);
	}
    }
 
  //softElectronTagInfos
  if(get_SE_tag_infos_)
    {
      iEvent.put(auto_ptr< vector<int> >(new vector<int>(nElectrons)),label_+"nElectrons");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronPt)),label_+"electronPt");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronEta)),label_+"electronEta");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronPhi)),label_+"electronPhi");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronNHits)),label_+"electronNHits");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronNChi2)),label_+"electronNChi2");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronPtRel)),label_+"electronPtRel");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronSip2d)),label_+"electronSip2d");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronSip3d)),label_+"electronSip3d");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronP0Par)),label_+"electronP0Par");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronDeltaR)),label_+"electronDeltaR");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronEtaRel)),label_+"electronEtaRel");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronRatio)),label_+"electronRatio");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(electronRatioRel)),label_+"electronRatioRel");
    }
							               
  //softMuonTagInfos	
  if(get_SM_tag_infos_)
    {
      iEvent.put(auto_ptr< vector<int> >(new vector<int>(nMuons)),label_+"nMuons");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonPt)),label_+"muonPt");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonEta)),label_+"muonEta");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonPhi)),label_+"muonPhi");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonNHits)),label_+"muonNHits");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonNChi2)),label_+"muonNChi2");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonPtRel)),label_+"muonPtRel");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonSip2d)),label_+"muonSip2d");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonSip3d)),label_+"muonSip3d");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonP0Par)),label_+"muonP0Par");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonDeltaR)),label_+"muonDeltaR");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonEtaRel)),label_+"muonEtaRel");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonRatio)),label_+"muonRatio");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(muonRatioRel)),label_+"muonRatioRel");
    }

  //b tagger outputs configured in python file
  for (vector< ParameterSet >::iterator ibTag = bTag_Config_.begin(); ibTag != bTag_Config_.end(); ibTag++) 
    {
      string alias = ibTag->getParameter<string>("alias");
      iEvent.put(auto_ptr< vector<float> >(new vector<float>(bTagVectors[ibTag->getParameter<string>("alias")])),alias);
    }  
}

// ------------ method called once each job just before starting event loop  ------------
void 
TagNtupleProducer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TagNtupleProducer::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(TagNtupleProducer);
