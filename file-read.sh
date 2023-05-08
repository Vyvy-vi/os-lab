#!/bin/bash

files=(file1.txt file-manip.txt details.txt)

for i in "${files[@]}"
do
  echo Content of file $i:
  cat $i
done
