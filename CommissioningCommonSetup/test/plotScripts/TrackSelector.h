//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug  4 12:39:27 2010 by ROOT version 5.22/00d
// from TTree t/t
// found on file: standardPFNtuple_MC.root
//////////////////////////////////////////////////////////

#ifndef TrackSelector_h
#define TrackSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>
#include "informationTrackCuts.h"
#include "TH1D.h"

class TrackSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

  // some objects
   TH1D*dataHist;
   TH1D* mcHistb;
   TH1D* mcHistc; 
   TH1D* mcHistl;
   TH1D* mcHistn;
   bool isData;
   informationTrackCuts info;


   // Declaration of leaf types
   Bool_t          triggerHLTL1Jet6U;
   Bool_t          triggerHLTL1Jet10U;
   Bool_t          triggerHLTJet15U;
   UInt_t          eventNumber;
   UInt_t          runNumber;
   UInt_t          lumiBlockNumber;
   UInt_t          numberOfPrimaryVertices;
   Float_t         pthat;
   Int_t           nJets;
   Float_t         jetPt[40];   //[nJets]
   Float_t         jetEta[40];   //[nJets]
   Float_t         jetPhi[40];   //[nJets]
   Float_t         jetEMFraction[40];   //[nJets]
   Float_t         jetChargedEmEnergyFraction[40];   //[nJets]
   Float_t         jetNeutralEmEnergyFraction[40];   //[nJets]
   Float_t         jetChargedHadronEnergyFraction[40];   //[nJets]
   Float_t         jetNeutralHadronEnergyFraction[40];   //[nJets]
   Float_t         jetChargedMultiplicity[40];   //[nJets]
   Float_t         jetMass[40];   //[nJets]
   Int_t           jetnConstituents[40];   //[nJets]
   Int_t           jetnTracks[40];   //[nJets]
   Float_t         jetVertexChi2[40];   //[nJets]
   Float_t         jetVertexChi2Ndof[40];   //[nJets]
   Float_t         jetVertexNormalizedChi2[40];   //[nJets]
   Int_t           nTracks;
   Int_t           trackJetIndex[200];   //[nTracks]
   Bool_t          trackSelected[200];   //[nTracks]
   Float_t         trackTransverseMomentum[200];   //[nTracks]
   Float_t         trackEta[200];   //[nTracks]
   Float_t         trackPhi[200];   //[nTracks]
   Float_t         trackMomentum[200];   //[nTracks]
   Int_t           trackNHits[200];   //[nTracks]
   Int_t           trackNPixelHits[200];   //[nTracks]
   Float_t         trackChi2[200];   //[nTracks]
   Float_t         trackNormChi2[200];   //[nTracks]
   Int_t           trackQuality[200];   //[nTracks]
   Float_t         trackLongitudinalImpactParameter[200];   //[nTracks]
   Float_t         trackIP[200];   //[nTracks]
   Float_t         trackDecayLength[200];   //[nTracks]
   Float_t         trackDistJetAxis[200];   //[nTracks]
   Float_t         trackDeltaR[200];   //[nTracks]
   Float_t         trackIP3d[200];   //[nTracks]
   Float_t         trackIP2d[200];   //[nTracks]
   Float_t         trackIP3dError[200];   //[nTracks]
   Float_t         trackIP2dError[200];   //[nTracks]
   Int_t           trackHasSharedPix1[200];   //[nTracks]
   Int_t           trackHasSharedPix2[200];   //[nTracks]
   Int_t           trackHasSharedPix3[200];   //[nTracks]
   Int_t           trackHasSharedPixAll[200];   //[nTracks]
   Int_t           MCTrueFlavor[40];   //[nJets]
   Float_t         SV3dDistance[40];   //[nJets]
   Float_t         SV3dDistanceError[40];   //[nJets]
   Float_t         SV2dDistance[40];   //[nJets]
   Float_t         SV2dDistanceError[40];   //[nJets]
   Float_t         SVChi2[40];   //[nJets]
   Float_t         SVIPFirstAboveCharm[40];   //[nJets]
   Float_t         SVDegreesOfFreedom[40];   //[nJets]
   Float_t         SVNormChi2[40];   //[nJets]
   Int_t           SVnSelectedTracks[40];   //[nJets]
   Float_t         SVMass[40];   //[nJets]
   Float_t         SVEnergyRatio[40];   //[nJets]
   Int_t           SVnVertices[40];   //[nJets]
   Int_t           SVnVertexTracks[40];   //[nJets]
   Int_t           SVnVertexTracksAll[40];   //[nJets]
   Int_t           SVnFirstVertexTracks[40];   //[nJets]
   Int_t           SVnFirstVertexTracksAll[40];   //[nJets]
   Float_t         SVjetDeltaR[40];   //[nJets]
   Float_t         SVvtxSumVtxDirDeltaR[40];   //[nJets]
   Float_t         SVvtxSumJetDeltaR[40];   //[nJets]
   Int_t           IPnSelectedTracks[40];   //[nJets]
   Float_t         IPghostTrackPt[40];   //[nJets]
   Float_t         IPghostTrackPtRel[40];   //[nJets]
   Float_t         IPghostTrackEta[40];   //[nJets]
   Float_t         IPghostTrackPhi[40];   //[nJets]
   Float_t         IPghostTrackDeltaR[40];   //[nJets]
   Int_t           IPPix1SharedHits[40];   //[nJets]
   Int_t           IPPix1TotalHits[40];   //[nJets]
   Int_t           IPPix2SharedHits[40];   //[nJets]
   Int_t           IPPix2TotalHits[40];   //[nJets]
   Int_t           IPPix3SharedHits[40];   //[nJets]
   Int_t           IPPix3TotalHits[40];   //[nJets]
   Int_t           IPPixAllSharedHits[40];   //[nJets]
   Int_t           IPPixAllTotalHits[40];   //[nJets]
   Int_t           IP3dTrackQuality1[40];   //[nJets]
   Int_t           IP3dHasSharedPix11[40];   //[nJets]
   Int_t           IP3dHasSharedPix21[40];   //[nJets]
   Int_t           IP3dHasSharedPix31[40];   //[nJets]
   Int_t           IP3dHasSharedPixAll1[40];   //[nJets]
   Float_t         IP3d1[40];   //[nJets]
   Float_t         IP3dError1[40];   //[nJets]
   Float_t         IP3dProbability1[40];   //[nJets]
   Float_t         IP3dTrackPtRel1[40];   //[nJets]
   Float_t         IP3dDistJetAxis1[40];   //[nJets]
   Float_t         IP3dDecayLength1[40];   //[nJets]
   Float_t         IP3dDeltaR1[40];   //[nJets]
   Float_t         IP3dMomentum1[40];   //[nJets]
   Float_t         IP3dTransverseMomentum1[40];   //[nJets]
   Float_t         IP3dEta1[40];   //[nJets]
   Float_t         IP3dPhi1[40];   //[nJets]
   Int_t           IP3dNHits1[40];   //[nJets]
   Int_t           IP3dNPixelHits1[40];   //[nJets]
   Float_t         IP3dNormChi21[40];   //[nJets]
   Int_t           IP2dTrackQuality1[40];   //[nJets]
   Float_t         IP2d1[40];   //[nJets]
   Float_t         IP2dError1[40];   //[nJets]
   Float_t         IP2dProbability1[40];   //[nJets]
   Float_t         IP2dTrackPtRel1[40];   //[nJets]
   Int_t           IP3dTrackQuality2[40];   //[nJets]
   Int_t           IP3dHasSharedPix12[40];   //[nJets]
   Int_t           IP3dHasSharedPix22[40];   //[nJets]
   Int_t           IP3dHasSharedPix32[40];   //[nJets]
   Int_t           IP3dHasSharedPixAll2[40];   //[nJets]
   Float_t         IP3d2[40];   //[nJets]
   Float_t         IP3dError2[40];   //[nJets]
   Float_t         IP3dProbability2[40];   //[nJets]
   Float_t         IP3dTrackPtRel2[40];   //[nJets]
   Float_t         IP3dDistJetAxis2[40];   //[nJets]
   Float_t         IP3dDecayLength2[40];   //[nJets]
   Float_t         IP3dDeltaR2[40];   //[nJets]
   Float_t         IP3dMomentum2[40];   //[nJets]
   Float_t         IP3dTransverseMomentum2[40];   //[nJets]
   Float_t         IP3dEta2[40];   //[nJets]
   Float_t         IP3dPhi2[40];   //[nJets]
   Int_t           IP3dNHits2[40];   //[nJets]
   Int_t           IP3dNPixelHits2[40];   //[nJets]
   Float_t         IP3dNormChi22[40];   //[nJets]
   Int_t           IP2dTrackQuality2[40];   //[nJets]
   Float_t         IP2d2[40];   //[nJets]
   Float_t         IP2dError2[40];   //[nJets]
   Float_t         IP2dProbability2[40];   //[nJets]
   Float_t         IP2dTrackPtRel2[40];   //[nJets]
   Int_t           IP3dTrackQuality3[40];   //[nJets]
   Int_t           IP3dHasSharedPix13[40];   //[nJets]
   Int_t           IP3dHasSharedPix23[40];   //[nJets]
   Int_t           IP3dHasSharedPix33[40];   //[nJets]
   Int_t           IP3dHasSharedPixAll3[40];   //[nJets]
   Float_t         IP3d3[40];   //[nJets]
   Float_t         IP3dError3[40];   //[nJets]
   Float_t         IP3dProbability3[40];   //[nJets]
   Float_t         IP3dTrackPtRel3[40];   //[nJets]
   Float_t         IP3dDistJetAxis3[40];   //[nJets]
   Float_t         IP3dDecayLength3[40];   //[nJets]
   Float_t         IP3dDeltaR3[40];   //[nJets]
   Float_t         IP3dMomentum3[40];   //[nJets]
   Float_t         IP3dTransverseMomentum3[40];   //[nJets]
   Float_t         IP3dEta3[40];   //[nJets]
   Float_t         IP3dPhi3[40];   //[nJets]
   Int_t           IP3dNHits3[40];   //[nJets]
   Int_t           IP3dNPixelHits3[40];   //[nJets]
   Float_t         IP3dNormChi23[40];   //[nJets]
   Int_t           IP2dTrackQuality3[40];   //[nJets]
   Float_t         IP2d3[40];   //[nJets]
   Float_t         IP2dError3[40];   //[nJets]
   Float_t         IP2dProbability3[40];   //[nJets]
   Float_t         IP2dTrackPtRel3[40];   //[nJets]
   Int_t           IP3dTrackQuality4[40];   //[nJets]
   Int_t           IP3dHasSharedPix14[40];   //[nJets]
   Int_t           IP3dHasSharedPix24[40];   //[nJets]
   Int_t           IP3dHasSharedPix34[40];   //[nJets]
   Int_t           IP3dHasSharedPixAll4[40];   //[nJets]
   Float_t         IP3d4[40];   //[nJets]
   Float_t         IP3dError4[40];   //[nJets]
   Float_t         IP3dProbability4[40];   //[nJets]
   Float_t         IP3dTrackPtRel4[40];   //[nJets]
   Float_t         IP3dDistJetAxis4[40];   //[nJets]
   Float_t         IP3dDecayLength4[40];   //[nJets]
   Float_t         IP3dDeltaR4[40];   //[nJets]
   Float_t         IP3dMomentum4[40];   //[nJets]
   Float_t         IP3dTransverseMomentum4[40];   //[nJets]
   Float_t         IP3dEta4[40];   //[nJets]
   Float_t         IP3dPhi4[40];   //[nJets]
   Int_t           IP3dNHits4[40];   //[nJets]
   Int_t           IP3dNPixelHits4[40];   //[nJets]
   Float_t         IP3dNormChi24[40];   //[nJets]
   Int_t           IP2dTrackQuality4[40];   //[nJets]
   Float_t         IP2d4[40];   //[nJets]
   Float_t         IP2dError4[40];   //[nJets]
   Float_t         IP2dProbability4[40];   //[nJets]
   Float_t         IP2dTrackPtRel4[40];   //[nJets]
   Int_t           nElectrons[40];   //[nJets]
   Float_t         electronPt[40];   //[nJets]
   Float_t         electronEta[40];   //[nJets]
   Float_t         electronPhi[40];   //[nJets]
   Int_t           electronNHits[40];   //[nJets]
   Int_t           electronNExpectedOuterHits[40];   //[nJets]
   Int_t           electronNPixelHits[40];   //[nJets]
   Float_t         electronNChi2[40];   //[nJets]
   Float_t         electronPtRel[40];   //[nJets]
   Float_t         electronSip2d[40];   //[nJets]
   Float_t         electronIp2d[40];   //[nJets]
   Float_t         electronIpe2d[40];   //[nJets]
   Float_t         electronSip3d[40];   //[nJets]
   Float_t         electronIp3d[40];   //[nJets]
   Float_t         electronIpe3d[40];   //[nJets]
   Float_t         electronP0Par[40];   //[nJets]
   Float_t         electronDeltaR[40];   //[nJets]
   Float_t         electronEtaRel[40];   //[nJets]
   Float_t         electronRatio[40];   //[nJets]
   Int_t           electronTrackQuality[40];   //[nJets]
   Float_t         electronRatioRel[40];   //[nJets]
   Int_t           nMuons[40];   //[nJets]
   Float_t         muonPt[40];   //[nJets]
   Float_t         muonEta[40];   //[nJets]
   Float_t         muonPhi[40];   //[nJets]
   Int_t           muonNHits[40];   //[nJets]
   Int_t           muonNExpectedOuterHits[40];   //[nJets]
   Int_t           muonNPixelHits[40];   //[nJets]
   Float_t         muonNChi2[40];   //[nJets]
   Float_t         muonPtRel[40];   //[nJets]
   Float_t         muonSip2d[40];   //[nJets]
   Float_t         muonIp2d[40];   //[nJets]
   Float_t         muonIpe2d[40];   //[nJets]
   Float_t         muonSip3d[40];   //[nJets]
   Float_t         muonIp3d[40];   //[nJets]
   Float_t         muonIpe3d[40];   //[nJets]
   Float_t         muonP0Par[40];   //[nJets]
   Float_t         muonDeltaR[40];   //[nJets]
   Float_t         muonEtaRel[40];   //[nJets]
   Float_t         muonRatio[40];   //[nJets]
   Int_t           muonTrackQuality[40];   //[nJets]
   Float_t         muonRatioRel[40];   //[nJets]
   Float_t         standardCombinedSecondaryVertexMVAPFBJetTags[40];   //[nJets]
   Float_t         standardCombinedSecondaryVertexPFBJetTags[40];   //[nJets]
   Float_t         standardGhostTrackPFBJetTags[40];   //[nJets]
   Float_t         standardJetBProbabilityPFBJetTags[40];   //[nJets]
   Float_t         standardJetProbabilityPFBJetTags[40];   //[nJets]
   Float_t         standardSimpleSecondaryVertexHighEffPFBJetTags[40];   //[nJets]
   Float_t         standardSimpleSecondaryVertexHighPurPFBJetTags[40];   //[nJets]
   Float_t         standardSoftElectronByIP3dPFBJetTags[40];   //[nJets]
   Float_t         standardSoftElectronByPtPFBJetTags[40];   //[nJets]
   Float_t         standardSoftMuonByIP3dPFBJetTags[40];   //[nJets]
   Float_t         standardSoftMuonByPtPFBJetTags[40];   //[nJets]
   Float_t         standardSoftMuonPFBJetTags[40];   //[nJets]
   Float_t         standardTrackCountingHighEffPFBJetTags[40];   //[nJets]
   Float_t         standardTrackCountingHighPurPFBJetTags[40];   //[nJets]

   // List of branches
   TBranch        *b_triggerHLTL1Jet6U;   //!
   TBranch        *b_triggerHLTL1Jet10U;   //!
   TBranch        *b_triggerHLTJet15U;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_lumiBlockNumber;   //!
   TBranch        *b_numberOfPrimaryVertices;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_jetPt;   //!
   TBranch        *b_jetEta;   //!
   TBranch        *b_jetPhi;   //!
   TBranch        *b_jetEMFraction;   //!
   TBranch        *b_jetChargedEmEnergyFraction;   //!
   TBranch        *b_jetNeutralEmEnergyFraction;   //!
   TBranch        *b_jetChargedHadronEnergyFraction;   //!
   TBranch        *b_jetNeutralHadronEnergyFraction;   //!
   TBranch        *b_jetChargedMultiplicity;   //!
   TBranch        *b_jetMass;   //!
   TBranch        *b_jetnConstituents;   //!
   TBranch        *b_jetnTracks;   //!
   TBranch        *b_jetVertexChi2;   //!
   TBranch        *b_jetVertexChi2Ndof;   //!
   TBranch        *b_jetVertexNormalizedChi2;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_trackJetIndex;   //!
   TBranch        *b_trackSelected;   //!
   TBranch        *b_trackTransverseMomentum;   //!
   TBranch        *b_trackEta;   //!
   TBranch        *b_trackPhi;   //!
   TBranch        *b_trackMomentum;   //!
   TBranch        *b_trackNHits;   //!
   TBranch        *b_trackNPixelHits;   //!
   TBranch        *b_trackChi2;   //!
   TBranch        *b_trackNormChi2;   //!
   TBranch        *b_trackQuality;   //!
   TBranch        *b_trackLongitudinalImpactParameter;   //!
   TBranch        *b_trackIP;   //!
   TBranch        *b_trackDecayLength;   //!
   TBranch        *b_trackDistJetAxis;   //!
   TBranch        *b_trackDeltaR;   //!
   TBranch        *b_trackIP3d;   //!
   TBranch        *b_trackIP2d;   //!
   TBranch        *b_trackIP3dError;   //!
   TBranch        *b_trackIP2dError;   //!
   TBranch        *b_trackHasSharedPix1;   //!
   TBranch        *b_trackHasSharedPix2;   //!
   TBranch        *b_trackHasSharedPix3;   //!
   TBranch        *b_trackHasSharedPixAll;   //!
   TBranch        *b_MCTrueFlavor;   //!
   TBranch        *b_SV3dDistance;   //!
   TBranch        *b_SV3dDistanceError;   //!
   TBranch        *b_SV2dDistance;   //!
   TBranch        *b_SV2dDistanceError;   //!
   TBranch        *b_SVChi2;   //!
   TBranch        *b_SVIPFirstAboveCharm;   //!
   TBranch        *b_SVDegreesOfFreedom;   //!
   TBranch        *b_SVNormChi2;   //!
   TBranch        *b_SVnSelectedTracks;   //!
   TBranch        *b_SVMass;   //!
   TBranch        *b_SVEnergyRatio;   //!
   TBranch        *b_SVnVertices;   //!
   TBranch        *b_SVnVertexTracks;   //!
   TBranch        *b_SVnVertexTracksAll;   //!
   TBranch        *b_SVnFirstVertexTracks;   //!
   TBranch        *b_SVnFirstVertexTracksAll;   //!
   TBranch        *b_SVjetDeltaR;   //!
   TBranch        *b_SVvtxSumVtxDirDeltaR;   //!
   TBranch        *b_SVvtxSumJetDeltaR;   //!
   TBranch        *b_IPnSelectedTracks;   //!
   TBranch        *b_IPghostTrackPt;   //!
   TBranch        *b_IPghostTrackPtRel;   //!
   TBranch        *b_IPghostTrackEta;   //!
   TBranch        *b_IPghostTrackPhi;   //!
   TBranch        *b_IPghostTrackDeltaR;   //!
   TBranch        *b_IPPix1SharedHits;   //!
   TBranch        *b_IPPix1TotalHits;   //!
   TBranch        *b_IPPix2SharedHits;   //!
   TBranch        *b_IPPix2TotalHits;   //!
   TBranch        *b_IPPix3SharedHits;   //!
   TBranch        *b_IPPix3TotalHits;   //!
   TBranch        *b_IPPixAllSharedHits;   //!
   TBranch        *b_IPPixAllTotalHits;   //!
   TBranch        *b_IP3dTrackQuality1;   //!
   TBranch        *b_IP3dHasSharedPix11;   //!
   TBranch        *b_IP3dHasSharedPix21;   //!
   TBranch        *b_IP3dHasSharedPix31;   //!
   TBranch        *b_IP3dHasSharedPixAll1;   //!
   TBranch        *b_IP3d1;   //!
   TBranch        *b_IP3dError1;   //!
   TBranch        *b_IP3dProbability1;   //!
   TBranch        *b_IP3dTrackPtRel1;   //!
   TBranch        *b_IP3dDistJetAxis1;   //!
   TBranch        *b_IP3dDecayLength1;   //!
   TBranch        *b_IP3dDeltaR1;   //!
   TBranch        *b_IP3dMomentum1;   //!
   TBranch        *b_IP3dTransverseMomentum1;   //!
   TBranch        *b_IP3dEta1;   //!
   TBranch        *b_IP3dPhi1;   //!
   TBranch        *b_IP3dNHits1;   //!
   TBranch        *b_IP3dNPixelHits1;   //!
   TBranch        *b_IP3dNormChi21;   //!
   TBranch        *b_IP2dTrackQuality1;   //!
   TBranch        *b_IP2d1;   //!
   TBranch        *b_IP2dError1;   //!
   TBranch        *b_IP2dProbability1;   //!
   TBranch        *b_IP2dTrackPtRel1;   //!
   TBranch        *b_IP3dTrackQuality2;   //!
   TBranch        *b_IP3dHasSharedPix12;   //!
   TBranch        *b_IP3dHasSharedPix22;   //!
   TBranch        *b_IP3dHasSharedPix32;   //!
   TBranch        *b_IP3dHasSharedPixAll2;   //!
   TBranch        *b_IP3d2;   //!
   TBranch        *b_IP3dError2;   //!
   TBranch        *b_IP3dProbability2;   //!
   TBranch        *b_IP3dTrackPtRel2;   //!
   TBranch        *b_IP3dDistJetAxis2;   //!
   TBranch        *b_IP3dDecayLength2;   //!
   TBranch        *b_IP3dDeltaR2;   //!
   TBranch        *b_IP3dMomentum2;   //!
   TBranch        *b_IP3dTransverseMomentum2;   //!
   TBranch        *b_IP3dEta2;   //!
   TBranch        *b_IP3dPhi2;   //!
   TBranch        *b_IP3dNHits2;   //!
   TBranch        *b_IP3dNPixelHits2;   //!
   TBranch        *b_IP3dNormChi22;   //!
   TBranch        *b_IP2dTrackQuality2;   //!
   TBranch        *b_IP2d2;   //!
   TBranch        *b_IP2dError2;   //!
   TBranch        *b_IP2dProbability2;   //!
   TBranch        *b_IP2dTrackPtRel2;   //!
   TBranch        *b_IP3dTrackQuality3;   //!
   TBranch        *b_IP3dHasSharedPix13;   //!
   TBranch        *b_IP3dHasSharedPix23;   //!
   TBranch        *b_IP3dHasSharedPix33;   //!
   TBranch        *b_IP3dHasSharedPixAll3;   //!
   TBranch        *b_IP3d3;   //!
   TBranch        *b_IP3dError3;   //!
   TBranch        *b_IP3dProbability3;   //!
   TBranch        *b_IP3dTrackPtRel3;   //!
   TBranch        *b_IP3dDistJetAxis3;   //!
   TBranch        *b_IP3dDecayLength3;   //!
   TBranch        *b_IP3dDeltaR3;   //!
   TBranch        *b_IP3dMomentum3;   //!
   TBranch        *b_IP3dTransverseMomentum3;   //!
   TBranch        *b_IP3dEta3;   //!
   TBranch        *b_IP3dPhi3;   //!
   TBranch        *b_IP3dNHits3;   //!
   TBranch        *b_IP3dNPixelHits3;   //!
   TBranch        *b_IP3dNormChi23;   //!
   TBranch        *b_IP2dTrackQuality3;   //!
   TBranch        *b_IP2d3;   //!
   TBranch        *b_IP2dError3;   //!
   TBranch        *b_IP2dProbability3;   //!
   TBranch        *b_IP2dTrackPtRel3;   //!
   TBranch        *b_IP3dTrackQuality4;   //!
   TBranch        *b_IP3dHasSharedPix14;   //!
   TBranch        *b_IP3dHasSharedPix24;   //!
   TBranch        *b_IP3dHasSharedPix34;   //!
   TBranch        *b_IP3dHasSharedPixAll4;   //!
   TBranch        *b_IP3d4;   //!
   TBranch        *b_IP3dError4;   //!
   TBranch        *b_IP3dProbability4;   //!
   TBranch        *b_IP3dTrackPtRel4;   //!
   TBranch        *b_IP3dDistJetAxis4;   //!
   TBranch        *b_IP3dDecayLength4;   //!
   TBranch        *b_IP3dDeltaR4;   //!
   TBranch        *b_IP3dMomentum4;   //!
   TBranch        *b_IP3dTransverseMomentum4;   //!
   TBranch        *b_IP3dEta4;   //!
   TBranch        *b_IP3dPhi4;   //!
   TBranch        *b_IP3dNHits4;   //!
   TBranch        *b_IP3dNPixelHits4;   //!
   TBranch        *b_IP3dNormChi24;   //!
   TBranch        *b_IP2dTrackQuality4;   //!
   TBranch        *b_IP2d4;   //!
   TBranch        *b_IP2dError4;   //!
   TBranch        *b_IP2dProbability4;   //!
   TBranch        *b_IP2dTrackPtRel4;   //!
   TBranch        *b_nElectrons;   //!
   TBranch        *b_electronPt;   //!
   TBranch        *b_electronEta;   //!
   TBranch        *b_electronPhi;   //!
   TBranch        *b_electronNHits;   //!
   TBranch        *b_electronNExpectedOuterHits;   //!
   TBranch        *b_electronNPixelHits;   //!
   TBranch        *b_electronNChi2;   //!
   TBranch        *b_electronPtRel;   //!
   TBranch        *b_electronSip2d;   //!
   TBranch        *b_electronIp2d;   //!
   TBranch        *b_electronIpe2d;   //!
   TBranch        *b_electronSip3d;   //!
   TBranch        *b_electronIp3d;   //!
   TBranch        *b_electronIpe3d;   //!
   TBranch        *b_electronP0Par;   //!
   TBranch        *b_electronDeltaR;   //!
   TBranch        *b_electronEtaRel;   //!
   TBranch        *b_electronRatio;   //!
   TBranch        *b_electronTrackQuality;   //!
   TBranch        *b_electronRatioRel;   //!
   TBranch        *b_nMuons;   //!
   TBranch        *b_muonPt;   //!
   TBranch        *b_muonEta;   //!
   TBranch        *b_muonPhi;   //!
   TBranch        *b_muonNHits;   //!
   TBranch        *b_muonNExpectedOuterHits;   //!
   TBranch        *b_muonNPixelHits;   //!
   TBranch        *b_muonNChi2;   //!
   TBranch        *b_muonPtRel;   //!
   TBranch        *b_muonSip2d;   //!
   TBranch        *b_muonIp2d;   //!
   TBranch        *b_muonIpe2d;   //!
   TBranch        *b_muonSip3d;   //!
   TBranch        *b_muonIp3d;   //!
   TBranch        *b_muonIpe3d;   //!
   TBranch        *b_muonP0Par;   //!
   TBranch        *b_muonDeltaR;   //!
   TBranch        *b_muonEtaRel;   //!
   TBranch        *b_muonRatio;   //!
   TBranch        *b_muonTrackQuality;   //!
   TBranch        *b_muonRatioRel;   //!
   TBranch        *b_standardCombinedSecondaryVertexMVAPFBJetTags;   //!
   TBranch        *b_standardCombinedSecondaryVertexPFBJetTags;   //!
   TBranch        *b_standardGhostTrackPFBJetTags;   //!
   TBranch        *b_standardJetBProbabilityPFBJetTags;   //!
   TBranch        *b_standardJetProbabilityPFBJetTags;   //!
   TBranch        *b_standardSimpleSecondaryVertexHighEffPFBJetTags;   //!
   TBranch        *b_standardSimpleSecondaryVertexHighPurPFBJetTags;   //!
   TBranch        *b_standardSoftElectronByIP3dPFBJetTags;   //!
   TBranch        *b_standardSoftElectronByPtPFBJetTags;   //!
   TBranch        *b_standardSoftMuonByIP3dPFBJetTags;   //!
   TBranch        *b_standardSoftMuonByPtPFBJetTags;   //!
   TBranch        *b_standardSoftMuonPFBJetTags;   //!
   TBranch        *b_standardTrackCountingHighEffPFBJetTags;   //!
   TBranch        *b_standardTrackCountingHighPurPFBJetTags;   //!

   TrackSelector(TTree * /*tree*/ =0) { }
   virtual ~TrackSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   virtual void    SetUp(bool isData_, TH1D*dataHist_, TH1D* mcHistb_, TH1D* mcHistc_, TH1D* mcHistl_, TH1D* mcHistn_, informationTrackCuts info_){
     isData = isData_;
     dataHist = dataHist_;
     mcHistb = mcHistb_;
     mcHistc = mcHistc_;
     mcHistl = mcHistl_;
     mcHistn = mcHistn_;
     info = info_;
   }

   ClassDef(TrackSelector,0);
};

