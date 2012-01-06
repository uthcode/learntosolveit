=======
Jenkins
=======

Runs as a jenkins user.


Uninstall Jenkins from Centos. It does not remove the config files.

- /var/log/jenkins
- /var/lib/jenkins

Apart from that, there are files like

/etc/init.d/jenkins
/etc/sysconfig/jenkins

Python plugin

https://wiki.jenkins-ci.org/display/JENKINS/Python+Plugin

The python executable via jenkins will not be able to see a PATH mounted via
NFS.
