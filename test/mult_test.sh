#!/bin/bash
if	[ $# != 2 ]
then
	echo -e "Must provide arguments for length of stack to test and number of tests to run"
	exit 1
fi
DIR=$(pwd)
MIN=10000000
MAX=0
CHECK='OK'
for ((i=0; i<$2; i++))
do
	if [ $(expr $i \* 100 / $2 % 10) -eq 0 ] && [ $(expr $(expr $i - 1 ) \* 100 / $2 % 10) != 0 ]
	then
		echo -e "$(expr $i \* 100 / $2) %"
	fi
	RES=$($DIR/test/test.sh $1)
	L=$(echo $RES | head -n1 | awk '{print $1;}')
	OK=$(echo $RES | head -n1 | awk '{print $2;}')
	if [ $OK != 'OK' ]
	then
		CHECK='KO'
	fi
	if [ $MAX -lt $L ]
	then
		MAX=$L
	fi
	if [ $L -lt $MIN ]
	then
		MIN=$L
	fi
done
echo -e "MIN = $MIN MAX = $MAX CHECK = $CHECK"
