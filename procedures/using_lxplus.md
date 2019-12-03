# Notes on using LXPLUS

## .bashrc and .bash_profile

If there is a bug in .bashrc or .bash_profile, you may get ``locked out" of ssh-ing in if it throws an error.
To interrupt the execution of .bash_profile on login, Ctrl+C as soon as soon as the "Welcome to lxplus..."
header pops up after ssh-ing to lxplus.

Example start of .bashrc:

```
if [ -f /etc/bashrc ]; then
        . /etc/bashrc
fi
if [ -f ~/.bash_aliases ]; then
    source ~/.bash_aliases
fi
```

Example start of .bash_profile:
```
if [ -f ~/.bashrc ]; then
    . ~/.bashrc
fi

if [ -f ~/.bash_aliases ]; then
    source ~/.bash_aliases
fi
```

Example .bash_aliases:
```
# Commands
alias 'emacs'='emacs -nw'
alias 'voms'='voms-proxy-init --rfc --voms cms'
alias 'crb'='source /cvmfs/cms.cern.ch/crab3/crab.sh'
alias 'll'='ls -lrtha'
# Shortcuts for directories
alias 'work'='cd /afs/cern.ch/work/s/skkwan'
```