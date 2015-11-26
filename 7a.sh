#!/bin/sh
v=" "
for i in $*
do
	v=$i" "$v
done
echo $v
