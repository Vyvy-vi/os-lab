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

for ((i=3; i <= $lim; i+=2))
do
	prime=1
	for ((j=2; j*j <= $i; j++))
	do
		prime=$((i%j))
		if ((!$prime));then
			break
		fi
	done

	if (($prime)) ;then
		printf "%d " $i
	fi
done
