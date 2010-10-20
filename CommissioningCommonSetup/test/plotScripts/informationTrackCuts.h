#ifndef ITRACKKUTS_H
#define  ITRACKKUTS_H

#include <string>

class informationTrackCuts{
 public:
  bool triggerHLTJet15U;
  bool triggerHLTJet30U;
  float jetPtCut;
  float jetEtaCut;
  unsigned int nHitsCut;
  unsigned int nPixHitsCut;
  float Chi2Cut;
  float trackPtCut;
  float distJetAxisCut;
  float decayLengthCut;
  float IP2dCut;
  float longIPCut;

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
