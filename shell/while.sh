#!/bin/bash
# while 조건식 do ~ done
count=0

while [ $count -lt 5 ]
do
	echo $count
	let count++
done
echo "escape from while"
