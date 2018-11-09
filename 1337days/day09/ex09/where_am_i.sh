#!/bin/sh

OUT=`ifconfig | grep "inet " | cut -d' ' -f 2 | grep -vo "127.0.0.1"`
if [[ "$OUT" == "" ]]
then 
	echo "I am lost!"
else
	echo "$OUT"
fi

