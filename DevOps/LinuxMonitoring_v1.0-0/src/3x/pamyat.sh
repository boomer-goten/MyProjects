#!/bin/bash
RAM_TOTAL=$(cat /proc/meminfo | grep MemTotal | cut -d ":" -f 2 | xargs | cut -d ' ' -f 1)
RAM_FREE=$(cat /proc/meminfo | grep MemFree | cut -d ":" -f 2 | xargs | cut -d ' ' -f 1)
GB=$(( 1024 * 1024 ))
if [ $RAM_TOTAL -ge $GB ]
then
RAM_TOTAL=$(bc<<<"scale=3;$RAM_TOTAL/1024/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}RAM_TOTAL${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$RAM_TOTAL GB${NORMAL[0]}"
else
RAM_TOTAL=$(bc<<<"scale=3;$RAM_TOTAL/1024/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}RAM_TOTAL${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}0$RAM_TOTAL GB${NORMAL[0]}"
fi
if [ $RAM_FREE -ge $GB ]
then
RAM_FREE=$(bc<<<"scale=3;$RAM_FREE/1024/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}RAM_FREE${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$RAM_FREE GB${NORMAL[0]}"
else
RAM_FREE=$(bc<<<"scale=3;$RAM_FREE/1024/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}RAM_FREE${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}0$RAM_FREE GB${NORMAL[0]}"
fi
RAM_USED=$(free | grep Память | xargs | cut -d " " -f 3 | xargs)
if [ $RAM_USED -ge $GB ]
then
RAM_USED=$(bc<<<"scale=3;$RAM_USED/1024/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}RAM_USED${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$RAM_USED GB${NORMAL[0]}"
else
RAM_USED=$(bc<<<"scale=3;$RAM_USED/1024/1024")
echo -e "${TEXT[$1]}${BACKGROUND[$2]}RAM_USED${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}0$RAM_USED GB${NORMAL[0]}"
fi