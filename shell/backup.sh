#!/bin/bash

BACK_DIR="/home/ubuntu/shell /home/ubuntu/.bashrc"
BACK_TARGET="/tmp/backup/"

[ -d $BACK_TARGET ] || mkdir $BACK_TARGET	

for dir in $BACK_DIR
do
	if [ ! -e $dir ]
	then
		echo "$dir is not found"
		exit 1
	fi

done

tar -zcvf ${BACK_TARGET}/ubuntu_$(date +%Y%m%d).tar.gz $BACK_DIR >/dev/null 2>&1

