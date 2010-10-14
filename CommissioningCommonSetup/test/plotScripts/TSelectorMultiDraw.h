//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 11 00:27:16 2010 by ROOT version 5.22/00d
// from TTree /
// found on file: Memory Directory
//////////////////////////////////////////////////////////

#ifndef TSelectorMultiDraw_h
#define TSelectorMultiDraw_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TSelectorDraw.h>
#include <list>
#include <string>

#include "TrackSelector.h"
#include "MuonSelector.h"

class TSelectorMultiDraw : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   std::list<TSelectorDraw*> fSelectors; //list of TSelectorDraws
   std::list<TrackSelector*> fTrackSelectors; //list of TrackSelectors
   std::list<MuonSelector*>  fMuonSelectors; //list of MuonSelectors

   // need them as arrays as well, to get faster access:
   TSelectorDraw** fArrSelectors;
   TrackSelector** fArrTrackSelectors;
   MuonSelector**  fArrMuonSelectors;

   int nSelectors;
   int nTrackSelectors;
   int nMuonSelectors;

   // Declaration of leaf types

   // List of branches

   TSelectorMultiDraw(/*TTree * tree =0 */) { }
   virtual ~TSelectorMultiDraw() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) {
     for(int i=0; i<nSelectors; i++)        fArrSelectors[i]->SetOption(option);  
     for(int j=0; j<nTrackSelectors; j++)   fArrTrackSelectors[j]->SetOption(option);
     for(int j=0; j<nMuonSelectors; j++)    fArrMuonSelectors[j]->SetOption(option);
   }

   virtual void SetupArrays();
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   virtual void    LoadVariables(std::string varexp, std::string selection);
   virtual void    AddTrackSelector(bool isData, TH1D*dataHist, TH1D* mcHistb, TH1D* mcHistc, TH1D* mcHistl, TH1D* mcHistn, informationTrackCuts info);
   virtual void    AddMuonSelector(bool isData, TH1D*dataHist, TH1D* mcHistb, TH1D* mcHistc, TH1D* mcHistl, TH1D* mcHistn, informationMuonCuts info);
   //   virtual void    SetOption(const char* option);

   ClassDef(TSelectorMultiDraw,0);
};

#endif

#ifdef TSelectorMultiDraw_cxx
void TSelectorMultiDraw::Init(TTree *tree)
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

   for(int i=0; i<nSelectors; i++)        fArrSelectors[i]->Init(tree);  
   for(int j=0; j<nTrackSelectors; j++)   fArrTrackSelectors[j]->Init(tree);
   for(int j=0; j<nMuonSelectors; j++)    fArrMuonSelectors[j]->Init(tree);
}

Bool_t TSelectorMultiDraw::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef TSelectorMultiDraw_cxx
