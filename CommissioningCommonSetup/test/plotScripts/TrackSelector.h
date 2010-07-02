//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul  1 12:16:58 2010 by ROOT version 5.22/00d
// from TTree Events/
// found on file: /nfs/data6/alschmid/btagCommissioning/files/btagJEC16June_pt30/QCD_Pt30job_90_BTagCommissioning2010_June16_7TeV_MC.root
//////////////////////////////////////////////////////////

#ifndef TrackSelector_h
#define TrackSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <vector>
#include <iostream>
#include "informationTrackCuts.h"
#include "TH1D.h"

using namespace std;

   const Int_t kMaxbool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation = 1;
   const Int_t kMaxbool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation = 1;
   const Int_t kMaxbool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation = 1;


 
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation = 1; */
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj = 13; */
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation = 1; */
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj = 13; */
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation = 1; */
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj = 13; */
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation = 1; */
/*    const Int_t kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj = 123; */

/*    const Int_t kMaxdoubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation = 1; */
/*    const Int_t kMaxdoubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj = 13; */

   const Int_t kMaxbools_standardPFBTagNtuple_standardPFtrackSelected_validation = 1;

   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2d1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2d2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2d3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dError1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dError2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dError3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dProbability1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dProbability2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dProbability3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3d1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3d2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3d3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dError1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dError2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dError3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dEta1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dEta2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dEta3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dPhi1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dPhi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dPhi3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dProbability1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dProbability2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dProbability3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSV2dDistance_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSV3dDistance_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVMass_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVNormChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronDeltaR_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronEta_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronEtaRel_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronIp2d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronIp3d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronIpe2d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronIpe3d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronNChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronP0Par_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronPhi_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronPt_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronPtRel_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronRatio_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronRatioRel_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronSip2d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFelectronSip3d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetEMFraction_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetEta_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetMass_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetPhi_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetPt_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetVertexChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonDeltaR_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonEta_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonEtaRel_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonIp2d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonIp3d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonIpe2d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonIpe3d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonNChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonP0Par_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonPhi_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonPt_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonPtRel_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonRatio_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonRatioRel_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonSip2d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFmuonSip3d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackDecayLength_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackDeltaR_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackEta_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackIP2d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackIP2dError_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackIP3d_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackIP3dError_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackMomentum_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackNormChi2_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackPhi_validation = 1;
   const Int_t kMaxfloats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation = 1;

   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dNHits1_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dNHits2_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dNHits3_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFSVnVertices_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFelectronNHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFjetnConstituents_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFjetnTracks_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFmuonNHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFnElectrons_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFnMuons_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackJetIndex_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackNHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation = 1;
   const Int_t kMaxints_standardPFBTagNtuple_standardPFtrackQuality_validation = 1;



   const Int_t kMaxuint_standardPFBTagNtuple_standardPFeventNumber_validation = 1;
   const Int_t kMaxuint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation = 1;
   const Int_t kMaxuint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation = 1;
   const Int_t kMaxuint_standardPFBTagNtuple_standardPFrunNumber_validation = 1;

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


 //edm::Wrapper<bool> *bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation.;
   Bool_t          bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_present;
   Bool_t          bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_obj;
 //edm::Wrapper<bool> *bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation.;
   Bool_t          bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_present;
   Bool_t          bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_obj;
 //edm::Wrapper<bool> *bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation.;
   Bool_t          bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_present;
   Bool_t          bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_obj;
 

 //edm::Wrapper<vector<ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag> > > *doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation.;
