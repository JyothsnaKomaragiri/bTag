#!/usr/bin/env python
import sys, os, math, array, ROOT

#For batch mode
ROOT.gROOT.SetBatch(True)

keep = []

canvasIdx = 0

class Canvas:
	def __init__(self):
		global canvasIdx
		canvasIdx += 1
		name = "c%d" % canvasIdx
		self.c = ROOT.TCanvas(name, "", 700, 700)
		ROOT.gPad.UseCurrentStyle()

	def cd(self):
		self.c.cd()

	def Print(self, p):
#		self.c.Print("PlotsLumi/%s.png" % p)		
### For area normalization
		self.c.Print("PlotsArea/%s.png" % p) 
#		self.c.Print("PlotsArea/%s.root" % p)

def style():
	global tdrStyle

	ROOT.gROOT.SetStyle("Plain")
	ROOT.gROOT.ForceStyle()

	tdrStyle = ROOT.TStyle()
	tdrStyle.SetFrameBorderMode(0)
	tdrStyle.SetCanvasBorderMode(0)
	tdrStyle.SetPadBorderMode(0)
	tdrStyle.SetPadBorderMode(0)

#	tdrStyle.SetFrameColor(0)
	tdrStyle.SetPadColor(0)
	tdrStyle.SetCanvasColor(0)
	tdrStyle.SetStatColor(0)
	tdrStyle.SetFillColor(0)

	tdrStyle.SetPaperSize(20,26)
#	tdrStyle.SetPadTopMargin(0.08)
#	tdrStyle.SetPadBottomMargin(0.14)
	tdrStyle.SetPadRightMargin(0.04)
	tdrStyle.SetPadLeftMargin(0.16)
#	tdrStyle.SetCanvasDefH(800)
#	tdrStyle.SetCanvasDefW(800)
#	tdrStyle.SetPadGridX(1)
#	tdrStyle.SetPadGridY(1)
	tdrStyle.SetPadTickX(1)
	tdrStyle.SetPadTickY(1)

	tdrStyle.SetTextFont(42) #132
	tdrStyle.SetTextSize(0.09)
	tdrStyle.SetLabelFont(42,"xyz")
	tdrStyle.SetTitleFont(42,"xyz")
	tdrStyle.SetLabelSize(0.045,"xyz") #0.035
	tdrStyle.SetTitleSize(0.045,"xyz")
	tdrStyle.SetTitleOffset(1.5,"y")
    
	tdrStyle.SetTitleX(0.16)
	tdrStyle.SetTitleY(0.93)
	tdrStyle.SetTitleColor(1)
	tdrStyle.SetTitleTextColor(1)
	tdrStyle.SetTitleFillColor(0)
	tdrStyle.SetTitleBorderSize(1)
	tdrStyle.SetTitleFontSize(0.04)
#	tdrStyle.SetPadTopMargin(0.05)
#	tdrStyle.SetPadBottomMargin(0.13)
#	tdrStyle.SetPadLeftMargin(0.14)
#	tdrStyle.SetPadRightMargin(0.02)

	# use bold lines and markers
	tdrStyle.SetMarkerStyle(8)
	tdrStyle.SetHistLineWidth(2)
	tdrStyle.SetLineWidth(1)

	tdrStyle.SetOptTitle(1)
        tdrStyle.SetOptStat(0)

	tdrStyle.cd()

colors = [1, 2, 3, 4, 6, 7, 8, 9, 11]
markers = [20, 21, 22, 23, 24, 25, 26, 27, 28]
styles = [1, 2, 3, 4, 5, 6, 7, 8, 9]

def format(h, i, fac = 1.):
	global colors, markers, styles

	h.UseCurrentStyle()
	h.SetFillColor(0)
	h.GetXaxis().SetTitleOffset(0.9)
	h.GetYaxis().SetTitleOffset(1.22)
#	h.SetLineColor(colors[i])
#	h.SetMarkerColor(colors[i])
#	h.SetLineStyle(styles[i])
#	h.SetMarkerStyle(markers[i])
	h.SetStats(0)


def rebin(list, tmpl):
	global keep
	for i in range(len(list)):
		old = list[i]
		new = tmpl.Clone(old.GetName() + "_new")
		keep.append(new)
		for j in range(old.GetNbinsX()):
			new.Fill(old.GetBinCenter(j), old.GetBinContent(j))
		list[i] = new

