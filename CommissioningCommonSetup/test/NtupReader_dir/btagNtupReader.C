/////////////////////////////////////////////////////////////////
// Author : Caroline Collard (IPHC) - first commit : april 2011
////////////////////////////////////////////////////////////////


#define btagNtupReader_cxx
#include "btagNtupReader.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>


// ----------- 

// TO BE DEFINED FIRST !
  bool Run_on_Jet = true;
  bool Run_on_Btag = false;
//  TString final_dir = "dir_btag20pu";
  TString final_dir = "dir_jet60pu_test";
  // + check the data and MC input files

//  TString my_trigger_path="HLT_Jet30";
  TString my_trigger_path="HLT_Jet60";
//  TString my_trigger_path="HLT_Jet80";
//  TString my_trigger_path="HLT_Jet110";
//  TString my_trigger_path="HLT_BTagMu_DiJet20_Mu5";
//  TString my_trigger_path="HLT_BTagMu_DiJet40_Mu5";
//  TString my_trigger_path="HLT_BTagMu_DiJet60_Mu7";
//  TString my_trigger_path="HLT_BTagMu_DiJet70_Mu5";
//  TString my_trigger_path="HLT_BTagMu_DiJet110_Mu5";

  // CUT VALUES
//  float cutJetPt=30.;  // FOR JETS HLT_Jet30
  float cutJetPt=60.;  // FOR JETS HLT_Jet60
//  float cutJetPt=80.;  // FOR JETS HLT_Jet80
//  float cutJetPt=110.;  // FOR JETS HLT_Jet80
//  float cutJetPt=45.;  // FOR JETS HLT_BTagMu_DiJet20_Mu5
//  float cutJetPt=65.;  // FOR JETS HLT_BTagMu_DiJet40_Mu5
//  float cutJetPt=95.;  // FOR JETS HLT_BTagMu_DiJet60_Mu7
//  float cutJetPt=105.;  // FOR JETS HLT_BTagMu_DiJet70_Mu5
//  float cutJetPt=160.;  // FOR JETS HLT_BTagMu_DiJet110_Mu5

  float cutMuonPt=7.;  // FOR MUON HLT_BTagMu_DiJet20_Mu5, 40, 70,110
//  float cutMuonPt=9.;  // FOR MUON HLT_BTagMu_DiJet60_Mu7


// ----------- 

int main() {
  run();
  return 0;
}

void run(){



float weight;

/* MC 39X
//QCD 
// w = sect / n_ev;
float weight05 = 36750000000.  / 1648096. ;
float weight15=   815900000. / 5420080.;
float weight30=   53120000.  / 3244045.;
float weight50=   6359000.   / 2739226.;
float weight80=   784300.    / 3208299.;
float weight120=  115100.    / 3045200.;
float weight170=  24260.     / 3212880.;
float weight300=  1168.      / 3060200.;

//Mu enriched QCD
// (filter* sect) /n_ev
float wmu15=(0.00254    *579200000.)/2884915.;
float wmu20=(0.00518    *236300000.)/11417239.;
float wmu30=(0.01090    *53070000. )/11431864.;
float wmu50=(0.02274    *6351000.  )/10748755.;
float wmu80=(0.03700    *785100.   )/3191979.;
float wmu120=(0.04777   *92950.    )/998503.;
float wmu150=(0.05964   *47580.)/1022541.;
*/

// MC 311X
//QCD
// w = sect / n_ev;
float weight15=   815900000. / 8213600.;
float weight30=   53120000.  / 6529320.;
float weight50=   6359000.   / 4301392.;
float weight80=   784300.    / 6407732.;
float weight120=  115100.    / 6090400.;
float weight170=  24260.     / 5684160.;
float weight300=  1168.      / 6336960.;

//Mu enriched QCD
// (filter* sect) /n_ev
float wmu15=(0.00254    *579200000.)/2884915.;
float wmu20=(0.00518    *236300000.)/11352301.; 
float wmu30=(0.01090    *53070000. )/10909951.;
float wmu50=(0.02274    *6351000.  )/10686315.;
float wmu80=(0.03700    *785100.   )/3183540.;
float wmu120=(0.04777   *92950.    )/991024.;
float wmu150=(0.05964   *47580.    )/1015900.;

cout << " MC weights " << endl;
cout << "------------" << endl;
cout << " weight15  " << weight15 << endl;
cout << " weight30  " << weight30 << endl;
cout << " weight50  " << weight50 << endl;
cout << " weight80  " << weight80 << endl;
cout << " weight120 " << weight120 << endl;
cout << " weight170 " << weight170 << endl;
cout << " weight300 " << weight300 << endl;
cout << " wmu15 " << wmu15 << endl;
cout << " wmu20 " << wmu20 << endl;
cout << " wmu30 " << wmu30 << endl;
cout << " wmu50 " << wmu50 << endl;
cout << " wmu80 " << wmu80 << endl;
cout << " wmu120 " << wmu120 << endl;
cout << " wmu150 " << wmu150 << endl;
cout << endl;




TString action;



cout << " ----> DATA 2011" << endl;
  weight=1;

  if (Run_on_Jet)      { 
//     btagNtupReader yt(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/Data/Jet2011/*.root");   
//     btagNtupReader yt(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/v42x_v1/Data/link_jet/*.root");
    btagNtupReader yt(3,"/user/fblekman/data/b-tagwork/Jet2011_prompt_15june11/*.root");
    //    btagNtupReader yt(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/BTAG/v42X_v1/Data/Jet2011_rerecomay10/standardPFNtuple_15*.root");
     yt.Loop(0, weight); 
     action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_minijet2011.root";
     system(action);
  }
  if (Run_on_Btag){ 
//     btagNtupReader yt(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/Data/Met2011/*.root");    

//     btagNtupReader yt(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/v42x_v1/Data/link_met/*.root");    
    btagNtupReader yt(3,"/user/fblekman/data/b-tagwork/Jet2011_prompt_15june11/*.root");
     yt.Loop(0, weight); 
     action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_minibtag2011.root";
     system(action);
  }



/*
if (Run_on_Jet)  {
   cout << " ----> DATA 2010" << endl;
   weight=1;
   btagNtupReader yt2(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/Jet_Run2010B-Dec22ReReco_v1_prescale/*.root");
   yt2.Loop(0, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_minijet2010.root";
   system(action);
}
*/


if (Run_on_Jet) {

cout << " ----> MC : QCD 15-30 " << endl;
   weight=weight15;
//  btagNtupReader xt15(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_15to30_TuneZ2_7TeV_pythia6_PU/*.root"); // 39X
//  btagNtupReader xt15(2, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD15to30/QCD15to30/*.root"); // 311X
//   btagNtupReader xt15(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_15to30/*.root"); // 311X DA & SV fix
   btagNtupReader xt15(3, "/user/fblekman/data/b-tagwork/14MayQCDPt_15to30/*.root"); // 311X DA & SV fix
   //   btagNtupReader xt15(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/May14_MC_btagNtuples/14MayQCDPt_15to30/standardPFNtuple_10*.root"); // 311X DA & SV fix

   xt15.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcd15.root";
   system(action);

cout << " ----> MC : QCD 30-50 " << endl;
   weight=weight30;
//   btagNtupReader xt30(0, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_30to50_TuneZ2_7TeV_pythia6_PU/*.root"); // 39X
//   btagNtupReader xt30(2, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD30to50/*.root"); // 311X
//   btagNtupReader xt30(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_30to50/*.root"); // 311X DA & SV fix 
   btagNtupReader xt30(3, "/user/fblekman/data/b-tagwork/14MayQCDPt_30to50/*.root"); // 311X DA & SV fix
   //   btagNtupReader xt30(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/May14_MC_btagNtuples/14MayQCDPt_30to50/standardPFNtuple_10*.root"); // 311X DA & SV fix

   xt30.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcd30.root";
   system(action);


cout << " ----> MC : QCD 50-80 " << endl;
   weight=weight50;
//   btagNtupReader xt50(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_50to80_TuneZ2_7TeV_pythia6_PU_v2/*.root"); // 39X
//   btagNtupReader xt50(2, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD50to80/*.root"); // 311X
//   btagNtupReader xt50(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_50to80/*.root"); // 311X DA & SV fix
   btagNtupReader xt50(3, "/user/fblekman/data/b-tagwork/14MayQCDPt_50to80/*.root"); // 311X DA & SV fix
   //   btagNtupReader xt50(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/May14_MC_btagNtuples/14MayQCDPt_50to80/standardPFNtuple_1*.root"); // 311X DA & SV fix

   xt50.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcd50.root";
   system(action);



cout << " ----> MC : QCD 80-120 " << endl;
   weight=weight80;
//   btagNtupReader xt80(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_80to120_TuneZ2_7TeV_pythia6_PU_prescale/*.root"); // 39X
//   btagNtupReader xt80(2, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD80to120/*.root"); //311X
//   btagNtupReader xt80(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_80to120/*.root"); // 311X DA & SV fix
   btagNtupReader xt80(3, "/user/fblekman/data/b-tagwork/14MayQCDPt_80to120/*.root"); // 311X DA & SV fix
   //   btagNtupReader xt80(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/May14_MC_btagNtuples/14MayQCDPt_80to120/standardPFNtuple_10*.root"); // 311X DA & SV fix

   xt80.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcd80.root";
   system(action);


cout << " ----> MC : QCD 120-170 " << endl;
   weight=weight120;
//   btagNtupReader xt120(0, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_120to170_TuneZ2_7TeV_pythia6_PU/*.root"); // 39X
//   btagNtupReader xt120(2, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD120to170/*.root"); // 311X
//   btagNtupReader xt120(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCD_Pt_120to170/*.root"); // 311X DA & SV fix
   btagNtupReader xt120(3, "/user/fblekman/data/b-tagwork/QCD_Pt_120to170/*.root"); // 311X DA & SV fix
   //   btagNtupReader xt120(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/BTAG/V4_DA_SVfix/MC/QCD_Pt_120to170/standardPFNtuple_100*.root"); // 311X DA & SV fix

   xt120.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcd120.root";
   system(action);


cout << " ----> MC : QCD 170-300 " << endl;
   weight=weight170;
//   btagNtupReader xt170(0, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_170to300_TuneZ2_7TeV_pythia6_PU/*.root"); // 39X
//   btagNtupReader xt170(2, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD170to300/*.root");  //311X
//   btagNtupReader xt170(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_170to300/*.root"); // 311X DA & SV fix
   btagNtupReader xt170(3, "/user/fblekman/data/b-tagwork/14MayQCDPt_170to300/*.root"); // 311X DA & SV fix
   //   btagNtupReader xt170(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/May14_MC_btagNtuples/14MayQCDPt_170to300/standardPFNtuple_10*.root"); // 311X DA & SV fix

   xt170.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcd170.root";
   system(action);


cout << " ----> MC : QCD 300-470 " << endl;
   weight=weight300;
//   btagNtupReader xt300(0, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_300to470_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xt300(2, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD300to470/*.root");  // 311X
//   btagNtupReader xt300(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_300to470/*.root"); // 311X DA & SV fix
   btagNtupReader xt300(3, "/user/fblekman/data/b-tagwork/14MayQCDPt_300to470/*.root"); // 311X DA & SV fix
   //   btagNtupReader xt300(3, "/nfs/data4/alschmid/btagCommisioning/CaroNtuples/May14_MC_btagNtuples/14MayQCDPt_300to470/standardPFNtuple_10*.root"); // 311X DA & SV fix

   xt300.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcd300.root";
   system(action);

}


if (Run_on_Btag) {
//  BTAGMET

cout << " ----> MC : QCD  MU 15-20 " << endl;
   weight=wmu15;
//   btagNtupReader xmu15(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT15to20_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xmu15(2, "/opt/sbg/cms/ui2_data1/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu15to20/*.root");
//   btagNtupReader xmu15(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_15to20/*.root"); // 311X DA & SV fix
   btagNtupReader xmu15(3, "/user/fblekman/data/b-tagwork/14MayQCDMuEnrichedPt_15to20/*.root"); // 311X DA & SV fix
   xmu15.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcdmu15.root";
   system(action);

cout << " ----> MC : QCD  MU 20-30 " << endl;
   weight=wmu20;
//   btagNtupReader xmu20(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT20to30_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xmu20(2, "/opt/sbg/cms/ui2_data1/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu20to30/*.root"); //311X
//   btagNtupReader xmu20(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_20to30/*.root"); // 311X DA & SV fix
   btagNtupReader xmu20(3, "/user/fblekman/data/b-tagwork/14MayQCDMuEnrichedPt_20to30/*.root"); // 311X DA & SV fix
   xmu20.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcdmu20.root";
   system(action);



cout << " ----> MC : QCD  MU 30-50 " << endl;
   weight=wmu30;
//   btagNtupReader xmu30(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT30to50_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xmu30(2, "/opt/sbg/cms/ui2_data1/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu30to50/*.root"); //311X
//   btagNtupReader xmu30(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCDMuEnriched_Pt-30to50/*.root"); // 311X DA & SV fix
   btagNtupReader xmu30(3, "/user/fblekman/data/b-tagwork/QCDMuEnriched_Pt-30to50/*.root"); // 311X DA & SV fix
   xmu30.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcdmu30.root";
   system(action);


cout << " ----> MC : QCD  MU 50-80 " << endl;
   weight=wmu50;
//   btagNtupReader xmu50(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT50to80_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xmu50(2, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu50to80/QCDMu50to80/*.root"); //311X
//   btagNtupReader xmu50(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCDMuEnriched_Pt-50to80/*.root"); // 311X DA & SV fix
   btagNtupReader xmu50(3, "/user/fblekman/data/b-tagwork/QCDMuEnriched_Pt-50to80/*.root"); // 311X DA & SV fix
   xmu50.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcdmu50.root";
   system(action);

cout << " ----> MC : QCD  MU 80-120 " << endl;
   weight=wmu80;
//   btagNtupReader xmu80(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT80to120_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xmu80(2, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu80to120/QCDMu80to120/*.root"); //311X
//   btagNtupReader xmu80(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCDMuEnriched_Pt-80to120/*.root"); // 311X DA & SV fix
   btagNtupReader xmu80(3, "/user/fblekman/data/b-tagwork/QCDMuEnriched_Pt-80to120/*.root"); // 311X DA & SV fix
   xmu80.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcdmu80.root";
   system(action);

cout << " ----> MC : QCD  MU 120-150 " << endl;
   weight=wmu120;
//   btagNtupReader xmu120(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT120to150_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xmu120(2, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu120to150/QCDMu120to150/*.root"); //311X
//   btagNtupReader xmu120(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_120to150/*.root"); // 311X DA & SV fix
   btagNtupReader xmu120(3, "/user/fblekman/data/b-tagwork/14MayQCDMuEnrichedPt_120to150/*.root"); // 311X DA & SV fix
   xmu120.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcdmu120.root";
   system(action);


cout << " ----> MC : QCD  MU 150 " << endl;
   weight=wmu150;
//   btagNtupReader xmu150(1, "/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT150_TuneZ2_7TeV_pythia6_PU/*.root"); //39X
//   btagNtupReader xmu150(2, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu150/QCDMu150/*.root"); //311X
//   btagNtupReader xmu150(3, "/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_150/*.root"); // 311X DA & SV fix   
   btagNtupReader xmu150(3, "/user/fblekman/data/b-tagwork/14MayQCDMuEnrichedPt_150/*.root"); // 311X DA & SV fix
   xmu150.Loop(1, weight);
   action = "mv  "+final_dir+"/histoFile.root "+final_dir+"/histo_qcdmu150.root";
   system(action);


}


}

