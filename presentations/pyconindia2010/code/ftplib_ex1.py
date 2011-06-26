import ftplib
ftp = ftplib.FTP('ftp.gnome.org')
ftp.login()           # login anonymously before securing control channel
ftp.retrlines('LIST') # list directory content securely
ftp.quit()
