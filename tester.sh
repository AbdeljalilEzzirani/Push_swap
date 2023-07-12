#!/bin/bash

GREEN="\033[92m"
RED="\033[91m"

from=-9999
to=9999
quantity=3

while true
do
	numbers=$(seq $from $to | sort -R | head -n $quantity | paste -sd" " -)
	ins=$(./push_swap $numbers | wc -l | tr -d " ")
	if [ $ins -ge 13 ]
	then
		echo -e "${RED}$ins"
		exit
	else
		echo -e "${GREEN}$ins"
	fi
	sleep 0.1
done
