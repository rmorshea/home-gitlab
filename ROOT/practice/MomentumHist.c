#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

void MomentumHist() 
{
    //open file
    TFile *f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
   if (f == 0) {
      // print an error message if unable to open
      printf("Error: cannot open http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root!\n");
      return;
   }

    //new TTreeReader
    TTreeReader myReader("EventTree", f);
    //get momentum values and assign to an array
    TTreeReaderArray<Double_t> particlesMomentum(myReader, "fParticles.fMomentum");
    //get position values and assign to an array
    TTreeReaderArray<Double_t> particlesPosX(myReader, "fParticles.fPosX");
    //assign new histogram to variable TH1F
    TH1F *hPosX;
    hPosX = new TH1F("hPosX", "Position in X",20, -5, 5);
    hPosX->Sumw2(); //allow error bars
    
    while (myReader.Next())
    {
        Int_t range = particlesPosX.GetSize();
        
        for(Int_t i=0; i<range; i++)
        {
            Double_t pPosX_i = particlesPosX[i];
            Double_t pMomX_i = particlesMomentum[i];

            if (pMomX_i>40)
            {
                hPosX->Fill(pPosX_i);
            }
            
        }
    }
    hPosX->Fit("gaus");
    hPosX->Draw();
}