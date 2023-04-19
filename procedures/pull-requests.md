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
# cd to the main-CMSSW PR area 
git fetch my-cmssw branchname-of-my-cms-l1t-offline
git cherry-pick hash-of-squashed-commit
```
This should be automatically reflected in the pull request page - no need to "git push" again, otherwise it will appear as a duplicate commit.