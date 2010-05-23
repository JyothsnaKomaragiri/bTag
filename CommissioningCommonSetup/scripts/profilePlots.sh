#!/bin/sh

### Loop over categories
#for category in `echo "loosePF" "standardPF" "looseCalo" "standardCalo"`
#for category in `echo "standardPF" "standardCalo"`
for category in `echo "standardPF"`
do

### Loop over bins
#for bin in `echo "GLOBAL" "PT_10-20" "PT_20-40" "PT_40-99999" "ETA_0-1v5_PT_10-20" "ETA_1v5-2v5_PT_10-20" "ETA_0-1v5_PT_20-40" "ETA_1v5-2v5_PT_20-40" "ETA_0-1v5_PT_40-99999" "ETA_1v5-2v5_PT_40-99999"`
for bin in `echo "GLOBAL"`
do

###############################################################
################# Impact Parameter TagInfo
###############################################################
### profile plots
./Profileplot.py -r protrackMultVsJetPt         ${category}  ${bin} 'Jet p_{T} [GeV/c]' 'Track Multiplicity' 
./Profileplot.py -r proselectedTrackMultVsJetPt ${category}  ${bin} 'Jet p_{T} [GeV/c]' 'Selected Track Multiplicity' 

### done with Loop over bins
done

### done with Loop over categories
done
