#include "TROOT.h"
#include "TObject.h"
#include "TFile.h"
#include "TProfile.h"
#include "THStack.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TTree.h"

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <utility>

struct information1d{
  std::string plotName;
  std::string label;
  std::string aliasx;
  std::string cut;
  double xlow;
  double xup;
  int nbinsx;
} ;

struct information2d{
  std::string plotName;
  std::string label;
  std::string aliasx;
  std::string aliasy;
  std::string cut;
  double xlow;
  double xup;
  int nbinsx;
  double ylow;
  double yup;
  int nbinsy;
};

struct flavorHists1D{
  TH1F* data_hist;
  TH1F* mc_all_hist;
  TH1F* mc_b_hist;
  TH1F* mc_c_hist;
  TH1F* mc_light_hist;
  TH1F* mc_none_hist;
};

struct qualityHists1D{
  TH1F* data_hist_undef;
  TH1F* data_hist_loose;
  TH1F* data_hist_tight;
  TH1F* data_hist_high_purity;
  TH1F* mc_hist_undef;
  TH1F* mc_hist_loose;
  TH1F* mc_hist_tight;
  TH1F* mc_hist_high_purity;
};

struct flavorHists2D{
  TH2F* data_hist;
  TH2F* mc_all_hist;
  TH2F* mc_b_hist;
  TH2F* mc_c_hist;
  TH2F* mc_light_hist;
  TH2F* mc_none_hist;
};

struct profileHists{
  TH2F* data_hist;
  TH2F* mc_all_hist;
  TH2F* mc_b_hist;
  TH2F* mc_c_hist;
  TH2F* mc_light_hist;
  TH2F* mc_none_hist;
  TProfile* data_prof;
  TProfile* mc_all_prof;
  TProfile* mc_b_prof;
  TProfile* mc_c_prof;
  TProfile* mc_light_prof;
  TProfile* mc_none_prof;
};

using namespace std;

information1d param1d(ifstream* plotFile)
{
  information1d thisPlot;
  bool plotName = false;
  bool label = false;
  bool aliasx = false;
  bool cut = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;

  while (! (plotName && label && aliasx && cut && xlow && xup && nbinsx)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    position = line.find("=");
    if(line.find("plotName")!=string::npos){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("label")!=string::npos){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")!=string::npos){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("cut")!=string::npos){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("xlow")!=string::npos){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")!=string::npos){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")!=string::npos){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
  }
  return thisPlot;
}

information2d param2d(ifstream* plotFile)
{
  information2d thisPlot;
  bool plotName = false;
  bool label = false;
  bool aliasx = false;
  bool aliasy = false;
  bool cut = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool ylow = false;
  bool yup = false;
  bool nbinsy = false;

  while (! (plotName && label && aliasx && aliasy && cut && xlow && xup && nbinsx && ylow && yup && nbinsy)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    position = line.find("=");
    if(line.find("plotName")!=string::npos){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("label")!=string::npos){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")!=string::npos){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("aliasy")!=string::npos){
      aliasy = true;
      thisPlot.aliasy = line.substr(position+1);
    }
    if(line.find("cut")!=string::npos){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("xlow")!=string::npos){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")!=string::npos){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")!=string::npos){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("ylow")!=string::npos){
      ylow = true;
      thisPlot.ylow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("yup")!=string::npos){
      yup = true;
      thisPlot.yup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsy")!=string::npos){
      nbinsy = true;
      thisPlot.nbinsy = atoi((line.substr(position+1)).c_str());
    }
  }
  return thisPlot;
}

void MakeAPlot(information1d info, flavorHists1D hists, double scale)
{
  hists.mc_all_hist->Add(hists.mc_b_hist);
  hists.mc_all_hist->Add(hists.mc_c_hist);
  hists.mc_all_hist->Add(hists.mc_light_hist);
  hists.mc_all_hist->Add(hists.mc_none_hist);
  hists.mc_all_hist->Write();
  hists.mc_b_hist->Write();
  hists.mc_c_hist->Write();
  hists.mc_light_hist->Write();
  hists.mc_none_hist->Write();
  hists.data_hist->Write();
  if(scale<=0)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    }      
  hists.mc_b_hist->Scale(scale);
  hists.mc_c_hist->Scale(scale);
  hists.mc_light_hist->Scale(scale);
  hists.mc_none_hist->Scale(scale);
  
  THStack mc_stack((info.plotName+"_mc_stack").c_str(),"Monte Carlo Stack");
  hists.mc_none_hist->SetFillColor(kMagenta);
  mc_stack.Add(hists.mc_none_hist);
  hists.mc_light_hist->SetFillColor(kBlue);
  mc_stack.Add(hists.mc_light_hist);
  hists.mc_c_hist->SetFillColor(kGreen);
  mc_stack.Add(hists.mc_c_hist);
  hists.mc_b_hist->SetFillColor(kRed);
  mc_stack.Add(hists.mc_b_hist);
  mc_stack.Write();
  
  //Make Canvas
  TCanvas canvas("canvas","Comparison of Monte Carlo Flavors",300,300);
  canvas.cd();
  mc_stack.Draw("HIST");
  hists.data_hist->Draw("E1SAME");
  canvas.SaveAs((info.plotName+".pdf").c_str());
  return;
}

