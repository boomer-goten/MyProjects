#!/bin/bash
ECHO_VVOD="./arguments.sh"
if [ ! -f "$ECHO_VVOD" ]; 
then
    echo "$ECHO_VVOD not found"
    exit 10
fi
source "$ECHO_VVOD"

# First method
if [[ $1 -eq 1 ]]
then
    j=0
    count_of_dir="$(cat ../2x/sys.log | awk '{print $1}' | grep "^/" | wc -l)"
    for (( i=1; i <= $count_of_dir; i++ ))
    do
        name_dir="$(cat ../2x/sys.log | awk '{print $1}' | grep "^/" | sed -n $i\p)"
        if [ -d $name_dir ]
        then
            name_dir_for_rm[j]=$name_dir
            (( j++ ))
        fi
    done
    for (( i=0; i < $j; i++ ))
    do
        rm -rf ${name_dir_for_rm[i]}
    done
fi

# Second method
if [ $1 -eq 2 ]
then
    echo "Введите дату начала и конца в формате YYMMDDHHMM-YYMMDDHHMM"
    read time_vvod
    regular='^((22)+((1[0-2])|([0][0-9]))+((3[0-1])|([0-2][0-9]))+((2[0-3])|([0-1][0-9]))+((60)|([0-5][0-9]))+(-)+(22)+((1[0-2])|([0][0-9]))+((3[0-1])|([0-2][0-9]))+((2[0-3])|([0-1][0-9]))+((60)|([0-5][0-9])))$'
    if [[ $time_vvod =~ $regular ]]
    then
        first_date=$(echo "$time_vvod" | awk -F"-" '{printf $1}')
        second_date=$(echo "$time_vvod" | awk -F"-" '{printf $2}')
        first_date_modify="20${first_date:0:2}-${first_date:2:2}-${first_date:4:2} ${first_date:6:2}:${first_date:8:2}"
        second_date_modify="20${second_date:0:2}-${second_date:2:2}-${second_date:4:2} ${second_date:6:2}:${second_date:8:2}"
        name_mask=${first_date:4:2}${first_date:2:2}${first_date:0:2}
        echo "$first_date_modify"
        echo "$second_date_modify"
        echo "$name_mask"
        find / -mindepth 1 -newermt "${first_date_modify}" ! -newermt "${second_date_modify}" -name "*$name_mask*" -delete 2>/dev/null
    else
        echo "Неверные входные данные, запустите скрипт заново"
        exit 2
    fi
fi

# Third method
if [ $1 -eq 3 ]
then
    echo "Введите паттерн для удаления папок"
    read pattern
    regular='^[a-zA-Z]{1,7}+(_)+(((3[0-1])|([0-2][0-9]))+((1[0-2])|([0][0-9]))+(22))$'
    if [[ $pattern =~ $regular ]]
    then
        regex_symbols=$(echo "$pattern" | awk -F"_" '{print $1}')
        regex_date=$(echo "$pattern" | awk -F"_" '{print $2}')
        length_symbols=$(expr length "$regex_symbols")
        regex_for_find=*
        for (( i=0; i < $length_symbols; i++ ))
        do
            regex_for_find=$regex_for_find${regex_symbols:$i:1}
            regex_for_find=$regex_for_find*
        done
        regex_for_find=$regex_for_find"_"$regex_date
        find / -name "$regex_for_find" -exec rm -rf {} \; 2> /dev/null
    fi
fi