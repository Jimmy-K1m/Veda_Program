#!/bin/bash
# ./caculate.sh file_name

if [ $# -ne 1 ]
then
	echo "Usage : $0 file_name"
	exit 1
fi

if [ -e $1 ]
then 
	if [ -d $1 ]
	then 
		echo "Directory"
	else
		if [ -f $1 ]
		then
			echo "Regular File"
		fi
	fi
	if [ -r $1 ]
	then
		echo "Readable"
	fi
	if [ -w $1 ]
	then
		echo "Writable"
	fi
	if [ -x $1 ]
	then
		echo "executable"
	fi

fi