void MakeA2DPlot(information2d info, flavorHists2D hists, double scale)
{
  hists.mc_all_hist->Add(hists.mc_b_hist);
  hists.mc_all_hist->Add(hists.mc_c_hist);
  hists.mc_all_hist->Add(hists.mc_light_hist);
  hists.mc_all_hist->Add(hists.mc_none_hist);
  hists.mc_all_hist->Write();
  hists.mc_b_hist->Write();
  hists.mc_c_hist->Write();
  hists.mc_light_hist->Write();
  hists.mc_none_hist->Write();
  hists.data_hist->Write();
  if(scale<=0)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    }   
  hists.mc_b_hist->Scale(scale);
  hists.mc_c_hist->Scale(scale);
  hists.mc_light_hist->Scale(scale);
  hists.mc_none_hist->Scale(scale);
  //Make Canvases
  TCanvas mc_comp("mc_comp","Comparison of Monte Carlo Flavors",800,600);
  TCanvas data_comp("data_comp","Comparison of Data and Monte Carlo",800,400);
  mc_comp.Divide(2,2);
  data_comp.Divide(2,1);
  mc_comp.cd(1);
  hists.mc_b_hist->Draw("colz");
  mc_comp.cd(2);
  hists.mc_c_hist->Draw("colz");
  mc_comp.cd(3);
  hists.mc_light_hist->Draw("colz");
  mc_comp.cd(4);
  hists.mc_none_hist->Draw("colz");

  data_comp.cd(1);
  hists.mc_all_hist->Draw("colz");
  data_comp.cd(2);
  hists.data_hist->Draw("colz");
  string mc_name = info.plotName+"_flavorComp.pdf";
  mc_comp.SaveAs(mc_name.c_str());
  string data_name = info.plotName+"_dataComp.pdf";
  data_comp.SaveAs(data_name.c_str());
  return;
}

void MakeATrackQualityPlot(information1d info, qualityHists1D hists, double scale)
{
  hists.mc_hist_undef->Write();
  hists.mc_hist_loose->Write();
  hists.mc_hist_tight->Write();
  hists.mc_hist_high_purity->Write();
  if(scale<=0)
    {
      //assume normalization to data
      scale = hists.data_hist_undef->Integral()/hists.mc_hist_undef->Integral();
    }   
  hists.mc_hist_undef->Scale(scale);
  hists.mc_hist_loose->Scale(scale);
  hists.mc_hist_tight->Scale(scale);
  hists.mc_hist_high_purity->Scale(scale);
  hists.mc_hist_undef->SetFillColor(kCyan);
  hists.mc_hist_loose->SetFillColor(kMagenta);
  hists.mc_hist_tight->SetFillColor(kBlue);
  hists.mc_hist_high_purity->SetFillColor(kRed);

  //Make Canvas
  TCanvas canvasOne("onePlot","Comparison of Monte Carlo Flavors",300,300);
  canvasOne.cd();
  hists.mc_hist_undef->Draw("HIST");
  hists.mc_hist_loose->Draw("HISTSAME");
  hists.mc_hist_tight->Draw("HISTSAME");
  hists.mc_hist_high_purity->Draw("HISTSAME");
  hists.data_hist_undef->Draw("E1SAME");
  hists.data_hist_loose->Draw("E1SAME");
  hists.data_hist_tight->Draw("E1SAME");
  hists.data_hist_high_purity->Draw("E1SAME");

  canvasOne.SaveAs((info.plotName+"_trackQualityOverlay.pdf").c_str());

  hists.data_hist_undef->SetFillColor(kCyan);
  hists.data_hist_loose->SetFillColor(kMagenta);
  hists.data_hist_tight->SetFillColor(kBlue);
  hists.data_hist_high_purity->SetFillColor(kRed);

  //Make Canvas
  TCanvas canvasTwo("twoPlots","Comparison of Monte Carlo Flavors",600,300);
  canvasTwo.Divide(2,1);
  canvasTwo.cd(1);
  hists.mc_hist_undef->Draw("HIST");
  hists.mc_hist_loose->Draw("HISTSAME");
  hists.mc_hist_tight->Draw("HISTSAME");
  hists.mc_hist_high_purity->Draw("HISTSAME");
  canvasTwo.cd(2);
  hists.data_hist_undef->Draw("HIST");
  hists.data_hist_loose->Draw("HISTSAME");
  hists.data_hist_tight->Draw("HISTSAME");
  hists.data_hist_high_purity->Draw("HISTSAME");
  canvasTwo.SaveAs((info.plotName+"_trackQuality.pdf").c_str());
  return;
}

