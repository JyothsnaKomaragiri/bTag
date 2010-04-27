
#!/bin/sh

### Loop over categories
for category in `echo "loosePF" "standardPF" "looseCalo" "standardCalo"`
do

### Loop over bins
for bin in `echo "GLOBAL" "PT_10-20" "PT_20-40" "PT_40-99999" "ETA_0-1v5_PT_10-20" "ETA_1v5-2v5_PT_10-20" "ETA_0-1v5_PT_20-40" "ETA_1v5-2v5_PT_20-40" "ETA_0-1v5_PT_40-99999" "ETA_1v5-2v5_PT_40-99999"`
do

###############################################################
################# Secondary Vertex TagInfo
###############################################################
./NormoverlayMCData.py -r svjetNSecondaryVertices ${category}  ${bin} 'No. of secondary vertices per jet' 'MC Normalized to Data' 0.5 4.5

./NormoverlayMCData.py -r  svtrackMomentum ${category}  ${bin} 'track p [GeV/c]' 'MC Normalized to Data' 0 100
./NormoverlayMCData.py -r  svtrackDeltaR ${category}  ${bin} '#DeltaR(track, jet axis)' 'MC Normalized to Data' -0.1 0.7

./NormoverlayMCData.py -r svtrackPtRel ${category}  ${bin} 'track p_{T}^{rel} [GeV/c]' 'MC Normalized to Data' 0 10
./NormoverlayMCData.py -r svtrackEtaRel ${category}  ${bin} 'track #eta^{rel}' 'MC Normalized to Data' 0 10

./NormoverlayMCData.py -r svtrackPPar ${category}  ${bin} 'track parallel momentum [GeV/c]' 'MC Normalized to Data' 0 250
./NormoverlayMCData.py -r -l svtrackPParRatio ${category}  ${bin} 'track parallel momentum ratio' 'MC Normalized to Data' 0 10
./NormoverlayMCData.py -r svtrackJetDist ${category}  ${bin} 'minimum track approach distance to jet axis all jets' 'MC Normalized to Data' -10 0
./NormoverlayMCData.py -r svtrackSumJetDeltaR ${category}  ${bin} '#DeltaR(track sum, jet axis)' 'MC Normalized to Data' -0.1 0.5

./NormoverlayMCData.py -r svtrackSip2dSig ${category}  ${bin} 'signed transverse IP significance' 'MC Normalized to Data' -50 50
./NormoverlayMCData.py -r svtrackSip2dVal ${category}  ${bin} 'signed transverse IP [cm]' 'MC Normalized to Data' -0.3 0.3

./NormoverlayMCData.py -r svtrackSip3dSig ${category}  ${bin} 'signed 3D IP significance' 'MC Normalized to Data' -80 80
./NormoverlayMCData.py -r svtrackSip3dVal ${category}  ${bin} 'signed 3D IP [cm]' 'MC Normalized to Data' -3.1 3.1

./NormoverlayMCData.py -r -l svtrackSip3dSigAboveCharm ${category}  ${bin} 'first track 3D signed IP above charm' 'MC Normalized to Data' -50 50 

./NormoverlayMCData.py -r svflightDistance2dVal_CAT1 ${category}  ${bin} 'transverse flight distance [cm]' 'MC Normalized to Data' 0 2.5
./NormoverlayMCData.py -r svflightDistance2dSig_CAT1 ${category}  ${bin} 'transverse flight distance significance' 'MC Normalized to Data' 0 80

./NormoverlayMCData.py -r svflightDistance3dVal_CAT1 ${category}  ${bin} '3D flight distance [cm]' 'MC Normalized to Data' 0 15
./NormoverlayMCData.py -r svflightDistance3dSig_CAT1 ${category}  ${bin} '3D flight distance significance' 'MC Normalized to Data' 0 80

