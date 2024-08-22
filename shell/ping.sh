#!/bin/bash
# 서버의 연결 상태를 점검하는 프로그램
SERVER="127.0.0.1 ubuntu 127.0.1.1  192.168.56.100"

for ip in $SERVER
do
	ping -c 1 $ip >/dev/null 2>&1
	if [ $? -eq 0 ]
	then
		echo "$ip is alive"

	else
		echo "$ ip is Not alive"
	fi
done