def prelim(header):
	t = ROOT.TPaveText(0.4, 0.92, 0.9, 0.97, "brNDC")
	title = " "

	if header == "GLOBAL":
		title = "p_{T} > 10 GeV and |#eta| < 2.5"
	elif header == "PT_10-20":
		title = "10 < p_{T} < 20 GeV and |#eta| < 2.5"
	elif header == "PT_20-40":
		title = "20 < p_{T} < 40 GeV and |#eta| < 2.5"
	elif header == "PT_40-99999" :
		title = "p_{T} > 40 GeV and |#eta| < 2.5"
	elif header == "ETA_0-1v5_PT_40-99999" :
		title = "p_{T} > 40 GeV and 0 < |#eta| < 1.5"
	else: #"ETA_1v5-2v5_PT_40-99999"
		title = "p_{T} > 40 GeV and 1.5 < |#eta| < 2.5"

	t.AddText(title)
	t.SetTextSize(0.035)
	t.SetFillStyle(0)
	t.SetBorderSize(0)
	t.SetTextAlign(13)
	t.SetMargin(0.0)
	t.SetFillColor(0)
	t.Draw("SAME")
	return t

def draw(mc, data, xTit, yTit, title, category, bintype, left, blind):
	global keep

	c = Canvas()
	keep.append(c)

	mc[2].SetFillColor(ROOT.kMagenta) #Loose
	mc[1].SetFillColor(ROOT.kBlue) #Tight
	mc[0].SetFillColor(ROOT.kRed) #HighPur

	for i in range(3):
		data[i].Sumw2()
		data[i].SetMarkerSize(1.2)
		data[i].SetMarkerColor(1)
		data[i].SetMarkerStyle(20+i)


################################# LINEAR PLOT ################################# 
	c.cd()
	ROOT.gPad.SetLogy(False)

	for i in range(3):

		f1 = 1.4
		data[i].SetMaximum( max(data[i].GetMaximum(), mc[i].GetMaximum()) * f1)
		
		data[i].SetTitle("")
		data[i].GetXaxis().SetTitle(xTit)
		data[i].GetYaxis().SetTitle(yTit)

		data[i].Draw("E1")
		mc[i].Draw("histsame")
		data[i].Draw("sameE1")

		if left:
			leg = ROOT.TLegend(0.22, 0.63, 0.37, 0.88)
		else:
			leg = ROOT.TLegend(0.73, 0.73, 0.95, 0.88)
			leg.SetFillColor(ROOT.kWhite)
			leg.SetMargin(0.12)
			leg.SetTextSize(0.035)
			leg.SetBorderSize(0)
			
		#keep.append(leg)
		if i == 0 :
			leg.SetHeader("HighPurity")
		if i == 1 :
			leg.SetHeader("Tight")
		if i == 2 :
			leg.SetHeader("Loose")

		leg.AddEntry(data[i], "DATA")
		leg.AddEntry(mc[i], "MC", "f")
		leg.Draw()

		keep.append(prelim(bintype))

		if i == 0: qual = 'highpur'
		if i == 1: qual = 'tight'
		if i == 2: qual = 'loose'
		ntitle = title+qual
		c.Print(ntitle)

################################# LOG PLOT ################################# 
	c.cd()
	ROOT.gPad.SetLogy(True)

	for i in range(3):
		f2 = 3.0
		data[i].SetMaximum( max(data[i].GetMaximum(), mc[i].GetMaximum()) * f2)
		data[i].SetMinimum( 0.2 )

		data[i].Draw("E1")
		mc[i].Draw("histsame")
		data[i].Draw("sameE1")

		if left:
			leg = ROOT.TLegend(0.22, 0.63, 0.37, 0.88)
		else:
			leg = ROOT.TLegend(0.73, 0.73, 0.95, 0.88)
			leg.SetFillColor(ROOT.kWhite)
			leg.SetMargin(0.12)
			leg.SetTextSize(0.035)
			leg.SetBorderSize(0)
			
		#keep.append(leg)
		if i == 0 :
			leg.SetHeader("HighPurity")
		if i == 1 :
			leg.SetHeader("Tight")
		if i == 2 :
			leg.SetHeader("Loose")

		leg.AddEntry(data[i], "DATA")
		leg.AddEntry(mc[i], "MC", "f")
		leg.Draw()

		keep.append(prelim(bintype))

		if i == 0: qual = 'highpur'
		if i == 1: qual = 'tight'
		if i == 2: qual = 'loose'
		
		newtitle = 'log_'+title+qual
		c.Print(newtitle)

