#! /usr/bin/bash

read -p "Enter the file path :- " file_path
read -p "Enter the search string :- " search
read -p "Enter the replace string :- " replace

word_count=$(grep -w -o -n $search $file_path | wc -l)

if [ "$word_count" -eq 0 ]; then
	echo "Word Not Found !"
	exit
fi

if [[ $search != "" && $replace != "" ]]; then
	sed -i "s/$search/$replace/g" $file_path
fi