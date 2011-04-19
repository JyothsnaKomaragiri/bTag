{

// FOR JET SAMPLE

  gROOT->ProcessLine(".L LoadDisplayRootPlot.C");

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  int date=2011;
// PlotStack(TString selection, int date, bool down=false, bool logy=false, bool mu=false){

//  for Jet dataset
/*
  PlotStack("npv",date, 0, 0,0);
  PlotStack("alljetpt",date, 1, 1, 0);

  PlotStack("tche_discri",date, 1, 1, 0);
  PlotStack("tchp_discri",date, 1, 1, 0);
  PlotStack("ssche_discri0", date, 1, 1, 0);
  PlotStack("ssche_discri", date, 0, 0, 0);
  PlotStack("sschp_discri0", date, 1, 1, 0);
  PlotStack("sschp_discri", date, 0, 0, 0);
  PlotStack("jetprob_discri",date, 1, 1, 0);
  PlotStack("jetbprob_discri",date, 1, 1, 0);

  PlotStack("ntracks_jet", date, 1, 0, 0);
  PlotStack("nseltracks_jet", date, 1, 0, 0);
  PlotStack("pt_tracks", date, 1, 1, 0);
  PlotStack("pt_seltracks", date, 1, 1, 0);

  // IP
  PlotStack("IP3d1",date, 1, 1, 0);
  PlotStack("IP3d2",date, 1, 1, 0);
  PlotStack("IP3d3",date, 1, 1, 0);
  PlotStack("IP3d1sig",date, 1, 1, 0);
  PlotStack("IP3d2sig",date, 1, 1, 0);
  PlotStack("IP3d3sig",date, 1, 1, 0);

  PlotStack("IP3d10",date, 1, 1, 0);
  PlotStack("IP3d20",date, 1, 1, 0);
  PlotStack("IP3d30",date, 1, 1, 0);
  PlotStack("IP3d1sig0",date, 1, 1, 0);
  PlotStack("IP3d2sig0",date, 1, 1, 0);
  PlotStack("IP3d3sig0",date, 1, 1, 0);

  // SV
  PlotStack("jetpt",date, 0, 1, 0);
  PlotStack("nvertices0",date, 0, 1, 0);
  PlotStack("nvertices",date, 0, 1, 0);
  PlotStack("tracksel", date, 0, 0, 0);
  PlotStack("trackmul", date, 0, 0, 0);

  PlotStack("flightsig2d",date, 0, 1, 0);
  PlotStack("flightsig3d",date, 0, 1, 0);
  PlotStack("flightdis2d",date, 0, 1, 0);
  PlotStack("flightdis3d",date, 0, 1, 0);

  PlotStack("svmass", date, 0, 0, 0);
  PlotStack("svmass3tr", date, 0, 0, 0);
  PlotStack("ipsigcharm",date, 0, 1, 0);
   
  PlotStack("normchi2",date, 0, 1, 0);
  PlotStack("eratio", date, 0, 0, 0);
  PlotStack("vtxdir_eta", date, 0, 0, 0);
  PlotStack("vtxdir_phi", date, 0, 0, 0);
 
  PlotStack("deltar_jet",date, 0, 1, 0);
  PlotStack("deltar_sum_jet",date, 0, 1, 0);
  PlotStack("deltar_sum_dir",date, 0, 1, 0);
*/



// for btagmet dataset 

  PlotStack("npv",date, 0, 0,1);
  PlotStack("alljetpt",date, 1, 1, 1);

  PlotStack("tche_discri",date, 1, 1, 1);
  PlotStack("tchp_discri",date, 1, 1, 1);
  PlotStack("ssche_discri0", date, 1, 1, 1);
  PlotStack("ssche_discri", date, 0, 0, 1);
  PlotStack("sschp_discri0", date, 1, 1, 1);
  PlotStack("sschp_discri", date, 0, 0, 1);
  PlotStack("jetprob_discri",date, 1, 1, 1);
  PlotStack("jetbprob_discri",date, 1, 1, 1);

  PlotStack("ntracks_jet", date, 1, 0, 1);
  PlotStack("nseltracks_jet", date, 1, 0, 1);
  PlotStack("pt_tracks", date, 1, 1, 1);
  PlotStack("pt_seltracks", date, 1, 1, 1);

  PlotStack("muon_ptrel", date, 0, 0, 1);
  PlotStack("muonPt", date, 0, 0, 1);
  PlotStack("muonDeltaR", date, 0, 0, 1);

  //IP
  PlotStack("IP3d1",date, 1, 1, 1);
  PlotStack("IP3d2",date, 1, 1, 1);
  PlotStack("IP3d3",date, 1, 1, 1);
  PlotStack("IP3d1sig",date, 1, 1, 1);
  PlotStack("IP3d2sig",date, 1, 1, 1);
  PlotStack("IP3d3sig",date, 1, 1, 1);

  PlotStack("IP3d10",date, 1, 1, 1);
  PlotStack("IP3d20",date, 1, 1, 1);
  PlotStack("IP3d30",date, 1, 1, 1);
  PlotStack("IP3d1sig0",date, 1, 1, 1);
  PlotStack("IP3d2sig0",date, 1, 1, 1);
  PlotStack("IP3d3sig0",date, 1, 1, 1);

  //SV
  PlotStack("jetpt",date, 0, 1, 1);
  PlotStack("nvertices0",date, 0, 1, 1);
  PlotStack("nvertices",date, 0, 1, 1);
  PlotStack("tracksel", date, 0, 0, 1);
  PlotStack("trackmul", date, 0, 0, 1);

  PlotStack("flightsig2d",date, 0, 1, 1);
  PlotStack("flightsig3d",date, 0, 1, 1);
  PlotStack("flightdis2d",date, 0, 1, 1);
  PlotStack("flightdis3d",date, 0, 1, 1);

  PlotStack("svmass", date, 0, 0, 1);
  PlotStack("svmass3tr", date, 0, 0, 1);
  PlotStack("ipsigcharm",date, 0, 1, 1);
   
  PlotStack("normchi2",date, 0, 1, 1);
  PlotStack("eratio", date, 0, 0, 1);
  PlotStack("vtxdir_eta", date, 0, 0, 1);
  PlotStack("vtxdir_phi", date, 0, 0, 1);

  PlotStack("deltar_jet",date, 0, 1, 1);
  PlotStack("deltar_sum_jet",date, 0, 1, 1);
  PlotStack("deltar_sum_dir",date, 0, 1, 1);



}
