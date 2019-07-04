# (cont.d) Week of June 27 - July 4, 2019

## (contd.) Monday (July 1, 2019)

### Next steps for writing makeTable.C

Ideas: 
* ~~ Use [this tutorial](https://root.cern.ch/root/html/tutorials/tree/tree1.C.html) to create a TTree.~~
* Use [this tutorial](https://root.cern.ch/root/html608/TMVAClassificationCategoryApplication_8C.html) to classify. 
  * Use [this function](https://root.cern.ch/root/html608/classTMVA_1_1Reader.html#a209436a06ae04b848c9ac98b367e0dd6).
    *  ~~It takes in a std::vector<Float_t>, a const TString which is the MethodTag. It returns a Double_t.~~ 
    * ~~ So the underlying table should be doubles. ~~

## Tuesday (July 2, 2019)

### Progress on makeTable.C

- Went with the C++ two-dimensional array approach (commit `e3572d7`), permutes five variables correctly.
- Called EvaluateTMVA function
- Successfully prints table with variable permutations and the discr. value (commit `437223b`).
- Added some comments (commit `1b2b1d7`).

## Wednesday (July 3, 2019)

### Closer look at table
- L1DecayMode seems to have no effect on the BDT value with the current variables/binning.

### Thoughts on reading "BDTs in the CMS L1 Endcap Muon Detector"
- They use different variables for the BDT depending on which stations in the CSC/RPC chambers were hit.


### Other things
- Watched first lecture of [MIT Intro to Deep Learning](https://www.youtube.com/watch?v=5v1JnYv_yWs)
   - Evaluating the output of a perceptron: take a dot product, add a bias, take a non-linearity
   - Need a non-linear function known as an activation function, to introduce non-linearity into the system
- Revisited TMVA documentation ("boosted" makes more sense now - default value for number of trees in the forest is 800)
- Made note to revisit tau trigger paper to get some physics questions answered 
   - I don't quite understand the distributions of the variables 
   - and I don't understand what track1ChiSquared is
   - I also don't understand what the main sources of bkg are (aside from "jets faking taus")
- Started doing safety trainings for L1T Shift

## Thursday (July 4, 2019)

