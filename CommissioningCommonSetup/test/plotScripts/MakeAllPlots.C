#include "TROOT.h"
#include "TStyle.h"
#include "TColor.h"
#include "TObject.h"
#include "TFile.h"
#include "TProfile.h"
#include "THStack.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TTree.h"
#include "TSelectorMultiDraw.h"
#include "TDirectory.h"
#include "TPaveText.h"

//#include <cmath>
#include <math.h>
#include <string>
//#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <utility>
#include "TStyle.h"
#include "informationTrackCuts.h"
#include "informationMuonCuts.h"

struct information1d{
  std::string plotName;
  std::string plotTitle;
  std::string label;
  std::string aliasx;
  std::string xTitle;
  std::string cut;
  double xlow;
  double xup;
  int nbinsx;
  std::string yTitle;
  double yMin;
  double ratioMin;
  double ratioMax;
  double bScale;
  double cScale;
  int ratioRebin;
  bool displayOverUnderflowBin;
  bool displayNoInfo;
  bool legendPosition;
};


information1d get1DInfoFromTrackCut(informationTrackCuts info);
information1d get1DInfoFromMuonCut(informationMuonCuts info);
double IntegralAndError(TH1D*    , int, int, double &);

//Header on canvas: CMS preliminary/cm energy and lumi
// for plots with ratio at the bottom
void cmsPrel(double intLumi) {

  TLatex *latex = new TLatex();
  latex->SetNDC();
  latex->SetTextSize(0.045);
  latex->SetTextFont(42); //22

  latex->SetTextAlign(13);
  latex->DrawLatex(0.22, 0.96, Form("CMS Preliminary 2010,     #sqrt{s} = 7 TeV,  L = %.2g pb^{   -1}",intLumi));

}

// For profile and noRatio plots
void cmsProfPrel(double intLumi) {

  TLatex *latex = new TLatex();
  latex->SetNDC();
  latex->SetTextSize(0.035);
  latex->SetTextFont(42); //22

  latex->SetTextAlign(13);
  latex->DrawLatex(0.22, 0.95, Form("CMS Preliminary 2010,   #sqrt{s} = 7 TeV,  L = %.2g pb^{-1}",intLumi));

}

void setTDRStyle() {

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-DR");

  gROOT->SetStyle("Plain");
  gROOT->ForceStyle();

  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetPadBorderMode(0);
  tdrStyle->SetPadBorderMode(0);

  //	tdrStyle->SetFrameColor(0);
  tdrStyle->SetPadColor(0);
  tdrStyle->SetCanvasColor(0);
  tdrStyle->SetStatColor(0);
  tdrStyle->SetFillColor(0);

  tdrStyle->SetPaperSize(20,26);
  //	tdrStyle->SetPadTopMargin(0.08);
  //	tdrStyle->SetPadBottomMargin(0.14);
  tdrStyle->SetPadRightMargin(0.04);
  tdrStyle->SetPadLeftMargin(0.16);
  //	tdrStyle->SetCanvasDefH(800);
  //	tdrStyle->SetCanvasDefW(800);
  //	tdrStyle->SetPadGridX(1);
  //	tdrStyle->SetPadGridY(1);
  tdrStyle->SetPadTickX(1);
  tdrStyle->SetPadTickY(1);

  tdrStyle->SetTextFont(42); //132
  tdrStyle->SetTextSize(0.09);
  tdrStyle->SetLabelFont(42,"xyz");
  tdrStyle->SetTitleFont(42,"xyz");
  tdrStyle->SetLabelSize(0.045,"xyz"); //0.035
  tdrStyle->SetTitleSize(0.045,"xyz");
  tdrStyle->SetTitleOffset(1.5,"y");
    
  tdrStyle->SetTitleX(0.16);
  tdrStyle->SetTitleY(0.93);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(0);
  tdrStyle->SetTitleBorderSize(1);
  tdrStyle->SetTitleFontSize(0.04);
  //	tdrStyle->SetPadTopMargin(0.05);
  //	tdrStyle->SetPadBottomMargin(0.13);
  //	tdrStyle->SetPadLeftMargin(0.14);
  //	tdrStyle->SetPadRightMargin(0.02);

  // use bold lines and markers
  tdrStyle->SetMarkerStyle(8);
  tdrStyle->SetHistLineWidth(3);
  tdrStyle->SetLineWidth(1);
  
  tdrStyle->SetOptTitle(kFALSE);
  tdrStyle->SetOptStat(0);

  tdrStyle->cd();
}

struct informationCutComp{
  std::string plotName;
  std::string plotTitle;
  std::string label;
  std::string aliasx;
  std::string xTitle;
  std::string cut;
  std::vector<string> cutList;
  std::vector<string> labelList;
  double xlow;
  double xup;
  int nbinsx;
  double ratioMin;
  double ratioMax;
  int ratioRebin;
  bool displayNoInfo;
  bool legendPosition;
};

struct informationQuality{
  std::string plotName;
  std::string plotTitle;
  std::string label;
  std::string aliasx;
  std::string xTitle;
  std::string cut;
  std::string qualityVar;
  double xlow;
  double xup;
  int nbinsx;
};

struct informationPtHat{
  std::string plotName;
  std::string plotTitle;
  std::string label;
  std::string aliasx;
  std::string xTitle;
  std::string cut;
  std::string pthatCut;
  std::vector<double> ptHatBins;
  double xlow;
  double xup;
  int nbinsx;
  double pthatlow;
  double pthatup;
  int nbinspthat;
};

struct information2d{
  std::string plotName;
  std::string plotTitle;
  std::string label;
  std::string aliasx;
  std::string xTitle;
  std::string aliasy;
  std::string yTitle;
  std::string cut;
  double bScale;
  double cScale;
  double xlow;
  double xup;
  int nbinsx;
  double ylow;
  double yup;
  int nbinsy;
  bool displayNoInfo;
  bool legendPosition;
};

struct informationCut{
  std::string plotName;
  std::string plotTitle;
  std::string label;
  std::string aliasx;
  std::string xTitle;
  std::string aliasy;
  std::string yTitle;
  std::string cut;
  double bScale;
  double cScale;
  std::string direction;
  double xlow;
  double xup;
  int nbinsx;
  double ylow;
  double yup;
  int nbinsy;
  bool displayNoInfo;
  bool legendPosition;
};



struct flavorHists1D {
  TH1D* data_hist;
  TH1D* mc_all_hist;
  TH1D* mc_b_hist;
  TH1D* mc_bglusplit_hist;
  TH1D* mc_c_hist;
  TH1D* mc_light_hist;
  TH1D* mc_none_hist;
  // constructor to avoid warning
  flavorHists1D(){data_hist=0; mc_all_hist=0; mc_b_hist=0; mc_bglusplit_hist=0; mc_c_hist=0; mc_light_hist=0; mc_none_hist=0;};
};

struct cutCompHists{
  TH1D* CutCompInfo_data;
  TH1D* CutCompInfo_mc;
  std::vector<TH2D*> hists_data;
  std::vector<TH2D*> hists_mc_all;
  std::vector<TH2D*> hists_mc_b;
  std::vector<TH2D*> hists_mc_c;
  std::vector<TH2D*> hists_mc_light;
  std::vector<TH2D*> hists_mc_none;
};

struct ptHatHists1D{
  TH1D* data_hist;
  TH1D* pthat_hist;
  std::vector<TH1D*> mc_hists;
};

struct qualityHists1D{
  TH1D* data_hist_undef;
  TH1D* data_hist_loose;
  TH1D* data_hist_tight;
  TH1D* data_hist_high_purity;
  TH1D* mc_hist_undef;
  TH1D* mc_hist_loose;
  TH1D* mc_hist_tight;
  TH1D* mc_hist_high_purity;
};

struct flavorHists2D{
  TH2D* data_hist;
  TH2D* mc_all_hist;
  TH2D* mc_b_hist;
  TH2D* mc_bglusplit_hist;
  TH2D* mc_c_hist;
  TH2D* mc_light_hist;
  TH2D* mc_none_hist;
  flavorHists2D(){data_hist=0; mc_all_hist=0; mc_b_hist=0; mc_bglusplit_hist=0; mc_c_hist=0; mc_light_hist=0; mc_none_hist=0;};
};

using namespace std;

information1d param1d(ifstream* plotFile, information1d defaultParams)
{
  information1d thisPlot = defaultParams;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool cut = false;
  bool bScale = false;
  bool cScale = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool yTitle = false;
  bool yMin = false;
  bool ratioMin = false;
  bool ratioMax = false;
  bool ratioRebin = false;
  bool displayOverUnderflowBin = false;
  bool bDisplayNoInfo = false;
  bool blegendPosition = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && cut && bScale && cScale && xlow && xup && nbinsx && yTitle && yMin && ratioMin && ratioMax && displayOverUnderflowBin && ratioRebin && bDisplayNoInfo && blegendPosition)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("cut")<position){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("bScale")<position){
      bScale = true;
      thisPlot.bScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("cScale")<position){
      cScale = true;
      thisPlot.cScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("yTitle")<position){
      yTitle = true;
      thisPlot.yTitle = line.substr(position+1);
    }
    if(line.find("yMin")<position){
      yMin = true;
      thisPlot.yMin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMin")<position){
      ratioMin = true;
      thisPlot.ratioMin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMax")<position){
      ratioMax = true;
      thisPlot.ratioMax = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioRebin")<position){
      ratioRebin = true;
      thisPlot.ratioRebin = atof((line.substr(position+1)).c_str());
    }
   if(line.find("displayOverUnderflowBin")<position){
      displayOverUnderflowBin = true;
      thisPlot.displayOverUnderflowBin = (bool)atoi((line.substr(position+1)).c_str());
    }
    if(line.find("displayNoInfo")<position){
      bDisplayNoInfo = true;
      thisPlot.displayNoInfo = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("legendPosition")<position){
      blegendPosition = true;
      thisPlot.legendPosition = (bool)(atoi((line.substr(position+1)).c_str()));
    }

  }
  return thisPlot;
}


informationTrackCuts paramTrackCuts(ifstream* plotFile)
{
  informationTrackCuts thisPlot;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool cut = false;
  bool bScale = false;
  bool cScale = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool yTitle = false;
  bool yMin = false;
  bool ratioMin = false;
  bool ratioMax = false;
  bool ratioRebin = false;
  bool displayOverUnderflowBin = false;
  bool bDisplayNoInfo = false;
  bool blegendPosition = false;

  bool btriggerHLTJet30U = false;
  bool bjetPtCut = false;
  bool bjetEtaCut = false;
  bool bnHitsCut = false;
  bool bnPixHitsCut = false;
  bool bChi2Cut = false;
  bool btrackPtCut = false;
  bool bdistJetAxisCut = false;
  bool bdecayLengthCut = false;
  bool bIP2dCut = false;
  bool blongIPCut = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && cut && bScale && cScale && xlow && xup && nbinsx && yTitle && yMin && ratioMin && ratioMax && displayOverUnderflowBin && ratioRebin && bDisplayNoInfo && blegendPosition && bjetPtCut && bjetEtaCut && bnHitsCut && bnPixHitsCut && bChi2Cut && btrackPtCut && bdistJetAxisCut && bdecayLengthCut && bIP2dCut && blongIPCut && btriggerHLTJet30U)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
      //  thisPlot.plotName += "_TC";
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("cut")<position){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("bScale")<position){
      bScale = true;
      thisPlot.bScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("cScale")<position){
      cScale = true;
      thisPlot.cScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("yTitle")<position){
      yTitle = true;
      thisPlot.yTitle = line.substr(position+1);
    }
    if(line.find("yMin")<position){
      yMin = true;
      thisPlot.yMin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMin")<position){
      ratioMin = true;
      thisPlot.ratioMin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMax")<position){
      ratioMax = true;
      thisPlot.ratioMax = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioRebin")<position){
      ratioRebin = true;
      thisPlot.ratioRebin = atof((line.substr(position+1)).c_str());
    }
   if(line.find("displayOverUnderflowBin")<position){
      displayOverUnderflowBin = true;
      thisPlot.displayOverUnderflowBin = (bool)atoi((line.substr(position+1)).c_str());
    }
    if(line.find("displayNoInfo")<position){
      bDisplayNoInfo = true;
      thisPlot.displayNoInfo = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("legendPosition")<position){
      blegendPosition = true;
      thisPlot.legendPosition = (bool)(atoi((line.substr(position+1)).c_str()));
    }

    if(line.find("jetPtCut")<position){
      bjetPtCut = true;
      thisPlot.jetPtCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("jetEtaCut")<position){
      bjetEtaCut = true;
      thisPlot.jetEtaCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nHitsCut")<position){
      bnHitsCut = true;
      thisPlot.nHitsCut = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("nPixHitsCut")<position){
      bnPixHitsCut = true;
      thisPlot.nPixHitsCut = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("Chi2Cut")<position){
      bChi2Cut = true;
      thisPlot.Chi2Cut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("trackPtCut")<position){
      btrackPtCut = true;
      thisPlot.trackPtCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("distJetAxisCut")<position){
      bdistJetAxisCut = true;
      thisPlot.distJetAxisCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("decayLengthCut")<position){
      bdecayLengthCut = true;
      thisPlot.decayLengthCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("IP2dCut")<position){
      bIP2dCut = true;
      thisPlot.IP2dCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("longIPCut")<position){
      blongIPCut = true;
      thisPlot.longIPCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("triggerHLTJet30U")<position){
      btriggerHLTJet30U = true;
      thisPlot.triggerHLTJet30U = (bool)(atoi((line.substr(position+1)).c_str()));
    }

  }
  return thisPlot;
}

informationMuonCuts paramMuonCuts(ifstream* plotFile)
{
  informationMuonCuts thisPlot;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool cut = false;
  bool bScale = false;
  bool cScale = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool yTitle = false;
  bool yMin = false;
  bool ratioMin = false;
  bool ratioMax = false;
  bool ratioRebin = false;
  bool displayOverUnderflowBin = false;
  bool bDisplayNoInfo = false;
  bool blegendPosition = false;

  bool btriggerHLTJet30U = false;
  bool bjetPtCut = false;
  bool bjetEtaCut = false;
  bool bmuPtCut = false;
  bool bmuEtaCut = false;
  bool bmuIsGlobal = false;
  bool bmuGlobalHits = false;
  bool bmuNmatch = false;
  bool bmuInnerHits = false;
  bool bmuPixelHits = false;
  bool bmuExpOuterHits = false;
  bool bmuInnerChi2 = false;
  bool bmuGlobalChi2 = false;
  bool bmuVzPVDist = false;
  bool bmuDR = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && cut && bScale && cScale && xlow && xup && nbinsx && yTitle && yMin && ratioMin && ratioMax && displayOverUnderflowBin && ratioRebin && bDisplayNoInfo && blegendPosition 
	    && btriggerHLTJet30U && bjetPtCut && bjetEtaCut && bmuPtCut && bmuEtaCut && bmuIsGlobal && bmuGlobalHits && bmuNmatch && bmuInnerHits && bmuPixelHits && bmuExpOuterHits && bmuInnerChi2 && bmuGlobalChi2 && bmuVzPVDist && bmuDR) ) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
      //  thisPlot.plotName += "_TC";
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("cut")<position){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("bScale")<position){
      bScale = true;
      thisPlot.bScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("cScale")<position){
      cScale = true;
      thisPlot.cScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("yTitle")<position){
      yTitle = true;
      thisPlot.yTitle = line.substr(position+1);
    }
    if(line.find("yMin")<position){
      yMin = true;
      thisPlot.yMin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMin")<position){
      ratioMin = true;
      thisPlot.ratioMin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMax")<position){
      ratioMax = true;
      thisPlot.ratioMax = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioRebin")<position){
      ratioRebin = true;
      thisPlot.ratioRebin = atof((line.substr(position+1)).c_str());
    }
   if(line.find("displayOverUnderflowBin")<position){
      displayOverUnderflowBin = true;
      thisPlot.displayOverUnderflowBin = (bool)atoi((line.substr(position+1)).c_str());
    }
    if(line.find("displayNoInfo")<position){
      bDisplayNoInfo = true;
      thisPlot.displayNoInfo = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("legendPosition")<position){
      blegendPosition = true;
      thisPlot.legendPosition = (bool)(atoi((line.substr(position+1)).c_str()));
    }

    if(line.find("triggerHLTJet30U")<position){
      btriggerHLTJet30U = true;
      thisPlot.triggerHLTJet30U = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("jetPtCut")<position){
      bjetPtCut = true;
      thisPlot.jetPtCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("jetEtaCut")<position){
      bjetEtaCut = true;
      thisPlot.jetEtaCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("muonPtCut")<position){
      bmuPtCut = true;
      thisPlot.muonPtCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("muonEtaCut")<position){
      bmuEtaCut = true;
      thisPlot.muonEtaCut = atof((line.substr(position+1)).c_str());
    }
    if(line.find("muonIsGlobal")<position){
      bmuIsGlobal = true;
      thisPlot.muonIsGlobal = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("muonGlobalMuonHits")<position){
      bmuGlobalHits = true;
      thisPlot.muonGlobalMuonHits = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("muonNumberOfMatches")<position){
      bmuNmatch = true;
      thisPlot.muonNumberOfMatches = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("muonInnerValidHits")<position){
      bmuInnerHits = true;
      thisPlot.muonInnerValidHits = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("muonNPixelHits")<position){
      bmuPixelHits = true;
      thisPlot.muonNPixelHits = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("muonNExpectedOuterHits")<position){
      bmuExpOuterHits = true;
      thisPlot.muonNExpectedOuterHits = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("muonInnerNChi2")<position){
      bmuInnerChi2 = true;
      thisPlot.muonInnerNChi2 = atof((line.substr(position+1)).c_str());
    }
    if(line.find("muonGlobalNChi2")<position){
      bmuGlobalChi2 = true;
      thisPlot.muonGlobalNChi2 = atof((line.substr(position+1)).c_str());
    }
    if(line.find("muonVzPVDist")<position){
      bmuVzPVDist = true;
      thisPlot.muonVzPVDist = atof((line.substr(position+1)).c_str());
    }
    if(line.find("muonDeltaR")<position){
      bmuDR = true;
      thisPlot.muonDeltaR = atof((line.substr(position+1)).c_str());
    }
  }
  return thisPlot;
}

informationCutComp paramCutComp(ifstream* plotFile, informationCutComp defaultParams)
{
  informationCutComp thisPlot = defaultParams;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool cut = false;
  bool cutList = false;
  bool labelList = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool ratioMin = false;
  bool ratioMax = false;
  bool ratioRebin = false;
  bool bDisplayNoInfo = false;
  bool blegendPosition = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && cut && cutList && labelList && xlow && xup && nbinsx && ratioMin && ratioMax && ratioRebin && bDisplayNoInfo && blegendPosition)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("cut")<position && !(line.find("cutList")<position)){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("cutList")<position){
      cutList = true;
      string cutListString = line.substr(position+1);
      vector<string> cuts;
      char* allCuts;
      allCuts = new char [cutListString.size()+1];
      strcpy (allCuts, cutListString.c_str());
      char * tokens = strtok(allCuts,",");
      while(tokens!=NULL){
	cuts.push_back(string(tokens));
	tokens = strtok(NULL,",");
      }
      thisPlot.cutList = cuts;
      delete[] allCuts;
    }
    if(line.find("labelList")<position){
      labelList = true;
      string labelListString = line.substr(position+1);
      vector<string> labels;
      char* allLabels;
      allLabels = new char [labelListString.size()+1];
      strcpy (allLabels, labelListString.c_str());
      char * tokens = strtok(allLabels,",");
      while(tokens!=NULL){
	labels.push_back(string(tokens));
	tokens = strtok(NULL,",");
      }
      thisPlot.labelList = labels;
      delete[] allLabels;
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMin")<position){
      ratioMin = true;
      thisPlot.ratioMin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioMax")<position){
      ratioMax = true;
      thisPlot.ratioMax = atof((line.substr(position+1)).c_str());
    }
    if(line.find("ratioRebin")<position){
      ratioRebin = true;
      thisPlot.ratioRebin = atof((line.substr(position+1)).c_str());
    }
    if(line.find("displayNoInfo")<position){
      bDisplayNoInfo = true;
      thisPlot.displayNoInfo = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("legendPosition")<position){
      blegendPosition = true;
      thisPlot.legendPosition = (bool)(atoi((line.substr(position+1)).c_str()));
    }
  }
  return thisPlot;
}

