#!/bin/bash
# if-then-fi
# ./scp.sh file_name

if [ $# -ne 1 ]
then
	echo "Usage : $0 file_name"
	exit 1

fi

[ -f $1 ] || exit 1

scp $1 user@ubuntu:/home/user