./NormoverlayMCData.py -r svvertexNTracks_CAT1 ${category}  ${bin} 'no. of tracks at SV' 'MC Normalized to Data' 0.5 11.5
./NormoverlayMCData.py -r svvertexMass_CAT1 ${category}  ${bin} 'vertex mass [GeV/c^{2}]' 'MC Normalized to Data' 0 3.5
./NormoverlayMCData.py -r -l svvertexEnergyRatio_CAT1 ${category}  ${bin} 'fraction of charged jet energy at SV' 'MC Normalized to Data' 0 1
./NormoverlayMCData.py -r svvertexJetDeltaR_CAT1 ${category}  ${bin} '#DeltaR(sv, jet axis)' 'MC Normalized to Data' -0.1 0.7

###############################################################
################# Impact Parameter TagInfo
###############################################################
./NormoverlayMCData.py -r ipdecLen ${category}  ${bin} 'Decay length' 'MC Normalized to Data' -0.5 5
./NormoverlayMCData.py -r -l ipjetDist ${category}  ${bin} 'Jet distance' 'MC Normalized to Data' -0.15 0.01

./NormoverlayMCData.py -r ipselTrksNbr_2D ${category}  ${bin} 'no. of selected tracks for 2D in jet' 'MC Normalized to Data' -0.5 19.5
./NormoverlayMCData.py -r ipselTrksNbr_3D ${category}  ${bin} 'no. of selected tracks for 3D in jet' 'MC Normalized to Data' -0.5 19.5

### 2D plots
./NormoverlayMCData.py -r ipip_2D ${category}  ${bin} '2D IP value' 'MC Normalized to Data' -0.2 0.2
./NormoverlayMCData.py -r ipipe_2D ${category}  ${bin} '2D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips_2D ${category}  ${bin} '2D IP significance' 'MC Normalized to Data' -40 40
./NormoverlayMCData.py -r ipprob_2D ${category}  ${bin} '2D IP probability' 'MC Normalized to Data' -1.1 1.1

./NormoverlayMCData.py -r ipip1_2D ${category}  ${bin} '1^{st} track 2D IP value' 'MC Normalized to Data' -0.2 0.2

./NormoverlayMCData.py -r ipipe1_2D ${category}  ${bin} '1^{st} track 2D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips1_2D ${category}  ${bin} '1^{st} track 2D IP significance' 'MC Normalized to Data' -40 40

./NormoverlayMCData.py -r ipip2_2D ${category}  ${bin} '2^{nd} track 2D IP value' 'MC Normalized to Data' -0.2 0.2
./NormoverlayMCData.py -r ipipe2_2D ${category}  ${bin} '2^{nd} track 2D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips2_2D ${category}  ${bin} '2^{nd} track 2D IP significance' 'MC Normalized to Data' -40 40

./NormoverlayMCData.py -r ipip3_2D ${category}  ${bin} '3^{rd} track 2D IP value' 'MC Normalized to Data' -0.2 0.2
./NormoverlayMCData.py -r ipipe3_2D ${category}  ${bin} '3^{rd} track 2D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips3_2D ${category}  ${bin} '3^{rd} track 2D IP significance' 'MC Normalized to Data' -40 40

### 3D plots
./NormoverlayMCData.py -r ipip_3D ${category}  ${bin} '3D IP value' 'MC Normalized to Data' -0.2 0.2
./NormoverlayMCData.py -r ipipe_3D ${category}  ${bin} '3D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips_3D ${category}  ${bin} '3D IP significance' 'MC Normalized to Data' -40 40
./NormoverlayMCData.py -r ipprob_3D ${category}  ${bin} '3D IP probability' 'MC Normalized to Data' -1.1 1.1

./NormoverlayMCData.py -r ipip1_3D ${category}  ${bin} '1^{st} track 3D IP value' 'MC Normalized to Data' -0.2 0.2
./NormoverlayMCData.py -r ipipe1_3D ${category}  ${bin} '1^{st} track 3D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips1_3D ${category}  ${bin} '1^{st} track 3D IP significance' 'MC Normalized to Data' -40 40

./NormoverlayMCData.py -r ipip2_3D ${category}  ${bin} '2^{nd} track 3D IP value' 'MC Normalized to Data' -0.2 0.2
./NormoverlayMCData.py -r ipipe2_3D ${category}  ${bin} '2^{nd} track 3D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips2_3D ${category}  ${bin} '2^{nd} track 3D IP significance' 'MC Normalized to Data' -40 40

