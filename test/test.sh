#!/bin/bash
if	[ $# != 1 ]
then
	echo -e "Must provide an argument for length of stack to test"
	exit 1
fi
DIR="/Users/lolalebreton/Documents/42/push-swap"
ARG=$($DIR/test/./randnum.sh $1) ; ARG="${ARG//$'\n'/ }"
$DIR/./push_swap $(echo $ARG) | wc -l
$DIR/./push_swap $(echo $ARG) | $DIR/./checker_Mac $ARG