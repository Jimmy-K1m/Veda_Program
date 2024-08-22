#!/bin/bash

ppid=$(ps -el | awk '$2=="Z" { print $5 }')
if [ -z "$ppid" ]
then

	echo "no zombie process"
	exit 1
fi

for pid in $ppid
do
#ps -e | grep $pid | awk '{ print $1, $4 }'
	ps -e | awk '$1=="'$pid'" { print $1, $4 }'
done