./NormoverlayMCData.py -r ipip3_3D ${category}  ${bin} '3^{rd} track 3D IP value' 'MC Normalized to Data' -0.2 0.2
./NormoverlayMCData.py -r ipipe3_3D ${category}  ${bin} '3^{rd} track 3D IP error' 'MC Normalized to Data' 0 0.05
./NormoverlayMCData.py -r ipips3_3D ${category}  ${bin} '3^{rd} track 3D IP significance' 'MC Normalized to Data' -40 40

###############################################################
################# Electron TagInfo
###############################################################
 ./NormoverlayMCData.py -r 'el1st lepton delta R' ${category}  ${bin} '#DeltaR(electron, jet axis)' 'MC Normalized to Data' 0 0.5
 ./NormoverlayMCData.py -r 'el1st lepton energy ratio' ${category}  ${bin}   'Electron p_{T}/Energy^{jet}' 'MC Normalized to Data' 0 1.4
 ./NormoverlayMCData.py -r 'el1st lepton eta rel'    ${category}  ${bin}   'Electron #eta^{rel}' 'MC Normalized to Data' -1 10
 ./NormoverlayMCData.py -r 'el1st lepton p0 par' ${category}  ${bin} 'Electron p_{T}^{rel} in the B rest frame' 'MC Normalized to Data' 0 3
 ./NormoverlayMCData.py -r 'el1st lepton pT rel' ${category}  ${bin} 'Electron p_{T}^{rel} [GeV/C]' 'MC Normalized to Data'  0 3
 ./NormoverlayMCData.py -r 'el1st lepton pT'    ${category}  ${bin} 'Electron p_{T} [GeV/C]'  'MC Normalized to Data' 0 20
 ./NormoverlayMCData.py -r 'el1st lepton parallel energy ratio'   ${category}  ${bin} 'Electron Ppar/Energy^{jet}' 'MC Normalized to Data' 0 1.4
 ./NormoverlayMCData.py -r 'el1st lepton sip2d'	${category}  ${bin} 'Electron signed 2D impact parameter significance' 'MC Normalized to Data' -20 30
 ./NormoverlayMCData.py -r 'el1st lepton sip3d'	${category}  ${bin} 'Electron signed 3D impact parameter significance' 'MC Normalized to Data' -20 30

###############################################################
################# Muon TagInfo
###############################################################
 ./NormoverlayMCData.py -r 'mu1st lepton delta R'	${category}  ${bin} '#DeltaR(muon, jet axis)' 'MC Normalized to Data' 0 0.5
 ./NormoverlayMCData.py -r 'mu1st lepton energy ratio'	${category}  ${bin} 'Muon p_{T}/Energy^{jet}'  'MC Normalized to Data' 0 1.2
 ./NormoverlayMCData.py -r 'mu1st lepton eta rel'	${category}  ${bin} 'Muon #eta^{rel}'   'MC Normalized to Data' -1 10
 ./NormoverlayMCData.py -r 'mu1st lepton p0 par'	${category}  ${bin} 'Muon p_{T}^{rel} in the B rest frame'  'MC Normalized to Data' 0 3
 ./NormoverlayMCData.py -r 'mu1st lepton pT rel'	${category}  ${bin} 'Muon p_{T}^{rel} [GeV/C]'  'MC Normalized to Data' 0 3
 ./NormoverlayMCData.py -r 'mu1st lepton pT'	${category}  ${bin} 'Muon p_{T} [GeV/C]'  'MC Normalized to Data' 0 20
 ./NormoverlayMCData.py -r 'mu1st lepton parallel energy ratio'   ${category}  ${bin} 'Muon Ppar/Energy^{jet}'  'MC Normalized to Data' 0 1.4 
 ./NormoverlayMCData.py -r 'mu1st lepton sip2d'	${category}  ${bin} 'Muon signed 2D impact parameter significance'  'MC Normalized to Data' -20 30
 ./NormoverlayMCData.py -r 'mu1st lepton sip3d'	${category}  ${bin} 'Muon signed 3D impact parameter significance'  'MC Normalized to Data' -20 30

### done with Loop over bins
done

### done with Loop over categories
done