informationQuality paramQuality(ifstream* plotFile, informationQuality defaultParams)
{
  informationQuality thisPlot = defaultParams;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool cut = false;
  bool qualityVar = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && cut && qualityVar && xlow && xup && nbinsx)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("cut")<position){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("qualityVar")<position){
      qualityVar = true;
      thisPlot.qualityVar = line.substr(position+1);
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
  }
  return thisPlot;
}

informationPtHat paramPtHat(ifstream* plotFile, informationPtHat defaultParams)
{
  informationPtHat thisPlot = defaultParams;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool cut = false;
  bool pthatCut = false;
  bool ptHatBins = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool pthatlow = false;
  bool pthatup = false;
  bool nbinspthat = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && cut && pthatCut && ptHatBins && xlow && xup && nbinsx && pthatlow && pthatup && nbinspthat)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("cut")<position){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("pthatCut")<position){
      pthatCut = true;
      thisPlot.pthatCut = line.substr(position+1);
    }
    if(line.find("ptHatBins")<position){
      ptHatBins = true;
      string binString = line.substr(position+1);
      vector<double> bins;
      char* allBins;
      allBins = new char [binString.size()+1];
      strcpy (allBins, binString.c_str());
      char * tokens = strtok(allBins,",");
      while(tokens!=NULL){
	bins.push_back(atof(tokens));
	tokens = strtok(NULL,",");
      }
      thisPlot.ptHatBins = bins;
      delete[] allBins;
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("pthatlow")<position){
      pthatlow = true;
      thisPlot.pthatlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("pthatup")<position){
      pthatup = true;
      thisPlot.pthatup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinspthat")<position){
      nbinspthat = true;
      thisPlot.nbinspthat = atoi((line.substr(position+1)).c_str());
    }
  }
  return thisPlot;
}

information2d param2d(ifstream* plotFile, information2d defaultParams)
{
  information2d thisPlot = defaultParams;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool aliasy = false;
  bool yTitle = false;
  bool cut = false;
  bool bScale = false;
  bool cScale = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool ylow = false;
  bool yup = false;
  bool nbinsy = false;
  bool bDisplayNoInfo = false;
  bool blegendPosition = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && aliasy && yTitle && cut && bScale && cScale && xlow && xup && nbinsx && ylow && yup && nbinsy && bDisplayNoInfo && blegendPosition)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("aliasy")<position){
      aliasy = true;
      thisPlot.aliasy = line.substr(position+1);
    }
    if(line.find("yTitle")<position){
      yTitle = true;
      thisPlot.yTitle = line.substr(position+1);
    }
    if(line.find("cut")<position){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("bScale")<position){
      bScale = true;
      thisPlot.bScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("cScale")<position){
      cScale = true;
      thisPlot.cScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("ylow")<position){
      ylow = true;
      thisPlot.ylow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("yup")<position){
      yup = true;
      thisPlot.yup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsy")<position){
      nbinsy = true;
      thisPlot.nbinsy = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("displayNoInfo")<position){
      bDisplayNoInfo = true;
      thisPlot.displayNoInfo = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("legendPosition")<position){
      blegendPosition = true;
      thisPlot.legendPosition = (bool)(atoi((line.substr(position+1)).c_str()));
    }
  }
  return thisPlot;
}

informationCut paramCut(ifstream* plotFile, informationCut defaultParams)
{
  informationCut thisPlot = defaultParams;
  bool plotName = false;
  bool plotTitle = false;
  bool label = false;
  bool aliasx = false;
  bool xTitle = false;
  bool aliasy = false;
  bool yTitle = false;
  bool cut = false;
  bool bScale  = false; 
  bool cScale = false;
  bool direction = false;
  bool xlow = false;
  bool xup = false;
  bool nbinsx = false;
  bool ylow = false;
  bool yup = false;
  bool nbinsy = false;
  bool bDisplayNoInfo = false;
  bool blegendPosition = false;

  while (! (plotName && plotTitle && label && aliasx && xTitle && aliasy && yTitle && cut && bScale && cScale &&  direction && xlow && xup && nbinsx && ylow && yup && nbinsy && bDisplayNoInfo && blegendPosition)) {
    string line;
    size_t position;
    getline(*plotFile,line);
    if (line.find("#")==0) continue;
    if (line.find("end_plot")!=string::npos) return thisPlot;
    if (line.find("end_default")!=string::npos) return thisPlot;
    position = line.find("=");
    if(line.find("plotName")<position){
      plotName = true; 
      thisPlot.plotName = line.substr(position+1);
    }
    if(line.find("plotTitle")<position){
      plotTitle = true; 
      thisPlot.plotTitle = line.substr(position+1);
    }
    if(line.find("label")<position){
      label = true; 
      thisPlot.label = line.substr(position+1);
    }
    if(line.find("aliasx")<position){
      aliasx = true;
      thisPlot.aliasx = line.substr(position+1);
    }
    if(line.find("xTitle")<position){
      xTitle = true;
      thisPlot.xTitle = line.substr(position+1);
    }
    if(line.find("aliasy")<position){
      aliasy = true;
      thisPlot.aliasy = line.substr(position+1);
    }
    if(line.find("yTitle")<position){
      yTitle = true;
      thisPlot.yTitle = line.substr(position+1);
    }
    if(line.find("cut")<position){
      cut = true;
      thisPlot.cut = line.substr(position+1);
    }
    if(line.find("bScale")<position){
      bScale = true;
      thisPlot.bScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("cScale")<position){
      cScale = true;
      thisPlot.cScale = atof((line.substr(position+1)).c_str());
    }
    if(line.find("direction")<position){
      direction = true;
      thisPlot.direction = line.substr(position+1);
    }
    if(line.find("xlow")<position){
      xlow = true;
      thisPlot.xlow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("xup")<position){
      xup = true;
      thisPlot.xup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsx")<position){
      nbinsx = true;
      thisPlot.nbinsx = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("ylow")<position){
      ylow = true;
      thisPlot.ylow = atof((line.substr(position+1)).c_str());
    }
    if(line.find("yup")<position){
      yup = true;
      thisPlot.yup = atof((line.substr(position+1)).c_str());
    }
    if(line.find("nbinsy")<position){
      nbinsy = true;
      thisPlot.nbinsy = atoi((line.substr(position+1)).c_str());
    }
    if(line.find("displayNoInfo")<position){
      bDisplayNoInfo = true;
      thisPlot.displayNoInfo = (bool)(atoi((line.substr(position+1)).c_str()));
    }
    if(line.find("legendPosition")<position){
      blegendPosition = true;
      thisPlot.legendPosition = (bool)(atoi((line.substr(position+1)).c_str()));
    }
  }
  return thisPlot;
}

double binarySummer(int dimension,vector<int> *whichCut, int cutPoint, int start, vector<double>* binaryHist)
{
  //recursive summation for cut correlation calculations
  //cout << "in the summer" << endl;
  double sum = 0;
  for(int k = start; k<whichCut->size(); k++)
    {
      bool kMatch = false;
      for(int i = 0; i<dimension; i++)
	{
	  if(k == (*whichCut)[i]){
	    kMatch = true;
	    continue;
	  }
	}
      if(kMatch) continue;
      (*whichCut)[cutPoint] = k;
      int iBin=0;
      for(int i = 0; i < cutPoint+1; i++)
	    {
	      iBin += pow(2,(*whichCut)[i]);
	    }
      sum+=(*binaryHist)[iBin];
      if(cutPoint < whichCut->size())  sum += binarySummer(dimension,whichCut,cutPoint+1,k+1,binaryHist);
    }
  //cout << "leaving summer" << endl;
  return sum;
}

void MakeACutCompPlot(informationCutComp info, cutCompHists hists)
{
  //Sort Out Triggers into Correlation Plot
  TH2D* dataCorrelations = new TH2D((info.plotName+"_dataCorrelations").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size(),info.cutList.size(),0,info.cutList.size());
  dataCorrelations->Sumw2();
  TH2D* mcCorrelations = new TH2D((info.plotName+"_mcCorrelations").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size(),info.cutList.size(),0,info.cutList.size());
  mcCorrelations->Sumw2();
  vector<int> whichCut(info.cutList.size(),0);
  vector<double> transcribe_data;
  vector<double> transcribe_mc;
  vector<double> transcribe_data_error2;
  vector<double> transcribe_mc_error2;
  double integral_mc=0;
  double integral_data=0;
  double integral_mc_error=0;
  double integral_data_error=0;
  for(int i = 0; i <= hists.CutCompInfo_data->GetNbinsX(); i++)
    {
      double placeHolder=hists.CutCompInfo_mc->GetBinContent(i);
      transcribe_mc.push_back(placeHolder);
      integral_mc+=placeHolder;
      placeHolder=hists.CutCompInfo_data->GetBinContent(i);
      transcribe_data.push_back(placeHolder);
      integral_data+=placeHolder;
      placeHolder = pow(hists.CutCompInfo_mc->GetBinError(i),2);
      transcribe_mc_error2.push_back(placeHolder);
      integral_mc_error+=placeHolder;
      placeHolder = pow(hists.CutCompInfo_data->GetBinError(i),2);
      transcribe_data_error2.push_back(placeHolder);
      integral_data_error+=placeHolder;
    }
  integral_mc_error=sqrt(integral_mc_error);
  integral_data_error=sqrt(integral_data_error);
  for(int i = 0; i < whichCut.size(); i++)
    {
      whichCut[0]=i;
      double dataBinContent = transcribe_data[pow(2,i)];
      double dataBinError = transcribe_data_error2[pow(2,i)];
      dataBinContent += binarySummer(1,&whichCut,1,0,&transcribe_data);
      dataBinError += binarySummer(1,&whichCut,1,0,&transcribe_data_error2);
      double mcBinContent = transcribe_mc[pow(2,i)];
      double mcBinError = transcribe_mc_error2[pow(2,i)];
      mcBinContent += binarySummer(1,&whichCut,1,0,&transcribe_mc);
      mcBinError += binarySummer(1,&whichCut,1,0,&transcribe_mc_error2);
      dataCorrelations->SetBinContent(i+1,i+1,dataBinContent);
      dataCorrelations->SetBinError(i+1,i+1,sqrt(dataBinError));
      mcCorrelations->SetBinContent(i+1,i+1,mcBinContent);
      mcCorrelations->SetBinError(i+1,i+1,sqrt(mcBinError));
      for(unsigned int j = i+1; j < whichCut.size(); j++)
	{
	  whichCut[1]=j;
	  dataBinContent = transcribe_data[pow(2,i)+pow(2,j)];
	  dataBinError = transcribe_data_error2[pow(2,i)+pow(2,j)];
	  dataBinContent += binarySummer(2,&whichCut,2,0,&transcribe_data);
	  dataBinError += binarySummer(2,&whichCut,2,0,&transcribe_data_error2);
	  mcBinContent = transcribe_mc[pow(2,i)+pow(2,j)];
	  mcBinError = transcribe_mc_error2[pow(2,i)+pow(2,j)];
	  mcBinContent += binarySummer(2,&whichCut,2,0,&transcribe_mc);
	  mcBinError += binarySummer(2,&whichCut,2,0,&transcribe_mc_error2);
	  dataCorrelations->SetBinContent(i+1,j+1,dataBinContent);
	  dataCorrelations->SetBinError(i+1,j+1,sqrt(dataBinError));
	  mcCorrelations->SetBinContent(i+1,j+1,mcBinContent);
	  mcCorrelations->SetBinError(i+1,j+1,sqrt(mcBinError));
	  dataCorrelations->SetBinContent(j+1,i+1,dataBinContent);
	  dataCorrelations->SetBinError(j+1,i+1,sqrt(dataBinError));
	  mcCorrelations->SetBinContent(j+1,i+1,mcBinContent);
	  mcCorrelations->SetBinError(j+1,i+1,sqrt(mcBinError));
	}
    }

  //include the official CMS label
  TPaveText *pt = new TPaveText(0.4,0.92,0.9,0.97,"brNDC");   
  pt->SetBorderSize(0);   
  pt->SetFillStyle(0);  
  pt->SetTextAlign(13);   
  pt->SetTextFont(42);   
  pt->SetTextSize(0.035);   
  TText *text = pt->AddText("CMS Preliminary 2010");   

  //Set up 2D drawing with labels on plot
  TCanvas canvas_data_correlations((info.plotName+"canvas_data_correlations").c_str(),info.plotTitle.c_str(),1024,1024);
  //Following code snippet stolen from http://www.slac.stanford.edu/BFROOT/www/Computing/Offline/ROOT/info/binLabels.C
  canvas_data_correlations.SetGrid();
  canvas_data_correlations.SetLeftMargin(0.20);
  canvas_data_correlations.SetBottomMargin(0.20);
  dataCorrelations->GetXaxis()->SetLabelOffset(99);
  dataCorrelations->GetYaxis()->SetLabelOffset(99);
  dataCorrelations->Draw("text");
  // draw labels along X
  TLatex t;
  double x,y;
  y = gPad->GetUymin() - 0.1*mcCorrelations->GetYaxis()->GetBinWidth(1);
  t.SetTextAngle(60);
  t.SetTextSize(0.02);
  t.SetTextAlign(33);
  for (unsigned int i=0;i<info.labelList.size();i++) {
    x = mcCorrelations->GetXaxis()->GetBinCenter(i+1);
    t.DrawLatex(x,y,info.labelList[i].c_str());
  }
  // draw labels along y
  x = gPad->GetUxmin() - 0.1*dataCorrelations->GetXaxis()->GetBinWidth(1);
  t.SetTextAlign(32);
  t.SetTextAngle(0);
  for (unsigned int i=0;i<info.labelList.size();i++) {
    y = dataCorrelations->GetYaxis()->GetBinCenter(i+1);
    t.DrawLatex(x,y,info.labelList[i].c_str());
  }
  pt->Draw();
  canvas_data_correlations.SaveAs((info.plotName+"_data_correlations.pdf").c_str());
  canvas_data_correlations.SaveAs((info.plotName+"_data_correlations.png").c_str());
  canvas_data_correlations.SaveAs((info.plotName+"_data_correlations.root").c_str());

  TCanvas canvas_mc_correlations((info.plotName+"canvas_mc_correlations").c_str(),info.plotTitle.c_str(),1024,1024);
  //Following code snippet stolen from http://www.slac.stanford.edu/BFROOT/www/Computing/Offline/ROOT/info/binLabels.C
  canvas_mc_correlations.SetGrid();
  canvas_mc_correlations.SetLeftMargin(0.15);
  canvas_mc_correlations.SetBottomMargin(0.15);
  mcCorrelations->GetXaxis()->SetLabelOffset(99);
  mcCorrelations->GetYaxis()->SetLabelOffset(99);
  mcCorrelations->Draw("text");
  // draw labels along X
  y = gPad->GetUymin() - 0.1*mcCorrelations->GetYaxis()->GetBinWidth(1);
  t.SetTextAngle(60);
  t.SetTextSize(0.02);
  t.SetTextAlign(33);
  for (unsigned int i=0;i<info.labelList.size();i++) {
    x = mcCorrelations->GetXaxis()->GetBinCenter(i+1);
    t.DrawLatex(x,y,info.labelList[i].c_str());
  }
  // draw labels along y
  x = gPad->GetUxmin() - 0.1*mcCorrelations->GetXaxis()->GetBinWidth(1);
  t.SetTextAlign(32);
  t.SetTextAngle(0);
  for (unsigned int i=0;i<info.labelList.size();i++) {
    y = mcCorrelations->GetYaxis()->GetBinCenter(i+1);
    t.DrawLatex(x,y,info.labelList[i].c_str());
  }
  pt->Draw();
  canvas_mc_correlations.SaveAs((info.plotName+"_mc_correlations.pdf").c_str());
  canvas_mc_correlations.SaveAs((info.plotName+"_mc_correlations.png").c_str());
  canvas_mc_correlations.SaveAs((info.plotName+"_mc_correlations.root").c_str());

  //Set up 1D Efficiency Plots -- Diagonal Entries/CutCompInfo->Integral(0,-1)

  //TH1D* dataPassed = new TH1D((info.plotName+"_dataPassed").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size());
  //dataPassed->Sumw2();
  //TH1D* mcPassed = new TH1D((info.plotName+"_mcPassed").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size());
  //mcPassed->Sumw2();
  //TH1D* dataTotal = new TH1D((info.plotName+"_dataTotal").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size());
  //dataTotal->Sumw2();
  //TH1D* mcTotal = new TH1D((info.plotName+"_mcTotal").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size());
  //mcTotal->Sumw2();

  TH1D* dataEfficiencies = new TH1D((info.plotName+"_dataEfficiencies").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size());
  dataEfficiencies->Sumw2();
  TH1D* mcEfficiencies = new TH1D((info.plotName+"_mcEfficiencies").c_str(),info.plotName.c_str(),info.cutList.size(),0,info.cutList.size());
  mcEfficiencies->Sumw2();


  for (unsigned int i=0;i<info.labelList.size();i++) {
    //dataPassed->SetBinContent(i+1,dataCorrelations->GetBinContent(i+1,i+1));
    //dataPassed->SetBinError(i+1,dataCorrelations->GetBinError(i+1,i+1));
    //mcPassed->SetBinContent(i+1,mcCorrelations->GetBinContent(i+1,i+1));
    //mcPassed->SetBinError(i+1,mcCorrelations->GetBinError(i+1,i+1));
    //dataTotal->SetBinContent(i+1,integral_data);
    //dataTotal->SetBinError(i+1,integral_data_error);
    //mcTotal->SetBinContent(i+1,integral_mc);
    //mcTotal->SetBinError(i+1,integral_mc_error);
    double data_content = dataCorrelations->GetBinContent(i+1,i+1);
    double data_error = dataCorrelations->GetBinError(i+1,i+1);
    double data_calc_ratio = data_content/integral_data;
    double data_calc_error = 0;
    if(data_content!=integral_data) data_calc_error = sqrt(fabs(((1.-2.*data_calc_ratio)*data_error*data_error+data_calc_ratio*data_calc_ratio*integral_data_error*integral_data_error)/(integral_data*integral_data)));
    dataEfficiencies->SetBinContent(i+1,data_calc_ratio);
    dataEfficiencies->SetBinError(i+1, data_calc_error);
    
    double mc_content = mcCorrelations->GetBinContent(i+1,i+1);
    double mc_error = mcCorrelations->GetBinError(i+1,i+1);
    double mc_calc_ratio = mc_content/integral_mc;
    double mc_calc_error = 0;
    if(mc_content!=integral_mc) mc_calc_error = sqrt(fabs(((1.-2.*data_calc_ratio)*data_error*data_error+data_calc_ratio*data_calc_ratio*integral_data_error*integral_data_error)/(integral_data*integral_data)));
    mcEfficiencies->SetBinContent(i+1,mc_calc_ratio);
    mcEfficiencies->SetBinError(i+1,mc_calc_error);
  }


  //dataEfficiencies->Divide(dataPassed,dataTotal,1,1,"B");
  //mcEfficiencies->Divide(mcPassed,mcTotal,1,1,"B");

  dataEfficiencies->SetMaximum(1);
  mcEfficiencies->SetMaximum(1);
  mcEfficiencies->GetYaxis()->SetTitle("Cut Efficiency");

  TH1D* drawHelper = (TH1D*)dataEfficiencies->Clone((info.plotName+"draw_helper").c_str());
  drawHelper->SetMarkerStyle(20);

  TLegend legend(0.725,0.6, 0.925, 0.85);
  legend.AddEntry(drawHelper,"Data","LPE");
  legend.AddEntry(mcEfficiencies,"MC","F");

  TCanvas canvas_efficiencies((info.plotName+"efficiencies").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_efficiencies.SetBottomMargin(0.20);
  mcEfficiencies->GetXaxis()->SetLabelOffset(99);
  dataEfficiencies->GetXaxis()->SetLabelOffset(99);
  drawHelper->GetXaxis()->SetLabelOffset(99);
  mcEfficiencies->Draw("HIST");
  dataEfficiencies->SetLineColor(kBlack);
  dataEfficiencies->Draw("E1SAME");
  drawHelper->Draw("PSAME");
  // draw labels along X
  y = gPad->GetUymin() - 0.01*mcCorrelations->GetYaxis()->GetBinWidth(1);
  t.SetTextAngle(60);
  t.SetTextSize(0.02);
  t.SetTextAlign(33);
  for (unsigned int i=0;i<info.labelList.size();i++) {
    x = mcCorrelations->GetXaxis()->GetBinCenter(i+1);
    t.DrawLatex(x,y,info.labelList[i].c_str());
  }
  legend.Draw();
  pt->Draw();
  
  canvas_efficiencies.SaveAs((info.plotName+"_efficiencies.pdf").c_str());
  canvas_efficiencies.SaveAs((info.plotName+"_efficiencies.png").c_str());
  canvas_efficiencies.SaveAs((info.plotName+"_efficiencies.root").c_str());

  //Add MC Histograms and Create a Scale Factor from untriggered hists (good for any of the hists)
  if(info.aliasx != "")
    {
      
    }
}

void MakeAProfilePlot(information1d info, flavorHists1D hists, double intLumi, int dataVsmc)
{

  THStack mc_stack((info.plotName+"mc_stack").c_str(),info.plotTitle.c_str());
  if(dataVsmc) {
    hists.mc_none_hist->SetLineColor(kMagenta);
    hists.mc_none_hist->SetLineWidth(3);
    hists.mc_none_hist->SetFillStyle(0);
    hists.mc_light_hist->SetLineColor(kBlue);
    hists.mc_light_hist->SetLineWidth(3);
    hists.mc_light_hist->SetFillStyle(0);
    hists.mc_c_hist->SetLineColor(kGreen);
    hists.mc_c_hist->SetLineWidth(3);
    hists.mc_c_hist->SetFillStyle(0);
    hists.mc_b_hist->SetLineColor(kRed);
    hists.mc_b_hist->SetLineWidth(3);
    hists.mc_b_hist->SetFillStyle(0);
    hists.mc_bglusplit_hist->SetLineColor(kOrange);
    hists.mc_bglusplit_hist->SetLineWidth(3);
    hists.mc_bglusplit_hist->SetFillStyle(0);
    hists.mc_all_hist->SetLineColor(kBlack);
  }
  else  {
    hists.mc_all_hist->SetLineColor(kRed);
    hists.mc_all_hist->SetMarkerColor(kRed);
  }
  hists.mc_all_hist->SetLineWidth(3);
  hists.mc_all_hist->SetFillStyle(0);

  if(dataVsmc) {
    if(info.displayNoInfo == true) mc_stack.Add(hists.mc_none_hist);
    mc_stack.Add(hists.mc_light_hist);
    mc_stack.Add(hists.mc_c_hist);
    mc_stack.Add(hists.mc_b_hist);
    mc_stack.Add(hists.mc_bglusplit_hist);
    mc_stack.Add(hists.mc_all_hist);
  }
  else     mc_stack.Add(hists.mc_all_hist);

  hists.data_hist->SetLineColor(kBlack);
  hists.data_hist->SetFillStyle(0);

  TH1D* drawHelper = (TH1D*)hists.data_hist->Clone((info.plotName+"draw_helper").c_str());
  drawHelper->SetMarkerStyle(20);

  //add ratio
  TH1D* ratio = (TH1D*)hists.data_hist->Clone((info.plotName+"ratio").c_str());
  TH1D* ratioMC = (TH1D*)hists.mc_all_hist->Clone((info.plotName+"ratioMC").c_str());
  if(dataVsmc)   ratio->SetTitle((info.plotTitle+": Data to Monte Carlo Simulation Ratio").c_str());  
  else           ratio->SetTitle((info.plotTitle+": Data to Data Ratio").c_str());  
  
  if(info.ratioRebin >=2){
    ratio->Rebin(info.ratioRebin);
    ratioMC->Rebin(info.ratioRebin);
  }

  ratio->Divide(ratioMC);
  ratio->SetMarkerStyle(20);

  TCanvas canvas_ratio((info.plotName+"canvas_ratio").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_ratio.cd();
  if(dataVsmc)     ratio->SetYTitle("Data/Sim ratio");
  else             ratio->SetYTitle("Data/Data ratio");
  ratio->Draw("E1X0");
  cmsPrel(intLumi);
  canvas_ratio.SaveAs((info.plotName+"_ratio.pdf").c_str());
  canvas_ratio.SaveAs((info.plotName+"_ratio.png").c_str());
  canvas_ratio.SaveAs((info.plotName+"_ratio.root").c_str());

  /////////////
  TLegend *legend;
  if(info.legendPosition == true)
    legend = new TLegend(0.725,0.15, 0.925, 0.35); //"bottom right"
  else
    legend = new TLegend(0.725,0.6, 0.925, 0.85); //By default legend is on the "top right" side of the canvas
  legend->AddEntry(drawHelper,"Data","LPE");
  if(dataVsmc) {
    legend->AddEntry(hists.mc_all_hist,"Sim.(total)","L");
    legend->AddEntry(hists.mc_light_hist,"Sim.(light)","L");
    legend->AddEntry(hists.mc_c_hist,"Sim.(charm)","L");
    legend->AddEntry(hists.mc_b_hist,"Sim.(bottom)","L");
    legend->AddEntry(hists.mc_bglusplit_hist,"Sim.(b glusplit)","L");
    if(info.displayNoInfo == true) legend->AddEntry(hists.mc_none_hist,"Sim.(no info)","L");
  }
  else      legend->AddEntry(hists.mc_all_hist,"Data","LPE");
  
  legend->SetBorderSize(0);
  legend->SetFillColor(kWhite);
  legend->SetMargin(0.12);
  legend->SetTextSize(0.035);

  hists.data_hist->GetYaxis()->CenterTitle(1);
  hists.data_hist->GetYaxis()->SetTitleSize( 0.055 );
  hists.data_hist->GetYaxis()->SetTitleOffset( 1.3 );

  //set the Y-axis range for the ratio
  ratio->GetYaxis()->SetRangeUser(info.ratioMin,info.ratioMax);
  ratio->GetYaxis()->CenterTitle(1);
  ratio->GetYaxis()->SetTitleSize( 0.16 );
  ratio->GetYaxis()->SetTitleOffset( 0.425 );
  ratio->GetYaxis()->SetLabelSize( 0.16 );
  ratio->GetYaxis()->SetNdivisions( 505 );

  ratio->GetXaxis()->SetTitleSize( 0.16 );
  ratio->GetXaxis()->SetLabelSize( 0.16 );
  ratio->GetXaxis()->SetTitleOffset( 1 );
  ratio->GetXaxis()->SetLabelOffset( 0.006 );
  ratio->GetXaxis()->SetNdivisions( 510 );
  ratio->GetXaxis()->SetTickLength( ratio->GetXaxis()->GetTickLength() * 3.0 );
  if(dataVsmc) ratio->SetYTitle("Data/Sim");
  else         ratio->SetYTitle("Data/Data");

  TCanvas canvas((info.plotName+"canvas").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas.cd();
  canvas.Divide(1,2,0.01,0.0);
  
  canvas.cd(1);
  gPad->SetPad( 0.0, 0.25, 1.0, 1.0 );
  gPad->SetTopMargin(0.1);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);

  canvas.cd(2);
  gPad->SetPad( 0.0, 0.0,  1.0, 0.25 );
  gPad->SetBottomMargin(0.375);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);
  gPad->SetGridy();
 
  canvas.cd(1);

  if(dataVsmc)   mc_stack.Draw("HISTNOSTACK");
  else           mc_stack.Draw("E1X0");
  drawHelper->Draw("PSAME");
  hists.data_hist->Draw("E1X0SAME");
  legend->Draw();

  cmsProfPrel(intLumi);

  gPad->Update();
  canvas.cd(2);
  ratio->Draw("E1X0");
  gPad->Update();

  canvas.SaveAs((info.plotName+"_Linear.pdf").c_str());
  canvas.SaveAs((info.plotName+"_Linear.png").c_str());
  canvas.SaveAs((info.plotName+"_Linear.root").c_str());

  canvas.Clear();
  canvas.Divide(1,2,0.01,0.0);
  
  canvas.cd(1);
  gPad->SetLogy();
  gPad->SetPad( 0.0, 0.25, 1.0, 1.0 );
  gPad->SetTopMargin(0.1);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);

  canvas.cd(2);
  gPad->SetPad( 0.0, 0.0,  1.0, 0.25 );
  gPad->SetBottomMargin(0.375);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);
  gPad->SetGridy();

  canvas.cd(2);
  ratio->Draw("E1X0");

  canvas.cd(1);

  //  canvas.SetLogy();
  //  hists.data_hist->SetMaximum(max(mc_stack_bDown.GetMaximum(),ymaxdef) * 6.0);
  //  hists.data_hist->SetMinimum(info.yMin);
  if(dataVsmc)   mc_stack.Draw("HISTNOSTACK");
  else           mc_stack.Draw("E1X0");
  drawHelper->Draw("PSAME");
  hists.data_hist->Draw("E1X0SAME");
  legend->Draw();
  cmsProfPrel(intLumi);
  canvas.SaveAs((info.plotName+"_Log.pdf").c_str());
  canvas.SaveAs((info.plotName+"_Log.png").c_str());
  canvas.SaveAs((info.plotName+"_Log.root").c_str());
}

