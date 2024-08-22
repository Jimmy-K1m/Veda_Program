 #!/bin/bash

 # ./user_monitor.sh
 # 로그인되어 있는 경우 그 사용자가 수행하는 명령을 모니터링하는 프로그램
#로그아웃 판단 로그아수 전까지 내용 저장
 
echo "user name : "
read user
if who | grep $user >/dev/null 2>&1
then
	echo "$user is loggined"
	while true
	do
		who | grep $user >/dev/null 2>&1
		if (( $? != 0 ))
		then
			tty=$(tty)
			echo "$user is logout" > $tty
			break
		fi
		echo "----------------"
		ps -u user | awk '$2 ~ "pts" && $4 != "bash" { print $1, $4 }'
		echo "----------------"
		echo

		sleep 3

	 done | tee ${user}_$(date +%Y%m%d).log

 else
	echo "$user is Not loggined"
 fi
