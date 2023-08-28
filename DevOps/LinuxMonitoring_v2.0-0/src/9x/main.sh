#!/bin/bash
#CPU
while true
do
TOTALMEM=$(free -m | awk '$1=="Mem:" {print $2}')
FS_USAGE=$(df -PTh|egrep -iw "ext4|ext3|xfs|gfs|gfs2|btrfs"|grep -v "loop"|sort -k6n|awk '!seen[$1]++')
echo -e "CPU Cores\t\t" `awk -F: '/model name/ {core++} END {print core}' /proc/cpuinfo` > index.html
echo -e "<br>" >> index.html
echo -e "CPU MHz:\t\t" `lscpu | grep -oP 'CPU MHz:\s*\K.+'` >> index.html
echo -e "<br>" >> index.html
echo -e "CPU Usage:\t\t" `cat /proc/stat | awk '/cpu/{printf("%.2f%\n"), ($2+$4)*100/($2+$4+$5)}' |  awk '{print $0}' | head -1` >> index.html
echo -e "<br>" >> index.html
echo -e "RAM:\t\t\t" "${TOTALMEM}Mb" >> index.html
echo -e "<br>" >> index.html
echo -e "Memory Usage:\t\t" `free | awk '/Mem/{printf("%.2f%"), $3/$2*100}'` >> index.html
echo -e "<br>" >> index.html
if free | awk '/^Swap:/ {exit !$2}'; then
	TOTALSWAP=$(free -m | awk '$1=="Swap:" {print $2}')
	echo -e "Total swap:\t\t" "${TOTALSWAP}Mb" >> index.html
    echo -e "<br>" >> index.html
	echo -e "Swap Usage:\t\t" `free | awk '/Swap/{printf("%.2f%"), $3/$2*100}'` >> index.html
    echo -e "<br>" >> index.html
else
	Error "Swap Usage:\t\t" "swap does not exist"
fi
    COL3=
	COL1=$(echo "$FS_USAGE"|awk '{print $1 " "$7}')
	COL2=$(echo "$FS_USAGE"|awk '{print $6}'|sed -e 's/%//g')
	for i in $(echo "$COL2"); do
	{
	    COL3="$(echo -e $i"% $SuccessMark\n$COL3")"
	}
	done
	COL3=$(echo "$COL3"|sort -k1n)
	paste  <(echo "$COL1") <(echo "$COL3") <(echo "<br>") -d' '|column -t >> index.html
    sleep 5
done