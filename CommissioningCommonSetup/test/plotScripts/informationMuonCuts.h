#ifndef IMUONCUTS_H
#define IMUONCUTS_H

#include <string>

class informationMuonCuts{

 public:
  bool triggerHLTJet30U;
  float jetPtCut;
  float jetEtaCut;
  float muonPtCut;
  float muonEtaCut;
  bool  muonIsGlobal;
  int muonGlobalMuonHits;
  int muonNumberOfMatches;
  int muonInnerValidHits;
  int muonNPixelHits;
  int muonNExpectedOuterHits;   			       
  float muonInnerNChi2;
  float muonGlobalNChi2;
  float muonVzPVDist;
  float muonDeltaR;

  std::string plotName;
  std::string plotTitle;
  std::string label;
  std::string aliasx;
  std::string xTitle;
  std::string cut;
  double bScale;
  double cScale;
  double xlow;
  double xup;
  int nbinsx;
  std::string yTitle;
  double yMin;
  double ratioMin;
  double ratioMax;
  int ratioRebin;
  bool displayOverUnderflowBin;
  bool displayNoInfo;
  bool legendPosition;

};


#endif
