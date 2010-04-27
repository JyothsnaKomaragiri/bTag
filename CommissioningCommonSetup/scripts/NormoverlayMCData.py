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
		self.c.Print("PlotsLumi/%s.png" % p)		
### For area normalization
#		self.c.Print("PlotsArea/%s.png" % p) 
#		self.c.Print("PlotsArea/%s.eps" % p)
#		os.system("sed -e 's/0\\.95 0\\.95 0\\.95/1.0 1.0 1.0/g' -i 'PlotsArea/%s.eps'" % p)
#		os.system("epstopdf 'PlotsArea/%s.eps'" % p)

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
#	if not h.GetSumw2N():
#		h.Sumw2()
#		for j in range(h.GetNbinsX()):
#			v = h.GetBinContent(j + 1) / fac
#			h.SetBinContent(j + 1, v)
#			h.SetBinError(j + 1, math.sqrt(v))

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
	t = ROOT.TPaveText(0.2, 0.92, 0.7, 0.97, "brNDC")
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

	mc[4].SetFillColor(ROOT.kYellow) #total
	mc[3].SetFillColor(ROOT.kRed) #bottom
	mc[2].SetFillColor(ROOT.kGreen) #charm
	mc[1].SetFillColor(ROOT.kBlue) # light
	mc[0].SetFillColor(ROOT.kGray) #no info

	data.Sumw2()
	data.SetMarkerSize(1.2)
	data.SetMarkerColor(1)
#	data.SetLineColor(ROOT.kBlue)
#	data.SetMarkerColor(ROOT.kBlue)

	ROOT.gPad.SetLogy(False)
#	ROOT.gPad.SetGridy(True)

################################# LINEAR PLOT ################################# 
	c.cd()
	ROOT.gPad.SetLogy(False)
#	ROOT.gPad.SetGridy(True)

	f1 = 1.4
        stack = ROOT.THStack( "b-tag stack", title )

        #Stacking order b first, then charm, then light
	stack.Add(mc[3])
	stack.Add(mc[2])
	stack.Add(mc[1])
	stack.Add(mc[0])

        data.SetMaximum( max(data.GetMaximum(), mc[4].GetMaximum()) * f1)
#        stack.SetMinimum( 0 )

	stack.SetTitle("")

	data.SetTitle("")
	data.SetXTitle(xTit)
	data.SetYTitle(yTit)

	data.Draw("E")
	stack.Draw("histsame")
	data.Draw("sameE")

	if left:
		l = ROOT.TLegend(0.22, 0.73, 0.37, 0.88)
	else:
		l = ROOT.TLegend(0.73, 0.73, 0.95, 0.88)
	l.SetFillColor(ROOT.kWhite)
	l.SetMargin(0.12)
        l.SetTextSize(0.035)
	l.SetBorderSize(0)

	keep.append(l)
	l.AddEntry(data, "DATA")
	if not blind:
		l.AddEntry(mc[1], "MC (light)", "f")
		l.AddEntry(mc[2], "MC (charm)", "f")
		l.AddEntry(mc[3], "MC (bottom)", "f")
		l.AddEntry(mc[0], "MC (no info)", "f")
	else :
		l.AddEntry(mc[4], "MC")
	l.Draw()
	keep.append(prelim(bintype))

	c.Print(title)

################################# LOG PLOT ################################# 
	c.cd()
	ROOT.gPad.SetLogy(True)

	f2 = 2.5
        data.SetMaximum( max(data.GetMaximum(), mc[4].GetMaximum()) * f2)
        data.SetMinimum( 0.2 )

	data.Draw("E")
	stack.Draw("histsame")
	data.Draw("sameE")

	l.Draw()
	keep.append(prelim(bintype))
	
	newtitle = 'log_'+title
	c.Print(newtitle)

################################# RATIO PLOT ################################# 
	c.cd()
	ROOT.gPad.SetLogy(False)

	hratio = data.Clone()
	hratio.Clear()
	hratio.Divide(data, mc[4], 1., 1.,"B")
	hratio.SetXTitle(xTit)
	hratio.SetYTitle("data/MC ratio")

	#hratio.Sumw2()
	hratio.SetMarkerSize(1.2)
	hratio.SetMarkerColor(4)
	hratio.SetLineWidth(2)

	hratio.GetYaxis().SetRangeUser(0., 3.0)
	hratio.Draw("e")
	keep.append(prelim(bintype))

	ratio = 'ratio_'+title
	c.Print(ratio)

#################################

