# Data Aggregation Service browser access issues

I'm already a member of the CMS Virtual Organization so these steps are to
help me troubleshoot when certificate issues are preventing me from using
the DAS website (or other cmsweb websites):

1. Try clearing browser cache and reloading first.
2. Go to [https://ca.cern.ch/ca/] and click on "New Grid User Certificate"
3. Download the new certificate (`myCertificate.p12`)
4. On a Mac, double-click on the file to install it to Keychain Access
   (or open Keychain Access and `File` -> `Import Items`)
5. In Keychain Access, open `Certificates` and click on it: in the "Trust" 
   drop-down menu, for "When using this certificate" select "Always Trust" 
   (otherwise you'll have to enter your laptop password every time you
   use DAS's website)
6. You need two more certificates: `CERN Root Certification Authority 2 Certificate` and `CERN Grid Certificate Authority (1) Certificate`: [https://cafiles.cern.ch/cafiles/certificates/Download.aspx?ca=grid]. When clicking on these, it should open Keychain Access, but you might need to open `Certificates` (it won't be in `My Certificates`). And click "always trust"
   
   If all you need is to refresh your certificate for Google Chrome/Safari on your local machine, this is all you need to do.
6. Still in Keychain Access, right-click on the certificate, and click on
   "Export <certificate name>". This will download a `.p12` certificate file.
7. Place the `.p12` certificate file in the `.globus` directory of your home
   area:
   ```
   cd ~
   mkdir .globus
   cd ~/.globus
   mv /path/to/myCertificate.p12 .
   ```
8. Execute the following shell commands:
   ```
   rm -f usercert.pem
   rm -f userkey.pem	
   openssl pkcs12 -in myCertificate.p12 -clcerts -nokeys -out usercert.pem
   openssl pkcs12 -in myCertificate.p12 -nocerts -out userkey.pem
   chmod 400 userkey.pem
   chmod 400 usercert.pem
   ```
   n.b.: For openssl commands, you need to put the same password that you chose while importing the certificate in your browser, and you would also be asked for "Enter PEM pass phrase". (Just make them the same)

This should fix DAS website certificate issues.
