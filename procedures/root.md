# ROOT 

## Opening a histogram in the command line with a hyphen in the name
In the command line, open ROOT:
```
root
```
In the ROOT prompt:
```
TFile *f = TFile::Open("hist_preVFP_DYJetsToLL_M-50_cat_1_batch_2.root")
TH1F *h = (TH1F*) f->Get("mm/CRZ/preVFP_DYJetsToLL_M-50_m_ll")
```
And manipulate the histogram as usual, e.g.
```
h->Print("all")
```