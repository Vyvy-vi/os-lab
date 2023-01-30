#!/bin/bash

read -p "Enter operand1: " a
read -p "Enter operand2: " b
read -p "Enter operator: " op

case "$op" in
	"+") echo $a + $b = $(($a + $b));;
	"-") echo $a + $b = $(($a - $b));;
	"*") echo $a + $b = $(($a * $b));;
	"/") echo $a + $b = $(($a / $b));;
esac
