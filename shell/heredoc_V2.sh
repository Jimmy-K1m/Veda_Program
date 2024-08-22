#!/bin/bash
# heredoc : <<
command=(exit ls ps)
cat << CATEND
1. ls
2. ps
CATEND



while true
do
	echo -n "select : "
	read menuno
	
	if (( menuno > 2 ))
		  then
		  echo "Type wrong"
		  fi
	${command[menuno]}

done
