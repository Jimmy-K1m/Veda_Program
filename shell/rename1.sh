#!/bin/bash

for orgfile in *
do

	destfile=$(echo "$orgfile" | sed 's/[ +\-]/_/g')
	if [ "$orgfile" != "$destfile" ]
	then
		echo "mv $orgfile $destfile"
		mv "$orgfile" $destfile

	fi
done