void MakeAProfilePlot(information2d info, profileHists hists, double scale)
{
  //Turn 2D Plot into Integral Plot:
  string title="Data";
  TH2F data_int((info.plotName+"_data_int").c_str(),title.c_str(), info.nbinsx, info.xlow, info.xup, info.nbinsy, info.ylow, info.yup);
  data_int.Sumw2();
  data_int.GetXaxis()->SetTitle(info.aliasx.c_str());
  data_int.GetYaxis()->SetTitle(info.aliasy.c_str());
  title="Monte Carlo";
  TH2F mc_all_int((info.plotName+"_mc_all_int").c_str(),title.c_str(), info.nbinsx, info.xlow, info.xup, info.nbinsy, info.ylow, info.yup);
  mc_all_int.Sumw2();
  mc_all_int.GetXaxis()->SetTitle(info.aliasx.c_str());
  mc_all_int.GetYaxis()->SetTitle(info.aliasy.c_str());
  title="Monte Carlo (b quarks)";
  TH2F mc_b_int((info.plotName+"_mc_b_int").c_str(),title.c_str(), info.nbinsx, info.xlow, info.xup, info.nbinsy, info.ylow, info.yup);
  mc_b_int.Sumw2();
  mc_b_int.GetXaxis()->SetTitle(info.aliasx.c_str());
  mc_b_int.GetYaxis()->SetTitle(info.aliasy.c_str());
  title="Monte Carlo (c quarks)";
  TH2F mc_c_int((info.plotName+"_mc_c_int").c_str(),title.c_str(), info.nbinsx, info.xlow, info.xup, info.nbinsy, info.ylow, info.yup);
  mc_c_int.Sumw2();
  mc_c_int.GetXaxis()->SetTitle(info.aliasx.c_str());
  mc_c_int.GetYaxis()->SetTitle(info.aliasy.c_str());
  title="Monte Carlo (light partons)";
  TH2F mc_light_int((info.plotName+"_mc_light_int").c_str(),title.c_str(), info.nbinsx, info.xlow, info.xup, info.nbinsy, info.ylow, info.yup);
  mc_light_int.Sumw2();
  mc_light_int.GetXaxis()->SetTitle(info.aliasx.c_str());
  mc_light_int.GetYaxis()->SetTitle(info.aliasy.c_str());
  title="Monte Carlo (no truth match)";
  TH2F mc_none_int((info.plotName+"_mc_none_int").c_str(),title.c_str(), info.nbinsx, info.xlow, info.xup, info.nbinsy, info.ylow, info.yup);
  mc_none_int.Sumw2();
  mc_none_int.GetXaxis()->SetTitle(info.aliasx.c_str());
  mc_none_int.GetYaxis()->SetTitle(info.aliasy.c_str());

  for(int iXbin = 1; iXbin<=info.nbinsx; iXbin++){
    for(int iYbin = 1; iYbin<=info.nbinsy; iYbin++){
      data_int.SetBinContent(iXbin,iYbin,hists.data_hist->Integral(iXbin,iXbin,iYbin,info.nbinsy));
      mc_all_int.SetBinContent(iXbin,iYbin,hists.mc_all_hist->Integral(iXbin,iXbin,iYbin,info.nbinsy));
      mc_b_int.SetBinContent(iXbin,iYbin,hists.mc_b_hist->Integral(iXbin,iXbin,iYbin,info.nbinsy));
      mc_c_int.SetBinContent(iXbin,iYbin,hists.mc_c_hist->Integral(iXbin,iXbin,iYbin,info.nbinsy));
      mc_light_int.SetBinContent(iXbin,iYbin,hists.mc_light_hist->Integral(iXbin,iXbin,iYbin,info.nbinsy));
      mc_none_int.SetBinContent(iXbin,iYbin,hists.mc_none_hist->Integral(iXbin,iXbin,iYbin,info.nbinsy));
    }
  }
  if(scale<=0)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    }   
  hists.data_prof = data_int.ProfileY();
  hists.mc_all_prof = mc_all_int.ProfileY();
  hists.mc_b_prof = mc_b_int.ProfileY();
  hists.mc_c_prof = mc_c_int.ProfileY();
  hists.mc_light_prof = mc_light_int.ProfileY();
  hists.mc_none_prof = mc_none_int.ProfileY();

  mc_all_int.Scale(scale);
  mc_b_int.Scale(scale);
  mc_c_int.Scale(scale);
  mc_light_int.Scale(scale);
  mc_none_int.Scale(scale);

  //Make Canvas

  THStack mc_stack((info.plotName+"mc_stack").c_str(),"Monte Carlo Stack");
  hists.mc_none_prof->SetLineColor(kMagenta);
  hists.mc_none_prof->SetFillStyle(0);
  mc_stack.Add(hists.mc_none_prof);
  hists.mc_light_prof->SetLineColor(kBlue);
  hists.mc_light_prof->SetFillStyle(0);
  mc_stack.Add(hists.mc_light_prof);
  hists.mc_c_prof->SetLineColor(kGreen);
  hists.mc_c_prof->SetFillStyle(0);
  mc_stack.Add(hists.mc_c_prof);
  hists.mc_b_prof->SetLineColor(kRed);
  hists.mc_b_prof->SetFillStyle(0);
  mc_stack.Add(hists.mc_b_prof);
  hists.mc_all_prof->SetLineColor(kBlack);
  hists.mc_all_prof->SetFillStyle(0);
  mc_stack.Add(hists.mc_all_prof);

  //Make Canvas
  TCanvas canvas("canvas","Comparison of Monte Carlo Flavors",300,300);
  canvas.cd();
  mc_stack.Draw("HISTNOSTACK");
  hists.data_prof->Draw("E1SAME");
  canvas.SaveAs((info.plotName+"_profile.pdf").c_str());

  //Make Canvases
  TCanvas mc_comp("mc_comp","Comparison of Monte Carlo Flavors",800,600);
  TCanvas data_comp("data_comp","Comparison of Data and Monte Carlo",800,400);
  mc_comp.Divide(2,2);
  data_comp.Divide(2,1);
  mc_comp.cd(1);
  mc_b_int.Draw("colz");
  mc_comp.cd(2);
  mc_c_int.Draw("colz");
  mc_comp.cd(3);
  mc_light_int.Draw("colz");
  mc_comp.cd(4);
  mc_none_int.Draw("colz");

  data_comp.cd(1);
  mc_all_int.Draw("colz");
  data_comp.cd(2);
  data_int.Draw("colz");
  string mc_name = info.plotName+"_flavorComp.pdf";
  mc_comp.SaveAs(mc_name.c_str());
  string data_name = info.plotName+"_dataComp.pdf";
  data_comp.SaveAs(data_name.c_str());
  return;
}


