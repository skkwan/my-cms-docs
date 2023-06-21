// Usage: root -l -b -q example_plotting.cpp
// Change "myFile", "myTreeName", "myVariableName"

#include <cstring>
#include <string>

void example_plotting() {
    // Open the file
    std::unique_ptr<TFile> myFile(TFile::Open("myFile.root"));

    // Get the TTree
    TTree efficiencyTree = (TTree) myFile->Get("myTreeName");

    // Create a histogram (number of bins: 50, range is 0 to 200)
    TH1F *hist = new TH1F("hist", name , 50, -100, 400);

    // Draw one of the branches
    efficiencyTree->Draw("myVariableName>>hist");

    // Create TCanvas
    TCanvas* Tcan = new TCanvas("Tcan", "", 100, 20, 800, 600);

    // Generally we need this line before we draw anything
    Tcan->cd();

    // Draw the histogram
    hist->SetMarkerColor(0);
    hist->SetLineWidth(1);
    hist->SetFillStyle(1001);
    hist->Draw("HIST");

    Tcan->SaveAs("example.pdf");

    // Clean up 
    delete Tcan;
    
}
