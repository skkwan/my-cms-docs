# Xilinx Vivado HLS on uwlogin.cern.ch

This is how I set up a VNC connection from my Mac to the uwlogin.cern.ch machines and run Vivado HLS.
For the first time setting this up, I followed instructions on https://twiki.cern.ch/twiki/bin/viewauth/CMS/L1TriggerPhase2HLSProjects
so these steps are for subsequent logins.
Also big thanks to https://cat.pdx.edu/platforms/mac/remote-access/vnc-to-linux/ -- much of the text quoted here is from that.

## 1. Starting the VNC Server on the remote computer
1. SSH into **uwlogin.cern.ch**. At the terminal: `vncserver -localhost -geometry 1920x1080`
   This tells us `New 'uwlogin:3 (skkwan)' desktop is uwlogin:3`
   If going away for days, kill the VNC server (3) using the command: `vncserver -kill :3`

## 2. Creating the SSH Tunnel from your computer
1. Now that the VNC server is running, we need to create the SSH tunnel from your local machine to the remote host.
   ```
   ssh uwlogin-via-lxplus -L5903:127.0.0.1:5903
   ```
   (Everything sent through the remote computer's port 5903 (the second number) will be funneled into the local computer's
   port 5903 (the first number).)

## 3. Connecting to the Linux system with VNC
   Open TigerVNC and connect to `localhost:5903`.

## 4. Starting Xilinx Vivado HLS
   In the remote terminal, the required .sh files to source are already in my ~/.bashrc file, so just go ahead and run `vivado_hls`.

## 5. Creating projects
1. After writing a .cpp file, compile it like so: 
   ```
   c++ -o importArray importArray.cpp
   ./importArray
   ```

# Viewing and managing licenses
1. SSH and VNC to **uwlogin.cern.ch**. My .bashrc already has `source /opt/Xilinx/Vivado/2017.2/settings64.sh` to setup the environment.
2. `vivado` 
3. In the Vivado GUI, Help -> Manage License pulls up the Vivado License Manager window
4. e.g. click View License Status