void MakeAEffVsCutPlot(information1d info, flavorHists1D hists, double scale, double intLumi, int dataVsmc)
{
  double dataIntegralError    ;
  double mc_allIntegralError  ;
  
  double dataIntegral     = IntegralAndError(hists.data_hist    , 0,info.nbinsx+1, dataIntegralError);
  double mc_allIntegral   = IntegralAndError(hists.mc_all_hist  , 0,info.nbinsx+1, mc_allIntegralError);

  TH1D *dataEff     = (TH1D*)hists.data_hist->Clone((info.plotName+"dataEff").c_str());
  TH1D *mc_allEff   = (TH1D*)hists.mc_all_hist->Clone((info.plotName+"mc_allEff").c_str());
  
  for(int i=1; i<=info.nbinsx ; i++){
    
    double dataIntEffError    ;
    double mc_allIntEffError  ;
    
    double dataIntEff     = IntegralAndError(dataEff    ,i,info.nbinsx+1, dataIntEffError);
    double mc_allIntEff   = IntegralAndError(mc_allEff  ,i,info.nbinsx+1,   mc_allIntEffError);
    
    double dataEffError = sqrt( (dataIntEffError/dataIntegral)*(dataIntEffError/dataIntegral) 
				+ (dataIntEff*dataIntegralError/(dataIntegral*dataIntegral))*(dataIntEff*dataIntegralError/(dataIntegral*dataIntegral))  );
    double mc_allEffError = sqrt( (mc_allIntEffError/mc_allIntegral)*(mc_allIntEffError/mc_allIntegral) 
				  + (mc_allIntEff*mc_allIntegralError/(mc_allIntegral*mc_allIntegral))*(mc_allIntEff*mc_allIntegralError/(mc_allIntegral*mc_allIntegral))  );
    
    hists.data_hist->SetBinContent    (i, dataIntEff/dataIntegral);
    hists.data_hist->SetBinError      (i, dataEffError);
    hists.mc_all_hist->SetBinContent  (i, mc_allIntEff/mc_allIntegral);
    hists.mc_all_hist->SetBinError    (i, mc_allEffError);
    
  }

  if(dataVsmc) {//dataVsmc
    
    double mc_bIntegralError    ;
    double mc_bglusplitIntegralError    ;
    double mc_cIntegralError    ;
    double mc_lightIntegralError;
    double mc_noneIntegralError ;
    
    double mc_bIntegral     = IntegralAndError(hists.mc_b_hist    , 0,info.nbinsx+1, mc_bIntegralError);
    double mc_bglusplitIntegral     = IntegralAndError(hists.mc_bglusplit_hist    , 0,info.nbinsx+1, mc_bglusplitIntegralError);
    double mc_cIntegral     = IntegralAndError(hists.mc_c_hist    , 0,info.nbinsx+1, mc_cIntegralError);
    double mc_lightIntegral = IntegralAndError(hists.mc_light_hist, 0,info.nbinsx+1, mc_lightIntegralError);
    double mc_noneIntegral  = IntegralAndError(hists.mc_none_hist , 0,info.nbinsx+1,  mc_noneIntegralError);
    
    TH1D *mc_bEff     = (TH1D*)hists.mc_b_hist->Clone((info.plotName+"mc_bEff").c_str());
    TH1D *mc_bglusplitEff     = (TH1D*)hists.mc_bglusplit_hist->Clone((info.plotName+"mc_bglusplitEff").c_str());
    TH1D *mc_cEff     = (TH1D*)hists.mc_c_hist->Clone((info.plotName+"mc_cEff").c_str());
    TH1D *mc_lightEff = (TH1D*)hists.mc_light_hist->Clone((info.plotName+"mc_lightEff").c_str());
    TH1D *mc_noneEff  = (TH1D*)hists.mc_none_hist->Clone((info.plotName+"mc_noneEff").c_str());
    
    for(int i=1; i<=info.nbinsx ; i++){
    
      double mc_bIntEffError    ;
      double mc_bglusplitIntEffError    ;
      double mc_cIntEffError    ;
      double mc_lightIntEffError;
      double mc_noneIntEffError ;
      
      double mc_bIntEff     = IntegralAndError(mc_bEff    ,i,info.nbinsx+1, mc_bIntEffError);
      double mc_bglusplitIntEff     = IntegralAndError(mc_bglusplitEff    ,i,info.nbinsx+1, mc_bglusplitIntEffError);
      double mc_cIntEff     = IntegralAndError(mc_cEff    ,i,info.nbinsx+1, mc_cIntEffError);
      double mc_lightIntEff = IntegralAndError(mc_lightEff,i,info.nbinsx+1, mc_lightIntEffError);
      double mc_noneIntEff  = IntegralAndError(mc_noneEff ,i,info.nbinsx+1,  mc_noneIntEffError);
      
      double mc_bEffError = sqrt( (mc_bIntEffError/mc_bIntegral)*(mc_bIntEffError/mc_bIntegral) 
				  + (mc_bIntEff*mc_bIntegralError/(mc_bIntegral*mc_bIntegral))*(mc_bIntEff*mc_bIntegralError/(mc_bIntegral*mc_bIntegral))  );
      double mc_bglusplitEffError = sqrt( (mc_bglusplitIntEffError/mc_bglusplitIntegral)*(mc_bglusplitIntEffError/mc_bglusplitIntegral) 
				  + (mc_bglusplitIntEff*mc_bglusplitIntegralError/(mc_bglusplitIntegral*mc_bglusplitIntegral))*(mc_bglusplitIntEff*mc_bglusplitIntegralError/(mc_bglusplitIntegral*mc_bglusplitIntegral))  );
      
      double mc_cEffError = sqrt( (mc_cIntEffError/mc_cIntegral)*(mc_cIntEffError/mc_cIntegral) 
				  + (mc_cIntEff*mc_cIntegralError/(mc_cIntegral*mc_cIntegral))*(mc_cIntEff*mc_cIntegralError/(mc_cIntegral*mc_cIntegral))  );
      
      double mc_lightEffError = sqrt( (mc_lightIntEffError/mc_lightIntegral)*(mc_lightIntEffError/mc_lightIntegral) 
				      + (mc_lightIntEff*mc_lightIntegralError/(mc_lightIntegral*mc_lightIntegral))*(mc_lightIntEff*mc_lightIntegralError/(mc_lightIntegral*mc_lightIntegral))  );
      
      double mc_noneEffError = sqrt( (mc_noneIntEffError/mc_noneIntegral)*(mc_noneIntEffError/mc_noneIntegral) 
				     + (mc_noneIntEff*mc_noneIntegralError/(mc_noneIntegral*mc_noneIntegral))*(mc_noneIntEff*mc_noneIntegralError/(mc_noneIntegral*mc_noneIntegral))  );
      
      hists.mc_b_hist->SetBinContent    (i, mc_bIntEff/mc_bIntegral);
      hists.mc_b_hist->SetBinError      (i, mc_bEffError);
      hists.mc_bglusplit_hist->SetBinContent    (i, mc_bglusplitIntEff/mc_bglusplitIntegral);
      hists.mc_bglusplit_hist->SetBinError      (i, mc_bglusplitEffError);
      hists.mc_c_hist->SetBinContent    (i, mc_cIntEff/mc_cIntegral);
      hists.mc_c_hist->SetBinError      (i, mc_cEffError);
      hists.mc_light_hist->SetBinContent    (i, mc_lightIntEff/mc_lightIntegral);
      hists.mc_light_hist->SetBinError      (i, mc_lightEffError);
      hists.mc_none_hist->SetBinContent    (i, mc_noneIntEff/mc_noneIntegral);
      hists.mc_none_hist->SetBinError      (i, mc_noneEffError);
    }
  }//dataVsmc
      
  hists.data_hist    ->GetYaxis()->SetTitle("Efficiency");
  hists.mc_all_hist  ->GetYaxis()->SetTitle("Efficiency");
  if(dataVsmc) {
     hists.mc_b_hist    ->GetYaxis()->SetTitle("Efficiency");
     hists.mc_bglusplit_hist    ->GetYaxis()->SetTitle("Efficiency");
     hists.mc_c_hist    ->GetYaxis()->SetTitle("Efficiency");
     hists.mc_light_hist->GetYaxis()->SetTitle("Efficiency");
     hists.mc_none_hist ->GetYaxis()->SetTitle("Efficiency");
  }

  MakeAProfilePlot(info, hists, intLumi, dataVsmc);

}


