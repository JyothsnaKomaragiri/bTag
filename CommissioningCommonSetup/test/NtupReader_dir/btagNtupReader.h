/////////////////////////////////////////////////////////////////
// Author : Caroline Collard (IPHC) - first commit : april 2011
////////////////////////////////////////////////////////////////

#ifndef btagNtupReader_h
#define btagNtupReader_h


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class btagNtupReader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   int dataflag;


   // Declaration of leaf types
   Bool_t          triggerHLTL1Jet6U;
   Bool_t          triggerHLTL1Jet10U;
   Bool_t          triggerHLTJet15U;
   Bool_t          triggerHLTJet30U;
   Bool_t          triggerHLTJet50U;
   Bool_t          triggerHLTJet70U;
   Bool_t          triggerHLTJet100U;
   Bool_t          triggerHLTBTagIPJet50U;
   Bool_t          triggerHLTBTagMuJet10U;
   Bool_t          triggerHLTBTagMuJet20U;
   Bool_t          triggerHLTBTagMuDiJet10U;
   Bool_t          triggerHLTBTagMuDiJet20U;
   Bool_t          triggerHLTBTagMuDiJet20UMu5;
   Bool_t          triggerHLTBTagMuDiJet30U;
   Bool_t          triggerHLTBTagMuDiJet30UMu5;
   Int_t           prescaleHLTL1Jet6U;
   Int_t           prescaleHLTL1Jet10U;
   Int_t           prescaleHLTJet15U;
   Int_t           prescaleHLTJet30U;
   Int_t           prescaleHLTJet50U;
   Int_t           prescaleHLTJet70U;
   Int_t           prescaleHLTJet100U;
   Int_t           prescaleHLTBTagIPJet50U;
   Int_t           prescaleHLTBTagMuJet10U;
   Int_t           prescaleHLTBTagMuJet20U;
   Int_t           prescaleHLTBTagMuDiJet10U;
   Int_t           prescaleHLTBTagMuDiJet20U;
   Int_t           prescaleHLTBTagMuDiJet20UMu5;
   Int_t           prescaleHLTBTagMuDiJet30U;
   Int_t           prescaleHLTBTagMuDiJet30UMu5;
   Bool_t          triggerHLT_L1SingleJet36;
   Bool_t          triggerHLT_Jet30;
   Bool_t          triggerHLT_Jet60;
   Bool_t          triggerHLT_Jet80;
   Bool_t          triggerHLT_Jet110;
   Bool_t          triggerHLT_Jet150;
   Bool_t          triggerHLT_Jet190;
   Bool_t          triggerHLT_Jet240;
   Bool_t          triggerHLT_Jet370;
   Bool_t          triggerHLT_Jet370_NoJetID;
   Int_t           prescaleHLT_L1SingleJet36;
   Int_t           prescaleHLT_Jet30;
   Int_t           prescaleHLT_Jet60;
   Int_t           prescaleHLT_Jet80;
   Int_t           prescaleHLT_Jet110;
   Int_t           prescaleHLT_Jet150;
   Int_t           prescaleHLT_Jet190;
   Int_t           prescaleHLT_Jet240;
   Int_t           prescaleHLT_Jet370;
   Int_t           prescaleHLT_Jet370_NoJetID;
   Bool_t          triggerHLT_DiJetAve15U_v4;
   Bool_t          triggerHLT_DiJetAve30U_v4;
   Bool_t          triggerHLT_DiJetAve50U_v4;
   Bool_t          triggerHLT_DiJetAve70U_v4;
   Bool_t          triggerHLT_DiJetAve100U_v4;
   Bool_t          triggerHLT_DiJetAve140U_v4;
   Bool_t          triggerHLT_DiJetAve180U_v4;
   Bool_t          triggerHLT_DiJetAve300U_v4;
   Bool_t          triggerHLT_BTagMu_DiJet20_Mu5_v2;
   Bool_t          triggerHLT_BTagMu_DiJet60_Mu7_v2;
   Bool_t          triggerHLT_BTagMu_DiJet80_Mu9_v2;
   Bool_t          triggerHLT_BTagMu_DiJet100_Mu9_v2;
   Int_t           prescaleHLT_DiJetAve15U_v4;
   Int_t           prescaleHLT_DiJetAve30U_v4;
   Int_t           prescaleHLT_DiJetAve50U_v4;
   Int_t           prescaleHLT_DiJetAve70U_v4;
   Int_t           prescaleHLT_DiJetAve100U_v4;
   Int_t           prescaleHLT_DiJetAve140U_v4;
   Int_t           prescaleHLT_DiJetAve180U_v4;
   Int_t           prescaleHLT_DiJetAve300U_v4;
   Int_t           prescaleHLT_BTagMu_DiJet20_Mu5_v2;
   Int_t           prescaleHLT_BTagMu_DiJet60_Mu7_v2;
   Int_t           prescaleHLT_BTagMu_DiJet80_Mu9_v2;
   Int_t           prescaleHLT_BTagMu_DiJet100_Mu9_v2;

   UInt_t          eventNumber;
   UInt_t          runNumber;
   UInt_t          lumiBlockNumber;
   UInt_t          numberOfPUVertices;
   UInt_t          numberOfPrimaryVertices;
   UInt_t          numberOfTracksAtPV;
   Float_t         PVx;
   Float_t         PVy;
   Float_t         PVz;
   Float_t         PVChi2;
   Float_t         PVndof;
   Float_t         PVNormalizedChi2;
   Float_t         pthat;
   Bool_t          isBGluonSplitting;
   Bool_t          isCGluonSplitting;
   Int_t           nJets;
   Float_t         jetPt[30];   //[nJets]
   Float_t         jetEta[30];   //[nJets]
   Float_t         jetPhi[30];   //[nJets]
   Float_t         jetEMFraction[30];   //[nJets]
   Float_t         jetChargedEmEnergyFraction[30];   //[nJets]
   Float_t         jetNeutralEmEnergyFraction[30];   //[nJets]
   Float_t         jetChargedHadronEnergyFraction[30];   //[nJets]
   Float_t         jetNeutralHadronEnergyFraction[30];   //[nJets]
   Float_t         jetChargedMultiplicity[30];   //[nJets]
   Float_t         jetMass[30];   //[nJets]
   Int_t           jetnConstituents[30];   //[nJets]
   Int_t           jetnTracks[30];   //[nJets]
   Float_t         jetVertexChi2[30];   //[nJets]
   Float_t         jetVertexChi2Ndof[30];   //[nJets]
   Float_t         jetVertexNormalizedChi2[30];   //[nJets]
   Int_t           nTracks;
   Int_t           trackJetIndex[500];   //[nTracks]
   Bool_t          trackSelected[500];   //[nTracks]
   Float_t         trackTransverseMomentum[500];   //[nTracks]
   Float_t         trackEta[500];   //[nTracks]
   Float_t         trackPhi[500];   //[nTracks]
   Float_t         trackMomentum[500];   //[nTracks]
   Int_t           trackNHits[500];   //[nTracks]
   Int_t           trackNPixelHits[500];   //[nTracks]
   Float_t         trackChi2[500];   //[nTracks]
   Float_t         trackNormChi2[500];   //[nTracks]
   Int_t           trackQuality[500];   //[nTracks]
   Float_t         trackLongitudinalImpactParameter[500];   //[nTracks]
   Float_t         trackIP[500];   //[nTracks]
   Float_t         trackDecayLength[500];   //[nTracks]
   Float_t         trackDistJetAxis[500];   //[nTracks]
   Float_t         trackDeltaR[500];   //[nTracks]
   Float_t         trackIP3d[500];   //[nTracks]
   Float_t         trackIP2d[500];   //[nTracks]
   Float_t         trackIP3dError[500];   //[nTracks]
   Float_t         trackIP2dError[500];   //[nTracks]
   Int_t           trackHasSharedPix1[500];   //[nTracks]
   Int_t           trackHasSharedPix2[500];   //[nTracks]
   Int_t           trackHasSharedPix3[500];   //[nTracks]
   Int_t           trackHasSharedPixAll[500];   //[nTracks]
   Bool_t          trackIsVertexTrack[500];   //[nTracks]
   Int_t           MCTrueFlavor[30];   //[nJets]
   Float_t         SV3dDistance[30];   //[nJets]
   Float_t         SV3dDistanceError[30];   //[nJets]
   Float_t         SV2dDistance[30];   //[nJets]
   Float_t         SV2dDistanceError[30];   //[nJets]
   Float_t         SVChi2[30];   //[nJets]
   Float_t         SVIPFirstAboveCharm[30];   //[nJets]
   Float_t         SVDegreesOfFreedom[30];   //[nJets]
   Float_t         SVNormChi2[30];   //[nJets]
   Int_t           SVnSelectedTracks[30];   //[nJets]
   Float_t         SVMass[30];   //[nJets]
   Float_t         SVEnergyRatio[30];   //[nJets]
   Int_t           SVnVertices[30];   //[nJets]
   Int_t           SVnVertexTracks[30];   //[nJets]
   Int_t           SVnVertexTracksAll[30];   //[nJets]
   Int_t           SVnFirstVertexTracks[30];   //[nJets]
   Int_t           SVnFirstVertexTracksAll[30];   //[nJets]
   Float_t         SVjetDeltaR[30];   //[nJets]
   Float_t         SVvtxSumVtxDirDeltaR[30];   //[nJets]
   Float_t         SVvtxSumJetDeltaR[30];   //[nJets]
   Float_t         SVvtxPt[30];   //[nJets]
   Float_t         SVvtxSumDirEta[30];   //[nJets]
   Float_t         SVvtxSumDirPhi[30];   //[nJets]
   Float_t         SVvtxDirEta[30];   //[nJets]
   Float_t         SVvtxDirPhi[30];   //[nJets]
   Float_t         SVvtxSumPTrel[30];   //[nJets]
   Float_t         SVvtxDirPTrel[30];   //[nJets]
   Float_t         SVvtxDistJetAxis[30];   //[nJets]
   Int_t           SVtotCharge[30];   //[nJets]
   Int_t           IPnSelectedTracks[30];   //[nJets]
   Float_t         IPghostTrackPt[30];   //[nJets]
   Float_t         IPghostTrackPtRel[30];   //[nJets]
   Float_t         IPghostTrackEta[30];   //[nJets]
   Float_t         IPghostTrackPhi[30];   //[nJets]
   Float_t         IPghostTrackDeltaR[30];   //[nJets]
   Int_t           IPPix1SharedHits[30];   //[nJets]
   Int_t           IPPix1TotalHits[30];   //[nJets]
   Int_t           IPPix2SharedHits[30];   //[nJets]
   Int_t           IPPix2TotalHits[30];   //[nJets]
   Int_t           IPPix3SharedHits[30];   //[nJets]
   Int_t           IPPix3TotalHits[30];   //[nJets]
   Int_t           IPPixAllSharedHits[30];   //[nJets]
   Int_t           IPPixAllTotalHits[30];   //[nJets]
   Int_t           IP3dTrackQuality1[30];   //[nJets]
   Int_t           IP3dHasSharedPix11[30];   //[nJets]
   Int_t           IP3dHasSharedPix21[30];   //[nJets]
   Int_t           IP3dHasSharedPix31[30];   //[nJets]
   Int_t           IP3dHasSharedPixAll1[30];   //[nJets]
   Float_t         IP3d1[30];   //[nJets]
   Float_t         IP3dError1[30];   //[nJets]
   Float_t         IP3dProbability1[30];   //[nJets]
   Float_t         IP3dTrackPtRel1[30];   //[nJets]
   Float_t         IP3dDistJetAxis1[30];   //[nJets]
   Float_t         IP3dDecayLength1[30];   //[nJets]
   Float_t         IP3dDeltaR1[30];   //[nJets]
   Float_t         IP3dMomentum1[30];   //[nJets]
   Float_t         IP3dTransverseMomentum1[30];   //[nJets]
   Float_t         IP3dEta1[30];   //[nJets]
   Float_t         IP3dPhi1[30];   //[nJets]
   Int_t           IP3dNHits1[30];   //[nJets]
   Int_t           IP3dNPixelHits1[30];   //[nJets]
   Float_t         IP3dNormChi21[30];   //[nJets]
   Int_t           IP2dTrackQuality1[30];   //[nJets]
   Float_t         IP2d1[30];   //[nJets]
   Float_t         IP2dError1[30];   //[nJets]
   Float_t         IP2dProbability1[30];   //[nJets]
   Float_t         IP2dTrackPtRel1[30];   //[nJets]
   Int_t           IP3dTrackQuality2[30];   //[nJets]
   Int_t           IP3dHasSharedPix12[30];   //[nJets]
   Int_t           IP3dHasSharedPix22[30];   //[nJets]
   Int_t           IP3dHasSharedPix32[30];   //[nJets]
   Int_t           IP3dHasSharedPixAll2[30];   //[nJets]
   Float_t         IP3d2[30];   //[nJets]
   Float_t         IP3dError2[30];   //[nJets]
   Float_t         IP3dProbability2[30];   //[nJets]
   Float_t         IP3dTrackPtRel2[30];   //[nJets]
   Float_t         IP3dDistJetAxis2[30];   //[nJets]
   Float_t         IP3dDecayLength2[30];   //[nJets]
   Float_t         IP3dDeltaR2[30];   //[nJets]
   Float_t         IP3dMomentum2[30];   //[nJets]
   Float_t         IP3dTransverseMomentum2[30];   //[nJets]
   Float_t         IP3dEta2[30];   //[nJets]
   Float_t         IP3dPhi2[30];   //[nJets]
   Int_t           IP3dNHits2[30];   //[nJets]
   Int_t           IP3dNPixelHits2[30];   //[nJets]
   Float_t         IP3dNormChi22[30];   //[nJets]
   Int_t           IP2dTrackQuality2[30];   //[nJets]
   Float_t         IP2d2[30];   //[nJets]
   Float_t         IP2dError2[30];   //[nJets]
   Float_t         IP2dProbability2[30];   //[nJets]
   Float_t         IP2dTrackPtRel2[30];   //[nJets]
   Int_t           IP3dTrackQuality3[30];   //[nJets]
   Int_t           IP3dHasSharedPix13[30];   //[nJets]
   Int_t           IP3dHasSharedPix23[30];   //[nJets]
   Int_t           IP3dHasSharedPix33[30];   //[nJets]
   Int_t           IP3dHasSharedPixAll3[30];   //[nJets]
   Float_t         IP3d3[30];   //[nJets]
   Float_t         IP3dError3[30];   //[nJets]
   Float_t         IP3dProbability3[30];   //[nJets]
   Float_t         IP3dTrackPtRel3[30];   //[nJets]
   Float_t         IP3dDistJetAxis3[30];   //[nJets]
   Float_t         IP3dDecayLength3[30];   //[nJets]
   Float_t         IP3dDeltaR3[30];   //[nJets]
   Float_t         IP3dMomentum3[30];   //[nJets]
   Float_t         IP3dTransverseMomentum3[30];   //[nJets]
   Float_t         IP3dEta3[30];   //[nJets]
   Float_t         IP3dPhi3[30];   //[nJets]
   Int_t           IP3dNHits3[30];   //[nJets]
   Int_t           IP3dNPixelHits3[30];   //[nJets]
   Float_t         IP3dNormChi23[30];   //[nJets]
   Int_t           IP2dTrackQuality3[30];   //[nJets]
   Float_t         IP2d3[30];   //[nJets]
   Float_t         IP2dError3[30];   //[nJets]
   Float_t         IP2dProbability3[30];   //[nJets]
   Float_t         IP2dTrackPtRel3[30];   //[nJets]
   Int_t           IP3dTrackQuality4[30];   //[nJets]
   Int_t           IP3dHasSharedPix14[30];   //[nJets]
   Int_t           IP3dHasSharedPix24[30];   //[nJets]
   Int_t           IP3dHasSharedPix34[30];   //[nJets]
   Int_t           IP3dHasSharedPixAll4[30];   //[nJets]
   Float_t         IP3d4[30];   //[nJets]
   Float_t         IP3dError4[30];   //[nJets]
   Float_t         IP3dProbability4[30];   //[nJets]
   Float_t         IP3dTrackPtRel4[30];   //[nJets]
   Float_t         IP3dDistJetAxis4[30];   //[nJets]
   Float_t         IP3dDecayLength4[30];   //[nJets]
   Float_t         IP3dDeltaR4[30];   //[nJets]
   Float_t         IP3dMomentum4[30];   //[nJets]
   Float_t         IP3dTransverseMomentum4[30];   //[nJets]
   Float_t         IP3dEta4[30];   //[nJets]
   Float_t         IP3dPhi4[30];   //[nJets]
   Int_t           IP3dNHits4[30];   //[nJets]
   Int_t           IP3dNPixelHits4[30];   //[nJets]
   Float_t         IP3dNormChi24[30];   //[nJets]
   Int_t           IP2dTrackQuality4[30];   //[nJets]
   Float_t         IP2d4[30];   //[nJets]
   Float_t         IP2dError4[30];   //[nJets]
   Float_t         IP2dProbability4[30];   //[nJets]
   Float_t         IP2dTrackPtRel4[30];   //[nJets]
   Int_t           nElectrons[30];   //[nJets]
