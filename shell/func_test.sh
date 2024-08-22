#!/bin/bash

# 함수 정의= function myFunc {} 
# or myFunc() {}

myfunc() 
{
	echo "myfunc : $1, $2"
	return 1
}


# 함수 호출

myfunc red blue
echo "after"
myfunc mango grape
