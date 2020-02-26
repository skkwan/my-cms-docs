# Xilinx Vivado HLS on uwlogin.cern.ch

This is how I set up a VNC connection from my Mac to the uwlogin.cern.ch machines and run Vivado HLS.
For the first time setting this up, I followed instructions on https://twiki.cern.ch/twiki/bin/viewauth/CMS/L1TriggerPhase2HLSProjects
so these steps are for subsequent logins.
Also big thanks to https://cat.pdx.edu/platforms/mac/remote-access/vnc-to-linux/ -- much of the text quoted here is from that.

## 1. Starting the VNC Server on the remote computer
1. SSH into **uwlogin.cern.ch**. At the terminal: `vncserver -localhost -geometry 1920x1080`
   This tells us `New 'uwlogin:4 (skkwan)' desktop is uwlogin:4`
   If going away for days, kill the VNC server (4) using the command: `vncserver -kill :4`

## 2. Creating the SSH Tunnel from your computer
1. Now that the VNC server is running, we need to create the SSH tunnel from your local machine to the remote host.
   ```
   ssh uwlogin-via-lxplus -L5904:127.0.0.1:5904
   ```
   (Everything sent through the remote computer's port 5903 (the second number) will be funneled into the local computer's port 5904 (the first number).)
   
   If you see this error upon login:
   ```
   bind [127.0.0.1]:5904: Address already in use
   channel_setup_fwd_listener_tcpip: cannot listen to port: 5904
   Could not request local forwarding.
   ```
   On your own computer's command line, run `sudo lsof -i tcp:5904` to view the processes that are occupying the port:
   ```
   nat-oitwireless-inside-vapornet100-10-8-4-180:~ stephaniekwan$ sudo lsof -i tcp:5904
COMMAND  PID          USER   FD   TYPE             DEVICE SIZE/OFF NODE NAME
ssh     2237 stephaniekwan    6u  IPv6 0x2fda24aa3e81afb3      0t0  TCP localhost:5904 (LISTEN)
ssh     2237 stephaniekwan    7u  IPv4 0x2fda24aa44673b33      0t0  TCP localhost:5904 (LISTEN)
ssh     2237 stephaniekwan   11u  IPv6 0x2fda24aa3e819e73      0t0  TCP localhost:5904->localhost:51705 (CLOSE_WAIT)
   ```
   Kill the process with `kill -9 [PID number]`, e.g. `kill -9 2237`, and try Step 2 again.

## 3. Connecting to the Linux system with VNC
   Open TigerVNC and connect to `localhost:5904`.

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