void MakeAFlavorPlot(information1d info, flavorHists1D hists, double scale, double intLumi, int dataVsmc)
{

  if(scale==0)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    }    
  if(scale==-1)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral(0,info.nbinsx+1)/hists.mc_all_hist->Integral(0,info.nbinsx+1);
    }      
  hists.mc_all_hist->Scale(scale);
  if(dataVsmc) {//only for data vs mc comparison
    hists.mc_b_hist->Scale(scale);
    hists.mc_bglusplit_hist->Scale(scale);
    hists.mc_c_hist->Scale(scale);
    hists.mc_light_hist->Scale(scale);
    hists.mc_none_hist->Scale(scale);

    hists.mc_none_hist->SetFillColor(kMagenta);
    hists.mc_light_hist->SetFillColor(kBlue);
    hists.mc_c_hist->SetFillColor(kGreen);
    hists.mc_b_hist->SetFillColor(kRed);
    hists.mc_bglusplit_hist->SetFillColor(kOrange);
  }
  hists.mc_all_hist->SetLineColor(kRed);
  hists.mc_all_hist->SetFillColor(kRed);
  hists.mc_all_hist->SetMarkerColor(kRed);
  
  // calculate over and underflow bin if requested
  if(info.displayOverUnderflowBin == true){
    double nBinX=hists.mc_all_hist->GetNbinsX();
    hists.mc_all_hist->SetBinContent(nBinX, hists.mc_all_hist->GetBinContent(nBinX) + hists.mc_all_hist->GetBinContent(nBinX+1));
    hists.mc_all_hist->SetBinContent(1, hists.mc_all_hist->GetBinContent(1) + hists.mc_all_hist->GetBinContent(0));
    if(dataVsmc) {//only for data vs mc comparison
      hists.mc_b_hist->SetBinContent(nBinX, hists.mc_b_hist->GetBinContent(nBinX) + hists.mc_b_hist->GetBinContent(nBinX+1));
      hists.mc_b_hist->SetBinContent(1, hists.mc_b_hist->GetBinContent(1) + hists.mc_b_hist->GetBinContent(0));
      hists.mc_bglusplit_hist->SetBinContent(nBinX, hists.mc_bglusplit_hist->GetBinContent(nBinX) + hists.mc_bglusplit_hist->GetBinContent(nBinX+1));
      hists.mc_bglusplit_hist->SetBinContent(1, hists.mc_bglusplit_hist->GetBinContent(1) + hists.mc_bglusplit_hist->GetBinContent(0));
      hists.mc_c_hist->SetBinContent(nBinX, hists.mc_c_hist->GetBinContent(nBinX) + hists.mc_c_hist->GetBinContent(nBinX+1));
      hists.mc_c_hist->SetBinContent(1, hists.mc_c_hist->GetBinContent(1) + hists.mc_c_hist->GetBinContent(0));
      hists.mc_light_hist->SetBinContent(nBinX, hists.mc_light_hist->GetBinContent(nBinX) + hists.mc_light_hist->GetBinContent(nBinX+1));
      hists.mc_light_hist->SetBinContent(1, hists.mc_light_hist->GetBinContent(1) + hists.mc_light_hist->GetBinContent(0));
      hists.mc_none_hist->SetBinContent(nBinX, hists.mc_none_hist->GetBinContent(nBinX) + hists.mc_none_hist->GetBinContent(nBinX+1));
      hists.mc_none_hist->SetBinContent(1, hists.mc_none_hist->GetBinContent(1) + hists.mc_none_hist->GetBinContent(0));
    }
    hists.data_hist->SetBinContent(nBinX, hists.data_hist->GetBinContent(nBinX) + hists.data_hist->GetBinContent(nBinX+1));
    hists.data_hist->SetBinContent(1, hists.data_hist->GetBinContent(1) + hists.data_hist->GetBinContent(0));
  }

  THStack mc_stack_bUp((info.plotName+"_mc_stack_bUp").c_str(),info.plotTitle.c_str());
  if(dataVsmc) {//only for data vs mc comparison
    if(info.displayNoInfo == true) mc_stack_bUp.Add(hists.mc_none_hist);
    mc_stack_bUp.Add(hists.mc_light_hist);
    mc_stack_bUp.Add(hists.mc_c_hist);
    mc_stack_bUp.Add(hists.mc_bglusplit_hist);
    mc_stack_bUp.Add(hists.mc_b_hist);
  }
  else     mc_stack_bUp.Add(hists.mc_all_hist);

  THStack mc_stack_bDown((info.plotName+"_mc_stack_bDown").c_str(),info.plotTitle.c_str());
  if(dataVsmc) {//only for data vs mc comparison
    mc_stack_bDown.Add(hists.mc_b_hist);
    mc_stack_bDown.Add(hists.mc_bglusplit_hist);
    mc_stack_bDown.Add(hists.mc_c_hist);
    mc_stack_bDown.Add(hists.mc_light_hist);
    if(info.displayNoInfo == true) mc_stack_bDown.Add(hists.mc_none_hist);
  }
  else     mc_stack_bDown.Add(hists.mc_all_hist);
  
  TH1D* drawHelper = (TH1D*)hists.data_hist->Clone((info.plotName+"draw_helper").c_str());
  drawHelper->SetMarkerStyle(20);
  
  TH1D* ratio = (TH1D*)hists.data_hist->Clone((info.plotName+"ratio").c_str());
  TH1D* ratioMC = (TH1D*)hists.mc_all_hist->Clone((info.plotName+"ratioMC").c_str());
  ratio->SetTitle((info.plotTitle+": Data to Monte Carlo Simulation Ratio").c_str());  
  
  if(info.ratioRebin >=2){
    ratio->Rebin(info.ratioRebin);
    ratioMC->Rebin(info.ratioRebin);
  }

  ratio->Divide(ratioMC);
  ratio->SetMarkerStyle(20);

  TLegend *legend;
  if(info.legendPosition == true)
    legend = new TLegend(0.685, 0.575, 0.985, 0.875); // "top right"
  else
    legend = new TLegend(0.195, 0.575, 0.495, 0.875); //By default legend is on the "top left" side of the canvas
  legend->AddEntry(drawHelper,"Data","LPE");
  if(dataVsmc) {//only for data vs mc comparison
    legend->AddEntry(hists.mc_light_hist,"Sim.(light)","F");
    legend->AddEntry(hists.mc_c_hist,"Sim.(charm)","F");
    legend->AddEntry(hists.mc_bglusplit_hist,"Sim.(b glusplit)","F");
    legend->AddEntry(hists.mc_b_hist,"Sim.(bottom)","F");
    if(info.displayNoInfo == true) legend->AddEntry(hists.mc_none_hist,"Sim.(no info)","F");
  }
  else     legend->AddEntry(hists.mc_all_hist,"Data","LPE");

  legend->SetBorderSize(0);
  legend->SetFillColor(kWhite);
  legend->SetMargin(0.12);
  legend->SetTextSize(0.05);

  //store the default value of y-maximum
  double ymaxdef = hists.data_hist->GetMaximum();
  hists.data_hist->GetYaxis()->CenterTitle(1);

  //Make Canvas
  TCanvas canvas_bUp((info.plotName+"canvas_bUp").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_bUp.cd();

  hists.data_hist->SetMaximum(max(mc_stack_bUp.GetMaximum(),ymaxdef) * 1.4);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc) mc_stack_bUp.Draw("HISTSAME");
  else         mc_stack_bUp.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();

  //include the official CMS label
  cmsProfPrel(intLumi);

  canvas_bUp.SaveAs((info.plotName+"_bUp_Linear_noRatio.pdf").c_str());
  canvas_bUp.SaveAs((info.plotName+"_bUp_Linear_noRatio.png").c_str());
  canvas_bUp.SaveAs((info.plotName+"_bUp_Linear_noRatio.root").c_str());
  canvas_bUp.Clear();
  canvas_bUp.SetLogy();

  hists.data_hist->SetMaximum(max(mc_stack_bUp.GetMaximum(),ymaxdef) * 6.0);
  hists.data_hist->SetMinimum(info.yMin);
  hists.data_hist->SetMarkerStyle(1);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc)   mc_stack_bUp.Draw("HISTSAME");
  else           mc_stack_bUp.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();
  cmsProfPrel(intLumi);
  canvas_bUp.SaveAs((info.plotName+"_bUp_Log_noRatio.pdf").c_str());
  canvas_bUp.SaveAs((info.plotName+"_bUp_Log_noRatio.png").c_str());
  canvas_bUp.SaveAs((info.plotName+"_bUp_Log_noRatio.root").c_str());
  hists.data_hist->SetMinimum(0);
  
  TCanvas canvas_bDown((info.plotName+"canvas_bDown").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_bDown.cd();
  hists.data_hist->SetMaximum(max(mc_stack_bDown.GetMaximum(),ymaxdef) * 1.4);
  hists.data_hist->SetMarkerStyle(1);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc)   mc_stack_bDown.Draw("HISTSAME");
  else           mc_stack_bDown.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();

  //include the official CMS label
  cmsProfPrel(intLumi);

  canvas_bDown.SaveAs((info.plotName+"_bDown_Linear_noRatio.pdf").c_str());
  canvas_bDown.SaveAs((info.plotName+"_bDown_Linear_noRatio.png").c_str());
  canvas_bDown.SaveAs((info.plotName+"_bDown_Linear_noRatio.root").c_str());
  canvas_bDown.Clear();
  canvas_bDown.SetLogy();
  hists.data_hist->SetMaximum(max(mc_stack_bDown.GetMaximum(),ymaxdef) * 6.0);
  hists.data_hist->SetMinimum(info.yMin);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc)   mc_stack_bDown.Draw("HISTSAME");
  else           mc_stack_bDown.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();
  cmsProfPrel(intLumi);
  canvas_bDown.SaveAs((info.plotName+"_bDown_Log_noRatio.pdf").c_str());
  canvas_bDown.SaveAs((info.plotName+"_bDown_Log_noRatio.png").c_str());
  canvas_bDown.SaveAs((info.plotName+"_bDown_Log_noRatio.root").c_str());

  TCanvas canvas_ratio((info.plotName+"canvas_ratio").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_ratio.cd();
  if(dataVsmc) ratio->SetYTitle("Data/Sim");
  else         ratio->SetYTitle("Data/Data");
  ratio->Draw("E1X0");
  cmsPrel(intLumi);
  canvas_ratio.SaveAs((info.plotName+"_ratio.pdf").c_str());
  canvas_ratio.SaveAs((info.plotName+"_ratio.png").c_str());
  canvas_ratio.SaveAs((info.plotName+"_ratio.root").c_str());
  
  ////////////////////////////////////////////////////
  // Set the titles, range etc here before drawing
  hists.data_hist->GetYaxis()->CenterTitle(1);
  hists.data_hist->GetYaxis()->SetTitleSize( 0.055 );
  hists.data_hist->GetYaxis()->SetTitleOffset( 1.3 );

  //set the Y-axis range for the ratio
  ratio->GetYaxis()->SetRangeUser(info.ratioMin,info.ratioMax);
  ratio->GetYaxis()->CenterTitle(1);
  ratio->GetYaxis()->SetTitleSize( 0.16 );
  ratio->GetYaxis()->SetTitleOffset( 0.425 );
  ratio->GetYaxis()->SetLabelSize( 0.16 );
  ratio->GetYaxis()->SetNdivisions( 505 );

  ratio->GetXaxis()->SetTitleSize( 0.16 );
  ratio->GetXaxis()->SetLabelSize( 0.16 );
  ratio->GetXaxis()->SetTitleOffset( 1 );
  ratio->GetXaxis()->SetLabelOffset( 0.006 );
  ratio->GetXaxis()->SetNdivisions( 510 );
  ratio->GetXaxis()->SetTickLength( ratio->GetXaxis()->GetTickLength() * 3.0 );
  if(dataVsmc) ratio->SetYTitle("Data/Sim");
  else         ratio->SetYTitle("Data/Data");

  //Draw the plot and ratio on the same canvas
  TCanvas canvas_bDownLin((info.plotName+"canvas_bDownLin").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_bDownLin.cd();
  canvas_bDownLin.Clear();

  canvas_bDownLin.Divide(1,2,0.01,0.0);
  
  canvas_bDownLin.cd(1);
  gPad->SetPad( 0.0, 0.25, 1.0, 1.0 );
  gPad->SetTopMargin(0.1);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);

  canvas_bDownLin.cd(2);
  gPad->SetPad( 0.0, 0.0,  1.0, 0.25 );
  gPad->SetBottomMargin(0.375);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);
  gPad->SetGridy();
 
  canvas_bDownLin.cd(1);
  hists.data_hist->SetMaximum(max(mc_stack_bDown.GetMaximum(),ymaxdef) * 1.4);
  hists.data_hist->SetMinimum(0);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc)   mc_stack_bDown.Draw("HISTSAME");
  else           mc_stack_bDown.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();
  cmsPrel(intLumi);
  gPad->Update();

  canvas_bDownLin.cd(2);
  ratio->Draw("E1X0");
  gPad->Update();

  canvas_bDownLin.SaveAs((info.plotName+"_bDown_Linear.pdf").c_str());
  canvas_bDownLin.SaveAs((info.plotName+"_bDown_Linear.png").c_str());
  canvas_bDownLin.SaveAs((info.plotName+"_bDown_Linear.root").c_str());
  //
  //
  TCanvas canvas_bDownLog((info.plotName+"canvas_bDownLog").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_bDownLog.cd();

  canvas_bDownLog.Divide(1,2,0.01,0.0);
  
  canvas_bDownLog.cd(1);
  gPad->SetLogy();
  gPad->SetPad( 0.0, 0.25, 1.0, 1.0 );
  gPad->SetTopMargin(0.1);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);

  canvas_bDownLog.cd(2);
  gPad->SetPad( 0.0, 0.0,  1.0, 0.25 );
  gPad->SetBottomMargin(0.375);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);
  gPad->SetGridy();

  canvas_bDownLog.cd(2);
  ratio->Draw("E1X0");

  canvas_bDownLog.cd(1);
  hists.data_hist->SetMaximum(max(mc_stack_bDown.GetMaximum(),ymaxdef) * 6.0);
  hists.data_hist->SetMinimum(info.yMin);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc)   mc_stack_bDown.Draw("HISTSAME");
  else           mc_stack_bDown.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();
  cmsPrel(intLumi);

  canvas_bDownLog.SaveAs((info.plotName+"_bDown_Log.pdf").c_str());
  canvas_bDownLog.SaveAs((info.plotName+"_bDown_Log.png").c_str());
  canvas_bDownLog.SaveAs((info.plotName+"_bDown_Log.root").c_str());


  ////////////////////////////////////////
  //Draw the plot and ratio on the same canvas
  TCanvas canvas_bUpLin((info.plotName+"canvas_bUpLin").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_bUpLin.cd();
  canvas_bUpLin.Clear();

  canvas_bUpLin.Divide(1,2,0.01,0.0);
  
  canvas_bUpLin.cd(1);
  gPad->SetPad( 0.0, 0.25, 1.0, 1.0 );
  gPad->SetTopMargin(0.1);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);

  canvas_bUpLin.cd(2);
  gPad->SetPad( 0.0, 0.0,  1.0, 0.25 );
  gPad->SetBottomMargin(0.375);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);
  gPad->SetGridy();
 
  canvas_bUpLin.cd(1);
  hists.data_hist->SetMaximum(max(mc_stack_bUp.GetMaximum(),ymaxdef) * 1.4);
  hists.data_hist->SetMinimum(0);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc)   mc_stack_bUp.Draw("HISTSAME");
  else           mc_stack_bUp.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();
  cmsPrel(intLumi);
  gPad->Update();

  canvas_bUpLin.cd(2);
  ratio->Draw("E1X0");
  gPad->Update();

  canvas_bUpLin.SaveAs((info.plotName+"_bUp_Linear.pdf").c_str());
  canvas_bUpLin.SaveAs((info.plotName+"_bUp_Linear.png").c_str());
  canvas_bUpLin.SaveAs((info.plotName+"_bUp_Linear.root").c_str());
  //
  //
  TCanvas canvas_bUpLog((info.plotName+"canvas_bUpLog").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_bUpLog.cd();

  canvas_bUpLog.Divide(1,2,0.01,0.0);
  
  canvas_bUpLog.cd(1);
  gPad->SetLogy();
  gPad->SetPad( 0.0, 0.25, 1.0, 1.0 );
  gPad->SetTopMargin(0.1);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);

  canvas_bUpLog.cd(2);
  gPad->SetPad( 0.0, 0.0,  1.0, 0.25 );
  gPad->SetBottomMargin(0.375);
  gPad->SetLeftMargin(0.16);
  gPad->SetRightMargin(0.04);
  gPad->SetGridy();

  canvas_bUpLog.cd(2);
  ratio->Draw("E1X0");

  canvas_bUpLog.cd(1);

  hists.data_hist->SetMaximum(max(mc_stack_bUp.GetMaximum(),ymaxdef) * 6.0);
  hists.data_hist->SetMinimum(info.yMin);
  hists.data_hist->Draw("E1X0");
  if(dataVsmc)   mc_stack_bUp.Draw("HISTSAME");
  else           mc_stack_bUp.Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend->Draw();
  cmsPrel(intLumi);

  canvas_bUpLog.SaveAs((info.plotName+"_bUp_Log.pdf").c_str());
  canvas_bUpLog.SaveAs((info.plotName+"_bUp_Log.png").c_str());
  canvas_bUpLog.SaveAs((info.plotName+"_bUp_Log.root").c_str());

  return;
}

void MakeATrackCutPlot(informationTrackCuts info, flavorHists1D hists, double scale, double intLumi, int dataVsmc){
  information1d info1d = get1DInfoFromTrackCut(info);
  
  MakeAFlavorPlot(info1d, hists, scale, intLumi, dataVsmc);
}

void MakeAMuonCutPlot(informationMuonCuts info, flavorHists1D hists, double scale, double intLumi, int dataVsmc){
  information1d info1d = get1DInfoFromMuonCut(info);
  
  MakeAFlavorPlot(info1d, hists, scale, intLumi, dataVsmc);
}

void MakeAPtHatPlot(informationPtHat info, ptHatHists1D hists, double scale)
{
  if(scale==0)
    {
      //assume normalization to data
      double mc_int = 0;
      for(vector<TH1D*>::iterator iPlot = hists.mc_hists.begin();iPlot!=hists.mc_hists.end(); iPlot++)
	  {
	    mc_int+=(*iPlot)->Integral();
	  }
      scale = hists.data_hist->Integral()/mc_int;
    }   
  if(scale==-1)
    {
      double mc_int = 0;
      for(vector<TH1D*>::iterator iPlot = hists.mc_hists.begin();iPlot!=hists.mc_hists.end(); iPlot++)
	  {
	    mc_int+=(*iPlot)->Integral(0,info.nbinsx+1);
	  }
      scale = hists.data_hist->Integral(0,info.nbinsx+1)/mc_int;
    }      

  THStack mc_stack_highUp((info.plotName+"_mc_stack_highUp").c_str(),info.plotTitle.c_str());
  THStack mc_stack_highDown((info.plotName+"_mc_stack_highDown").c_str(),info.plotTitle.c_str());

  TH1D* drawHelper = (TH1D*)hists.data_hist->Clone((info.plotName+"draw_helper").c_str());
  drawHelper->SetMarkerStyle(20);

  TLegend legend(0.725,0.65, 0.925, 0.85);
  legend.AddEntry(drawHelper,"Data","LPE");

  int iColor = 2;
  vector<double>::iterator iPtHat;
  vector<TH1D*>::iterator iPlot;
  for(iPtHat = info.ptHatBins.begin() , iPlot = hists.mc_hists.begin(); (iPtHat+1)!=info.ptHatBins.end()||iPlot!=hists.mc_hists.end(); iPtHat++,iPlot++)
	  {
	    stringstream lowBin;
	    lowBin << *iPtHat;
	    stringstream highBin;
	    highBin << *(iPtHat+1);
	    (*iPlot)->Scale(scale);
	    (*iPlot)->SetFillColor(iColor);
	    iColor++;
	    mc_stack_highUp.Add(*iPlot);	    
	    if(*(iPtHat+1)!=-1) legend.AddEntry(*iPlot,(lowBin.str()+" < pthat < "+highBin.str()).c_str());
	    else legend.AddEntry(*iPlot,(lowBin.str()+" < pthat").c_str());
	  }

  for(vector<TH1D*>::reverse_iterator irPlot = hists.mc_hists.rbegin(); irPlot!=hists.mc_hists.rend(); irPlot++)
	  {
	    mc_stack_highDown.Add(*irPlot);
	  }

  mc_stack_highUp.SetMaximum(max(mc_stack_highUp.GetMaximum(),hists.data_hist->GetMaximum()) * 1.2);
  mc_stack_highDown.SetMaximum(max(mc_stack_highDown.GetMaximum(),hists.data_hist->GetMaximum()) * 1.2);

  legend.SetBorderSize(1);
  legend.SetFillColor(kWhite);
  //legend.SetFillStyle(1);

  TCanvas canvas_highUp((info.plotName+"canvas_highUp").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_highUp.cd();
  mc_stack_highUp.Draw("HIST");
  hists.data_hist->Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend.Draw();
  canvas_highUp.SaveAs((info.plotName+"_highUp_Linear.pdf").c_str());
  canvas_highUp.SaveAs((info.plotName+"_highUp_Linear.png").c_str());
  canvas_highUp.SaveAs((info.plotName+"_highUp_Linear.root").c_str());
  canvas_highUp.Clear();
  canvas_highUp.SetLogy();
  mc_stack_highUp.SetMinimum(0.1);
  hists.data_hist->SetMinimum(0.1);
  hists.data_hist->SetMarkerStyle(1);
  mc_stack_highUp.Draw("HIST");
  hists.data_hist->SetMarkerStyle(1);
  hists.data_hist->Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend.Draw();
  canvas_highUp.SaveAs((info.plotName+"_highUp_Log.pdf").c_str());
  canvas_highUp.SaveAs((info.plotName+"_highUp_Log.png").c_str());
  canvas_highUp.SaveAs((info.plotName+"_highUp_Log.root").c_str());
  hists.data_hist->SetMinimum(0);
  
  TCanvas canvas_highDown((info.plotName+"canvas_highDown").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_highDown.cd();
  mc_stack_highDown.Draw("HIST");
  hists.data_hist->SetMarkerStyle(1);
  hists.data_hist->Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend.Draw();
  canvas_highDown.SaveAs((info.plotName+"_highDown_Linear.pdf").c_str());
  canvas_highDown.SaveAs((info.plotName+"_highDown_Linear.png").c_str());
  canvas_highDown.SaveAs((info.plotName+"_highDown_Linear.root").c_str());
  canvas_highDown.Clear();
  canvas_highDown.SetLogy();
  mc_stack_highDown.SetMinimum(0.1);
  hists.data_hist->SetMinimum(0.1);
  mc_stack_highDown.Draw("HIST");
  hists.data_hist->Draw("E1X0SAME");
  drawHelper->Draw("PSAME");
  legend.Draw();
  canvas_highDown.SaveAs((info.plotName+"_highDown_Log.pdf").c_str());
  canvas_highDown.SaveAs((info.plotName+"_highDown_Log.png").c_str());
  canvas_highDown.SaveAs((info.plotName+"_highDown_Log.root").c_str());

  TCanvas canvas_pthat((info.plotName+"canvas_pthat").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_pthat.cd();
  hists.pthat_hist->SetMarkerStyle(21);
  hists.pthat_hist->Draw();
  canvas_pthat.SaveAs((info.plotName+"_pthat_Linear.pdf").c_str());
  canvas_pthat.SaveAs((info.plotName+"_pthat_Linear.png").c_str());
  canvas_pthat.SaveAs((info.plotName+"_pthat_Linear.root").c_str());
  hists.pthat_hist->SetMinimum(0.1);
  canvas_pthat.Clear();
  canvas_pthat.SetLogy();
  hists.pthat_hist->Draw();
  canvas_pthat.SaveAs((info.plotName+"_pthat_Log.pdf").c_str());
  canvas_pthat.SaveAs((info.plotName+"_pthat_Log.png").c_str());
  canvas_pthat.SaveAs((info.plotName+"_pthat_Log.root").c_str());
  return;
}



void MakeAReweightedPlot(information2d info, flavorHists2D hists, double scale, double intLumi, int dataVsmc)
{
  double finalScale = scale;
  if(scale==0)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    }   
  if(scale==-1)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1)/hists.mc_all_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1);
    }   
  
  hists.mc_all_hist->Scale(scale);
  if(dataVsmc) {
    hists.mc_b_hist->Scale(scale);
    hists.mc_c_hist->Scale(scale);
    hists.mc_light_hist->Scale(scale);
    hists.mc_none_hist->Scale(scale);
  }

  flavorHists1D reweightedHists;
  information1d reweightedInfo;
  reweightedInfo.displayNoInfo = info.displayNoInfo;
  reweightedInfo.plotName = info.plotName;
  reweightedInfo.plotTitle = info.plotTitle;

  reweightedHists.data_hist = hists.data_hist->ProjectionX();
  reweightedHists.mc_all_hist = hists.mc_all_hist->ProjectionX();
  reweightedHists.data_hist->Reset();
  reweightedHists.mc_all_hist->Reset();
  TH1D* data_temp;
  TH1D* mc_all_temp;

  for(int iYbin = 0; iYbin<info.nbinsy+2; iYbin++){
    double tempScale;
    data_temp = hists.data_hist->ProjectionX("data_temp",iYbin,iYbin);
    mc_all_temp = hists.mc_all_hist->ProjectionX("mc_all_temp",iYbin,iYbin);
    if(mc_all_temp->Integral(0,info.nbinsy+1) !=0 ) tempScale = data_temp->Integral(0,info.nbinsy+1)/mc_all_temp->Integral(0,info.nbinsy+1);
    else tempScale = 1;
    mc_all_temp->Scale(tempScale);
    reweightedHists.data_hist->Add(data_temp);
    reweightedHists.mc_all_hist->Add(mc_all_temp);
    delete data_temp;
    delete mc_all_temp;
  }

  if(dataVsmc) {
    reweightedHists.mc_b_hist = hists.mc_b_hist->ProjectionX();
    reweightedHists.mc_c_hist = hists.mc_c_hist->ProjectionX();
    reweightedHists.mc_light_hist = hists.mc_light_hist->ProjectionX();
    reweightedHists.mc_none_hist = hists.mc_none_hist->ProjectionX();
    reweightedHists.mc_b_hist->Reset();
    reweightedHists.mc_c_hist->Reset();
    reweightedHists.mc_light_hist->Reset();
    reweightedHists.mc_none_hist->Reset();  
    TH1D* mc_b_temp;
    TH1D* mc_c_temp;
    TH1D* mc_light_temp;
    TH1D* mc_none_temp;
    
    for(int iYbin = 0; iYbin<info.nbinsy+2; iYbin++){
      mc_b_temp = hists.mc_b_hist->ProjectionX("mc_b_temp",iYbin,iYbin);
      mc_c_temp = hists.mc_c_hist->ProjectionX("mc_c_temp",iYbin,iYbin);
      mc_light_temp = hists.mc_light_hist->ProjectionX("mc_light_temp",iYbin,iYbin);
      mc_none_temp = hists.mc_none_hist->ProjectionX("mc_none_temp",iYbin,iYbin);
      double tempScale;
      if(mc_all_temp->Integral(0,info.nbinsy+1) !=0 ) tempScale = data_temp->Integral(0,info.nbinsy+1)/mc_all_temp->Integral(0,info.nbinsy+1);
      else tempScale = 1;
      mc_b_temp->Scale(tempScale);
      mc_c_temp->Scale(tempScale);
      mc_light_temp->Scale(tempScale);
      mc_none_temp->Scale(tempScale);
      reweightedHists.mc_b_hist->Add(mc_b_temp);
      reweightedHists.mc_c_hist->Add(mc_c_temp);
      reweightedHists.mc_light_hist->Add(mc_light_temp);
      reweightedHists.mc_none_hist->Add(mc_none_temp);
      delete mc_b_temp;
      delete mc_c_temp;
      delete mc_light_temp;
      delete mc_none_temp;
    }
  }
  MakeAFlavorPlot(reweightedInfo,reweightedHists,finalScale, intLumi, dataVsmc);
}

