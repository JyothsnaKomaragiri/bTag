#include "Rtypes.h"
//##################################################
//#####   General Settings for all codes   #########
//##################################################
//------------(I)Samples------------------------------
#define bTagNtupleVersion 4
//it stands for version of the commissioning ntuples
//Version3=14May
//Version4=29Nov
//The samples are defined in the end of this file, classfied by versions.
//Each version must contain at least five variables:
//(1)const char JetDATA[]="" : the Jet data
//(2)const char MetDATA[]="" : the MET data
//(3)const char *MC_files[]={"","",.....}: the files locations
//(4)const char *MC_SampleNames[]={"","",.....}: the sample names
//(5)const Float_t MC_Weights[]={,,....}: the sample weights 
//   weight = ( filter(QCDSamples=1) * sect) /n_ev;
//The program will skip empty strings. The arrays (3)(4)(5) have to have the same size and have to be corresponding.
//------------(II) the PU reweight-------------------------------------
//From https://twiki.cern.ch/twiki/bin/viewauth/CMS/PileupInformation
const Double_t Spring11[]={0.0698146584, 0.0698146584, 0.0698146584,0.0698146584,0.0698146584,0.0698146584,0.0698146584,0.0698146584,0.0698146584,0.0698146584,0.0698146584,0.0630151648,0.0526654164,0.0402754482,0.0292988928,0.0194384503,0.0122016783,0.007207042,0.004003637,0.0020278322,0.0010739954,0.0004595759,0.0002229748,0.0001028162,4.58337152809607E-05};
const Double_t Fall2011[]={0.003388501,0.010357558,0.024724258,0.042348605,0.058279812,0.068851751,0.072914824,0.071579609,0.066811668,0.060672356,0.054528356,0.04919354,0.044886042,0.041341896,0.0384679,0.035871463,0.03341952,0.030915649,0.028395374,0.025798107,0.023237445,0.020602754,0.0180688,0.015559693,0.013211063,0.010964293,0.008920993,0.007080504,0.005499239,0.004187022,0.003096474,0.002237361,0.001566428,0.001074149,0.000721755,0.000470838,0.00030268,0.000184665,0.000112883,6.74043E-05,3.82178E-05,2.22847E-05,1.20933E-05,6.96173E-06,3.4689E-06,1.96172E-06,8.49283E-07,5.02393E-07,2.15311E-07,9.56938E-08};
//Link to a predefined PU scenario
#define npu_probs Fall2011//comment it out to let the program calculate the pudistribution from ntuples
//the file name of the PU distribution in data
//See https://twiki.cern.ch/twiki/bin/viewauth/CMS/PileupReweighting for details
#define pudistribution_data_filename "pudistRun175832_180252.root"//comment it out to reweight PU to flat distribution from 0 up to MAXPU