// old 
   Float_t         electronPt[30];   //[nJets]
   Float_t         electronEta[30];   //[nJets]
   Float_t         electronPhi[30];   //[nJets]
   Int_t           electronNHits[30];   //[nJets]
   Int_t           electronNExpectedOuterHits[30];   //[nJets]
   Int_t           electronNPixelHits[30];   //[nJets]
   Float_t         electronNChi2[30];   //[nJets]
   Float_t         electronPtRel[30];   //[nJets]
   Float_t         electronSip2d[30];   //[nJets]
   Float_t         electronIp2d[30];   //[nJets]
   Float_t         electronIpe2d[30];   //[nJets]
   Float_t         electronSip3d[30];   //[nJets]
   Float_t         electronIp3d[30];   //[nJets]
   Float_t         electronIpe3d[30];   //[nJets]
   Float_t         electronP0Par[30];   //[nJets]
   Float_t         electronDeltaR[30];   //[nJets]
   Float_t         electronEtaRel[30];   //[nJets]
   Float_t         electronRatio[30];   //[nJets]
   Int_t           electronTrackQuality[30];   //[nJets]
   Float_t         electronRatioRel[30];   //[nJets]
// new 
   Float_t         electron1Pt[30];   //[nJets]
   Float_t         electron1Eta[30];   //[nJets]
   Float_t         electron1Phi[30];   //[nJets]
   Int_t           electron1NHits[30];   //[nJets]
   Int_t           electron1NExpectedOuterHits[30];   //[nJets]
   Int_t           electron1NPixelHits[30];   //[nJets]
   Float_t         electron1NChi2[30];   //[nJets]
   Float_t         electron1PtRel[30];   //[nJets]
   Float_t         electron1Sip2d[30];   //[nJets]
   Float_t         electron1Ip2d[30];   //[nJets]
   Float_t         electron1Ipe2d[30];   //[nJets]
   Float_t         electron1Sip3d[30];   //[nJets]
   Float_t         electron1Ip3d[30];   //[nJets]
   Float_t         electron1Ipe3d[30];   //[nJets]
   Float_t         electron1P0Par[30];   //[nJets]
   Float_t         electron1DeltaR[30];   //[nJets]
   Float_t         electron1EtaRel[30];   //[nJets]
   Float_t         electron1Ratio[30];   //[nJets]
   Int_t           electron1TrackQuality[30];   //[nJets]
   Float_t         electron1RatioRel[30];   //[nJets]
   Float_t         electron1eSuperClusterOverP[30];   //[nJets]
   Float_t         electron1eSeedClusterOverP[30];   //[nJets]
   Float_t         electron1eSeedClusterOverPout[30];   //[nJets]
   Float_t         electron1eEleClusterOverPout[30];   //[nJets]
   Float_t         electron1deltaEtaSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron1deltaEtaSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron1deltaEtaEleClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron1deltaPhiSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron1deltaPhiSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron1deltaPhiEleClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron2Pt[30];   //[nJets]
   Float_t         electron2Eta[30];   //[nJets]
   Float_t         electron2Phi[30];   //[nJets]
   Int_t           electron2NHits[30];   //[nJets]
   Int_t           electron2NExpectedOuterHits[30];   //[nJets]
   Int_t           electron2NPixelHits[30];   //[nJets]
   Float_t         electron2NChi2[30];   //[nJets]
   Float_t         electron2PtRel[30];   //[nJets]
   Float_t         electron2Sip2d[30];   //[nJets]
   Float_t         electron2Ip2d[30];   //[nJets]
   Float_t         electron2Ipe2d[30];   //[nJets]
   Float_t         electron2Sip3d[30];   //[nJets]
   Float_t         electron2Ip3d[30];   //[nJets]
   Float_t         electron2Ipe3d[30];   //[nJets]
   Float_t         electron2P0Par[30];   //[nJets]
   Float_t         electron2DeltaR[30];   //[nJets]
   Float_t         electron2EtaRel[30];   //[nJets]
   Float_t         electron2Ratio[30];   //[nJets]
   Int_t           electron2TrackQuality[30];   //[nJets]
   Float_t         electron2RatioRel[30];   //[nJets]
   Float_t         electron2eSuperClusterOverP[30];   //[nJets]
   Float_t         electron2eSeedClusterOverP[30];   //[nJets]
   Float_t         electron2eSeedClusterOverPout[30];   //[nJets]
   Float_t         electron2eEleClusterOverPout[30];   //[nJets]
   Float_t         electron2deltaEtaSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron2deltaEtaSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron2deltaEtaEleClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron2deltaPhiSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron2deltaPhiSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron2deltaPhiEleClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron3Pt[30];   //[nJets]
   Float_t         electron3Eta[30];   //[nJets]
   Float_t         electron3Phi[30];   //[nJets]
   Int_t           electron3NHits[30];   //[nJets]
   Int_t           electron3NExpectedOuterHits[30];   //[nJets]
   Int_t           electron3NPixelHits[30];   //[nJets]
   Float_t         electron3NChi2[30];   //[nJets]
   Float_t         electron3PtRel[30];   //[nJets]   
   Float_t         electron3Sip2d[30];   //[nJets]
   Float_t         electron3Ip2d[30];   //[nJets]
   Float_t         electron3Ipe2d[30];   //[nJets]
   Float_t         electron3Sip3d[30];   //[nJets]
   Float_t         electron3Ip3d[30];   //[nJets]
   Float_t         electron3Ipe3d[30];   //[nJets]
   Float_t         electron3P0Par[30];   //[nJets]
   Float_t         electron3DeltaR[30];   //[nJets]
   Float_t         electron3EtaRel[30];   //[nJets]
   Float_t         electron3Ratio[30];   //[nJets]
   Int_t           electron3TrackQuality[30];   //[nJets]
   Float_t         electron3RatioRel[30];   //[nJets]
   Float_t         electron3eSuperClusterOverP[30];   //[nJets]
   Float_t         electron3eSeedClusterOverP[30];   //[nJets]
   Float_t         electron3eSeedClusterOverPout[30];   //[nJets]
   Float_t         electron3eEleClusterOverPout[30];   //[nJets]
   Float_t         electron3deltaEtaSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron3deltaEtaSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron3deltaEtaEleClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron3deltaPhiSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron3deltaPhiSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron3deltaPhiEleClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron4Pt[30];   //[nJets]
   Float_t         electron4Eta[30];   //[nJets]
   Float_t         electron4Phi[30];   //[nJets]
   Int_t           electron4NHits[30];   //[nJets]
   Int_t           electron4NExpectedOuterHits[30];   //[nJets]
   Int_t           electron4NPixelHits[30];   //[nJets]
   Float_t         electron4NChi2[30];   //[nJets]
   Float_t         electron4PtRel[30];   //[nJets]
   Float_t         electron4Sip2d[30];   //[nJets]
   Float_t         electron4Ip2d[30];   //[nJets]
   Float_t         electron4Ipe2d[30];   //[nJets]
   Float_t         electron4Sip3d[30];   //[nJets]
   Float_t         electron4Ip3d[30];   //[nJets]
   Float_t         electron4Ipe3d[30];   //[nJets]
   Float_t         electron4P0Par[30];   //[nJets]
   Float_t         electron4DeltaR[30];   //[nJets]
   Float_t         electron4EtaRel[30];   //[nJets]
   Float_t         electron4Ratio[30];   //[nJets]
   Int_t           electron4TrackQuality[30];   //[nJets]
   Float_t         electron4RatioRel[30];   //[nJets]
   Float_t         electron4eSuperClusterOverP[30];   //[nJets]
   Float_t         electron4eSeedClusterOverP[30];   //[nJets]
   Float_t         electron4eSeedClusterOverPout[30];   //[nJets]
   Float_t         electron4eEleClusterOverPout[30];   //[nJets]
   Float_t         electron4deltaEtaSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron4deltaEtaSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron4deltaEtaEleClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron4deltaPhiSuperClusterTrackAtVtx[30];   //[nJets]
   Float_t         electron4deltaPhiSeedClusterTrackAtCalo[30];   //[nJets]
   Float_t         electron4deltaPhiEleClusterTrackAtCalo[30];   //[nJets]
   Int_t           nMuons[30];   //[nJets]
   Bool_t          muon1IsGlobal[30];   //[nJets]
   Bool_t          muon1IsTracker[30];   //[nJets]
   Bool_t          muon1IsStandalone[30];   //[nJets]
   Float_t         muon1Pt[30];   //[nJets]
   Float_t         muon1Eta[30];   //[nJets]
   Float_t         muon1Phi[30];   //[nJets]
   Int_t           muon1NumberOfMatches[30];   //[nJets]
   Int_t           muon1GlobalMuonHits[30];   //[nJets]
   Int_t           muon1InnerValidHits[30];   //[nJets]
   Int_t           muon1NExpectedOuterHits[30];   //[nJets]
   Int_t           muon1NPixelHits[30];   //[nJets]
   Float_t         muon1InnerNChi2[30];   //[nJets]
   Float_t         muon1GlobalNChi2[30];   //[nJets]
   Float_t         muon1VzPVDist[30];   //[nJets]
   Float_t         muon1PtRel[30];   //[nJets]
   Float_t         muon1Sip2d[30];   //[nJets]
   Float_t         muon1Ip2d[30];   //[nJets]
   Float_t         muon1Ipe2d[30];   //[nJets]
   Float_t         muon1Sip3d[30];   //[nJets]
   Float_t         muon1Ip3d[30];   //[nJets]
   Float_t         muon1Ipe3d[30];   //[nJets]
   Float_t         muon1P0Par[30];   //[nJets]
   Float_t         muon1DeltaR[30];   //[nJets]
   Float_t         muon1EtaRel[30];   //[nJets]
   Float_t         muon1Ratio[30];   //[nJets]
   Int_t           muon1TrackQuality[30];   //[nJets]
   Float_t         muon1RatioRel[30];   //[nJets]
   Bool_t          muon2IsGlobal[30];   //[nJets]
   Bool_t          muon2IsTracker[30];   //[nJets]
   Bool_t          muon2IsStandalone[30];   //[nJets]
   Float_t         muon2Pt[30];   //[nJets]
   Float_t         muon2Eta[30];   //[nJets]
   Float_t         muon2Phi[30];   //[nJets]
   Int_t           muon2NumberOfMatches[30];   //[nJets]
   Int_t           muon2GlobalMuonHits[30];   //[nJets]
   Int_t           muon2InnerValidHits[30];   //[nJets]
   Int_t           muon2NExpectedOuterHits[30];   //[nJets]
   Int_t           muon2NPixelHits[30];   //[nJets]
   Float_t         muon2InnerNChi2[30];   //[nJets]
   Float_t         muon2GlobalNChi2[30];   //[nJets]
   Float_t         muon2VzPVDist[30];   //[nJets]
   Float_t         muon2PtRel[30];   //[nJets]
   Float_t         muon2Sip2d[30];   //[nJets]
   Float_t         muon2Ip2d[30];   //[nJets]
   Float_t         muon2Ipe2d[30];   //[nJets]
   Float_t         muon2Sip3d[30];   //[nJets]
   Float_t         muon2Ip3d[30];   //[nJets]
   Float_t         muon2Ipe3d[30];   //[nJets]
   Float_t         muon2P0Par[30];   //[nJets]
   Float_t         muon2DeltaR[30];   //[nJets]
   Float_t         muon2EtaRel[30];   //[nJets]
   Float_t         muon2Ratio[30];   //[nJets]
   Int_t           muon2TrackQuality[30];   //[nJets]
   Float_t         muon2RatioRel[30];   //[nJets]
   Bool_t          muon3IsGlobal[30];   //[nJets]
   Bool_t          muon3IsTracker[30];   //[nJets]
   Bool_t          muon3IsStandalone[30];   //[nJets]
   Float_t         muon3Pt[30];   //[nJets]
   Float_t         muon3Eta[30];   //[nJets]
   Float_t         muon3Phi[30];   //[nJets]
   Int_t           muon3NumberOfMatches[30];   //[nJets]
   Int_t           muon3GlobalMuonHits[30];   //[nJets]
   Int_t           muon3InnerValidHits[30];   //[nJets]
   Int_t           muon3NExpectedOuterHits[30];   //[nJets]
   Int_t           muon3NPixelHits[30];   //[nJets]
   Float_t         muon3InnerNChi2[30];   //[nJets]
   Float_t         muon3GlobalNChi2[30];   //[nJets]
   Float_t         muon3VzPVDist[30];   //[nJets]
   Float_t         muon3PtRel[30];   //[nJets]
   Float_t         muon3Sip2d[30];   //[nJets]
   Float_t         muon3Ip2d[30];   //[nJets]
   Float_t         muon3Ipe2d[30];   //[nJets]
   Float_t         muon3Sip3d[30];   //[nJets]
   Float_t         muon3Ip3d[30];   //[nJets]
   Float_t         muon3Ipe3d[30];   //[nJets]
   Float_t         muon3P0Par[30];   //[nJets]
   Float_t         muon3DeltaR[30];   //[nJets]
   Float_t         muon3EtaRel[30];   //[nJets]
   Float_t         muon3Ratio[30];   //[nJets]
   Int_t           muon3TrackQuality[30];   //[nJets]
   Float_t         muon3RatioRel[30];   //[nJets]
   Bool_t          muon4IsGlobal[30];   //[nJets]
   Bool_t          muon4IsTracker[30];   //[nJets]
   Bool_t          muon4IsStandalone[30];   //[nJets]
   Float_t         muon4Pt[30];   //[nJets]
   Float_t         muon4Eta[30];   //[nJets]
   Float_t         muon4Phi[30];   //[nJets]
   Int_t           muon4NumberOfMatches[30];   //[nJets]
   Int_t           muon4GlobalMuonHits[30];   //[nJets]
   Int_t           muon4InnerValidHits[30];   //[nJets]
   Int_t           muon4NExpectedOuterHits[30];   //[nJets]
   Int_t           muon4NPixelHits[30];   //[nJets]
   Float_t         muon4InnerNChi2[30];   //[nJets]
   Float_t         muon4GlobalNChi2[30];   //[nJets]
   Float_t         muon4VzPVDist[30];   //[nJets]
   Float_t         muon4PtRel[30];   //[nJets]
   Float_t         muon4Sip2d[30];   //[nJets]
   Float_t         muon4Ip2d[30];   //[nJets]
   Float_t         muon4Ipe2d[30];   //[nJets]
   Float_t         muon4Sip3d[30];   //[nJets]
   Float_t         muon4Ip3d[30];   //[nJets]
   Float_t         muon4Ipe3d[30];   //[nJets]
   Float_t         muon4P0Par[30];   //[nJets]
   Float_t         muon4DeltaR[30];   //[nJets]
   Float_t         muon4EtaRel[30];   //[nJets]
   Float_t         muon4Ratio[30];   //[nJets]
   Int_t           muon4TrackQuality[30];   //[nJets]
   Float_t         muon4RatioRel[30];   //[nJets]
   Float_t         standardCombinedSecondaryVertexMVAPFBJetTags[30];   //[nJets]
   Float_t         standardCombinedSecondaryVertexPFBJetTags[30];   //[nJets]
   Float_t         standardGhostTrackPFBJetTags[30];   //[nJets]
   Float_t         standardJetBProbabilityPFBJetTags[30];   //[nJets]
   Float_t         standardJetProbabilityPFBJetTags[30];   //[nJets]
   Float_t         standardSimpleSecondaryVertexHighEffPFBJetTags[30];   //[nJets]
   Float_t         standardSimpleSecondaryVertexHighPurPFBJetTags[30];   //[nJets]
   Float_t         standardSoftElectronByIP3dPFBJetTags[30];   //[nJets]
   Float_t         standardSoftElectronByPtPFBJetTags[30];   //[nJets]
   Float_t         standardSoftMuonByIP3dPFBJetTags[30];   //[nJets]
   Float_t         standardSoftMuonByPtPFBJetTags[30];   //[nJets]
   Float_t         standardSoftMuonPFBJetTags[30];   //[nJets]
   Float_t         standardTrackCountingHighEffPFBJetTags[30];   //[nJets]
   Float_t         standardTrackCountingHighPurPFBJetTags[30];   //[nJets]

   // List of branches
   TBranch        *b_triggerHLTL1Jet6U;   //!
   TBranch        *b_triggerHLTL1Jet10U;   //!
   TBranch        *b_triggerHLTJet15U;   //!
   TBranch        *b_triggerHLTJet30U;   //!
   TBranch        *b_triggerHLTJet50U;   //!
   TBranch        *b_triggerHLTJet70U;   //!
   TBranch        *b_triggerHLTJet100U;   //!
   TBranch        *b_triggerHLTBTagIPJet50U;   //!
   TBranch        *b_triggerHLTBTagMuJet10U;   //!
   TBranch        *b_triggerHLTBTagMuJet20U;   //!
   TBranch        *b_triggerHLTBTagMuDiJet10U;   //!
   TBranch        *b_triggerHLTBTagMuDiJet20U;   //!
   TBranch        *b_triggerHLTBTagMuDiJet20UMu5;   //!
   TBranch        *b_triggerHLTBTagMuDiJet30U;   //!
   TBranch        *b_triggerHLTBTagMuDiJet30UMu5;   //!
   TBranch        *b_prescaleHLTL1Jet6U;   //!
   TBranch        *b_prescaleHLTL1Jet10U;   //!
   TBranch        *b_prescaleHLTJet15U;   //!
   TBranch        *b_prescaleHLTJet30U;   //!
   TBranch        *b_prescaleHLTJet50U;   //!
   TBranch        *b_prescaleHLTJet70U;   //!
   TBranch        *b_prescaleHLTJet100U;   //!
   TBranch        *b_prescaleHLTBTagIPJet50U;   //!
   TBranch        *b_prescaleHLTBTagMuJet10U;   //!
   TBranch        *b_prescaleHLTBTagMuJet20U;   //!
   TBranch        *b_prescaleHLTBTagMuDiJet10U;   //!
   TBranch        *b_prescaleHLTBTagMuDiJet20U;   //!
   TBranch        *b_prescaleHLTBTagMuDiJet20UMu5;   //!
   TBranch        *b_prescaleHLTBTagMuDiJet30U;   //!
   TBranch        *b_prescaleHLTBTagMuDiJet30UMu5;   //!
   TBranch          *b_triggerHLT_L1SingleJet36;
   TBranch          *b_triggerHLT_Jet30;
   TBranch          *b_triggerHLT_Jet60;
   TBranch          *b_triggerHLT_Jet80;
   TBranch          *b_triggerHLT_Jet110;
   TBranch          *b_triggerHLT_Jet150;
   TBranch          *b_triggerHLT_Jet190;
   TBranch          *b_triggerHLT_Jet240;
   TBranch          *b_triggerHLT_Jet370;
   TBranch          *b_triggerHLT_Jet370_NoJetID;
   TBranch          *b_prescaleHLT_L1SingleJet36;
   TBranch          *b_prescaleHLT_Jet30;
   TBranch          *b_prescaleHLT_Jet60;
   TBranch          *b_prescaleHLT_Jet80;
   TBranch          *b_prescaleHLT_Jet110;
   TBranch          *b_prescaleHLT_Jet150;
   TBranch          *b_prescaleHLT_Jet190;
   TBranch          *b_prescaleHLT_Jet240;
   TBranch          *b_prescaleHLT_Jet370;
   TBranch          *b_prescaleHLT_Jet370_NoJetID;
   TBranch        *b_triggerHLT_DiJetAve15U_v4;   //!
   TBranch        *b_triggerHLT_DiJetAve30U_v4;   //!
   TBranch        *b_triggerHLT_DiJetAve50U_v4;   //!
   TBranch        *b_triggerHLT_DiJetAve70U_v4;   //!
   TBranch        *b_triggerHLT_DiJetAve100U_v4;   //!
   TBranch        *b_triggerHLT_DiJetAve140U_v4;   //!
   TBranch        *b_triggerHLT_DiJetAve180U_v4;   //!
   TBranch        *b_triggerHLT_DiJetAve300U_v4;   //!
   TBranch        *b_triggerHLT_BTagMu_DiJet20_Mu5_v2;   //!
   TBranch        *b_triggerHLT_BTagMu_DiJet60_Mu7_v2;   //!
   TBranch        *b_triggerHLT_BTagMu_DiJet80_Mu9_v2;   //!
   TBranch        *b_triggerHLT_BTagMu_DiJet100_Mu9_v2;   //!
   TBranch        *b_prescaleHLT_DiJetAve15U_v4;   //!
   TBranch        *b_prescaleHLT_DiJetAve30U_v4;   //!
   TBranch        *b_prescaleHLT_DiJetAve50U_v4;   //!
   TBranch        *b_prescaleHLT_DiJetAve70U_v4;   //!
   TBranch        *b_prescaleHLT_DiJetAve100U_v4;   //!
   TBranch        *b_prescaleHLT_DiJetAve140U_v4;   //!
   TBranch        *b_prescaleHLT_DiJetAve180U_v4;   //!
   TBranch        *b_prescaleHLT_DiJetAve300U_v4;   //!
   TBranch        *b_prescaleHLT_BTagMu_DiJet20_Mu5_v2;   //!
   TBranch        *b_prescaleHLT_BTagMu_DiJet60_Mu7_v2;   //!
   TBranch        *b_prescaleHLT_BTagMu_DiJet80_Mu9_v2;   //!
   TBranch        *b_prescaleHLT_BTagMu_DiJet100_Mu9_v2;   //!

   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_lumiBlockNumber;   //!
   TBranch        *b_numberOfPUVertices;   //!
   TBranch        *b_numberOfPrimaryVertices;   //!
   TBranch        *b_numberOfTracksAtPV;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_PVChi2;   //!
   TBranch        *b_PVndof;   //!
   TBranch        *b_PVNormalizedChi2;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_isBGluonSplitting;   //!
   TBranch        *b_isCGluonSplitting;   //!
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
   TBranch        *b_trackIsVertexTrack;   //!
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
   TBranch        *b_SVvtxPt;   //!
   TBranch        *b_SVvtxSumDirEta;   //!
   TBranch        *b_SVvtxSumDirPhi;   //!
   TBranch        *b_SVvtxDirEta;   //!
   TBranch        *b_SVvtxDirPhi;   //!
   TBranch        *b_SVvtxSumPTrel;   //!
   TBranch        *b_SVvtxDirPTrel;   //!
   TBranch        *b_SVvtxDistJetAxis;   //!
   TBranch        *b_SVtotCharge;   //!
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
// old
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
// new
   TBranch        *b_electron1Pt;   //! 
   TBranch        *b_electron1Eta;   //!
   TBranch        *b_electron1Phi;   //!  
   TBranch        *b_electron1NHits;   //!
   TBranch        *b_electron1NExpectedOuterHits;   //!
   TBranch        *b_electron1NPixelHits;   //!
   TBranch        *b_electron1NChi2;   //!
   TBranch        *b_electron1PtRel;   //!
   TBranch        *b_electron1Sip2d;   //! 
   TBranch        *b_electron1Ip2d;   //!  
   TBranch        *b_electron1Ipe2d;   //! 
   TBranch        *b_electron1Sip3d;   //!   
   TBranch        *b_electron1Ip3d;   //!
   TBranch        *b_electron1Ipe3d;   //!
   TBranch        *b_electron1P0Par;   //!
   TBranch        *b_electron1DeltaR;   //!
   TBranch        *b_electron1EtaRel;   //!
   TBranch        *b_electron1Ratio;   //!
   TBranch        *b_electron1TrackQuality;   //!
   TBranch        *b_electron1RatioRel;   //!
   TBranch        *b_electron1eSuperClusterOverP;   //!
   TBranch        *b_electron1eSeedClusterOverP;   //!
   TBranch        *b_electron1eSeedClusterOverPout;   //!
   TBranch        *b_electron1eEleClusterOverPout;   //!
   TBranch        *b_electron1deltaEtaSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron1deltaEtaSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron1deltaEtaEleClusterTrackAtCalo;   //!
   TBranch        *b_electron1deltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron1deltaPhiSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron1deltaPhiEleClusterTrackAtCalo;   //!
   TBranch        *b_electron2Pt;   //!
   TBranch        *b_electron2Eta;   //!
   TBranch        *b_electron2Phi;   //!
   TBranch        *b_electron2NHits;   //!
   TBranch        *b_electron2NExpectedOuterHits;   //!
   TBranch        *b_electron2NPixelHits;   //!
   TBranch        *b_electron2NChi2;   //!
   TBranch        *b_electron2PtRel;   //!
   TBranch        *b_electron2Sip2d;   //!
   TBranch        *b_electron2Ip2d;   //!
   TBranch        *b_electron2Ipe2d;   //!
   TBranch        *b_electron2Sip3d;   //!
   TBranch        *b_electron2Ip3d;   //!
   TBranch        *b_electron2Ipe3d;   //!
   TBranch        *b_electron2P0Par;   //!
   TBranch        *b_electron2DeltaR;   //!
   TBranch        *b_electron2EtaRel;   //!
   TBranch        *b_electron2Ratio;   //!
   TBranch        *b_electron2TrackQuality;   //!
   TBranch        *b_electron2RatioRel;   //!
   TBranch        *b_electron2eSuperClusterOverP;   //!
   TBranch        *b_electron2eSeedClusterOverP;   //!
   TBranch        *b_electron2eSeedClusterOverPout;   //!
   TBranch        *b_electron2eEleClusterOverPout;   //!
   TBranch        *b_electron2deltaEtaSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron2deltaEtaSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron2deltaEtaEleClusterTrackAtCalo;   //!
   TBranch        *b_electron2deltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron2deltaPhiSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron2deltaPhiEleClusterTrackAtCalo;   //!
   TBranch        *b_electron3Pt;   //!
   TBranch        *b_electron3Eta;   //!
   TBranch        *b_electron3Phi;   //!
   TBranch        *b_electron3NHits;   //!
   TBranch        *b_electron3NExpectedOuterHits;   //!
   TBranch        *b_electron3NPixelHits;   //!
   TBranch        *b_electron3NChi2;   //!
   TBranch        *b_electron3PtRel;   //!
   TBranch        *b_electron3Sip2d;   //!
   TBranch        *b_electron3Ip2d;   //!
   TBranch        *b_electron3Ipe2d;   //!
   TBranch        *b_electron3Sip3d;   //!
   TBranch        *b_electron3Ip3d;   //!
   TBranch        *b_electron3Ipe3d;   //!
   TBranch        *b_electron3P0Par;   //!
   TBranch        *b_electron3DeltaR;   //!
   TBranch        *b_electron3EtaRel;   //!
   TBranch        *b_electron3Ratio;   //!
   TBranch        *b_electron3TrackQuality;   //!
   TBranch        *b_electron3RatioRel;   //!
   TBranch        *b_electron3eSuperClusterOverP;   //!
   TBranch        *b_electron3eSeedClusterOverP;   //!
   TBranch        *b_electron3eSeedClusterOverPout;   //!
   TBranch        *b_electron3eEleClusterOverPout;   //!
   TBranch        *b_electron3deltaEtaSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron3deltaEtaSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron3deltaEtaEleClusterTrackAtCalo;   //!
   TBranch        *b_electron3deltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron3deltaPhiSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron3deltaPhiEleClusterTrackAtCalo;   //!
   TBranch        *b_electron4Pt;   //!
   TBranch        *b_electron4Eta;   //!
   TBranch        *b_electron4Phi;   //!
   TBranch        *b_electron4NHits;   //!
   TBranch        *b_electron4NExpectedOuterHits;   //!
   TBranch        *b_electron4NPixelHits;   //!
   TBranch        *b_electron4NChi2;   //!
   TBranch        *b_electron4PtRel;   //!
   TBranch        *b_electron4Sip2d;   //!
   TBranch        *b_electron4Ip2d;   //!
   TBranch        *b_electron4Ipe2d;   //!
   TBranch        *b_electron4Sip3d;   //!
   TBranch        *b_electron4Ip3d;   //!
   TBranch        *b_electron4Ipe3d;   //!
   TBranch        *b_electron4P0Par;   //!
   TBranch        *b_electron4DeltaR;   //!
   TBranch        *b_electron4EtaRel;   //!
   TBranch        *b_electron4Ratio;   //!
   TBranch        *b_electron4TrackQuality;   //!
   TBranch        *b_electron4RatioRel;   //!
   TBranch        *b_electron4eSuperClusterOverP;   //!
   TBranch        *b_electron4eSeedClusterOverP;   //!
   TBranch        *b_electron4eSeedClusterOverPout;   //!
   TBranch        *b_electron4eEleClusterOverPout;   //!
   TBranch        *b_electron4deltaEtaSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron4deltaEtaSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron4deltaEtaEleClusterTrackAtCalo;   //!
   TBranch        *b_electron4deltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b_electron4deltaPhiSeedClusterTrackAtCalo;   //!
   TBranch        *b_electron4deltaPhiEleClusterTrackAtCalo;   //!
   TBranch        *b_nMuons;   //!
   TBranch        *b_muon1IsGlobal;   //!
   TBranch        *b_muon1IsTracker;   //!
   TBranch        *b_muon1IsStandalone;   //!
   TBranch        *b_muon1Pt;   //!
   TBranch        *b_muon1Eta;   //!
   TBranch        *b_muon1Phi;   //!
   TBranch        *b_muon1NumberOfMatches;   //!
   TBranch        *b_muon1GlobalMuonHits;   //!
   TBranch        *b_muon1InnerValidHits;   //!
   TBranch        *b_muon1NExpectedOuterHits;   //!
   TBranch        *b_muon1NPixelHits;   //!
   TBranch        *b_muon1InnerNChi2;   //!
   TBranch        *b_muon1GlobalNChi2;   //!
   TBranch        *b_muon1VzPVDist;   //!
   TBranch        *b_muon1PtRel;   //!
   TBranch        *b_muon1Sip2d;   //!
   TBranch        *b_muon1Ip2d;   //!
   TBranch        *b_muon1Ipe2d;   //!
   TBranch        *b_muon1Sip3d;   //!
   TBranch        *b_muon1Ip3d;   //!
   TBranch        *b_muon1Ipe3d;   //!
   TBranch        *b_muon1P0Par;   //!
   TBranch        *b_muon1DeltaR;   //!
   TBranch        *b_muon1EtaRel;   //!
   TBranch        *b_muon1Ratio;   //!
   TBranch        *b_muon1TrackQuality;   //!
   TBranch        *b_muon1RatioRel;   //!
   TBranch        *b_muon2IsGlobal;   //!
   TBranch        *b_muon2IsTracker;   //!
   TBranch        *b_muon2IsStandalone;   //!
   TBranch        *b_muon2Pt;   //!
   TBranch        *b_muon2Eta;   //!
   TBranch        *b_muon2Phi;   //!
   TBranch        *b_muon2NumberOfMatches;   //!
   TBranch        *b_muon2GlobalMuonHits;   //!
   TBranch        *b_muon2InnerValidHits;   //!
   TBranch        *b_muon2NExpectedOuterHits;   //!
   TBranch        *b_muon2NPixelHits;   //!
   TBranch        *b_muon2InnerNChi2;   //!
   TBranch        *b_muon2GlobalNChi2;   //!
   TBranch        *b_muon2VzPVDist;   //!
   TBranch        *b_muon2PtRel;   //!
   TBranch        *b_muon2Sip2d;   //!
   TBranch        *b_muon2Ip2d;   //!
   TBranch        *b_muon2Ipe2d;   //!
   TBranch        *b_muon2Sip3d;   //!
   TBranch        *b_muon2Ip3d;   //!
   TBranch        *b_muon2Ipe3d;   //!
   TBranch        *b_muon2P0Par;   //!
   TBranch        *b_muon2DeltaR;   //!
   TBranch        *b_muon2EtaRel;   //!
   TBranch        *b_muon2Ratio;   //!
   TBranch        *b_muon2TrackQuality;   //!
   TBranch        *b_muon2RatioRel;   //!
   TBranch        *b_muon3IsGlobal;   //!
   TBranch        *b_muon3IsTracker;   //!
   TBranch        *b_muon3IsStandalone;   //!
   TBranch        *b_muon3Pt;   //!
   TBranch        *b_muon3Eta;   //!
   TBranch        *b_muon3Phi;   //!
   TBranch        *b_muon3NumberOfMatches;   //!
   TBranch        *b_muon3GlobalMuonHits;   //!
   TBranch        *b_muon3InnerValidHits;   //!
   TBranch        *b_muon3NExpectedOuterHits;   //!
   TBranch        *b_muon3NPixelHits;   //!
   TBranch        *b_muon3InnerNChi2;   //!
   TBranch        *b_muon3GlobalNChi2;   //!
   TBranch        *b_muon3VzPVDist;   //!
   TBranch        *b_muon3PtRel;   //!
   TBranch        *b_muon3Sip2d;   //!
   TBranch        *b_muon3Ip2d;   //!
   TBranch        *b_muon3Ipe2d;   //!
   TBranch        *b_muon3Sip3d;   //!
   TBranch        *b_muon3Ip3d;   //!
   TBranch        *b_muon3Ipe3d;   //!
   TBranch        *b_muon3P0Par;   //!
   TBranch        *b_muon3DeltaR;   //!
   TBranch        *b_muon3EtaRel;   //!
   TBranch        *b_muon3Ratio;   //!
   TBranch        *b_muon3TrackQuality;   //!
   TBranch        *b_muon3RatioRel;   //!
   TBranch        *b_muon4IsGlobal;   //!
   TBranch        *b_muon4IsTracker;   //!
   TBranch        *b_muon4IsStandalone;   //!
   TBranch        *b_muon4Pt;   //!
   TBranch        *b_muon4Eta;   //!
   TBranch        *b_muon4Phi;   //!
   TBranch        *b_muon4NumberOfMatches;   //!
   TBranch        *b_muon4GlobalMuonHits;   //!
   TBranch        *b_muon4InnerValidHits;   //!
   TBranch        *b_muon4NExpectedOuterHits;   //!
   TBranch        *b_muon4NPixelHits;   //!
   TBranch        *b_muon4InnerNChi2;   //!
   TBranch        *b_muon4GlobalNChi2;   //!
   TBranch        *b_muon4VzPVDist;   //!
   TBranch        *b_muon4PtRel;   //!
   TBranch        *b_muon4Sip2d;   //!
   TBranch        *b_muon4Ip2d;   //!
   TBranch        *b_muon4Ipe2d;   //!
   TBranch        *b_muon4Sip3d;   //!
   TBranch        *b_muon4Ip3d;   //!
   TBranch        *b_muon4Ipe3d;   //!
   TBranch        *b_muon4P0Par;   //!
   TBranch        *b_muon4DeltaR;   //!
   TBranch        *b_muon4EtaRel;   //!
   TBranch        *b_muon4Ratio;   //!
   TBranch        *b_muon4TrackQuality;   //!
   TBranch        *b_muon4RatioRel;   //!
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

