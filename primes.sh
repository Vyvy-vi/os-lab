#!/bin/bash

greet="PRIMES!"
echo $greet

read -p "Enter limit: " lim

if (($lim < 2))
then
	echo "No primes available within given limit"
	exit
fi

printf "%d " 2

i=3
while [ $i -le $lim ]
do
	j=2
	remainder=1

	while [ $(($j*$j)) -le $i ]
	do
		remainder=$((i%j))
		if ((!$remainder));then
			break
		fi
		j=`expr $j + 1`
	done

	if (($remainder)) ;then
		printf "%d " $i
	fi

	i=`expr $i + 2`
done
