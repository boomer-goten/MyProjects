#!/bin/bash
ECHO_VVOD="./arguments.sh"
echo "" >> sys.log
if [ ! -f "$ECHO_VVOD" ]; 
then
    echo "$ECHO_VVOD not found"
    exit 10
fi
source "$ECHO_VVOD"

exec 2>/dev/null


# Команда для вывода текущего размера размера
Current_memory=$(df -Th / | awk -F"G" '{printf $2}' | xargs | tr , .);
# Команда для вывода всего обьема
All_memory=$(df -Th / | awk -F"G" '{printf $1}' | awk '{printf $10}' | tr , .);
Current_free=$(bc<<<"scale=1; $All_memory-$Current_memory")

# Считаем длинну символов
dates="$(date +%d%m%y)"
length_dirname=$(expr length "$3")
regular='(^0$)|(^.[0-9]$)'
file_rashir=$(echo "$5" | awk -F"." '{printf $2}')
name_without_rashir=$(echo "$5" | awk -F"." '{printf $1}')
echo "$file_rashir"
tmp_name_begin=$3
tmp_filename_begin=$name_without_rashir
length_filename=$(expr length "$name_without_rashir")
echo "$length_filename"
tmp=$(echo "${tmp_name_begin:0:1}")
tmp_file=$(echo "${tmp_filename_begin:0:1}")
# Дозаполняем название первой папки до 4 симоволов если их было меньше
for (( u=0; u < $length_dirname; u++ ))
do
    dirname_count_begin[u]=1
    dirname_count[u]=1
    dirname_symbol_begin[u]=$(echo "${tmp_name_begin:$u:1}")
    dirname_symbol[u]=$(echo "${tmp_name_begin:$u:1}")
done
if [ $length_dirname -lt 4 ]
then
    while [ $length_dirname -ne 4 ]
    do
        tmp_name_begin=$(echo "$tmp_name_begin" | sed "s/^/$tmp/")
        (( length_dirname++ ))
        (( dirname_count[0]++ ))
        (( dirname_count_begin[0]++ ))
        dirname_symbol[0]+=$(echo "${tmp_name_begin:0:1}")
        dirname_symbol_begin[0]+=$(echo "${tmp_name_begin:0:1}")
    done
fi
if [ $length_filename -lt 4 ]
then
    while [ $length_filename -ne 4 ]
    do
        tmp_filename_begin=$(echo "$tmp_filename_begin" | sed "s/^/$tmp_file/")
        (( length_filename++ ))
    done
fi
tmp_filename_begin+=$(echo ".$file_rashir")
for (( p=0; p < $length_dirname; p++ ))
do
    dirname_begin+=$(echo "${dirname_symbol_begin[$p]}")
done
file_weight=$(echo "$6" | awk -F"k" '{printf $1}')
count_max=245
tmp_symbol=$3
m=0
if [[ $Current_free =~ $regular ]]
then 
    echo "You have too little space on your device"
else
    while [[ !($Current_free =~ $regular) ]]
    do
        for (( g=0; g < $length_dirname; g++ ))
        do
            tmp_roditel+=$(echo "${dirname_symbol[$g]}")
            (( length+=${dirname_count[$g]} ))
        done
        tmp_roditel+=$(echo "_$(date +%d%m%y)")
        # echo "$tmp_roditel"
        # echo "$length"
        tmp_dirname=$1$tmp_roditel
        mkdir $tmp_dirname
        file_name=$tmp_filename_begin
        echo "$tmp_dirname $dates" >> sys.log
        for (( x=1; x <= $4; x++ ))
        do
            fallocate -l "$file_weight"K $tmp_dirname/$file_name
            echo "$tmp_dirname/$file_name $dates $6" >> sys.log
            file_name=$(echo "$file_name" | sed "s/^/$tmp_file/")
        done
        tmp_dirname+="/"
        str2=$dirname_begin
        str2+=$(echo "_$(date +%d%m%y)")
        for (( i=1; i <= $2; i++ ))
        do
            tmp_dirname=$tmp_dirname$str2/
            mkdir "$tmp_dirname"
            echo "$tmp_dirname $dates" >> sys.log
            file_name=$tmp_filename_begin
            for (( j=1; j <= $4; j++ ))
            do
                fallocate -l "$file_weight"K $tmp_dirname/$file_name
                echo "$tmp_dirname$file_name $dates $6" >> sys.log
                file_name=$(echo "$file_name" | sed "s/^/$tmp_file/")
            done
            str2=$(echo "$str2" | sed "s/^/$tmp/")
        done 
        if [ $length -eq $count_max ]
        then
            m_local=$m
            while [ $length -eq $count_max ]
            do
                length=0
                dirname_symbol[m]=${dirname_symbol_begin[m]}
                dirname_count[m]=${dirname_count_begin[m]}
                (( m++ ))
                for (( g=0; g < $length_dirname; g++ ))
                do
                    length+=$(echo "${dirname_count[$g]}")
                done
            done
            dirname_symbol[m]+=$(echo "${tmp_symbol:$m:1}")
            (( dirname_count[m]++ ))
            m=$m_local
        else
            dirname_symbol[m]+=$(echo "${tmp_symbol:$m:1}")
            (( dirname_count[m]++ ))
        fi
        tmp_roditel=""
        length=""
        Current_memory=$(df -Th / | awk -F"G" '{printf $2}' | xargs | tr , .);
        All_memory=$(df -Th / | awk -F"G" '{printf $1}' | awk '{printf $10}' | tr , .);
        Current_free=$(bc<<<"scale=1; $All_memory-$Current_memory")
        if [[ $Current_free =~ $regular ]]
        then
            break
        fi
    done
fi