#endif

#ifdef TrackSelector_cxx
void TrackSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("triggerHLTL1Jet6U", &triggerHLTL1Jet6U, &b_triggerHLTL1Jet6U);
   fChain->SetBranchAddress("triggerHLTL1Jet10U", &triggerHLTL1Jet10U, &b_triggerHLTL1Jet10U);
   fChain->SetBranchAddress("triggerHLTJet15U", &triggerHLTJet15U, &b_triggerHLTJet15U);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("lumiBlockNumber", &lumiBlockNumber, &b_lumiBlockNumber);
   fChain->SetBranchAddress("numberOfPrimaryVertices", &numberOfPrimaryVertices, &b_numberOfPrimaryVertices);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("jetPt", jetPt, &b_jetPt);
   fChain->SetBranchAddress("jetEta", jetEta, &b_jetEta);
   fChain->SetBranchAddress("jetPhi", jetPhi, &b_jetPhi);
   fChain->SetBranchAddress("jetEMFraction", jetEMFraction, &b_jetEMFraction);
   fChain->SetBranchAddress("jetChargedEmEnergyFraction", jetChargedEmEnergyFraction, &b_jetChargedEmEnergyFraction);
   fChain->SetBranchAddress("jetNeutralEmEnergyFraction", jetNeutralEmEnergyFraction, &b_jetNeutralEmEnergyFraction);
   fChain->SetBranchAddress("jetChargedHadronEnergyFraction", jetChargedHadronEnergyFraction, &b_jetChargedHadronEnergyFraction);
   fChain->SetBranchAddress("jetNeutralHadronEnergyFraction", jetNeutralHadronEnergyFraction, &b_jetNeutralHadronEnergyFraction);
   fChain->SetBranchAddress("jetChargedMultiplicity", jetChargedMultiplicity, &b_jetChargedMultiplicity);
   fChain->SetBranchAddress("jetMass", jetMass, &b_jetMass);
   fChain->SetBranchAddress("jetnConstituents", jetnConstituents, &b_jetnConstituents);
   fChain->SetBranchAddress("jetnTracks", jetnTracks, &b_jetnTracks);
   fChain->SetBranchAddress("jetVertexChi2", jetVertexChi2, &b_jetVertexChi2);
   fChain->SetBranchAddress("jetVertexChi2Ndof", jetVertexChi2Ndof, &b_jetVertexChi2Ndof);
   fChain->SetBranchAddress("jetVertexNormalizedChi2", jetVertexNormalizedChi2, &b_jetVertexNormalizedChi2);
   fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
   fChain->SetBranchAddress("trackJetIndex", trackJetIndex, &b_trackJetIndex);
   fChain->SetBranchAddress("trackSelected", trackSelected, &b_trackSelected);
   fChain->SetBranchAddress("trackTransverseMomentum", trackTransverseMomentum, &b_trackTransverseMomentum);
   fChain->SetBranchAddress("trackEta", trackEta, &b_trackEta);
   fChain->SetBranchAddress("trackPhi", trackPhi, &b_trackPhi);
   fChain->SetBranchAddress("trackMomentum", trackMomentum, &b_trackMomentum);
   fChain->SetBranchAddress("trackNHits", trackNHits, &b_trackNHits);
   fChain->SetBranchAddress("trackNPixelHits", trackNPixelHits, &b_trackNPixelHits);
   fChain->SetBranchAddress("trackChi2", trackChi2, &b_trackChi2);
   fChain->SetBranchAddress("trackNormChi2", trackNormChi2, &b_trackNormChi2);
   fChain->SetBranchAddress("trackQuality", trackQuality, &b_trackQuality);
   fChain->SetBranchAddress("trackLongitudinalImpactParameter", trackLongitudinalImpactParameter, &b_trackLongitudinalImpactParameter);
   fChain->SetBranchAddress("trackIP", trackIP, &b_trackIP);
   fChain->SetBranchAddress("trackDecayLength", trackDecayLength, &b_trackDecayLength);
   fChain->SetBranchAddress("trackDistJetAxis", trackDistJetAxis, &b_trackDistJetAxis);
   fChain->SetBranchAddress("trackDeltaR", trackDeltaR, &b_trackDeltaR);
   fChain->SetBranchAddress("trackIP3d", trackIP3d, &b_trackIP3d);
   fChain->SetBranchAddress("trackIP2d", trackIP2d, &b_trackIP2d);
   fChain->SetBranchAddress("trackIP3dError", trackIP3dError, &b_trackIP3dError);
   fChain->SetBranchAddress("trackIP2dError", trackIP2dError, &b_trackIP2dError);
   fChain->SetBranchAddress("trackHasSharedPix1", trackHasSharedPix1, &b_trackHasSharedPix1);
   fChain->SetBranchAddress("trackHasSharedPix2", trackHasSharedPix2, &b_trackHasSharedPix2);
   fChain->SetBranchAddress("trackHasSharedPix3", trackHasSharedPix3, &b_trackHasSharedPix3);
   fChain->SetBranchAddress("trackHasSharedPixAll", trackHasSharedPixAll, &b_trackHasSharedPixAll);
   fChain->SetBranchAddress("MCTrueFlavor", MCTrueFlavor, &b_MCTrueFlavor);
   fChain->SetBranchAddress("SV3dDistance", SV3dDistance, &b_SV3dDistance);
   fChain->SetBranchAddress("SV3dDistanceError", SV3dDistanceError, &b_SV3dDistanceError);
   fChain->SetBranchAddress("SV2dDistance", SV2dDistance, &b_SV2dDistance);
   fChain->SetBranchAddress("SV2dDistanceError", SV2dDistanceError, &b_SV2dDistanceError);
   fChain->SetBranchAddress("SVChi2", SVChi2, &b_SVChi2);
   fChain->SetBranchAddress("SVIPFirstAboveCharm", SVIPFirstAboveCharm, &b_SVIPFirstAboveCharm);
   fChain->SetBranchAddress("SVDegreesOfFreedom", SVDegreesOfFreedom, &b_SVDegreesOfFreedom);
   fChain->SetBranchAddress("SVNormChi2", SVNormChi2, &b_SVNormChi2);
   fChain->SetBranchAddress("SVnSelectedTracks", SVnSelectedTracks, &b_SVnSelectedTracks);
   fChain->SetBranchAddress("SVMass", SVMass, &b_SVMass);
   fChain->SetBranchAddress("SVEnergyRatio", SVEnergyRatio, &b_SVEnergyRatio);
   fChain->SetBranchAddress("SVnVertices", SVnVertices, &b_SVnVertices);
   fChain->SetBranchAddress("SVnVertexTracks", SVnVertexTracks, &b_SVnVertexTracks);
   fChain->SetBranchAddress("SVnVertexTracksAll", SVnVertexTracksAll, &b_SVnVertexTracksAll);
   fChain->SetBranchAddress("SVnFirstVertexTracks", SVnFirstVertexTracks, &b_SVnFirstVertexTracks);
   fChain->SetBranchAddress("SVnFirstVertexTracksAll", SVnFirstVertexTracksAll, &b_SVnFirstVertexTracksAll);
   fChain->SetBranchAddress("SVjetDeltaR", SVjetDeltaR, &b_SVjetDeltaR);
   fChain->SetBranchAddress("SVvtxSumVtxDirDeltaR", SVvtxSumVtxDirDeltaR, &b_SVvtxSumVtxDirDeltaR);
   fChain->SetBranchAddress("SVvtxSumJetDeltaR", SVvtxSumJetDeltaR, &b_SVvtxSumJetDeltaR);
   fChain->SetBranchAddress("IPnSelectedTracks", IPnSelectedTracks, &b_IPnSelectedTracks);
   fChain->SetBranchAddress("IPghostTrackPt", IPghostTrackPt, &b_IPghostTrackPt);
   fChain->SetBranchAddress("IPghostTrackPtRel", IPghostTrackPtRel, &b_IPghostTrackPtRel);
   fChain->SetBranchAddress("IPghostTrackEta", IPghostTrackEta, &b_IPghostTrackEta);
   fChain->SetBranchAddress("IPghostTrackPhi", IPghostTrackPhi, &b_IPghostTrackPhi);
   fChain->SetBranchAddress("IPghostTrackDeltaR", IPghostTrackDeltaR, &b_IPghostTrackDeltaR);
   fChain->SetBranchAddress("IPPix1SharedHits", IPPix1SharedHits, &b_IPPix1SharedHits);
   fChain->SetBranchAddress("IPPix1TotalHits", IPPix1TotalHits, &b_IPPix1TotalHits);
   fChain->SetBranchAddress("IPPix2SharedHits", IPPix2SharedHits, &b_IPPix2SharedHits);
   fChain->SetBranchAddress("IPPix2TotalHits", IPPix2TotalHits, &b_IPPix2TotalHits);
   fChain->SetBranchAddress("IPPix3SharedHits", IPPix3SharedHits, &b_IPPix3SharedHits);
   fChain->SetBranchAddress("IPPix3TotalHits", IPPix3TotalHits, &b_IPPix3TotalHits);
   fChain->SetBranchAddress("IPPixAllSharedHits", IPPixAllSharedHits, &b_IPPixAllSharedHits);
   fChain->SetBranchAddress("IPPixAllTotalHits", IPPixAllTotalHits, &b_IPPixAllTotalHits);
   fChain->SetBranchAddress("IP3dTrackQuality1", IP3dTrackQuality1, &b_IP3dTrackQuality1);
   fChain->SetBranchAddress("IP3dHasSharedPix11", IP3dHasSharedPix11, &b_IP3dHasSharedPix11);
   fChain->SetBranchAddress("IP3dHasSharedPix21", IP3dHasSharedPix21, &b_IP3dHasSharedPix21);
   fChain->SetBranchAddress("IP3dHasSharedPix31", IP3dHasSharedPix31, &b_IP3dHasSharedPix31);
   fChain->SetBranchAddress("IP3dHasSharedPixAll1", IP3dHasSharedPixAll1, &b_IP3dHasSharedPixAll1);
   fChain->SetBranchAddress("IP3d1", IP3d1, &b_IP3d1);
   fChain->SetBranchAddress("IP3dError1", IP3dError1, &b_IP3dError1);
   fChain->SetBranchAddress("IP3dProbability1", IP3dProbability1, &b_IP3dProbability1);
   fChain->SetBranchAddress("IP3dTrackPtRel1", IP3dTrackPtRel1, &b_IP3dTrackPtRel1);
   fChain->SetBranchAddress("IP3dDistJetAxis1", IP3dDistJetAxis1, &b_IP3dDistJetAxis1);
   fChain->SetBranchAddress("IP3dDecayLength1", IP3dDecayLength1, &b_IP3dDecayLength1);
   fChain->SetBranchAddress("IP3dDeltaR1", IP3dDeltaR1, &b_IP3dDeltaR1);
   fChain->SetBranchAddress("IP3dMomentum1", IP3dMomentum1, &b_IP3dMomentum1);
   fChain->SetBranchAddress("IP3dTransverseMomentum1", IP3dTransverseMomentum1, &b_IP3dTransverseMomentum1);
   fChain->SetBranchAddress("IP3dEta1", IP3dEta1, &b_IP3dEta1);
   fChain->SetBranchAddress("IP3dPhi1", IP3dPhi1, &b_IP3dPhi1);
   fChain->SetBranchAddress("IP3dNHits1", IP3dNHits1, &b_IP3dNHits1);
   fChain->SetBranchAddress("IP3dNPixelHits1", IP3dNPixelHits1, &b_IP3dNPixelHits1);
   fChain->SetBranchAddress("IP3dNormChi21", IP3dNormChi21, &b_IP3dNormChi21);
   fChain->SetBranchAddress("IP2dTrackQuality1", IP2dTrackQuality1, &b_IP2dTrackQuality1);
   fChain->SetBranchAddress("IP2d1", IP2d1, &b_IP2d1);
   fChain->SetBranchAddress("IP2dError1", IP2dError1, &b_IP2dError1);
   fChain->SetBranchAddress("IP2dProbability1", IP2dProbability1, &b_IP2dProbability1);
   fChain->SetBranchAddress("IP2dTrackPtRel1", IP2dTrackPtRel1, &b_IP2dTrackPtRel1);
   fChain->SetBranchAddress("IP3dTrackQuality2", IP3dTrackQuality2, &b_IP3dTrackQuality2);
   fChain->SetBranchAddress("IP3dHasSharedPix12", IP3dHasSharedPix12, &b_IP3dHasSharedPix12);
   fChain->SetBranchAddress("IP3dHasSharedPix22", IP3dHasSharedPix22, &b_IP3dHasSharedPix22);
   fChain->SetBranchAddress("IP3dHasSharedPix32", IP3dHasSharedPix32, &b_IP3dHasSharedPix32);
   fChain->SetBranchAddress("IP3dHasSharedPixAll2", IP3dHasSharedPixAll2, &b_IP3dHasSharedPixAll2);
   fChain->SetBranchAddress("IP3d2", IP3d2, &b_IP3d2);
   fChain->SetBranchAddress("IP3dError2", IP3dError2, &b_IP3dError2);
   fChain->SetBranchAddress("IP3dProbability2", IP3dProbability2, &b_IP3dProbability2);
   fChain->SetBranchAddress("IP3dTrackPtRel2", IP3dTrackPtRel2, &b_IP3dTrackPtRel2);
   fChain->SetBranchAddress("IP3dDistJetAxis2", IP3dDistJetAxis2, &b_IP3dDistJetAxis2);
   fChain->SetBranchAddress("IP3dDecayLength2", IP3dDecayLength2, &b_IP3dDecayLength2);
   fChain->SetBranchAddress("IP3dDeltaR2", IP3dDeltaR2, &b_IP3dDeltaR2);
   fChain->SetBranchAddress("IP3dMomentum2", IP3dMomentum2, &b_IP3dMomentum2);
   fChain->SetBranchAddress("IP3dTransverseMomentum2", IP3dTransverseMomentum2, &b_IP3dTransverseMomentum2);
   fChain->SetBranchAddress("IP3dEta2", IP3dEta2, &b_IP3dEta2);
   fChain->SetBranchAddress("IP3dPhi2", IP3dPhi2, &b_IP3dPhi2);
   fChain->SetBranchAddress("IP3dNHits2", IP3dNHits2, &b_IP3dNHits2);
   fChain->SetBranchAddress("IP3dNPixelHits2", IP3dNPixelHits2, &b_IP3dNPixelHits2);
   fChain->SetBranchAddress("IP3dNormChi22", IP3dNormChi22, &b_IP3dNormChi22);
   fChain->SetBranchAddress("IP2dTrackQuality2", IP2dTrackQuality2, &b_IP2dTrackQuality2);
   fChain->SetBranchAddress("IP2d2", IP2d2, &b_IP2d2);
   fChain->SetBranchAddress("IP2dError2", IP2dError2, &b_IP2dError2);
   fChain->SetBranchAddress("IP2dProbability2", IP2dProbability2, &b_IP2dProbability2);
   fChain->SetBranchAddress("IP2dTrackPtRel2", IP2dTrackPtRel2, &b_IP2dTrackPtRel2);
   fChain->SetBranchAddress("IP3dTrackQuality3", IP3dTrackQuality3, &b_IP3dTrackQuality3);
   fChain->SetBranchAddress("IP3dHasSharedPix13", IP3dHasSharedPix13, &b_IP3dHasSharedPix13);
   fChain->SetBranchAddress("IP3dHasSharedPix23", IP3dHasSharedPix23, &b_IP3dHasSharedPix23);
   fChain->SetBranchAddress("IP3dHasSharedPix33", IP3dHasSharedPix33, &b_IP3dHasSharedPix33);
   fChain->SetBranchAddress("IP3dHasSharedPixAll3", IP3dHasSharedPixAll3, &b_IP3dHasSharedPixAll3);
   fChain->SetBranchAddress("IP3d3", IP3d3, &b_IP3d3);
   fChain->SetBranchAddress("IP3dError3", IP3dError3, &b_IP3dError3);
   fChain->SetBranchAddress("IP3dProbability3", IP3dProbability3, &b_IP3dProbability3);
   fChain->SetBranchAddress("IP3dTrackPtRel3", IP3dTrackPtRel3, &b_IP3dTrackPtRel3);
   fChain->SetBranchAddress("IP3dDistJetAxis3", IP3dDistJetAxis3, &b_IP3dDistJetAxis3);
   fChain->SetBranchAddress("IP3dDecayLength3", IP3dDecayLength3, &b_IP3dDecayLength3);
   fChain->SetBranchAddress("IP3dDeltaR3", IP3dDeltaR3, &b_IP3dDeltaR3);
   fChain->SetBranchAddress("IP3dMomentum3", IP3dMomentum3, &b_IP3dMomentum3);
   fChain->SetBranchAddress("IP3dTransverseMomentum3", IP3dTransverseMomentum3, &b_IP3dTransverseMomentum3);
   fChain->SetBranchAddress("IP3dEta3", IP3dEta3, &b_IP3dEta3);
   fChain->SetBranchAddress("IP3dPhi3", IP3dPhi3, &b_IP3dPhi3);
   fChain->SetBranchAddress("IP3dNHits3", IP3dNHits3, &b_IP3dNHits3);
   fChain->SetBranchAddress("IP3dNPixelHits3", IP3dNPixelHits3, &b_IP3dNPixelHits3);
   fChain->SetBranchAddress("IP3dNormChi23", IP3dNormChi23, &b_IP3dNormChi23);
   fChain->SetBranchAddress("IP2dTrackQuality3", IP2dTrackQuality3, &b_IP2dTrackQuality3);
   fChain->SetBranchAddress("IP2d3", IP2d3, &b_IP2d3);
   fChain->SetBranchAddress("IP2dError3", IP2dError3, &b_IP2dError3);
   fChain->SetBranchAddress("IP2dProbability3", IP2dProbability3, &b_IP2dProbability3);
   fChain->SetBranchAddress("IP2dTrackPtRel3", IP2dTrackPtRel3, &b_IP2dTrackPtRel3);
   fChain->SetBranchAddress("IP3dTrackQuality4", IP3dTrackQuality4, &b_IP3dTrackQuality4);
   fChain->SetBranchAddress("IP3dHasSharedPix14", IP3dHasSharedPix14, &b_IP3dHasSharedPix14);
   fChain->SetBranchAddress("IP3dHasSharedPix24", IP3dHasSharedPix24, &b_IP3dHasSharedPix24);
   fChain->SetBranchAddress("IP3dHasSharedPix34", IP3dHasSharedPix34, &b_IP3dHasSharedPix34);
   fChain->SetBranchAddress("IP3dHasSharedPixAll4", IP3dHasSharedPixAll4, &b_IP3dHasSharedPixAll4);
   fChain->SetBranchAddress("IP3d4", IP3d4, &b_IP3d4);
   fChain->SetBranchAddress("IP3dError4", IP3dError4, &b_IP3dError4);
   fChain->SetBranchAddress("IP3dProbability4", IP3dProbability4, &b_IP3dProbability4);
   fChain->SetBranchAddress("IP3dTrackPtRel4", IP3dTrackPtRel4, &b_IP3dTrackPtRel4);
   fChain->SetBranchAddress("IP3dDistJetAxis4", IP3dDistJetAxis4, &b_IP3dDistJetAxis4);
   fChain->SetBranchAddress("IP3dDecayLength4", IP3dDecayLength4, &b_IP3dDecayLength4);
   fChain->SetBranchAddress("IP3dDeltaR4", IP3dDeltaR4, &b_IP3dDeltaR4);
   fChain->SetBranchAddress("IP3dMomentum4", IP3dMomentum4, &b_IP3dMomentum4);
   fChain->SetBranchAddress("IP3dTransverseMomentum4", IP3dTransverseMomentum4, &b_IP3dTransverseMomentum4);
   fChain->SetBranchAddress("IP3dEta4", IP3dEta4, &b_IP3dEta4);
   fChain->SetBranchAddress("IP3dPhi4", IP3dPhi4, &b_IP3dPhi4);
   fChain->SetBranchAddress("IP3dNHits4", IP3dNHits4, &b_IP3dNHits4);
   fChain->SetBranchAddress("IP3dNPixelHits4", IP3dNPixelHits4, &b_IP3dNPixelHits4);
   fChain->SetBranchAddress("IP3dNormChi24", IP3dNormChi24, &b_IP3dNormChi24);
   fChain->SetBranchAddress("IP2dTrackQuality4", IP2dTrackQuality4, &b_IP2dTrackQuality4);
   fChain->SetBranchAddress("IP2d4", IP2d4, &b_IP2d4);
   fChain->SetBranchAddress("IP2dError4", IP2dError4, &b_IP2dError4);
   fChain->SetBranchAddress("IP2dProbability4", IP2dProbability4, &b_IP2dProbability4);
   fChain->SetBranchAddress("IP2dTrackPtRel4", IP2dTrackPtRel4, &b_IP2dTrackPtRel4);
   fChain->SetBranchAddress("nElectrons", nElectrons, &b_nElectrons);
   fChain->SetBranchAddress("electronPt", electronPt, &b_electronPt);
   fChain->SetBranchAddress("electronEta", electronEta, &b_electronEta);
   fChain->SetBranchAddress("electronPhi", electronPhi, &b_electronPhi);
   fChain->SetBranchAddress("electronNHits", electronNHits, &b_electronNHits);
   fChain->SetBranchAddress("electronNExpectedOuterHits", electronNExpectedOuterHits, &b_electronNExpectedOuterHits);
   fChain->SetBranchAddress("electronNPixelHits", electronNPixelHits, &b_electronNPixelHits);
   fChain->SetBranchAddress("electronNChi2", electronNChi2, &b_electronNChi2);
   fChain->SetBranchAddress("electronPtRel", electronPtRel, &b_electronPtRel);
   fChain->SetBranchAddress("electronSip2d", electronSip2d, &b_electronSip2d);
   fChain->SetBranchAddress("electronIp2d", electronIp2d, &b_electronIp2d);
   fChain->SetBranchAddress("electronIpe2d", electronIpe2d, &b_electronIpe2d);
   fChain->SetBranchAddress("electronSip3d", electronSip3d, &b_electronSip3d);
   fChain->SetBranchAddress("electronIp3d", electronIp3d, &b_electronIp3d);
   fChain->SetBranchAddress("electronIpe3d", electronIpe3d, &b_electronIpe3d);
   fChain->SetBranchAddress("electronP0Par", electronP0Par, &b_electronP0Par);
   fChain->SetBranchAddress("electronDeltaR", electronDeltaR, &b_electronDeltaR);
   fChain->SetBranchAddress("electronEtaRel", electronEtaRel, &b_electronEtaRel);
   fChain->SetBranchAddress("electronRatio", electronRatio, &b_electronRatio);
   fChain->SetBranchAddress("electronTrackQuality", electronTrackQuality, &b_electronTrackQuality);
   fChain->SetBranchAddress("electronRatioRel", electronRatioRel, &b_electronRatioRel);
   fChain->SetBranchAddress("nMuons", nMuons, &b_nMuons);
   fChain->SetBranchAddress("muonPt", muonPt, &b_muonPt);
   fChain->SetBranchAddress("muonEta", muonEta, &b_muonEta);
   fChain->SetBranchAddress("muonPhi", muonPhi, &b_muonPhi);
   fChain->SetBranchAddress("muonNHits", muonNHits, &b_muonNHits);
   fChain->SetBranchAddress("muonNExpectedOuterHits", muonNExpectedOuterHits, &b_muonNExpectedOuterHits);
   fChain->SetBranchAddress("muonNPixelHits", muonNPixelHits, &b_muonNPixelHits);
   fChain->SetBranchAddress("muonNChi2", muonNChi2, &b_muonNChi2);
   fChain->SetBranchAddress("muonPtRel", muonPtRel, &b_muonPtRel);
   fChain->SetBranchAddress("muonSip2d", muonSip2d, &b_muonSip2d);
   fChain->SetBranchAddress("muonIp2d", muonIp2d, &b_muonIp2d);
   fChain->SetBranchAddress("muonIpe2d", muonIpe2d, &b_muonIpe2d);
   fChain->SetBranchAddress("muonSip3d", muonSip3d, &b_muonSip3d);
   fChain->SetBranchAddress("muonIp3d", muonIp3d, &b_muonIp3d);
   fChain->SetBranchAddress("muonIpe3d", muonIpe3d, &b_muonIpe3d);
   fChain->SetBranchAddress("muonP0Par", muonP0Par, &b_muonP0Par);
   fChain->SetBranchAddress("muonDeltaR", muonDeltaR, &b_muonDeltaR);
   fChain->SetBranchAddress("muonEtaRel", muonEtaRel, &b_muonEtaRel);
   fChain->SetBranchAddress("muonRatio", muonRatio, &b_muonRatio);
   fChain->SetBranchAddress("muonTrackQuality", muonTrackQuality, &b_muonTrackQuality);
   fChain->SetBranchAddress("muonRatioRel", muonRatioRel, &b_muonRatioRel);
   fChain->SetBranchAddress("standardCombinedSecondaryVertexMVAPFBJetTags", standardCombinedSecondaryVertexMVAPFBJetTags, &b_standardCombinedSecondaryVertexMVAPFBJetTags);
   fChain->SetBranchAddress("standardCombinedSecondaryVertexPFBJetTags", standardCombinedSecondaryVertexPFBJetTags, &b_standardCombinedSecondaryVertexPFBJetTags);
   fChain->SetBranchAddress("standardGhostTrackPFBJetTags", standardGhostTrackPFBJetTags, &b_standardGhostTrackPFBJetTags);
   fChain->SetBranchAddress("standardJetBProbabilityPFBJetTags", standardJetBProbabilityPFBJetTags, &b_standardJetBProbabilityPFBJetTags);
   fChain->SetBranchAddress("standardJetProbabilityPFBJetTags", standardJetProbabilityPFBJetTags, &b_standardJetProbabilityPFBJetTags);
   fChain->SetBranchAddress("standardSimpleSecondaryVertexHighEffPFBJetTags", standardSimpleSecondaryVertexHighEffPFBJetTags, &b_standardSimpleSecondaryVertexHighEffPFBJetTags);
   fChain->SetBranchAddress("standardSimpleSecondaryVertexHighPurPFBJetTags", standardSimpleSecondaryVertexHighPurPFBJetTags, &b_standardSimpleSecondaryVertexHighPurPFBJetTags);
   fChain->SetBranchAddress("standardSoftElectronByIP3dPFBJetTags", standardSoftElectronByIP3dPFBJetTags, &b_standardSoftElectronByIP3dPFBJetTags);
   fChain->SetBranchAddress("standardSoftElectronByPtPFBJetTags", standardSoftElectronByPtPFBJetTags, &b_standardSoftElectronByPtPFBJetTags);
   fChain->SetBranchAddress("standardSoftMuonByIP3dPFBJetTags", standardSoftMuonByIP3dPFBJetTags, &b_standardSoftMuonByIP3dPFBJetTags);
   fChain->SetBranchAddress("standardSoftMuonByPtPFBJetTags", standardSoftMuonByPtPFBJetTags, &b_standardSoftMuonByPtPFBJetTags);
   fChain->SetBranchAddress("standardSoftMuonPFBJetTags", standardSoftMuonPFBJetTags, &b_standardSoftMuonPFBJetTags);
   fChain->SetBranchAddress("standardTrackCountingHighEffPFBJetTags", standardTrackCountingHighEffPFBJetTags, &b_standardTrackCountingHighEffPFBJetTags);
   fChain->SetBranchAddress("standardTrackCountingHighPurPFBJetTags", standardTrackCountingHighPurPFBJetTags, &b_standardTrackCountingHighPurPFBJetTags);
}

Bool_t TrackSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef TrackSelector_cxx