void MakeA2DPlot(information2d info, flavorHists2D hists, double scale, double intLumi, int dataVsmc)
{
  if(scale==0)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    }   
  if(scale==-1)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1)/hists.mc_all_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1);
    }    

  hists.mc_all_hist->Scale(scale);
  if(dataVsmc) {
    hists.mc_b_hist->Scale(scale);
    hists.mc_bglusplit_hist->Scale(scale);
    hists.mc_c_hist->Scale(scale);
    hists.mc_light_hist->Scale(scale);
    hists.mc_none_hist->Scale(scale);
  }

  flavorHists1D profiles;
  information1d profInfo;
  profInfo.displayNoInfo = info.displayNoInfo;
  profInfo.legendPosition = info.legendPosition;

  TProfile* data_prof_x = hists.data_hist->ProfileX();
  TProfile* mc_all_prof_x = hists.mc_all_hist->ProfileX();
  data_prof_x->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
  mc_all_prof_x->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
  data_prof_x->GetYaxis()->SetTitle(info.yTitle.c_str());
  mc_all_prof_x->GetYaxis()->SetTitle(info.yTitle.c_str());
  profiles.data_hist = (TH1D*)data_prof_x;
  profiles.mc_all_hist = (TH1D*)mc_all_prof_x;

  if(dataVsmc) {
    TProfile* mc_b_prof_x = hists.mc_b_hist->ProfileX();
    TProfile* mc_bglusplit_prof_x = hists.mc_bglusplit_hist->ProfileX();
    TProfile* mc_c_prof_x = hists.mc_c_hist->ProfileX();
    TProfile* mc_light_prof_x = hists.mc_light_hist->ProfileX();
    TProfile* mc_none_prof_x = hists.mc_none_hist->ProfileX();
    mc_bglusplit_prof_x->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_b_prof_x->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_c_prof_x->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_light_prof_x->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_none_prof_x->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_b_prof_x->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_bglusplit_prof_x->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_c_prof_x->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_light_prof_x->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_none_prof_x->GetYaxis()->SetTitle(info.yTitle.c_str());
    profiles.mc_b_hist = (TH1D*)mc_b_prof_x;
    profiles.mc_bglusplit_hist = (TH1D*)mc_bglusplit_prof_x;
    profiles.mc_c_hist = (TH1D*)mc_c_prof_x;
    profiles.mc_light_hist = (TH1D*)mc_light_prof_x;
    profiles.mc_none_hist = (TH1D*)mc_none_prof_x;
  }
  
  profInfo.plotName = info.plotName+"_x_profile";
  profInfo.plotTitle = info.plotTitle+" : "+" "+info.xTitle+" Profile";
 
  MakeAProfilePlot(profInfo, profiles, intLumi, dataVsmc);

  TProfile* data_prof_y = hists.data_hist->ProfileY();
  TProfile* mc_all_prof_y = hists.mc_all_hist->ProfileY();
  data_prof_y->SetTitle((info.plotTitle+" : "+" "+info.yTitle+" Profile").c_str());
  mc_all_prof_y->SetTitle((info.plotTitle+" : "+" "+info.yTitle+" Profile").c_str());
  data_prof_y->GetYaxis()->SetTitle(info.xTitle.c_str());
  mc_all_prof_y->GetYaxis()->SetTitle(info.xTitle.c_str());
  profiles.data_hist = (TH1D*)data_prof_y;
  profiles.mc_all_hist = (TH1D*)mc_all_prof_y;

  if(dataVsmc) {
    TProfile* mc_b_prof_y = hists.mc_b_hist->ProfileY();
    TProfile* mc_bglusplit_prof_y = hists.mc_bglusplit_hist->ProfileY();
    TProfile* mc_c_prof_y = hists.mc_c_hist->ProfileY();
    TProfile* mc_light_prof_y = hists.mc_light_hist->ProfileY();
    TProfile* mc_none_prof_y = hists.mc_none_hist->ProfileY();
    mc_b_prof_y->SetTitle((info.plotTitle+" : "+" "+info.yTitle+" Profile").c_str());
    mc_bglusplit_prof_y->SetTitle((info.plotTitle+" : "+" "+info.yTitle+" Profile").c_str());
    mc_c_prof_y->SetTitle((info.plotTitle+" : "+" "+info.yTitle+" Profile").c_str());
    mc_light_prof_y->SetTitle((info.plotTitle+" : "+" "+info.yTitle+" Profile").c_str());
    mc_none_prof_y->SetTitle((info.plotTitle+" : "+" "+info.yTitle+" Profile").c_str());
    mc_b_prof_y->GetYaxis()->SetTitle(info.xTitle.c_str());
    mc_bglusplit_prof_y->GetYaxis()->SetTitle(info.xTitle.c_str());
    mc_c_prof_y->GetYaxis()->SetTitle(info.xTitle.c_str());
    mc_light_prof_y->GetYaxis()->SetTitle(info.xTitle.c_str());
    mc_none_prof_y->GetYaxis()->SetTitle(info.xTitle.c_str());
    profiles.mc_b_hist = (TH1D*)mc_b_prof_y;
    profiles.mc_bglusplit_hist = (TH1D*)mc_bglusplit_prof_y;
    profiles.mc_c_hist = (TH1D*)mc_c_prof_y;
    profiles.mc_light_hist = (TH1D*)mc_light_prof_y;
    profiles.mc_none_hist = (TH1D*)mc_none_prof_y;
  }
  
  profInfo.plotName = info.plotName+"_y_profile";
  profInfo.plotTitle = info.plotTitle+" : "+" "+info.yTitle+" Profile";

  MakeAProfilePlot(profInfo, profiles, intLumi, dataVsmc);

  //Make Canvases

  if(dataVsmc) {
    TCanvas mc_comp((info.plotName+"mc_comp").c_str(),info.plotTitle.c_str(),2048,2048);
    mc_comp.Divide(2,2);
    mc_comp.cd(1);
    hists.mc_b_hist->SetTitle((info.plotTitle+" : True b-jet").c_str());
    hists.mc_b_hist->Draw("colz");
    mc_comp.cd(2);
    hists.mc_c_hist->SetTitle((info.plotTitle+" : True c-jet").c_str());
    hists.mc_c_hist->Draw("colz");
    mc_comp.cd(3);
    hists.mc_light_hist->SetTitle((info.plotTitle+" : True light-jet").c_str());
    hists.mc_light_hist->Draw("colz");
    mc_comp.cd(4);
    hists.mc_none_hist->SetTitle((info.plotTitle+" : No Truth Match").c_str());
    hists.mc_none_hist->Draw("colz");
    string mc_name = info.plotName+"_flavorComp.pdf";
    mc_comp.SaveAs(mc_name.c_str());
    mc_name = info.plotName+"_flavorComp.png";
    mc_comp.SaveAs(mc_name.c_str());
    mc_name = info.plotName+"_flavorComp.root";
    mc_comp.SaveAs(mc_name.c_str());
  }

  TCanvas data_comp((info.plotName+"data_comp").c_str(),info.plotTitle.c_str(),2048,1024);
  data_comp.Divide(2,1);
  data_comp.cd(1);
  if(dataVsmc)   hists.mc_all_hist->SetTitle((info.plotTitle+" : Monte Carlo Simulation").c_str());
  else           hists.mc_all_hist->SetTitle((info.plotTitle+" : Data").c_str());
  hists.mc_all_hist->Draw("colz");
  data_comp.cd(2);
  hists.data_hist->SetTitle((info.plotTitle+" : Data").c_str());
  hists.data_hist->Draw("colz");
  string data_name = info.plotName+"_dataComp.pdf";
  data_comp.SaveAs(data_name.c_str());
  data_name = info.plotName+"_dataComp.png";
  data_comp.SaveAs(data_name.c_str());
  data_name = info.plotName+"_dataComp.root";
  data_comp.SaveAs(data_name.c_str());
  return;
}

