/////////////////////////////////////////////////////////////////
// Author : Caroline Collard (IPHC) - first commit : april 2011
////////////////////////////////////////////////////////////////

#include <vector>

string ptval_jet="60";
string ptval_btag="40";

PlotStack(TString selection, int date, bool down=false, bool logy=false, bool mu=false){
  
 
  const int maxmax=10;
  TFile * mc[maxmax];


////// IMPORTANT : DEFINE HERE THE DIRECTORY WHERE THE FILES ARE : "dir"
  string ptval;
  string dir;
   if (mu==false) {
     ptval=ptval_jet;
     dir ="dir_jet"+ptval+"/";
   }
   else {
     ptval=ptval_btag;
     dir ="dir_btag"+ptval+"/";
   }
  cout << dir << endl;

  vector<string> nameroot;
  if (mu==false) {

// PUT HERE THE NAME OF QCD ROOTFILES
  if (ptval!="60" && ptval!="80" && ptval!="110") nameroot.push_back(dir+"histo_qcd15.root");
  nameroot.push_back(dir+"histo_qcd30.root");
  nameroot.push_back(dir+"histo_qcd50.root");
  nameroot.push_back(dir+"histo_qcd80.root");
  nameroot.push_back(dir+"histo_qcd120.root");
  nameroot.push_back(dir+"histo_qcd170.root");
  nameroot.push_back(dir+"histo_qcd300.root");
  }
  else {
// PUT HERE THE NAME OF QCD (MU ENRICHED) ROOTFILES
  nameroot.push_back(dir+"histo_qcdmu15.root");
  nameroot.push_back(dir+"histo_qcdmu20.root");
  nameroot.push_back(dir+"histo_qcdmu30.root");
  nameroot.push_back(dir+"histo_qcdmu50.root");
  nameroot.push_back(dir+"histo_qcdmu80.root");
  nameroot.push_back(dir+"histo_qcdmu120.root");
  nameroot.push_back(dir+"histo_qcdmu150.root");
  }


  for (int i=0; i<nameroot.size(); i++){
    if (i<maxmax) {
     mc[i] = new TFile(nameroot[i].c_str());
//     cout << " root " << nameroot[i].c_str() << endl;
    }
  }


  string dataroot;
  string dataroot2;
  if (date==2010) {
     dataroot=dir+"histo_minijet2010.root";
  }
  else if (date==2011) {
    if (mu==false) {dataroot=dir+"histo_minijet2011.root"; }
    else           {dataroot=dir+"histo_minibtag2011.root"; }
  }
  TFile * data   = new TFile(dataroot.c_str());

//  if (mu==false) {dataroot2=dir+"histo_minijet2010.root"; }
  if (mu==false) {dataroot2=dir+"histo_minijet2011.root"; } // pas de 2010 pour l'instant
  else           {dataroot2=dir+"histo_minibtag2011.root"; }  // AS NO 2010 BTAG DATA YET, PUT 2011 TO AVOID CRASH...
  TFile * data2  = new TFile(dataroot2.c_str());


  TH1F * histo0_Data;
  TH1F * histo0_2010;
  TH1F * histo0_MC;
  TH1F * histo0_MC_b;
  TH1F * histo0_MC_c;
  TH1F * histo0_MC_udsg;
  TH1F * histo0_MC_gspl;

  TH1F* histo_MC[maxmax];
  TH1F* histo_MC_b[maxmax];
  TH1F* histo_MC_c[maxmax];
  TH1F* histo_MC_udsg[maxmax];
  TH1F* histo_MC_gspl[maxmax];

  TH1F * histo0_ratio;
  TH1F * histo0_ratio2;

  
  //###################################################
  //###################################################
  
  
  histo0_Data = (TH1F*)data->Get(selection);
  histo0_2010 = (TH1F*)data2->Get(selection);

  TString bsel = selection+"_b";
  TString csel = selection+"_c";
  TString lsel = selection+"_udsg"; 
  TString gsel = selection+"_gspl";
  if (selection=="npv" || selection=="pthat" || selection=="npv_no_scaled" || selection=="npu") {
   // IF selection=="npv" or selection=="pthat", no _b info
   // PUT DUMMY NAMES TO AVOID CRASH...
   bsel = "sv_jetpt_b";
   csel = "sv_jetpt_b";
   lsel = "sv_jetpt_b";
   gsel = "sv_jetpt_b";
  }
  for (int i=0; i<nameroot.size(); i++){
   histo_MC[i]     =(TH1F*)mc[i]->Get(selection);
   histo_MC_b[i]   =(TH1F*)mc[i]->Get(bsel);
   histo_MC_c[i]   =(TH1F*)mc[i]->Get(csel);
   histo_MC_udsg[i]=(TH1F*)mc[i]->Get(lsel);
   histo_MC_gspl[i]=(TH1F*)mc[i]->Get(gsel);
  
//   if (selection=="npv") cout <<  " somme MC :      i = " << i  << endl;
 
   if (i==0) {
    histo0_MC=      (TH1F*)mc[i]->Get(selection);
    histo0_MC_b=    (TH1F*)mc[i]->Get(bsel);
    histo0_MC_c=    (TH1F*)mc[i]->Get(csel);
    histo0_MC_udsg= (TH1F*)mc[i]->Get(lsel);
    histo0_MC_gspl= (TH1F*)mc[i]->Get(gsel);
//    histo0_MC_b->Add(histo_MC_gspl[0]);
   }
   else {
    histo0_MC->Add(histo_MC[i]);
    histo0_MC_b->Add(histo_MC_b[i]);
//    histo0_MC_b->Add(histo_MC_gspl[i]);
    histo0_MC_c->Add(histo_MC_c[i]);
    histo0_MC_udsg->Add(histo_MC_udsg[i]);
    histo0_MC_gspl->Add(histo_MC_gspl[i]);
   }
  }


  // SCALE MC TO DATA
  float scaleparam=histo0_Data->Integral()/histo0_MC->Integral();
  if (selection!="npv_no_scaled" && selection!="npu") {
   histo0_MC_b->Scale(scaleparam);
   histo0_MC_c->Scale(scaleparam);
   histo0_MC_udsg->Scale(scaleparam);
   histo0_MC_gspl->Scale(scaleparam);
   histo0_MC->Scale(scaleparam);
  }
  else {
   float scaleaa=1./histo0_MC->Integral();
   float scalebb=1./histo0_Data->Integral();
   histo0_MC_b->Scale(scaleaa);
   histo0_MC_c->Scale(scaleaa);
   histo0_MC_udsg->Scale(scaleaa);
   histo0_MC_gspl->Scale(scaleaa);
   histo0_MC->Scale(scaleaa);
   histo0_Data->Scale(scalebb);
    histo0_MC->SetMaximum(histo0_Data->GetMaximum()*1.1);

  }


  // SCALE 2010 TO 2011
  float scaledata=histo0_Data->Integral()/histo0_2010->Integral();
  histo0_2010->Scale(scaledata);


  // MAKE DATA/MC RATIO
  histo0_ratio = (TH1F*) histo0_Data->Clone();
  histo0_ratio->SetName("histo0_ratio");
  histo0_ratio->SetTitle("");


  // REBIN 

  if (selection=="muon_Pt"  ) {
     histo0_ratio->Rebin(2);
     histo0_Data->Rebin(2);
     histo0_2010->Rebin(2);
     histo0_MC->Rebin(2);
     histo0_MC_b->Rebin(2);
     histo0_MC_c->Rebin(2);
     histo0_MC_udsg->Rebin(2);
     histo0_MC_gspl->Rebin(2);
   }



  histo0_ratio->Divide(histo0_MC);

  if (selection=="npv_no_scaled" ){
    for (int iii=1; iii<histo0_ratio->GetNbinsX(); iii++) {
       cout << iii-1 << " " << histo0_ratio->GetBinContent(iii) << endl;
    }
  }
  else if (selection=="npu"){
    for (int iii=1; iii<histo0_MC->GetNbinsX(); iii++) {
       cout << iii-1 << " " << histo0_MC->GetBinContent(iii) << endl;
    }
  }

 
  // MAKE 2010/2011 RATIO 
  histo0_rat2010 = (TH1F*) histo0_2010->Clone();
  histo0_rat2010->SetName("histo0_rat2010");
  histo0_rat2010->Divide(histo0_MC);

  histo0_ratdata = (TH1F*) histo0_Data->Clone();
  histo0_ratdata->SetName("histo0_ratdata");
  histo0_ratdata->Divide(histo0_2010);


  // SET COLORS
  histo0_MC->SetLineColor(2);
  histo0_MC_b->SetFillColor(2);
  histo0_MC_c->SetFillColor(8);
  histo0_MC_gspl->SetFillColor(7);
  histo0_MC_udsg->SetFillColor(4);

  // DO STACK
  THStack* hs= new THStack();
  if (down==false) {
    hs->Add(histo0_MC_udsg);
    hs->Add(histo0_MC_c);
    hs->Add(histo0_MC_gspl); 
    hs->Add(histo0_MC_b);
  }
  else {
    hs->Add(histo0_MC_b);
    hs->Add(histo0_MC_gspl);  
    hs->Add(histo0_MC_c);
    hs->Add(histo0_MC_udsg);
  }
  
  // SET COSMETICS
  histo0_Data->SetMarkerStyle(20);
  histo0_Data->SetMarkerSize(0.75);
  histo0_Data->GetXaxis()->SetTitle(histo0_MC->GetName());  
  if (selection=="npv" || selection=="npv_no_scaled") histo0_Data->GetXaxis()->SetTitle(histo0_MC->GetTitle());  

  histo0_2010->SetMarkerStyle(21);
  histo0_2010->SetMarkerColor(7);
  histo0_2010->SetLineColor(7);
  histo0_2010->SetMarkerSize(0.5);

  hs->SetTitle(histo0_Data->GetTitle());

  if (selection=="sv_vtxsum_phi" || selection=="sv_vtxdir_phi" || selection=="sv_vtxsum_eta" || selection=="sv_vtxdir_eta") {
      hs->SetMaximum(hs->GetMaximum()*1.5);
      hs->SetMinimum(0.);
      histo0_Data->SetMinimum(0.);
      histo0_Data->SetMaximum(histo0_Data->GetMaximum()*1.5);
  }
  if (selection=="trackNHits" || selection=="trackNHits_cut") {
     hs->SetMaximum(hs->GetMaximum()*1.25);
     histo0_Data->SetMaximum(histo0_Data->GetMaximum()*1.25);
  }
  if (selection=="trackIP3dsig" || selection=="trackIP3dsig_sel"
        || selection=="trackIP3dsig_cutsel" ) {
      hs->SetMaximum(hs->GetMaximum()*1.5);
      histo0_Data->SetMaximum(histo0_Data->GetMaximum()*1.5);
  }

  if (selection=="sv_flightsig3d_3tr") {
     hs->SetMaximum(hs->GetMaximum()*1.5);
     histo0_Data->SetMaximum(histo0_Data->GetMaximum()*1.5);
  }


  // CREATE CANVAS
  TCanvas *canvas = new TCanvas("c1", "c1",10,32,782,552);
  canvas->cd();

  // FIRST MC & DATA
  TPad *canvas_1 = new TPad("canvas_1", "canvas_1",0,0.25,1.0,0.98);
  canvas_1->Draw();
  canvas_1->cd();


  if (histo0_Data->GetMaximum() > hs->GetMaximum() ) {
    hs->SetMaximum(histo0_Data->GetMaximum() );
  }
  if (selection=="sv_eratio") {
    hs->SetMaximum(hs->GetMaximum() *1.25 );
    if (ptval=="70" && mu==true) hs->SetMaximum(hs->GetMaximum() *1.25 );
    if (hs->GetMaximum()<histo0_Data->GetMaximum()) hs->SetMaximum(histo0_Data->GetMaximum()*1.1 );
    if (ptval=="110" && mu==true) hs->SetMaximum(hs->GetMaximum() *2. );
  }
  if (ptval=="110" && mu==true && selection=="sv_vtx_pt" ) hs->SetMaximum(hs->GetMaximum() *1.5 );
  if (selection!="npv" && selection!="npv_no_scaled" && selection!="npu") {
   hs->Draw("hist");
  }
  else {
   histo0_MC->Draw("hist");
  }
  if (selection!="pthat" && selection!="npu") histo0_Data->Draw("e same");

  // ADD LEGEND
  TLegend* qw = 0;
  if (mu==false) {
    if (selection=="sv_eratio") {
     qw = new TLegend(0.5,0.73,0.8,1.);
    }
    else if (selection=="IP3d1" || selection=="IP3d1sorted" || selection=="trackIP3d" || selection=="trackIP3d_cutsel") {
     qw = new TLegend(0.12,0.63,0.42,0.9);
    }
    else {
     qw = new TLegend(0.6,0.73,0.95,1.);
    }
  } 
  else {
    if (selection=="sv_eratio") {
     qw = new TLegend(0.12,0.63,0.42,0.9);
    }
    else if (selection=="IP3d1" || selection=="IP3d1sorted" || selection=="IP3d1sig" || selection=="IP3d1sigsorted" || selection=="sv_ipsigcharm" ||
 	selection=="IP3d2" || selection=="IP3d2sorted" || selection=="IP3d2sig" || selection=="IP3d2sigsorted" || 
 	selection=="IP3d3" || selection=="IP3d3sorted" || selection=="IP3d3sig" || selection=="IP3d3sigsorted" 
	) {
     qw = new TLegend(0.12,0.63,0.42,0.9);
    }
    else {
     qw = new TLegend(0.6,0.73,0.95,1.);
    }
  }

  if (selection!="pthat" && selection!="npu") {
  if (date==2010) {
     qw->SetHeader("CMS Preliminary, 33 pb^{-1}");
     qw->AddEntry(histo0_Data,        "JET Run2010B ",           "p");
  }
  else if (date==2011) {
   if (mu==false) {
      if (ptval=="30") {
       qw->SetHeader("2011 effective lumi : 0.0031  pb^{-1}"); // 30
       qw->AddEntry(histo0_Data,        "HLT_JET30",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 0.056  pb^{-1}"); // 60
       qw->AddEntry(histo0_Data,        "HLT_JET60",           "p"); 
      }
      else if (ptval=="80") {
       qw->SetHeader("2011 effective lumi : 0.305  pb^{-1}"); // 80
       qw->AddEntry(histo0_Data,        "HLT_JET80",           "p"); 
      }
      else if (ptval=="110") {
       qw->SetHeader("2011 effective lumi : 1.63  pb^{-1}"); // 110
       qw->AddEntry(histo0_Data,        "HLT_JET110",           "p"); 
      }

   }
   else  { 
      if (ptval=="20") {
       qw->SetHeader("2011 effective lumi : 1.62  pb^{-1}"); // 20
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet20_Mu5",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 15.38  pb^{-1}"); // 60
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet60_Mu7",           "p"); 
      }
      else if (ptval=="40") { 
       qw->SetHeader("2011 effective lumi : 3.12  pb^{-1}"); // 40
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet40_Mu5",           "p"); 
      }
      else if (ptval=="70") { 
       qw->SetHeader("2011 effective lumi : 15.38  pb^{-1}"); // 70
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet70_Mu5",           "p"); 
      }
      else if (ptval=="110") { 
       qw->SetHeader("2011 effective lumi : 89.8  pb^{-1}"); // 110
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet110_Mu5",           "p"); 
      }
   }

  }
  }
  if (selection!="npv" && selection!="npv_no_scaled" && selection!="npu") {
    qw->AddEntry(histo0_MC_b,        "QCD (b quark) "           ,"f");
    qw->AddEntry(histo0_MC_gspl,     "QCD (b from gspl) "     ,"f");
    qw->AddEntry(histo0_MC_c,        "QCD (c quark) "           ,"f");
    qw->AddEntry(histo0_MC_udsg,     "QCD (uds quark & g) "     ,"f");
  }
  else {
  qw->AddEntry(histo0_MC,     "QCD "     ,"f");
  }
 
  qw->SetFillColor(0);
  qw->Draw();


  canvas->cd();


  // SECOND DATA/MC RATIO
//  TPad *canvas_2 = new TPad("canvas_2", "canvas_2",0,0.12,1.0,0.32);
  TPad *canvas_2 = new TPad("canvas_2", "canvas_2",0,0.,1.0,0.32);
  canvas_2->Draw();
  canvas_2->cd();
  gPad->SetBottomMargin(0.375);
  gPad->SetGridy();
  gPad->SetGridx();
  histo0_ratio->SetMarkerStyle(20);
  histo0_ratio->SetMarkerSize(0.75);
  histo0_ratio->SetLineWidth(2);
  histo0_ratio->GetYaxis()->SetTitle("Data/MC");
  histo0_ratio->GetXaxis()->SetTitle(histo0_Data->GetName());  

  histo0_ratio->GetYaxis()->SetTitleOffset( 0.4 );
  histo0_ratio->GetYaxis()->SetTitleSize( 0.1 );
  histo0_ratio->GetYaxis()->SetLabelSize(0.1);
  histo0_ratio->GetYaxis()->SetNdivisions( 505 );
  histo0_ratio->GetXaxis()->SetLabelSize(0.1);
  histo0_ratio->GetXaxis()->SetTitleSize( 0.15 );

  histo0_ratio->SetMinimum(0.4);
  histo0_ratio->SetMaximum(1.6);
  histo0_ratio->Draw("E1X0");

   canvas->cd();


/*
  // THIRD 2011/2010 RATIO, only for jet dataset
  TPad *canvas_3 = new TPad("canvas_3", "canvas_3",0,0.,1.0,0.20);
  if (mu==false && selection!="npv") {
  canvas_3->Draw();
  canvas_3->cd();
  gPad->SetBottomMargin(0.375);
  gPad->SetGridy();
  gPad->SetGridx();
  histo0_ratdata->SetTitle();
  histo0_ratdata->SetMinimum(0.4);
  histo0_ratdata->SetMaximum(1.6);
  histo0_ratdata->GetYaxis()->SetTitle("2011/2010");
  histo0_ratdata->GetXaxis()->SetTitle(histo0_Data->GetName());  

  histo0_ratdata->GetYaxis()->SetTitleOffset( 0.4 );
  histo0_ratdata->GetYaxis()->SetTitleSize( 0.1 );
  histo0_ratdata->GetYaxis()->SetLabelSize(0.1);
  histo0_ratdata->GetYaxis()->SetNdivisions( 505 );
  histo0_ratdata->GetXaxis()->SetLabelSize(0.1);
  histo0_ratdata->GetXaxis()->SetTitleSize( 0.1 );

  histo0_ratdata->SetMarkerStyle(20);
  histo0_ratdata->SetMarkerColor(6);
  histo0_ratdata->SetLineWidth(2);
  histo0_ratdata->SetLineColor(6);
  histo0_ratdata->SetMarkerSize(0.75);
  histo0_ratdata->Draw("E1X0");
  }
*/

   canvas->cd();

  // SAVE PNG FILES
  string name_can=selection+"_Linear.png";
  canvas->SaveAs(name_can.c_str());

  if (logy==1) {
   canvas_1->SetLogy(logy);
   string name_can2=selection+"_Log.png";
   canvas->SaveAs(name_can2.c_str());
  }



  for (int i=0; i<nameroot.size(); i++){
    if (i<maxmax) {
     mc[i]->Close(); 
    }
  }
  data->Close();
  data2->Close();


  


}