//   btagNtupReader(TTree *tree=0);
   btagNtupReader(int valinfo, string filename);
   virtual ~btagNtupReader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int cutgen, float weight);
   void      AddHisto(vector<TH1F*> &HistoBtag, string name,  const int& j, string title,  const int& nbins, const float& min, const float& max);
   void      AddHisto2D(vector<TH2F*> &Histo2DB, string name,  const int& j, string title, const int& nbins, const float& min, const float& max, const int& nbinsy, const float& miny, const float& maxy);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);


   bool SearchStar(string s, vector<string>& out);
   void StringSeparator(string s, string sep, vector<string>& out);
   void StringSeparator(string s, string sep, vector<int>& out);

   // declaration histo
   vector<TH1F*> HistoBtag;
   vector<TH2F*> Histo2DB;

};

   void run();

#endif

#ifdef btagNtupReader_cxx
btagNtupReader::btagNtupReader(int valinfo, string filename)
{

      // The following code should be used if you want this class to access a chain
      // of trees.
      dataflag=valinfo;
      TChain * chain = new TChain("t","");
      vector<string> filenames;
      bool star = SearchStar(filename,filenames);
      if(!star){
           filenames.clear();
           StringSeparator(filename,string(","),filenames);
      }
      for(unsigned int i=0;i<filenames.size();i++){
                 chain->AddFile(filenames[i].c_str());
      }
      TTree* tree = chain;
      Init(tree);
}