void MakeATrackQualityHist(string type, TTree* thisTree, information1d info, qualityHists1D hists, string scale)
{
  string undefCut,looseCut,tightCut,highPurityCut;
  undefCut = "("+info.label+"trackQuality>=-1)";
  looseCut = "("+info.label+"trackQuality>=0)";
  tightCut = "("+info.label+"trackQuality>=1)";
  highPurityCut = "("+info.label+"trackQuality>=2)";

  if(info.cut!="")
    {
      undefCut = "("+info.cut+")&&"+undefCut;
      looseCut = "("+info.cut+")&&"+looseCut;
      tightCut = "("+info.cut+")&&"+tightCut;
      highPurityCut = "("+info.cut+")&&"+highPurityCut;
    }
  //Fill Histograms
  if(type == "data")
    {
      TH1F* temp_data_hist_undef = (TH1F*)hists.data_hist_undef->Clone((info.plotName+"_temp_data_hist_undef").c_str());
      TH1F* temp_data_hist_loose = (TH1F*)hists.data_hist_loose->Clone((info.plotName+"_temp_data_hist_loose").c_str());
      TH1F* temp_data_hist_tight = (TH1F*)hists.data_hist_tight->Clone((info.plotName+"_temp_data_hist_tight").c_str());
      TH1F* temp_data_hist_high_purity = (TH1F*)hists.data_hist_high_purity->Clone((info.plotName+"_temp_data_hist_high_purity").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_data_hist_undef").c_str(),(scale+"*("+undefCut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_data_hist_loose").c_str(),(scale+"*("+looseCut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_data_hist_tight").c_str(),(scale+"*("+tightCut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_data_hist_high_purity").c_str(),(scale+"*("+highPurityCut+")").c_str());
      hists.data_hist_undef->Add(temp_data_hist_undef);
      hists.data_hist_loose->Add(temp_data_hist_loose);
      hists.data_hist_tight->Add(temp_data_hist_tight);
      hists.data_hist_high_purity->Add(temp_data_hist_high_purity);
    }
  if(type == "data")
    {
      TH1F* temp_mc_hist_undef = (TH1F*)hists.mc_hist_undef->Clone((info.plotName+"_temp_mc_hist_undef").c_str());
      TH1F* temp_mc_hist_loose = (TH1F*)hists.mc_hist_loose->Clone((info.plotName+"_temp_mc_hist_loose").c_str());
      TH1F* temp_mc_hist_tight = (TH1F*)hists.mc_hist_tight->Clone((info.plotName+"_temp_mc_hist_tight").c_str());
      TH1F* temp_mc_hist_high_purity = (TH1F*)hists.mc_hist_high_purity->Clone((info.plotName+"_temp_mc_hist_high_purity").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_hist_undef").c_str(),(scale+"*("+undefCut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_hist_loose").c_str(),(scale+"*("+looseCut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_hist_tight").c_str(),(scale+"*("+tightCut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_hist_high_purity").c_str(),(scale+"*("+highPurityCut+")").c_str());
      hists.mc_hist_undef->Add(temp_mc_hist_undef);
      hists.mc_hist_loose->Add(temp_mc_hist_loose);
      hists.mc_hist_tight->Add(temp_mc_hist_tight);
      hists.mc_hist_high_purity->Add(temp_mc_hist_high_purity);
    }
  return;
}

void MakeATrackHist(string type, TTree* thisTree, information1d info, flavorHists1D hists, string scale)
{
  if(type=="data")
    {
      TH1F* temp_data_hist = (TH1F*)hists.data_hist->Clone((info.plotName+"_temp_data_hist").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_data_hist").c_str(),(scale+"*("+info.cut+")").c_str());
      hists.data_hist->Add(temp_data_hist);
    }
  if(type=="mc")
    {
      string bcut,ccut,lightcut,nonecut;
      bcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==5)";
      ccut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==4)";
      lightcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==1 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==2 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==3 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==21)";
      nonecut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==0)";
      
      if(info.cut!="")  
	{
	  bcut = "("+info.cut+")&&"+bcut;
	  ccut = "("+info.cut+")&&"+ccut;
	  lightcut ="("+info.cut+")&&"+lightcut;
	  nonecut ="("+info.cut+")&&"+nonecut;
	}      
      TH1F* temp_mc_b_hist = (TH1F*)hists.mc_b_hist->Clone((info.plotName+"_temp_mc_b_hist").c_str());
      TH1F* temp_mc_c_hist = (TH1F*)hists.mc_c_hist->Clone((info.plotName+"_temp_mc_c_hist").c_str());
      TH1F* temp_mc_light_hist = (TH1F*)hists.mc_light_hist->Clone((info.plotName+"_temp_mc_light_hist").c_str());
      TH1F* temp_mc_none_hist = (TH1F*)hists.mc_none_hist->Clone((info.plotName+"_temp_mc_none_hist").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_b_hist").c_str(),(scale+"*("+bcut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_c_hist").c_str(),(scale+"*("+ccut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_light_hist").c_str(),(scale+"*("+lightcut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_none_hist").c_str(),(scale+"*("+nonecut+")").c_str());
      hists.mc_b_hist->Add(temp_mc_b_hist);
      hists.mc_c_hist->Add(temp_mc_c_hist);
      hists.mc_light_hist->Add(temp_mc_light_hist);
      hists.mc_none_hist->Add(temp_mc_none_hist);
    }
  return;
}

