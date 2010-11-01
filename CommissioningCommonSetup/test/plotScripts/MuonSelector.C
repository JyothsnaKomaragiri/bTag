#define MuonSelector_cxx
// The class definition in MuonSelector.h has been generated automatically
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
// Root > T->Process("MuonSelector.C")
// Root > T->Process("MuonSelector.C","some options")
// Root > T->Process("MuonSelector.C+")
//

#include "MuonSelector.h"
#include <TH2.h>
#include <TStyle.h>


void MuonSelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void MuonSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t MuonSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either MuonSelector::GetEntry() or TBranch::GetEntry()
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

  b_triggerHLTJet30U->GetEntry(entry);
  b_isGluonSplitting->GetEntry(entry);

  b_nJets -> GetEntry(entry);
  b_jetPt->GetEntry(entry);
  b_jetEta->GetEntry(entry);

  b_muon1Pt->GetEntry(entry);
  b_muon1Eta->GetEntry(entry);
  b_muon1IsGlobal->GetEntry(entry);
  b_muon1GlobalMuonHits->GetEntry(entry);
  b_muon1NumberOfMatches->GetEntry(entry);
  b_muon1InnerValidHits->GetEntry(entry);
  b_muon1NPixelHits->GetEntry(entry); 
  b_muon1NExpectedOuterHits->GetEntry(entry);
  b_muon1InnerNChi2->GetEntry(entry);
  b_muon1GlobalNChi2->GetEntry(entry); 
  b_muon1VzPVDist->GetEntry(entry);
  b_muon1DeltaR->GetEntry(entry);

  b_muon2Pt->GetEntry(entry);
  b_muon2Eta->GetEntry(entry);
  b_muon2IsGlobal->GetEntry(entry);
  b_muon2GlobalMuonHits->GetEntry(entry);
  b_muon2NumberOfMatches->GetEntry(entry);
  b_muon2InnerValidHits->GetEntry(entry);
  b_muon2NPixelHits->GetEntry(entry); 
  b_muon2NExpectedOuterHits->GetEntry(entry);
  b_muon2InnerNChi2->GetEntry(entry);
  b_muon2GlobalNChi2->GetEntry(entry); 
  b_muon2VzPVDist->GetEntry(entry);
  b_muon2DeltaR->GetEntry(entry);

  b_muon3Pt->GetEntry(entry);
  b_muon3Eta->GetEntry(entry);
  b_muon3IsGlobal->GetEntry(entry);
  b_muon3GlobalMuonHits->GetEntry(entry);
  b_muon3NumberOfMatches->GetEntry(entry);
  b_muon3InnerValidHits->GetEntry(entry);
  b_muon3NPixelHits->GetEntry(entry); 
  b_muon3NExpectedOuterHits->GetEntry(entry);
  b_muon3InnerNChi2->GetEntry(entry);
  b_muon3GlobalNChi2->GetEntry(entry); 
  b_muon3VzPVDist->GetEntry(entry);
  b_muon3DeltaR->GetEntry(entry);

  b_muon4Pt->GetEntry(entry);
  b_muon4Eta->GetEntry(entry);
  b_muon4IsGlobal->GetEntry(entry);
  b_muon4GlobalMuonHits->GetEntry(entry);
  b_muon4NumberOfMatches->GetEntry(entry);
  b_muon4InnerValidHits->GetEntry(entry);
  b_muon4NPixelHits->GetEntry(entry); 
  b_muon4NExpectedOuterHits->GetEntry(entry);
  b_muon4InnerNChi2->GetEntry(entry);
  b_muon4GlobalNChi2->GetEntry(entry); 
  b_muon4VzPVDist->GetEntry(entry);
  b_muon4DeltaR->GetEntry(entry);

  if(!isData) b_MCTrueFlavor->GetEntry(entry);

  unsigned int sizeOfJets = nJets;

   // only fill histograms if cuts are fulfilled
  

  if(triggerHLTJet30U != info.triggerHLTJet30U) return kTRUE;
  

  ////////////////////////////////////////////////////////////
  /// ITERATE OVER ALL JETS
  for(unsigned int i=0 ;i<sizeOfJets; i++){//loop over jets
    

    if(jetPt[i] < info.jetPtCut) continue;
    if(fabs(jetEta[i]) > info.jetEtaCut) continue;
    

    /*
      muon1Pt > 5.0 && TMath::Abs(muon1Eta) < 2.4 && muon1IsGlobal == 1 
      && muon1GlobalMuonHits > 0 && muon1NumberOfMatches > 1 
      && muon1InnerValidHits > 10 && muon1NPixelHits > 1 
      && muon1NExpectedOuterHits < 3 && muon1InnerNChi2 < 10 
      && muon1GlobalNChi2 < 10 && muon1VzPVDist < 2 && muon1DeltaR < 0.4
    */

    unsigned int Nmupassingcuts = 0;
    
    ///////////////////////////////////////
    //Count separately for the muons ordered in pT, muon1,2,3 and 4
    //muon1

    
    if (  (muon1Pt[i] > info.muonPtCut) &&
    (fabs(muon1Eta[i]) < info.muonEtaCut) &&
    (muon1IsGlobal[i] == info.muonIsGlobal) &&
    (muon1GlobalMuonHits[i] > info.muonGlobalMuonHits) &&
    (muon1NumberOfMatches[i] > info.muonNumberOfMatches) &&
    (muon1InnerValidHits[i] > info.muonInnerValidHits) &&
    (muon1NPixelHits[i] > info.muonNPixelHits) &&
    (muon1NExpectedOuterHits[i] < info.muonNExpectedOuterHits) &&
    (muon1InnerNChi2[i] < info.muonInnerNChi2) &&
    (muon1GlobalNChi2[i] < info.muonGlobalNChi2) &&
      (fabs(muon1VzPVDist[i]) < info.muonVzPVDist) &&
	  (muon1DeltaR[i] < info.muonDeltaR) ) Nmupassingcuts++;
    
   if (  (muon2Pt[i] > info.muonPtCut) &&
    (fabs(muon2Eta[i]) < info.muonEtaCut) &&
    (muon2IsGlobal[i] == info.muonIsGlobal) &&
    (muon2GlobalMuonHits[i] > info.muonGlobalMuonHits) &&
    (muon2NumberOfMatches[i] > info.muonNumberOfMatches) &&
    (muon2InnerValidHits[i] > info.muonInnerValidHits) &&
    (muon2NPixelHits[i] > info.muonNPixelHits) &&
    (muon2NExpectedOuterHits[i] < info.muonNExpectedOuterHits) &&
    (muon2InnerNChi2[i] < info.muonInnerNChi2) &&
    (muon2GlobalNChi2[i] < info.muonGlobalNChi2) &&
      (fabs(muon2VzPVDist[i]) < info.muonVzPVDist) &&
	  (muon2DeltaR[i] < info.muonDeltaR) ) Nmupassingcuts++; 

   if (  (muon3Pt[i] > info.muonPtCut) &&
    (fabs(muon3Eta[i]) < info.muonEtaCut) &&
    (muon3IsGlobal[i] == info.muonIsGlobal) &&
    (muon3GlobalMuonHits[i] > info.muonGlobalMuonHits) &&
    (muon3NumberOfMatches[i] > info.muonNumberOfMatches) &&
    (muon3InnerValidHits[i] > info.muonInnerValidHits) &&
    (muon3NPixelHits[i] > info.muonNPixelHits) &&
    (muon3NExpectedOuterHits[i] < info.muonNExpectedOuterHits) &&
    (muon3InnerNChi2[i] < info.muonInnerNChi2) &&
    (muon3GlobalNChi2[i] < info.muonGlobalNChi2) &&
      (fabs(muon3VzPVDist[i]) < info.muonVzPVDist) &&
	  (muon3DeltaR[i] < info.muonDeltaR) ) Nmupassingcuts++;

   if (  (muon4Pt[i] > info.muonPtCut) &&
    (fabs(muon4Eta[i]) < info.muonEtaCut) &&
    (muon4IsGlobal[i] == info.muonIsGlobal) &&
    (muon4GlobalMuonHits[i] > info.muonGlobalMuonHits) &&
    (muon4NumberOfMatches[i] > info.muonNumberOfMatches) &&
    (muon4InnerValidHits[i] > info.muonInnerValidHits) &&
    (muon4NPixelHits[i] > info.muonNPixelHits) &&
    (muon4NExpectedOuterHits[i] < info.muonNExpectedOuterHits) &&
    (muon4InnerNChi2[i] < info.muonInnerNChi2) &&
    (muon4GlobalNChi2[i] < info.muonGlobalNChi2) &&
      (fabs(muon4VzPVDist[i]) < info.muonVzPVDist) &&
	  (muon4DeltaR[i] < info.muonDeltaR) ) Nmupassingcuts++;

    ///////////////////////////////////////
  
  
    // fill number of muons in histograms depending on jet flavour etc...
    if( isData ) dataHist->Fill(Nmupassingcuts, fChain->GetWeight());
    else{//MC
      if( abs(MCTrueFlavor[i]) == 5 && isGluonSplitting == 0) mcHistb->Fill(Nmupassingcuts,  fChain->GetWeight()); 
      else if( abs(MCTrueFlavor[i]) == 5 && isGluonSplitting==1) mcHistbglusplit->Fill(Nmupassingcuts,  fChain->GetWeight()); 
      else if( abs(MCTrueFlavor[i]) == 4) mcHistc->Fill(Nmupassingcuts,  fChain->GetWeight()); 
      else if( abs(MCTrueFlavor[i]) == 3
	  || abs(MCTrueFlavor[i]) == 2
	  || abs(MCTrueFlavor[i]) == 1
	  || abs(MCTrueFlavor[i]) == 21 ) mcHistl->Fill(Nmupassingcuts,  fChain->GetWeight()); 
      else mcHistn->Fill(Nmupassingcuts,  fChain->GetWeight()); 
    }

  }//loop over jets

   return kTRUE;
}

void MuonSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void MuonSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
