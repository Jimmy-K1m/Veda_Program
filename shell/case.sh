#!/bin/bash

. /etc/lsb-release

case $DISTRIB_ID in
"Ubuntu")
	echo "apt"
	;;
"RHEL")
	echo "yum"
	;;
"Fedora"|"CentOS")
	echo "dnf"
	;;
"Debian")
	echo "deb"
	;;
*)
	echo "can not recognized distribution"
	;;
esac
