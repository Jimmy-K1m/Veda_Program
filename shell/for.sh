#!/bin/bash
# for .. in... 	;do ... ;done

if [ $# -eq 0 ]
then
	cd /home
	for name in $home
		do
			cat $name
			ls -al
		done
		

else
	for name in $*
		do
			cd /home/$name
			ls -al
		done

fi