const UInt_t MAXPU=sizeof(npu_probs)/sizeof(const Double_t)-1;
//##############################
//#######   Samples   ##########
//##############################
#if bTagNtupleVersion == 0 //39X
const char JetDATA[]="";
const char MetDATA[]="";
const char QCD15to30[]="";
const char QCD30to50[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_30to50_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCD50to80[]="";
const char QCD80to120[]="";
const char QCD120to170[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_120to170_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCD170to300[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_170to300_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCD300to470[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_300to470_TuneZ2_7TeV_pythia6_PU/*.root";
const char *MC_files[]={};
const char *MC_SampleNames[]={};
const Float_t MC_Weights[]={};
#endif

#if bTagNtupleVersion == 1 //39X
const char JetDATA[]="";
const char MetDATA[]="";
const char QCD5to15[]="";
const char QCD15to30[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_15to30_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCD30to50[]="";
const char QCD50to80[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_50to80_TuneZ2_7TeV_pythia6_PU_v2/*.root";
const char QCD80to120[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Pt_80to120_TuneZ2_7TeV_pythia6_PU_prescale/*.root";
const char QCD120to170[]="";
const char QCD170to300[]="";
const char QCD300to470[]="";
const char QCDMu15to20[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT15to20_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCDMu20to30[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT20to30_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCDMu30to50[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT30to50_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCDMu50to80[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT50to80_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCDMu80to120[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT80to120_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCDMu120to150[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT120to150_TuneZ2_7TeV_pythia6_PU/*.root";
const char QCDMu150plus[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V1/QCD_Mu_PT150_TuneZ2_7TeV_pythia6_PU/*.root"; 
const char *MC_files[]={QCD5to15,QCD15to30,QCD30to50,QCD50to80,QCD80to120,QCD120to170,QCD170to300,QCD300to470,QCDMu15to20,QCDMu20to30,QCDMu30to50,QCDMu50to80,QCDMu80to120,QCDMu120to150,QCDMu150plus};
const char *MC_SampleNames[]={"qcd5","qcd15","qcd30","qcd50","qcd80","qcd120","qcd170","qcd300","qcdmu15","qcdmu20","qcdmu30","qcdmu50","qcdmu80","qcdmu120","qcdmu150"};
const Float_t MC_Weights[]={36750000000.  / 1648096.,//weight05
		      815900000. / 5420080.,//weight15
		      53120000.  / 3244045.,//weight30
		      6359000.   / 2739226.,//weight50
		      784300.    / 3208299.,//weight80
		      115100.    / 3045200.,//weight120
		      24260.     / 3212880.,//weight170
		      1168.      / 3060200.,//weight300
		      (0.00254    *579200000.)/2884915.,//wmu15
		      (0.00518    *236300000.)/11417239.,//wmu20
		      (0.01090    *53070000. )/11431864.,//wmu30
		      (0.02274    *6351000.  )/10748755.,//wmu50
		      (0.03700    *785100.   )/3191979.,//wmu80
		      (0.04777   *92950.    )/998503.,//wmu120
		      (0.05964   *47580.)/1022541.//wmu150
};
#endif

#if bTagNtupleVersion == 2 //311X
const char JetDATA[]="";
const char MetDATA[]="";
const char QCD15to30[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD15to30/QCD15to30/*.root";
const char QCD30to50[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD30to50/*.root";
const char QCD50to80[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD50to80/*.root";
const char QCD80to120[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD80to120/*.root";
const char QCD120to170[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD120to170/*.root";
const char QCD170to300[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD170to300/*.root";
const char QCD300to470[]="/opt/sbg/cms/ui2_data2/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCD300to470/*.root";
const char QCDMu15to20[]="/opt/sbg/cms/ui2_data1/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu15to20/*.root";
const char QCDMu20to30[]="/opt/sbg/cms/ui2_data1/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu20to30/*.root";
const char QCDMu30to50[]="/opt/sbg/cms/ui2_data1/ccollard/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu30to50/*.root";
const char QCDMu50to80[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu50to80/QCDMu50to80/*.root";
const char QCDMu80to120[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu80to120/QCDMu80to120/*.root";
const char QCDMu120to150[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu120to150/QCDMu120to150/*.root";
const char QCDMu150plus[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V3/bTagCommissioning_30_03_11/QCDMu150/QCDMu150/*.root";
const char *MC_files[]={QCD15to30,QCD30to50,QCD50to80,QCD80to120,QCD120to170,QCD170to300,QCD300to470,QCDMu15to20,QCDMu20to30,QCDMu30to50,QCDMu50to80,QCDMu80to120,QCDMu120to150,QCDMu150plus};
const char *MC_SampleNames[]={"qcd15","qcd30","qcd50","qcd80","qcd120","qcd170","qcd300","qcdmu15","qcdmu20","qcdmu30","qcdmu50","qcdmu80","qcdmu120","qcdmu150"};
const Float_t MC_Weights[]={815900000. / 8213600.,//weight15
		      53120000.  / 6529320.,//weight30
		      6359000.   / 4301392.,//weight50
		      784300.    / 6407732.,//weight80
		      115100.    / 6090400.,//weight120
		      24260.     / 5684160.,//weight170
		      1168.      / 6336960.,//weight300
		      (0.00254    *579200000.)/2884915.,//wmu15
		      (0.00518    *236300000.)/11352301.,//wmu20
		      (0.01090    *53070000. )/10909951.,//wmu30
		      (0.02274    *6351000.  )/10686315.,//wmu50
		      (0.03700    *785100.   )/3183540.,//wmu80
		      (0.04777   *92950.    )/991024.,//wmu120
		      (0.05964   *47580.    )/1015900.//wmu150
};
#endif

#if bTagNtupleVersion == 3 // 311X DA & SV fix
const char JetDATA[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/v42x_v1/Data/link_jet/*.root";
//"/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/Data/Jet2011/*.root";
const char MetDATA[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/v42x_v1/Data/link_met/*.root";
//"/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/Data/Met2011/*.root"
const char QCD15to30[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_15to30/*.root";
const char QCD30to50[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_30to50/*.root";
const char QCD50to80[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_50to80/*.root";
const char QCD80to120[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_80to120/*.root";
const char QCD120to170[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCD_Pt_120to170/*.root";
const char QCD170to300[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_170to300/*.root";
const char QCD300to470[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDPt_300to470/*.root";
const char QCDMu15to20[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_15to20/*.root";
const char QCDMu20to30[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_20to30/*.root";
const char QCDMu30to50[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCDMuEnriched_Pt-30to50/*.root";
const char QCDMu50to80[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCDMuEnriched_Pt-50to80/*.root";
const char QCDMu80to120[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/QCDMuEnriched_Pt-80to120/*.root";
const char QCDMu120to150[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_120to150/*.root";
const char QCDMu150plus[]="/opt/sbg/data/data1/cms/ccollard/files/btagCommNtuple/V4_DA_SVfix/MC/14MayQCDMuEnrichedPt_150/*.root";
const char *MC_files[]={QCD15to30,QCD30to50,QCD50to80,QCD80to120,QCD120to170,QCD170to300,QCD300to470,QCDMu15to20,QCDMu20to30,QCDMu30to50,QCDMu50to80,QCDMu80to120,QCDMu120to150,QCDMu150plus};
const char *MC_SampleNames[]={"qcd15","qcd30","qcd50","qcd80","qcd120","qcd170","qcd300","qcdmu15","qcdmu20","qcdmu30","qcdmu50","qcdmu80","qcdmu120","qcdmu150"};
const Float_t MC_Weights[]={815900000. / 8213600.,//weight15
		      53120000.  / 6529320.,//weight30
		      6359000.   / 4301392.,//weight50
		      784300.    / 6407732.,//weight80
		      115100.    / 6090400.,//weight120
		      24260.     / 5684160.,//weight170
		      1168.      / 6336960.,//weight300
		      (0.00254    *579200000.)/2884915.,//wmu15
		      (0.00518    *236300000.)/11352301.,//wmu20
		      (0.01090    *53070000. )/10909951.,//wmu30
		      (0.02274    *6351000.  )/10686315.,//wmu50
		      (0.03700    *785100.   )/3183540.,//wmu80
		      (0.04777   *92950.    )/991024.,//wmu120
		      (0.05964   *47580.    )/1015900.//wmu150
};
#endif

#if bTagNtupleVersion == 4
const char JetDATA[]="/afs/cern.ch/user/z/zhangjin/MetaData/bTaggingNtuple_29Nov2011_Jet_Run2011B-PromptReco-v1/*.root";
const char MetDATA[]="";
const char QCD120to170[]="";
const char QCD15to3000[]="/afs/cern.ch/user/z/zhangjin/MetaData/bTaggingNtuple_29Nov2011_QCD_Pt-15to3000/*.root";
const char *MC_files[]={QCD15to3000};
const char *MC_SampleNames[]={"qcd15to3000"};
const Float_t MC_Weights[]={1.};
#endif
