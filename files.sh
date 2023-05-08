#!/bin/bash

var=($(ls $1))

count=0
echo No of files in directory $1 is: ${#var[@]}

for i in "${var[@]}"
do
  vars=($(ls $1/$i))
  count=$(($count+${#vars[@]}))
done

echo No of files in $1 and all it\'s subdirectories is: $count
