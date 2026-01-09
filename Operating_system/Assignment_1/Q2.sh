#! /usr/bin/bash

echo "Enter the path to the file"
read file_path

if [ -f "$file_path" ]; then
    echo "$file_path exists."
    number_of_lines=`wc --lines < $file_path`
    ans=$(( $number_of_lines + 1 ))

    #printing the number of lines in the file
    echo "Number of lines in the file :- $ans"
else    
    echo "File does not exists."
    echo "Creating New file.."
    touch $file_path
fi
