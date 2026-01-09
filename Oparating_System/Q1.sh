#! /usr/bin/bash

echo "Enter the value of variable 1"
read uv1
echo "Enter the value of variable 2"
read uv2

#printing comma separated values
echo "$uv1, $uv2"

#printing and separated values
echo "$uv2 and $uv1"

#check if the variable is number or string
re='^[0-9]+$'
if ! [[ $uv1 =~ $re ]] ; then
   t=1
fi
if ! [[ $uv2 =~ $re ]] ; then
   s=1
fi

#printing the varibles in reverse order
rev1=0
rev2=0
if [ "$t" == 1 ]
then 
    # finding the length of string
    strlen=${#uv1}
    # traverse the string in reverse order.
    for (( i=$strlen-1; i>=0; i-- ))
    do
        reversed_string=$reversed_string${uv1:$i:1}
    done
    # printing the reversed string.
    echo "reverse of uv1: $reversed_string" 
else
    while [ $uv1 -ne 0 ]
    do
        n=`expr $uv1 % 10`
        rev1=$((($rev1 * 10) + $n))
        uv1=`expr $uv1 / 10`
    done
    echo "Reverse of uv1: $rev1"
fi

if [ "$s" == 1 ]
then 
    # finding the length of string
    strlen1=${#uv2}
    # traverse the string in reverse order.
    for (( i=$strlen1-1; i>=0; i-- ))
    do
        reversed_string1=$reversed_string1${uv2:$i:1}
    done
    # printing the reversed string.
    echo "reverse of uv1: $reversed_string1" 
else
    while [ $uv2 -ne 0 ]
    do
        n1=`expr $uv2 % 10`
        rev2=$((($rev2 * 10) + $n1))
        uv2=`expr $uv2 / 10`
    done
    echo "Reverse of uv1: $rev2"
fi
