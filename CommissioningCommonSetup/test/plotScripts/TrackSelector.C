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

  b_isGluonSplitting->GetEntry(entry);
  b_nJets -> GetEntry(entry);
  b_nTracks->GetEntry(entry);
  b_jetPt->GetEntry(entry);
  b_jetEta->GetEntry(entry);
  b_trackNHits->GetEntry(entry);
  b_triggerHLTJet15U->GetEntry(entry);  
  b_triggerHLTJet30U->GetEntry(entry);  
  b_trackJetIndex->GetEntry(entry);
  b_trackNPixelHits->GetEntry(entry);
  b_trackNHits->GetEntry(entry);
  b_trackNormChi2->GetEntry(entry);
  b_trackTransverseMomentum->GetEntry(entry);
  b_trackDistJetAxis->GetEntry(entry);
  b_trackDecayLength->GetEntry(entry);
  b_trackIP2d->GetEntry(entry);
  b_trackLongitudinalImpactParameter->GetEntry(entry);

  if(!isData) b_MCTrueFlavor->GetEntry(entry);

  unsigned int sizeOfJets =    nJets;
  unsigned int sizeOfTracks =  nTracks;
 

  // only fill histograms if cuts are fulfilled
  
  if(triggerHLTJet30U != info.triggerHLTJet30U) return kTRUE;

  /// ITERATE OVER ALL JETS
  for(unsigned int i=0 ;i<sizeOfJets; i++){
  
    if(jetPt[i] < info.jetPtCut) continue;
    if(fabs(jetEta[i]) > info.jetEtaCut) continue;

    unsigned int NtrackspassingCuts = 0;
    // now iterate over tracks of this jet and check cuts
    for(unsigned int j=0 ;j<sizeOfTracks; j++){
      if(trackJetIndex[j]   != i)           continue;
      if(trackNPixelHits[j] <  info.nPixHitsCut) continue;
      if(trackNHits[j]      <  info.nHitsCut)    continue;
      if(trackNormChi2[j]     >  info.Chi2Cut)    continue;
      if(trackTransverseMomentum[j] < info.trackPtCut) continue; 
      if(fabs(trackDistJetAxis[j]) > info.distJetAxisCut) continue;
      if(trackDecayLength[j] > info.decayLengthCut) continue; 
      if(fabs(trackIP2d[j]) > info.IP2dCut) continue;
      if(fabs(trackLongitudinalImpactParameter[j]) > info.longIPCut ) continue;
      // passed all cuts, now count the track
      NtrackspassingCuts++;
    }

    // fill number of tracks in histograms depending on jet flavour etc...
    if( isData ) dataHist->Fill(NtrackspassingCuts, fChain->GetWeight());
    else{
      if( abs(MCTrueFlavor[i]) == 5 && isGluonSplitting==0) mcHistb->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
      else if( abs(MCTrueFlavor[i]) == 5 && isGluonSplitting==1) mcHistbglusplit->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
      else if( abs(MCTrueFlavor[i]) == 4) mcHistc->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
      else if( abs(MCTrueFlavor[i]) == 3
	  || abs(MCTrueFlavor[i]) == 2
	  || abs(MCTrueFlavor[i]) == 1
	  || abs(MCTrueFlavor[i]) == 21 ) mcHistl->Fill(NtrackspassingCuts,  fChain->GetWeight()); 
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
