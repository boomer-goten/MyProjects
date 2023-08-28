#!/bin/bash
RAM_TOTAL=$(cat /proc/meminfo | grep MemTotal | cut -d ":" -f 2 | xargs | cut -d ' ' -f 1)
RAM_FREE=$(cat /proc/meminfo | grep MemFree | cut -d ":" -f 2 | xargs | cut -d ' ' -f 1)
GB=$(( 1024 * 1024 ))
if [ $RAM_TOTAL -ge $GB ]
then
RAM_TOTAL=$(bc<<<"scale=3;$RAM_TOTAL/1024/1024")
echo "RAM_TOTAL = $RAM_TOTAL GB"
else
RAM_TOTAL=$(bc<<<"scale=3;$RAM_TOTAL/1024/1024")
echo "RAM_TOTAL = 0$RAM_TOTAL GB"
fi
if [ $RAM_FREE -ge $GB ]
then
RAM_FREE=$(bc<<<"scale=3;$RAM_FREE/1024/1024")
echo "RAM_FREE = $RAM_FREE GB"
else
RAM_FREE=$(bc<<<"scale=3;$RAM_FREE/1024/1024")
echo "RAM_FREE = 0$RAM_FREE GB"
fi
RAM_USED=$(free | grep Память | xargs | cut -d " " -f 3 | xargs)
if [ $RAM_USED -ge $GB ]
then
RAM_USED=$(bc<<<"scale=3;$RAM_USED/1024/1024")
echo "RAM_USED = $RAM_USED GB"
else
RAM_USED=$(bc<<<"scale=3;$RAM_USED/1024/1024")
echo "RAM_USED = 0$RAM_USED GB"
fi