To get started, copy one of these configurations to ~/.offlineimaprc:
* minimal configuration:
    cp -n /opt/twitter/Cellar/offline-imap/6.5.4/offlineimap.conf.minimal ~/.offlineimaprc

* advanced configuration:
    cp -n /opt/twitter/Cellar/offline-imap/6.5.4/offlineimap.conf ~/.offlineimaprc

To have launchd start offline-imap at login:
    ln -sfv /opt/twitter/opt/offline-imap/*.plist ~/Library/LaunchAgents
Then to load offline-imap now:
    launchctl load ~/Library/LaunchAgents/homebrew.mxcl.offline-imap.plist

WARNING: launchctl will fail when run under tmux.
