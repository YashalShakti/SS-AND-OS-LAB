#!/bin/sh
if [ $# -eq 0 ]
then
	echo "Not enough params"
else
	echo "There are two files : $*"
	v1=`ls -l $1 | cut -d " " -f 1`
	v2=`ls -l $2 | cut -d " " -f 1`
	if [ $v1 = $v2 ]
	then
		echo Both have same $v1 permission
	else
		echo Both have different permissions
		echo $1 has $v1
		echo $2 has $v2
	fi
fi