void MakeAHist(string type, TTree* thisTree, information1d info, flavorHists1D hists,string scale)
{
  if(type=="data")
    {
      TH1F* temp_data_hist = (TH1F*)hists.data_hist->Clone((info.plotName+"_temp_data_hist").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_data_hist").c_str(),(scale+"*("+info.cut+")").c_str());
      hists.data_hist->Add(temp_data_hist);
    }
  if(type=="mc")
    {
      string bcut,ccut,lightcut,nonecut;
      bcut = "("+info.label+"MCTrueFlavor==5)";
      ccut = "("+info.label+"MCTrueFlavor==4)";
      lightcut = "("+info.label+"MCTrueFlavor==1 ||"+info.label+"MCTrueFlavor==2 ||"+info.label+"MCTrueFlavor==3 ||"+info.label+"MCTrueFlavor==21)";
      nonecut = "("+info.label+"MCTrueFlavor==0)";
       
      if(info.cut!="")  
	{
	  bcut = "("+info.cut+")&&"+bcut;
	  ccut = "("+info.cut+")&&"+ccut;
	  lightcut ="("+info.cut+")&&"+lightcut;
	  nonecut ="("+info.cut+")&&"+nonecut;
	}
      TH1F* temp_mc_b_hist = (TH1F*)hists.mc_b_hist->Clone((info.plotName+"_temp_mc_b_hist").c_str());
      TH1F* temp_mc_c_hist = (TH1F*)hists.mc_c_hist->Clone((info.plotName+"_temp_mc_c_hist").c_str());
      TH1F* temp_mc_light_hist = (TH1F*)hists.mc_light_hist->Clone((info.plotName+"_temp_mc_light_hist").c_str());
      TH1F* temp_mc_none_hist = (TH1F*)hists.mc_none_hist->Clone((info.plotName+"_temp_mc_none_hist").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_b_hist").c_str(),(scale+"*("+bcut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_c_hist").c_str(),(scale+"*("+ccut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_light_hist").c_str(),(scale+"*("+lightcut+")").c_str());
      thisTree->Draw((info.aliasx+">>"+info.plotName+"_temp_mc_none_hist").c_str(),(scale+"*("+nonecut+")").c_str());
      hists.mc_b_hist->Add(temp_mc_b_hist);
      hists.mc_c_hist->Add(temp_mc_c_hist);
      hists.mc_light_hist->Add(temp_mc_light_hist);
      hists.mc_none_hist->Add(temp_mc_none_hist);
    }
  return;
}

void MakeA2DHist(string type, TTree* thisTree, information2d info,flavorHists2D hists, string scale)
{
  if(type=="data")
    {
      TH2F* temp_data_hist = (TH2F*)hists.data_hist->Clone((info.plotName+"_temp_data_hist").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_data_hist").c_str(),(scale+"*("+info.cut+")").c_str());
      hists.data_hist->Add(temp_data_hist);
    }
  if(type=="mc")
    {
      string bcut,ccut,lightcut,nonecut;
      bcut = "("+info.label+"MCTrueFlavor==5)";
      ccut = "("+info.label+"MCTrueFlavor==4)";
      lightcut = "("+info.label+"MCTrueFlavor==1 ||"+info.label+"MCTrueFlavor==2 ||"+info.label+"MCTrueFlavor==3 ||"+info.label+"MCTrueFlavor==21)";
      nonecut = "("+info.label+"MCTrueFlavor==0)";
       
      if(info.cut!="")  
	{
	  bcut = "("+info.cut+")&&"+bcut;
	  ccut = "("+info.cut+")&&"+ccut;
	  lightcut ="("+info.cut+")&&"+lightcut;
	  nonecut ="("+info.cut+")&&"+nonecut;
	}
      TH2F* temp_mc_b_hist = (TH2F*)hists.mc_b_hist->Clone((info.plotName+"_temp_mc_b_hist").c_str());
      TH2F* temp_mc_c_hist = (TH2F*)hists.mc_c_hist->Clone((info.plotName+"_temp_mc_c_hist").c_str());
      TH2F* temp_mc_light_hist = (TH2F*)hists.mc_light_hist->Clone((info.plotName+"_temp_mc_light_hist").c_str());
      TH2F* temp_mc_none_hist = (TH2F*)hists.mc_none_hist->Clone((info.plotName+"_temp_mc_none_hist").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_b_hist").c_str(),(scale+"*("+bcut+")").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_c_hist").c_str(),(scale+"*("+ccut+")").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_light_hist").c_str(),(scale+"*("+lightcut+")").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_none_hist").c_str(),(scale+"*("+nonecut+")").c_str());
      hists.mc_b_hist->Add(temp_mc_b_hist);
      hists.mc_c_hist->Add(temp_mc_c_hist);
      hists.mc_light_hist->Add(temp_mc_light_hist);
      hists.mc_none_hist->Add(temp_mc_none_hist);
    }
  return;
}

void MakeAProfileHist(string type, TTree* thisTree, information2d info,profileHists hists, string scale)
{
  if(type=="data")
    {
      TH2F* temp_data_hist = (TH2F*)hists.data_hist->Clone((info.plotName+"_temp_data_hist").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_data_hist").c_str(),(scale+"*("+info.cut+")").c_str());
      hists.data_hist->Add(temp_data_hist);
    }
  if(type=="mc")
    {
      string bcut,ccut,lightcut,nonecut;
      bcut = "("+info.label+"MCTrueFlavor==5)";
      ccut = "("+info.label+"MCTrueFlavor==4)";
      lightcut = "("+info.label+"MCTrueFlavor==1 ||"+info.label+"MCTrueFlavor==2 ||"+info.label+"MCTrueFlavor==3 ||"+info.label+"MCTrueFlavor==21)";
      nonecut = "("+info.label+"MCTrueFlavor==0)";
       
      if(info.cut!="")  
	{
	  bcut = "("+info.cut+")&&"+bcut;
	  ccut = "("+info.cut+")&&"+ccut;
	  lightcut ="("+info.cut+")&&"+lightcut;
	  nonecut ="("+info.cut+")&&"+nonecut;
	}
      TH2F* temp_mc_b_hist = (TH2F*)hists.mc_b_hist->Clone((info.plotName+"_temp_mc_b_hist").c_str());
      TH2F* temp_mc_c_hist = (TH2F*)hists.mc_c_hist->Clone((info.plotName+"_temp_mc_c_hist").c_str());
      TH2F* temp_mc_light_hist = (TH2F*)hists.mc_light_hist->Clone((info.plotName+"_temp_mc_light_hist").c_str());
      TH2F* temp_mc_none_hist = (TH2F*)hists.mc_none_hist->Clone((info.plotName+"_temp_mc_none_hist").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_b_hist").c_str(),(scale+"*("+bcut+")").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_c_hist").c_str(),(scale+"*("+ccut+")").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_light_hist").c_str(),(scale+"*("+lightcut+")").c_str());
      thisTree->Draw((info.aliasy+":"+info.aliasx+">>"+info.plotName+"_temp_mc_none_hist").c_str(),(scale+"*("+nonecut+")").c_str());
      hists.mc_b_hist->Add(temp_mc_b_hist);
      hists.mc_c_hist->Add(temp_mc_c_hist);
      hists.mc_light_hist->Add(temp_mc_light_hist);
      hists.mc_none_hist->Add(temp_mc_none_hist);
    }
  return;
}

void
MakeAllPlots(string mcfilename, string datafilename, string plotfilename, double finalNorm=1, string rootFile="plots.root" , string doPlot="")
{

  TFile* theFile = TFile::Open(rootFile.c_str(),"RECREATE");

  ifstream mcFiles;
  mcFiles.open(mcfilename.c_str());
  ifstream dataFiles;
  dataFiles.open(datafilename.c_str());
  ifstream plotFiles;
  plotFiles.open(plotfilename.c_str());

  list<pair<string, string> > mcList;
  list<pair<string, string> > dataList;

  while (! mcFiles.eof()) {
    string line;
    getline (mcFiles,line);
    if (line.find("#")==0) continue;
    size_t position = line.find(",");
    if(position == string::npos) continue;
    string thisFileName = line.substr(0,position);
    string thisWeight = line.substr(position+1).c_str();
    mcList.push_back(pair<string,string>(thisFileName,thisWeight));
  }
  while (! dataFiles.eof()) {
    string line;
    getline (dataFiles,line);
    if (line.find("#")==0) continue;
    size_t position = line.find(",");
    if(position == string::npos) continue;
    string thisFileName = line.substr(0,position);
    string thisWeight = line.substr(position+1);
    dataList.push_back(pair<string,string>(thisFileName,thisWeight));
  }

  list< pair< information1d , flavorHists1D > > jetPlots1D;
  list< pair< information1d , flavorHists1D > > trackPlots_flavorStack;
  list< pair< information1d , qualityHists1D > > trackPlots_qualityStack;
  list< pair< information2d , flavorHists2D > > jetPlots2D;
  list< pair< information2d , profileHists > > profilePlots;

  while (! plotFiles.eof()) {
    string line;
    getline (plotFiles,line);
    if (line.find("#")==0) continue;
    if(line.find("plot_type")==string::npos) continue;
    size_t typePosition = line.find("=");
    string plotType = line.substr(typePosition+1);
    if(plotType.find("jetPlots1D")!=string::npos){
      information1d thisPlot = param1d(&plotFiles);
      if(doPlot == "" || thisPlot.plotName.find(doPlot)!=string::npos){
	flavorHists1D theseHists;
	theseHists.data_hist = new TH1F((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_all_hist = new TH1F((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_b_hist = new TH1F((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_c_hist = new TH1F((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_light_hist = new TH1F((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_none_hist = new TH1F((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	theseHists.mc_b_hist->Sumw2();
	theseHists.mc_c_hist->Sumw2();
	theseHists.mc_light_hist->Sumw2();
	theseHists.mc_none_hist->Sumw2();
	jetPlots1D.push_back(pair<information1d,flavorHists1D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("jetPlots2D")!=string::npos){
      information2d thisPlot = param2d(&plotFiles);
      if(doPlot == "" || thisPlot.plotName.find(doPlot)!=string::npos){
	flavorHists2D theseHists;
	theseHists.data_hist = new TH2F((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_all_hist = new TH2F((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_b_hist = new TH2F((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_c_hist = new TH2F((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_light_hist = new TH2F((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_none_hist = new TH2F((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	theseHists.mc_b_hist->Sumw2();
	theseHists.mc_c_hist->Sumw2();
	theseHists.mc_light_hist->Sumw2();
	theseHists.mc_none_hist->Sumw2();
	jetPlots2D.push_back(pair<information2d,flavorHists2D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("profilePlots")!=string::npos){
      information2d thisPlot = param2d(&plotFiles);
      if(doPlot == "" || thisPlot.plotName.find(doPlot)!=string::npos){
	profileHists theseHists;
	theseHists.data_hist = new TH2F((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_all_hist = new TH2F((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_b_hist = new TH2F((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_c_hist = new TH2F((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_light_hist = new TH2F((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_none_hist = new TH2F((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	theseHists.mc_b_hist->Sumw2();
	theseHists.mc_c_hist->Sumw2();
	theseHists.mc_light_hist->Sumw2();
	theseHists.mc_none_hist->Sumw2();
	profilePlots.push_back(pair<information2d,profileHists>(thisPlot,theseHists));
      }
    }
    if(plotType.find("trackPlots_flavorStack")!=string::npos){
      information1d thisPlot = param1d(&plotFiles);
      if(doPlot == "" || thisPlot.plotName.find(doPlot)!=string::npos){
	flavorHists1D theseHists;
	theseHists.data_hist = new TH1F((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_all_hist = new TH1F((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_b_hist = new TH1F((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_c_hist = new TH1F((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_light_hist = new TH1F((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_none_hist = new TH1F((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	theseHists.mc_b_hist->Sumw2();
	theseHists.mc_c_hist->Sumw2();
	theseHists.mc_light_hist->Sumw2();
	theseHists.mc_none_hist->Sumw2();
	trackPlots_flavorStack.push_back(pair<information1d,flavorHists1D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("trackPlots_qualityStack")!=string::npos){
      information1d thisPlot = param1d(&plotFiles);
      if(doPlot == "" || thisPlot.plotName.find(doPlot)!=string::npos){
	qualityHists1D theseHists;
	theseHists.data_hist_undef = new TH1F((thisPlot.plotName+"_data_hist_undef").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_loose = new TH1F((thisPlot.plotName+"_data_hist_loose").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_tight = new TH1F((thisPlot.plotName+"_data_hist_tight").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_high_purity = new TH1F((thisPlot.plotName+"_data_hist_high_purity").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_undef = new TH1F((thisPlot.plotName+"_mc_hist_undef").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_loose = new TH1F((thisPlot.plotName+"_mc_hist_loose").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_tight = new TH1F((thisPlot.plotName+"_mc_hist_tight").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_high_purity = new TH1F((thisPlot.plotName+"_mc_hist_high_purity").c_str(),thisPlot.plotName.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_undef->Sumw2();
	theseHists.data_hist_loose->Sumw2();
	theseHists.data_hist_tight->Sumw2();
	theseHists.data_hist_high_purity->Sumw2();
	theseHists.mc_hist_undef->Sumw2();
	theseHists.mc_hist_loose->Sumw2();
	theseHists.mc_hist_tight->Sumw2();
	theseHists.mc_hist_high_purity->Sumw2();
	trackPlots_qualityStack.push_back(pair<information1d,qualityHists1D>(thisPlot,theseHists));
      } 
    }
  }

  for(list<pair<string,string> >::iterator iFile = mcList.begin(); iFile != mcList.end(); iFile++)
    {
      TFile* thisFile = TFile::Open((iFile->first).c_str());
      TTree* thisTree = (TTree*)thisFile->Get("Events");
      thisFile->cd();
      for(list< pair< information1d , flavorHists1D > >::iterator iPlot = jetPlots1D.begin(); iPlot != jetPlots1D.end(); iPlot++)
	{
	  MakeAHist("mc",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information1d , flavorHists1D > >::iterator iPlot = trackPlots_flavorStack.begin(); iPlot != trackPlots_flavorStack.end(); iPlot++)
	{
	  MakeATrackHist("mc",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information1d , qualityHists1D > >::iterator iPlot = trackPlots_qualityStack.begin(); iPlot != trackPlots_qualityStack.end(); iPlot++)
	{
	  MakeATrackQualityHist("mc",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information2d , flavorHists2D > >::iterator iPlot = jetPlots2D.begin(); iPlot != jetPlots2D.end(); iPlot++)
	{
	  MakeA2DHist("mc",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information2d , profileHists > >::iterator iPlot = profilePlots.begin(); iPlot != profilePlots.end(); iPlot++)
	{
	  MakeAProfileHist("mc",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      thisFile->Close();
    }

  for(list<pair<string,string> >::iterator iFile = dataList.begin(); iFile != dataList.end(); iFile++)
    {
      TFile* thisFile = TFile::Open((iFile->first).c_str());
      TTree* thisTree = (TTree*)thisFile->Get("Events");
      for(list< pair< information1d , flavorHists1D > >::iterator iPlot = jetPlots1D.begin(); iPlot != jetPlots1D.end(); iPlot++)
	{
	  MakeAHist("data",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information1d , flavorHists1D > >::iterator iPlot = trackPlots_flavorStack.begin(); iPlot != trackPlots_flavorStack.end(); iPlot++)
	{
	  MakeATrackHist("data",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information1d , qualityHists1D > >::iterator iPlot = trackPlots_qualityStack.begin(); iPlot != trackPlots_qualityStack.end(); iPlot++)
	{
	  MakeATrackQualityHist("data",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information2d , flavorHists2D > >::iterator iPlot = jetPlots2D.begin(); iPlot != jetPlots2D.end(); iPlot++)
	{
	  MakeA2DHist("data",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      for(list< pair< information2d , profileHists > >::iterator iPlot = profilePlots.begin(); iPlot != profilePlots.end(); iPlot++)
	{
	  MakeAProfileHist("data",thisTree,iPlot->first,iPlot->second,iFile->second);
	}
      thisFile->Close();
    }

  theFile->cd();

  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = jetPlots1D.begin(); iPlot != jetPlots1D.end(); iPlot++)
    {
      MakeAPlot(iPlot->first,iPlot->second,finalNorm);
    }
  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = trackPlots_flavorStack.begin(); iPlot != trackPlots_flavorStack.end(); iPlot++)
    {
      MakeAPlot(iPlot->first,iPlot->second,finalNorm);
    }
  for(list< pair< information1d , qualityHists1D > >::iterator iPlot = trackPlots_qualityStack.begin(); iPlot != trackPlots_qualityStack.end(); iPlot++)
    {
      MakeATrackQualityPlot(iPlot->first,iPlot->second,finalNorm);
    }
  for(list< pair< information2d , flavorHists2D > >::iterator iPlot = jetPlots2D.begin(); iPlot != jetPlots2D.end(); iPlot++)
    {
      MakeA2DPlot(iPlot->first,iPlot->second,finalNorm);
    }
  for(list< pair< information2d , profileHists > >::iterator iPlot = profilePlots.begin(); iPlot != profilePlots.end(); iPlot++)
    {
      MakeAProfilePlot(iPlot->first,iPlot->second,finalNorm);
    }
  return;
}
