#!/bin/sh

### Loop over categories
for category in `echo "loosePF" "standardPF" "looseCalo" "standardCalo"`
do

### Loop over bins
for bin in `echo "GLOBAL" "PT_10-20" "PT_20-40" "PT_40-99999" "ETA_0-1v5_PT_10-20" "ETA_1v5-2v5_PT_10-20" "ETA_0-1v5_PT_20-40" "ETA_1v5-2v5_PT_20-40" "ETA_0-1v5_PT_40-99999" "ETA_1v5-2v5_PT_40-99999"`
do

./jetTags_NormoverlayMCData.py -r TEdiscr ${category}  ${bin} 'TCHE Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r TPdiscr ${category}  ${bin} 'TCHP Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r JPdiscr ${category}  ${bin} 'JetProb Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r JBdiscr ${category}  ${bin} 'JetBProb Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r SEdiscr ${category}  ${bin} 'SSV High Eff Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r SPdiscr ${category}  ${bin} 'SSV High Puity Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r CSdiscr ${category}  ${bin} 'CSV Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r CMdiscr ${category}  ${bin} 'CSV MVA Discriminator' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r MIdiscr ${category}  ${bin} 'SoftMuonByIP3dBJetTags' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r MPdiscr ${category}  ${bin} 'SoftMuonByPtBJetTags' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r MUdiscr ${category}  ${bin} 'SoftMuonBJetTags' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r EIdiscr ${category}  ${bin} 'SoftElectronByIP3dBJetTags' 'MC Normalized to Data'

./jetTags_NormoverlayMCData.py -r EPdiscr ${category}  ${bin} 'SoftElectronByPtBJetTags' 'MC Normalized to Data'

### done with Loop over bins
done

### done with Loop over categories
done