bool btagNtupReader::SearchStar(string s, vector<string>& out)
{
  int pos = s.find('*');
  if(pos<(int)s.size() && pos>=0){
        string command;
        command = "ls -ltrh " + s + "| awk {'print $9'} > tmp.AnaEnvLoader";
        system(command.c_str());
        ifstream ifile("tmp.AnaEnvLoader");
        int aa =0;
        while(!ifile.eof()){
                string sread;
                ifile>>sread;
                out.push_back(sread);
                aa++;
        }
        out.erase(out.end());
//        out.erase(out.end());
//        out.erase(out.end()-1,out.end());
/*
        for (int i=0; i<out.size(); i++) {
           cout << out[i] << endl;
        }
*/
        cout << " nombre de fichiers lus : " << out.size() << " last one " << out[out.size()-1]  << endl;
        cout << " check " ;
        string command2;
        command2 = "ls -ltrh " + s + " | wc ";
        system(command2.c_str());
        system("rm tmp.AnaEnvLoader");
        cout << endl;
        return true;
  }
  return false;
}
void btagNtupReader::StringSeparator(string s, string sep, vector<string>& out)
{
  string::size_type pos, pos_ex = 0;
  while ( (pos = s.find(sep, pos_ex)) != string::npos)
  {
        out.push_back(s.substr(pos_ex, pos-pos_ex));
        pos_ex = pos + 1;
  }
  out.push_back(s.substr(pos_ex));
}
void btagNtupReader::StringSeparator(string s, string sep, vector<int>& out)
{
  string::size_type pos, pos_ex = 0;
  while ( (pos = s.find(sep, pos_ex)) != string::npos)
  {
        string a = s.substr(pos_ex, pos-pos_ex);
        out.push_back(atoi(a.c_str()));
        pos_ex = pos + 1;
  }
  string a = s.substr(pos_ex);
  out.push_back(atoi(a.c_str()));
}



