void MakeAllPlotsLoader(string mcfilename, string datafilename, string plotfilename, double finalNorm=-1, string rootFile="plots.root" , string doPlot="")
{
  if(gSystem->Load("TrackSelector_C.so")<0)gSystem->CompileMacro("TrackSelector.C","Ok");
  if(gSystem->Load("TSelectorMultiDraw_C.so")<0)gSystem->CompileMacro("TSelectorMultiDraw.C","Ok");
  if(gSystem->Load("MakeAllPlots_C.so")<0)gSystem->CompileMacro("MakeAllPlots.C","Ok");
  MakeAllPlots(mcfilename,datafilename,plotfilename,finalNorm, rootFile, doPlot);
}
