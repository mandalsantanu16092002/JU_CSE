#! /usr/bin/bash
# echo "Filename to search in:"
# read filename
# echo "Word to search:"
# read word

# if [[ grep -Fqw $word $filename ]]; then
#   echo "The number of occurrences of $word:"
#   grep -Eow $word $filename | wc -l
#   echo "Number of occurrences of $word in each line:(count:line no.)"
#   grep -won $word $filename | uniq -c | cut -d ":" -f1 | cut -d " " -f7,8 | tr " " ":"
# else
#   echo "The entered string($word) was not found in $filename"
# fi

#counting the occurence of a word in a file
read -p "Enter the file name :- " file_path
read -p "Enter the word to analysed :- " word
#getting the total word count
word_count=$(grep -w -o -n $word $file_path | wc -l)
if [ "$word_count" -gt 0 ]; then #print the total word count
    echo "Total word count :- $word_count"
else #case for word count = 0
    echo "Word Not Found !"
    exit
fi
#count the occurence of word in each line of the file
count=0
for i in $(grep -w -o -n $word $file_path | cut -d : -f 1 | uniq -c);do
    if [ "$count" -eq 0 ];then
        count=$i
    else
        echo "line $i -> $count" #print the count of occurence of the word in the file
        count=0
    fi
done