btagNtupReader::~btagNtupReader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t btagNtupReader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t btagNtupReader::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void btagNtupReader::Init(TTree *tree)
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
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("triggerHLTL1Jet6U", &triggerHLTL1Jet6U, &b_triggerHLTL1Jet6U);
   fChain->SetBranchAddress("triggerHLTL1Jet10U", &triggerHLTL1Jet10U, &b_triggerHLTL1Jet10U);
   fChain->SetBranchAddress("triggerHLTJet15U", &triggerHLTJet15U, &b_triggerHLTJet15U);
   fChain->SetBranchAddress("triggerHLTJet30U", &triggerHLTJet30U, &b_triggerHLTJet30U);
   fChain->SetBranchAddress("triggerHLTJet50U", &triggerHLTJet50U, &b_triggerHLTJet50U);
   fChain->SetBranchAddress("triggerHLTJet70U", &triggerHLTJet70U, &b_triggerHLTJet70U);
   fChain->SetBranchAddress("triggerHLTJet100U", &triggerHLTJet100U, &b_triggerHLTJet100U);
   fChain->SetBranchAddress("triggerHLTBTagIPJet50U", &triggerHLTBTagIPJet50U, &b_triggerHLTBTagIPJet50U);
   fChain->SetBranchAddress("triggerHLTBTagMuJet10U", &triggerHLTBTagMuJet10U, &b_triggerHLTBTagMuJet10U);
   fChain->SetBranchAddress("triggerHLTBTagMuJet20U", &triggerHLTBTagMuJet20U, &b_triggerHLTBTagMuJet20U);
   fChain->SetBranchAddress("triggerHLTBTagMuDiJet10U", &triggerHLTBTagMuDiJet10U, &b_triggerHLTBTagMuDiJet10U);
   fChain->SetBranchAddress("triggerHLTBTagMuDiJet20U", &triggerHLTBTagMuDiJet20U, &b_triggerHLTBTagMuDiJet20U);
   fChain->SetBranchAddress("triggerHLTBTagMuDiJet20UMu5", &triggerHLTBTagMuDiJet20UMu5, &b_triggerHLTBTagMuDiJet20UMu5);
   fChain->SetBranchAddress("triggerHLTBTagMuDiJet30U", &triggerHLTBTagMuDiJet30U, &b_triggerHLTBTagMuDiJet30U);
   fChain->SetBranchAddress("triggerHLTBTagMuDiJet30UMu5", &triggerHLTBTagMuDiJet30UMu5, &b_triggerHLTBTagMuDiJet30UMu5);
   if (dataflag>0) {
   fChain->SetBranchAddress("prescaleHLTL1Jet6U", &prescaleHLTL1Jet6U, &b_prescaleHLTL1Jet6U);
   fChain->SetBranchAddress("prescaleHLTL1Jet10U", &prescaleHLTL1Jet10U, &b_prescaleHLTL1Jet10U);
   fChain->SetBranchAddress("prescaleHLTJet15U", &prescaleHLTJet15U, &b_prescaleHLTJet15U);
   fChain->SetBranchAddress("prescaleHLTJet30U", &prescaleHLTJet30U, &b_prescaleHLTJet30U);
   fChain->SetBranchAddress("prescaleHLTJet50U", &prescaleHLTJet50U, &b_prescaleHLTJet50U);
   fChain->SetBranchAddress("prescaleHLTJet70U", &prescaleHLTJet70U, &b_prescaleHLTJet70U);
   fChain->SetBranchAddress("prescaleHLTJet100U", &prescaleHLTJet100U, &b_prescaleHLTJet100U);
   fChain->SetBranchAddress("prescaleHLTBTagIPJet50U", &prescaleHLTBTagIPJet50U, &b_prescaleHLTBTagIPJet50U);
   fChain->SetBranchAddress("prescaleHLTBTagMuJet10U", &prescaleHLTBTagMuJet10U, &b_prescaleHLTBTagMuJet10U);
   fChain->SetBranchAddress("prescaleHLTBTagMuJet20U", &prescaleHLTBTagMuJet20U, &b_prescaleHLTBTagMuJet20U);
   fChain->SetBranchAddress("prescaleHLTBTagMuDiJet10U", &prescaleHLTBTagMuDiJet10U, &b_prescaleHLTBTagMuDiJet10U);
   fChain->SetBranchAddress("prescaleHLTBTagMuDiJet20U", &prescaleHLTBTagMuDiJet20U, &b_prescaleHLTBTagMuDiJet20U);
   fChain->SetBranchAddress("prescaleHLTBTagMuDiJet20UMu5", &prescaleHLTBTagMuDiJet20UMu5, &b_prescaleHLTBTagMuDiJet20UMu5);
   fChain->SetBranchAddress("prescaleHLTBTagMuDiJet30U", &prescaleHLTBTagMuDiJet30U, &b_prescaleHLTBTagMuDiJet30U);
   fChain->SetBranchAddress("prescaleHLTBTagMuDiJet30UMu5", &prescaleHLTBTagMuDiJet30UMu5, &b_prescaleHLTBTagMuDiJet30UMu5);
   }
   if (dataflag>1) {
   fChain->SetBranchAddress("triggerHLT_L1SingleJet36", &triggerHLT_L1SingleJet36, &b_triggerHLT_L1SingleJet36);
   fChain->SetBranchAddress("triggerHLT_Jet30", &triggerHLT_Jet30, &b_triggerHLT_Jet30);
   fChain->SetBranchAddress("triggerHLT_Jet60", &triggerHLT_Jet60, &b_triggerHLT_Jet60);
   fChain->SetBranchAddress("triggerHLT_Jet80", &triggerHLT_Jet80, &b_triggerHLT_Jet80);
   fChain->SetBranchAddress("triggerHLT_Jet110", &triggerHLT_Jet110, &b_triggerHLT_Jet110);
   fChain->SetBranchAddress("triggerHLT_Jet150", &triggerHLT_Jet150, &b_triggerHLT_Jet150);
   fChain->SetBranchAddress("triggerHLT_Jet190", &triggerHLT_Jet190, &b_triggerHLT_Jet190);
   fChain->SetBranchAddress("triggerHLT_Jet240", &triggerHLT_Jet240, &b_triggerHLT_Jet240);
   fChain->SetBranchAddress("triggerHLT_Jet370", &triggerHLT_Jet370, &b_triggerHLT_Jet370);
   fChain->SetBranchAddress("triggerHLT_Jet370_NoJetID", &triggerHLT_Jet370_NoJetID, &b_triggerHLT_Jet370_NoJetID);
   fChain->SetBranchAddress("prescaleHLT_L1SingleJet36", &prescaleHLT_L1SingleJet36, &b_prescaleHLT_L1SingleJet36);
   fChain->SetBranchAddress("prescaleHLT_Jet30", &prescaleHLT_Jet30, &b_prescaleHLT_Jet30);
   fChain->SetBranchAddress("prescaleHLT_Jet60", &prescaleHLT_Jet60, &b_prescaleHLT_Jet60);
   fChain->SetBranchAddress("prescaleHLT_Jet80", &prescaleHLT_Jet80, &b_prescaleHLT_Jet80);
   fChain->SetBranchAddress("prescaleHLT_Jet110", &prescaleHLT_Jet110, &b_prescaleHLT_Jet110);
   fChain->SetBranchAddress("prescaleHLT_Jet150", &prescaleHLT_Jet150, &b_prescaleHLT_Jet150);
   fChain->SetBranchAddress("prescaleHLT_Jet190", &prescaleHLT_Jet190, &b_prescaleHLT_Jet190);
   fChain->SetBranchAddress("prescaleHLT_Jet240", &prescaleHLT_Jet240, &b_prescaleHLT_Jet240);
   fChain->SetBranchAddress("prescaleHLT_Jet370", &prescaleHLT_Jet370, &b_prescaleHLT_Jet370);
   fChain->SetBranchAddress("prescaleHLT_Jet370_NoJetID", &prescaleHLT_Jet370_NoJetID, &b_prescaleHLT_Jet370_NoJetID);
   fChain->SetBranchAddress("triggerHLT_DiJetAve15U_v4", &triggerHLT_DiJetAve15U_v4, &b_triggerHLT_DiJetAve15U_v4);
   fChain->SetBranchAddress("triggerHLT_DiJetAve30U_v4", &triggerHLT_DiJetAve30U_v4, &b_triggerHLT_DiJetAve30U_v4);
   fChain->SetBranchAddress("triggerHLT_DiJetAve50U_v4", &triggerHLT_DiJetAve50U_v4, &b_triggerHLT_DiJetAve50U_v4);
   fChain->SetBranchAddress("triggerHLT_DiJetAve70U_v4", &triggerHLT_DiJetAve70U_v4, &b_triggerHLT_DiJetAve70U_v4);
   fChain->SetBranchAddress("triggerHLT_DiJetAve100U_v4", &triggerHLT_DiJetAve100U_v4, &b_triggerHLT_DiJetAve100U_v4);
   fChain->SetBranchAddress("triggerHLT_DiJetAve140U_v4", &triggerHLT_DiJetAve140U_v4, &b_triggerHLT_DiJetAve140U_v4);
   fChain->SetBranchAddress("triggerHLT_DiJetAve180U_v4", &triggerHLT_DiJetAve180U_v4, &b_triggerHLT_DiJetAve180U_v4);
   fChain->SetBranchAddress("triggerHLT_DiJetAve300U_v4", &triggerHLT_DiJetAve300U_v4, &b_triggerHLT_DiJetAve300U_v4);
   fChain->SetBranchAddress("triggerHLT_BTagMu_DiJet20_Mu5_v2", &triggerHLT_BTagMu_DiJet20_Mu5_v2, &b_triggerHLT_BTagMu_DiJet20_Mu5_v2);
   fChain->SetBranchAddress("triggerHLT_BTagMu_DiJet60_Mu7_v2", &triggerHLT_BTagMu_DiJet60_Mu7_v2, &b_triggerHLT_BTagMu_DiJet60_Mu7_v2);
   fChain->SetBranchAddress("triggerHLT_BTagMu_DiJet80_Mu9_v2", &triggerHLT_BTagMu_DiJet80_Mu9_v2, &b_triggerHLT_BTagMu_DiJet80_Mu9_v2);
   fChain->SetBranchAddress("triggerHLT_BTagMu_DiJet100_Mu9_v2", &triggerHLT_BTagMu_DiJet100_Mu9_v2, &b_triggerHLT_BTagMu_DiJet100_Mu9_v2);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve15U_v4", &prescaleHLT_DiJetAve15U_v4, &b_prescaleHLT_DiJetAve15U_v4);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve30U_v4", &prescaleHLT_DiJetAve30U_v4, &b_prescaleHLT_DiJetAve30U_v4);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve50U_v4", &prescaleHLT_DiJetAve50U_v4, &b_prescaleHLT_DiJetAve50U_v4);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve70U_v4", &prescaleHLT_DiJetAve70U_v4, &b_prescaleHLT_DiJetAve70U_v4);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve100U_v4", &prescaleHLT_DiJetAve100U_v4, &b_prescaleHLT_DiJetAve100U_v4);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve140U_v4", &prescaleHLT_DiJetAve140U_v4, &b_prescaleHLT_DiJetAve140U_v4);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve180U_v4", &prescaleHLT_DiJetAve180U_v4, &b_prescaleHLT_DiJetAve180U_v4);
   fChain->SetBranchAddress("prescaleHLT_DiJetAve300U_v4", &prescaleHLT_DiJetAve300U_v4, &b_prescaleHLT_DiJetAve300U_v4);
   fChain->SetBranchAddress("prescaleHLT_BTagMu_DiJet20_Mu5_v2", &prescaleHLT_BTagMu_DiJet20_Mu5_v2, &b_prescaleHLT_BTagMu_DiJet20_Mu5_v2);
   fChain->SetBranchAddress("prescaleHLT_BTagMu_DiJet60_Mu7_v2", &prescaleHLT_BTagMu_DiJet60_Mu7_v2, &b_prescaleHLT_BTagMu_DiJet60_Mu7_v2);
   fChain->SetBranchAddress("prescaleHLT_BTagMu_DiJet80_Mu9_v2", &prescaleHLT_BTagMu_DiJet80_Mu9_v2, &b_prescaleHLT_BTagMu_DiJet80_Mu9_v2);
   fChain->SetBranchAddress("prescaleHLT_BTagMu_DiJet100_Mu9_v2", &prescaleHLT_BTagMu_DiJet100_Mu9_v2, &b_prescaleHLT_BTagMu_DiJet100_Mu9_v2);
   }
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("lumiBlockNumber", &lumiBlockNumber, &b_lumiBlockNumber);
   fChain->SetBranchAddress("numberOfPUVertices", &numberOfPUVertices, &b_numberOfPUVertices);
   fChain->SetBranchAddress("numberOfPrimaryVertices", &numberOfPrimaryVertices, &b_numberOfPrimaryVertices);
   fChain->SetBranchAddress("numberOfTracksAtPV", &numberOfTracksAtPV, &b_numberOfTracksAtPV);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("PVChi2", &PVChi2, &b_PVChi2);
   fChain->SetBranchAddress("PVndof", &PVndof, &b_PVndof);
   fChain->SetBranchAddress("PVNormalizedChi2", &PVNormalizedChi2, &b_PVNormalizedChi2);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("isBGluonSplitting", &isBGluonSplitting, &b_isBGluonSplitting);
   fChain->SetBranchAddress("isCGluonSplitting", &isCGluonSplitting, &b_isCGluonSplitting);
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
   fChain->SetBranchAddress("trackIsVertexTrack", trackIsVertexTrack, &b_trackIsVertexTrack);
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
   fChain->SetBranchAddress("SVvtxPt", SVvtxPt, &b_SVvtxPt);
   fChain->SetBranchAddress("SVvtxSumDirEta", SVvtxSumDirEta, &b_SVvtxSumDirEta);
   fChain->SetBranchAddress("SVvtxSumDirPhi", SVvtxSumDirPhi, &b_SVvtxSumDirPhi);
   fChain->SetBranchAddress("SVvtxDirEta", SVvtxDirEta, &b_SVvtxDirEta);
   fChain->SetBranchAddress("SVvtxDirPhi", SVvtxDirPhi, &b_SVvtxDirPhi);
   fChain->SetBranchAddress("SVvtxSumPTrel", SVvtxSumPTrel, &b_SVvtxSumPTrel);
   fChain->SetBranchAddress("SVvtxDirPTrel", SVvtxDirPTrel, &b_SVvtxDirPTrel);
   fChain->SetBranchAddress("SVvtxDistJetAxis", SVvtxDistJetAxis, &b_SVvtxDistJetAxis);
   fChain->SetBranchAddress("SVtotCharge", SVtotCharge, &b_SVtotCharge);
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
   if (dataflag<2) {
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
   }
   else {
   fChain->SetBranchAddress("nElectrons", nElectrons, &b_nElectrons);
   fChain->SetBranchAddress("electron1Pt", electron1Pt, &b_electron1Pt);
   fChain->SetBranchAddress("electron1Eta", electron1Eta, &b_electron1Eta);
   fChain->SetBranchAddress("electron1Phi", electron1Phi, &b_electron1Phi);
   fChain->SetBranchAddress("electron1NHits", electron1NHits, &b_electron1NHits);
   fChain->SetBranchAddress("electron1NExpectedOuterHits", electron1NExpectedOuterHits, &b_electron1NExpectedOuterHits);
   fChain->SetBranchAddress("electron1NPixelHits", electron1NPixelHits, &b_electron1NPixelHits);
   fChain->SetBranchAddress("electron1NChi2", electron1NChi2, &b_electron1NChi2);
   fChain->SetBranchAddress("electron1PtRel", electron1PtRel, &b_electron1PtRel);
   fChain->SetBranchAddress("electron1Sip2d", electron1Sip2d, &b_electron1Sip2d);
   fChain->SetBranchAddress("electron1Ip2d", electron1Ip2d, &b_electron1Ip2d);
   fChain->SetBranchAddress("electron1Ipe2d", electron1Ipe2d, &b_electron1Ipe2d);
   fChain->SetBranchAddress("electron1Sip3d", electron1Sip3d, &b_electron1Sip3d);
   fChain->SetBranchAddress("electron1Ip3d", electron1Ip3d, &b_electron1Ip3d);
   fChain->SetBranchAddress("electron1Ipe3d", electron1Ipe3d, &b_electron1Ipe3d);
   fChain->SetBranchAddress("electron1P0Par", electron1P0Par, &b_electron1P0Par);
   fChain->SetBranchAddress("electron1DeltaR", electron1DeltaR, &b_electron1DeltaR);
   fChain->SetBranchAddress("electron1EtaRel", electron1EtaRel, &b_electron1EtaRel);
   fChain->SetBranchAddress("electron1Ratio", electron1Ratio, &b_electron1Ratio);
   fChain->SetBranchAddress("electron1TrackQuality", electron1TrackQuality, &b_electron1TrackQuality);
   fChain->SetBranchAddress("electron1RatioRel", electron1RatioRel, &b_electron1RatioRel);
   fChain->SetBranchAddress("electron1eSuperClusterOverP", electron1eSuperClusterOverP, &b_electron1eSuperClusterOverP);
   fChain->SetBranchAddress("electron1eSeedClusterOverP", electron1eSeedClusterOverP, &b_electron1eSeedClusterOverP);
   fChain->SetBranchAddress("electron1eSeedClusterOverPout", electron1eSeedClusterOverPout, &b_electron1eSeedClusterOverPout);
   fChain->SetBranchAddress("electron1eEleClusterOverPout", electron1eEleClusterOverPout, &b_electron1eEleClusterOverPout);
   fChain->SetBranchAddress("electron1deltaEtaSuperClusterTrackAtVtx", electron1deltaEtaSuperClusterTrackAtVtx, &b_electron1deltaEtaSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron1deltaEtaSeedClusterTrackAtCalo", electron1deltaEtaSeedClusterTrackAtCalo, &b_electron1deltaEtaSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron1deltaEtaEleClusterTrackAtCalo", electron1deltaEtaEleClusterTrackAtCalo, &b_electron1deltaEtaEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electron1deltaPhiSuperClusterTrackAtVtx", electron1deltaPhiSuperClusterTrackAtVtx, &b_electron1deltaPhiSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron1deltaPhiSeedClusterTrackAtCalo", electron1deltaPhiSeedClusterTrackAtCalo, &b_electron1deltaPhiSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron1deltaPhiEleClusterTrackAtCalo", electron1deltaPhiEleClusterTrackAtCalo, &b_electron1deltaPhiEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electron2Pt", electron2Pt, &b_electron2Pt);
   fChain->SetBranchAddress("electron2Eta", electron2Eta, &b_electron2Eta);
   fChain->SetBranchAddress("electron2Phi", electron2Phi, &b_electron2Phi);
   fChain->SetBranchAddress("electron2NHits", electron2NHits, &b_electron2NHits);
   fChain->SetBranchAddress("electron2NExpectedOuterHits", electron2NExpectedOuterHits, &b_electron2NExpectedOuterHits);
   fChain->SetBranchAddress("electron2NPixelHits", electron2NPixelHits, &b_electron2NPixelHits);
   fChain->SetBranchAddress("electron2NChi2", electron2NChi2, &b_electron2NChi2);
   fChain->SetBranchAddress("electron2PtRel", electron2PtRel, &b_electron2PtRel);
   fChain->SetBranchAddress("electron2Sip2d", electron2Sip2d, &b_electron2Sip2d);
   fChain->SetBranchAddress("electron2Ip2d", electron2Ip2d, &b_electron2Ip2d);
   fChain->SetBranchAddress("electron2Ipe2d", electron2Ipe2d, &b_electron2Ipe2d);
   fChain->SetBranchAddress("electron2Sip3d", electron2Sip3d, &b_electron2Sip3d);
   fChain->SetBranchAddress("electron2Ip3d", electron2Ip3d, &b_electron2Ip3d);
   fChain->SetBranchAddress("electron2Ipe3d", electron2Ipe3d, &b_electron2Ipe3d);
   fChain->SetBranchAddress("electron2P0Par", electron2P0Par, &b_electron2P0Par);
   fChain->SetBranchAddress("electron2DeltaR", electron2DeltaR, &b_electron2DeltaR);
   fChain->SetBranchAddress("electron2EtaRel", electron2EtaRel, &b_electron2EtaRel);
   fChain->SetBranchAddress("electron2Ratio", electron2Ratio, &b_electron2Ratio);
   fChain->SetBranchAddress("electron2TrackQuality", electron2TrackQuality, &b_electron2TrackQuality);
   fChain->SetBranchAddress("electron2RatioRel", electron2RatioRel, &b_electron2RatioRel);
   fChain->SetBranchAddress("electron2eSuperClusterOverP", electron2eSuperClusterOverP, &b_electron2eSuperClusterOverP);
   fChain->SetBranchAddress("electron2eSeedClusterOverP", electron2eSeedClusterOverP, &b_electron2eSeedClusterOverP);
   fChain->SetBranchAddress("electron2eSeedClusterOverPout", electron2eSeedClusterOverPout, &b_electron2eSeedClusterOverPout);
   fChain->SetBranchAddress("electron2eEleClusterOverPout", electron2eEleClusterOverPout, &b_electron2eEleClusterOverPout);
   fChain->SetBranchAddress("electron2deltaEtaSuperClusterTrackAtVtx", electron2deltaEtaSuperClusterTrackAtVtx, &b_electron2deltaEtaSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron2deltaEtaSeedClusterTrackAtCalo", electron2deltaEtaSeedClusterTrackAtCalo, &b_electron2deltaEtaSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron2deltaEtaEleClusterTrackAtCalo", electron2deltaEtaEleClusterTrackAtCalo, &b_electron2deltaEtaEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electron2deltaPhiSuperClusterTrackAtVtx", electron2deltaPhiSuperClusterTrackAtVtx, &b_electron2deltaPhiSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron2deltaPhiSeedClusterTrackAtCalo", electron2deltaPhiSeedClusterTrackAtCalo, &b_electron2deltaPhiSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron2deltaPhiEleClusterTrackAtCalo", electron2deltaPhiEleClusterTrackAtCalo, &b_electron2deltaPhiEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electron3Pt", electron3Pt, &b_electron3Pt);
   fChain->SetBranchAddress("electron3Eta", electron3Eta, &b_electron3Eta);
   fChain->SetBranchAddress("electron3Phi", electron3Phi, &b_electron3Phi);
   fChain->SetBranchAddress("electron3NHits", electron3NHits, &b_electron3NHits);
   fChain->SetBranchAddress("electron3NExpectedOuterHits", electron3NExpectedOuterHits, &b_electron3NExpectedOuterHits);
   fChain->SetBranchAddress("electron3NPixelHits", electron3NPixelHits, &b_electron3NPixelHits);
   fChain->SetBranchAddress("electron3NChi2", electron3NChi2, &b_electron3NChi2);
   fChain->SetBranchAddress("electron3PtRel", electron3PtRel, &b_electron3PtRel);
   fChain->SetBranchAddress("electron3Sip2d", electron3Sip2d, &b_electron3Sip2d);
   fChain->SetBranchAddress("electron3Ip2d", electron3Ip2d, &b_electron3Ip2d);
   fChain->SetBranchAddress("electron3Ipe2d", electron3Ipe2d, &b_electron3Ipe2d);
   fChain->SetBranchAddress("electron3Sip3d", electron3Sip3d, &b_electron3Sip3d);
   fChain->SetBranchAddress("electron3Ip3d", electron3Ip3d, &b_electron3Ip3d);
   fChain->SetBranchAddress("electron3Ipe3d", electron3Ipe3d, &b_electron3Ipe3d);
   fChain->SetBranchAddress("electron3P0Par", electron3P0Par, &b_electron3P0Par);
   fChain->SetBranchAddress("electron3DeltaR", electron3DeltaR, &b_electron3DeltaR);
   fChain->SetBranchAddress("electron3EtaRel", electron3EtaRel, &b_electron3EtaRel);
   fChain->SetBranchAddress("electron3Ratio", electron3Ratio, &b_electron3Ratio);
   fChain->SetBranchAddress("electron3TrackQuality", electron3TrackQuality, &b_electron3TrackQuality);
   fChain->SetBranchAddress("electron3RatioRel", electron3RatioRel, &b_electron3RatioRel);
   fChain->SetBranchAddress("electron3eSuperClusterOverP", electron3eSuperClusterOverP, &b_electron3eSuperClusterOverP);
   fChain->SetBranchAddress("electron3eSeedClusterOverP", electron3eSeedClusterOverP, &b_electron3eSeedClusterOverP);
   fChain->SetBranchAddress("electron3eSeedClusterOverPout", electron3eSeedClusterOverPout, &b_electron3eSeedClusterOverPout);
   fChain->SetBranchAddress("electron3eEleClusterOverPout", electron3eEleClusterOverPout, &b_electron3eEleClusterOverPout);
   fChain->SetBranchAddress("electron3deltaEtaSuperClusterTrackAtVtx", electron3deltaEtaSuperClusterTrackAtVtx, &b_electron3deltaEtaSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron3deltaEtaSeedClusterTrackAtCalo", electron3deltaEtaSeedClusterTrackAtCalo, &b_electron3deltaEtaSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron3deltaEtaEleClusterTrackAtCalo", electron3deltaEtaEleClusterTrackAtCalo, &b_electron3deltaEtaEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electron3deltaPhiSuperClusterTrackAtVtx", electron3deltaPhiSuperClusterTrackAtVtx, &b_electron3deltaPhiSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron3deltaPhiSeedClusterTrackAtCalo", electron3deltaPhiSeedClusterTrackAtCalo, &b_electron3deltaPhiSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron3deltaPhiEleClusterTrackAtCalo", electron3deltaPhiEleClusterTrackAtCalo, &b_electron3deltaPhiEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electron4Pt", electron4Pt, &b_electron4Pt);
   fChain->SetBranchAddress("electron4Eta", electron4Eta, &b_electron4Eta);
   fChain->SetBranchAddress("electron4Phi", electron4Phi, &b_electron4Phi);
   fChain->SetBranchAddress("electron4NHits", electron4NHits, &b_electron4NHits);
   fChain->SetBranchAddress("electron4NExpectedOuterHits", electron4NExpectedOuterHits, &b_electron4NExpectedOuterHits);
   fChain->SetBranchAddress("electron4NPixelHits", electron4NPixelHits, &b_electron4NPixelHits);
   fChain->SetBranchAddress("electron4NChi2", electron4NChi2, &b_electron4NChi2);
   fChain->SetBranchAddress("electron4PtRel", electron4PtRel, &b_electron4PtRel);
   fChain->SetBranchAddress("electron4Sip2d", electron4Sip2d, &b_electron4Sip2d);
   fChain->SetBranchAddress("electron4Ip2d", electron4Ip2d, &b_electron4Ip2d);
   fChain->SetBranchAddress("electron4Ipe2d", electron4Ipe2d, &b_electron4Ipe2d);
   fChain->SetBranchAddress("electron4Sip3d", electron4Sip3d, &b_electron4Sip3d);
   fChain->SetBranchAddress("electron4Ip3d", electron4Ip3d, &b_electron4Ip3d);
   fChain->SetBranchAddress("electron4Ipe3d", electron4Ipe3d, &b_electron4Ipe3d);
   fChain->SetBranchAddress("electron4P0Par", electron4P0Par, &b_electron4P0Par);
   fChain->SetBranchAddress("electron4DeltaR", electron4DeltaR, &b_electron4DeltaR);
   fChain->SetBranchAddress("electron4EtaRel", electron4EtaRel, &b_electron4EtaRel);
   fChain->SetBranchAddress("electron4Ratio", electron4Ratio, &b_electron4Ratio);
   fChain->SetBranchAddress("electron4TrackQuality", electron4TrackQuality, &b_electron4TrackQuality);
   fChain->SetBranchAddress("electron4RatioRel", electron4RatioRel, &b_electron4RatioRel);
   fChain->SetBranchAddress("electron4eSuperClusterOverP", electron4eSuperClusterOverP, &b_electron4eSuperClusterOverP);
   fChain->SetBranchAddress("electron4eSeedClusterOverP", electron4eSeedClusterOverP, &b_electron4eSeedClusterOverP);
   fChain->SetBranchAddress("electron4eSeedClusterOverPout", electron4eSeedClusterOverPout, &b_electron4eSeedClusterOverPout);
   fChain->SetBranchAddress("electron4eEleClusterOverPout", electron4eEleClusterOverPout, &b_electron4eEleClusterOverPout);
   fChain->SetBranchAddress("electron4deltaEtaSuperClusterTrackAtVtx", electron4deltaEtaSuperClusterTrackAtVtx, &b_electron4deltaEtaSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron4deltaEtaSeedClusterTrackAtCalo", electron4deltaEtaSeedClusterTrackAtCalo, &b_electron4deltaEtaSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron4deltaEtaEleClusterTrackAtCalo", electron4deltaEtaEleClusterTrackAtCalo, &b_electron4deltaEtaEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electron4deltaPhiSuperClusterTrackAtVtx", electron4deltaPhiSuperClusterTrackAtVtx, &b_electron4deltaPhiSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electron4deltaPhiSeedClusterTrackAtCalo", electron4deltaPhiSeedClusterTrackAtCalo, &b_electron4deltaPhiSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electron4deltaPhiEleClusterTrackAtCalo", electron4deltaPhiEleClusterTrackAtCalo, &b_electron4deltaPhiEleClusterTrackAtCalo);
   }
   fChain->SetBranchAddress("nMuons", nMuons, &b_nMuons);
   fChain->SetBranchAddress("muon1IsGlobal", muon1IsGlobal, &b_muon1IsGlobal);
   fChain->SetBranchAddress("muon1IsTracker", muon1IsTracker, &b_muon1IsTracker);
   fChain->SetBranchAddress("muon1IsStandalone", muon1IsStandalone, &b_muon1IsStandalone);
   fChain->SetBranchAddress("muon1Pt", muon1Pt, &b_muon1Pt);
   fChain->SetBranchAddress("muon1Eta", muon1Eta, &b_muon1Eta);
   fChain->SetBranchAddress("muon1Phi", muon1Phi, &b_muon1Phi);
   fChain->SetBranchAddress("muon1NumberOfMatches", muon1NumberOfMatches, &b_muon1NumberOfMatches);
   fChain->SetBranchAddress("muon1GlobalMuonHits", muon1GlobalMuonHits, &b_muon1GlobalMuonHits);
   fChain->SetBranchAddress("muon1InnerValidHits", muon1InnerValidHits, &b_muon1InnerValidHits);
   fChain->SetBranchAddress("muon1NExpectedOuterHits", muon1NExpectedOuterHits, &b_muon1NExpectedOuterHits);
   fChain->SetBranchAddress("muon1NPixelHits", muon1NPixelHits, &b_muon1NPixelHits);
   fChain->SetBranchAddress("muon1InnerNChi2", muon1InnerNChi2, &b_muon1InnerNChi2);
   fChain->SetBranchAddress("muon1GlobalNChi2", muon1GlobalNChi2, &b_muon1GlobalNChi2);
   fChain->SetBranchAddress("muon1VzPVDist", muon1VzPVDist, &b_muon1VzPVDist);
   fChain->SetBranchAddress("muon1PtRel", muon1PtRel, &b_muon1PtRel);
   fChain->SetBranchAddress("muon1Sip2d", muon1Sip2d, &b_muon1Sip2d);
   fChain->SetBranchAddress("muon1Ip2d", muon1Ip2d, &b_muon1Ip2d);
   fChain->SetBranchAddress("muon1Ipe2d", muon1Ipe2d, &b_muon1Ipe2d);
   fChain->SetBranchAddress("muon1Sip3d", muon1Sip3d, &b_muon1Sip3d);
   fChain->SetBranchAddress("muon1Ip3d", muon1Ip3d, &b_muon1Ip3d);
   fChain->SetBranchAddress("muon1Ipe3d", muon1Ipe3d, &b_muon1Ipe3d);
   fChain->SetBranchAddress("muon1P0Par", muon1P0Par, &b_muon1P0Par);
   fChain->SetBranchAddress("muon1DeltaR", muon1DeltaR, &b_muon1DeltaR);
   fChain->SetBranchAddress("muon1EtaRel", muon1EtaRel, &b_muon1EtaRel);
   fChain->SetBranchAddress("muon1Ratio", muon1Ratio, &b_muon1Ratio);
   fChain->SetBranchAddress("muon1TrackQuality", muon1TrackQuality, &b_muon1TrackQuality);
   fChain->SetBranchAddress("muon1RatioRel", muon1RatioRel, &b_muon1RatioRel);
   fChain->SetBranchAddress("muon2IsGlobal", muon2IsGlobal, &b_muon2IsGlobal);
   fChain->SetBranchAddress("muon2IsTracker", muon2IsTracker, &b_muon2IsTracker);
   fChain->SetBranchAddress("muon2IsStandalone", muon2IsStandalone, &b_muon2IsStandalone);
   fChain->SetBranchAddress("muon2Pt", muon2Pt, &b_muon2Pt);
   fChain->SetBranchAddress("muon2Eta", muon2Eta, &b_muon2Eta);
   fChain->SetBranchAddress("muon2Phi", muon2Phi, &b_muon2Phi);
   fChain->SetBranchAddress("muon2NumberOfMatches", muon2NumberOfMatches, &b_muon2NumberOfMatches);
   fChain->SetBranchAddress("muon2GlobalMuonHits", muon2GlobalMuonHits, &b_muon2GlobalMuonHits);
   fChain->SetBranchAddress("muon2InnerValidHits", muon2InnerValidHits, &b_muon2InnerValidHits);
   fChain->SetBranchAddress("muon2NExpectedOuterHits", muon2NExpectedOuterHits, &b_muon2NExpectedOuterHits);
   fChain->SetBranchAddress("muon2NPixelHits", muon2NPixelHits, &b_muon2NPixelHits);
   fChain->SetBranchAddress("muon2InnerNChi2", muon2InnerNChi2, &b_muon2InnerNChi2);
   fChain->SetBranchAddress("muon2GlobalNChi2", muon2GlobalNChi2, &b_muon2GlobalNChi2);
   fChain->SetBranchAddress("muon2VzPVDist", muon2VzPVDist, &b_muon2VzPVDist);
   fChain->SetBranchAddress("muon2PtRel", muon2PtRel, &b_muon2PtRel);
   fChain->SetBranchAddress("muon2Sip2d", muon2Sip2d, &b_muon2Sip2d);
   fChain->SetBranchAddress("muon2Ip2d", muon2Ip2d, &b_muon2Ip2d);
   fChain->SetBranchAddress("muon2Ipe2d", muon2Ipe2d, &b_muon2Ipe2d);
   fChain->SetBranchAddress("muon2Sip3d", muon2Sip3d, &b_muon2Sip3d);
   fChain->SetBranchAddress("muon2Ip3d", muon2Ip3d, &b_muon2Ip3d);
   fChain->SetBranchAddress("muon2Ipe3d", muon2Ipe3d, &b_muon2Ipe3d);
   fChain->SetBranchAddress("muon2P0Par", muon2P0Par, &b_muon2P0Par);
   fChain->SetBranchAddress("muon2DeltaR", muon2DeltaR, &b_muon2DeltaR);
   fChain->SetBranchAddress("muon2EtaRel", muon2EtaRel, &b_muon2EtaRel);
   fChain->SetBranchAddress("muon2Ratio", muon2Ratio, &b_muon2Ratio);
   fChain->SetBranchAddress("muon2TrackQuality", muon2TrackQuality, &b_muon2TrackQuality);
   fChain->SetBranchAddress("muon2RatioRel", muon2RatioRel, &b_muon2RatioRel);
   fChain->SetBranchAddress("muon3IsGlobal", muon3IsGlobal, &b_muon3IsGlobal);
   fChain->SetBranchAddress("muon3IsTracker", muon3IsTracker, &b_muon3IsTracker);
   fChain->SetBranchAddress("muon3IsStandalone", muon3IsStandalone, &b_muon3IsStandalone);
   fChain->SetBranchAddress("muon3Pt", muon3Pt, &b_muon3Pt);
   fChain->SetBranchAddress("muon3Eta", muon3Eta, &b_muon3Eta);
   fChain->SetBranchAddress("muon3Phi", muon3Phi, &b_muon3Phi);
   fChain->SetBranchAddress("muon3NumberOfMatches", muon3NumberOfMatches, &b_muon3NumberOfMatches);
   fChain->SetBranchAddress("muon3GlobalMuonHits", muon3GlobalMuonHits, &b_muon3GlobalMuonHits);
   fChain->SetBranchAddress("muon3InnerValidHits", muon3InnerValidHits, &b_muon3InnerValidHits);
   fChain->SetBranchAddress("muon3NExpectedOuterHits", muon3NExpectedOuterHits, &b_muon3NExpectedOuterHits);
   fChain->SetBranchAddress("muon3NPixelHits", muon3NPixelHits, &b_muon3NPixelHits);
   fChain->SetBranchAddress("muon3InnerNChi2", muon3InnerNChi2, &b_muon3InnerNChi2);
   fChain->SetBranchAddress("muon3GlobalNChi2", muon3GlobalNChi2, &b_muon3GlobalNChi2);
   fChain->SetBranchAddress("muon3VzPVDist", muon3VzPVDist, &b_muon3VzPVDist);
   fChain->SetBranchAddress("muon3PtRel", muon3PtRel, &b_muon3PtRel);
   fChain->SetBranchAddress("muon3Sip2d", muon3Sip2d, &b_muon3Sip2d);
   fChain->SetBranchAddress("muon3Ip2d", muon3Ip2d, &b_muon3Ip2d);
   fChain->SetBranchAddress("muon3Ipe2d", muon3Ipe2d, &b_muon3Ipe2d);
   fChain->SetBranchAddress("muon3Sip3d", muon3Sip3d, &b_muon3Sip3d);
   fChain->SetBranchAddress("muon3Ip3d", muon3Ip3d, &b_muon3Ip3d);
   fChain->SetBranchAddress("muon3Ipe3d", muon3Ipe3d, &b_muon3Ipe3d);
   fChain->SetBranchAddress("muon3P0Par", muon3P0Par, &b_muon3P0Par);
   fChain->SetBranchAddress("muon3DeltaR", muon3DeltaR, &b_muon3DeltaR);
   fChain->SetBranchAddress("muon3EtaRel", muon3EtaRel, &b_muon3EtaRel);
   fChain->SetBranchAddress("muon3Ratio", muon3Ratio, &b_muon3Ratio);
   fChain->SetBranchAddress("muon3TrackQuality", muon3TrackQuality, &b_muon3TrackQuality);
   fChain->SetBranchAddress("muon3RatioRel", muon3RatioRel, &b_muon3RatioRel);
   fChain->SetBranchAddress("muon4IsGlobal", muon4IsGlobal, &b_muon4IsGlobal);
   fChain->SetBranchAddress("muon4IsTracker", muon4IsTracker, &b_muon4IsTracker);
   fChain->SetBranchAddress("muon4IsStandalone", muon4IsStandalone, &b_muon4IsStandalone);
   fChain->SetBranchAddress("muon4Pt", muon4Pt, &b_muon4Pt);
   fChain->SetBranchAddress("muon4Eta", muon4Eta, &b_muon4Eta);
   fChain->SetBranchAddress("muon4Phi", muon4Phi, &b_muon4Phi);
   fChain->SetBranchAddress("muon4NumberOfMatches", muon4NumberOfMatches, &b_muon4NumberOfMatches);
   fChain->SetBranchAddress("muon4GlobalMuonHits", muon4GlobalMuonHits, &b_muon4GlobalMuonHits);
   fChain->SetBranchAddress("muon4InnerValidHits", muon4InnerValidHits, &b_muon4InnerValidHits);
   fChain->SetBranchAddress("muon4NExpectedOuterHits", muon4NExpectedOuterHits, &b_muon4NExpectedOuterHits);
   fChain->SetBranchAddress("muon4NPixelHits", muon4NPixelHits, &b_muon4NPixelHits);
   fChain->SetBranchAddress("muon4InnerNChi2", muon4InnerNChi2, &b_muon4InnerNChi2);
   fChain->SetBranchAddress("muon4GlobalNChi2", muon4GlobalNChi2, &b_muon4GlobalNChi2);
   fChain->SetBranchAddress("muon4VzPVDist", muon4VzPVDist, &b_muon4VzPVDist);
   fChain->SetBranchAddress("muon4PtRel", muon4PtRel, &b_muon4PtRel);
   fChain->SetBranchAddress("muon4Sip2d", muon4Sip2d, &b_muon4Sip2d);
   fChain->SetBranchAddress("muon4Ip2d", muon4Ip2d, &b_muon4Ip2d);
   fChain->SetBranchAddress("muon4Ipe2d", muon4Ipe2d, &b_muon4Ipe2d);
   fChain->SetBranchAddress("muon4Sip3d", muon4Sip3d, &b_muon4Sip3d);
   fChain->SetBranchAddress("muon4Ip3d", muon4Ip3d, &b_muon4Ip3d);
   fChain->SetBranchAddress("muon4Ipe3d", muon4Ipe3d, &b_muon4Ipe3d);
   fChain->SetBranchAddress("muon4P0Par", muon4P0Par, &b_muon4P0Par);
   fChain->SetBranchAddress("muon4DeltaR", muon4DeltaR, &b_muon4DeltaR);
   fChain->SetBranchAddress("muon4EtaRel", muon4EtaRel, &b_muon4EtaRel);
   fChain->SetBranchAddress("muon4Ratio", muon4Ratio, &b_muon4Ratio);
   fChain->SetBranchAddress("muon4TrackQuality", muon4TrackQuality, &b_muon4TrackQuality);
   fChain->SetBranchAddress("muon4RatioRel", muon4RatioRel, &b_muon4RatioRel);
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
   Notify();
}

Bool_t btagNtupReader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void btagNtupReader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t btagNtupReader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef btagNtupReader_cxx