void btagNtupReader::Loop(int cutgen, float weightsave)
{
//   In a ROOT session, you can do:
//      Root > .L btagNtupReader.C
//      Root > btagNtupReader t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;


   vector<TH1F*> HistoBtag;
   double pi=acos(-1);

   int jmax=1;
   int nhisto_to_clone = 0;
   int nhisto_to_clone2D = 0;
   if (cutgen==1) jmax=5;

   // HISTOGRAM DEFINITIONS 
   // FOR DATA : only 1 histo
   // FOR MC : all, b, c, udsg, splitting
   for (int j=0; j<jmax; j++) {

//   TEMPLATE :
//   AddHisto(string name, int j, string title, string xaxis, const int& nbins, const float& min, const float& max)

// general information on the jets
     AddHisto(HistoBtag, "all_jetpt",       j,"PT of all jets",80,0.,400.);   //0

// discri
     AddHisto(HistoBtag, "discri_tche",   j,"TCHE Discriminator",50,0.,30.);  // 1
     AddHisto(HistoBtag, "discri_tchp",   j,"TCHP Discriminator",50,0.,30.);  // 2

     AddHisto(HistoBtag, "discri_ssche0",   j,"SSVHE Discriminator",80,-1.,7.); // 3
     AddHisto(HistoBtag, "discri_ssche",   j,"SSVHE Discriminator",50,0.,7.);   // 4
     AddHisto(HistoBtag, "discri_sschp0",   j,"SSVHP Discriminator",80,-1.,7.); // 5
     AddHisto(HistoBtag, "discri_sschp",   j,"SSVHP Discriminator",50,0.,7.);   

     AddHisto(HistoBtag, "discri_jetprob",   j,"JetProb Discriminator",50,0.,2.5);
     AddHisto(HistoBtag, "discri_jetbprob",   j,"JetBProb Discriminator",50,0.,8.);

// track info : 
     AddHisto(HistoBtag, "n_tracks_jet",   j,"# of tracks in jet",100,0.,100.);
     AddHisto(HistoBtag, "pt_tracks",   j,"Pt of tracks",80,0.,200.);    // 10
     AddHisto(HistoBtag, "n_seltracks_jet",   j,"# of sel tracks in jet",100,0.,100.);
     AddHisto(HistoBtag, "pt_seltracks",   j,"Pt of  sel tracks",80,0.,200.);

     AddHisto(HistoBtag, "trackNHits",  j,"Number of hits",35,-0.5, 34.5);
     AddHisto(HistoBtag, "trackNPixelHits",  j,"number of pixel hits",10,-0.5, 9.5);
     AddHisto(HistoBtag, "trackNormChi2",  j,"Normalized #chi^{2}",100,0.,30.); // 15
     AddHisto(HistoBtag, "trackTransverseMomentum",  j,"Track p_{T}",150,0.,15.);
     AddHisto(HistoBtag, "trackLongitudinalIP",  j,"Longitudinal IP",100,-20.,20.);
     AddHisto(HistoBtag, "trackIP2d",  j,"Transverse IP",200,-1.,1.);
     AddHisto(HistoBtag, "trackDistJetAxis",  j,"Track jet axis distance",100,0.,0.3);
     AddHisto(HistoBtag, "trackDecayLength",  j,"Track decay length",100,0,25.); //20

     AddHisto(HistoBtag, "trackNHits_cut",  j,"Number of hits",35,-0.5, 34.5);
     AddHisto(HistoBtag, "trackNPixelHits_cut",  j,"number of pixel hits",10,-0.5, 9.5);
     AddHisto(HistoBtag, "trackNormChi2_cut",  j,"Normalized #chi^{2}",100,0.,30.);
     AddHisto(HistoBtag, "trackTransverseMomentum_cut",  j,"Track p_{T}",150,0.,15.);
     AddHisto(HistoBtag, "trackLongitudinalIP_cut",  j,"Longitudinal IP",100,-20.,20.);// 25
     AddHisto(HistoBtag, "trackIP2d_cut",  j,"Transverse IP",200,-1.,1.);
     AddHisto(HistoBtag, "trackDistJetAxis_cut",  j,"Track jet axis distance",100,0.,0.3);
     AddHisto(HistoBtag, "trackDecayLength_cut",  j,"Track decay length",100,0,25.);

     AddHisto(HistoBtag, "trackIP3d",  j,"Track 3D IP value",100,-0.05,0.05);
     AddHisto(HistoBtag, "trackIP3dError",  j,"Track 3D IP Error",100,0.,0.1); //30
     AddHisto(HistoBtag, "trackIP3dsig",  j,"Track 3D IP significance",200,-5.,5.);
     AddHisto(HistoBtag, "trackIP3d_sel",  j,"Track 3D IP value",100,-0.05,0.05);
     AddHisto(HistoBtag, "trackIP3dError_sel",  j,"Track 3D IP Error",100,0.,0.1);
     AddHisto(HistoBtag, "trackIP3dsig_sel",  j,"Track 3D IP significance",200,-5.,5.);
     AddHisto(HistoBtag, "trackIP3d_cutsel",  j,"Track 3D IP value",100,-0.05,0.05); //35
     AddHisto(HistoBtag, "trackIP3dError_cutsel",  j,"Track 3D IP Error",100,0.,0.1);
     AddHisto(HistoBtag, "trackIP3dsig_cutsel",  j,"Track 3D IP significance",200,-5.,5.);

// IP  : first 3 tracks
     AddHisto(HistoBtag, "IP3d1",j,"1st track 3D IP value",100,-0.1,0.1);
     AddHisto(HistoBtag, "IP3d1sig",j,"1st track 3D IP significance",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d1sigz",j,"1st track 3D IP significance",100,-2.,2.); //40
     AddHisto(HistoBtag, "IP3d2",j,"2nd track 3D IP value",100,-0.1,0.1);
     AddHisto(HistoBtag, "IP3d2sig",j,"2nd track 3D IP significance",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d2sigz",j,"2nd track 3D IP significance",100,-2.,2.); 
     AddHisto(HistoBtag, "IP3d3",j,"3rd track 3D IP value",100,-0.1,0.1); 
     AddHisto(HistoBtag, "IP3d3sig",j,"3rd track 3D IP significance",100,-35.,35.); //45
     AddHisto(HistoBtag, "IP3d3sigz",j,"3rd track 3D IP significance",100,-2.,2.);
 
     AddHisto(HistoBtag, "IP3d1sorted",j,"1st track 3D IP value (sorted)",100,-0.1,0.1);
     AddHisto(HistoBtag, "IP3d1sigsorted",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d1sigzsorted",j,"1st track 3D IP significance (sorted)",100,-2.,2.);
     AddHisto(HistoBtag, "IP3d2sorted",j,"2nd track 3D IP value (sorted)",100,-0.1,0.1); //50
     AddHisto(HistoBtag, "IP3d2sigsorted",j,"2nd track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d2sigzsorted",j,"2nd track 3D IP significance (sorted)",100,-2.,2.);
     AddHisto(HistoBtag, "IP3d3sorted",j,"3rd track 3D IP value (sorted)",100,-0.1,0.1); 
     AddHisto(HistoBtag, "IP3d3sigsorted",j,"3rd track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d3sigzsorted",j,"3rd track 3D IP significance (sorted)",100,-2.,2.);//55

// SV : 

     AddHisto(HistoBtag, "sv_nvertices0", j,"# of secondary vertices",5,0,5);
     AddHisto(HistoBtag, "sv_nvertices", j,"# of secondary vertices",5,0,5);
     AddHisto(HistoBtag, "sv_jetpt",       j,"PT of jet",80,0.,400.);
     AddHisto(HistoBtag, "sv_normchi2",    j,"Norm Chi2",50,0.,10.);

     AddHisto(HistoBtag, "sv_mass",    j,"SV mass",50,0.,8.); // 60
     AddHisto(HistoBtag, "sv_mass_3tr", j,"SV mass for >=3tracks",50,0.,8.);

     AddHisto(HistoBtag, "sv_trackmul",  j,"Track multiplicity : SVnVertexTracks",24,0.25,12.25);
     AddHisto(HistoBtag, "sv_trackmul1",  j,"Track multiplicity : SVnFirstVertexTracks",10,0,10);
     AddHisto(HistoBtag, "sv_tracksel",  j,"Track multiplicity : SVnSelectedTracks",20,0,20);

     AddHisto(HistoBtag, "sv_ipsigcharm",  j,"IP significance 2D charm",50,-35.,35.); //65
     AddHisto(HistoBtag, "sv_eratio",    j,"Fractional energy",50,0.,1.);

     AddHisto(HistoBtag, "sv_flightsig2d", j,"Flight significance 2D",50,0.,80.);
     AddHisto(HistoBtag, "sv_flightsig3d", j,"Flight significance 3D",50,0.,80.);
     AddHisto(HistoBtag, "sv_flightdis2d", j,"Flight distance 2D",50,0.,2.5);
     AddHisto(HistoBtag, "sv_flightdis3d", j,"Flight distance 3D",50,0.,15.); //70
     AddHisto(HistoBtag, "sv_flightsig3d_3tr", j,"Flight significance 3D for >=3tracks",50,0.,80.);

     AddHisto(HistoBtag, "sv_deltar_jet",    j,"SVjetDeltaR",50,0.,0.5);
     AddHisto(HistoBtag, "sv_deltar_sum_jet",    j,"SVvtxSumJetDeltaR",50,0.,0.5);
     AddHisto(HistoBtag, "sv_deltar_sum_dir",    j,"SVvtxSumVtxDirDeltaR",50,0.,0.5);

     AddHisto(HistoBtag, "sv_vtxsum_eta",    j,"SVvtxSumEta",52,-2.6,2.6); //75
     AddHisto(HistoBtag, "sv_vtxsum_phi",    j,"SVvtxSumPhi",50,-1.*pi,pi);
     AddHisto(HistoBtag, "sv_vtxdir_eta",    j,"SVvtxDirEta",52,-2.6,2.6);
     AddHisto(HistoBtag, "sv_vtxdir_phi",    j,"SVvtxDirPhi",50,-1.*pi,pi);

     AddHisto(HistoBtag, "sv_vtxsum_ptrel",  j,"SVvtxSumPTrel",100,0.,10.);
     AddHisto(HistoBtag, "sv_vtxdir_ptrel",  j,"SVvtxDirPTrel",100,0.,10.); //80
     AddHisto(HistoBtag, "sv_totcharge",     j,"Total charge",21,-10.5,10.5);
     AddHisto(HistoBtag, "sv_vtx_pt",        j,"PT of vtx",50,0.,100.);
    

// muon in jets : for all jets
     AddHisto(HistoBtag, "muons_multiplicity", j,"# of muons in jet",10,0,10);
     AddHisto(HistoBtag, "muon_Pt", j, "Muon p_{T}",200,0,100);
     AddHisto(HistoBtag, "muon_ptrel", j , "Muon p_{T}^{rel}",50,0,5); //85
     AddHisto(HistoBtag, "muon_Ip3d", j, "Muon 3D IP",50,-0.1,0.1);
     AddHisto(HistoBtag, "muon_Ip2d", j, "Muon 2D IP",50,-0.1,0.1);
     AddHisto(HistoBtag, "muon_Sip3d", j, "Muon 3D IP significance",50,-35,35);
     AddHisto(HistoBtag, "muon_Sip2d", j, "Muon 2D IP significance",50,-35,35);
     AddHisto(HistoBtag, "muon_DeltaR", j,"Muon1 deltaR",50,0,0.5); //90
     AddHisto(HistoBtag, "muon_Ratio", j,"Muon1 energy ratio",50,0.,1.4);

// additional plots : with #PV selection
     // #PV: 1-3
     AddHisto(HistoBtag, "npv1_IP3d2sig0",        j,"2nd sorted track 3D IP significance (#PV:1-3)",100,-35.,35.);
     AddHisto(HistoBtag, "npv1_IP3d3sig0",        j,"3rd sorted track 3D IP significance (#PV:1-3)",100,-35.,35.);
     AddHisto(HistoBtag, "npv1_ntracks_jet",      j,"# of tracks in jet (#PV:1-3)",                 100,0.,100.);
     AddHisto(HistoBtag, "npv1_nseltracks_jet",   j,"# of sel tracks in jet (#PV:1-3)",              50,0.,50.); //95
     AddHisto(HistoBtag, "npv1_ncutseltracks_jet",j,"# of cut sel tracks in jet (#PV:1-3)",          50,0.,50.);
     AddHisto(HistoBtag, "npv1_pt_tracks",        j,"Pt of tracks (#PV:1-3)",                        80,0.,200.);
     AddHisto(HistoBtag, "npv1_pt_seltracks",     j,"Pt of  sel tracks (#PV:1-3)",                   80,0.,200.);
     AddHisto(HistoBtag, "npv1_pt_cutseltracks",  j,"Pt of  cut sel tracks (#PV:1-3)",               80,0.,200.);

     AddHisto(HistoBtag, "npv1_nsv0",              j,"# of secondary vertices (#PV:1-3)",              5,0,5); //100
     AddHisto(HistoBtag, "npv1_nsv",              j,"# of secondary vertices (#PV:1-3)",              5,0,5);
     AddHisto(HistoBtag, "npv1_flightsig3d",      j,"Flight Significance 3D (#PV:1-3)",                  50,0.,100.);
     AddHisto(HistoBtag, "npv1_flightsig3d_3tr",  j,"Flight Significance 3D for >=3tracks (#PV:1-3)",    50,0.,100.);
     AddHisto(HistoBtag, "npv1_svmass",           j,"SV mass (#PV:1-3)",                             50,0.,8.);
     AddHisto(HistoBtag, "npv1_svmass_3tr",       j,"SV mass for >=3tracks (#PV:1-3)",               50,0.,8.); //105

     // #PV: 4-7
     AddHisto(HistoBtag, "npv2_IP3d2sig0",        j,"2nd sorted track 3D IP significance (#PV:4-7)",100,-35.,35.);
     AddHisto(HistoBtag, "npv2_IP3d3sig0",        j,"3rd sorted track 3D IP significance (#PV:4-7)",100,-35.,35.);
     AddHisto(HistoBtag, "npv2_ntracks_jet",      j,"# of tracks in jet (#PV:4-7)",                 100,0.,100.);
     AddHisto(HistoBtag, "npv2_nseltracks_jet",   j,"# of sel tracks in jet (#PV:4-7)",              50,0.,50.); 
     AddHisto(HistoBtag, "npv2_ncutseltracks_jet",j,"# of cut sel tracks in jet (#PV:4-7)",          50,0.,50.);//110
     AddHisto(HistoBtag, "npv2_pt_tracks",        j,"Pt of tracks (#PV:4-7)",                        80,0.,200.);
     AddHisto(HistoBtag, "npv2_pt_seltracks",     j,"Pt of  sel tracks (#PV:4-7)",                   80,0.,200.);
     AddHisto(HistoBtag, "npv2_pt_cutseltracks",  j,"Pt of  cut sel tracks (#PV:4-7)",               80,0.,200.);

     AddHisto(HistoBtag, "npv2_nsv0",              j,"# of secondary vertices (#PV:4-7)",              5,0,5);
     AddHisto(HistoBtag, "npv2_nsv",              j,"# of secondary vertices (#PV:4-7)",              5,0,5); //115
     AddHisto(HistoBtag, "npv2_flightsig3d",      j,"Flight Significance 3D (#PV:4-7)",                  50,0.,100.);
     AddHisto(HistoBtag, "npv2_flightsig3d_3tr",  j,"Flight Significance 3D for >=3tracks (#PV:4-7)",    50,0.,100.);
     AddHisto(HistoBtag, "npv2_svmass",           j,"SV mass (#PV:4-7)",                             50,0.,8.);
     AddHisto(HistoBtag, "npv2_svmass_3tr",       j,"SV mass for >=3tracks (#PV:4-7)",               50,0.,8.);

     // #PV: >7
     AddHisto(HistoBtag, "npv3_IP3d2sig0",        j,"2nd sorted track 3D IP significance (#PV:>7)",100,-35.,35.); //120
     AddHisto(HistoBtag, "npv3_IP3d3sig0",        j,"3rd sorted track 3D IP significance (#PV:>7)",100,-35.,35.);
     AddHisto(HistoBtag, "npv3_ntracks_jet",      j,"# of tracks in jet (#PV:>7)",                 100,0.,100.);
     AddHisto(HistoBtag, "npv3_nseltracks_jet",   j,"# of sel tracks in jet (#PV:>7)",              50,0.,50.);
     AddHisto(HistoBtag, "npv3_ncutseltracks_jet",j,"# of cut sel tracks in jet (#PV:>7)",          50,0.,50.); 
     AddHisto(HistoBtag, "npv3_pt_tracks",        j,"Pt of tracks (#PV:>7)",                        80,0.,200.); //125
     AddHisto(HistoBtag, "npv3_pt_seltracks",     j,"Pt of  sel tracks (#PV:>7)",                   80,0.,200.);
     AddHisto(HistoBtag, "npv3_pt_cutseltracks",  j,"Pt of  cut sel tracks (#PV:>7)",               80,0.,200.);

     AddHisto(HistoBtag, "npv3_nsv0",              j,"# of secondary vertices (#PV:>7)",              5,0,5); 
     AddHisto(HistoBtag, "npv3_nsv",              j,"# of secondary vertices (#PV:>7)",              5,0,5);
     AddHisto(HistoBtag, "npv3_flightsig3d",      j,"Flight Significance 3D (#PV:>7)",                  50,0.,100.); //130
     AddHisto(HistoBtag, "npv3_flightsig3d_3tr",  j,"Flight Significance 3D for >=3tracks (#PV:>7)",    50,0.,100.);
     AddHisto(HistoBtag, "npv3_svmass",           j,"SV mass (#PV:>7)",                             50,0.,8.);
     AddHisto(HistoBtag, "npv3_svmass_3tr",       j,"SV mass for >=3tracks (#PV:>7)",               50,0.,8.);




// additional plots for AN-11-180 
     AddHisto(HistoBtag, "n_cutseltracks_jet",   j,"# of sel tracks in jet",100,0.,100.);
     AddHisto(HistoBtag, "pt_cutseltracks",   j,"Pt of  sel tracks",80,0.,200.);  //135
     AddHisto(HistoBtag, "IP3d1Errorsorted",  j,"1st track 3D IP Error",100,0.,0.1); 
     AddHisto(HistoBtag, "IP3d2Errorsorted",  j,"2nd track 3D IP Error",100,0.,0.1); 
     AddHisto(HistoBtag, "IP3d3Errorsorted",  j,"3rd track 3D IP Error",100,0.,0.1); 
     AddHisto(HistoBtag, "trackIP3d_bin1_cutsel",  j,"Track 3D IP value (1<Pt<=2 GeV/c)",100,-0.05,0.05); 
     AddHisto(HistoBtag, "trackIP3d_bin2_cutsel",  j,"Track 3D IP value (2<Pt<=5 GeV/c)",100,-0.05,0.05); //140
     AddHisto(HistoBtag, "trackIP3d_bin3_cutsel",  j,"Track 3D IP value (5<Pt<=8 GeV/c)",100,-0.05,0.05); 
     AddHisto(HistoBtag, "trackIP3d_bin4_cutsel",  j,"Track 3D IP value (8<Pt<=12 GeV/c)",100,-0.05,0.05); 
     AddHisto(HistoBtag, "trackIP3d_bin5_cutsel",  j,"Track 3D IP value (12<Pt<=20 GeV/c)",100,-0.05,0.05); 
     AddHisto(HistoBtag, "trackIP3d_bin6_cutsel",  j,"Track 3D IP value (20<Pt<=50 GeV/c)",100,-0.05,0.05); 
     AddHisto(HistoBtag, "npv1_nsv_3tr",              j,"# of secondary vertices (>=3tr) (#PV:1-3)",              5,0,5); //145
     AddHisto(HistoBtag, "npv2_nsv_3tr",              j,"# of secondary vertices (>=3tr) (#PV:4-7)",              5,0,5); 
     AddHisto(HistoBtag, "npv3_nsv_3tr",              j,"# of secondary vertices (>=3tr) (#PV:>7)",              5,0,5);
     AddHisto(HistoBtag, "npv1_nsv0_3tr",              j,"# of secondary vertices (>=3tr) (#PV:1-3)",              5,0,5);
     AddHisto(HistoBtag, "npv2_nsv0_3tr",              j,"# of secondary vertices (>=3tr) (#PV:4-7)",              5,0,5); 
     AddHisto(HistoBtag, "npv3_nsv0_3tr",              j,"# of secondary vertices (>=3tr) (#PV:>7)",              5,0,5); //150

     //IP significance sorted in bins of track pt
     AddHisto(HistoBtag, "IP3d1sigsorted_bin1",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d1sigsorted_bin2",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d1sigsorted_bin3",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d1sigsorted_bin4",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d1sigsorted_bin5",j,"1st track 3D IP significance (sorted)",100,-35.,35.);//155
     AddHisto(HistoBtag, "IP3d1sigsorted_bin6",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
 
     AddHisto(HistoBtag, "IP3d2sigsorted_bin1",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d2sigsorted_bin2",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d2sigsorted_bin3",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d2sigsorted_bin4",j,"1st track 3D IP significance (sorted)",100,-35.,35.);//160
     AddHisto(HistoBtag, "IP3d2sigsorted_bin5",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
     AddHisto(HistoBtag, "IP3d2sigsorted_bin6",j,"1st track 3D IP significance (sorted)",100,-35.,35.);
 
     // muon-enriched (ptrel>0) standard track-based properties:

     AddHisto(HistoBtag, "sv_mass_muenriched",    j,"SV mass",50,0.,8.); //163, similar to 60
     AddHisto(HistoBtag, "IP3d2sigsorted_muenriched",j,"2nd track 3D IP significance (sorted)",100,-35.,35.); //164, similar to 51
     AddHisto(HistoBtag, "IP3d2sigzsorted_muenriched",j,"2nd track 3D IP significance (sorted)",100,-2.,2.); //165, similar to 52
     AddHisto(HistoBtag, "sv_flightsig2d_muenriched", j,"Flight significance 2D",50,0.,80.); //166, similar to 54
     AddHisto(HistoBtag, "sv_flightsig3d_muenriched", j,"Flight significance 3D",50,0.,80.); //167, similar to 55
     // the following are filled just after the 'normal' discriminants (#4-10)
     AddHisto(HistoBtag, "discri_tche_muenriched",   j,"TCHE Discriminator",50,0.,30.);  // 168 
     AddHisto(HistoBtag, "discri_tchp_muenriched",   j,"TCHP Discriminator",50,0.,30.);  // 169
     AddHisto(HistoBtag, "discri_ssche_muenriched",   j,"SSVHE Discriminator",50,0.,7.);   // 170
     AddHisto(HistoBtag, "discri_sschp_muenriched",   j,"SSVHP Discriminator",50,0.,7.);  //171


    // ====> ADD HERE NEW HISTO AT 1D FOR WHICH QUARK CONTENT INFO NEEDED
    // example :
    // AddHisto(HistoBtag, "new_histo", j,"Test Caro",50,0.,1.);

// 2D plots SV
     AddHisto2D(Histo2DB, "sv_track_vs_jetpt", j,"SV track multiplicity vs jet pt",80,0,400, 10,0,10);
     AddHisto2D(Histo2DB, "sv_mass_vs_flightDistSignCut", j, " SVMass vs Cut on SV sign ", 100,0, 80,100,0,6);
     AddHisto2D(Histo2DB, "sv_mass_vs_flightDistCut", j, " SVMass vs Cut on SV distance ",100,0, 80,100,0,6);

     AddHisto2D(Histo2DB, "track_vs_jetpt", j,"track multiplicity vs jet pt",80,0,400, 100,0,100);
     AddHisto2D(Histo2DB, "seltrack_vs_jetpt", j,"sel track multiplicity vs jet pt",80,0,400, 100,0,100);
     AddHisto2D(Histo2DB, "cutseltrack_vs_jetpt", j,"sel track multiplicity vs jet pt",80,0,400, 100,0,100);


    // ====> ADD HERE NEW HISTO AT 2D FOR WHICH QUARK CONTENT INFO IS NEEDED

     if (j==0) nhisto_to_clone=HistoBtag.size();
     if (j==0) nhisto_to_clone2D=Histo2DB.size();
   }
   AddHisto(HistoBtag, "pthat",       0,"PThat",80,0.,400.);
   AddHisto(HistoBtag, "prescale_30",      0,"prescale HLT_JET30",400,0.,400.);
   AddHisto(HistoBtag, "prescale_60",      0,"prescale HLT_JET60",400,0.,400.);
   AddHisto(HistoBtag, "prescale_80",      0,"prescale HLT_JET80",400,0.,400.);
   AddHisto(HistoBtag, "prescale_110",     0,"prescale HLT_JET110",400,0.,400.);
   AddHisto(HistoBtag, "prescale_100",     0,"prescale HLTJET100",400,0.,400.);
   AddHisto(HistoBtag, "weight_prescale",  0,"weight from prescale HLTJET50to100",400,0.,400.);
   AddHisto(HistoBtag, "npv",  0,"numberOfPrimaryVertices",50,-0.5,49.5);
   AddHisto(HistoBtag, "npv_no_scaled",  0,"numberOfPrimaryVertices",50,-0.5,49.5);

   AddHisto(HistoBtag, "npu",  0,"numberOfPUVertices",50,-0.5,49.5);
   AddHisto(HistoBtag, "npu_no_scaled",  0,"numberOfPUVertices",50,-0.5,49.5);

    // ====> ADD HERE NEW HISTO AT 1D OR 2D FOR WHICH QUARK CONTENT INFO IS NOT NEEDED
    // in this case, do not put "j" but 0!
    // example : 
    // AddHisto(HistoBtag, "another_new_histo", 0,"Test Caro 2",50,0.,1.);

   cout << " # histos created : " << HistoBtag.size() << " (nhisto_to_clone : " << nhisto_to_clone  << ")" << endl;
/*
   for (int i=0; i<HistoBtag.size(); i++) {
      cout << " HistoBtag[" <<i << "] " << HistoBtag[i]->GetName() << endl;
   }

*/



   cout<< " weight " << weightsave << endl;


   Long64_t nentries = fChain->GetEntries();

   cout << " nentries " << nentries << endl;
   Long64_t nbytes = 0, nb = 0;

   // LOOP ON EVENTS IN THE NTUPLES 

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      float weight=weightsave;
      if(jentry%100000 == 0) cout << "number of processed events " << jentry << endl;

       if (cutgen==1) {
           float weightnpv[26];
// 499 pb-1
          if (Run_on_Jet) {
/*
           //HLT_Jet60
           weightnpv[0]=0;
           weightnpv[1]=0.222754;
           weightnpv[2]=0.754103;
           weightnpv[3]=1.43403;
           weightnpv[4]=1.85957;
           weightnpv[5]=1.94963;
           weightnpv[6]=1.68839;
           weightnpv[7]=1.28163;
           weightnpv[8]=0.884921;
           weightnpv[9]=0.585522;
           weightnpv[10]=0.386745;
           weightnpv[11]=0.264428;
           weightnpv[12]=0.192353;
           weightnpv[13]=0.142132;
           weightnpv[14]=0.113182;
           weightnpv[15]=0.0891076;
           weightnpv[16]=0.0787451;
           weightnpv[17]=0.0544419;
           weightnpv[18]=0.0678632;
           weightnpv[19]=0.0861539;
           weightnpv[20]=0;
           weightnpv[21]=0;
*/
           weightnpv[0]=0.129517;
           weightnpv[1]=0.311049;
           weightnpv[2]=0.877493;
           weightnpv[3]=1.32235;
           weightnpv[4]=1.91109;
           weightnpv[5]=1.81043;
           weightnpv[6]=1.83934;
           weightnpv[7]=1.77981;
           weightnpv[8]=1.29938;
           weightnpv[9]=0.8919;
           weightnpv[10]=0.590799;
           weightnpv[11]=0.430463;
           weightnpv[12]=0.306837;
           weightnpv[13]=0.255782;
           weightnpv[14]=0.20193;
           weightnpv[15]=0.162117;
           weightnpv[16]=0.133357;
           weightnpv[17]=0.0979672;
           weightnpv[18]=0.0954009;
           weightnpv[19]=0.133177;
           weightnpv[20]=0.201325;
           weightnpv[21]=0.159833;
           weightnpv[22]=0.336746;
           weightnpv[23]=0.0713124;
           weightnpv[24]=0.0463483;
           weightnpv[25]=0;

           }
           else if (Run_on_Btag) {
           // BTagMu_Dijet40_Mu5
/*
           weightnpv[0]=0;
           weightnpv[1]=0.185062;
           weightnpv[2]=0.684153;
           weightnpv[3]=1.36635;
           weightnpv[4]=1.80395;
           weightnpv[5]=1.95111;
           weightnpv[6]=1.71438;
           weightnpv[7]=1.31984;
           weightnpv[8]=0.916886;
           weightnpv[9]=0.604304;
           weightnpv[10]=0.403362;
           weightnpv[11]=0.285383;
           weightnpv[12]=0.199778;
           weightnpv[13]=0.148974;
           weightnpv[14]=0.110441;
           weightnpv[15]=0.0930386;
           weightnpv[16]=0.0717144;
           weightnpv[17]=0.0708401;
           weightnpv[18]=0.0359999;
           weightnpv[19]=0.0434156;
           weightnpv[20]=0.;
           weightnpv[21]=0.;
*/
           weightnpv[0]=0.156498;
           weightnpv[1]=0.348279;
           weightnpv[2]=0.931435;
           weightnpv[3]=1.38161;
           weightnpv[4]=1.91335;
           weightnpv[5]=1.8012;
           weightnpv[6]=1.77467;
           weightnpv[7]=1.70689;
           weightnpv[8]=1.25496;
           weightnpv[9]=0.849071;
           weightnpv[10]=0.560916;
           weightnpv[11]=0.410454;
           weightnpv[12]=0.292295;
           weightnpv[13]=0.236444;
           weightnpv[14]=0.186692;
           weightnpv[15]=0.151324;
           weightnpv[16]=0.12243;
           weightnpv[17]=0.0901566;
           weightnpv[18]=0.0918909;
           weightnpv[19]=0.12913;
           weightnpv[20]=0.200706;
           weightnpv[21]=0.181146;
           weightnpv[22]=0.341892;
           weightnpv[23]=0.0849563;
           weightnpv[24]=0.0416172;
           weightnpv[25]=0.;


           }
  
//           int npvval=numberOfPrimaryVertices;
//           if (numberOfPrimaryVertices>=21) npvval=21;
           int npvval=numberOfPUVertices;
           if (numberOfPUVertices>=25) npvval=25;
           weight*=weightnpv[npvval];
       }

      HistoBtag[jmax*nhisto_to_clone]->Fill(pthat,weight);
      HistoBtag[jmax*nhisto_to_clone+1]->Fill(prescaleHLT_Jet30);
      HistoBtag[jmax*nhisto_to_clone+2]->Fill(prescaleHLT_Jet60);
      HistoBtag[jmax*nhisto_to_clone+3]->Fill(prescaleHLT_Jet80);
      HistoBtag[jmax*nhisto_to_clone+4]->Fill(prescaleHLT_Jet110);
      HistoBtag[jmax*nhisto_to_clone+5]->Fill(prescaleHLTJet100U);

      HistoBtag[jmax*nhisto_to_clone+9]->Fill(numberOfPUVertices,weight);
      HistoBtag[jmax*nhisto_to_clone+10]->Fill(numberOfPUVertices,weightsave);


      bool cut_on_mu= false; 
      if (Run_on_Jet) cut_on_mu= false; // for JET
      if (Run_on_Btag) cut_on_mu=true;  // for BTAG

      //// IMPORTANT : TRIGGER 
      bool cut_trigger= false;

      int minimu=1;
      vector<int> presvec;

      // BTAGMET
      int nmu20=0;
      int nmu40=0;
      int nmu70=0;
      int nmu110=0;
      int nmu60=0;
      for (int i=0; i<nJets; i++) {
        if (-2.4<jetEta[i] && jetEta[i]<2.4) {
         // threshold from Daniel
         if (jetPt[i]>40) nmu20++;
         if (jetPt[i]>60) nmu40++;
         if (jetPt[i]>90) nmu60++;
         if (jetPt[i]>100) nmu70++;
//         if (jetPt[i]>130) nmu110++;
         if (jetPt[i]>155) nmu110++;
        }
      }

      // HLT_BTagMu_DiJet20_Mu5
      if (my_trigger_path=="HLT_BTagMu_DiJet20_Mu5") {
       if (cutgen==0 && dataflag>=2) {  // APPLIED ON 2011 DATA
        if ( triggerHLT_BTagMu_DiJet20_Mu5 && nmu20>1 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_BTagMu_DiJet20_Mu5);
        }
       }
       else {  // APPLIED ON MC
        if ( nmu20>1) {
             cut_trigger=true;
             presvec.push_back(1.);
        }
       }
      }
      // HLT_BTagMu_DiJet40_Mu5
      if (my_trigger_path=="HLT_BTagMu_DiJet40_Mu5") {
       if (cutgen==0 && dataflag>=2) {  // APPLIED ON 2011 DATA
        if ( triggerHLT_BTagMu_DiJet40_Mu5 && nmu40>1 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_BTagMu_DiJet40_Mu5);
        }
       }
       else {  // APPLIED ON MC
        if ( nmu40>1) {
             cut_trigger=true;
             presvec.push_back(1.);
        }
       }
      }
      // HLT_BTagMu_DiJet70_Mu5
      if (my_trigger_path=="HLT_BTagMu_DiJet70_Mu5") {
       if (cutgen==0 && dataflag>=2) {  // APPLIED ON 2011 DATA
        if ( triggerHLT_BTagMu_DiJet70_Mu5 && nmu70>1 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_BTagMu_DiJet70_Mu5);
        }
       }
       else {  // APPLIED ON MC
        if ( nmu70>1) {
             cut_trigger=true;
             presvec.push_back(1.);
        }
       }
      }
      // HLT_BTagMu_DiJet110_Mu5
      if (my_trigger_path=="HLT_BTagMu_DiJet110_Mu5") {
       if (cutgen==0 && dataflag>=2) {  // APPLIED ON 2011 DATA
        if ( triggerHLT_BTagMu_DiJet110_Mu5 && nmu110>1 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_BTagMu_DiJet110_Mu5);
        }
       }
       else {  // APPLIED ON MC
        if ( nmu110>1) {
             cut_trigger=true;
             presvec.push_back(1.);
        }
       }
      }

      // HLT_BTagMu_DiJet60_Mu7_v2
      else if (my_trigger_path=="HLT_BTagMu_DiJet60_Mu7") {
       if (cutgen==0 && dataflag>=2) { // APPLIED ON 2011 DATA
        if ( triggerHLT_BTagMu_DiJet60_Mu7_v2 && nmu60>1 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_BTagMu_DiJet60_Mu7_v2);
        }
       }      
       else { // APPLIED ON MC
        if ( nmu60>1 ) {
             cut_trigger=true;
             presvec.push_back(1.);
        } 
       }
      }

      // HLT_Jet30
      else if (my_trigger_path=="HLT_Jet30") {
       if (cutgen==0 && dataflag>=2) { // APPLIED ON 2011 DATA
        if ( triggerHLT_Jet30 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_Jet30);
        }
       }
       else { // APPLIED ON MC AND DATA 2010
        if ( triggerHLTJet15U ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLTJet15U);
        }
       }
      }


      // HLT_Jet60
      else if (my_trigger_path=="HLT_Jet60") {
       if (cutgen==0 && dataflag>=2) {  // APPLIED ON 2011 DATA
        if ( triggerHLT_Jet60 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_Jet60);
        }
       } 
       else { // APPLIED ON MC AND DATA 2010
        if ( triggerHLTJet30U ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLTJet30U);
        }
       } 
      }

      // HLT_Jet80
      else if (my_trigger_path=="HLT_Jet80") {
       if (cutgen==0 && dataflag>=2) {  // APPLIED ON 2011 DATA
        if ( triggerHLT_Jet80 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_Jet80);
        }
       }
       else { // APPLIED ON MC AND DATA 2010
        if ( triggerHLTJet50U ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLTJet50U);
        }
       }
      }

      // HLT_Jet110
      else if (my_trigger_path=="HLT_Jet110") {
       if (cutgen==0 && dataflag>=2) {  // APPLIED ON 2011 DATA
        if ( triggerHLT_Jet110 ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLT_Jet110);
        }
       }
       else { // APPLIED ON MC AND DATA 2010
        if ( triggerHLTJet70U ) {
             cut_trigger=true;
             presvec.push_back(prescaleHLTJet70U);
        }
       }
      }


      if (cut_trigger) {

       minimu=100000;
       // test : take the lowest prescale of triggers
       for (int i=0; i<presvec.size(); i++) {
            if (presvec[i]<minimu) minimu=presvec[i];
       }
       if (cutgen==0) {
//         weight=minimu;  // if we want to apply prescale weight in data
         HistoBtag[jmax*nhisto_to_clone+6]->Fill(minimu);
       }




       HistoBtag[jmax*nhisto_to_clone+7]->Fill(numberOfPrimaryVertices,weight);
       HistoBtag[jmax*nhisto_to_clone+8]->Fill(numberOfPrimaryVertices,weightsave);
       // FILL HERE YOUR NEW HISTO outside "j" loop
       // example :
       // float caro_test_2=0.2;
       // HistoBtag[jmax*nhisto_to_clone+11]->Fill(caro_test_2, weight);   // increase the "10" of "npu" histo into a "11"


       for (int i=0; i<nJets; i++) {
            // cut on Muon in jets from plot_muJet.cfg
           int cut_mu_pass=0;
           if (muon1Pt[i]> cutMuonPt     && TMath::Abs(muon1Eta[i]) < 2.4 && muon1IsGlobal[i] == 1     && 
                muon1GlobalMuonHits[i]> 0 && muon1NumberOfMatches[i]>1     && muon1InnerValidHits[i]>10 &&
                muon1NPixelHits[i]> 1     && muon1NExpectedOuterHits[i]<3  && muon1InnerNChi2[i]< 10    &&
                muon1GlobalNChi2[i]< 10   && muon1VzPVDist[i]< 2           && muon1DeltaR[i]< 0.4) {
                    cut_mu_pass=1;
           }
           if (cut_on_mu==false) cut_mu_pass=1; // BYPASS THIS CUT IF YOU DON'T CARE ABOUT MUON IN JET
           if (jetPt[i]>cutJetPt && -2.4<jetEta[i] && jetEta[i]<2.4 && cut_mu_pass==1) {

            for (int j=0; j<jmax; j++) {
             int ok=0;
             if (j==0) ok=1;  // everyone 
             else if (j==1 && MCTrueFlavor[i]==5 && isBGluonSplitting==0) ok=1;   // b only
             else if (j==2 && MCTrueFlavor[i]==4) ok=1;  // c only
             else if (j==3 && (MCTrueFlavor[i]==0 || MCTrueFlavor[i]==1 || MCTrueFlavor[i]==2 || MCTrueFlavor[i]==3 || MCTrueFlavor[i]==21 )) ok=1;  // light 
             else if (j==4 && MCTrueFlavor[i]==5 && isBGluonSplitting==1) ok=1; // gluon splitting in b
             if (ok==1) {
               // HERE WE FILL THE HISTOGRAMS

                       HistoBtag[0+j*nhisto_to_clone]->Fill(jetPt[i], weight);      // alljetpt

                       //discri
                       HistoBtag[1+j*nhisto_to_clone]->Fill(standardTrackCountingHighEffPFBJetTags[i], weight);
                       HistoBtag[2+j*nhisto_to_clone]->Fill(standardTrackCountingHighPurPFBJetTags[i], weight);

                       HistoBtag[3+j*nhisto_to_clone]->Fill(standardSimpleSecondaryVertexHighEffPFBJetTags[i], weight);
                       HistoBtag[4+j*nhisto_to_clone]->Fill(standardSimpleSecondaryVertexHighEffPFBJetTags[i], weight);
                       HistoBtag[5+j*nhisto_to_clone]->Fill(standardSimpleSecondaryVertexHighPurPFBJetTags[i], weight);
                       HistoBtag[6+j*nhisto_to_clone]->Fill(standardSimpleSecondaryVertexHighPurPFBJetTags[i], weight);

                       HistoBtag[7+j*nhisto_to_clone]->Fill(standardJetProbabilityPFBJetTags[i], weight);
                       HistoBtag[8+j*nhisto_to_clone]->Fill(standardJetBProbabilityPFBJetTags[i], weight);

		       // and same but when requiring a pTrel cut, to enrich the jets in b's
		       if(standardSoftMuonPFBJetTags[i]>0.){		       
			 HistoBtag[168+j*nhisto_to_clone]->Fill(standardTrackCountingHighEffPFBJetTags[i], weight);
			 HistoBtag[169+j*nhisto_to_clone]->Fill(standardTrackCountingHighPurPFBJetTags[i], weight);
			 HistoBtag[170+j*nhisto_to_clone]->Fill(standardSimpleSecondaryVertexHighEffPFBJetTags[i], weight);
			 HistoBtag[171+j*nhisto_to_clone]->Fill(standardSimpleSecondaryVertexHighPurPFBJetTags[i], weight);
		       }

                       // info on tracks
                       int ntrack_jet=0;
                       int nseltrack_jet=0;
                       int ncutseltrack_jet=0;
                       int n1_ip=-1;
                       int n2_ip=-1;
                       int n3_ip=-1;
                       float sig1_ip=-9999;
                       float sig2_ip=-9999;
                       float sig3_ip=-9999;


                       for (int k=0; k<nTracks; k++) {  // LOOP ON THE TRACKS
                         if (trackJetIndex[k]==i)  {    // TRACK ASSOCIATED TO THE JET

                           ntrack_jet++;
                           HistoBtag[10+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight);  //pt_tracks
                           // 9,11,12 : see below 

                           //on all tracks
                           HistoBtag[13+j*nhisto_to_clone]->Fill(trackNHits[k], weight);
                           HistoBtag[14+j*nhisto_to_clone]->Fill(trackNPixelHits[k], weight);
                           HistoBtag[15+j*nhisto_to_clone]->Fill(trackNormChi2[k], weight);
                           HistoBtag[16+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight);
                           HistoBtag[17+j*nhisto_to_clone]->Fill(trackLongitudinalImpactParameter[k], weight);
                           HistoBtag[18+j*nhisto_to_clone]->Fill(trackIP2d[k], weight);
                           HistoBtag[19+j*nhisto_to_clone]->Fill(TMath::Abs(trackDistJetAxis[k]), weight);
                           HistoBtag[20+j*nhisto_to_clone]->Fill(trackDecayLength[k], weight);

                           // cuts N
                           // trackNormChi2 < 5 && trackNHits >= 8 && trackNPixelHits >=2 && 
                           // TMath::Abs(trackLongitudinalImpactParameter) < 17  &&
                           // trackTransverseMomentum > 1 && TMath::Abs(trackIP2d) < 0.2 && 
                           // TMath::Abs(trackDistJetAxis) < 0.07 && trackDecayLength < 5
                           // cuts N-1
                           bool cut1=false;
                           bool cut2=false;
                           bool cut3=false;
                           bool cut4=false;
                           if (trackNormChi2[k] < 5 && trackNHits[k]>= 8 && trackNPixelHits[k] >=2) cut1=true;
                           if (TMath::Abs(trackLongitudinalImpactParameter[k]) < 17) cut2=true;
                           if (trackTransverseMomentum[k]> 1 && TMath::Abs(trackIP2d[k]) < 0.2) cut3=true;
                           if (TMath::Abs(trackDistJetAxis[k])< 0.07 && trackDecayLength[k]< 5) cut4=true;

                           if (trackNormChi2[k]< 5 && trackNPixelHits[k] >=2 && cut2 && cut3 && cut4) HistoBtag[21+j*nhisto_to_clone]->Fill(trackNHits[k], weight);
                           if (trackNormChi2[k]< 5 && trackNHits[k]>= 8      && cut2 && cut3 && cut4) HistoBtag[22+j*nhisto_to_clone]->Fill(trackNPixelHits[k], weight);
                           if (trackNHits[k]>= 8   && trackNPixelHits[k] >=2 && cut2 && cut3 && cut4) HistoBtag[23+j*nhisto_to_clone]->Fill(trackNormChi2[k], weight);
                           if (cut1 && cut2 && TMath::Abs(trackIP2d[k]) < 0.2 && cut4)                HistoBtag[24+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight);
                           if (cut1 && cut3 && cut4)                                                  HistoBtag[25+j*nhisto_to_clone]->Fill(trackLongitudinalImpactParameter[k], weight);
                           if (cut1 && cut2 && trackTransverseMomentum[k]> 1 && cut4)                 HistoBtag[26+j*nhisto_to_clone]->Fill(trackIP2d[k], weight);
                           if (cut1 && cut2 && cut3 && trackDecayLength[k]< 5)                        HistoBtag[27+j*nhisto_to_clone]->Fill(TMath::Abs(trackDistJetAxis[k]), weight);
                           if (cut1 && cut2 && cut3 && TMath::Abs(trackDistJetAxis[k])< 0.07)         HistoBtag[28+j*nhisto_to_clone]->Fill(trackDecayLength[k], weight);

                           HistoBtag[29+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                           HistoBtag[30+j*nhisto_to_clone]->Fill(trackIP3dError[k], weight);
                           HistoBtag[31+j*nhisto_to_clone]->Fill(trackIP3d[k]/trackIP3dError[k], weight);
                           // 32 -34 : IP seltracks
                           // 35 -37 : IP cutseltracks


                            //depending on #PV
                            if (numberOfPrimaryVertices<=3) {          
                              HistoBtag[97+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight);  //pt_tracks
                            }
                            else if (numberOfPrimaryVertices>=4 && numberOfPrimaryVertices<=7) {
                              HistoBtag[111+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight);  //pt_tracks
                            }
                            else {
                              HistoBtag[125+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight);  //pt_tracks
                            }

                            if (trackSelected[k]==true) { // selected tracks
                              nseltrack_jet++;
                              HistoBtag[12+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks
                              HistoBtag[32+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                              HistoBtag[33+j*nhisto_to_clone]->Fill(trackIP3dError[k], weight);
                              HistoBtag[34+j*nhisto_to_clone]->Fill(trackIP3d[k]/trackIP3dError[k], weight);


                              //depending on #PV
                              if (numberOfPrimaryVertices<=3) {          
                                  HistoBtag[98+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks
                              }
                              else if (numberOfPrimaryVertices>=4 && numberOfPrimaryVertices<=7) {
                                  HistoBtag[112+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks
                              }
                              else {
                                  HistoBtag[126+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks
                              }

                            }
                            // apply cut and sort IPsig
                            if (trackSelected[k] && TMath::Abs(trackDistJetAxis[k]) < 0.07 && trackDecayLength[k] < 5   && trackDecayLength[k]>-1 && trackIP3dError[k]!=0.) {

                              ncutseltrack_jet++;
                              HistoBtag[35+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                              HistoBtag[36+j*nhisto_to_clone]->Fill(trackIP3dError[k], weight);
                              HistoBtag[37+j*nhisto_to_clone]->Fill(trackIP3d[k]/trackIP3dError[k], weight);
                              HistoBtag[135+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks

                              if (1<trackTransverseMomentum[k] && trackTransverseMomentum[k]<=2) HistoBtag[139+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                              if (2<trackTransverseMomentum[k] && trackTransverseMomentum[k]<=5) HistoBtag[140+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                              if (5<trackTransverseMomentum[k] && trackTransverseMomentum[k]<=8) HistoBtag[141+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                              if (8<trackTransverseMomentum[k] && trackTransverseMomentum[k]<=12) HistoBtag[142+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                              if (12<trackTransverseMomentum[k] && trackTransverseMomentum[k]<=20) HistoBtag[143+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);
                              if (20<trackTransverseMomentum[k] && trackTransverseMomentum[k]<=50) HistoBtag[144+j*nhisto_to_clone]->Fill(trackIP3d[k], weight);

                              //depending on #PV
                              if (numberOfPrimaryVertices<=3) {          
                                HistoBtag[99+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks
                              }
                              else if (numberOfPrimaryVertices>=4 && numberOfPrimaryVertices<=7) {
                                HistoBtag[113+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks
                              }
                              else {
                                HistoBtag[127+j*nhisto_to_clone]->Fill(trackTransverseMomentum[k], weight); //pt_seltracks
                              }

                              float sig=trackIP3d[k]/trackIP3dError[k];
                              if (sig>sig1_ip) {
                                 sig3_ip=sig2_ip;
                                 sig2_ip=sig1_ip;
                                 sig1_ip=sig;
                                 n3_ip=n2_ip;
                                 n2_ip=n1_ip;
                                 n1_ip=k;
                              }
                              else if (sig>sig2_ip) {
                                 sig3_ip=sig2_ip;
                                 sig2_ip=sig;
                                 n3_ip=n2_ip;
                                 n2_ip=k;
                              }
                              else if (sig>sig3_ip) {
                                 sig3_ip=sig;
                                 n3_ip=k;
                              }
                           }  



                         } // end trackJetIndex
                       } // end nTracks loop
                       HistoBtag[9+j*nhisto_to_clone]->Fill(ntrack_jet, weight);  // ntracks_jet
                       HistoBtag[11+j*nhisto_to_clone]->Fill(nseltrack_jet, weight); // nseltracks_jet

                       // IP
                       if (TMath::Abs(IP3dDistJetAxis1[i]) < 0.07 && IP3dDecayLength1[i] < 5 && IP3d1[i]>-99 && IP3dError1[i]>-0.5) {  
                         HistoBtag[38+j*nhisto_to_clone]->Fill(IP3d1[i], weight);
                         HistoBtag[39+j*nhisto_to_clone]->Fill(IP3d1[i]/IP3dError1[i], weight);
                         HistoBtag[40+j*nhisto_to_clone]->Fill(IP3d1[i]/IP3dError1[i], weight);
                       }
                       if (TMath::Abs(IP3dDistJetAxis2[i]) < 0.07 && IP3dDecayLength2[i] < 5 && IP3d2[i]>-99 && IP3dError2[i]>-0.5) {  
                         HistoBtag[41+j*nhisto_to_clone]->Fill(IP3d2[i], weight);
                         HistoBtag[42+j*nhisto_to_clone]->Fill(IP3d2[i]/IP3dError2[i], weight);
                         HistoBtag[43+j*nhisto_to_clone]->Fill(IP3d2[i]/IP3dError2[i], weight);
                       }
                       if (TMath::Abs(IP3dDistJetAxis3[i]) < 0.07 && IP3dDecayLength3[i] < 5 && IP3d3[i]>-99 && IP3dError3[i]>-0.5) {  
                         HistoBtag[44+j*nhisto_to_clone]->Fill(IP3d3[i], weight);
                         HistoBtag[45+j*nhisto_to_clone]->Fill(IP3d3[i]/IP3dError3[i], weight);
                         HistoBtag[46+j*nhisto_to_clone]->Fill(IP3d3[i]/IP3dError3[i], weight);
                       }

                       // tracks sorted by ip

                       if (n1_ip>-1)  {
                          HistoBtag[47+j*nhisto_to_clone]->Fill(trackIP3d[n1_ip], weight);
                          HistoBtag[136+j*nhisto_to_clone]->Fill(trackIP3dError[n1_ip], weight);

			  if (1<trackTransverseMomentum[n1_ip] && trackTransverseMomentum[n1_ip]<=2)HistoBtag[151+j*nhisto_to_clone]->Fill(sig1_ip, weight);
			  if (2<trackTransverseMomentum[n1_ip] && trackTransverseMomentum[n1_ip]<=5)HistoBtag[152+j*nhisto_to_clone]->Fill(sig1_ip, weight);
			  if (5<trackTransverseMomentum[n1_ip] && trackTransverseMomentum[n1_ip]<=8)HistoBtag[153+j*nhisto_to_clone]->Fill(sig1_ip, weight);
			  if (8<trackTransverseMomentum[n1_ip] && trackTransverseMomentum[n1_ip]<=12)HistoBtag[154+j*nhisto_to_clone]->Fill(sig1_ip, weight);
			  if (12<trackTransverseMomentum[n1_ip] && trackTransverseMomentum[n1_ip]<=20)HistoBtag[155+j*nhisto_to_clone]->Fill(sig1_ip, weight);
			  if (20<trackTransverseMomentum[n1_ip] && trackTransverseMomentum[n1_ip]<=50)HistoBtag[156+j*nhisto_to_clone]->Fill(sig1_ip, weight);
		
			  // add sorted
			  //  std::cout<<"trackIP3d[n1_ip]/trackIP3dError[n1_ip] - sig1_ip = " << trackIP3d[n1_ip]/trackIP3dError[n1_ip] - sig1_ip << std::endl;
                       }
                       HistoBtag[48+j*nhisto_to_clone]->Fill(sig1_ip, weight);
                       HistoBtag[49+j*nhisto_to_clone]->Fill(sig1_ip, weight);

                       if (n2_ip>-1) {
                          HistoBtag[50+j*nhisto_to_clone]->Fill(trackIP3d[n2_ip], weight);
                          HistoBtag[137+j*nhisto_to_clone]->Fill(trackIP3dError[n2_ip], weight);

			  if (1<trackTransverseMomentum[n2_ip] && trackTransverseMomentum[n2_ip]<=2)HistoBtag[157+j*nhisto_to_clone]->Fill(sig2_ip, weight);
			  if (2<trackTransverseMomentum[n2_ip] && trackTransverseMomentum[n2_ip]<=5)HistoBtag[158+j*nhisto_to_clone]->Fill(sig2_ip, weight);
			  if (5<trackTransverseMomentum[n2_ip] && trackTransverseMomentum[n2_ip]<=8)HistoBtag[159+j*nhisto_to_clone]->Fill(sig2_ip, weight);
			  if (8<trackTransverseMomentum[n2_ip] && trackTransverseMomentum[n2_ip]<=12)HistoBtag[160+j*nhisto_to_clone]->Fill(sig2_ip, weight);
			  if (12<trackTransverseMomentum[n2_ip] && trackTransverseMomentum[n2_ip]<=20)HistoBtag[161+j*nhisto_to_clone]->Fill(sig2_ip, weight);
			  if (20<trackTransverseMomentum[n2_ip] && trackTransverseMomentum[n2_ip]<=50)HistoBtag[162+j*nhisto_to_clone]->Fill(sig2_ip, weight);

                       }
                       HistoBtag[51+j*nhisto_to_clone]->Fill(sig2_ip, weight);
                       HistoBtag[52+j*nhisto_to_clone]->Fill(sig2_ip, weight);
		       if(standardSoftMuonPFBJetTags[i]>0.){
			 HistoBtag[164+j*nhisto_to_clone]->Fill(sig2_ip, weight);
			 HistoBtag[165+j*nhisto_to_clone]->Fill(sig2_ip, weight);
		       }

                       if (n3_ip>-1) {
                          HistoBtag[53+j*nhisto_to_clone]->Fill(trackIP3d[n3_ip], weight);
                          HistoBtag[138+j*nhisto_to_clone]->Fill(trackIP3dError[n3_ip], weight);
                       }
                       HistoBtag[54+j*nhisto_to_clone]->Fill(sig3_ip, weight);
                       HistoBtag[55+j*nhisto_to_clone]->Fill(sig3_ip, weight);
                       Histo2DB[3+j*nhisto_to_clone2D]->Fill(jetPt[i],ntrack_jet, weight);
                       Histo2DB[4+j*nhisto_to_clone2D]->Fill(jetPt[i],nseltrack_jet, weight);
                       Histo2DB[5+j*nhisto_to_clone2D]->Fill(jetPt[i],ncutseltrack_jet, weight);

		       if(standardSoftMuonPFBJetTags[i]>0.){
			 HistoBtag[166+j*nhisto_to_clone]->Fill(sig3_ip, weight);
			 HistoBtag[167+j*nhisto_to_clone]->Fill(sig3_ip, weight);
		       }

                       // SV
                       Histo2DB[0+j*nhisto_to_clone2D]->Fill(jetPt[i],SVnVertexTracks[i], weight);
                       HistoBtag[56+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                       if(SVnVertices[i]>0) {
                        HistoBtag[57+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                        HistoBtag[58+j*nhisto_to_clone]->Fill(jetPt[i], weight);
                        HistoBtag[59+j*nhisto_to_clone]->Fill(SVNormChi2[i], weight);

                        HistoBtag[60+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                        // 61 see below
			if(standardSoftMuonPFBJetTags[i]>0)
			  HistoBtag[163+j*nhisto_to_clone]->Fill(SVMass[i], weight);

                        HistoBtag[62+j*nhisto_to_clone]->Fill(SVnVertexTracks[i], weight);
                        HistoBtag[63+j*nhisto_to_clone]->Fill(SVnFirstVertexTracks[i], weight);
                        HistoBtag[64+j*nhisto_to_clone]->Fill(SVnSelectedTracks[i], weight);

                        HistoBtag[65+j*nhisto_to_clone]->Fill(SVIPFirstAboveCharm[i], weight);
                        HistoBtag[66+j*nhisto_to_clone]->Fill(SVEnergyRatio[i], weight);

                        HistoBtag[67+j*nhisto_to_clone]->Fill(SV2dDistance[i]/SV2dDistanceError[i], weight);
                        HistoBtag[68+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                        HistoBtag[69+j*nhisto_to_clone]->Fill(SV2dDistance[i], weight);
                        HistoBtag[70+j*nhisto_to_clone]->Fill(SV3dDistance[i], weight);
                        if (SVnVertexTracks[i]>=3) {
                             HistoBtag[61+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                             HistoBtag[71+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                        }

                        HistoBtag[72+j*nhisto_to_clone]->Fill(SVjetDeltaR[i], weight);
                        HistoBtag[73+j*nhisto_to_clone]->Fill(SVvtxSumJetDeltaR[i], weight);
                        HistoBtag[74+j*nhisto_to_clone]->Fill(SVvtxSumVtxDirDeltaR[i], weight);

                        HistoBtag[75+j*nhisto_to_clone]->Fill(SVvtxSumDirEta[i], weight);
                        HistoBtag[76+j*nhisto_to_clone]->Fill(SVvtxSumDirPhi[i], weight);
                        HistoBtag[77+j*nhisto_to_clone]->Fill(SVvtxDirEta[i], weight);
                        HistoBtag[78+j*nhisto_to_clone]->Fill(SVvtxDirPhi[i], weight);

                        HistoBtag[79+j*nhisto_to_clone]->Fill(SVvtxSumPTrel[i], weight);
                        HistoBtag[80+j*nhisto_to_clone]->Fill(SVvtxDirPTrel[i], weight);
                        HistoBtag[81+j*nhisto_to_clone]->Fill(SVtotCharge[i], weight);
                        HistoBtag[82+j*nhisto_to_clone]->Fill(SVvtxPt[i], weight);

                        Histo2DB[1+j*nhisto_to_clone2D]->Fill(SV3dDistance[i]/SV3dDistanceError[i], SVMass[i], weight);
                        Histo2DB[2+j*nhisto_to_clone2D]->Fill(SV3dDistance[i], SVMass[i], weight);

                } // end cut SVnVertices

                // muon info
                HistoBtag[83+j*nhisto_to_clone]->Fill(nMuons[i], weight);
                HistoBtag[84+j*nhisto_to_clone]->Fill(muon1Pt[i], weight);
                HistoBtag[85+j*nhisto_to_clone]->Fill(muon1PtRel[i], weight);
                HistoBtag[86+j*nhisto_to_clone]->Fill(muon1Ip3d[i], weight);
                HistoBtag[87+j*nhisto_to_clone]->Fill(muon1Ip2d[i], weight);
                HistoBtag[88+j*nhisto_to_clone]->Fill(muon1Sip3d[i], weight);
                HistoBtag[89+j*nhisto_to_clone]->Fill(muon1Sip2d[i], weight);
                HistoBtag[90+j*nhisto_to_clone]->Fill(muon1DeltaR[i], weight);
                HistoBtag[91+j*nhisto_to_clone]->Fill(muon1Ratio[i], weight);
      
                HistoBtag[134+j*nhisto_to_clone]->Fill(ncutseltrack_jet, weight); // nseltracks_jet
                // depending on #PV
                if (numberOfPrimaryVertices<=3) {          
                 HistoBtag[92+j*nhisto_to_clone]->Fill(sig2_ip, weight);
                 HistoBtag[93+j*nhisto_to_clone]->Fill(sig3_ip, weight);
                 HistoBtag[94+j*nhisto_to_clone]->Fill(ntrack_jet, weight);  // ntracks_jet
                 HistoBtag[95+j*nhisto_to_clone]->Fill(nseltrack_jet, weight); // nseltracks_jet
                 HistoBtag[96+j*nhisto_to_clone]->Fill(ncutseltrack_jet, weight); // nseltracks_jet
                 // 97 : see above in track loop
                 // 98 : see above in track loop
                 // 99 : see above in track loop
                 HistoBtag[100+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                 int nnsv3tr=0;
                 if (SVnVertexTracks[i]>=3) nnsv3tr=SVnVertices[i];
                 HistoBtag[148+j*nhisto_to_clone]->Fill(nnsv3tr, weight);
                 if(SVnVertices[i]>0) {
                     HistoBtag[101+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                     HistoBtag[102+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                     HistoBtag[104+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                     if (SVnVertexTracks[i]>=3) {
                          HistoBtag[103+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                          HistoBtag[105+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                          HistoBtag[145+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                     }
                 }
                }
                else if (numberOfPrimaryVertices>=4 && numberOfPrimaryVertices<=7) {
                 HistoBtag[106+j*nhisto_to_clone]->Fill(sig2_ip, weight);
                 HistoBtag[107+j*nhisto_to_clone]->Fill(sig3_ip, weight);
                 HistoBtag[108+j*nhisto_to_clone]->Fill(ntrack_jet, weight);  // ntracks_jet
                 HistoBtag[109+j*nhisto_to_clone]->Fill(nseltrack_jet, weight); // nseltracks_jet
                 HistoBtag[110+j*nhisto_to_clone]->Fill(ncutseltrack_jet, weight); // nseltracks_jet
                 // 111 : see above in track loop
                 // 112 : see above in track loop
                 // 113 : see above in track loop
                 HistoBtag[114+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                 int nnsv3tr=0;
                 if (SVnVertexTracks[i]>=3) nnsv3tr=SVnVertices[i];
                 HistoBtag[149+j*nhisto_to_clone]->Fill(nnsv3tr, weight);
                 if(SVnVertices[i]>0) {
                     HistoBtag[115+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                     HistoBtag[116+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                     HistoBtag[118+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                     if (SVnVertexTracks[i]>=3) {
                          HistoBtag[117+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                          HistoBtag[119+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                          HistoBtag[146+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                     }
                 }
                }
                else {
                 HistoBtag[120+j*nhisto_to_clone]->Fill(sig2_ip, weight);
                 HistoBtag[121+j*nhisto_to_clone]->Fill(sig3_ip, weight);
                 HistoBtag[122+j*nhisto_to_clone]->Fill(ntrack_jet, weight);  // ntracks_jet
                 HistoBtag[123+j*nhisto_to_clone]->Fill(nseltrack_jet, weight); // nseltracks_jet
                 HistoBtag[124+j*nhisto_to_clone]->Fill(ncutseltrack_jet, weight); // nseltracks_jet
                 // 125 : see above in track loop
                 // 126 : see above in track loop
                 // 127 : see above in track loop
                 HistoBtag[128+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                 int nnsv3tr=0;
                 if (SVnVertexTracks[i]>=3) nnsv3tr=SVnVertices[i];
                 HistoBtag[150+j*nhisto_to_clone]->Fill(nnsv3tr, weight);
                 if(SVnVertices[i]>0) {
                     HistoBtag[129+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                     HistoBtag[130+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                     HistoBtag[132+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                     if (SVnVertexTracks[i]>=3) {
                          HistoBtag[131+j*nhisto_to_clone]->Fill(SV3dDistance[i]/SV3dDistanceError[i], weight);
                          HistoBtag[133+j*nhisto_to_clone]->Fill(SVMass[i], weight);
                          HistoBtag[147+j*nhisto_to_clone]->Fill(SVnVertices[i], weight);
                     }
                 }
                }

                // FILL HERE YOUR NEW HISTO in "j" loop
                // example :
	        // float caro_new_info=0.6;
                // HistoBtag[151+j*nhisto_to_clone]->Fill(caro_new_info, weight); // the "150" of "nnsv3tr" becomes here a "150" for "new_histo"



             } // end cut ok

         } // end loop j : quark composition
        } //jet cut (Pt, Eta)
      } // end loop i : Jet
      } // cut trigger
        
   } // loop event

   TString rootfiletofill = final_dir+"/histoFile.root";
   TFile* fout  = new TFile(rootfiletofill,"RECREATE");
   for (unsigned int i=0; i<HistoBtag.size(); i++) {
        HistoBtag[i]->Write();
   }
   for (unsigned int i=0; i<Histo2DB.size(); i++) {
        Histo2DB[i]->Write();
   }
   fout->Close();

   for (unsigned int i=0; i<HistoBtag.size(); i++) {
        HistoBtag[i]=0;
   }
   HistoBtag.clear();
   for (unsigned int i=0; i<Histo2DB.size(); i++) {
        Histo2DB[i]=0;
   }
   Histo2DB.clear();


}


void btagNtupReader::AddHisto(vector<TH1F*> &HistoBtag, string name, const int& j, string title, const int& nbins, const float& min, const float& max)  {
        
       char namehisto[35];
       if (j==0) sprintf(namehisto,"%s",name.c_str());
       else if (j==1) sprintf(namehisto,"%s_b",name.c_str());
       else if (j==2) sprintf(namehisto,"%s_c",name.c_str());
       else if (j==3) sprintf(namehisto,"%s_udsg",name.c_str());
       else if (j==4) sprintf(namehisto,"%s_gspl",name.c_str());
       TH1F* h = new TH1F(namehisto,title.c_str(),nbins,min,max);
       h->Sumw2();
       HistoBtag.push_back(h);
}
void btagNtupReader::AddHisto2D(vector<TH2F*> &Histo2DB, string name, const int& j, string title, const int& nbins, const float& min, const float& max, const int& nbinsy, const float& miny, const float& maxy)  {
        
       char namehisto[35];
       if (j==0) sprintf(namehisto,"%s",name.c_str());
       else if (j==1) sprintf(namehisto,"%s_b",name.c_str());
       else if (j==2) sprintf(namehisto,"%s_c",name.c_str());
       else if (j==3) sprintf(namehisto,"%s_udsg",name.c_str());
       else if (j==4) sprintf(namehisto,"%s_gspl",name.c_str());
       TH2F* h1 = new TH2F(namehisto,title.c_str(),nbins,min,max,nbinsy,miny,maxy);
       h1->Sumw2();
       Histo2DB.push_back(h1);
}

