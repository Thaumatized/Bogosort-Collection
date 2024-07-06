#!/bin/bash

bogosort() {
    sorted=0
	while [ $sorted == 0 ]
    do
		shuffle
        isSorted
    done    
}

shuffle() {
    for i in "${!arr[@]}"
    do
        local otherIndex=$((RANDOM % len))
        local holder=${arr[$i]}
        arr[$i]=${arr[$otherIndex]}
        arr[$otherIndex]=$holder
    done
}

isSorted() {
    sorted=1
    for i in "${!arr[@]}"
    do
        if [ $i != 0 ]
        then
            if [ ${arr[$i-1]} -gt ${arr[$i]} ]
            then
                sorted=0
            fi
        fi
    done
}

verbose=false;
len=8;
max=255;
count=1;
arr=(69 5 32 7 666 29 2 55);

bogosort
first=1;
result="";
for element in "${arr[@]}"
do
        if [ $first == 0 ]
        then
            result="${result}, "
        else
            first=0;
        fi
        result="${result}${element}"
done
echo $result