/*    Bool_t          doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_present; */
/*    Int_t           doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_; */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_fCoordinates_fX[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_fCoordinates_fY[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_fCoordinates_fZ[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation.obj_] */
/*  //edm::Wrapper<vector<ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag> > > *doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation.; */
/*    Bool_t          doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_present; */
/*    Int_t           doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_; */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_fCoordinates_fX[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_fCoordinates_fY[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_fCoordinates_fZ[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation.obj_] */
/*  //edm::Wrapper<vector<ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag> > > *doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation.; */
/*    Bool_t          doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_present; */
/*    Int_t           doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_; */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_fCoordinates_fX[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_fCoordinates_fY[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_fCoordinates_fZ[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation.obj_] */
/*  //edm::Wrapper<vector<ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<double>,ROOT::Math::DefaultCoordinateSystemTag> > > *doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation.; */
/*    Bool_t          doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_present; */
/*    Int_t           doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_; */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_fCoordinates_fX[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_fCoordinates_fY[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation.obj_] */
/*    Double_t        doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_fCoordinates_fZ[kMaxdoubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj];   //[doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation.obj_] */
/*  //edm::Wrapper<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > > > *doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardCaloBTagNtuple_standardCalojetP4_validation.; */

/*  //edm::Wrapper<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > > > *doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation.; */
/*    Bool_t          doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_present; */
/*    Int_t           doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_; */
/*    Double_t        doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fX[kMaxdoubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj];   //[doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation.obj_] */
/*    Double_t        doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fY[kMaxdoubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj];   //[doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation.obj_] */
/*    Double_t        doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fZ[kMaxdoubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj];   //[doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation.obj_] */
/*    Double_t        doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fT[kMaxdoubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj];   //[doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation.obj_] */
/*  //edm::Wrapper<vector<bool> > *bools_standardCaloBTagNtuple_standardCalotrackSelected_validation.; */

 //edm::Wrapper<vector<bool> > *bools_standardPFBTagNtuple_standardPFtrackSelected_validation.;
   Bool_t          bools_standardPFBTagNtuple_standardPFtrackSelected_validation_present;
 //vector<bool>    bools_standardPFBTagNtuple_standardPFtrackSelected_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardCaloBTagNtuple_standardCaloIP2d1_validation.;

 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2d1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2d1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2d1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2d2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2d2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2d2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2d3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2d3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2d3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dError1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dError1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dError1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dError2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dError2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dError2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dError3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dError3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dError3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3d1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3d1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3d1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3d2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3d2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3d2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3d3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3d3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3d3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dError1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dError1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dError1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dError2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dError2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dError2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dError3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dError3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dError3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dEta1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dEta2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dEta3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSV2dDistance_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSV3dDistance_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVMass_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVMass_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVMass_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVNormChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronEta_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronEta_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronEta_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronIp2d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronIp3d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronNChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronP0Par_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronPhi_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronPhi_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronPhi_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronPt_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronPt_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronPt_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronPtRel_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronRatio_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronRatio_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronRatio_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronSip2d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFelectronSip3d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetEMFraction_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetEta_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetEta_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetEta_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetMass_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetMass_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetMass_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetPhi_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetPhi_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetPhi_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetPt_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetPt_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetPt_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonEta_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonEta_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonEta_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonIp2d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonIp3d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonNChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonP0Par_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonPhi_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonPhi_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonPhi_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonPt_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonPt_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonPt_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonPtRel_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonRatio_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonRatio_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonRatio_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonSip2d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFmuonSip3d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackEta_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackEta_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackEta_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackIP2d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackIP3d_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackMomentum_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackPhi_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackPhi_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackPhi_validation_obj;
 //edm::Wrapper<vector<float> > *floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation.;
   Bool_t          floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_present;
   vector<float>   floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_obj;

 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFSVnVertices_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFSVnVertices_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFSVnVertices_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFelectronNHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFelectronNHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFelectronNHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFjetnConstituents_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFjetnTracks_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFjetnTracks_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFjetnTracks_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFmuonNHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFmuonNHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFmuonNHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFnElectrons_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFnElectrons_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFnElectrons_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFnMuons_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFnMuons_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFnMuons_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackNHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackNHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_obj;
 //edm::Wrapper<vector<int> > *ints_standardPFBTagNtuple_standardPFtrackQuality_validation.;
   Bool_t          ints_standardPFBTagNtuple_standardPFtrackQuality_validation_present;
   vector<int>     ints_standardPFBTagNtuple_standardPFtrackQuality_validation_obj;

   Bool_t          uint_standardPFBTagNtuple_standardPFeventNumber_validation_present;
   UInt_t          uint_standardPFBTagNtuple_standardPFeventNumber_validation_obj;
 //edm::Wrapper<unsigned int> *uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation.;
   Bool_t          uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_present;
   UInt_t          uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_obj;
 //edm::Wrapper<unsigned int> *uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation.;
   Bool_t          uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_present;
   UInt_t          uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_obj;
 //edm::Wrapper<unsigned int> *uint_standardPFBTagNtuple_standardPFrunNumber_validation.;
   Bool_t          uint_standardPFBTagNtuple_standardPFrunNumber_validation_present;
   UInt_t          uint_standardPFBTagNtuple_standardPFrunNumber_validation_obj;

   // List of branches

   TBranch        *b_bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_present;   //!
   TBranch        *b_bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_obj;   //!
   TBranch        *b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_present;   //!
   TBranch        *b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_obj;   //!
   TBranch        *b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_present;   //!
   TBranch        *b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_obj;   //!

 /*   TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_present;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_fCoordinates_fX;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_fCoordinates_fY;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFIPghostTrackP3_validation_obj_fCoordinates_fZ;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_present;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_fCoordinates_fX;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_fCoordinates_fY;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFSecondaryVertex_validation_obj_fCoordinates_fZ;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_present;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_fCoordinates_fX;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_fCoordinates_fY;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFjetVertex_validation_obj_fCoordinates_fZ;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_present;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_fCoordinates_fX;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_fCoordinates_fY;   //! */
/*    TBranch        *b_doubleROOTMathCartesian3DROOTMathDefaultCoordinateSystemTagROOTMathDisplacementVector3Ds_standardPFBTagNtuple_standardPFtrack3Momentum_validation_obj_fCoordinates_fZ;   //! */

/*    TBranch        *b_doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_present;   //! */
/*    TBranch        *b_doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_;   //! */
/*    TBranch        *b_doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fX;   //! */
/*    TBranch        *b_doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fY;   //! */
/*    TBranch        *b_doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fZ;   //! */
/*    TBranch        *b_doubleROOTMathPxPyPzE4DROOTMathLorentzVectors_standardPFBTagNtuple_standardPFjetP4_validation_obj_fCoordinates_fT;   //! */

   TBranch        *b_bools_standardPFBTagNtuple_standardPFtrackSelected_validation_present;   //!

   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2d1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2d1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2d2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2d2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2d3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2d3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dError1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dError1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dError2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dError2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dError3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dError3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3d1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3d1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3d2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3d2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3d3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3d3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dError1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dError1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dError2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dError2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dError3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dError3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVMass_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVMass_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronEta_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronEta_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronPhi_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronPhi_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronPt_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronPt_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronRatio_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronRatio_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetEta_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetEta_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetMass_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetMass_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetPhi_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetPhi_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetPt_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetPt_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonEta_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonEta_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonPhi_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonPhi_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonPt_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonPt_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonRatio_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonRatio_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackEta_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackEta_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackPhi_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackPhi_validation_obj;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_present;   //!
   TBranch        *b_floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_obj;   //!

   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnVertices_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFSVnVertices_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronNHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronNHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFjetnTracks_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFjetnTracks_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonNHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonNHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFnElectrons_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFnElectrons_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFnMuons_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFnMuons_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackNHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_obj;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackQuality_validation_present;   //!
   TBranch        *b_ints_standardPFBTagNtuple_standardPFtrackQuality_validation_obj;   //!

   TBranch        *b_uint_standardPFBTagNtuple_standardPFeventNumber_validation_present;   //!
   TBranch        *b_uint_standardPFBTagNtuple_standardPFeventNumber_validation_obj;   //!
   TBranch        *b_uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_present;   //!
   TBranch        *b_uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_obj;   //!
   TBranch        *b_uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_present;   //!
   TBranch        *b_uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_obj;   //!
   TBranch        *b_uint_standardPFBTagNtuple_standardPFrunNumber_validation_present;   //!
   TBranch        *b_uint_standardPFBTagNtuple_standardPFrunNumber_validation_obj;   //!

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

   // Set object pointer
  //   EventAuxiliary = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);


   fChain->SetBranchAddress("bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation.present", &bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_present, &b_bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_present);
   fChain->SetBranchAddress("bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation.obj", &bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_obj, &b_bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_obj);
   fChain->SetBranchAddress("bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation.present", &bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_present, &b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_present);
   fChain->SetBranchAddress("bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation.obj", &bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_obj, &b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet10U_validation_obj);
   fChain->SetBranchAddress("bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation.present", &bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_present, &b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_present);
   fChain->SetBranchAddress("bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation.obj", &bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_obj, &b_bool_standardPFBTagNtuple_standardPFtriggerHLTL1Jet6U_validation_obj);


   fChain->SetBranchAddress("bools_standardPFBTagNtuple_standardPFtrackSelected_validation.present", &bools_standardPFBTagNtuple_standardPFtrackSelected_validation_present, &b_bools_standardPFBTagNtuple_standardPFtrackSelected_validation_present);

   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2d1_validation.present", &floats_standardPFBTagNtuple_standardPFIP2d1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2d1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2d1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2d1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2d1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2d2_validation.present", &floats_standardPFBTagNtuple_standardPFIP2d2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2d2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2d2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2d2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2d2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2d3_validation.present", &floats_standardPFBTagNtuple_standardPFIP2d3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2d3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2d3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2d3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2d3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dError1_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dError1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dError1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dError1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dError1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dError1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dError2_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dError2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dError2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dError2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dError2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dError2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dError3_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dError3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dError3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dError3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dError3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dError3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dProbability1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dProbability2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dProbability3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation.present", &floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP2dTrackPtRel3_validation_obj);

   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3d1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3d1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3d1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3d1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3d1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3d1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3d2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3d2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3d2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3d2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3d2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3d2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3d3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3d3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3d3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3d3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3d3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3d3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDecayLength3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDeltaR3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dDistJetAxis3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dError1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dError1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dError1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dError1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dError1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dError1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dError2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dError2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dError2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dError2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dError2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dError2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dError3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dError3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dError3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dError3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dError3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dError3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dEta1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dEta1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dEta1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dEta2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dEta2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dEta2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dEta3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dEta3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dEta3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dMomentum1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dMomentum2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dMomentum3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dNormChi21_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dNormChi22_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dNormChi23_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dPhi1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dPhi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dPhi3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dProbability1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dProbability2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dProbability3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dTrackPtRel3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum1_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation.present", &floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_present, &b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation.obj", &floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIP3dTransverseMomentum3_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation.present", &floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_present, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation.obj", &floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackDeltaR_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation.present", &floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_present, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation.obj", &floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackEta_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation.present", &floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_present, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation.obj", &floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackPhi_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation.present", &floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_present, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation.obj", &floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackPt_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation.present", &floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_present, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation.obj", &floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_obj, &b_floats_standardPFBTagNtuple_standardPFIPghostTrackPtRel_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation.present", &floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_present, &b_floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation.obj", &floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj, &b_floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV2dDistance_validation.present", &floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_present, &b_floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV2dDistance_validation.obj", &floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSV2dDistance_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation.present", &floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_present, &b_floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation.obj", &floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSV2dDistanceError_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV3dDistance_validation.present", &floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_present, &b_floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV3dDistance_validation.obj", &floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSV3dDistance_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation.present", &floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_present, &b_floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation.obj", &floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSV3dDistanceError_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVChi2_validation.present", &floats_standardPFBTagNtuple_standardPFSVChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFSVChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation.present", &floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation.obj", &floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVDegreesOfFreedom_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation.present", &floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation.obj", &floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVEnergyRatio_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation.present", &floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation.obj", &floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVIPFirstAboveCharm_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVMass_validation.present", &floats_standardPFBTagNtuple_standardPFSVMass_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVMass_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVMass_validation.obj", &floats_standardPFBTagNtuple_standardPFSVMass_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVMass_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVNormChi2_validation.present", &floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVNormChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVNormChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation.present", &floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation.obj", &floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVjetDeltaR_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation.present", &floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation.obj", &floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVvtxSumJetDeltaR_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation.present", &floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_present, &b_floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation.obj", &floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_obj, &b_floats_standardPFBTagNtuple_standardPFSVvtxSumVtxDirDeltaR_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation.present", &floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronDeltaR_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronEta_validation.present", &floats_standardPFBTagNtuple_standardPFelectronEta_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronEta_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronEta_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronEta_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronEta_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation.present", &floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronEtaRel_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIp2d_validation.present", &floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIp2d_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronIp2d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIp3d_validation.present", &floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIp3d_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronIp3d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation.present", &floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronIpe2d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation.present", &floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronIpe3d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronNChi2_validation.present", &floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronNChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronNChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronP0Par_validation.present", &floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronP0Par_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronP0Par_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronPhi_validation.present", &floats_standardPFBTagNtuple_standardPFelectronPhi_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronPhi_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronPhi_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronPhi_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronPhi_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronPt_validation.present", &floats_standardPFBTagNtuple_standardPFelectronPt_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronPt_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronPt_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronPt_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronPt_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronPtRel_validation.present", &floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronPtRel_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronPtRel_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronRatio_validation.present", &floats_standardPFBTagNtuple_standardPFelectronRatio_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronRatio_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronRatio_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronRatio_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronRatio_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation.present", &floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronRatioRel_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronSip2d_validation.present", &floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronSip2d_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronSip2d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronSip3d_validation.present", &floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_present, &b_floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFelectronSip3d_validation.obj", &floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFelectronSip3d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation.present", &floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation.obj", &floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetChargedEmEnergyFraction_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation.present", &floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation.obj", &floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetChargedHadronEnergyFraction_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation.present", &floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation.obj", &floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetChargedMultiplicity_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetEMFraction_validation.present", &floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetEMFraction_validation.obj", &floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetEMFraction_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetEta_validation.present", &floats_standardPFBTagNtuple_standardPFjetEta_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetEta_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetEta_validation.obj", &floats_standardPFBTagNtuple_standardPFjetEta_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetEta_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetMass_validation.present", &floats_standardPFBTagNtuple_standardPFjetMass_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetMass_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetMass_validation.obj", &floats_standardPFBTagNtuple_standardPFjetMass_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetMass_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation.present", &floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation.obj", &floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetNeutralEmEnergyFraction_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation.present", &floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation.obj", &floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetNeutralHadronEnergyFraction_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetPhi_validation.present", &floats_standardPFBTagNtuple_standardPFjetPhi_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetPhi_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetPhi_validation.obj", &floats_standardPFBTagNtuple_standardPFjetPhi_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetPhi_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetPt_validation.present", &floats_standardPFBTagNtuple_standardPFjetPt_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetPt_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetPt_validation.obj", &floats_standardPFBTagNtuple_standardPFjetPt_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetPt_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation.present", &floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetVertexChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation.present", &floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation.obj", &floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetVertexChi2Ndof_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation.present", &floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFjetVertexNormalizedChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation.present", &floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonDeltaR_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonEta_validation.present", &floats_standardPFBTagNtuple_standardPFmuonEta_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonEta_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonEta_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonEta_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonEta_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation.present", &floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonEtaRel_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIp2d_validation.present", &floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIp2d_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonIp2d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIp3d_validation.present", &floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIp3d_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonIp3d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation.present", &floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonIpe2d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation.present", &floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonIpe3d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonNChi2_validation.present", &floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonNChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonNChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonP0Par_validation.present", &floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonP0Par_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonP0Par_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonPhi_validation.present", &floats_standardPFBTagNtuple_standardPFmuonPhi_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonPhi_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonPhi_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonPhi_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonPhi_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonPt_validation.present", &floats_standardPFBTagNtuple_standardPFmuonPt_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonPt_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonPt_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonPt_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonPt_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonPtRel_validation.present", &floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonPtRel_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonPtRel_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonRatio_validation.present", &floats_standardPFBTagNtuple_standardPFmuonRatio_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonRatio_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonRatio_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonRatio_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonRatio_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation.present", &floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonRatioRel_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonSip2d_validation.present", &floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonSip2d_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonSip2d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonSip3d_validation.present", &floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_present, &b_floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFmuonSip3d_validation.obj", &floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFmuonSip3d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexMVAPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardCombinedSecondaryVertexPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardGhostTrackPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardJetBProbabilityPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardJetProbabilityPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighEffPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardSimpleSecondaryVertexHighPurPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByIP3dPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardSoftElectronByPtPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByIP3dPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonByPtPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardSoftMuonPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighEffPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation.present", &floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_present, &b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation.obj", &floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_obj, &b_floats_standardPFBTagNtuple_standardPFstandardTrackCountingHighPurPFBJetTags_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackChi2_validation.present", &floats_standardPFBTagNtuple_standardPFtrackChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation.present", &floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation.present", &floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackDeltaR_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation.present", &floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackEta_validation.present", &floats_standardPFBTagNtuple_standardPFtrackEta_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackEta_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackEta_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackEta_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackEta_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP2d_validation.present", &floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP2d_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation.present", &floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackIP2dError_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP3d_validation.present", &floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP3d_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackIP3d_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation.present", &floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackIP3dError_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation.present", &floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackMomentum_validation.present", &floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackMomentum_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackMomentum_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation.present", &floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackPhi_validation.present", &floats_standardPFBTagNtuple_standardPFtrackPhi_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackPhi_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackPhi_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackPhi_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackPhi_validation_obj);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation.present", &floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_present, &b_floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_present);
   fChain->SetBranchAddress("floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation.obj", &floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_obj, &b_floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_obj);

   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation.present", &ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation.obj", &ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality1_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation.present", &ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation.obj", &ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality2_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation.present", &ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation.obj", &ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP2dTrackQuality3_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix11_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix12_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix13_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix21_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix22_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix23_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix31_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix32_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPix33_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll1_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll2_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dHasSharedPixAll3_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dNHits1_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dNHits2_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dNHits3_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits1_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits2_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dNPixelHits3_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality1_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality2_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation.present", &ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_present, &b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation.obj", &ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIP3dTrackQuality3_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPix1SharedHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPix1TotalHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPix2SharedHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPix2TotalHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPix3SharedHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPix3TotalHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPixAllSharedHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation.present", &ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation.obj", &ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPPixAllTotalHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation.present", &ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_present, &b_ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation.obj", &ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_obj, &b_ints_standardPFBTagNtuple_standardPFIPnSelectedTracks_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation.present", &ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_present, &b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation.obj", &ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_obj, &b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracks_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation.present", &ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_present, &b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation.obj", &ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_obj, &b_ints_standardPFBTagNtuple_standardPFSVnFirstVertexTracksAll_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation.present", &ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_present, &b_ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation.obj", &ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_obj, &b_ints_standardPFBTagNtuple_standardPFSVnSelectedTracks_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation.present", &ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_present, &b_ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation.obj", &ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_obj, &b_ints_standardPFBTagNtuple_standardPFSVnVertexTracks_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation.present", &ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_present, &b_ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation.obj", &ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_obj, &b_ints_standardPFBTagNtuple_standardPFSVnVertexTracksAll_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnVertices_validation.present", &ints_standardPFBTagNtuple_standardPFSVnVertices_validation_present, &b_ints_standardPFBTagNtuple_standardPFSVnVertices_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFSVnVertices_validation.obj", &ints_standardPFBTagNtuple_standardPFSVnVertices_validation_obj, &b_ints_standardPFBTagNtuple_standardPFSVnVertices_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation.present", &ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation.obj", &ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFelectronNExpectedOuterHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronNHits_validation.present", &ints_standardPFBTagNtuple_standardPFelectronNHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFelectronNHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronNHits_validation.obj", &ints_standardPFBTagNtuple_standardPFelectronNHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFelectronNHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation.present", &ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation.obj", &ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFelectronNPixelHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation.present", &ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_present, &b_ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation.obj", &ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_obj, &b_ints_standardPFBTagNtuple_standardPFelectronTrackQuality_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFjetnConstituents_validation.present", &ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_present, &b_ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFjetnConstituents_validation.obj", &ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_obj, &b_ints_standardPFBTagNtuple_standardPFjetnConstituents_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFjetnTracks_validation.present", &ints_standardPFBTagNtuple_standardPFjetnTracks_validation_present, &b_ints_standardPFBTagNtuple_standardPFjetnTracks_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFjetnTracks_validation.obj", &ints_standardPFBTagNtuple_standardPFjetnTracks_validation_obj, &b_ints_standardPFBTagNtuple_standardPFjetnTracks_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation.present", &ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation.obj", &ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFmuonNExpectedOuterHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonNHits_validation.present", &ints_standardPFBTagNtuple_standardPFmuonNHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFmuonNHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonNHits_validation.obj", &ints_standardPFBTagNtuple_standardPFmuonNHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFmuonNHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation.present", &ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation.obj", &ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFmuonNPixelHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation.present", &ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_present, &b_ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation.obj", &ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_obj, &b_ints_standardPFBTagNtuple_standardPFmuonTrackQuality_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFnElectrons_validation.present", &ints_standardPFBTagNtuple_standardPFnElectrons_validation_present, &b_ints_standardPFBTagNtuple_standardPFnElectrons_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFnElectrons_validation.obj", &ints_standardPFBTagNtuple_standardPFnElectrons_validation_obj, &b_ints_standardPFBTagNtuple_standardPFnElectrons_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFnMuons_validation.present", &ints_standardPFBTagNtuple_standardPFnMuons_validation_present, &b_ints_standardPFBTagNtuple_standardPFnMuons_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFnMuons_validation.obj", &ints_standardPFBTagNtuple_standardPFnMuons_validation_obj, &b_ints_standardPFBTagNtuple_standardPFnMuons_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation.present", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix1_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation.present", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix2_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation.present", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPix3_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation.present", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackHasSharedPixAll_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation.present", &ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackNHits_validation.present", &ints_standardPFBTagNtuple_standardPFtrackNHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackNHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackNHits_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation.present", &ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_obj);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackQuality_validation.present", &ints_standardPFBTagNtuple_standardPFtrackQuality_validation_present, &b_ints_standardPFBTagNtuple_standardPFtrackQuality_validation_present);
   fChain->SetBranchAddress("ints_standardPFBTagNtuple_standardPFtrackQuality_validation.obj", &ints_standardPFBTagNtuple_standardPFtrackQuality_validation_obj, &b_ints_standardPFBTagNtuple_standardPFtrackQuality_validation_obj);

   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFeventNumber_validation.present", &uint_standardPFBTagNtuple_standardPFeventNumber_validation_present, &b_uint_standardPFBTagNtuple_standardPFeventNumber_validation_present);
   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFeventNumber_validation.obj", &uint_standardPFBTagNtuple_standardPFeventNumber_validation_obj, &b_uint_standardPFBTagNtuple_standardPFeventNumber_validation_obj);
   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation.present", &uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_present, &b_uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_present);
   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation.obj", &uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_obj, &b_uint_standardPFBTagNtuple_standardPFlumiBlockNumber_validation_obj);
   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation.present", &uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_present, &b_uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_present);
   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation.obj", &uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_obj, &b_uint_standardPFBTagNtuple_standardPFnumberOfPrimaryVertices_validation_obj);
   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFrunNumber_validation.present", &uint_standardPFBTagNtuple_standardPFrunNumber_validation_present, &b_uint_standardPFBTagNtuple_standardPFrunNumber_validation_present);
   fChain->SetBranchAddress("uint_standardPFBTagNtuple_standardPFrunNumber_validation.obj", &uint_standardPFBTagNtuple_standardPFrunNumber_validation_obj, &b_uint_standardPFBTagNtuple_standardPFrunNumber_validation_obj);
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
