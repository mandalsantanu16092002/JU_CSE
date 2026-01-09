#! /usr/bin/bash

op=1
while getopts ":c" o; do
	case "${o}" in
		c)
			cd "./my_deleted_files"
			rm -r *
			((op--))
	esac
done
if [ $op -eq 1 ];then
read -p "Enter the file to be deleted: " filename
cd ./my_deleted_files
if [[ -e $filename ]];then
	count=0
	while [ -e "$filename$count" ]
	do
		((count++))
	done
	mv $filename "$filename$count"
	if [ $count -e 0 ];then
		cd ..
		mv $filename "./my_deleted_files/$filename"
		cd ./my_deleted_files
	fi
else
	count=0
	while [[ -f "$filename$count" ]]
	do
		((count++))
	done
	cd ..
	if [[ $count -eq 0 ]];then
		mv "$(pwd)/$filename" "$(pwd)/my_deleted_files"
	else
		mv "$(pwd)/$filename" "$(pwd)/my_deleted_files/$filename$count"
	fi
fi
fi
