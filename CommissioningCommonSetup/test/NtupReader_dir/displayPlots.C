{

// FOR JET SAMPLE

  gROOT->ProcessLine(".L LoadDisplayRootPlot.C");

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  bool runJet=false;
  int date=2011;
// PlotStack(TString selection, int date, bool down=false, bool logy=false, bool mu=false){

//  for Jet dataset


 if (runJet) {
   PlotStack("npv","number of PV", date, 0, 0,0);
   PlotStack("npv_no_scaled","number of PV", date, 0, 0,0);
   PlotStack("all_jetpt","jet p_{t}",date, 1, 1, 0);

   PlotStack("discri_tche","TCHE discriminator",date, 1, 1, 0);
   PlotStack("discri_tchp","TCHP discriminator",date, 1, 1, 0);
  PlotStack("discri_ssche0","SSVHE discriminator", date, 1, 1, 0);
  PlotStack("discri_ssche", "SSVHE discriminator", date, 0, 0, 0);
  PlotStack("discri_sschp0","SSVHP discriminator", date, 1, 1, 0);
  PlotStack("discri_sschp", "SSVHP discriminator", date, 0, 0, 0);
  PlotStack("discri_jetprob", "JP discriminator", date, 1, 1, 0);
  PlotStack("discri_jetbprob", "JBP discriminator",date, 1, 1, 0);

  PlotStack("n_tracks_jet", "nr. of tracks in jet",  date, 1, 0, 0);
  PlotStack("n_seltracks_jet","nr. of selected tracks",  date, 1, 0, 0);
  PlotStack("pt_tracks", "track p_{t}", date, 1, 1, 0);
  PlotStack("pt_seltracks", "track p_{t}", date, 1, 1, 0);

  // IP
  PlotStack("IP3d1",  "1st track 3D IP", date, 1, 1, 0);
  PlotStack("IP3d2",  "2nd track 3D IP",date, 1, 1, 0);
  PlotStack("IP3d3",  "3rd track 3D IP",date, 1, 1, 0);
  PlotStack("IP3d1sig", "1st track 3D IP significance", date, 1, 1, 0);
  PlotStack("IP3d2sig", "2nd track 3D IP significance", date, 1, 1, 0);
  PlotStack("IP3d3sig", "3rd track 3D IP significance", date, 1, 1, 0);

  PlotStack("IP3d1sorted","1st track 3D IP",  date, 1, 1, 0);
  PlotStack("IP3d2sorted","2nd track 3D IP",  date, 1, 1, 0);
  PlotStack("IP3d3sorted","3rd track 3D IP",  date, 1, 1, 0);
  PlotStack("IP3d1sigsorted", "1st track 3D IP significance", date, 1, 1, 0);
  PlotStack("IP3d2sigsorted", "2nd track 3D IP significance", date, 1, 1, 0);
  PlotStack("IP3d3sigsorted", "3rd track 3D IP significance", date, 1, 1, 0);

  PlotStack("trackNHits", "nr. of hits", date, 1, 1, 0);
  PlotStack("trackNPixelHits", "nr. of pixel hits", date, 1, 1, 0);
  PlotStack("trackNormChi2", "norm. #chi^{2}", date, 1, 1, 0);
  PlotStack("trackTransverseMomentum", "p_{t}", date, 1, 1, 0);
  PlotStack("trackLongitudinalIP", "longitudinal IP", date, 1, 1, 0);
  PlotStack("trackIP2d", "2D IP", date, 1, 1, 0);
  PlotStack("trackDistJetAxis", "distance to jet axis", date, 1, 1, 0);
  PlotStack("trackDecayLength", "decay length", date, 1, 1, 0);

  PlotStack("trackNHits_cut","nr. of hits",date, 1, 1, 0);
  PlotStack("trackNPixelHits_cut","nr. of pixel hits", date, 1, 1, 0);
  PlotStack("trackNormChi2_cut", "norm. #chi^{2}",date, 1, 1, 0);
  PlotStack("trackTransverseMomentum_cut","track p_{t}",date, 1, 1, 0);
  PlotStack("trackLongitudinalIP_cut", "longitudinal IP", date, 1, 1, 0);
  PlotStack("trackIP2d_cut", "2D IP", date, 1, 1, 0);
  PlotStack("trackDistJetAxis_cut", "distance to jet axis", date, 1, 1, 0);
  PlotStack("trackDecayLength_cut", "decay length", date, 1, 1, 0);

  PlotStack("trackIP3d", "3D IP", date, 1, 1, 0);
  PlotStack("trackIP3dError", "3D IP error", date, 1, 1, 0);
  PlotStack("trackIP3dsig", "3D IP significance", date, 1, 1, 0);
  PlotStack("trackIP3d_sel", "3D IP", date, 1, 1, 0);
  PlotStack("trackIP3dError_sel", "3D IP error", date, 1, 1, 0);
  PlotStack("trackIP3dsig_sel", "3D IP significance", date, 1, 1, 0);
  PlotStack("trackIP3d_cutsel", "3D IP",  date, 1, 1, 0);
  PlotStack("trackIP3dError_cutsel", "3D IP error", date, 1, 1, 0);
  PlotStack("trackIP3dsig_cutsel", "3D IP significance", date, 1, 1, 0);

  // SV
  PlotStack("sv_nvertices0", "nr. of SV", date, 0, 1, 0);
  PlotStack("sv_nvertices",  "nr. of SV", date, 0, 1, 0);
  PlotStack("sv_jetpt", "jet p_{t}", date, 0, 1, 0);
  PlotStack("sv_tracksel", "SV track multiplicity", date, 0, 0, 0);
  PlotStack("sv_trackmul", "SV track multiplicity", date, 0, 0, 0);

  PlotStack("sv_flightsig2d", "2D flight significance", date, 0, 1, 0);
  PlotStack("sv_flightsig3d", "3D flight significance", date, 0, 1, 0);
  PlotStack("sv_flightsig3d_3tr", "3-track 3D flight significance", date, 0, 1, 0);
  PlotStack("sv_flightdis2d", "2D flight distance" ,date, 0, 1, 0);
  PlotStack("sv_flightdis3d", "2D flight distance", date, 0, 1, 0);

  PlotStack("sv_normchi2","norm. #chi^{2}", date, 0, 1, 0);
  PlotStack("sv_mass", "SV mass", date, 0, 0, 0);
  PlotStack("sv_mass_3tr", "3-track SV mass", date, 0, 0, 0);
  PlotStack("sv_eratio", "SV energy ratio", date, 0, 0, 0);
  PlotStack("sv_ipsigcharm", "2D IP significance", date, 0, 1, 0);
   
  PlotStack("sv_vtx_pt", "vertex p_{t}", date, 0, 1, 0);
  PlotStack("sv_vtxdir_eta", "vertex #eta", date, 0, 0, 0);
  PlotStack("sv_vtxdir_phi", "vertex #phi", date, 0, 0, 0);
 
  PlotStack("sv_deltar_jet",    "#Delta R(vertex dir., jet)"            , date, 0, 1, 0);
  PlotStack("sv_deltar_sum_jet","#Delta R(vertex {#vec p}, jet)"          ,date, 0, 1, 0);
  PlotStack("sv_deltar_sum_dir","#Delta R(vertex {#vec p}, vertex dir.)"  ,date, 0, 1, 0);

  PlotStack("n_cutseltracks_jet", "nr. of tracks", date, 1, 0, 0);
  PlotStack("pt_cutseltracks", "track p_{t}", date, 1, 1, 0);

  // IP
  PlotStack("IP3d1Errorsorted","1st track 3D IP error", date, 1, 1, 0);
  PlotStack("IP3d2Errorsorted","2nd track 3D IP error", date, 1, 1, 0);
  PlotStack("IP3d3Errorsorted","3rd track 3D IP error", date, 1, 1, 0);
  PlotStack("trackIP3d_bin1_cutsel", "3D IP", date, 1, 1, 0);
  PlotStack("trackIP3d_bin2_cutsel","3D IP",date, 1, 1, 0);
  PlotStack("trackIP3d_bin3_cutsel","3D IP",date, 1, 1, 0);
  PlotStack("trackIP3d_bin4_cutsel","3D IP",date, 1, 1, 0);
  PlotStack("trackIP3d_bin5_cutsel","3D IP",date, 1, 1, 0);
  PlotStack("trackIP3d_bin6_cutsel","3D IP",date, 1, 1, 0);


 //  TagRate("discri_tche", "TCHE discr. cut", 1,1,0);
//   TagRate("discri_tchp", "TCHP discr. cut", 1,1,0);
//   TagRate("discri_ssche","SSVHE discr. cut", 0,0,0);
//   TagRate("discri_sschp","SSVHP discr. cut", 0,0,0);
//   TagRate("discri_jetprob", "JP discr. cut", 1,1,0);
//   TagRate("discri_jetbprob", "JBP discr. cut", 1,1,0);


  PlotData("IP3d2sig0", "2nd track 3D IP significance", date, 1, 1, 0);
  PlotData("IP3d3sig0","3nd track 3D IP significance",date, 1, 1, 0);
  PlotData("ntracks_jet","nr. of tracks in jet", date, 1, 1, 0);
  PlotData("nseltracks_jet","nr. of selected tracks", date, 1, 1, 0);
  PlotData("ncutseltracks_jet","nr. of selected tracks",date, 1, 1, 0);

  PlotData("pt_tracks", "track p_{t}", date, 1, 1, 0);
  PlotData("pt_seltracks", "track p_{t}", date, 1, 1, 0);
  PlotData("pt_cutseltracks", "track p_{t}", date, 1, 1, 0);

  PlotData("nsv0", "nr. of SV", date, 1, 1, 0);
  PlotData("nsv", "nr. of SV", date, 1, 1, 0);
  PlotData("flightsig3d", "3D flight significance",date, 1, 1, 0);
  PlotData("flightsig3d_3tr","3D flight significance",date, 1, 1, 0);
  PlotData("svmass", "SV mass",  date, 0, 0, 0);
  PlotData("svmass_3tr", "3-track SV mass", date, 0, 0, 0);

  PlotData("nsv_3tr", "nr. of 3-track SV", date, 1, 1, 0);
  PlotData("nsv0_3tr", "nr. of 3-track SV", date, 1, 1, 0);

  PlotStack("IP3d1sigsorted_bin1", "1st track 3D IP significance bin1", date, 1, 1, 0);
  PlotStack("IP3d1sigsorted_bin2", "1st track 3D IP significance bin2", date, 1, 1, 0);
  PlotStack("IP3d1sigsorted_bin3", "1st track 3D IP significance bin3", date, 1, 1, 0);
  PlotStack("IP3d1sigsorted_bin4", "1st track 3D IP significance bin4", date, 1, 1, 0);
  PlotStack("IP3d1sigsorted_bin5", "1st track 3D IP significance bin5", date, 1, 1, 0);
  PlotStack("IP3d1sigsorted_bin6", "1st track 3D IP significance bin6", date, 1, 1, 0);

  PlotStack("IP3d2sigsorted_bin1", "2nd track 3D IP significance bin1", date, 1, 1, 0);
  PlotStack("IP3d2sigsorted_bin2", "2nd track 3D IP significance bin2", date, 1, 1, 0);
  PlotStack("IP3d2sigsorted_bin3", "2nd track 3D IP significance bin3", date, 1, 1, 0);
  PlotStack("IP3d2sigsorted_bin4", "2nd track 3D IP significance bin4", date, 1, 1, 0);
  PlotStack("IP3d2sigsorted_bin5", "2nd track 3D IP significance bin5", date, 1, 1, 0);
  PlotStack("IP3d2sigsorted_bin6", "2nd track 3D IP significance bin6", date, 1, 1, 0);

  PlotStack("trackIP3d_jetptbin1",   "3D IP (jet bin1)",    date, 1, 1, 0);    
  PlotStack("trackIP3d_jetptbin2",   "3D IP (jet bin2)",    date, 1, 1, 0);        
  PlotStack("trackIP3d_jetptbin3",   "3D IP (jet bin3)",    date, 1, 1, 0);          
                             
  PlotStack("IP3d1_jetptbin1",   "1st track 3D IP (jet bin1)",    date, 1, 1, 0);              
  PlotStack("IP3d1_jetptbin2",   "1st track 3D IP (jet bin2)",    date, 1, 1, 0);              
  PlotStack("IP3d1_jetptbin3",   "1st track 3D IP (jet bin3)",    date, 1, 1, 0);              
                         
  PlotStack("IP3d2_jetptbin1",   "2nd track 3D IP (jet bin1)",    date, 1, 1, 0);              
  PlotStack("IP3d2_jetptbin2",   "2nd track 3D IP (jet bin2)",    date, 1, 1, 0);              
  PlotStack("IP3d2_jetptbin3",   "2nd track 3D IP (jet bin3)",    date, 1, 1, 0);              
                        
  PlotStack("IP3d3_jetptbin1",   "3rd track 3D IP (jet bin1)",    date, 1, 1, 0);              
  PlotStack("IP3d3_jetptbin2",   "3rd track 3D IP (jet bin2)",    date, 1, 1, 0);              
  PlotStack("IP3d3_jetptbin3",   "3rd track 3D IP (jet bin3)",    date, 1, 1, 0);              
                               
  // PlotStack("IP3dsigsorted_jetptbin1",    "",    date, 1, 1, 0);      
  //  PlotStack("IP3dsigsorted_jetptbin2",    "",    date, 1, 1, 0);      
  //  PlotStack("IP3dsigsorted_jetptbin3",    "",    date, 1, 1, 0);      
                             
  PlotStack("IP3d1sigsorted_jetptbin1",   "1st track 3D IP sig. (jet bin1)",    date, 1, 1, 0);     
  PlotStack("IP3d1sigsorted_jetptbin2",   "1st track 3D IP sig. (jet bin2)",    date, 1, 1, 0);     
  PlotStack("IP3d1sigsorted_jetptbin3",   "1st track 3D IP sig. (jet bin3)",    date, 1, 1, 0);     
                             		                            
  PlotStack("IP3d2sigsorted_jetptbin1",   "2nd track 3D IP sig. (jet bin1)",    date, 1, 1, 0);     
  PlotStack("IP3d2sigsorted_jetptbin2",   "2nd track 3D IP sig. (jet bin2)",    date, 1, 1, 0);     
  PlotStack("IP3d2sigsorted_jetptbin3",   "2nd track 3D IP sig. (jet bin3)",    date, 1, 1, 0);     
                             		                            
  PlotStack("IP3d3sigsorted_jetptbin1",   "3rd track 3D IP sig. (jet bin1)",    date, 1, 1, 0);     
  PlotStack("IP3d3sigsorted_jetptbin2",   "3rd track 3D IP sig. (jet bin2)",    date, 1, 1, 0);     
  PlotStack("IP3d3sigsorted_jetptbin3",   "3rd track 3D IP sig. (jet bin3)",    date, 1, 1, 0);     
                            
  //  PlotStack("IP3dErrorsorted_jetptbin1",   "",    date, 1, 1, 0);    
  //  PlotStack("IP3dErrorsorted_jetptbin2",   "",    date, 1, 1, 0);    
  //  PlotStack("IP3dErrorsorted_jetptbin3",   "",    date, 1, 1, 0);    
                              
  PlotStack("IP3d1Errorsorted_jetptbin1",   "1st track 3D IP err. (jet bin1)",    date, 1, 1, 0);     
  PlotStack("IP3d1Errorsorted_jetptbin2",   "1st track 3D IP err. (jet bin2)",    date, 1, 1, 0);     
  PlotStack("IP3d1Errorsorted_jetptbin3",   "1st track 3D IP err. (jet bin3)",    date, 1, 1, 0);     
                                 	                                   
  PlotStack("IP3d2Errorsorted_jetptbin1",   "2nd track 3D IP err. (jet bin1)",    date, 1, 1, 0);     
  PlotStack("IP3d2Errorsorted_jetptbin2",   "2nd track 3D IP err. (jet bin2)",    date, 1, 1, 0);     
  PlotStack("IP3d2Errorsorted_jetptbin3",   "2nd track 3D IP err. (jet bin3)",    date, 1, 1, 0);     
                              		                                   
  PlotStack("IP3d3Errorsorted_jetptbin1",   "3rd track 3D IP err. (jet bin1)",    date, 1, 1, 0);     
  PlotStack("IP3d3Errorsorted_jetptbin2",   "3rd track 3D IP err. (jet bin2)",    date, 1, 1, 0);     
  PlotStack("IP3d3Errorsorted_jetptbin3",   "3rd track 3D IP err. (jet bin3)",    date, 1, 1, 0);     
          
  PlotStack("sv_mass_jetptbin1",   "2-track SV mass (jet bin1)",    date, 1, 1, 0);            
  PlotStack("sv_mass_jetptbin2",   "2-track SV mass (jet bin2)",    date, 1, 1, 0);            
  PlotStack("sv_mass_jetptbin3",   "2-track SV mass (jet bin3)",    date, 1, 1, 0);            
                            
  PlotStack("sv_mass_3tr_jetptbin1",   "3-track SV mass (jet bin1)",    date, 1, 1, 0);        
  PlotStack("sv_mass_3tr_jetptbin2",   "3-track SV mass (jet bin2)",    date, 1, 1, 0);        
  PlotStack("sv_mass_3tr_jetptbin3",   "3-track SV mass (jet bin3)",    date, 1, 1, 0);        
                             
  //  PlotStack("sv_ipsigcharm_jetptbin1",   "",    date, 1, 1, 0);      
  //  PlotStack("sv_ipsigcharm_jetptbin2",   "",    date, 1, 1, 0);      
  //  PlotStack("sv_ipsigcharm_jetptbin3",   "",    date, 1, 1, 0);      
                           
  PlotStack("sv_eratio_jetptbin1",   "SV energy ratio (jet bin1)",    date, 1, 1, 0);          
  PlotStack("sv_eratio_jetptbin2",   "SV energy ratio (jet bin2)",    date, 1, 1, 0);          
  PlotStack("sv_eratio_jetptbin3",   "SV energy ratio (jet bin3)",    date, 1, 1, 0);          
                                
  PlotStack("sv_flightsig2d_jetptbin1",   "2D flight sig. (jet bin1)",    date, 1, 1, 0);       
  PlotStack("sv_flightsig2d_jetptbin2",   "2D flight sig. (jet bin2)",    date, 1, 1, 0);       
  PlotStack("sv_flightsig2d_jetptbin3",   "2D flight sig. (jet bin3)",    date, 1, 1, 0);       
                             
  PlotStack("sv_flightsig3d_jetptbin1",   "3D flight sig. (jet bin1)",    date, 1, 1, 0);       
  PlotStack("sv_flightsig3d_jetptbin2",   "3D flight sig. (jet bin2)",    date, 1, 1, 0);       
  PlotStack("sv_flightsig3d_jetptbin3",   "3D flight sig. (jet bin3)",    date, 1, 1, 0);       
                               
  PlotStack("sv_flightdis2d_jetptbin1",   "2D flight dist. (jet bin1)",    date, 1, 1, 0);       
  PlotStack("sv_flightdis2d_jetptbin2",   "2D flight dist. (jet bin2)",    date, 1, 1, 0);       
  PlotStack("sv_flightdis2d_jetptbin3",   "2D flight dist. (jet bin3)",    date, 1, 1, 0);       
                               
  PlotStack("sv_flightdis3d_jetptbin1",   "3D flight dist. (jet bin1)",    date, 1, 1, 0);       
  PlotStack("sv_flightdis3d_jetptbin2",   "3D flight dist. (jet bin2)",    date, 1, 1, 0);       
  PlotStack("sv_flightdis3d_jetptbin3",   "3D flight dist. (jet bin3)",    date, 1, 1, 0);       
                                 
  PlotStack("sv_flightsig3d_3tr_jetptbin1",   "3-track 3D flight dist. (jet bin1)",    date, 1, 1, 0);   
  PlotStack("sv_flightsig3d_3tr_jetptbin2",   "3-track 3D flight dist. (jet bin2)",    date, 1, 1, 0);   
  PlotStack("sv_flightsig3d_3tr_jetptbin3",   "3-track 3D flight dist. (jet bin3)",    date, 1, 1, 0);   
                               


  PlotStack("sv_deltar_jet_jetptbin1",   "#Delta R(vertex dir., jet) (jet bin1)",    date, 1, 1, 0);        
  PlotStack("sv_deltar_jet_jetptbin2",   "#Delta R(vertex dir., jet) (jet bin2)",    date, 1, 1, 0);        
  PlotStack("sv_deltar_jet_jetptbin3",   "#Delta R(vertex dir., jet) (jet bin3)",    date, 1, 1, 0);        
                                
  PlotStack("sv_deltar_sum_jet_jetptbin1",   "#Delta R(vertex {#vec p}, jet) (jet bin1)",    date, 1, 1, 0);    
  PlotStack("sv_deltar_sum_jet_jetptbin2",   "#Delta R(vertex {#vec p}, jet) (jet bin2)",    date, 1, 1, 0);    
  PlotStack("sv_deltar_sum_jet_jetptbin3",   "#Delta R(vertex {#vec p}, jet) (jet bin3)",    date, 1, 1, 0);    
                               
  PlotStack("sv_deltar_sum_dir_jetptbin1",   "#Delta R(vertex {#vec p}, vertex dir.) (jet bin1)",    date, 1, 1, 0);    
  PlotStack("sv_deltar_sum_dir_jetptbin2",   "#Delta R(vertex {#vec p}, vertex dir.) (jet bin2)",    date, 1, 1, 0);    
  PlotStack("sv_deltar_sum_dir_jetptbin3",   "#Delta R(vertex {#vec p}, vertex dir.) (jet bin3)",    date, 1, 1, 0);    
            
  PlotStack("discri_tche_jetptbin1",   "TCHE discriminator (jet bin1)",    date, 1, 1, 0);          
  PlotStack("discri_tche_jetptbin2",   "TCHE discriminator (jet bin2)",    date, 1, 1, 0);          
  PlotStack("discri_tche_jetptbin3",   "TCHE discriminator (jet bin3)",    date, 1, 1, 0);          
                              
  PlotStack("discri_tchp_jetptbin1",   "TCHP discriminator (jet bin1)",    date, 1, 1, 0);          
  PlotStack("discri_tchp_jetptbin2",   "TCHP discriminator (jet bin2)",    date, 1, 1, 0);          
  PlotStack("discri_tchp_jetptbin3",   "TCHP discriminator (jet bin3)",    date, 1, 1, 0);          
                            
  PlotStack("discri_ssche0_jetptbin1",   "SSVHE discriminator (jet bin1)",    date, 1, 1, 0);        
  PlotStack("discri_ssche0_jetptbin2",   "SSVHE discriminator (jet bin2)",    date, 1, 1, 0);        
  PlotStack("discri_ssche0_jetptbin3",   "SSVHE discriminator (jet bin3)",    date, 1, 1, 0);        
                           
  PlotStack("discri_ssche_jetptbin1",   "SSVHE discriminator (jet bin1)",    date, 1, 1, 0);         
  PlotStack("discri_ssche_jetptbin2",   "SSVHE discriminator (jet bin2)",    date, 1, 1, 0);         
  PlotStack("discri_ssche_jetptbin3",   "SSVHE discriminator (jet bin3)",    date, 1, 1, 0);         
                         
  PlotStack("discri_sschp0_jetptbin1",   "SSVHP discriminator (jet bin1)",    date, 1, 1, 0);        
  PlotStack("discri_sschp0_jetptbin2",   "SSVHP discriminator (jet bin2)",    date, 1, 1, 0);        
  PlotStack("discri_sschp0_jetptbin3",   "SSVHP discriminator (jet bin3)",    date, 1, 1, 0);        
                                
  PlotStack("discri_sschp_jetptbin1",   "SSVHP discriminator (jet bin1)",    date, 1, 1, 0);         
  PlotStack("discri_sschp_jetptbin2",   "SSVHP discriminator (jet bin2)",    date, 1, 1, 0);         
  PlotStack("discri_sschp_jetptbin3",   "SSVHP discriminator (jet bin3)",    date, 1, 1, 0);         
                            
  PlotStack("discri_jetprob_jetptbin1",   "JP discriminator (jet bin1)",    date, 1, 1, 0);       
  PlotStack("discri_jetprob_jetptbin2",   "JP discriminator (jet bin2)",    date, 1, 1, 0);       
  PlotStack("discri_jetprob_jetptbin3",   "JP discriminator (jet bin3)",    date, 1, 1, 0);       
                               
  PlotStack("discri_jetbprob_jetptbin1",   "JBP discriminator (jet bin1)",    date, 1, 1, 0);      
  PlotStack("discri_jetbprob_jetptbin2",   "JBP discriminator (jet bin2)",    date, 1, 1, 0);      
  PlotStack("discri_jetbprob_jetptbin3",   "JBP discriminator (jet bin3)",    date, 1, 1, 0);      

  //  PlotStack("sv_ipsigcharm_3tr",   "",    date, 1, 1, 0);              
  //  PlotStack("sv_eratio_3tr",   "3-track SV energy ratio",    date, 1, 1, 0);                  
  //  PlotStack("sv_vtx_pt_3tr",   "3-track SV vtx p_{t}",    date, 1, 1, 0);                  

  //  PlotStack("sv_trackmul_centered",   "SV track multiplicity",    date, 1, 1, 0);           
  //  PlotStack("sv_trackmul1_centered",   "SV track multiplicity",    date, 1, 1, 0);          
  //  PlotStack("sv_tracksel_centered",   "SV track multiplicity",    date, 1, 1, 0);           





  PlotStack2D("track_vs_jetpt",  0, 0);
  PlotStack2D("cutseltrack_vs_jetpt",  0, 0);
  PlotStack2D("sv_track_vs_jetpt",  0, 0);

  PlotStack2D("sv_mass_vs_flightDistSignCut",  0, 0);
  PlotStack2D("sv_mass_vs_flightDistCut",  0, 0);

  PlotStack2D("avg_sv_mass_vs_jetpt",  0, 0);

  PlotStack2D("sv_deltar_jet_vs_jetpt",  0, 0);
  PlotStack2D("sv_deltar_sum_jet_vs_jetpt",  0, 0);
  PlotStack2D("sv_deltar_sum_dir_vs_jetpt",  0, 0);
  PlotStack2D("muon_ptrel_vs_jetpt",  0, 0);
  PlotStack2D("muon_DeltaR_vs_jetpt",  0, 0);


 }
//  else {

// // for btagmet dataset 


 PlotStack("muons_multiplicity", "muon multiplicity" ,date, 0, 1, 1);
  PlotData("muons_multiplicity_centered",   "muon multiplicity",    date, 1, 1, 0);    
  PlotStack("muon_Ip3d", "muon 3D IP", date, 0, 1, 1);
  PlotStack("muon_Ip2d", "muon 2D IP", date, 0, 1, 1);
  PlotStack("muon_Sip3d", "muon 3D IP sig.", date, 0, 1, 1);
   PlotStack("muon_Sip2d", "muon 2D IP sig." date, 0, 1, 1);
 PlotStack("muon_ptrel","muon ptrel", date, 0, 0, 1);
 PlotStack("muon_Pt", "muon pt", date, 0, 1, 1);
 PlotStack("muon_DeltaR", "muon delta R", date, 0, 0, 1);
 // PlotStack("muon_Ratio", date, 0, 0, 1);


   PlotStack("npv","number of PV", date, 0, 0,1);
   PlotStack("npv_no_scaled","number of PV", date, 0, 0,1);
   PlotStack("all_jetpt","jet p_{t}",date, 1, 1, 1);

   PlotStack("discri_tche","TCHE discriminator",date, 1, 1, 1);
   PlotStack("discri_tchp","TCHP discriminator",date, 1, 1, 1);
  PlotStack("discri_ssche0","SSVHE discriminator", date, 1, 1, 1);
  PlotStack("discri_ssche", "SSVHE discriminator", date, 0, 0, 1);
  PlotStack("discri_sschp0","SSVHP discriminator", date, 1, 1, 1);
  PlotStack("discri_sschp", "SSVHP discriminator", date, 0, 0, 1);
  PlotStack("discri_jetprob", "JP discriminator", date, 1, 1, 1);
  PlotStack("discri_jetbprob", "JBP discriminator",date, 1, 1, 1);

  PlotStack("n_tracks_jet", "nr. of tracks in jet",  date, 1, 0, 1);
  PlotStack("n_seltracks_jet","nr. of selected tracks",  date, 1, 0, 1);
  PlotStack("pt_tracks", "track p_{t}", date, 1, 1, 1);
  PlotStack("pt_seltracks", "track p_{t}", date, 1, 1, 1);

  // IP
  PlotStack("IP3d1",  "1st track 3D IP", date, 1, 1, 1);
  PlotStack("IP3d2",  "2nd track 3D IP",date, 1, 1, 1);
  PlotStack("IP3d3",  "3rd track 3D IP",date, 1, 1, 1);
  PlotStack("IP3d1sig", "1st track 3D IP significance", date, 1, 1, 1);
  PlotStack("IP3d2sig", "2nd track 3D IP significance", date, 1, 1, 1);
  PlotStack("IP3d3sig", "3rd track 3D IP significance", date, 1, 1, 1);

  PlotStack("IP3d1sorted","1st track 3D IP",  date, 1, 1, 1);
  PlotStack("IP3d2sorted","2nd track 3D IP",  date, 1, 1, 1);
  PlotStack("IP3d3sorted","3rd track 3D IP",  date, 1, 1, 1);
  PlotStack("IP3d1sigsorted", "1st track 3D IP significance", date, 1, 1, 1);
  PlotStack("IP3d2sigsorted", "2nd track 3D IP significance", date, 1, 1, 1);
  PlotStack("IP3d3sigsorted", "3rd track 3D IP significance", date, 1, 1, 1);

  PlotStack("trackNHits", "nr. of hits", date, 1, 1, 1);
  PlotStack("trackNPixelHits", "nr. of pixel hits", date, 1, 1, 1);
  PlotStack("trackNormChi2", "norm. #chi^{2}", date, 1, 1, 1);
  PlotStack("trackTransverseMomentum", "p_{t}", date, 1, 1, 1);
  PlotStack("trackLongitudinalIP", "longitudinal IP", date, 1, 1, 1);
  PlotStack("trackIP2d", "2D IP", date, 1, 1, 1);
  PlotStack("trackDistJetAxis", "distance to jet axis", date, 1, 1, 1);
  PlotStack("trackDecayLength", "decay length", date, 1, 1, 1);

  PlotStack("trackNHits_cut","nr. of hits",date, 1, 1, 1);
  PlotStack("trackNPixelHits_cut","nr. of pixel hits", date, 1, 1, 1);
  PlotStack("trackNormChi2_cut", "norm. #chi^{2}",date, 1, 1, 1);
  PlotStack("trackTransverseMomentum_cut","track p_{t}",date, 1, 1, 1);
  PlotStack("trackLongitudinalIP_cut", "longitudinal IP", date, 1, 1, 1);
  PlotStack("trackIP2d_cut", "2D IP", date, 1, 1, 1);
  PlotStack("trackDistJetAxis_cut", "distance to jet axis", date, 1, 1, 1);
  PlotStack("trackDecayLength_cut", "decay length", date, 1, 1, 1);

  PlotStack("trackIP3d", "3D IP", date, 1, 1, 1);
  PlotStack("trackIP3dError", "3D IP error", date, 1, 1, 1);
  PlotStack("trackIP3dsig", "3D IP significance", date, 1, 1, 1);
  PlotStack("trackIP3d_sel", "3D IP", date, 1, 1, 1);
  PlotStack("trackIP3dError_sel", "3D IP error", date, 1, 1, 1);
  PlotStack("trackIP3dsig_sel", "3D IP significance", date, 1, 1, 1);
  PlotStack("trackIP3d_cutsel", "3D IP",  date, 1, 1, 1);
  PlotStack("trackIP3dError_cutsel", "3D IP error", date, 1, 1, 1);
  PlotStack("trackIP3dsig_cutsel", "3D IP significance", date, 1, 1, 1);

  // SV
  PlotStack("sv_nvertices0", "nr. of SV", date, 0, 1, 1);
  PlotStack("sv_nvertices",  "nr. of SV", date, 0, 1, 1);
  PlotStack("sv_jetpt", "jet p_{t}", date, 0, 1, 1);
  PlotStack("sv_tracksel", "SV track multiplicity", date, 0, 0, 1);
  PlotStack("sv_trackmul", "SV track multiplicity", date, 0, 0, 1);

  PlotStack("sv_flightsig2d", "2D flight significance", date, 0, 1, 1);
  PlotStack("sv_flightsig3d", "3D flight significance", date, 0, 1, 1);
  PlotStack("sv_flightsig3d_3tr", "3-track 3D flight significance", date, 0, 1, 1);
  PlotStack("sv_flightdis2d", "2D flight distance" ,date, 0, 1, 1);
  PlotStack("sv_flightdis3d", "2D flight distance", date, 0, 1, 1);

  PlotStack("sv_normchi2","norm. #chi^{2}", date, 0, 1, 1);
  PlotStack("sv_mass", "SV mass", date, 0, 0, 1);
  PlotStack("sv_mass_3tr", "3-track SV mass", date, 0, 0, 1);
  PlotStack("sv_eratio", "SV energy ratio", date, 0, 0, 1);
  PlotStack("sv_ipsigcharm", "2D IP significance", date, 0, 1, 1);
   
  PlotStack("sv_vtx_pt", "vertex p_{t}", date, 0, 1, 1);
  PlotStack("sv_vtxdir_eta", "vertex #eta", date, 0, 0, 1);
  PlotStack("sv_vtxdir_phi", "vertex #phi", date, 0, 0, 1);
 
  PlotStack("sv_deltar_jet",    "#Delta R(vertex dir., jet)"            , date, 0, 1, 1);
  PlotStack("sv_deltar_sum_jet","#Delta R(vertex {#vec p}, jet)"          ,date, 0, 1, 1);
  PlotStack("sv_deltar_sum_dir","#Delta R(vertex {#vec p}, vertex dir.)"  ,date, 0, 1, 1);

  PlotStack("n_cutseltracks_jet", "nr. of tracks", date, 1, 0, 1);
  PlotStack("pt_cutseltracks", "track p_{t}", date, 1, 1, 1);

  // IP
  PlotStack("IP3d1Errorsorted","1st track 3D IP error", date, 1, 1, 1);
  PlotStack("IP3d2Errorsorted","2nd track 3D IP error", date, 1, 1, 1);
  PlotStack("IP3d3Errorsorted","3rd track 3D IP error", date, 1, 1, 1);
  PlotStack("trackIP3d_bin1_cutsel", "3D IP", date, 1, 1, 1);
  PlotStack("trackIP3d_bin2_cutsel","3D IP",date, 1, 1, 1);
  PlotStack("trackIP3d_bin3_cutsel","3D IP",date, 1, 1, 1);
  PlotStack("trackIP3d_bin4_cutsel","3D IP",date, 1, 1, 1);
  PlotStack("trackIP3d_bin5_cutsel","3D IP",date, 1, 1, 1);
  PlotStack("trackIP3d_bin6_cutsel","3D IP",date, 1, 1, 1);


 //  TagRate("discri_tche", "TCHE discr. cut", 1,1,1);
//   TagRate("discri_tchp", "TCHP discr. cut", 1,1,1);
//   TagRate("discri_ssche","SSVHE discr. cut", 0,0,1);
//   TagRate("discri_sschp","SSVHP discr. cut", 0,0,1);
//   TagRate("discri_jetprob", "JP discr. cut", 1,1,1);
//   TagRate("discri_jetbprob", "JBP discr. cut", 1,1,1);


  PlotData("IP3d2sig0", "2nd track 3D IP significance", date, 1, 1, 1);
  PlotData("IP3d3sig0","3nd track 3D IP significance",date, 1, 1, 1);
  PlotData("ntracks_jet","nr. of tracks in jet", date, 1, 1, 1);
  PlotData("nseltracks_jet","nr. of selected tracks", date, 1, 1, 1);
  PlotData("ncutseltracks_jet","nr. of selected tracks",date, 1, 1, 1);

  PlotData("pt_tracks", "track p_{t}", date, 1, 1, 1);
  PlotData("pt_seltracks", "track p_{t}", date, 1, 1, 1);
  PlotData("pt_cutseltracks", "track p_{t}", date, 1, 1, 1);

  PlotData("nsv0", "nr. of SV", date, 1, 1, 1);
  PlotData("nsv", "nr. of SV", date, 1, 1, 1);
  PlotData("flightsig3d", "3D flight significance",date, 1, 1, 1);
  PlotData("flightsig3d_3tr","3D flight significance",date, 1, 1, 1);
  PlotData("svmass", "SV mass",  date, 0, 0, 1);
  PlotData("svmass_3tr", "3-track SV mass", date, 0, 0, 1);

  PlotData("nsv_3tr", "nr. of 3-track SV", date, 1, 1, 1);
  PlotData("nsv0_3tr", "nr. of 3-track SV", date, 1, 1, 1);

  PlotStack("IP3d1sigsorted_bin1", "1st track 3D IP significance bin1", date, 1, 1, 1);
  PlotStack("IP3d1sigsorted_bin2", "1st track 3D IP significance bin2", date, 1, 1, 1);
  PlotStack("IP3d1sigsorted_bin3", "1st track 3D IP significance bin3", date, 1, 1, 1);
  PlotStack("IP3d1sigsorted_bin4", "1st track 3D IP significance bin4", date, 1, 1, 1);
  PlotStack("IP3d1sigsorted_bin5", "1st track 3D IP significance bin5", date, 1, 1, 1);
  PlotStack("IP3d1sigsorted_bin6", "1st track 3D IP significance bin6", date, 1, 1, 1);

  PlotStack("IP3d2sigsorted_bin1", "2nd track 3D IP significance bin1", date, 1, 1, 1);
  PlotStack("IP3d2sigsorted_bin2", "2nd track 3D IP significance bin2", date, 1, 1, 1);
  PlotStack("IP3d2sigsorted_bin3", "2nd track 3D IP significance bin3", date, 1, 1, 1);
  PlotStack("IP3d2sigsorted_bin4", "2nd track 3D IP significance bin4", date, 1, 1, 1);
  PlotStack("IP3d2sigsorted_bin5", "2nd track 3D IP significance bin5", date, 1, 1, 1);
  PlotStack("IP3d2sigsorted_bin6", "2nd track 3D IP significance bin6", date, 1, 1, 1);

  PlotStack("trackIP3d_jetptbin1",   "3D IP (jet bin1)",    date, 1, 1, 1);    
  PlotStack("trackIP3d_jetptbin2",   "3D IP (jet bin2)",    date, 1, 1, 1);        
  PlotStack("trackIP3d_jetptbin3",   "3D IP (jet bin3)",    date, 1, 1, 1);          
                             
  PlotStack("IP3d1_jetptbin1",   "1st track 3D IP (jet bin1)",    date, 1, 1, 1);              
  PlotStack("IP3d1_jetptbin2",   "1st track 3D IP (jet bin2)",    date, 1, 1, 1);              
  PlotStack("IP3d1_jetptbin3",   "1st track 3D IP (jet bin3)",    date, 1, 1, 1);              
                         
  PlotStack("IP3d2_jetptbin1",   "2nd track 3D IP (jet bin1)",    date, 1, 1, 1);              
  PlotStack("IP3d2_jetptbin2",   "2nd track 3D IP (jet bin2)",    date, 1, 1, 1);              
  PlotStack("IP3d2_jetptbin3",   "2nd track 3D IP (jet bin3)",    date, 1, 1, 1);              
                        
  PlotStack("IP3d3_jetptbin1",   "3rd track 3D IP (jet bin1)",    date, 1, 1, 1);              
  PlotStack("IP3d3_jetptbin2",   "3rd track 3D IP (jet bin2)",    date, 1, 1, 1);              
  PlotStack("IP3d3_jetptbin3",   "3rd track 3D IP (jet bin3)",    date, 1, 1, 1);              
                               
  // PlotStack("IP3dsigsorted_jetptbin1",    "",    date, 1, 1, 1);      
  //  PlotStack("IP3dsigsorted_jetptbin2",    "",    date, 1, 1, 1);      
  //  PlotStack("IP3dsigsorted_jetptbin3",    "",    date, 1, 1, 1);      
                             
  PlotStack("IP3d1sigsorted_jetptbin1",   "1st track 3D IP sig. (jet bin1)",    date, 1, 1, 1);     
  PlotStack("IP3d1sigsorted_jetptbin2",   "1st track 3D IP sig. (jet bin2)",    date, 1, 1, 1);     
  PlotStack("IP3d1sigsorted_jetptbin3",   "1st track 3D IP sig. (jet bin3)",    date, 1, 1, 1);     
                             		                            
  PlotStack("IP3d2sigsorted_jetptbin1",   "2nd track 3D IP sig. (jet bin1)",    date, 1, 1, 1);     
  PlotStack("IP3d2sigsorted_jetptbin2",   "2nd track 3D IP sig. (jet bin2)",    date, 1, 1, 1);     
  PlotStack("IP3d2sigsorted_jetptbin3",   "2nd track 3D IP sig. (jet bin3)",    date, 1, 1, 1);     
                             		                            
  PlotStack("IP3d3sigsorted_jetptbin1",   "3rd track 3D IP sig. (jet bin1)",    date, 1, 1, 1);     
  PlotStack("IP3d3sigsorted_jetptbin2",   "3rd track 3D IP sig. (jet bin2)",    date, 1, 1, 1);     
  PlotStack("IP3d3sigsorted_jetptbin3",   "3rd track 3D IP sig. (jet bin3)",    date, 1, 1, 1);     
                            
  //  PlotStack("IP3dErrorsorted_jetptbin1",   "",    date, 1, 1, 1);    
  //  PlotStack("IP3dErrorsorted_jetptbin2",   "",    date, 1, 1, 1);    
  //  PlotStack("IP3dErrorsorted_jetptbin3",   "",    date, 1, 1, 1);    
                              
  PlotStack("IP3d1Errorsorted_jetptbin1",   "1st track 3D IP err. (jet bin1)",    date, 1, 1, 1);     
  PlotStack("IP3d1Errorsorted_jetptbin2",   "1st track 3D IP err. (jet bin2)",    date, 1, 1, 1);     
  PlotStack("IP3d1Errorsorted_jetptbin3",   "1st track 3D IP err. (jet bin3)",    date, 1, 1, 1);     
                                 	                                   
  PlotStack("IP3d2Errorsorted_jetptbin1",   "2nd track 3D IP err. (jet bin1)",    date, 1, 1, 1);     
  PlotStack("IP3d2Errorsorted_jetptbin2",   "2nd track 3D IP err. (jet bin2)",    date, 1, 1, 1);     
  PlotStack("IP3d2Errorsorted_jetptbin3",   "2nd track 3D IP err. (jet bin3)",    date, 1, 1, 1);     
                              		                                   
  PlotStack("IP3d3Errorsorted_jetptbin1",   "3rd track 3D IP err. (jet bin1)",    date, 1, 1, 1);     
  PlotStack("IP3d3Errorsorted_jetptbin2",   "3rd track 3D IP err. (jet bin2)",    date, 1, 1, 1);     
  PlotStack("IP3d3Errorsorted_jetptbin3",   "3rd track 3D IP err. (jet bin3)",    date, 1, 1, 1);     
          
  PlotStack("sv_mass_jetptbin1",   "2-track SV mass (jet bin1)",    date, 1, 1, 1);            
  PlotStack("sv_mass_jetptbin2",   "2-track SV mass (jet bin2)",    date, 1, 1, 1);            
  PlotStack("sv_mass_jetptbin3",   "2-track SV mass (jet bin3)",    date, 1, 1, 1);            
                            
  PlotStack("sv_mass_3tr_jetptbin1",   "3-track SV mass (jet bin1)",    date, 1, 1, 1);        
  PlotStack("sv_mass_3tr_jetptbin2",   "3-track SV mass (jet bin2)",    date, 1, 1, 1);        
  PlotStack("sv_mass_3tr_jetptbin3",   "3-track SV mass (jet bin3)",    date, 1, 1, 1);        
                             
  //  PlotStack("sv_ipsigcharm_jetptbin1",   "",    date, 1, 1, 1);      
  //  PlotStack("sv_ipsigcharm_jetptbin2",   "",    date, 1, 1, 1);      
  //  PlotStack("sv_ipsigcharm_jetptbin3",   "",    date, 1, 1, 1);      
                           
  PlotStack("sv_eratio_jetptbin1",   "SV energy ratio (jet bin1)",    date, 1, 1, 1);          
  PlotStack("sv_eratio_jetptbin2",   "SV energy ratio (jet bin2)",    date, 1, 1, 1);          
  PlotStack("sv_eratio_jetptbin3",   "SV energy ratio (jet bin3)",    date, 1, 1, 1);          
                                
  PlotStack("sv_flightsig2d_jetptbin1",   "2D flight sig. (jet bin1)",    date, 1, 1, 1);       
  PlotStack("sv_flightsig2d_jetptbin2",   "2D flight sig. (jet bin2)",    date, 1, 1, 1);       
  PlotStack("sv_flightsig2d_jetptbin3",   "2D flight sig. (jet bin3)",    date, 1, 1, 1);       
                             
  PlotStack("sv_flightsig3d_jetptbin1",   "3D flight sig. (jet bin1)",    date, 1, 1, 1);       
  PlotStack("sv_flightsig3d_jetptbin2",   "3D flight sig. (jet bin2)",    date, 1, 1, 1);       
  PlotStack("sv_flightsig3d_jetptbin3",   "3D flight sig. (jet bin3)",    date, 1, 1, 1);       
                               
  PlotStack("sv_flightdis2d_jetptbin1",   "2D flight dist. (jet bin1)",    date, 1, 1, 1);       
  PlotStack("sv_flightdis2d_jetptbin2",   "2D flight dist. (jet bin2)",    date, 1, 1, 1);       
  PlotStack("sv_flightdis2d_jetptbin3",   "2D flight dist. (jet bin3)",    date, 1, 1, 1);       
                               
  PlotStack("sv_flightdis3d_jetptbin1",   "3D flight dist. (jet bin1)",    date, 1, 1, 1);       
  PlotStack("sv_flightdis3d_jetptbin2",   "3D flight dist. (jet bin2)",    date, 1, 1, 1);       
  PlotStack("sv_flightdis3d_jetptbin3",   "3D flight dist. (jet bin3)",    date, 1, 1, 1);       
                                 
  PlotStack("sv_flightsig3d_3tr_jetptbin1",   "3-track 3D flight dist. (jet bin1)",    date, 1, 1, 1);   
  PlotStack("sv_flightsig3d_3tr_jetptbin2",   "3-track 3D flight dist. (jet bin2)",    date, 1, 1, 1);   
  PlotStack("sv_flightsig3d_3tr_jetptbin3",   "3-track 3D flight dist. (jet bin3)",    date, 1, 1, 1);   
                               


  PlotStack("sv_deltar_jet_jetptbin1",   "#Delta R(vertex dir., jet) (jet bin1)",    date, 1, 1, 1);        
  PlotStack("sv_deltar_jet_jetptbin2",   "#Delta R(vertex dir., jet) (jet bin2)",    date, 1, 1, 1);        
  PlotStack("sv_deltar_jet_jetptbin3",   "#Delta R(vertex dir., jet) (jet bin3)",    date, 1, 1, 1);        
                                
  PlotStack("sv_deltar_sum_jet_jetptbin1",   "#Delta R(vertex {#vec p}, jet) (jet bin1)",    date, 1, 1, 1);    
  PlotStack("sv_deltar_sum_jet_jetptbin2",   "#Delta R(vertex {#vec p}, jet) (jet bin2)",    date, 1, 1, 1);    
  PlotStack("sv_deltar_sum_jet_jetptbin3",   "#Delta R(vertex {#vec p}, jet) (jet bin3)",    date, 1, 1, 1);    
                               
  PlotStack("sv_deltar_sum_dir_jetptbin1",   "#Delta R(vertex {#vec p}, vertex dir.) (jet bin1)",    date, 1, 1, 1);    
  PlotStack("sv_deltar_sum_dir_jetptbin2",   "#Delta R(vertex {#vec p}, vertex dir.) (jet bin2)",    date, 1, 1, 1);    
  PlotStack("sv_deltar_sum_dir_jetptbin3",   "#Delta R(vertex {#vec p}, vertex dir.) (jet bin3)",    date, 1, 1, 1);    
            
  PlotStack("discri_tche_jetptbin1",   "TCHE discriminator (jet bin1)",    date, 1, 1, 1);          
  PlotStack("discri_tche_jetptbin2",   "TCHE discriminator (jet bin2)",    date, 1, 1, 1);          
  PlotStack("discri_tche_jetptbin3",   "TCHE discriminator (jet bin3)",    date, 1, 1, 1);          
                              
  PlotStack("discri_tchp_jetptbin1",   "TCHP discriminator (jet bin1)",    date, 1, 1, 1);          
  PlotStack("discri_tchp_jetptbin2",   "TCHP discriminator (jet bin2)",    date, 1, 1, 1);          
  PlotStack("discri_tchp_jetptbin3",   "TCHP discriminator (jet bin3)",    date, 1, 1, 1);          
                            
  PlotStack("discri_ssche0_jetptbin1",   "SSVHE discriminator (jet bin1)",    date, 1, 1, 1);        
  PlotStack("discri_ssche0_jetptbin2",   "SSVHE discriminator (jet bin2)",    date, 1, 1, 1);        
  PlotStack("discri_ssche0_jetptbin3",   "SSVHE discriminator (jet bin3)",    date, 1, 1, 1);        
                           
  PlotStack("discri_ssche_jetptbin1",   "SSVHE discriminator (jet bin1)",    date, 1, 1, 1);         
  PlotStack("discri_ssche_jetptbin2",   "SSVHE discriminator (jet bin2)",    date, 1, 1, 1);         
  PlotStack("discri_ssche_jetptbin3",   "SSVHE discriminator (jet bin3)",    date, 1, 1, 1);         
                         
  PlotStack("discri_sschp0_jetptbin1",   "SSVHP discriminator (jet bin1)",    date, 1, 1, 1);        
  PlotStack("discri_sschp0_jetptbin2",   "SSVHP discriminator (jet bin2)",    date, 1, 1, 1);        
  PlotStack("discri_sschp0_jetptbin3",   "SSVHP discriminator (jet bin3)",    date, 1, 1, 1);        
                                
  PlotStack("discri_sschp_jetptbin1",   "SSVHP discriminator (jet bin1)",    date, 1, 1, 1);         
  PlotStack("discri_sschp_jetptbin2",   "SSVHP discriminator (jet bin2)",    date, 1, 1, 1);         
  PlotStack("discri_sschp_jetptbin3",   "SSVHP discriminator (jet bin3)",    date, 1, 1, 1);         
                            
  PlotStack("discri_jetprob_jetptbin1",   "JP discriminator (jet bin1)",    date, 1, 1, 1);       
  PlotStack("discri_jetprob_jetptbin2",   "JP discriminator (jet bin2)",    date, 1, 1, 1);       
  PlotStack("discri_jetprob_jetptbin3",   "JP discriminator (jet bin3)",    date, 1, 1, 1);       
                               
  PlotStack("discri_jetbprob_jetptbin1",   "JBP discriminator (jet bin1)",    date, 1, 1, 1);      
  PlotStack("discri_jetbprob_jetptbin2",   "JBP discriminator (jet bin2)",    date, 1, 1, 1);      
  PlotStack("discri_jetbprob_jetptbin3",   "JBP discriminator (jet bin3)",    date, 1, 1, 1);      

  //  PlotStack("sv_ipsigcharm_3tr",   "",    date, 1, 1, 1);              
  //  PlotStack("sv_eratio_3tr",   "3-track SV energy ratio",    date, 1, 1, 1);                  
  //  PlotStack("sv_vtx_pt_3tr",   "3-track SV vtx p_{t}",    date, 1, 1, 1);                  

  //  PlotStack("sv_trackmul_centered",   "SV track multiplicity",    date, 1, 1, 1);           
  //  PlotStack("sv_trackmul1_centered",   "SV track multiplicity",    date, 1, 1, 1);          
  //  PlotStack("sv_tracksel_centered",   "SV track multiplicity",    date, 1, 1, 1);           


     PlotStack("sv_mass_muenriched",            "sv_mass_muenriched",               date, 1, 1, 1);      
     PlotStack("IP3d2sigsorted_muenriched",     "IP3d2sigsorted_muenriched",        date, 1, 1, 1);      
     PlotStack("IP3d2sigzsorted_muenriched",    "IP3d2sigzsorted_muenriched",       date, 1, 1, 1);      
     PlotStack("sv_flightsig2d_muenriched",     "sv_flightsig2d_muenriched",        date, 1, 1, 1);      
     PlotStack("sv_flightsig3d_muenriched",     "sv_flightsig3d_muenriched",        date, 1, 1, 1);      
     PlotStack("discri_tche_muenriched",        "discri_tche_muenriched",           date, 1, 1, 1);      
     PlotStack("discri_tchp_muenriched",        "discri_tchp_muenriched",           date, 1, 1, 1);      
     PlotStack("discri_ssche_muenriched",       "discri_ssche_muenriched",          date, 1, 1, 1);      
     PlotStack("discri_sschp_muenriched",       "discri_sschp_muenriched",          date, 1, 1, 1);      
     PlotStack("muenriched_discrim",            "muenriched_discrim",               date, 1, 1, 1);      
     PlotStack("discri_jetprob_muenriched",     "discri_jetprob_muenriched",        date, 1, 1, 1);      
     PlotStack("discri_jetbprob_muenriched",    "discri_jetbprob_muenriched",       date, 1, 1, 1);      






  PlotStack2D("track_vs_jetpt",  0, 1);
  PlotStack2D("cutseltrack_vs_jetpt",  0, 1);
  PlotStack2D("sv_track_vs_jetpt",  0, 1);

  PlotStack2D("sv_mass_vs_flightDistSignCut",  0, 1);
  PlotStack2D("sv_mass_vs_flightDistCut",  0, 1);

  PlotStack2D("avg_sv_mass_vs_jetpt",  0, 1);

  PlotStack2D("sv_deltar_jet_vs_jetpt",  0, 1);
  PlotStack2D("sv_deltar_sum_jet_vs_jetpt",  0, 1);
  PlotStack2D("sv_deltar_sum_dir_vs_jetpt",  0, 1);
  PlotStack2D("muon_ptrel_vs_jetpt",  0, 1);
  PlotStack2D("muon_DeltaR_vs_jetpt",  0, 1);








//   PlotStack("npv",date, 0, 0,1);
//   PlotStack("npv_no_scaled",date, 0, 0,1);
//   PlotStack("all_jetpt",date, 1, 1, 1);

//   PlotStack("discri_tche",date, 1, 1, 1);
//   PlotStack("discri_tchp",date, 1, 1, 1);
//   PlotStack("discri_ssche0", date, 1, 1, 1);
//   PlotStack("discri_ssche", date, 0, 0, 1);
//   PlotStack("discri_sschp0", date, 1, 1, 1);
//   PlotStack("discri_sschp", date, 0, 0, 1);
//   PlotStack("discri_jetprob",date, 1, 1, 1);
//   PlotStack("discri_jetbprob",date, 1, 1, 1);

//   PlotStack("n_tracks_jet", date, 1, 0, 1);
//   PlotStack("n_seltracks_jet", date, 1, 0, 1);
//   PlotStack("pt_tracks", date, 1, 1, 1);
//   PlotStack("pt_seltracks", date, 1, 1, 1);

//   // IP
//   PlotStack("IP3d1",date, 1, 1, 1);
//   PlotStack("IP3d2",date, 1, 1, 1);
//   PlotStack("IP3d3",date, 1, 1, 1);
//   PlotStack("IP3d1sig",date, 1, 1, 1);
//   PlotStack("IP3d2sig",date, 1, 1, 1);
//   PlotStack("IP3d3sig",date, 1, 1, 1);

//   PlotStack("IP3d1sorted",date, 1, 1, 1);
//   PlotStack("IP3d2sorted",date, 1, 1, 1);
//   PlotStack("IP3d3sorted",date, 1, 1, 1);
//   PlotStack("IP3d1sigsorted",date, 1, 1, 1);
//   PlotStack("IP3d2sigsorted",date, 1, 1, 1);
//   PlotStack("IP3d3sigsorted",date, 1, 1, 1);

//   PlotStack("trackNHits",date, 1, 1, 1);
//   PlotStack("trackNPixelHits",date, 1, 1, 1);
//   PlotStack("trackNormChi2",date, 1, 1, 1);
//   PlotStack("trackTransverseMomentum",date, 1, 1, 1);
//   PlotStack("trackLongitudinalIP",date, 1, 1, 1);
//   PlotStack("trackIP2d",date, 1, 1, 1);
//   PlotStack("trackDistJetAxis",date, 1, 1, 1);
//   PlotStack("trackDecayLength",date, 1, 1, 1);

//   PlotStack("trackNHits_cut",date, 1, 1, 1);
//   PlotStack("trackNPixelHits_cut",date, 1, 1, 1);
//   PlotStack("trackNormChi2_cut",date, 1, 1, 1);
//   PlotStack("trackTransverseMomentum_cut",date, 1, 1, 1);
//   PlotStack("trackLongitudinalIP_cut",date, 1, 1, 1);
//   PlotStack("trackIP2d_cut",date, 1, 1, 1);
//   PlotStack("trackDistJetAxis_cut",date, 1, 1, 1);
//   PlotStack("trackDecayLength_cut",date, 1, 1, 1);

//   PlotStack("trackIP3d",date, 1, 1, 1);
//   PlotStack("trackIP3dError",date, 1, 1, 1);
//   PlotStack("trackIP3dsig",date, 1, 1, 1);
//   PlotStack("trackIP3d_sel",date, 1, 1, 1);
//   PlotStack("trackIP3dError_sel",date, 1, 1, 1);
//   PlotStack("trackIP3dsig_sel",date, 1, 1, 1);
//   PlotStack("trackIP3d_cutsel",date, 1, 1, 1);
//   PlotStack("trackIP3dError_cutsel",date, 1, 1, 1);
//   PlotStack("trackIP3dsig_cutsel",date, 1, 1, 1);

//   // SV
//   PlotStack("sv_nvertices0",date, 0, 1, 1);
//   PlotStack("sv_nvertices",date, 0, 1, 1);
//   PlotStack("sv_jetpt",date, 0, 1, 1);
//   PlotStack("sv_tracksel", date, 0, 0, 1);
//   PlotStack("sv_trackmul", date, 0, 0, 1);

//   PlotStack("sv_flightsig2d",date, 0, 1, 1);
//   PlotStack("sv_flightsig3d",date, 0, 1, 1);
//   PlotStack("sv_flightsig3d_3tr",date, 0, 1, 1);
//   PlotStack("sv_flightdis2d",date, 0, 1, 1);
//   PlotStack("sv_flightdis3d",date, 0, 1, 1);

//   PlotStack("sv_normchi2",date, 0, 1, 1);
//   PlotStack("sv_mass", date, 0, 0, 1);
//   PlotStack("sv_mass_3tr", date, 0, 0, 1);
//   PlotStack("sv_eratio", date, 0, 0, 1);
//   PlotStack("sv_ipsigcharm",date, 0, 1, 1);
   
//   PlotStack("sv_vtx_pt",date, 0, 1, 1);
//   PlotStack("sv_vtxdir_eta", date, 0, 0, 1);
//   PlotStack("sv_vtxdir_phi", date, 0, 0, 1);
 
//   PlotStack("sv_deltar_jet",date, 0, 1, 1);
//   PlotStack("sv_deltar_sum_jet",date, 0, 1, 1);
//   PlotStack("sv_deltar_sum_dir",date, 0, 1, 1);

//   PlotStack("n_cutseltracks_jet", date, 1, 0, 1);
//   PlotStack("pt_cutseltracks", date, 1, 1, 1);

//   // IP
//   PlotStack("IP3d1Errorsorted",date, 1, 1, 1);
//   PlotStack("IP3d2Errorsorted",date, 1, 1, 1);
//   PlotStack("IP3d3Errorsorted",date, 1, 1, 1);
//   PlotStack("trackIP3d_bin1_cutsel",date, 1, 1, 1);
//   PlotStack("trackIP3d_bin2_cutsel",date, 1, 1, 1);
//   PlotStack("trackIP3d_bin3_cutsel",date, 1, 1, 1);
//   PlotStack("trackIP3d_bin4_cutsel",date, 1, 1, 1);
//   PlotStack("trackIP3d_bin5_cutsel",date, 1, 1, 1);
//   PlotStack("trackIP3d_bin6_cutsel",date, 1, 1, 1);


//   TagRate("discri_tche", 1,1,1);
//   TagRate("discri_tchp", 1,1,1);
//   TagRate("discri_ssche", 0,0,1);
//   TagRate("discri_sschp", 0,0,1);
//   TagRate("discri_jetprob", 1,1,1);
//   TagRate("discri_jetbprob", 1,1,1);


//   PlotData("IP3d2sig0",date, 1, 1, 1);
//   PlotData("IP3d3sig0",date, 1, 1, 1);
//   PlotData("ntracks_jet",date, 1, 1, 1);
//   PlotData("nseltracks_jet",date, 1, 1, 1);
//   PlotData("ncutseltracks_jet",date, 1, 1, 1);
//   PlotData("pt_tracks",date, 1, 1, 1);
//   PlotData("pt_seltracks",date, 1, 1, 1);
//   PlotData("pt_cutseltracks",date, 1, 1, 1);

//   PlotData("nsv",date, 1, 1, 1);
//   PlotData("flightsig3d",date, 1, 1, 1);
//   PlotData("flightsig3d_3tr",date, 1, 1, 1);
//   PlotData("svmass", date, 0, 0, 1);
//   PlotData("svmass_3tr", date, 0, 0, 1);
//   PlotData("nsv_3tr",date, 1, 1, 1);
//   PlotData("nsv0_3tr",date, 1, 1, 1);

//   PlotStack2D("track_vs_jetpt",  0, 1);
//   PlotStack2D("cutseltrack_vs_jetpt",  0, 1);
//   PlotStack2D("sv_track_vs_jetpt",  0, 1);




//  }







}
