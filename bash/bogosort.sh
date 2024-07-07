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
    for i in ${!arr[@]}
    do
        local otherIndex=$((RANDOM % len))
        local holder=${arr[$i]}
        arr[$i]=${arr[$otherIndex]}
        arr[$otherIndex]=$holder
    done
}

isSorted() {
    sorted=1
    for i in ${!arr[@]}
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

randomArray(){
    for i in $( seq 0 $(($len - 1)))
    do
        arr[$i]=$((RANDOM % (max + 1)))
    done
}

verbose=0
len=8
max=255
count=1
arr=()

action=""
for arg in "$@"
do
    if [ $arg == "-v" ]
    then
        verbose=1
        action=""
    elif [ $arg == "-l" ] || [ $arg == "-m" ] || [ $arg == "-c" ]
    then
        action=$arg
    elif [ $arg == "-a" ]
    then
        action=$arg
        len=0
    else
        if [ $action == "-l" ]
        then
            len=$arg
            action=""
        elif [ $action == "-m" ]
        then
            max=$arg
            action=""
        elif [ $action == "-c" ]
        then
            count=$arg
            action=""
        elif [ $action == "-a" ]
        then
            arr[len]=$arg
            len=$((len+1))
        fi
    fi
done

if [ ${#arr[@]} -ne 0 ]
then
    bogosort
    first=1;
    result="";
    for element in "${arr[@]}"
    do
            if [ $first == 0 ]
            then
                result="${result}, "
            else
                first=0
            fi
            result="${result}${element}"
    done
    echo $result
else
	individualTimes=()
	start=$(date +"%s%N")
	individualStart=0

    for round in $( seq 0 $(($count - 1)))
    do
        if [ $verbose -eq 1 ]
        then
            individualStart=$(date +"%s%N")
        fi
        randomArray
        bogosort
        if [ $verbose -eq 1 ]
        then
            individualTimes[$round]=$((($(date +"%s%N") - individualStart) / 1000000))
            seconds=$((individualTimes[round]/1000))
            milliSeconds=$((individualTimes[round]-(seconds*1000)))
            echo "${round}: ${seconds}.${milliSeconds}s"
        fi
    done

    if [ $verbose -eq 1 ]
    then
        summedUpTime=0
        for time in ${individualTimes[@]}
        do
            summedUpTime=$((summedUpTime+time))
        done

        averageTime=$((summedUpTime/count))

        seconds=$((averageTime/1000))
        milliSeconds=$((averageTime-(seconds*1000)))
        echo "Average time: ${seconds}.${milliSeconds}s"
        seconds=$((summedUpTime/1000))
        milliSeconds=$((summedUpTime-(seconds*1000)))
        echo "Summed up time: ${seconds}.${milliSeconds}s"
    fi

    time=$((($(date +"%s%N") - start) / 1000000))
    seconds=$((time/1000))
    milliSeconds=$((time-(seconds*1000)))
    echo "Total time: ${seconds}.${milliSeconds}s"
fi