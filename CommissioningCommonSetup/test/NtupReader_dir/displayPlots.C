{

// FOR JET SAMPLE

  gROOT->ProcessLine(".L LoadDisplayRootPlot.C");

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  bool runJet=true;
  int date=2011;
// PlotStack(TString selection, int date, bool down=false, bool logy=false, bool mu=false){

//  for Jet dataset


 if (runJet) {
  PlotStack("npv",date, 0, 0,0);
  PlotStack("npv_no_scaled",date, 0, 0,0);
  PlotStack("all_jetpt",date, 1, 1, 0);

  PlotStack("discri_tche",date, 1, 1, 0);
  PlotStack("discri_tchp",date, 1, 1, 0);
  PlotStack("discri_ssche0", date, 1, 1, 0);
  PlotStack("discri_ssche", date, 0, 0, 0);
  PlotStack("discri_sschp0", date, 1, 1, 0);
  PlotStack("discri_sschp", date, 0, 0, 0);
  PlotStack("discri_jetprob",date, 1, 1, 0);
  PlotStack("discri_jetbprob",date, 1, 1, 0);

  PlotStack("n_tracks_jet", date, 1, 0, 0);
  PlotStack("n_seltracks_jet", date, 1, 0, 0);
  PlotStack("pt_tracks", date, 1, 1, 0);
  PlotStack("pt_seltracks", date, 1, 1, 0);

  // IP
  PlotStack("IP3d1",date, 1, 1, 0);
  PlotStack("IP3d2",date, 1, 1, 0);
  PlotStack("IP3d3",date, 1, 1, 0);
  PlotStack("IP3d1sig",date, 1, 1, 0);
  PlotStack("IP3d2sig",date, 1, 1, 0);
  PlotStack("IP3d3sig",date, 1, 1, 0);

  PlotStack("IP3d1sorted",date, 1, 1, 0);
  PlotStack("IP3d2sorted",date, 1, 1, 0);
  PlotStack("IP3d3sorted",date, 1, 1, 0);
  PlotStack("IP3d1sigsorted",date, 1, 1, 0);
  PlotStack("IP3d2sigsorted",date, 1, 1, 0);
  PlotStack("IP3d3sigsorted",date, 1, 1, 0);

  PlotStack("trackNHits",date, 1, 1, 0);
  PlotStack("trackNPixelHits",date, 1, 1, 0);
  PlotStack("trackNormChi2",date, 1, 1, 0);
  PlotStack("trackTransverseMomentum",date, 1, 1, 0);
  PlotStack("trackLongitudinalIP",date, 1, 1, 0);
  PlotStack("trackIP2d",date, 1, 1, 0);
  PlotStack("trackDistJetAxis",date, 1, 1, 0);
  PlotStack("trackDecayLength",date, 1, 1, 0);

  PlotStack("trackNHits_cut",date, 1, 1, 0);
  PlotStack("trackNPixelHits_cut",date, 1, 1, 0);
  PlotStack("trackNormChi2_cut",date, 1, 1, 0);
  PlotStack("trackTransverseMomentum_cut",date, 1, 1, 0);
  PlotStack("trackLongitudinalIP_cut",date, 1, 1, 0);
  PlotStack("trackIP2d_cut",date, 1, 1, 0);
  PlotStack("trackDistJetAxis_cut",date, 1, 1, 0);
  PlotStack("trackDecayLength_cut",date, 1, 1, 0);

  PlotStack("trackIP3d",date, 1, 1, 0);
  PlotStack("trackIP3dError",date, 1, 1, 0);
  PlotStack("trackIP3dsig",date, 1, 1, 0);
  PlotStack("trackIP3d_sel",date, 1, 1, 0);
  PlotStack("trackIP3dError_sel",date, 1, 1, 0);
  PlotStack("trackIP3dsig_sel",date, 1, 1, 0);
  PlotStack("trackIP3d_cutsel",date, 1, 1, 0);
  PlotStack("trackIP3dError_cutsel",date, 1, 1, 0);
  PlotStack("trackIP3dsig_cutsel",date, 1, 1, 0);

  // SV
  PlotStack("sv_nvertices0",date, 0, 1, 0);
  PlotStack("sv_nvertices",date, 0, 1, 0);
  PlotStack("sv_jetpt",date, 0, 1, 0);
  PlotStack("sv_tracksel", date, 0, 0, 0);
  PlotStack("sv_trackmul", date, 0, 0, 0);

  PlotStack("sv_flightsig2d",date, 0, 1, 0);
  PlotStack("sv_flightsig3d",date, 0, 1, 0);
  PlotStack("sv_flightsig3d_3tr",date, 0, 1, 0);
  PlotStack("sv_flightdis2d",date, 0, 1, 0);
  PlotStack("sv_flightdis3d",date, 0, 1, 0);

  PlotStack("sv_normchi2",date, 0, 1, 0);
  PlotStack("sv_mass", date, 0, 0, 0);
  PlotStack("sv_mass_3tr", date, 0, 0, 0);
  PlotStack("sv_eratio", date, 0, 0, 0);
  PlotStack("sv_ipsigcharm",date, 0, 1, 0);
   
  PlotStack("sv_vtx_pt",date, 0, 1, 0);
  PlotStack("sv_vtxdir_eta", date, 0, 0, 0);
  PlotStack("sv_vtxdir_phi", date, 0, 0, 0);
 
  PlotStack("sv_deltar_jet",date, 0, 1, 0);
  PlotStack("sv_deltar_sum_jet",date, 0, 1, 0);
  PlotStack("sv_deltar_sum_dir",date, 0, 1, 0);
 }
 else {

// for btagmet dataset 


  PlotStack("muons_multiplicity",date, 0, 1, 1);
  PlotStack("muon_Ip3d",date, 0, 1, 1);
  PlotStack("muon_Ip2d",date, 0, 1, 1);
  PlotStack("muon_Sip3d",date, 0, 1, 1);
  PlotStack("muon_Sip2d",date, 0, 1, 1);
  PlotStack("muon_ptrel", date, 0, 0, 1);
  PlotStack("muon_Pt", date, 0, 1, 1);
  PlotStack("muon_DeltaR", date, 0, 0, 1);
  PlotStack("muon_Ratio", date, 0, 0, 1);

  PlotStack("npv",date, 0, 0,1);
  PlotStack("npv_no_scaled",date, 0, 0,1);
  PlotStack("all_jetpt",date, 1, 1, 1);

  PlotStack("discri_tche",date, 1, 1, 1);
  PlotStack("discri_tchp",date, 1, 1, 1);
  PlotStack("discri_ssche0", date, 1, 1, 1);
  PlotStack("discri_ssche", date, 0, 0, 1);
  PlotStack("discri_sschp0", date, 1, 1, 1);
  PlotStack("discri_sschp", date, 0, 0, 1);
  PlotStack("discri_jetprob",date, 1, 1, 1);
  PlotStack("discri_jetbprob",date, 1, 1, 1);

  PlotStack("n_tracks_jet", date, 1, 0, 1);
  PlotStack("n_seltracks_jet", date, 1, 0, 1);
  PlotStack("pt_tracks", date, 1, 1, 1);
  PlotStack("pt_seltracks", date, 1, 1, 1);

  // IP
  PlotStack("IP3d1",date, 1, 1, 1);
  PlotStack("IP3d2",date, 1, 1, 1);
  PlotStack("IP3d3",date, 1, 1, 1);
  PlotStack("IP3d1sig",date, 1, 1, 1);
  PlotStack("IP3d2sig",date, 1, 1, 1);
  PlotStack("IP3d3sig",date, 1, 1, 1);

  PlotStack("IP3d1sorted",date, 1, 1, 1);
  PlotStack("IP3d2sorted",date, 1, 1, 1);
  PlotStack("IP3d3sorted",date, 1, 1, 1);
  PlotStack("IP3d1sigsorted",date, 1, 1, 1);
  PlotStack("IP3d2sigsorted",date, 1, 1, 1);
  PlotStack("IP3d3sigsorted",date, 1, 1, 1);

  PlotStack("trackNHits",date, 1, 1, 1);
  PlotStack("trackNPixelHits",date, 1, 1, 1);
  PlotStack("trackNormChi2",date, 1, 1, 1);
  PlotStack("trackTransverseMomentum",date, 1, 1, 1);
  PlotStack("trackLongitudinalIP",date, 1, 1, 1);
  PlotStack("trackIP2d",date, 1, 1, 1);
  PlotStack("trackDistJetAxis",date, 1, 1, 1);
  PlotStack("trackDecayLength",date, 1, 1, 1);

  PlotStack("trackNHits_cut",date, 1, 1, 1);
  PlotStack("trackNPixelHits_cut",date, 1, 1, 1);
  PlotStack("trackNormChi2_cut",date, 1, 1, 1);
  PlotStack("trackTransverseMomentum_cut",date, 1, 1, 1);
  PlotStack("trackLongitudinalIP_cut",date, 1, 1, 1);
  PlotStack("trackIP2d_cut",date, 1, 1, 1);
  PlotStack("trackDistJetAxis_cut",date, 1, 1, 1);
  PlotStack("trackDecayLength_cut",date, 1, 1, 1);

  PlotStack("trackIP3d",date, 1, 1, 1);
  PlotStack("trackIP3dError",date, 1, 1, 1);
  PlotStack("trackIP3dsig",date, 1, 1, 1);
  PlotStack("trackIP3d_sel",date, 1, 1, 1);
  PlotStack("trackIP3dError_sel",date, 1, 1, 1);
  PlotStack("trackIP3dsig_sel",date, 1, 1, 1);
  PlotStack("trackIP3d_cutsel",date, 1, 1, 1);
  PlotStack("trackIP3dError_cutsel",date, 1, 1, 1);
  PlotStack("trackIP3dsig_cutsel",date, 1, 1, 1);

  // SV
  PlotStack("sv_nvertices0",date, 0, 1, 1);
  PlotStack("sv_nvertices",date, 0, 1, 1);
  PlotStack("sv_jetpt",date, 0, 1, 1);
  PlotStack("sv_tracksel", date, 0, 0, 1);
  PlotStack("sv_trackmul", date, 0, 0, 1);

  PlotStack("sv_flightsig2d",date, 0, 1, 1);
  PlotStack("sv_flightsig3d",date, 0, 1, 1);
  PlotStack("sv_flightsig3d_3tr",date, 0, 1, 1);
  PlotStack("sv_flightdis2d",date, 0, 1, 1);
  PlotStack("sv_flightdis3d",date, 0, 1, 1);

  PlotStack("sv_normchi2",date, 0, 1, 1);
  PlotStack("sv_mass", date, 0, 0, 1);
  PlotStack("sv_mass_3tr", date, 0, 0, 1);
  PlotStack("sv_eratio", date, 0, 0, 1);
  PlotStack("sv_ipsigcharm",date, 0, 1, 1);
   
  PlotStack("sv_vtx_pt",date, 0, 1, 1);
  PlotStack("sv_vtxdir_eta", date, 0, 0, 1);
  PlotStack("sv_vtxdir_phi", date, 0, 0, 1);
 
  PlotStack("sv_deltar_jet",date, 0, 1, 1);
  PlotStack("sv_deltar_sum_jet",date, 0, 1, 1);
  PlotStack("sv_deltar_sum_dir",date, 0, 1, 1);

 }







}
