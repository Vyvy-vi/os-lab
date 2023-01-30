#!/bin/bash

greet="let's print tables!"
echo $greet

read -p "Enter number: " p

for i in {1..10}
do
	num=$(($p * $i))
	echo "$p * $i = $num"
done
