# Comments on pull requests

## To squash 
Let's say you want to squash commits: reset to the last commit that you did not make:
```
git reset --soft hash-of-last-commit-I-didnt-make
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
