#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void AnalyzeTree() 
{
        Int_t totalSize = 0;
        TFile *f = TFile::Open("http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root");
        if (f == 0)
        {
            printf("Error: cannot open http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root!\n");
            return;
        }

        TTreeReader myReader("EventTree", f);
        TTreeReaderValue<Int_t> eventSize(myReader, "fEventSize");

        while (myReader.Next())
        {
        	totalSize+= *eventSize;
        }

        int sizeInMB = totalSize/1024/1024;
        printf("Total size of all events: %d MB\n", sizeInMB);
}