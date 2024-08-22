>/dev/null 2>&1#!/bin/bash
# ./proc_ctrl.sh [start|stop]

case "$1" in
"start")
	if [ -f .loop ]
	then
		  echo "loop was running"

	else
		./loop >/dev/null 2>&1 &
		echo "loop is running"
		touch .loop
		fi
	;;

"stop")
	if [ -f .loop ]
	then
		  
		echo "loop is dead"
		kill $(ps -u ubuntu | grep loop | awk '{ print $1 }')
		rm .loop

	else
		echo "loop is not running"
		fi
	;;

*)
	echo "Usage: $0 [start|stop]"
	;;

esac