void MakeATrackQualityPlot(information1d info, qualityHists1D hists, double scale)
{
  if(scale==0)
    {
      //assume normalization to data
      scale = (hists.data_hist_undef->Integral()+hists.data_hist_loose->Integral()+hists.data_hist_tight->Integral()+hists.data_hist_high_purity->Integral())/(hists.mc_hist_undef->Integral()+hists.mc_hist_loose->Integral()+hists.mc_hist_tight->Integral()+hists.mc_hist_high_purity->Integral());
    }   
  if(scale==-1)
    {
      //assume normalization to data
      scale = (hists.data_hist_undef->Integral(0,info.nbinsx+1)+hists.data_hist_loose->Integral(0,info.nbinsx+1)+hists.data_hist_tight->Integral(0,info.nbinsx+1)+hists.data_hist_high_purity->Integral(0,info.nbinsx+1))/(hists.mc_hist_undef->Integral(0,info.nbinsx+1)+hists.mc_hist_loose->Integral(0,info.nbinsx+1)+hists.mc_hist_tight->Integral(0,info.nbinsx+1)+hists.mc_hist_high_purity->Integral(0,info.nbinsx+1));
    }   
  hists.mc_hist_undef->Scale(scale);
  hists.mc_hist_loose->Scale(scale);
  hists.mc_hist_tight->Scale(scale);
  hists.mc_hist_high_purity->Scale(scale);
  hists.mc_hist_undef->SetFillColor(kCyan);
  hists.mc_hist_loose->SetFillColor(kMagenta);
  hists.mc_hist_tight->SetFillColor(kBlue);
  hists.mc_hist_high_purity->SetFillColor(kRed);

  hists.data_hist_undef->SetMarkerStyle(23);
  hists.data_hist_loose->SetMarkerStyle(22);
  hists.data_hist_tight->SetMarkerStyle(21);
  hists.data_hist_high_purity->SetMarkerStyle(20);

  THStack mc_stack_hpUp((info.plotName+"_mc_stack_hpUp").c_str(),info.plotTitle.c_str());
  mc_stack_hpUp.Add(hists.mc_hist_undef);
  mc_stack_hpUp.Add(hists.mc_hist_loose);
  mc_stack_hpUp.Add(hists.mc_hist_tight);
  mc_stack_hpUp.Add(hists.mc_hist_high_purity);

  THStack mc_stack_hpDown((info.plotName+"_mc_stack_hpDown").c_str(),info.plotTitle.c_str());
  mc_stack_hpDown.Add(hists.mc_hist_high_purity);
  mc_stack_hpDown.Add(hists.mc_hist_tight);
  mc_stack_hpDown.Add(hists.mc_hist_loose);
  mc_stack_hpDown.Add(hists.mc_hist_undef);

  THStack data_stack_hpUp((info.plotName+"_data_stack_hpUp").c_str(),info.plotTitle.c_str());
  data_stack_hpUp.Add(hists.data_hist_undef);
  data_stack_hpUp.Add(hists.data_hist_loose);
  data_stack_hpUp.Add(hists.data_hist_tight);
  data_stack_hpUp.Add(hists.data_hist_high_purity);

  THStack data_stack_hpDown((info.plotName+"_data_stack_hpDown").c_str(),info.plotTitle.c_str());
  data_stack_hpDown.Add(hists.data_hist_high_purity);
  data_stack_hpDown.Add(hists.data_hist_tight);
  data_stack_hpDown.Add(hists.data_hist_loose);
  data_stack_hpDown.Add(hists.data_hist_undef);

  data_stack_hpUp.SetMaximum(max(data_stack_hpUp.GetMaximum(),mc_stack_hpUp.GetMaximum()) * 1.2);
  data_stack_hpDown.SetMaximum(max(data_stack_hpDown.GetMaximum(),mc_stack_hpDown.GetMaximum()) * 1.2);
  mc_stack_hpDown.SetMaximum(max(data_stack_hpDown.GetMaximum(),mc_stack_hpDown.GetMaximum()) * 1.2);
  mc_stack_hpUp.SetMaximum(max(data_stack_hpUp.GetMaximum(),mc_stack_hpUp.GetMaximum()) * 1.2);
  

  //Make Canvas

  TLegend MClegend(0.7,0.7,0.95,0.95);
  MClegend.SetHeader("Monte Carlo Simulation");
  MClegend.AddEntry(hists.mc_hist_high_purity,"High Purity Tracks","F");
  MClegend.AddEntry(hists.mc_hist_tight,"Tight Tracks","F");
  MClegend.AddEntry(hists.mc_hist_loose,"Loose Tracks","F");
  MClegend.AddEntry(hists.mc_hist_undef,"Undefined Tracks","F");

  MClegend.SetBorderSize(1);
  MClegend.SetFillColor(kWhite);

  TLegend datalegend(0.05,0.7,0.3,0.95);
  datalegend.SetHeader("Data");
  datalegend.AddEntry(hists.data_hist_high_purity,"High Purity Tracks","PE");
  datalegend.AddEntry(hists.data_hist_tight,"Tight Tracks","PE");
  datalegend.AddEntry(hists.data_hist_loose,"Loose Tracks","PE");
  datalegend.AddEntry(hists.data_hist_undef,"Undefined Tracks","PE");

  datalegend.SetBorderSize(1);
  datalegend.SetFillColor(kWhite);

  datalegend.SetTextSize(MClegend.GetTextSize());

  TCanvas canvas_hpUp((info.plotName+"canvas_hpUp").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_hpUp.cd();
  mc_stack_hpUp.Draw("HIST");
  mc_stack_hpUp.GetXaxis()->SetTitle(info.xTitle.c_str());
  data_stack_hpUp.Draw("E1X0SAME");
  MClegend.Draw();
  datalegend.Draw();
  canvas_hpUp.SaveAs((info.plotName+"_hpUp_overlay_Linear.pdf").c_str());
  canvas_hpUp.SaveAs((info.plotName+"_hpUp_overlay_Linear.png").c_str());
  canvas_hpUp.SaveAs((info.plotName+"_hpUp_overlay_Linear.root").c_str());
  canvas_hpUp.Clear();
  canvas_hpUp.SetLogy();
  mc_stack_hpUp.SetMinimum(0.1);
  data_stack_hpUp.SetMinimum(0.1);
  mc_stack_hpUp.Draw("HIST");
  mc_stack_hpUp.GetXaxis()->SetTitle(info.xTitle.c_str());
  data_stack_hpUp.Draw("E1X0SAME");
  MClegend.Draw();
  datalegend.Draw();
  canvas_hpUp.SaveAs((info.plotName+"_hpUp_overlay_Log.pdf").c_str());
  canvas_hpUp.SaveAs((info.plotName+"_hpUp_overlay_Log.png").c_str());
  canvas_hpUp.SaveAs((info.plotName+"_hpUp_overlay_Log.root").c_str());
  
  TCanvas canvas_hpDown((info.plotName+"canvas_hpDown").c_str(),info.plotTitle.c_str(),1024,1024);
  canvas_hpDown.cd();
  mc_stack_hpDown.Draw("HIST");
  mc_stack_hpDown.GetXaxis()->SetTitle(info.xTitle.c_str());
  data_stack_hpDown.Draw("E1X0SAME");
  MClegend.Draw();
  datalegend.Draw();
  canvas_hpDown.SaveAs((info.plotName+"_hpDown_overlay_Linear.pdf").c_str());
  canvas_hpDown.SaveAs((info.plotName+"_hpDown_overlay_Linear.png").c_str());
  canvas_hpDown.SaveAs((info.plotName+"_hpDown_overlay_Linear.root").c_str());
  canvas_hpDown.Clear();
  canvas_hpDown.SetLogy();
  mc_stack_hpDown.SetMinimum(0.1);
  data_stack_hpDown.SetMinimum(0.1);
  mc_stack_hpUp.Draw("HIST");
  data_stack_hpDown.Draw("E1X0SAME");
  MClegend.Draw();
  datalegend.Draw();
  canvas_hpUp.SaveAs((info.plotName+"_hpDown_overlay_Log.pdf").c_str());
  canvas_hpUp.SaveAs((info.plotName+"_hpDown_overlay_Log.png").c_str());
  canvas_hpUp.SaveAs((info.plotName+"_hpDown_overlay_Log.root").c_str());

  mc_stack_hpUp.SetMinimum(0);
  data_stack_hpUp.SetMinimum(0);
  mc_stack_hpDown.SetMinimum(0);
  data_stack_hpDown.SetMinimum(0);

  hists.data_hist_undef->SetFillColor(kCyan);
  hists.data_hist_loose->SetFillColor(kMagenta);
  hists.data_hist_tight->SetFillColor(kBlue);
  hists.data_hist_high_purity->SetFillColor(kRed);

  THStack data_stack2_hpUp((info.plotName+"_data_stack2_hpUp").c_str(),info.plotTitle.c_str());
  data_stack2_hpUp.Add(hists.data_hist_undef);
  data_stack2_hpUp.Add(hists.data_hist_loose);
  data_stack2_hpUp.Add(hists.data_hist_tight);
  data_stack2_hpUp.Add(hists.data_hist_high_purity);
  data_stack2_hpUp.SetMaximum(max(data_stack2_hpUp.GetMaximum(),mc_stack_hpUp.GetMaximum()) * 1.2);

  THStack data_stack2_hpDown((info.plotName+"_data_stack2_hpDown").c_str(),info.plotTitle.c_str());
  data_stack2_hpDown.Add(hists.data_hist_high_purity);
  data_stack2_hpDown.Add(hists.data_hist_tight);
  data_stack2_hpDown.Add(hists.data_hist_loose);
  data_stack2_hpDown.Add(hists.data_hist_undef);
  data_stack2_hpDown.SetMaximum(max(data_stack2_hpDown.GetMaximum(),mc_stack_hpDown.GetMaximum()) * 1.2);

  TLegend legend2(0.7,0.7,0.95,0.95);
  legend2.AddEntry(hists.mc_hist_high_purity,"High Purity Tracks","F");
  legend2.AddEntry(hists.mc_hist_tight,"Tight Tracks","F");
  legend2.AddEntry(hists.mc_hist_loose,"Loose Tracks","F");
  legend2.AddEntry(hists.mc_hist_undef,"Undefined Tracks","F");

  legend2.SetBorderSize(1);
  legend2.SetFillColor(kWhite);

  mc_stack_hpDown.SetTitle((info.plotTitle+" : Monte Carlo Simulation").c_str());
  data_stack2_hpDown.SetTitle((info.plotTitle+" : Data").c_str());
  mc_stack_hpUp.SetTitle((info.plotTitle+" : Monte Carlo Simulation").c_str());
  data_stack2_hpUp.SetTitle((info.plotTitle+" : Data").c_str());

  TCanvas canvasTwo_hpUp((info.plotName+"canvasTwo_hpUp").c_str(),info.plotTitle.c_str(),2048,1024);
  canvasTwo_hpUp.Divide(2,1);
  canvasTwo_hpUp.cd(1);
  data_stack2_hpUp.Draw("HIST");
  data_stack2_hpUp.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpUp.cd(2);
  mc_stack_hpUp.Draw("HIST");
  mc_stack_hpUp.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpUp.SaveAs((info.plotName+"_hpUp_Linear.pdf").c_str());
  canvasTwo_hpUp.SaveAs((info.plotName+"_hpUp_Linear.png").c_str());
  canvasTwo_hpUp.SaveAs((info.plotName+"_hpUp_Linear.root").c_str());
  canvasTwo_hpUp.Clear();
  mc_stack_hpUp.SetMinimum(0.1);
  data_stack2_hpUp.SetMinimum(0.1);
  canvasTwo_hpUp.Divide(2,1);
  canvasTwo_hpUp.GetPad(1)->SetLogy();
  canvasTwo_hpUp.GetPad(2)->SetLogy();
  canvasTwo_hpUp.cd(1);
  data_stack2_hpUp.Draw("HIST");
  data_stack2_hpUp.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpUp.cd(2);
  mc_stack_hpUp.Draw("HIST");
  mc_stack_hpUp.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpUp.SaveAs((info.plotName+"_hpUp_Log.pdf").c_str());
  canvasTwo_hpUp.SaveAs((info.plotName+"_hpUp_Log.png").c_str());
  canvasTwo_hpUp.SaveAs((info.plotName+"_hpUp_Log.root").c_str());

  TCanvas canvasTwo_hpDown((info.plotName+"canvasTwo_hpDown").c_str(),info.plotTitle.c_str(),2048,1024);
  canvasTwo_hpDown.Divide(2,1);
  canvasTwo_hpDown.cd(1);
  data_stack2_hpDown.Draw("HIST");
  data_stack2_hpDown.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpDown.cd(2);
  mc_stack_hpDown.Draw("HIST");
  mc_stack_hpDown.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpDown.SaveAs((info.plotName+"_hpDown_Linear.pdf").c_str());
  canvasTwo_hpDown.SaveAs((info.plotName+"_hpDown_Linear.png").c_str());
  canvasTwo_hpDown.SaveAs((info.plotName+"_hpDown_Linear.root").c_str());
  canvasTwo_hpDown.Clear();
  mc_stack_hpDown.SetMinimum(0.1);
  data_stack2_hpDown.SetMinimum(0.1);
  canvasTwo_hpDown.Divide(2,1);
  canvasTwo_hpDown.GetPad(1)->SetLogy();
  canvasTwo_hpDown.GetPad(2)->SetLogy();
  canvasTwo_hpDown.cd(1);
  data_stack2_hpDown.Draw("HIST");
  data_stack2_hpDown.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpDown.cd(2);
  mc_stack_hpDown.Draw("HIST");
  mc_stack_hpDown.GetXaxis()->SetTitle(info.xTitle.c_str());
  legend2.Draw();
  canvasTwo_hpDown.SaveAs((info.plotName+"_hpDown_Log.pdf").c_str());
  canvasTwo_hpDown.SaveAs((info.plotName+"_hpDown_Log.png").c_str());
  canvasTwo_hpDown.SaveAs((info.plotName+"_hpDown_Log.root").c_str());
  
  return;
}

void MakeAJetTrackQualityPlot(informationQuality info, qualityHists1D hists, double scale)
{
  information1d helperQuality;
  helperQuality.plotName = info.plotName;
  helperQuality.plotTitle = info.plotTitle;
  helperQuality.xTitle = info.xTitle;
  MakeATrackQualityPlot(helperQuality,hists,scale);
}

void MakeACutPlot(informationCut info, flavorHists2D hists, double scale, double intLumi, int dataVsmc)
{
  //Turn 2D Plot into Integral Plot:
  TH2D* data_int = (TH2D*)hists.data_hist->Clone((info.plotName+"_data_int").c_str());
  TH2D* mc_all_int = (TH2D*)hists.mc_all_hist->Clone((info.plotName+"_mc_all_int").c_str());

  vector<double> error2_data(info.nbinsy+2,0);
  vector<double> error2_mc_all(info.nbinsy+2,0);

  if(info.direction.find("greaterThan")!=string::npos)
    {
      for(int iXbin = 0; iXbin<info.nbinsx+2; iXbin++){
	for(int iYbin = 0; iYbin<info.nbinsy+2; iYbin++){
	  data_int->SetBinContent(info.nbinsx+1-iXbin,iYbin,hists.data_hist->Integral(info.nbinsx+1-iXbin,info.nbinsx+1,iYbin,iYbin));
	  error2_data[iYbin]+=pow(hists.data_hist->GetBinError(info.nbinsx+1-iXbin,iYbin),2);
	  data_int->SetBinError(info.nbinsx+1-iXbin,iYbin,sqrt(error2_data[iYbin]));

	  mc_all_int->SetBinContent(info.nbinsx+1-iXbin,iYbin,hists.mc_all_hist->Integral(info.nbinsx+1-iXbin,info.nbinsx+1,iYbin,iYbin));
	  error2_data[iYbin]+=pow(hists.mc_all_hist->GetBinError(info.nbinsx+1-iXbin,iYbin),2);
	  mc_all_int->SetBinError(info.nbinsx+1-iXbin,iYbin,sqrt(error2_data[iYbin]));
	}
      }
    }

  if(info.direction.find("lessThan")!=string::npos)
    {
      for(int iXbin = 0; iXbin<info.nbinsx+2; iXbin++){
	for(int iYbin = 0; iYbin<info.nbinsy+2; iYbin++){
	  data_int->SetBinContent(iXbin,iYbin,hists.data_hist->Integral(0,iXbin,iYbin,iYbin));
	  error2_data[iYbin]+=pow(hists.data_hist->GetBinError(iXbin,iYbin),2);
	  data_int->SetBinError(iXbin,iYbin,sqrt(error2_data[iYbin]));

	  mc_all_int->SetBinContent(iXbin,iYbin,hists.mc_all_hist->Integral(0,iXbin,iYbin,iYbin));
	  error2_data[iYbin]+=pow(hists.mc_all_hist->GetBinError(iXbin,iYbin),2);
	  mc_all_int->SetBinError(iXbin,iYbin,sqrt(error2_data[iYbin]));

	}
      }
    }

  if(scale==0)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    }   
  if(scale==-1)
    {
      //assume normalization to data
      scale = hists.data_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1)/hists.mc_all_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1);
    }    

  mc_all_int->Scale(scale);
  
  flavorHists1D profiles;
  information1d profInfo;
  profInfo.displayNoInfo = info.displayNoInfo;
  profInfo.legendPosition = info.legendPosition;

  TProfile* data_prof = data_int->ProfileX();
  TProfile* mc_all_prof = mc_all_int->ProfileX();
  data_prof->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
  mc_all_prof->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
  data_prof->GetYaxis()->SetTitle(info.yTitle.c_str());
  mc_all_prof->GetYaxis()->SetTitle(info.yTitle.c_str());
  profiles.data_hist = (TH1D*)data_prof;
  profiles.mc_all_hist = (TH1D*)mc_all_prof;


  if(dataVsmc) {//dataVsmc comparison
    TH2D* mc_b_int = (TH2D*)hists.mc_all_hist->Clone((info.plotName+"_mc_b_int").c_str());
    TH2D* mc_bglusplit_int = (TH2D*)hists.mc_all_hist->Clone((info.plotName+"_mc_bglusplit_int").c_str());
    TH2D* mc_c_int = (TH2D*)hists.mc_all_hist->Clone((info.plotName+"_mc_c_int").c_str());
    TH2D* mc_light_int = (TH2D*)hists.mc_all_hist->Clone((info.plotName+"_mc_light_int").c_str());
    TH2D* mc_none_int = (TH2D*)hists.mc_all_hist->Clone((info.plotName+"_mc_none_int").c_str());
    
    vector<double> error2_mc_b(info.nbinsy+2,0);
    vector<double> error2_mc_bglusplit(info.nbinsy+2,0);
    vector<double> error2_mc_c(info.nbinsy+2,0);
    vector<double> error2_mc_light(info.nbinsy+2,0);
    vector<double> error2_mc_none(info.nbinsy+2,0);

    if(info.direction.find("greaterThan")!=string::npos)
      {
	for(int iXbin = 0; iXbin<info.nbinsx+2; iXbin++){
	  for(int iYbin = 0; iYbin<info.nbinsy+2; iYbin++){
	    mc_b_int->SetBinContent(info.nbinsx+1-iXbin,iYbin,hists.mc_b_hist->Integral(info.nbinsx+1-iXbin,info.nbinsx+1,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_b_hist->GetBinError(info.nbinsx+1-iXbin,iYbin),2);
	    mc_b_int->SetBinError(info.nbinsx+1-iXbin,iYbin,sqrt(error2_data[iYbin]));

	    mc_bglusplit_int->SetBinContent(info.nbinsx+1-iXbin,iYbin,hists.mc_bglusplit_hist->Integral(info.nbinsx+1-iXbin,info.nbinsx+1,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_bglusplit_hist->GetBinError(info.nbinsx+1-iXbin,iYbin),2);
	    mc_bglusplit_int->SetBinError(info.nbinsx+1-iXbin,iYbin,sqrt(error2_data[iYbin]));
	    
	    mc_c_int->SetBinContent(info.nbinsx+1-iXbin,iYbin,hists.mc_c_hist->Integral(info.nbinsx+1-iXbin,info.nbinsx+1,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_c_hist->GetBinError(info.nbinsx+1-iXbin,iYbin),2);
	    mc_c_int->SetBinError(info.nbinsx+1-iXbin,iYbin,sqrt(error2_data[iYbin]));
	    
	    mc_light_int->SetBinContent(info.nbinsx+1-iXbin,iYbin,hists.mc_light_hist->Integral(info.nbinsx+1-iXbin,info.nbinsx+1,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_light_hist->GetBinError(info.nbinsx+1-iXbin,iYbin),2);
	    mc_light_int->SetBinError(info.nbinsx+1-iXbin,iYbin,sqrt(error2_data[iYbin]));
	    
	    mc_none_int->SetBinContent(info.nbinsx+1-iXbin,iYbin,hists.mc_none_hist->Integral(info.nbinsx+1-iXbin,info.nbinsx+1,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_none_hist->GetBinError(info.nbinsx+1-iXbin,iYbin),2);
	    mc_none_int->SetBinError(info.nbinsx+1-iXbin,iYbin,sqrt(error2_data[iYbin]));
	  }
	}
      }
    
    if(info.direction.find("lessThan")!=string::npos)
      {
	for(int iXbin = 0; iXbin<info.nbinsx+2; iXbin++){
	  for(int iYbin = 0; iYbin<info.nbinsy+2; iYbin++){
	    
	    mc_b_int->SetBinContent(iXbin,iYbin,hists.mc_b_hist->Integral(0,iXbin,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_b_hist->GetBinError(iXbin,iYbin),2);
	    mc_b_int->SetBinError(iXbin,iYbin,sqrt(error2_data[iYbin]));

	    mc_bglusplit_int->SetBinContent(iXbin,iYbin,hists.mc_bglusplit_hist->Integral(0,iXbin,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_bglusplit_hist->GetBinError(iXbin,iYbin),2);
	    mc_bglusplit_int->SetBinError(iXbin,iYbin,sqrt(error2_data[iYbin]));
	    
	    mc_c_int->SetBinContent(iXbin,iYbin,hists.mc_c_hist->Integral(0,iXbin,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_c_hist->GetBinError(iXbin,iYbin),2);
	    mc_c_int->SetBinError(iXbin,iYbin,sqrt(error2_data[iYbin]));
	    
	    mc_light_int->SetBinContent(iXbin,iYbin,hists.mc_light_hist->Integral(0,iXbin,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_light_hist->GetBinError(iXbin,iYbin),2);
	    mc_light_int->SetBinError(iXbin,iYbin,sqrt(error2_data[iYbin]));
	    
	    mc_none_int->SetBinContent(iXbin,iYbin,hists.mc_none_hist->Integral(0,iXbin,iYbin,iYbin));
	    error2_data[iYbin]+=pow(hists.mc_none_hist->GetBinError(iXbin,iYbin),2);
	    mc_none_int->SetBinError(iXbin,iYbin,sqrt(error2_data[iYbin]));
	  }
	}
      }
    
    mc_all_int->Add(mc_b_int);
    mc_all_int->Add(mc_bglusplit_int);
    mc_all_int->Add(mc_c_int);
    mc_all_int->Add(mc_light_int);
    mc_all_int->Add(mc_none_int);
  
    hists.mc_all_hist->Add(hists.mc_b_hist);
    hists.mc_all_hist->Add(hists.mc_bglusplit_hist);
    hists.mc_all_hist->Add(hists.mc_c_hist);
    hists.mc_all_hist->Add(hists.mc_light_hist);
    hists.mc_all_hist->Add(hists.mc_none_hist);

    //assume normalization to data
    if(scale==0) scale = hists.data_hist->Integral()/hists.mc_all_hist->Integral();
    //assume normalization to data
    if(scale==-1)  scale = hists.data_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1)/hists.mc_all_hist->Integral(0,info.nbinsx+1,0,info.nbinsy+1);

    mc_b_int->Scale(scale);
    mc_bglusplit_int->Scale(scale);
    mc_c_int->Scale(scale);
    mc_light_int->Scale(scale);
    mc_none_int->Scale(scale);


    TProfile* mc_b_prof = mc_b_int->ProfileX();
    TProfile* mc_bglusplit_prof = mc_bglusplit_int->ProfileX();
    TProfile* mc_c_prof = mc_c_int->ProfileX();
    TProfile* mc_light_prof = mc_light_int->ProfileX();
    TProfile* mc_none_prof = mc_none_int->ProfileX();
    mc_b_prof->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_bglusplit_prof->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_c_prof->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_light_prof->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_none_prof->SetTitle((info.plotTitle+" : "+" "+info.xTitle+" Profile").c_str());
    mc_b_prof->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_bglusplit_prof->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_c_prof->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_light_prof->GetYaxis()->SetTitle(info.yTitle.c_str());
    mc_none_prof->GetYaxis()->SetTitle(info.yTitle.c_str());
    profiles.mc_b_hist = (TH1D*)mc_b_prof;
    profiles.mc_bglusplit_hist = (TH1D*)mc_bglusplit_prof;
    profiles.mc_c_hist = (TH1D*)mc_c_prof;
    profiles.mc_light_hist = (TH1D*)mc_light_prof;
    profiles.mc_none_hist = (TH1D*)mc_none_prof;
  
    //Make Canvases
    TCanvas mc_comp((info.plotName+"mc_comp").c_str(),info.plotTitle.c_str(),2048,2048);
    mc_comp.Divide(2,2);
    mc_comp.cd(1);
    mc_b_int->SetTitle((info.plotTitle+" : True b-jet").c_str());
    mc_b_int->Draw("colz");
    mc_comp.cd(2);
    mc_c_int->SetTitle((info.plotTitle+" : True c-jet").c_str());
    mc_c_int->Draw("colz");
    mc_comp.cd(3);
    mc_light_int->SetTitle((info.plotTitle+" : True light-jet").c_str());
    mc_light_int->Draw("colz");
    mc_comp.cd(4);
    mc_none_int->SetTitle((info.plotTitle+" : No Truth Match").c_str());
    mc_none_int->Draw("colz");
    string mc_name = info.plotName+"_flavorComp.pdf";
    mc_comp.SaveAs(mc_name.c_str());
    mc_name = info.plotName+"_flavorComp.png";
    mc_comp.SaveAs(mc_name.c_str());
    mc_name = info.plotName+"_flavorComp.root";
    mc_comp.SaveAs(mc_name.c_str());
  }

  profInfo.plotName = info.plotName+"_profile";
  profInfo.plotTitle = info.plotTitle+" : "+info.xTitle+" Profile";

  MakeAProfilePlot(profInfo, profiles, intLumi, dataVsmc);
  
  TCanvas data_comp((info.plotName+"data_comp").c_str(),info.plotTitle.c_str(),2048,1024);
  data_comp.cd(1);
  data_comp.Divide(2,1);
  if(dataVsmc)  mc_all_int->SetTitle((info.plotTitle+" : Monte Carlo Simulation").c_str());
  else          mc_all_int->SetTitle((info.plotTitle+" : Data").c_str());
  mc_all_int->Draw("colz");
  data_comp.cd(2);
  data_int->SetTitle((info.plotTitle+" : Data").c_str());
  data_int->Draw("colz");
  string data_name = info.plotName+"_dataComp.pdf";
  data_comp.SaveAs(data_name.c_str());
  data_name = info.plotName+"_dataComp.png";
  data_comp.SaveAs(data_name.c_str());
  data_name = info.plotName+"_dataComp.root";
  data_comp.SaveAs(data_name.c_str());
  return;
}

void MakeATrackQualityHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, information1d info, qualityHists1D hists)
{
  string undefCut,looseCut,tightCut,highPurityCut;
  undefCut = "("+info.label+"trackQuality==-1)";
  looseCut = "("+info.label+"trackQuality==0)";
  tightCut = "("+info.label+"trackQuality==1)";
  highPurityCut = "("+info.label+"trackQuality==2)";
  if(info.cut!="")
    {
      undefCut = "("+info.cut+")&&"+undefCut;
      looseCut = "("+info.cut+")&&"+looseCut;
      tightCut = "("+info.cut+")&&"+tightCut;
      highPurityCut = "("+info.cut+")&&"+highPurityCut;
    }
  //Fill Histograms
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_undef->GetName()),(undefCut));
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_loose->GetName()),(looseCut));
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_tight->GetName()),(tightCut));
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_high_purity->GetName()),(highPurityCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_undef->GetName()),(undefCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_loose->GetName()),(looseCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_tight->GetName()),(tightCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_high_purity->GetName()),(highPurityCut));
  return;
}

void MakeAJetTrackQualityHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, informationQuality info, qualityHists1D hists)
{
  string undefCut,looseCut,tightCut,highPurityCut;
  undefCut = "("+info.qualityVar+"==-1)";
  looseCut = "("+info.qualityVar+"==0)";
  tightCut = "("+info.qualityVar+"==1)";
  highPurityCut = "("+info.qualityVar+"==2)";

  if(info.cut!="")
    {
      undefCut = "("+info.cut+")&&"+undefCut;
      looseCut = "("+info.cut+")&&"+looseCut;
      tightCut = "("+info.cut+")&&"+tightCut;
      highPurityCut = "("+info.cut+")&&"+highPurityCut;
    }
  //Fill Histograms
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_undef->GetName()),(undefCut));
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_loose->GetName()),(looseCut));
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_tight->GetName()),(tightCut));
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_hist_high_purity->GetName()),(highPurityCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_undef->GetName()),(undefCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_loose->GetName()),(looseCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_tight->GetName()),(tightCut));
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist_high_purity->GetName()),(highPurityCut));
  return;
}

void MakeATrackHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, information1d info, flavorHists1D hists, int dataVsmc)
{
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist->GetName()),(info.cut));
  if(dataVsmc) {
    string bcut,bglusplitcut, ccut,lightcut,nonecut;
    bcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==5 && isGluonSplitting==0)";
    bglusplitcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==5 && isGluonSplitting==1)";
    ccut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==4)";
    lightcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==1 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==2 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==3 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==21)";
    nonecut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==0)";
    if(info.cut!="")  
      {
	bcut = "("+info.cut+")&&"+bcut;
	bglusplitcut = "("+info.cut+")&&"+bglusplitcut;
	ccut = "("+info.cut+")&&"+ccut;
	lightcut ="("+info.cut+")&&"+lightcut;
	nonecut ="("+info.cut+")&&"+nonecut;
      }      
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_b_hist->GetName()),(bcut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_bglusplit_hist->GetName()),(bglusplitcut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_c_hist->GetName()),(ccut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_light_hist->GetName()),(lightcut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_none_hist->GetName()),(nonecut));
  }
  else      mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_all_hist->GetName()),(info.cut));
  return;
}

void MakeAHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, information1d info, flavorHists1D hists, int dataVsmc)
{
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist->GetName()),(info.cut));
  if(dataVsmc) {//only for data vs mc comparison
    string bcut,bglusplitcut, ccut,lightcut,nonecut;
    bcut = "("+info.label+"MCTrueFlavor==5 && isGluonSplitting==0)";
    bglusplitcut = "("+info.label+"MCTrueFlavor==5 && isGluonSplitting==1)";
    ccut = "("+info.label+"MCTrueFlavor==4)";
    lightcut = "("+info.label+"MCTrueFlavor==1 ||"+info.label+"MCTrueFlavor==2 ||"+info.label+"MCTrueFlavor==3 ||"+info.label+"MCTrueFlavor==21)";
    nonecut = "("+info.label+"MCTrueFlavor==0)";     
    if(info.cut!="")  
      {
	bcut = "("+info.cut+")&&"+bcut;
	bglusplitcut = "("+info.cut+")&&"+bglusplitcut;
	ccut = "("+info.cut+")&&"+ccut;
	lightcut ="("+info.cut+")&&"+lightcut;
	nonecut ="("+info.cut+")&&"+nonecut;
      }
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_b_hist->GetName()),(bcut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_bglusplit_hist->GetName()),(bglusplitcut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_c_hist->GetName()),(ccut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_light_hist->GetName()),(lightcut));
    mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_none_hist->GetName()),(nonecut));
  }
  else     mcSelector->LoadVariables((info.aliasx+">>+"+hists.mc_all_hist->GetName()),(info.cut));
  return;
}


void MakeATrackCutHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, informationTrackCuts info, flavorHists1D hists, int dataVsmc)
{
  dataSelector->AddTrackSelector(true,  hists.data_hist, hists.mc_b_hist, hists.mc_bglusplit_hist, hists.mc_c_hist, hists.mc_light_hist, hists.mc_none_hist, info);

  if(dataVsmc) mcSelector->  AddTrackSelector(false, hists.data_hist, hists.mc_b_hist, hists.mc_bglusplit_hist, hists.mc_c_hist, hists.mc_light_hist, hists.mc_none_hist, info);
  else         mcSelector->  AddTrackSelector(true, hists.data_hist, hists.mc_b_hist, hists.mc_bglusplit_hist, hists.mc_c_hist, hists.mc_light_hist, hists.mc_none_hist, info);

  return;
}

void MakeAMuonCutHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, informationMuonCuts info, flavorHists1D hists, int dataVsmc)
{
  dataSelector->AddMuonSelector(true,  hists.data_hist, hists.mc_b_hist, hists.mc_bglusplit_hist, hists.mc_c_hist, hists.mc_light_hist, hists.mc_none_hist, info);
  if(dataVsmc) mcSelector->  AddMuonSelector(false, hists.data_hist, hists.mc_b_hist, hists.mc_bglusplit_hist, hists.mc_c_hist, hists.mc_light_hist, hists.mc_none_hist, info);
  else         mcSelector->  AddMuonSelector(true, hists.data_hist, hists.mc_b_hist, hists.mc_bglusplit_hist, hists.mc_c_hist, hists.mc_light_hist, hists.mc_none_hist, info);

  return;
}


void MakeACutCompHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, informationCutComp info, cutCompHists hists)
{
  stringstream binaryBinningStream;
  for(int i = 0; i<info.cutList.size(); i++)
    {
      int binaryBinner = pow(2,i);
      binaryBinningStream << binaryBinner << "*("<< info.cutList[i] <<")";
      if(i<info.labelList.size()-1) binaryBinningStream <<"+";
    }
  dataSelector->LoadVariables((binaryBinningStream.str()+">>+"+hists.CutCompInfo_data->GetName()),(info.cut));
  mcSelector->LoadVariables((binaryBinningStream.str()+">>+"+hists.CutCompInfo_mc->GetName()),(info.cut));
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
  if(info.aliasx != "")
    {
      cout <<"test"<<endl;
      for(unsigned int i = 0; i<info.cutList.size(); i++)
	{
	  dataSelector->LoadVariables((info.cutList[i]+":"+info.aliasx+">>+"+hists.hists_mc_b[i]->GetName()),(info.cut));
	  mcSelector->LoadVariables((info.cutList[i]+":"+info.aliasx+">>+"+hists.hists_mc_b[i]->GetName()),(bcut));
	  mcSelector->LoadVariables((info.cutList[i]+":"+info.aliasx+">>+"+hists.hists_mc_c[i]->GetName()),(ccut));
	  mcSelector->LoadVariables((info.cutList[i]+":"+info.aliasx+">>+"+hists.hists_mc_light[i]->GetName()),(lightcut));
	  mcSelector->LoadVariables((info.cutList[i]+":"+info.aliasx+">>+"+hists.hists_mc_none[i]->GetName()),(nonecut));
	}
    }
  return;
}

void MakeAPtHatHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, informationPtHat info, ptHatHists1D hists)
{
  dataSelector->LoadVariables((info.aliasx+">>+"+hists.data_hist->GetName()),(info.cut));
  vector<double>::iterator iPtHat; 
  vector<TH1D*>::iterator iPlot;
  for(iPtHat = info.ptHatBins.begin() , iPlot = hists.mc_hists.begin(); (iPtHat+1)!=info.ptHatBins.end()||iPlot!=hists.mc_hists.end(); iPtHat++,iPlot++)
    {
      stringstream lowBin;
      lowBin << *iPtHat;
      stringstream highBin;
      highBin << *(iPtHat+1);
      string cut = "("+info.label+"pthat>"+lowBin.str();
      if(*(iPtHat+1) != -1) cut = cut+"&&"+info.label+"pthat<"+highBin.str()+")";
      else cut = cut+")";
      if(info.cut!="") cut = "("+info.cut+")&&"+cut;
      mcSelector->LoadVariables((info.aliasx+">>+"+(*iPlot)->GetName()),(cut));
     }
  string cut ="";
  if(info.pthatCut!="") cut =info.pthatCut;
  mcSelector->LoadVariables((info.aliasx+">>+"+hists.pthat_hist->GetName()),(cut));
  return;
}

void MakeA2DHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, information2d info,flavorHists2D hists,int dataVsmc)
{
  dataSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.data_hist->GetName()),(info.cut));
  if(dataVsmc) {//only for data vs mc comparison
    string bcut,bglusplitcut, ccut,lightcut,nonecut;
    bcut = "("+info.label+"MCTrueFlavor==5 && isGluonSplitting==0)";
    bglusplitcut = "("+info.label+"MCTrueFlavor==5 && isGluonSplitting==1)";
    ccut = "("+info.label+"MCTrueFlavor==4)";
    lightcut = "("+info.label+"MCTrueFlavor==1 ||"+info.label+"MCTrueFlavor==2 ||"+info.label+"MCTrueFlavor==3 ||"+info.label+"MCTrueFlavor==21)";
    nonecut = "("+info.label+"MCTrueFlavor==0)";
    if(info.cut!="")  
      {
	bcut = "("+info.cut+")&&"+bcut;
	bglusplitcut = "("+info.cut+")&&"+bglusplitcut;
	ccut = "("+info.cut+")&&"+ccut;
	lightcut ="("+info.cut+")&&"+lightcut;
	nonecut ="("+info.cut+")&&"+nonecut;
      }
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_b_hist->GetName()),(bcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_bglusplit_hist->GetName()),(bglusplitcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_c_hist->GetName()),(ccut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_light_hist->GetName()),(lightcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_none_hist->GetName()),(nonecut));
  }
  else     mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_all_hist->GetName()),(info.cut));
  return;
}

void MakeA2DTrackHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector,  information2d info, flavorHists2D hists,int dataVsmc)
{
  dataSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.data_hist->GetName()),(info.cut));
  if(dataVsmc) {//only for data vs mc comparison
    string bcut,bglusplitcut, ccut,lightcut,nonecut;
    bcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==5 && isGluonSplitting==0)";
    bglusplitcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==5 && isGluonSplitting==1)";
    ccut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==4)";
    lightcut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==1 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==2 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==3 ||"+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==21)";
    nonecut = "("+info.label+"MCTrueFlavor["+info.label+"trackJetIndex[Iteration$]]==0)";
    if(info.cut!="")  
      {
	bcut = "("+info.cut+")&&"+bcut;
	bglusplitcut = "("+info.cut+")&&"+bglusplitcut;
	ccut = "("+info.cut+")&&"+ccut;
	lightcut ="("+info.cut+")&&"+lightcut;
	nonecut ="("+info.cut+")&&"+nonecut;
      }      
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_b_hist->GetName()),(bcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_bglusplit_hist->GetName()),(bglusplitcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_c_hist->GetName()),(ccut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_light_hist->GetName()),(lightcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_none_hist->GetName()),(nonecut));
  }
  else     mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_all_hist->GetName()),(info.cut));
  return;
}

void MakeACutHist(TSelectorMultiDraw* mcSelector, TSelectorMultiDraw* dataSelector, informationCut info,flavorHists2D hists, int dataVsmc)
{
  dataSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.data_hist->GetName()),(info.cut));
  if(dataVsmc) {//only for data vs mc comparison
    string bcut,bglusplitcut, ccut,lightcut,nonecut;
    bcut = "("+info.label+"MCTrueFlavor==5 && isGluonSplitting==0)";
    bglusplitcut = "("+info.label+"MCTrueFlavor==5 && isGluonSplitting==1)";
    ccut = "("+info.label+"MCTrueFlavor==4)";
    lightcut = "("+info.label+"MCTrueFlavor==1 ||"+info.label+"MCTrueFlavor==2 ||"+info.label+"MCTrueFlavor==3 ||"+info.label+"MCTrueFlavor==21)";
    nonecut = "("+info.label+"MCTrueFlavor==0)";
    if(info.cut!="")  
      {
	bcut = "("+info.cut+")&&"+bcut;
	bglusplitcut = "("+info.cut+")&&"+bglusplitcut;
	ccut = "("+info.cut+")&&"+ccut;
	lightcut ="("+info.cut+")&&"+lightcut;
	nonecut ="("+info.cut+")&&"+nonecut;
      }
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_b_hist->GetName()),(bcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_bglusplit_hist->GetName()),(bglusplitcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_c_hist->GetName()),(ccut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_light_hist->GetName()),(lightcut));
    mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_none_hist->GetName()),(nonecut));
  }
  else     mcSelector->LoadVariables((info.aliasy+":"+info.aliasx+">>+"+hists.mc_all_hist->GetName()),(info.cut));
  return;
}

