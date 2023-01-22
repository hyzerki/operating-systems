#!/bin/bash

pid=`ps -o pid= $1`i
if [[ $pid > 0 ]]; then	
	cat /proc/$1/status | head -n 1 | tail -n 1
	cat /proc/$1/status | head -n 6 | tail -n 1
	cat /proc/$1/status | head -n 7 | tail -n 1
else
	echo pid=$1 process not found
fi

if [[ $2 == 'fd' ]]; then
	yourfilenames=`ls /proc/$$/fd`
	for eachfile in $yourfilenames
	do
	   echo fd=$eachfile
	done
fi
