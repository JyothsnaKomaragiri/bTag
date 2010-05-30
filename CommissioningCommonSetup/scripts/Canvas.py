#!/usr/bin/env python
import sys, os, math, array, ROOT

#For batch mode
ROOT.gROOT.SetBatch(True)

canvasIdx = 0

class Canvas:
        def __init__(self):
		global canvasIdx
		canvasIdx += 1
		name = "c%d" % canvasIdx
		self.c = ROOT.TCanvas(name, "", 1024, 1024)
		ROOT.gPad.UseCurrentStyle()

	def cd(self):
		self.c.cd()

	def Modified(self):
		self.c.Modified()

	def Update(self):
		self.c.Update()

	def Print(self, p):
                self.c.Print("%s.png" % p)
                #self.c.Print("%s.pdf" % p)
                #self.c.Print("%s.root" % p) 		