def main(args, left, blind):

	mc = ROOT.TFile.Open("mc.root")
	data = ROOT.TFile.Open("data.root")

	histo = args[0]
        ##### IP Tag Infos
	if histo[0] == 'i' and histo[1] == 'p':
		if args[1] == 'loosePF':
			histo = histo[2:] + "_looseImpactParameterPFTagInfos_"+args[2]
			pfx = "DQMData/Run 1/Btag/Run summary/TrackIPPlots_looseImpactParameterPFTagInfos_"+args[2]
		elif args[1] == 'standardPF':
			histo = histo[2:] + "_standardImpactParameterPFTagInfos_"+args[2]
			pfx = "DQMData/Run 1/Btag/Run summary/TrackIPPlots_standardImpactParameterPFTagInfos_"+args[2]
		elif args[1] == 'looseCalo':
			histo = histo[2:] + "_looseImpactParameterCaloTagInfos_"+args[2]
			pfx = "DQMData/Run 1/Btag/Run summary/TrackIPPlots_looseImpactParameterCaloTagInfos_"+args[2]
		else:
			histo = histo[2:] + "_standardImpactParameterCaloTagInfos_"+args[2]
			pfx = "DQMData/Run 1/Btag/Run summary/TrackIPPlots_standardImpactParameterCaloTagInfos_"+args[2]
        ##### SV Tag Infos
	elif histo[0] == 's' and histo[1] == 'v':
		if args[1] == 'loosePF':
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/TaggingVariable_looseCombinedSecondaryVertexPF_"+args[2]
		elif args[1] == 'standardPF':
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/TaggingVariable_standardCombinedSecondaryVertexPF_"+args[2]
		elif args[1] == 'looseCalo':
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/TaggingVariable_looseCombinedSecondaryVertexCalo_"+args[2]
		else:
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/TaggingVariable_standardCombinedSecondaryVertexCalo_"+args[2]
        ##### Soft Muon Tag Infos
	elif histo[0] == 'm' and histo[1] == 'u':
		if args[1] == 'loosePF':
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_looseSoftMuonPFTagInfos_"+args[2]
		elif args[1] == 'standardPF':
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_standardSoftMuonPFTagInfos_"+args[2]
		elif args[1] == 'looseCalo':
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_looseSoftMuonCaloTagInfos_"+args[2]
		else:
			histo = histo[2:]
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_standardSoftMuonCaloTagInfos_"+args[2]
        ##### Soft Electron Tag Infos
	elif histo[0] == 'e' and histo[1] == 'l':
		if args[1] == 'loosePF':
			histo = histo[2:] 
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_looseSoftElectronPFTagInfos_"+args[2]
		elif args[1] == 'standardPF':
			histo = histo[2:] 
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_standardSoftElectronPFTagInfos_"+args[2]
		elif args[1] == 'looseCalo':
			histo = histo[2:] 
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_looseSoftElectronCaloTagInfos_"+args[2]
		else:
			histo = histo[2:] 
			pfx = "DQMData/Run 1/Btag/Run summary/SoftLepton_standardSoftElectronCaloTagInfos_"+args[2]
	else:
		pfx = "!!Nothing to draw!!"
		print "Nothing to draw"

        #####################			
	print pfx, histo

	mc = [
		mc.Get("%s/%sNI" % (pfx, histo)),
		mc.Get("%s/%sDUSG" % (pfx, histo)),
		mc.Get("%s/%sC" % (pfx, histo)),
		mc.Get("%s/%sB" % (pfx, histo)),
		mc.Get("%s/%sALL" % (pfx, histo))
	]

	mc.append(data.Get("%s/%sALL" % (pfx, histo)))

#### Scale MC to the data area
#### The MC histograms are normalized to the area of the data histograms
#	for i in range(5):
#		print "Scaling mc", i
#		mc[i].Scale(mc[-1].Integral()/mc[4].Integral())

#### Scale MC to data lumi ...Data/MC ratio
## Data lumi = 199.58 ub-1 and MC lumi = 157.12 ub-1
	scale = 1.27
	for i in range(5):
		mc[i].Scale(1.27)
##################

	if len(args) > 5:
		mc[4].GetXaxis().SetRangeUser(float(args[5]), float(args[6]))
		mc[-1].GetXaxis().SetRangeUser(float(args[5]), float(args[6]))

	for i, j in enumerate(mc):
		j.SetTitle("")
#		format(j, i)
	
	newTitle = args[0]+"_"+args[1]+"_"+args[2]

	draw(mc[:-1], mc[-1], args[3], args[4], newTitle, args[1], args[2], left, blind)

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
