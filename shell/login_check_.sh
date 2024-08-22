#!/bin/bash
# ./login_check.sh

echo "user name : "
read user
if who | grep $user >/dev/null 2>&1
then
	echo "$user is loggined"
else
	echo "$user is not loggined"
fi
