#!/bin/sh
if [ $# -eq 0 ]
then
	echo  "Not enough params"
else
	for i in $*
	do
		echo "cat>$i<<'eof'"
		cat $i
		echo "eof"
	done
fi