void MakeAllPlots(string mcfilename, string datafilename, string plotfilename, double finalNorm=-1, string rootFile="plots.root", double intLumi=2.8, int dataVsmc=1, string doPlot="", int firstPlot=0, int lastPlot=0)
{

  TFile* theFile = TFile::Open(rootFile.c_str(),"RECREATE");

  const Int_t NRGBs = 5;
  const Int_t NCont = 255;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);

  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetPadColor(kWhite);
  gStyle->SetStatBorderSize(1);
  gStyle->SetStatColor(kWhite);
  gStyle->SetTitleFillColor(0);
  gStyle->SetFrameFillColor(10);
  gStyle->SetCanvasColor(kWhite); 
  //  gStyle->SetMarkerStyle(6);
  //  gStyle->SetMarkerSize(1);
  gStyle->SetMarkerColor(1);
  gStyle->SetOptStat(000000000);
  gStyle->SetOptTitle(kFALSE);

  setTDRStyle();
  ifstream mcFiles;
  mcFiles.open(mcfilename.c_str());
  ifstream dataFiles;
  dataFiles.open(datafilename.c_str());
  ifstream plotFiles;
  plotFiles.open(plotfilename.c_str());

  list<pair<string,double> > mcList;
  list<pair<string,double> > dataList;


  while (! mcFiles.eof()) {
    string line;
    getline (mcFiles,line);
    if (line.find("#")==0) continue;
    size_t position = line.find(",");
    if(position == string::npos) continue;
    string thisFileName = line.substr(0,position);
    double thisWeight = atof(line.substr(position+1).c_str());
    mcList.push_back(pair<string,double>(thisFileName,thisWeight));
  }
  while (! dataFiles.eof()) {
    string line;
    getline (dataFiles,line);
    if (line.find("#")==0) continue;
    size_t position = line.find(",");
    if(position == string::npos) continue;
    string thisFileName = line.substr(0,position);
    double thisWeight = atof(line.substr(position+1).c_str());
    dataList.push_back(pair<string,double>(thisFileName,thisWeight));
  }


  information1d defaultInformation1d;
  information2d defaultInformation2d;
  informationCut defaultInformationCut;
  informationQuality defaultInformationQuality;
  informationPtHat defaultInformationPtHat;
  informationCutComp defaultInformationCutComp;

  list< pair< information1d , flavorHists1D > > jetPlots1D;
  list< pair< information1d , flavorHists1D > > trackPlots_flavorStack;
  list< pair< information1d , qualityHists1D > > trackPlots_qualityStack;
  list< pair< information2d , flavorHists2D > > jetPlots2D;
  list< pair< informationCut , flavorHists2D > > cutPlots;
  list< pair< information1d , flavorHists1D > > effVsCutPlots;
  list< pair< informationQuality , qualityHists1D > > jetTrackQualityPlots;
  list< pair< informationPtHat , ptHatHists1D > > ptHatPlots;
  list< pair< information2d , flavorHists2D > > reweightedPlots;
  list< pair< information2d , flavorHists2D > > reweightedTrackPlots;
  list< pair< informationCutComp , cutCompHists > > cutCompPlots;
  list< pair< informationTrackCuts , flavorHists1D > > trackCutPlots;
  list< pair< informationMuonCuts , flavorHists1D > > muonCutPlots;

  //  TString normalizationText = "";
  //  if(finalNorm<=0) normalizationText = "MC normalized to Data";
  //  else normalizationText = "normalized to Luminosity";

  int plotCounter=0;
  while (! plotFiles.eof()) {

    string line;
    getline (plotFiles,line);
    if (line.find("#")==0) continue;
    if (line.find("default1d")!=string::npos) defaultInformation1d = param1d(&plotFiles,defaultInformation1d);
    if (line.find("default2d")!=string::npos) defaultInformation2d = param2d(&plotFiles,defaultInformation2d);
    if (line.find("defaultCut")!=string::npos) defaultInformationCut = paramCut(&plotFiles,defaultInformationCut);
    if (line.find("defaultQuality")!=string::npos) defaultInformationQuality = paramQuality(&plotFiles,defaultInformationQuality);
    if (line.find("defaultPtHat")!=string::npos) defaultInformationPtHat = paramPtHat(&plotFiles,defaultInformationPtHat);
    if (line.find("defaultTriggerComp")!=string::npos) defaultInformationCutComp = paramCutComp(&plotFiles,defaultInformationCutComp);
    if(line.find("plot_type")==string::npos) continue;
    
    // found plot type increase plot counter
    plotCounter++;
    // check if plot is in the range of plots to be plotted
    if(firstPlot <=0 && lastPlot <=0) {}// no plot selection continue as usual
    else if( plotCounter < firstPlot || plotCounter > lastPlot ) continue; // skip plot if it is outside of range 

    size_t typePosition = line.find("=");
    string plotType = line.substr(typePosition+1);
    if(  plotType.find("jetPlots1D")!=string::npos ){
      information1d thisPlot = param1d(&plotFiles,defaultInformation1d);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists1D theseHists;
	theseHists.data_hist = new TH1D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_all_hist = new TH1D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH1D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_bglusplit_hist = new TH1D((thisPlot.plotName+"_mc_bglusplit_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_c_hist = new TH1D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_light_hist = new TH1D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_none_hist = new TH1D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_bglusplit_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_bglusplit_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	jetPlots1D.push_back(pair<information1d,flavorHists1D>(thisPlot,theseHists));
      }
    }

  if(  plotType.find("trackCutPlot")!=string::npos){
      informationTrackCuts thisPlot = paramTrackCuts(&plotFiles);
      information1d thisPlot1d = get1DInfoFromTrackCut(thisPlot);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists1D theseHists;
	theseHists.data_hist = new TH1D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_all_hist = new TH1D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH1D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_bglusplit_hist = new TH1D((thisPlot.plotName+"_mc_bglusplit_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_c_hist = new TH1D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_light_hist = new TH1D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_none_hist = new TH1D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_bglusplit_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_bglusplit_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_bglusplit_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	trackCutPlots.push_back(pair<informationTrackCuts,flavorHists1D>(thisPlot,theseHists));
      }
    }

  if(  plotType.find("muonCutPlot")!=string::npos){
      informationMuonCuts thisPlot = paramMuonCuts(&plotFiles);
      information1d thisPlot1d = get1DInfoFromMuonCut(thisPlot);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists1D theseHists;
	theseHists.data_hist = new TH1D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_all_hist = new TH1D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH1D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_bglusplit_hist = new TH1D((thisPlot.plotName+"_mc_bglusplit_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_c_hist = new TH1D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_light_hist = new TH1D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_none_hist = new TH1D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_bglusplit_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_bglusplit_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	muonCutPlots.push_back(pair<informationMuonCuts,flavorHists1D>(thisPlot,theseHists));
      }
    }


    if(plotType.find("cutCompPlots")!=string::npos){
      informationCutComp thisPlot = paramCutComp(&plotFiles,defaultInformationCutComp);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	cutCompHists theseHists;
	theseHists.CutCompInfo_data = new TH1D((thisPlot.plotName+"_CutCompInfo_data").c_str(),thisPlot.plotTitle.c_str(),pow(2,thisPlot.cutList.size())-1,0.5,pow(2,thisPlot.cutList.size())-0.5);
	theseHists.CutCompInfo_data->Sumw2();
	theseHists.CutCompInfo_mc = new TH1D((thisPlot.plotName+"_CutCompInfo_mc").c_str(),thisPlot.plotTitle.c_str(),pow(2,thisPlot.cutList.size())-1,0.5,pow(2,thisPlot.cutList.size())-0.5);
	theseHists.CutCompInfo_mc->Sumw2();
	if(thisPlot.aliasx != "")
	  {
	    for(unsigned int i = 0; i<thisPlot.labelList.size(); i++)
	      {
		stringstream nPlot;
		nPlot << i;
		TH2D* thisPlotPointer = new TH2D((thisPlot.plotName+"_"+nPlot.str()+"_data").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,2,0,1);
		thisPlotPointer->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
		thisPlotPointer->Sumw2();
		theseHists.hists_data.push_back(thisPlotPointer);
		thisPlotPointer = new TH2D((thisPlot.plotName+"_"+nPlot.str()+"_mc_all").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,2,0,1);
		thisPlotPointer->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
		thisPlotPointer->Sumw2();
		theseHists.hists_mc_all.push_back(thisPlotPointer);
		thisPlotPointer = new TH2D((thisPlot.plotName+"_"+nPlot.str()+"_mc_b").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,2,0,1);
		thisPlotPointer->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
		thisPlotPointer->Sumw2();
		theseHists.hists_mc_b.push_back(thisPlotPointer);
		thisPlotPointer = new TH2D((thisPlot.plotName+"_"+nPlot.str()+"_mc_c").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,2,0,1);
		thisPlotPointer->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
		thisPlotPointer->Sumw2();
		theseHists.hists_mc_c.push_back(thisPlotPointer);
		thisPlotPointer = new TH2D((thisPlot.plotName+"_"+nPlot.str()+"_mc_light").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,2,0,1);
		thisPlotPointer->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
		thisPlotPointer->Sumw2();
		theseHists.hists_mc_light.push_back(thisPlotPointer);
		thisPlotPointer = new TH2D((thisPlot.plotName+"_"+nPlot.str()+"_mc_none").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,2,0,1);
		thisPlotPointer->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
		thisPlotPointer->Sumw2();
		theseHists.hists_mc_none.push_back(thisPlotPointer);
	      }
	  }
	cutCompPlots.push_back(pair<informationCutComp,cutCompHists>(thisPlot,theseHists));
      }
    }
    if(plotType.find("ptHatPlots")!=string::npos){
      informationPtHat thisPlot = paramPtHat(&plotFiles,defaultInformationPtHat);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	ptHatHists1D theseHists;
	for(vector<double>::iterator iPlot = thisPlot.ptHatBins.begin(); (iPlot+1)!=thisPlot.ptHatBins.end(); iPlot++)
	  {
	    stringstream lowBin;
	    lowBin << *iPlot;
	    stringstream highBin;
	    highBin << *(iPlot+1);
	    TH1D* thisPlotPointer = new TH1D(((thisPlot.plotName+"_mc_hist_"+lowBin.str()+"_"+highBin.str()).c_str()),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	    thisPlotPointer->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	    thisPlotPointer->Sumw2();
	    theseHists.mc_hists.push_back(thisPlotPointer);
	  }
	theseHists.data_hist = new TH1D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.pthat_hist = new TH1D((thisPlot.plotName+"_pthat_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinspthat,thisPlot.pthatlow,thisPlot.pthatup);
	theseHists.pthat_hist->GetXaxis()->SetTitle("p_{T} hat");
	theseHists.pthat_hist->Sumw2();
        ptHatPlots.push_back(pair<informationPtHat,ptHatHists1D>(thisPlot,theseHists));
      }
    }
   if(plotType.find("jetTrackQualityPlots")!=string::npos){
      informationQuality thisPlot = paramQuality(&plotFiles,defaultInformationQuality);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	qualityHists1D theseHists;
	theseHists.data_hist_undef = new TH1D((thisPlot.plotName+"_data_hist_undef").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_loose = new TH1D((thisPlot.plotName+"_data_hist_loose").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_tight = new TH1D((thisPlot.plotName+"_data_hist_tight").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_high_purity = new TH1D((thisPlot.plotName+"_data_hist_high_purity").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_undef = new TH1D((thisPlot.plotName+"_mc_hist_undef").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_loose = new TH1D((thisPlot.plotName+"_mc_hist_loose").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_tight = new TH1D((thisPlot.plotName+"_mc_hist_tight").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_high_purity = new TH1D((thisPlot.plotName+"_mc_hist_high_purity").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_undef->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist_loose->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist_tight->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist_high_purity->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_undef->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_loose->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_tight->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_high_purity->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist_undef->Sumw2();
	theseHists.data_hist_loose->Sumw2();
	theseHists.data_hist_tight->Sumw2();
	theseHists.data_hist_high_purity->Sumw2();
	theseHists.mc_hist_undef->Sumw2();
	theseHists.mc_hist_loose->Sumw2();
	theseHists.mc_hist_tight->Sumw2();
	theseHists.mc_hist_high_purity->Sumw2();
	jetTrackQualityPlots.push_back(pair<informationQuality,qualityHists1D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("jetPlots2D")!=string::npos){
      information2d thisPlot = param2d(&plotFiles,defaultInformation2d);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists2D theseHists;
	theseHists.data_hist = new TH2D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_all_hist = new TH2D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH2D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_bglusplit_hist = new TH2D((thisPlot.plotName+"_mc_bglusplit_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_c_hist = new TH2D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_light_hist = new TH2D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_none_hist = new TH2D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_bglusplit_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	jetPlots2D.push_back(pair<information2d,flavorHists2D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("reweightedPlot")!=string::npos){
      information2d thisPlot = param2d(&plotFiles,defaultInformation2d);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists2D theseHists;
	theseHists.data_hist = new TH2D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_all_hist = new TH2D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH2D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_c_hist = new TH2D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_light_hist = new TH2D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_none_hist = new TH2D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle(thisPlot.yTitle.c_str() );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle(thisPlot.yTitle.c_str()  );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle(thisPlot.yTitle.c_str()  );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	reweightedPlots.push_back(pair<information2d,flavorHists2D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("reweightedTrackPlot")!=string::npos){
      information2d thisPlot = param2d(&plotFiles,defaultInformation2d);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists2D theseHists;
	theseHists.data_hist = new TH2D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_all_hist = new TH2D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH2D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_c_hist = new TH2D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_light_hist = new TH2D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_none_hist = new TH2D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	reweightedTrackPlots.push_back(pair<information2d,flavorHists2D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("cutPlots")!=string::npos){
      informationCut thisPlot = paramCut(&plotFiles,defaultInformationCut);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists2D theseHists;
	theseHists.data_hist = new TH2D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.mc_all_hist = new TH2D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH2D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_bglusplit_hist = new TH2D((thisPlot.plotName+"_mc_bglusplit_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_c_hist = new TH2D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_light_hist = new TH2D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_none_hist = new TH2D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup,thisPlot.nbinsy,thisPlot.ylow,thisPlot.yup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_bglusplit_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	cutPlots.push_back(pair<informationCut,flavorHists2D>(thisPlot,theseHists));
      }
    }
    if(  plotType.find("effVsCutPlot")!=string::npos ){
      information1d thisPlot = param1d(&plotFiles,defaultInformation1d);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists1D theseHists;
	theseHists.data_hist = new TH1D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_all_hist = new TH1D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH1D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_bglusplit_hist = new TH1D((thisPlot.plotName+"_mc_bglusplit_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_c_hist = new TH1D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_light_hist = new TH1D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_none_hist = new TH1D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_bglusplit_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str()  );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_bglusplit_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	effVsCutPlots.push_back(pair<information1d,flavorHists1D>(thisPlot,theseHists));
      }
    }

    if(plotType.find("trackPlots_flavorStack")!=string::npos){
      information1d thisPlot = param1d(&plotFiles,defaultInformation1d);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	flavorHists1D theseHists;
	theseHists.data_hist = new TH1D((thisPlot.plotName+"_data_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_all_hist = new TH1D((thisPlot.plotName+"_mc_all_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_all_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.mc_all_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	theseHists.data_hist->Sumw2();
	theseHists.mc_all_hist->Sumw2();
	if(dataVsmc) {//define only for data vs mc comparison
	  theseHists.mc_b_hist = new TH1D((thisPlot.plotName+"_mc_b_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_bglusplit_hist = new TH1D((thisPlot.plotName+"_mc_bglusplit_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_c_hist = new TH1D((thisPlot.plotName+"_mc_c_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_light_hist = new TH1D((thisPlot.plotName+"_mc_light_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_none_hist = new TH1D((thisPlot.plotName+"_mc_none_hist").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	  theseHists.mc_b_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_c_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_light_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_none_hist->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	  theseHists.mc_b_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_bglusplit_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_c_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_light_hist->GetYaxis()->SetTitle(thisPlot.yTitle.c_str() );
	  theseHists.mc_none_hist->GetYaxis()->SetTitle( thisPlot.yTitle.c_str() );
	  theseHists.mc_b_hist->Sumw2();
	  theseHists.mc_bglusplit_hist->Sumw2();
	  theseHists.mc_c_hist->Sumw2();
	  theseHists.mc_light_hist->Sumw2();
	  theseHists.mc_none_hist->Sumw2();
	}
	trackPlots_flavorStack.push_back(pair<information1d,flavorHists1D>(thisPlot,theseHists));
      }
    }
    if(plotType.find("trackPlots_qualityStack")!=string::npos){
      information1d thisPlot = param1d(&plotFiles,defaultInformation1d);
      if(doPlot == "" || doPlot.find(thisPlot.plotName)!=string::npos){
	qualityHists1D theseHists;
	theseHists.data_hist_undef = new TH1D((thisPlot.plotName+"_data_hist_undef").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_loose = new TH1D((thisPlot.plotName+"_data_hist_loose").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_tight = new TH1D((thisPlot.plotName+"_data_hist_tight").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_high_purity = new TH1D((thisPlot.plotName+"_data_hist_high_purity").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_undef = new TH1D((thisPlot.plotName+"_mc_hist_undef").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_loose = new TH1D((thisPlot.plotName+"_mc_hist_loose").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_tight = new TH1D((thisPlot.plotName+"_mc_hist_tight").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.mc_hist_high_purity = new TH1D((thisPlot.plotName+"_mc_hist_high_purity").c_str(),thisPlot.plotTitle.c_str(),thisPlot.nbinsx,thisPlot.xlow,thisPlot.xup);
	theseHists.data_hist_undef->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist_loose->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist_tight->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.data_hist_high_purity->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_undef->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_loose->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_tight->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
	theseHists.mc_hist_high_purity->GetXaxis()->SetTitle( thisPlot.xTitle.c_str() );
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

  TSelectorMultiDraw* mcSelector = new TSelectorMultiDraw();
  TSelectorMultiDraw* dataSelector = new TSelectorMultiDraw();

 
  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = jetPlots1D.begin(); iPlot != jetPlots1D.end(); iPlot++)
    {
      MakeAHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< informationTrackCuts , flavorHists1D > >::iterator iPlot = trackCutPlots.begin(); iPlot != trackCutPlots.end(); iPlot++)
    {
      MakeATrackCutHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< informationMuonCuts , flavorHists1D > >::iterator iPlot = muonCutPlots.begin(); iPlot != muonCutPlots.end(); iPlot++)
    {
      MakeAMuonCutHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair<informationCutComp , cutCompHists> >::iterator iPlot = cutCompPlots.begin(); iPlot != cutCompPlots.end(); iPlot++)
    {
      MakeACutCompHist(mcSelector,dataSelector,iPlot->first,iPlot->second);
    }
  for(list< pair< informationPtHat , ptHatHists1D > >::iterator iPlot = ptHatPlots.begin(); iPlot != ptHatPlots.end(); iPlot++)
    {
      MakeAPtHatHist(mcSelector,dataSelector,iPlot->first,iPlot->second);
    }
  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = trackPlots_flavorStack.begin(); iPlot != trackPlots_flavorStack.end(); iPlot++)
    {
      MakeATrackHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< information1d , qualityHists1D > >::iterator iPlot = trackPlots_qualityStack.begin(); iPlot != trackPlots_qualityStack.end(); iPlot++)
    {
      MakeATrackQualityHist(mcSelector,dataSelector,iPlot->first,iPlot->second);
    }
  for(list< pair< information2d , flavorHists2D > >::iterator iPlot = jetPlots2D.begin(); iPlot != jetPlots2D.end(); iPlot++)
    {
      MakeA2DHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< information2d , flavorHists2D > >::iterator iPlot = reweightedPlots.begin(); iPlot != reweightedPlots.end(); iPlot++)
    {   
      MakeA2DHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< information2d , flavorHists2D > >::iterator iPlot = reweightedTrackPlots.begin(); iPlot != reweightedTrackPlots.end(); iPlot++)
    {	  
      MakeA2DTrackHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< informationCut , flavorHists2D > >::iterator iPlot = cutPlots.begin(); iPlot != cutPlots.end(); iPlot++)
    {
      MakeACutHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = effVsCutPlots.begin(); iPlot != effVsCutPlots.end(); iPlot++)
    {
      MakeAHist(mcSelector,dataSelector,iPlot->first,iPlot->second,dataVsmc);
    }
  for(list< pair< informationQuality , qualityHists1D > >::iterator iPlot = jetTrackQualityPlots.begin(); iPlot != jetTrackQualityPlots.end(); iPlot++)
    {
      MakeAJetTrackQualityHist(mcSelector,dataSelector,iPlot->first,iPlot->second);
    }
  
  // setup selector arrays after everything is created
  mcSelector->SetupArrays();
  dataSelector->SetupArrays();
  

  for(list<pair<string,double> >::iterator iFile = mcList.begin(); iFile != mcList.end(); iFile++)
    {  
      std::cout<<"opening file " << iFile->first << std::endl;
      TFile* thisFile = TFile::Open((iFile->first).c_str());
      TTree* thisTree = (TTree*)thisFile->Get("t");
      thisTree->SetWeight(iFile->second);
      Long64_t nentries = thisTree->GetEntries();
      gDirectory->cd((rootFile+":/").c_str());
      thisTree->Process(mcSelector,"goff",nentries,0);
      thisFile->Close("r");
      //delete thisFile;
    }


  for(list<pair<string,double> >::iterator iFile = dataList.begin(); iFile != dataList.end(); iFile++)
    {
      std::cout<<"opening file " << iFile->first << std::endl;
      TFile* thisFile = TFile::Open((iFile->first).c_str());
      TTree* thisTree = (TTree*)thisFile->Get("t");
      thisTree->SetWeight(iFile->second);
      Long64_t nentries = thisTree->GetEntries();
      gDirectory->cd((rootFile+":/").c_str());
      thisTree->Process(dataSelector,"goff",nentries,0);
      thisFile->Close("r");
      //delete thisFile;
    }

  theFile->cd();

  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = jetPlots1D.begin(); iPlot != jetPlots1D.end(); iPlot++)
    {
      if(dataVsmc) {//only for data vs mc comparison
	// apply the flavor re scaling
	iPlot->second.mc_b_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_bglusplit_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_c_hist->Scale( iPlot->first.cScale );
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_bglusplit_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      }
      MakeAFlavorPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }

  for(list< pair< informationTrackCuts , flavorHists1D > >::iterator iPlot = trackCutPlots.begin(); iPlot != trackCutPlots.end(); iPlot++)
    {
      if(dataVsmc) {//only for data vs mc comparison      
	// apply the flavor re scaling
	iPlot->second.mc_b_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_bglusplit_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_c_hist->Scale( iPlot->first.cScale );
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_bglusplit_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      }
      MakeATrackCutPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }

  for(list< pair< informationMuonCuts , flavorHists1D > >::iterator iPlot = muonCutPlots.begin(); iPlot != muonCutPlots.end(); iPlot++)
    {
      if(dataVsmc) {//only for data vs mc comparison
	// apply the flavor re scaling
	iPlot->second.mc_b_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_bglusplit_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_c_hist->Scale( iPlot->first.cScale );
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_bglusplit_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      }
      MakeAMuonCutPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }

  for(list< pair<informationCutComp , cutCompHists> >::iterator iPlot = cutCompPlots.begin(); iPlot != cutCompPlots.end(); iPlot++)
    {
      MakeACutCompPlot(iPlot->first,iPlot->second);
    }
  for(list< pair< informationPtHat , ptHatHists1D > >::iterator iPlot = ptHatPlots.begin(); iPlot != ptHatPlots.end(); iPlot++)
    {
      MakeAPtHatPlot(iPlot->first,iPlot->second,finalNorm);
    }
  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = trackPlots_flavorStack.begin(); iPlot != trackPlots_flavorStack.end(); iPlot++)
    {
      if(dataVsmc) {//only for data vs mc comparison
	// apply the flavor re scaling
	iPlot->second.mc_b_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_bglusplit_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_c_hist->Scale( iPlot->first.cScale );
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_bglusplit_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      }
      MakeAFlavorPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }
  for(list< pair< information1d , qualityHists1D > >::iterator iPlot = trackPlots_qualityStack.begin(); iPlot != trackPlots_qualityStack.end(); iPlot++)
    {
      MakeATrackQualityPlot(iPlot->first,iPlot->second,finalNorm);
    }
  for(list< pair< information2d , flavorHists2D > >::iterator iPlot = jetPlots2D.begin(); iPlot != jetPlots2D.end(); iPlot++)
    {
      if(dataVsmc) {//only for data vs mc comparison
	// apply the flavor re scaling
	iPlot->second.mc_b_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_bglusplit_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_c_hist->Scale( iPlot->first.cScale );
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_bglusplit_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      }
      MakeA2DPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }
  for(list< pair< information2d , flavorHists2D > >::iterator iPlot = reweightedPlots.begin(); iPlot != reweightedPlots.end(); iPlot++)
    {
      if(dataVsmc) {//only for data vs mc comparison
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      }
      MakeAReweightedPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }
  for(list< pair< information2d , flavorHists2D > >::iterator iPlot = reweightedTrackPlots.begin(); iPlot != reweightedTrackPlots.end(); iPlot++)
    {
      iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
      iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
      iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
      iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      MakeAReweightedPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }
  for(list< pair< informationCut , flavorHists2D > >::iterator iPlot = cutPlots.begin(); iPlot != cutPlots.end(); iPlot++)
    {
      MakeACutPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }

  for(list< pair< information1d , flavorHists1D > >::iterator iPlot = effVsCutPlots.begin(); iPlot != effVsCutPlots.end(); iPlot++)
    {
      if(dataVsmc) {//only for data vs mc comparison
	// apply the flavor re scaling
	iPlot->second.mc_b_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_bglusplit_hist->Scale( iPlot->first.bScale );
	iPlot->second.mc_c_hist->Scale( iPlot->first.cScale );
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_b_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_bglusplit_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_c_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_light_hist);
	iPlot->second.mc_all_hist->Add(iPlot->second.mc_none_hist);
      }
      MakeAEffVsCutPlot(iPlot->first,iPlot->second,finalNorm, intLumi, dataVsmc);
    }

  for(list< pair< informationQuality , qualityHists1D > >::iterator iPlot = jetTrackQualityPlots.begin(); iPlot != jetTrackQualityPlots.end(); iPlot++)
    {
      MakeAJetTrackQualityPlot(iPlot->first,iPlot->second,finalNorm);
    }

  return;
}


information1d get1DInfoFromTrackCut(informationTrackCuts info){

  information1d info1d;
  info1d.plotName                 = info.plotName                ;
  info1d.plotTitle		  = info.plotTitle               ;
  info1d.label			  = info.label                   ;
  info1d.aliasx			  = info.aliasx                  ;
  info1d.xTitle			  = info.xTitle                  ;
  info1d.cut			  = info.cut                     ;
  info1d.bScale			  = info.bScale                     ;
  info1d.cScale			  = info.cScale                     ;
  info1d.xlow			  = info.xlow                    ;
  info1d.xup			  = info.xup                     ;
  info1d.nbinsx			  = info.nbinsx                  ;
  info1d.yTitle			  = info.yTitle                  ;
  info1d.yMin			  = info.yMin                    ;
  info1d.ratioMin		  = info.ratioMin                ;
  info1d.ratioMax		  = info.ratioMax                ;
  info1d.ratioRebin		  = info.ratioRebin              ;
  info1d.displayOverUnderflowBin  = info.displayOverUnderflowBin ;
  info1d.displayNoInfo		  = info.displayNoInfo           ;
  info1d.legendPosition           = info.legendPosition          ;

  return info1d;
}

information1d get1DInfoFromMuonCut(informationMuonCuts info){

  information1d info1d;
  info1d.plotName                 = info.plotName                ;
  info1d.plotTitle		  = info.plotTitle               ;
  info1d.label			  = info.label                   ;
  info1d.aliasx			  = info.aliasx                  ;
  info1d.xTitle			  = info.xTitle                  ;
  info1d.cut			  = info.cut                     ;
  info1d.bScale			  = info.bScale                     ;
  info1d.cScale			  = info.cScale                     ;
  info1d.xlow			  = info.xlow                    ;
  info1d.xup			  = info.xup                     ;
  info1d.nbinsx			  = info.nbinsx                  ;
  info1d.yTitle			  = info.yTitle                  ;
  info1d.yMin			  = info.yMin                    ;
  info1d.ratioMin		  = info.ratioMin                ;
  info1d.ratioMax		  = info.ratioMax                ;
  info1d.ratioRebin		  = info.ratioRebin              ;
  info1d.displayOverUnderflowBin  = info.displayOverUnderflowBin ;
  info1d.displayNoInfo		  = info.displayNoInfo           ;
  info1d.legendPosition           = info.legendPosition          ;

  return info1d;
}

double IntegralAndError(TH1D* h   , int i, int j, double &err){
  double integral = h->Integral( i, j);

  double error = 0;
  for(int k=i; k<=j; k++){
    error += h->GetBinError(k) * h->GetBinError(k);
  }

  err = sqrt(error);
  return integral;
}
