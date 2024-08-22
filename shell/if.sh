#!/bin/bash
# if-then-fi
# ./if.sh user_name
if [ $# -ne 1 ]
then
	echo "Usage : $0 user_name"
	exit 1
fi
grep $1 /etc/passwd >/dev/null 2>&1
if [ $? -eq 0 ]
then
	echo "$1 is exist"
else
	echo "$1 is NOT exist"
	# adduser $1
fi