TagRate(TString selection, bool down=false, bool logy=false, bool mu=false){
  
 
  const int maxmax=10;
  TFile * mc[maxmax];


////// IMPORTANT : DEFINE HERE THE DIRECTORY WHERE THE FILES ARE : "dir"
  string ptval;
  string dir;
   if (mu==false) {
     ptval=ptval_jet;
     dir ="dir_jet"+ptval+"/";
   }
   else {
     ptval=ptval_btag;
     dir ="dir_btag"+ptval+"/";
   }
  cout << dir << endl;

  vector<string> nameroot;
  if (mu==false) {

// PUT HERE THE NAME OF QCD ROOTFILES
  if (ptval!="60" && ptval!="80" && ptval!="110") nameroot.push_back(dir+"histo_qcd15.root");
  nameroot.push_back(dir+"histo_qcd30.root");
  nameroot.push_back(dir+"histo_qcd50.root");
  nameroot.push_back(dir+"histo_qcd80.root");
  nameroot.push_back(dir+"histo_qcd120.root");
  nameroot.push_back(dir+"histo_qcd170.root");
  nameroot.push_back(dir+"histo_qcd300.root");
  }
  else {
// PUT HERE THE NAME OF QCD (MU ENRICHED) ROOTFILES
  nameroot.push_back(dir+"histo_qcdmu15.root");
  nameroot.push_back(dir+"histo_qcdmu20.root");
  nameroot.push_back(dir+"histo_qcdmu30.root");
  nameroot.push_back(dir+"histo_qcdmu50.root");
  nameroot.push_back(dir+"histo_qcdmu80.root");
  nameroot.push_back(dir+"histo_qcdmu120.root");
  nameroot.push_back(dir+"histo_qcdmu150.root");
  }


  for (int i=0; i<nameroot.size(); i++){
    if (i<maxmax) {
     mc[i] = new TFile(nameroot[i].c_str());
//     cout << " root " << nameroot[i].c_str() << endl;
    }
  }


  string dataroot;
  if (mu==false) {dataroot=dir+"histo_minijet2011.root"; }
  else           {dataroot=dir+"histo_minibtag2011.root"; }
  TFile * data   = new TFile(dataroot.c_str());


  TH1F * histo0_Data;
  TH1F * histo0_Data2;
  TH1F * histo0_MC;
  TH1F * histo0_2MC;
  TH1F * histo0_MC_b;
  TH1F * histo0_MC_c;
  TH1F * histo0_MC_udsg;
  TH1F * histo0_MC_gspl;

  TH1F* histo_MC[maxmax];
  TH1F* histo_2MC[maxmax];
  TH1F* histo_MC_b[maxmax];
  TH1F* histo_MC_c[maxmax];
  TH1F* histo_MC_udsg[maxmax];
  TH1F* histo_MC_gspl[maxmax];

  TH1F * histo0_ratio;

  
  //###################################################
  //###################################################
  
  
  histo0_Data = (TH1F*)data->Get(selection);
  TString selection2;
  if (selection=="discri_ssche") {
    selection2 = "discri_ssche0";
  } 
  else if (selection=="discri_sschp")  {
    selection2 = "discri_sschp0";
  } 
  else {
    // WE DON'T CARE THIS CASE!
    selection2 = "sv_nvertices";
  }
  histo0_Data2 = (TH1F*)data->Get(selection2);

  int nbinx=histo0_Data->GetNbinsX();
  float minx=histo0_Data->GetXaxis()->GetXmin();
  float maxx=histo0_Data->GetXaxis()->GetXmax();
  TH1F * TagRate_Data = new TH1F ("TagRate_Data","",nbinx,minx,maxx);
  TH1F * TagRate_MC   = new TH1F ("TagRate_MC","",nbinx,minx,maxx);
  TH1F * TagRate_MC_b = new TH1F ("TagRate_MC_b","",nbinx,minx,maxx);
  TH1F * TagRate_MC_c = new TH1F ("TagRate_MC_c","",nbinx,minx,maxx);
  TH1F * TagRate_MC_udsg = new TH1F ("TagRate_MC_udsg","",nbinx,minx,maxx);
  TH1F * TagRate_MC_gspl = new TH1F ("TagRate_MC_gspl","",nbinx,minx,maxx);

  TString bsel = selection+"_b";
  TString csel = selection+"_c";
  TString lsel = selection+"_udsg"; 
  TString gsel = selection+"_gspl";
  if (selection=="npv" || selection=="pthat" || selection=="npv_no_scaled" || selection=="npu") {
   // IF selection=="npv" or selection=="pthat", no _b info
   // PUT DUMMY NAMES TO AVOID CRASH...
   bsel = "sv_jetpt_b";
   csel = "sv_jetpt_b";
   lsel = "sv_jetpt_b";
   gsel = "sv_jetpt_b";
  }
  for (int i=0; i<nameroot.size(); i++){
   histo_MC[i]     =(TH1F*)mc[i]->Get(selection);
   histo_2MC[i]     =(TH1F*)mc[i]->Get(selection2);
   histo_MC_b[i]   =(TH1F*)mc[i]->Get(bsel);
   histo_MC_c[i]   =(TH1F*)mc[i]->Get(csel);
   histo_MC_udsg[i]=(TH1F*)mc[i]->Get(lsel);
   histo_MC_gspl[i]=(TH1F*)mc[i]->Get(gsel);
  
//   if (selection=="npv") cout <<  " somme MC :      i = " << i  << endl;
 
   if (i==0) {
    histo0_MC=      (TH1F*)mc[i]->Get(selection);
    histo0_2MC=      (TH1F*)mc[i]->Get(selection2);
    histo0_MC_b=    (TH1F*)mc[i]->Get(bsel);
    histo0_MC_c=    (TH1F*)mc[i]->Get(csel);
    histo0_MC_udsg= (TH1F*)mc[i]->Get(lsel);
    histo0_MC_gspl= (TH1F*)mc[i]->Get(gsel);
   }
   else {
    histo0_MC->Add(histo_MC[i]);
    histo0_2MC->Add(histo_2MC[i]);
    histo0_MC_b->Add(histo_MC_b[i]);
    histo0_MC_c->Add(histo_MC_c[i]);
    histo0_MC_udsg->Add(histo_MC_udsg[i]);
    histo0_MC_gspl->Add(histo_MC_gspl[i]);
   }
  }


  // MAKE TAG RATE
  int nbin_max=histo0_Data->GetNbinsX();
  for (int ii=0; ii<nbin_max; ii++) {
      float totdata=histo0_Data->Integral(0,nbin_max+1);
      float totmc=histo0_MC->Integral(0,nbin_max+1);
      if (selection=="discri_ssche"||selection=="discri_sschp") {
        totdata=histo0_Data2->Integral(0,nbin_max+1);
        totmc=histo0_2MC->Integral(0,nbin_max+1);
      }
      float val = histo0_Data->Integral(ii+1,nbin_max+1) / totdata;
      float err = sqrt(totdata *val*(1-val))/ totdata;
      TagRate_Data->SetBinContent(ii+1, val);
      TagRate_Data->SetBinError(ii+1, err);
      TagRate_MC->SetBinContent(ii+1,   histo0_MC->Integral(ii+1,nbin_max+1) / totmc);
      TagRate_MC_b->SetBinContent(ii+1, histo0_MC_b->Integral(ii+1,nbin_max+1) / totmc);
      TagRate_MC_c->SetBinContent(ii+1, histo0_MC_c->Integral(ii+1,nbin_max+1) / totmc);
      TagRate_MC_udsg->SetBinContent(ii+1, histo0_MC_udsg->Integral(ii+1,nbin_max+1) / totmc);
      TagRate_MC_gspl->SetBinContent(ii+1, histo0_MC_gspl->Integral(ii+1,nbin_max+1) / totmc);
  }

  // MAKE DATA/MC RATIO
  histo0_ratio = (TH1F*) TagRate_Data->Clone();
  histo0_ratio->SetName("histo0_ratio");
  histo0_ratio->SetTitle("");
  histo0_ratio->Divide(TagRate_MC);


  // SET COLORS
  TagRate_MC->SetLineColor(2);
  TagRate_MC_b->SetFillColor(2);
  TagRate_MC_c->SetFillColor(8);
  TagRate_MC_gspl->SetFillColor(7);
  TagRate_MC_udsg->SetFillColor(4);

  // DO STACK
  THStack* hs= new THStack();
  if (down==false) {
    hs->Add(TagRate_MC_udsg);
    hs->Add(TagRate_MC_c);
    hs->Add(TagRate_MC_gspl); 
    hs->Add(TagRate_MC_b);
  }
  else {
    hs->Add(TagRate_MC_b);
    hs->Add(TagRate_MC_gspl);  
    hs->Add(TagRate_MC_c);
    hs->Add(TagRate_MC_udsg);
  }
  

  // SET COSMETICS
  TagRate_Data->SetMarkerStyle(20);
  TagRate_Data->SetMarkerSize(0.75);
  TagRate_Data->GetXaxis()->SetTitle(histo0_MC->GetName());  

  TString titlenam="Tag Rate for " + selection;
  hs->SetTitle(titlenam);

  // CREATE CANVAS
  TCanvas *canvas = new TCanvas("c1", "c1",10,32,782,552);
  canvas->cd();

  // FIRST MC & DATA
/*
  TPad *canvas_1 = new TPad("canvas_1", "canvas_1",0,0.25,1.0,0.98);
  canvas_1->Draw();
  canvas_1->cd();
*/


  if (TagRate_Data->GetMaximum() > hs->GetMaximum() ) {
    hs->SetMaximum(TagRate_Data->GetMaximum() );
  }
  hs->Draw("hist");
  TagRate_Data->Draw("e same");

  // ADD LEGEND
  TLegend* qw = 0;
  if (mu==false) {
    if (selection=="sv_eratio") {
     qw = new TLegend(0.5,0.73,0.8,1.);
    }
    else if (selection=="IP3d1" || selection=="IP3d1sorted" || selection=="trackIP3d" || selection=="trackIP3d_cutsel") {
     qw = new TLegend(0.12,0.63,0.42,0.9);
    }
    else {
     qw = new TLegend(0.6,0.73,0.95,1.);
    }
  } 
  else {
    if (selection=="sv_eratio") {
     qw = new TLegend(0.12,0.63,0.42,0.9);
    }
    else if (selection=="IP3d1" || selection=="IP3d1sorted" || selection=="IP3d1sig" || selection=="IP3d1sigsorted" || selection=="sv_ipsigcharm" ||
 	selection=="IP3d2" || selection=="IP3d2sorted" || selection=="IP3d2sig" || selection=="IP3d2sigsorted" || 
 	selection=="IP3d3" || selection=="IP3d3sorted" || selection=="IP3d3sig" || selection=="IP3d3sigsorted" 
	) {
     qw = new TLegend(0.12,0.63,0.42,0.9);
    }
    else {
     qw = new TLegend(0.6,0.73,0.95,1.);
    }
  }

  if (selection!="pthat" && selection!="npu") {
  if (date==2010) {
     qw->SetHeader("CMS Preliminary, 33 pb^{-1}");
     qw->AddEntry(TagRate_Data,        "JET Run2010B ",           "p");
  }
  else if (date==2011) {
   if (mu==false) {
      if (ptval=="30") {
       qw->SetHeader("2011 effective lumi : 0.0031  pb^{-1}"); // 30
       qw->AddEntry(TagRate_Data,        "HLT_JET30",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 0.056  pb^{-1}"); // 60
       qw->AddEntry(TagRate_Data,        "HLT_JET60",           "p"); 
      }
      else if (ptval=="80") {
       qw->SetHeader("2011 effective lumi : 0.305  pb^{-1}"); // 80
       qw->AddEntry(TagRate_Data,        "HLT_JET80",           "p"); 
      }
      else if (ptval=="110") {
       qw->SetHeader("2011 effective lumi : 1.63  pb^{-1}"); // 110
       qw->AddEntry(TagRate_Data,        "HLT_JET110",           "p"); 
      }

   }
   else  { 
      if (ptval=="20") {
       qw->SetHeader("2011 effective lumi : 1.62  pb^{-1}"); // 20
       qw->AddEntry(TagRate_Data,        "HLT_BTagMu_DiJet20_Mu5",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 15.38  pb^{-1}"); // 60
       qw->AddEntry(TagRate_Data,        "HLT_BTagMu_DiJet60_Mu7",           "p"); 
      }
      else if (ptval=="40") { 
       qw->SetHeader("2011 effective lumi : 3.12  pb^{-1}"); // 40
       qw->AddEntry(TagRate_Data,        "HLT_BTagMu_DiJet40_Mu5",           "p"); 
      }
      else if (ptval=="70") { 
       qw->SetHeader("2011 effective lumi : 15.38  pb^{-1}"); // 70
       qw->AddEntry(TagRate_Data,        "HLT_BTagMu_DiJet70_Mu5",           "p"); 
      }
      else if (ptval=="110") { 
       qw->SetHeader("2011 effective lumi : 89.8  pb^{-1}"); // 110
       qw->AddEntry(TagRate_Data,        "HLT_BTagMu_DiJet110_Mu5",           "p"); 
      }
   }

  }
  }
    qw->AddEntry(TagRate_MC_b,        "QCD (b quark) "           ,"f");
    qw->AddEntry(TagRate_MC_gspl,     "QCD (b from gspl) "     ,"f");
    qw->AddEntry(TagRate_MC_c,        "QCD (c quark) "           ,"f");
    qw->AddEntry(TagRate_MC_udsg,     "QCD (uds quark & g) "     ,"f");
 
  qw->SetFillColor(0);
  qw->Draw();


  canvas->cd();


/*
  // SECOND DATA/MC RATIO
//  TPad *canvas_2 = new TPad("canvas_2", "canvas_2",0,0.12,1.0,0.32);
  TPad *canvas_2 = new TPad("canvas_2", "canvas_2",0,0.,1.0,0.32);
  canvas_2->Draw();
  canvas_2->cd();
  gPad->SetBottomMargin(0.375);
  gPad->SetGridy();
  gPad->SetGridx();
  histo0_ratio->SetMarkerStyle(20);
  histo0_ratio->SetMarkerSize(0.75);
  histo0_ratio->SetLineWidth(2);
  histo0_ratio->GetYaxis()->SetTitle("Data/MC");
  histo0_ratio->GetXaxis()->SetTitle(histo0_Data->GetName());  

  histo0_ratio->GetYaxis()->SetTitleOffset( 0.4 );
  histo0_ratio->GetYaxis()->SetTitleSize( 0.1 );
  histo0_ratio->GetYaxis()->SetLabelSize(0.1);
  histo0_ratio->GetYaxis()->SetNdivisions( 505 );
  histo0_ratio->GetXaxis()->SetLabelSize(0.1);
  histo0_ratio->GetXaxis()->SetTitleSize( 0.15 );

  histo0_ratio->SetMinimum(0.4);
  histo0_ratio->SetMaximum(1.6);
  histo0_ratio->Draw("E1X0");

   canvas->cd();

*/

  // SAVE PNG FILES
  string name_can="tagRate_"+selection+"_Linear.png";
  canvas->SaveAs(name_can.c_str());

  if (logy==1) {
//   canvas_1->SetLogy(logy);
   canvas->SetLogy(logy);
   string name_can2="tagRate_"+selection+"_Log.png";
   canvas->SaveAs(name_can2.c_str());
  }



  for (int i=0; i<nameroot.size(); i++){
    if (i<maxmax) {
     mc[i]->Close(); 
    }
  }
  data->Close();


  


}


/////////////////////////////////////////////////////////////////
// Author : Caroline Collard (IPHC) 
////////////////////////////////////////////////////////////////

#include <vector>

PlotData(TString selection, int date, bool down=false, bool logy=false, bool mu=false){
  
 
  const int maxmax=10;
  TFile * mc[maxmax];


////// IMPORTANT : DEFINE HERE THE DIRECTORY WHERE THE FILES ARE : "dir"
  string ptval;
  string dir;
   if (mu==false) {
     ptval=ptval_jet;
     dir ="dir_jet"+ptval+"/";
   }
   else {
     ptval=ptval_btag;
     dir ="dir_btag"+ptval+"/";
   }
  cout << dir << endl;

  vector<string> nameroot;
  if (mu==false) {

// PUT HERE THE NAME OF QCD ROOTFILES
  if (ptval!="80" && ptval!="110") nameroot.push_back(dir+"histo_qcd15.root");
  nameroot.push_back(dir+"histo_qcd30.root");
  nameroot.push_back(dir+"histo_qcd50.root");
  nameroot.push_back(dir+"histo_qcd80.root");
  nameroot.push_back(dir+"histo_qcd120.root");
  nameroot.push_back(dir+"histo_qcd170.root");
  nameroot.push_back(dir+"histo_qcd300.root");
  }
  else {
// PUT HERE THE NAME OF QCD (MU ENRICHED) ROOTFILES
  nameroot.push_back(dir+"histo_qcdmu15.root");
  nameroot.push_back(dir+"histo_qcdmu20.root");
  nameroot.push_back(dir+"histo_qcdmu30.root");
  nameroot.push_back(dir+"histo_qcdmu50.root");
  nameroot.push_back(dir+"histo_qcdmu80.root");
  nameroot.push_back(dir+"histo_qcdmu120.root");
  nameroot.push_back(dir+"histo_qcdmu150.root");
  }


  for (int i=0; i<nameroot.size(); i++){
    if (i<maxmax) {
     mc[i] = new TFile(nameroot[i].c_str());
//     cout << " root " << nameroot[i].c_str() << endl;
    }
  }


  string dataroot;
  string dataroot2;
    if (mu==false) {dataroot=dir+"histo_minijet2011.root"; }
    else           {dataroot=dir+"histo_minibtag2011.root"; }
  TFile * data   = new TFile(dataroot.c_str());



  TH1F * histo0_Data1;
  TH1F * histo0_Data2;
  TH1F * histo0_Data3;

  TH1F * histo0_ratio;
  TH1F * histo0_ratio2;

  
  //###################################################
  //###################################################
  
  TString npv1;
  TString npv2;
  TString npv3;
  npv1 = "npv1_"+selection;
  npv2 = "npv2_"+selection;
  npv3 = "npv3_"+selection;
  
  histo0_Data1 = (TH1F*)data->Get(npv1);
  histo0_Data2 = (TH1F*)data->Get(npv2);
  histo0_Data3 = (TH1F*)data->Get(npv3);

  // SCALE MC TO DATA
  float scaleparam=1.;
  float scaleparam2=1.;
/*
  if (selection=="pt_tracks" || selection=="pt_seltracks" || selection=="pt_cutseltracks" ) {
     int nbinx_data = histo0_Data2->GetNbinsX();
     scaleparam=histo0_Data2->Integral(2,nbinx_data)/histo0_Data1->Integral(2,nbinx_data);
     scaleparam2=histo0_Data2->Integral(2,nbinx_data)/histo0_Data3->Integral(2,nbinx_data);
  }
  else {  
     scaleparam=histo0_Data2->Integral()/histo0_Data1->Integral();
     scaleparam2=histo0_Data2->Integral()/histo0_Data3->Integral();
  }
*/
     scaleparam=histo0_Data2->Integral()/histo0_Data1->Integral();
     scaleparam2=histo0_Data2->Integral()/histo0_Data3->Integral();

  histo0_Data1->Scale(scaleparam);
  histo0_Data3->Scale(scaleparam2);


  // MAKE DATA/MC RATIO
  histo0_ratio = (TH1F*) histo0_Data2->Clone();
  histo0_ratio->SetName("histo0_ratio");
  histo0_ratio->SetTitle("");
  histo0_ratio->Divide(histo0_Data1);

  histo0_ratio2 = (TH1F*) histo0_Data2->Clone();
  histo0_ratio2->SetName("histo0_ratio2");
  histo0_ratio2->SetTitle("");
  histo0_ratio2->Divide(histo0_Data3);

  // SET COSMETICS
  histo0_Data1->SetMarkerStyle(21);
  histo0_Data1->SetLineColor(2);
  histo0_Data1->SetMarkerColor(2);
  histo0_Data1->SetMarkerSize(0.75);
  histo0_Data2->SetMarkerStyle(20);
  histo0_Data2->SetMarkerSize(0.75);
  histo0_Data3->SetMarkerStyle(22);
  histo0_Data3->SetLineColor(8);
  histo0_Data3->SetMarkerColor(8);
  histo0_Data3->SetMarkerSize(0.75);

  // CREATE CANVAS
  TCanvas *canvas = new TCanvas("c1", "c1",10,32,782,552);
  canvas->cd();

  // FIRST MC & DATA
  TPad *canvas_1 = new TPad("canvas_1", "canvas_1",0,0.25,1.0,0.98);
  canvas_1->Draw();
  canvas_1->cd();


  if (histo0_Data1->GetMaximum() > histo0_Data2->GetMaximum()) histo0_Data2->SetMaximum(histo0_Data1->GetMaximum() *1.1);
  if (histo0_Data3->GetMaximum() > histo0_Data2->GetMaximum()) histo0_Data2->SetMaximum(histo0_Data3->GetMaximum() *1.1);
  histo0_Data2->Draw("e");
  histo0_Data1->Draw("e same");
  histo0_Data3->Draw("e same");

  // ADD LEGEND
  TLegend* qw = 0;
  if (mu==false) {
    if (selection=="eratio") {
     qw = new TLegend(0.5,0.60,0.85,1.);
    }
    else {
     qw = new TLegend(0.65,0.60,0.95,1.);
    }
  } 
  else {
    if (selection=="eratio") {
     qw = new TLegend(0.12,0.60,0.47,0.90);
    }
    else if (selection=="IP3d1" || selection=="IP3d1sorted") {
     qw = new TLegend(0.12,0.60,0.47,1.);
    }
    else {
     qw = new TLegend(0.65,0.60,0.95,1.);
    }
  }

  
   if (mu==false) {
      if (ptval=="30") {
       qw->SetHeader("2011 JET30 L=0.0031 pb^{-1}"); // 30
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 JET60 L=0.056 pb^{-1}"); // 60
      }
      else if (ptval=="80") {
       qw->SetHeader("2011 JET80 L=0.305 pb^{-1}"); // 80
      }
      else if (ptval=="110") {
       qw->SetHeader("2011 JET110 L=1.63 pb^{-1}"); // 110
      }
   }
   else  { 
      if (ptval=="20") {
       qw->SetHeader("2011 BTagMu_DiJet20_Mu5 L=1.62 pb^{-1}"); // 20
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 BTagMu_DiJet60_Mu7 L=15.38 pb^{-1}"); // 60
      }
      else if (ptval=="40") { 
       qw->SetHeader("2011 BTagMu_DiJet40_Mu5 L=3.12 pb^{-1}"); // 60
      }
      else if (ptval=="70") { 
       qw->SetHeader("2011 BTagMu_DiJet70_Mu5 L=15.38 pb^{-1}"); // 60
      }
      else if (ptval=="110") { 
       qw->SetHeader("2011 BTagMu_DiJet110_Mu5 L=89.8 pb^{-1}"); // 60
      }
   }
       qw->AddEntry(histo0_Data1,        "#PV: 1-3",           "p"); 
       qw->AddEntry(histo0_Data2,        "#PV: 4-7",           "p"); 
       qw->AddEntry(histo0_Data3,        "#PV: >7",           "p"); 

 
  qw->SetFillColor(0);
  qw->Draw();


  canvas->cd();


  // SECOND DATA/MC RATIO
  TPad *canvas_2 = new TPad("canvas_2", "canvas_2",0,0.,1.0,0.32);
  canvas_2->Draw();
  canvas_2->cd();
  gPad->SetBottomMargin(0.375);
  gPad->SetGridy();
  gPad->SetGridx();
  histo0_ratio->SetMarkerStyle(20);
  histo0_ratio->SetMarkerSize(0.75);
  histo0_ratio->SetLineWidth(2);
  histo0_ratio->GetYaxis()->SetTitle("#PV 4-7/#PV 1-3");
  histo0_ratio->GetXaxis()->SetTitle(histo0_Data2->GetName());  

  histo0_ratio->GetYaxis()->SetTitleOffset( 0.4 );
  histo0_ratio->GetYaxis()->SetTitleSize( 0.1 );
  histo0_ratio->GetYaxis()->SetLabelSize(0.1);
  histo0_ratio->GetYaxis()->SetNdivisions( 505 );
  histo0_ratio->GetXaxis()->SetLabelSize(0.1);
  histo0_ratio->GetXaxis()->SetTitleSize( 0.1 );

  histo0_ratio->SetMinimum(0.4);
  histo0_ratio->SetMaximum(1.6);
  histo0_ratio->Draw("E1X0");

   canvas->cd();


  // SAVE PNG FILES
  string name_can="npv_"+selection+"_Linear.png";
  canvas->SaveAs(name_can.c_str());

  if (logy==1) {
   canvas_1->SetLogy(logy);
   string name_can2="npv_"+selection+"_Log.png";
   canvas->SaveAs(name_can2.c_str());
  }

  data->Close();


}
/////////////////////////////////////////////////////////////////
// Author : Caroline Collard (IPHC) - first commit : april 2011
////////////////////////////////////////////////////////////////

#include <vector>

PlotStack2D(TString selection, bool logy=false, bool mu=false){
  
 
  const int maxmax=10;
  TFile * mc[maxmax];


////// IMPORTANT : DEFINE HERE THE DIRECTORY WHERE THE FILES ARE : "dir"
  string ptval;
  string dir;
   if (mu==false) {
     ptval=ptval_jet;
     dir ="dir_jet"+ptval+"/";
   }
   else {
     ptval=ptval_btag;
     dir ="dir_btag"+ptval+"/";
   }
  cout << dir << endl;

  vector<string> nameroot;
  if (mu==false) {

// PUT HERE THE NAME OF QCD ROOTFILES
  if (ptval!="60" && ptval!="80" && ptval!="110") nameroot.push_back(dir+"histo_qcd15.root");
  nameroot.push_back(dir+"histo_qcd30.root");
  nameroot.push_back(dir+"histo_qcd50.root");
  nameroot.push_back(dir+"histo_qcd80.root");
  nameroot.push_back(dir+"histo_qcd120.root");
  nameroot.push_back(dir+"histo_qcd170.root");
  nameroot.push_back(dir+"histo_qcd300.root");
  }
  else {
// PUT HERE THE NAME OF QCD (MU ENRICHED) ROOTFILES
  nameroot.push_back(dir+"histo_qcdmu15.root");
  nameroot.push_back(dir+"histo_qcdmu20.root");
  nameroot.push_back(dir+"histo_qcdmu30.root");
  nameroot.push_back(dir+"histo_qcdmu50.root");
  nameroot.push_back(dir+"histo_qcdmu80.root");
  nameroot.push_back(dir+"histo_qcdmu120.root");
  nameroot.push_back(dir+"histo_qcdmu150.root");
  }


  string dataroot;
  if (mu==false) {dataroot=dir+"histo_minijet2011.root"; }
  else           {dataroot=dir+"histo_minibtag2011.root"; }
  TFile * data   = new TFile(dataroot.c_str());
  histo0_Data = (TH2F*)data->Get(selection);
  TProfile * pro_data = histo0_Data->ProfileX();

  TH2F * histo0_Data;
  for (int i=0; i<nameroot.size(); i++){
    if (i<maxmax) {
     mc[i] = new TFile(nameroot[i].c_str());
//     cout << " root " << nameroot[i].c_str() << endl;
    }
  }


  TH2F * histo0_MC;
  TH2F * histo0_MC_b;
  TH2F * histo0_MC_c;
  TH2F * histo0_MC_udsg;
  TH2F * histo0_MC_gspl;

  TH2F* histo_MC[maxmax];
  TH2F* histo_MC_b[maxmax];
  TH2F* histo_MC_c[maxmax];
  TH2F* histo_MC_udsg[maxmax];
  TH2F* histo_MC_gspl[maxmax];

  
  //###################################################
  //###################################################
  
  

  TString bsel = selection+"_b";
  TString csel = selection+"_c";
  TString lsel = selection+"_udsg"; 
  TString gsel = selection+"_gspl";
  for (int i=0; i<nameroot.size(); i++){
   histo_MC[i]     =(TH2F*)mc[i]->Get(selection);
   histo_MC_b[i]   =(TH2F*)mc[i]->Get(bsel);
   histo_MC_c[i]   =(TH2F*)mc[i]->Get(csel);
   histo_MC_udsg[i]=(TH2F*)mc[i]->Get(lsel);
   histo_MC_gspl[i]=(TH2F*)mc[i]->Get(gsel);
  
 
   if (i==0) {
    histo0_MC=      (TH2F*)mc[i]->Get(selection);
    histo0_MC_b=    (TH2F*)mc[i]->Get(bsel);
    histo0_MC_c=    (TH2F*)mc[i]->Get(csel);
    histo0_MC_udsg= (TH2F*)mc[i]->Get(lsel);
    histo0_MC_gspl= (TH2F*)mc[i]->Get(gsel);
   }
   else {
    histo0_MC->Add(histo_MC[i]);
    histo0_MC_b->Add(histo_MC_b[i]);
    histo0_MC_c->Add(histo_MC_c[i]);
    histo0_MC_udsg->Add(histo_MC_udsg[i]);
    histo0_MC_gspl->Add(histo_MC_gspl[i]);
   }
  }


  // SCALE MC TO DATA
  float scaleparam=histo0_Data->Integral()/histo0_MC->Integral();
  histo0_MC_b->Scale(scaleparam);
  histo0_MC_c->Scale(scaleparam);
  histo0_MC_udsg->Scale(scaleparam);
  histo0_MC_gspl->Scale(scaleparam);
  histo0_MC->Scale(scaleparam);


  TProfile * pro_mc = histo0_MC->ProfileX();
  TProfile * pro_mc_b = histo0_MC_b->ProfileX();
  TProfile * pro_mc_c = histo0_MC_c->ProfileX();
  TProfile * pro_mc_udsg = histo0_MC_udsg->ProfileX();
  TProfile * pro_mc_gspl = histo0_MC_gspl->ProfileX();


  // SET COLORS
  pro_mc->SetLineColor(1);
  pro_mc_b->SetLineColor(2);
  pro_mc_c->SetLineColor(8);
  pro_mc_udsg->SetLineColor(4);
  pro_mc_gspl->SetLineColor(7);

  // SET COSMETICS
  pro_data->SetMarkerStyle(20);
  pro_data->SetMarkerSize(0.75);
  pro_mc_gspl->GetXaxis()->SetTitle(histo0_MC->GetName());  


  // CREATE CANVAS
  TCanvas *canvas = new TCanvas("c1", "c1",10,32,782,552);
  canvas->cd();

   pro_mc_gspl->Draw("hist");
   pro_mc->Draw("hist,same");
   pro_mc_b->Draw("hist,same");
   pro_mc_c->Draw("hist,same");
   pro_mc_udsg->Draw("hist,same");
   pro_data->Draw("e,same");

  // ADD LEGEND
  TLegend* qw = 0;
  if (mu==false) {
     qw = new TLegend(0.6,0.20,0.95,0.45);
  } 
  else {
     qw = new TLegend(0.6,0.20,0.95,0.45);
  }

  if (mu==false) {
      if (ptval=="30") {
       qw->SetHeader("2011 effective lumi : 0.0031  pb^{-1}"); // 30
       qw->AddEntry(pro_data,        "HLT_JET30",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 0.056  pb^{-1}"); // 60
       qw->AddEntry(pro_data,        "HLT_JET60",           "p"); 
      }
      else if (ptval=="80") {
       qw->SetHeader("2011 effective lumi : 0.305  pb^{-1}"); // 80
       qw->AddEntry(pro_data,        "HLT_JET80",           "p"); 
      }
      else if (ptval=="110") {
       qw->SetHeader("2011 effective lumi : 1.63  pb^{-1}"); // 110
       qw->AddEntry(pro_data,        "HLT_JET110",           "p"); 
      }
  }
  else  { 
      if (ptval=="20") {
       qw->SetHeader("2011 effective lumi : 1.62  pb^{-1}"); // 20
       qw->AddEntry(pro_data,        "HLT_BTagMu_DiJet20_Mu5",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 15.38  pb^{-1}"); // 60
       qw->AddEntry(pro_data,        "HLT_BTagMu_DiJet60_Mu7",           "p"); 
      }
      else if (ptval=="40") { 
       qw->SetHeader("2011 effective lumi : 3.12  pb^{-1}"); // 40
       qw->AddEntry(pro_data,        "HLT_BTagMu_DiJet40_Mu5",           "p"); 
      }
      else if (ptval=="70") { 
       qw->SetHeader("2011 effective lumi : 15.38  pb^{-1}"); // 70
       qw->AddEntry(pro_data,        "HLT_BTagMu_DiJet70_Mu5",           "p"); 
      }
      else if (ptval=="110") { 
       qw->SetHeader("2011 effective lumi : 89.8  pb^{-1}"); // 110
       qw->AddEntry(pro_data,        "HLT_BTagMu_DiJet110_Mu5",           "p"); 
      }

 }

    qw->AddEntry(pro_mc,        "QCD (total) "           ,"l");
    qw->AddEntry(pro_mc_b,        "QCD (b quark) "           ,"l");
    qw->AddEntry(pro_mc_gspl,     "QCD (b from gspl) "     ,"l");
    qw->AddEntry(pro_mc_c,        "QCD (c quark) "           ,"l");
    qw->AddEntry(pro_mc_udsg,     "QCD (uds quark & g) "     ,"l");
 
  qw->SetFillColor(0);
  qw->Draw();


  canvas->cd();



  // SAVE PNG FILES
  string name_can=selection+"_Linear.png";
  canvas->SaveAs(name_can.c_str());

  if (logy==1) {
   canvas_1->SetLogy(logy);
   string name_can2=selection+"_Log.png";
   canvas->SaveAs(name_can2.c_str());
  }


/*
  for (int i=0; i<nameroot.size(); i++){
    if (i<maxmax) {
     mc[i]->Close(); 
    }
  }
  data->Close();
  data2->Close();
*/

  


}
