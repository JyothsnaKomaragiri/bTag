#define TrackSelector_cxx
// The class definition in TrackSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("TrackSelector.C")
// Root > T->Process("TrackSelector.C","some options")
// Root > T->Process("TrackSelector.C+")
//

#include "TrackSelector.h"
#include <TH2.h>
#include <TStyle.h>
#include "TH1D.h"
#include <stdlib.h>
#include <math.h>

void TrackSelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void TrackSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t TrackSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either TrackSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
  b_floats_standardPFBTagNtuple_standardPFjetPt_validation_obj->GetEntry(entry);
  b_floats_standardPFBTagNtuple_standardPFjetEta_validation_obj->GetEntry(entry);
  b_ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj->GetEntry(entry);
  b_bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_obj->GetEntry(entry);  
  b_ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_obj->GetEntry(entry);
  b_ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_obj->GetEntry(entry);
  b_ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj->GetEntry(entry);
  b_floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_obj->GetEntry(entry);
  b_floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_obj->GetEntry(entry);
  b_floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_obj->GetEntry(entry);
  b_floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_obj->GetEntry(entry);
  b_floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_obj->GetEntry(entry);
  b_floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_obj->GetEntry(entry);

  if(!isData) b_floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj->GetEntry(entry);

  unsigned int sizeOfJets =    floats_standardPFBTagNtuple_standardPFjetPt_validation_obj.size();
  unsigned int sizeOfTracks =  ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj.size();
 

  // only fill histograms if cuts are fulfilled
  
  if(bool_standardPFBTagNtuple_standardPFtriggerHLTJet15U_validation_obj != info.standardPFtriggerHLTJet15U) return kTRUE;

  /// ITERATE OVER ALL JETS
  for(unsigned int i=0 ;i<sizeOfJets; i++){
  
    if(floats_standardPFBTagNtuple_standardPFjetPt_validation_obj[i] < info.jetPtCut) continue;
    if(fabs(floats_standardPFBTagNtuple_standardPFjetEta_validation_obj[i]) > info.jetEtaCut) continue;

    unsigned int NtrackspassingCuts = 0;
    // now iterate over tracks of this jet and check cuts
    for(unsigned int j=0 ;j<sizeOfTracks; j++){
      if(ints_standardPFBTagNtuple_standardPFtrackJetIndex_validation_obj[j]   != i)           continue;
      if(ints_standardPFBTagNtuple_standardPFtrackNPixelHits_validation_obj[j] <  info.nPixHitsCut) continue;
      if(ints_standardPFBTagNtuple_standardPFtrackNHits_validation_obj[j]      <  info.nHitsCut)    continue;
      if(floats_standardPFBTagNtuple_standardPFtrackNormChi2_validation_obj[j]     >  info.Chi2Cut)    continue;
      if(floats_standardPFBTagNtuple_standardPFtrackTransverseMomentum_validation_obj[j] < info.trackPtCut) continue; 
      if(fabs(floats_standardPFBTagNtuple_standardPFtrackDistJetAxis_validation_obj[j]) > info.distJetAxisCut) continue;
      if(floats_standardPFBTagNtuple_standardPFtrackDecayLength_validation_obj[j] > info.decayLengthCut) continue; 
      if(fabs(floats_standardPFBTagNtuple_standardPFtrackIP2d_validation_obj[j]) > info.IP2dCut) continue;
      if(fabs(floats_standardPFBTagNtuple_standardPFtrackLongitudinalImpactParameter_validation_obj[j]) > info.longIPCut ) continue;
      // passed all cuts, now count the track
      NtrackspassingCuts++;
    }

    // fill number of tracks in histograms depending on jet flavour etc...
    if( isData ) dataHist->Fill(NtrackspassingCuts, fChain->GetWeight());
    else{
      if( abs(floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj[i]) == 5) mcHistb->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
      else if( abs(floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj[i]) == 4) mcHistc->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
      else if( abs(floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj[i]) == 3
	  || abs(floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj[i]) == 2
	  || abs(floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj[i]) == 1
	  || abs(floats_standardPFBTagNtuple_standardPFMCTrueFlavor_validation_obj[i]) == 21 ) mcHistl->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
      else mcHistn->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
    }// is not data

  } // END ITERATION OVER ALL JETS
  


   return kTRUE;
}

void TrackSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void TrackSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
