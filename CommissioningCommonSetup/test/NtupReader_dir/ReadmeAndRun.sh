#!/bin/bash
g++ `root-config --cflags --glibs` -o btagNtupReader btagNtupReader.C
./btagNtupReader
g++ `root-config --cflags --glibs` -o displayPlots displayPlots.C
./displayPlots