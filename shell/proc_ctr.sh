
#!/bin/bash
# ./proc_ctrl.sh [start|stop]

case "$1" in
"start")
	ps -u ubuntu | grep loop > /dev/null 2>&1
	if (( $? == 0 ))
	then
		  echo "loop is already running"
	else
		./loop >/dev/null 2>&1 &
		echo "loop is running"
		fi
	;;

"stop")
	ps -u ubuntu | grep loop > /dev/null 2>&1
	if (( $? == 1))
	then
		  echo "loop is not running"
	else
 		kill $(ps -u ubuntu | grep loop | awk '{ print $1 }')
		echo "loop is dead"
		fi
	;;

*)
	echo "Usage: $0 [start|stop]"
	;;

esac
