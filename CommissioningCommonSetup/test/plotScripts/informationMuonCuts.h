#ifndef IMUONCUTS_H
#define IMUONCUTS_H

#include <string>

class informationMuonCuts{

 public:
  bool standardPFtriggerHLTJet30U;
  float jetPtCut;
  float jetEtaCut;
  float muonPtCut;
  float muonEtaCut;
  bool  muonIsGlobal;
  unsigned int muonGlobalMuonHits;
  unsigned int muonNumberOfMatches;
  unsigned int muonInnerValidHits;
  unsigned int muonNPixelHits;
  unsigned int muonNExpectedOuterHits;   			       
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
