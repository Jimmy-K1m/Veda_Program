#!/bin/bash
# 저장한 디렉토리로 이동  

loadd(){
	if [ X"${cwd}" != "X" ]
	then
		cd $cwd
	fi
}

# 현재 디렉토리 저장 
saved()
{
	cwd=$(pwd)
}

# 프로세스 강제 종료
# killproc process_name
killproc_()
{

    target=$1
    i=0
    process_names=($(ps -u ${whoami} | awk '{ print $1 }'))
    process_ids=($(ps -u ${whoami} | awk '{ print $2 }'))
    for process_name in ${process_names[*]}
            do

            if (( $target == $process_name ))
                    then
                            kill ${process_ids[$i]}
             fi
             let i++
             done
 }




killproc()
{
	if [ -z "$1" ]
	then
			  echo "Usage : killproc process_name"
			  return 1
	fi

	ps -u $USER | grep $1 >/dev/null 2>&1
	if [ $? -ne 0 ]
			  then
					echo "$1 : no such process"
					return 2
	else
				kill $(ps -u $USER | grep $1 | awk '{ print $1 }')
	fi
}



#pwd
#load
#cd /var/log
#pwd
#saved
#cd
#pwd
#load
#pwd