################################# STACKED LINEAR PLOT ################################# 
	c.cd()
	ROOT.gPad.SetLogy(False)
	#MC stack
        mcstack = ROOT.THStack( "mcstack", title )

        #Stacking order loose, tight, highpur
	mcstack.Add(mc[2])
	mcstack.Add(mc[1])
	mcstack.Add(mc[0])

	#Data stack
        datastack = ROOT.THStack( "datastack", title )

        #Stacking order loose, tight, highpur
	datastack.Add(data[2])
	datastack.Add(data[1])
	datastack.Add(data[0])

	f1 = 1.4
#        datastack.SetMaximum( max(datastack.GetMaximum(), mcstack.GetMaximum()) * f1)

	datastack.SetTitle("")
#	datastack.GetXaxis().SetTitle(xTit)
#	datastack.GetYaxis().SetTitle(yTit)

	datastack.Draw("E1")
	mcstack.Draw("histsame")
	datastack.Draw("sameE1")

	if left:
		l = ROOT.TLegend(0.22, 0.63, 0.37, 0.88)
	else:
		l = ROOT.TLegend(0.63, 0.63, 0.95, 0.88)
	l.SetFillColor(ROOT.kWhite)
	l.SetMargin(0.12)
        l.SetTextSize(0.035)
	l.SetBorderSize(0)

	keep.append(l)
	l.AddEntry(data[0], "DATA: HighPurity")
	l.AddEntry(data[1], "DATA: Tight")
	l.AddEntry(data[2], "DATA: Loose")
	l.AddEntry(mc[0], "MC: HighPurity", "f")
	l.AddEntry(mc[1], "MC: Tight", "f")
	l.AddEntry(mc[2], "MC: Loose", "f")
	l.Draw()
	keep.append(prelim(bintype))

	c.Print(title)

################################# STACKED LOG PLOT ################################# 
	c.cd()
	ROOT.gPad.SetLogy(True)

	f2 = 3.0
#        datastack.SetMaximum( max(data.GetMaximum(), mcstack.GetMaximum()) * f2)
        datastack.SetMinimum( 0.2 )

	datastack.Draw("E1")
	mcstack.Draw("histsame")
	datastack.Draw("sameE1")

	l.Draw()
	keep.append(prelim(bintype))
	
	newtitle = 'log_'+title
	c.Print(newtitle)

#################################

def main(args, left, blind):

	mc0 = ROOT.TFile.Open("MC_MinBias.root")
	mc1 = ROOT.TFile.Open("MC_QCD_Pt_0_15.root")
	mc2 = ROOT.TFile.Open("MC_QCD_Pt_15_20.root")
	mc3 = ROOT.TFile.Open("MC_QCD_Pt_20_30.root")
	mc4 = ROOT.TFile.Open("MC_QCD_Pt_30.root")

	data = ROOT.TFile.Open("data.root")

	histo = args[0]
        ##### IP Tag Infos
	if histo[0] == 'i' and histo[1] == 'p':
		if args[1] == 'standardPF':
			histo = histo[2:] + "_standardImpactParameterPFTagInfos_"+args[2]
			pfx = "DQMData/Run 1/Btag/Run summary/TrackIPPlots_standardImpactParameterPFTagInfos_"+args[2]
		else:
			histo = histo[2:] + "_standardImpactParameterCaloTagInfos_"+args[2]
			pfx = "DQMData/Run 1/Btag/Run summary/TrackIPPlots_standardImpactParameterCaloTagInfos_"+args[2]
	else:
		pfx = "!!Nothing to draw!!"
		print "Nothing to draw"

        #####################			
	print pfx, histo


        #MinBias
	mc0 = [
		mc0.Get("%s/%sQualHighPur" % (pfx, histo)),
		mc0.Get("%s/%sQualTight" % (pfx, histo)),
		mc0.Get("%s/%sQualLoose" % (pfx, histo))
		]
        #pT 0-15
	mc1 = [
		mc1.Get("%s/%sQualHighPur" % (pfx, histo)),
		mc1.Get("%s/%sQualTight" % (pfx, histo)),
		mc1.Get("%s/%sQualLoose" % (pfx, histo))
		]
        #pT 15-20
	mc2 = [
		mc2.Get("%s/%sQualHighPur" % (pfx, histo)),
		mc2.Get("%s/%sQualTight" % (pfx, histo)),
		mc2.Get("%s/%sQualLoose" % (pfx, histo))
		]

	#pT 20-30
	mc3 = [
		mc3.Get("%s/%sQualHighPur" % (pfx, histo)),
		mc3.Get("%s/%sQualTight" % (pfx, histo)),
		mc3.Get("%s/%sQualLoose" % (pfx, histo))
		]
	#pT 30
	mc4 = [
		mc4.Get("%s/%sQualHighPur" % (pfx, histo)),
		mc4.Get("%s/%sQualTight" % (pfx, histo)),
		mc4.Get("%s/%sQualLoose" % (pfx, histo))
		]


