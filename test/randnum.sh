#!/bin/bash
if	[ $# != 1 ]
then
	echo -e "Must provide an argument for number of random int to generate"
	exit 1
fi
jot -r $1 0 2147483647 | sort -R | uniq -u
