#!/bin/bash
default[1]=1
default[2]=2
default[3]=1
default[4]=2
output[1]=default
output[2]=default
output[3]=default
output[4]=default
colors[1]=white
colors[2]=red
colors[3]=green
colors[4]=blue
colors[5]=purple
colors[6]=black
re='^[1-6]$'
count=1
IFS=$'\n'
for entry in $(cat ./configure.txt | cut -d '=' -f 2)
do
echo "$entry"
arr[$count]=$entry
output[$count]=$entry
if ! [[ ${arr[$count]} =~ $re ]] || [[ "x${arr[$count]}" = "x\n" ]]
then
arr[$count]=${default[$count]}
output[$count]=defualt
fi
if [ $count -eq 4 ]
then
break
fi
count=$(( $count + 1 ))
done
if [[ ${arr[1]} == ${arr[2]} ]] || [[ ${arr[3]} == ${arr[4]} ]]
then
echo "The same parameters were entered. please change the config file"
exit 0
fi
# Color text
NORMAL[0]='\033[0m'    #NORMAL
TEXT[1]='\033[1;37m'   #WHITE
TEXT[2]='\033[1;31m'   #RED
TEXT[3]='\033[1;32m'   #GREEN
TEXT[4]='\033[1;34m'   #BLUE
TEXT[5]='\033[1;35m'   #PURPLE
TEXT[6]='\033[1;30m'   #BLACK
# Color background
BACKGROUND[1]='\033[47m'   #WHITE
BACKGROUND[2]='\033[41m'   #RED
BACKGROUND[3]='\033[42m'   #GREEN
BACKGROUND[4]='\033[44m'   #BLUE
BACKGROUND[5]='\033[45m'   #PURPLE
BACKGROUND[6]='\033[40m'   #BLACK
color_1=${TEXT[${arr[1]}]}${BACKGROUND[${arr[2]}]}
color_2=${TEXT[${arr[3]}]}${BACKGROUND[${arr[4]}]}