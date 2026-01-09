#! /usr/bin/bash

number_of_files=`find . -type f | wc -l`
echo "Total number of ordinary files : $number_of_files"

number_of_subdirectories=`ls -l | grep "^d" | wc -l`
ans=$(( $number_of_files + $number_of_subdirectories ))
echo "Number of SubDirectorues: $number_of_subdirectories"
echo "the count of files including the sub-directories that the current working directory has: $ans"
