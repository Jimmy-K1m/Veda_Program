#!/bin/bash
# heredoc : <<

cat << CATEND
1. ls
2. ps
CATEND


while true
do
	echo -n "select : "
	read menuno
	
	case $menuno in
	"1")
		ls
		;;
	"2")
		ps
		;;
	"0")
		exit
		;;
	*)
		echo "Wrong Choice!"
		;;
		esac

done
