#!/bin/bash
START=$(date +%s%N)
dates_begin="$(date)"
ECHO_VVOD="./arguments.sh"
echo "" > sys.log
if [ ! -f "$ECHO_VVOD" ]; 
then
    echo "$ECHO_VVOD not found"
    exit 10
fi
source "$ECHO_VVOD"

exec 2>/dev/null

count_of_dir=$(echo "$(find /home/boomergo/ -type d -perm /a=rwx | grep -v -e "\." -e "sbin" -e "bin" | wc -l)")

# Команда для вывода текущего размера размера
Current_memory=$(df -Th / | awk -F"G" '{printf $2}' | xargs | tr , .);
# Команда для вывода всего обьема
All_memory=$(df -Th / | awk -F"G" '{printf $1}' | awk '{printf $10}' | tr , .);
Current_free=$(bc<<<"scale=1; $All_memory-$Current_memory")
# Считаем длинну символов
dates="$(date +%d%m%y)"
length_dirname=$(expr length "$1")
length_filename=$(expr length "$2")
# regular='(^0$)|(^.[0-9]$)'
regular='^1.0$'
tmp_name_begin=$1
tmp_filename_begin=$2
tmp=$(echo "${tmp_name_begin:0:1}")
tmp_file=$(echo "${tmp_filename_begin:0:1}")
# Дозаполняем название первой папки до 5 симоволов если их было меньше
if [ $length_dirname -lt 5 ]
then
    while [ $length_dirname -ne 5 ]
    do
        tmp_name_begin=$(echo "$tmp_name_begin" | sed "s/^/$tmp/")
        (( length_dirname++ ))
    done
fi
if [ $length_filename -lt 5 ]
then
    while [ $length_filename -ne 5 ]
    do
        tmp_filename_begin=$(echo "$tmp_filename_begin" | sed "s/^/$tmp_file/")
        (( length_dirname++ ))
    done
fi
str=($tmp_name_begin\_$(date +%d%m%y))
str_file=($tmp_filename_begin\_$(date +%d%m%y))
str1=$str
file_weight=$(echo "$3" | awk -F"M" '{printf $1}')
for (( o=1; o <= $count_of_dir; o++ ))
do
    some_dirs[o]=$(echo "$(find /home/boomergo -type d -perm /a=rwx | grep -v -e "\." -e "sbin" -e "bin" | sed -n $o\p)")
done
if [[ $Current_free =~ $regular ]]
then 
    echo "You have too little space on your device"
else
    while [[ !($Current_free =~ $regular) ]]
    do
        for (( d=1; d <= $count_of_dir; d++ ))
        do
            tmp_roditel=${some_dirs[d]}
            tmp_dirname=$tmp_roditel/$str1
            mkdir $tmp_dirname
            file_name=$str_file
            echo "$tmp_dirname $dates" >> sys.log
            randomNumber=$(shuf -i 1-5 -n1)
            for (( x=1; x <= $randomNumber; x++ ))
            do
                fallocate -l "$file_weight"M $tmp_dirname/$file_name
                echo "$tmp_dirname/$file_name $dates $3" >> sys.log
                file_name=$(echo "$file_name" | sed "s/^/$tmp_file/")
                Current_memory=$(df -Th / | awk -F"G" '{printf $2}' | xargs | tr , .);
                All_memory=$(df -Th / | awk -F"G" '{printf $1}' | awk '{printf $10}' | tr , .);
                Current_free=$(bc<<<"scale=1; $All_memory-$Current_memory")
                if [[ $Current_free =~ $regular ]]
                then
                    break
                fi
            done
            if [[ $Current_free =~ $regular ]]
            then
                break
            fi
            tmp_dirname+="/"
            str2=$str
            randomNumber=$(shuf -i 1-100 -n1)
            for (( i=1; i <= $randomNumber; i++ ))
            do
                tmp_dirname=$tmp_dirname$str2/
                mkdir "$tmp_dirname"
                echo "$tmp_dirname $dates" >> sys.log
                file_name=$str_file
                randomNumber=$(shuf -i 1-5 -n1)
                for (( j=1; j <= $randomNumber; j++ ))
                do
                    fallocate -l "$file_weight"M $tmp_dirname/$file_name
                    echo "$tmp_dirname$file_name $dates $3" >> sys.log
                    file_name=$(echo "$file_name" | sed "s/^/$tmp_file/")
                    Current_memory=$(df -Th / | awk -F"G" '{printf $2}' | xargs | tr , .);
                    All_memory=$(df -Th / | awk -F"G" '{printf $1}' | awk '{printf $10}' | tr , .);
                    Current_free=$(bc<<<"scale=1; $All_memory-$Current_memory")
                    if [[ $Current_free =~ $regular ]]
                    then
                        break
                    fi
                done
                str2=$(echo "$str2" | sed "s/^/$tmp/")
                if [[ $Current_free =~ $regular ]]
                then
                    break
                fi
            done
            if [[ $Current_free =~ $regular ]]
            then
                break
            fi
        done
        if [[ $Current_free =~ $regular ]]
        then
            break
        fi
        str1=$(echo "$str1" | sed "s/^/$tmp/")
    done
fi
dates_end="$(date)"
END=$(date +%s%N)
DIFF=$((($END - $START)/1000000))
echo "Data_nachala=$dates_begin" >> sys.log
echo "Data_konca=$dates_end" >> sys.log
if [ $DIFF -ge 1000 ]
then
    DIFF=$(bc<<<"scale=1;$DIFF/1000")
    echo "Время выполнения=$DIFF c" >> sys.log 
else
    DIFF=$(bc<<<"scale=1;$DIFF/1000")
    echo "Время выполнения=0$DIFF c" >> sys.log
fi

