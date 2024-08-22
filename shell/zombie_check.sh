#!/bin/bash
#현재 수행중인 프로세스 중 Zombie 상태의 프로세스가 있는 지 확인하고 
# 해당 프로세스가 있는 경우 부모 프로세스가 누구인지 확인하는 프로그램



ppid=$( ps -el | awk '$2=="Z" { print $5 }' )

set $ppid  >/dev/null 2>&1


if (( $# == 0 ))
		  then
		   echo "No Zombie"
			return 1
		  else
			echo $#" Zombie exists" 

fi

while (( $#!=0 ))
	do
			
	kill -9 ${ppid[0]} >/dev/null 2>&1
	
	shift

	done

echo "Kill all parent of zombie"

