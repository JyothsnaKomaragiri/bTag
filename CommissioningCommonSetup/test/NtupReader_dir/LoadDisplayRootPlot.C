/////////////////////////////////////////////////////////////////
// Author : Caroline Collard (IPHC) - first commit : april 2011
////////////////////////////////////////////////////////////////

#include <vector>

PlotStack(TString selection, int date, bool down=false, bool logy=false, bool mu=false){
  
 
  const int maxmax=10;
  TFile * mc[maxmax];


////// IMPORTANT : DEFINE HERE THE DIRECTORY WHERE THE FILES ARE : "dir"
  string ptval;
  string dir;
   if (mu==false) {
     ptval="80";
     dir ="dir_jet"+ptval+"/";
   }
   else {
     ptval="60";
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
  if (selection=="npv" || selection=="pthat" || selection=="npv_no_scaled") {
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
    histo0_MC_b->Add(histo_MC_gspl[0]);
   }
   else {
    histo0_MC->Add(histo_MC[i]);
    histo0_MC_b->Add(histo_MC_b[i]);
    histo0_MC_b->Add(histo_MC_gspl[i]);
    histo0_MC_c->Add(histo_MC_c[i]);
    histo0_MC_udsg->Add(histo_MC_udsg[i]);
    histo0_MC_gspl->Add(histo_MC_gspl[i]);
   }
  }


  // SCALE MC TO DATA
  float scaleparam=histo0_Data->Integral()/histo0_MC->Integral();
  if (selection!="npv_no_scaled") {
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
/*
  if (selection=="sv_vtxdir_eta" || selection=="sv_vtxdir_phi" ) {
     histo0_ratio->Rebin(2);
     histo0_Data->Rebin(2);
     histo0_2010->Rebin(2);
     histo0_MC->Rebin(2);
     histo0_MC_b->Rebin(2);
     histo0_MC_c->Rebin(2);
     histo0_MC_udsg->Rebin(2);
     histo0_MC_gspl->Rebin(2);
   }
*/


  histo0_ratio->Divide(histo0_MC);

  if (selection=="npv_no_scaled"){
    for (int iii=1; iii<histo0_ratio->GetNbinsX(); iii++) {
       cout << iii-1 << " " << histo0_ratio->GetBinContent(iii) << endl;
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
//  hs->Add(histo0_MC_gspl);  // already in _b
    hs->Add(histo0_MC_c);
    hs->Add(histo0_MC_b);
  }
  else {
    hs->Add(histo0_MC_b);
    hs->Add(histo0_MC_c);
//  hs->Add(histo0_MC_gspl);  // already in _b
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

  if (selection=="sv_vtxsum_phi" || selection=="sv_vtxdir_phi") {
      hs->SetMaximum(hs->GetMaximum()*1.5);
      hs->SetMinimum(0.);
      histo0_Data->SetMinimum(0.);
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
    if (ptval=="110" && mu==true) hs->SetMaximum(hs->GetMaximum() *1.5 );
  }
  if (ptval=="110" && mu==true && selection=="sv_vtx_pt" ) hs->SetMaximum(hs->GetMaximum() *1.5 );
  if (selection!="npv" && selection!="npv_no_scaled") {
   hs->Draw("hist");
  }
  else {
   histo0_MC->Draw("hist");
  }
  if (selection!="pthat") histo0_Data->Draw("e same");

  // ADD LEGEND
  TLegend* qw = 0;
  if (mu==false) {
    if (selection=="sv_eratio") {
     qw = new TLegend(0.55,0.73,0.85,0.95);
    }
    else {
     qw = new TLegend(0.75,0.73,0.95,0.95);
    }
  } 
  else {
    if (selection=="sv_eratio") {
     qw = new TLegend(0.12,0.68,0.47,0.90);
    }
    else if (selection=="IP3d1" || selection=="IP3d10") {
     qw = new TLegend(0.12,0.68,0.47,0.90);
    }
    else {
     qw = new TLegend(0.70,0.73,0.95,0.95);
    }
  }

  
  if (date==2010) {
     qw->SetHeader("CMS Preliminary, 33 pb^{-1}");
     qw->AddEntry(histo0_Data,        "JET Run2010B ",           "p");
  }
  else if (date==2011) {
   if (mu==false) {
      if (ptval=="30") {
       qw->SetHeader("2011 effective lumi : 0.0022  pb^{-1}"); // 30
       qw->AddEntry(histo0_Data,        "HLT_JET30",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 0.040  pb^{-1}"); // 60
       qw->AddEntry(histo0_Data,        "HLT_JET60",           "p"); 
      }
      else if (ptval=="80") {
       qw->SetHeader("2011 effective lumi : 0.218  pb^{-1}"); // 80
       qw->AddEntry(histo0_Data,        "HLT_JET80",           "p"); 
      }
      else if (ptval=="110") {
       qw->SetHeader("2011 effective lumi : 1.157  pb^{-1}"); // 110
       qw->AddEntry(histo0_Data,        "HLT_JET110",           "p"); 
      }

   }
   else  { 
      if (ptval=="20") {
       qw->SetHeader("2011 effective lumi : 1.12  pb^{-1}"); // 20
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet20_Mu5",           "p"); 
      }
      else if (ptval=="60") { 
       qw->SetHeader("2011 effective lumi : 11.5  pb^{-1}"); // 60
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet60_Mu7",           "p"); 
      }
      else if (ptval=="40") { 
       qw->SetHeader("2011 effective lumi : 2.0  pb^{-1}"); // 40
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet40_Mu5",           "p"); 
      }
      else if (ptval=="70") { 
       qw->SetHeader("2011 effective lumi : 10.0  pb^{-1}"); // 70
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet70_Mu5",           "p"); 
      }
      else if (ptval=="110") { 
       qw->SetHeader("2011 effective lumi : 57.0  pb^{-1}"); // 110
       qw->AddEntry(histo0_Data,        "HLT_BTagMu_DiJet110_Mu5",           "p"); 
      }
   }

  }
  if (selection!="npv" && selection!="npv_no_scaled") {
    qw->AddEntry(histo0_MC_b,        "QCD (b quark) "           ,"f");
    qw->AddEntry(histo0_MC_c,        "QCD (c quark) "           ,"f");
    qw->AddEntry(histo0_MC_udsg,     "QCD (uds quark & g) "     ,"f");
//  qw->AddEntry(histo0_MC_gspl,     "QCD (g w splitting) "     ,"f");
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
  histo0_ratio->GetXaxis()->SetTitleSize( 0.1 );

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
