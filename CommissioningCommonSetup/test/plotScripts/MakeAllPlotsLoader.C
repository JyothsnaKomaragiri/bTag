void MakeAllPlotsLoader(string mcfilename, string datafilename, string plotfilename, double finalNorm=-1, string rootFile, double intLumi, int dataVsmc=1, string doPlot="", int firstPlot = 0, int lastPlot=0)
{
  if(gSystem->Load("TrackSelector_C.so")<0)gSystem->CompileMacro("TrackSelector.C","Ok");
  if(gSystem->Load("MuonSelector_C.so")<0)gSystem->CompileMacro("MuonSelector.C","Ok");
  if(gSystem->Load("TSelectorMultiDraw_C.so")<0)gSystem->CompileMacro("TSelectorMultiDraw.C","Ok");
  if(gSystem->Load("MakeAllPlots_C.so")<0)gSystem->CompileMacro("MakeAllPlots.C","Ok");
  MakeAllPlots(mcfilename,datafilename,plotfilename,finalNorm, rootFile, intLumi, dataVsmc, doPlot, firstPlot, lastPlot);
}
