#!/bin/bash
# write / shift
# 현재 로그인되어있는 사용자 전체에게 memo.txt 파일의 내용 전송 

list=$(who | awk '{ print $1, $2 }')

echo $list


set -- $list

num=$#

i=0
while (( i < num))
	do
		
		sudo write $1 /dev/$2 < memo.txt
		shift 2
		((i += 2))
	
done
