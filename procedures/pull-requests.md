# Comments on pull requests

## Checks to run

```
cd $CMSSW_BASE/src
scram b clean
scram b -j 8    # no other flags, must run without warnings or errors
scram b runtests
scram b code-checks
scram build code-format
scram build -k -j 16 check-headers
```

## Make a backup branch

To-do: add instructions on how to do this

## To squash 
Let's say you want to squash commits: reset to the last commit that you did not make:
```
git reset --soft hash-of-last-commit-I-didnt-make
git commit
```
Which should generate a new commit, call this commit `hash-of-squashed-commit`.

Then force push this commit to the remote:
```
git push --force my-cmssw branchname-of-my-cms-l1t-offline
```

## To cherry-pick 
To cherry-pick this commit from the `cms-l1t-offline` PR to the main CMSSW PR:
```
# cd to the area where I am making my PR to the main CMSSW
git checkout branchname-of-my-MAIN-cmssw-PR
git fetch my-cmssw branchname-of-my-cms-l1t-offline
git cherry-pick hash-of-squashed-commit
git push my-cmssw branchname-of-my-MAIN-cmssw-PR
```

At this point I got an error message:
```
To github.com:skkwan/cmssw.git
 ! [rejected]                phase2Emulator -> phase2Emulator (non-fast-forward)
error: failed to push some refs to 'github.com:skkwan/cmssw.git'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. Integrate the remote changes (e.g.
hint: 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```



## To change CMSSW versions
For instance, to change to `CMSSW_13_2_0_pre1`, do the following: 

Never use `cms-merge-topic`

```
cmsrel CMSSW_13_2_0_pre1
cd src
cmsenv && git cms-init
git cms-addpkg -u L1Trigger
git cms-addpkg -u Configuration
git cms-addpkg -u DataFormats
git cms-rebase-topic -u skkwan:branchname-of-my-MAIN-cmssw-PR
```