#### Scale MC to data lumi ...Data/MC ratio
#Data total luminosity 4.79 nb-1
#/MinBias/Spring10-START3X_V26A_357ReReco-v3/GEN-SIM-RECO 0.151 nb-1
#/QCDDiJet_Pt0to15/Spring10-START3X_V26_S09-v1/GEN-SIM-RECO 0.0403 nb-1
#/QCDDiJet_Pt15to20/Spring10-START3X_V26_S09-v1/GEN-SIM-RECO 3.21 nb-1
#/QCDDiJet_Pt20to30/Spring10-START3X_V26_S09-v1/GEN-SIM-RECO 3.77 nb-1
#/QCD_Pt30/Spring10-START3X_V26_S09-v1/GEN-SIM-RECO 21.26 nb-1

# MC weights = 31.72, 118.86, 1.49, 1.27, 0.23

	scale = [ 31.72, 118.86, 1.49, 1.27, 0.23 ]
    
##################

## Adding the histos:
## scale[0]*mc0 + scale[1]*mc1 + scale[2]*mc2 + scale[3]*mc3 + scale[4]*mc4 
	for i in range(3):
		mc3[i].Add( mc3[i], mc4[i], float(scale[3]), float(scale[4]) )		
		mc2[i].Add( mc2[i], mc3[i], float(scale[2]), 1.0 )
		mc1[i].Add( mc1[i], mc2[i], float(scale[1]), 1.0 )
		mc0[i].Add( mc0[i], mc1[i], float(scale[0]), 1.0 )

	mc = mc0

#	mc.append(data.Get("%s/%sALL" % (pfx, histo)))
	
	data = [
		data.Get("%s/%sQualHighPur" % (pfx, histo)),
		data.Get("%s/%sQualTight" % (pfx, histo)),
		data.Get("%s/%sQualLoose" % (pfx, histo))
		]

#### Now scale MC to the data area
#### The MC histograms are normalized to the area of the data histograms
	for i in range(3):
		mc[i].Scale(data[i].Integral()/mc[i].Integral())

##################

	if len(args) > 5:
		mc[4].GetXaxis().SetRangeUser(float(args[5]), float(args[6]))
		mc[-1].GetXaxis().SetRangeUser(float(args[5]), float(args[6]))

	for i, j in enumerate(mc):
		j.SetTitle("")
#		format(j, i)
	
	newTitle = args[0]+"_"+args[1]+"_"+args[2]

	draw(mc, data, args[3], args[4], newTitle, args[1], args[2], left, blind)

if __name__ == '__main__':
	app = ROOT.gApplication
	sh = ROOT.TSignalHandler(ROOT.kSigInterrupt, False)
	sh.Connect("Notified()", "TApplication", app, "Terminate()")
	ROOT.gSystem.AddSignalHandler(sh)
	style()
	s = 1
	run = len(sys.argv) > s and sys.argv[s] == '-r'
	if run: s += 1
	left = len(sys.argv) > s and sys.argv[s] == '-l'
	if left: s += 1
	blind = len(sys.argv) > s and sys.argv[s] == '-t'
	if blind: s += 1
	data = main(sys.argv[s:], left, blind)
	if not run:
		app.Run()
