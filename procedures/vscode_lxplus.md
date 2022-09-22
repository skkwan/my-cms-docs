# VSCode on lxplus

1. Install VSCode on your laptop/ personal machine: https://code.visualstudio.com/download
2. You need this Remote Development extension from Microsoft (click "Install"): https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack 
3. Then in principle we follow the instructions "Connect to a Remote Host" (lxplus already exists so we don't need to create our own remote host): https://code.visualstudio.com/docs/remote/ssh#_connect-to-a-remote-host 
    * I connect to a specific machine because VSCode is funky with servers that automatically assign machines per log-in instance. So in Step 2 in the bar I type `skkwan@lxplus730.cern.ch` to connect ot one specific machine.
    * It prompted me to select "Linux" and then type in my password. (You may need to type your password in a few times)
    * In the troubleshooting page it covers exactly our scenario: "Connecting to systems that dynamically assign machines per connection" (https://code.visualstudio.com/docs/remote/troubleshooting#_troubleshooting-hanging-or-failing-connections)
    * I ended up also trying the troubleshooting tip described on that page, that involves "using the `ControlMaster` option in OpenSSH" -- in the end I do not know if that's what got it to work.
    * A summer student also said: "I found that many times, it would take a few attempts to successfully SSH (although I'm not sure why) -- in those cases, removing the VSCode server folder from the lxplus home area (`rm -fr ~/.vscode-server/`) and reattempting to SSH via VSCode always worked for me."

