#!/bin/bash
if [ $# -ne 4 ]
then
echo "wrong number of options"
exit 1
fi
re='^[1-6]$'
if ! [[ $1 =~ $re ]] || ! [[ $2 =~ $re ]] || ! [[ $3 =~ $re ]] || ! [[ $4 =~ $re ]]
then
echo "numbers were not entered"
exit 1
fi
if [ $1 == $2 ] || [ $3 == $4 ]
then
echo "The same parameters were entered. Please re-run the script with different parameters"
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

echo -e "${TEXT[$1]}${BACKGROUND[$2]}HOSTNAME${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(hostname)${NORMAL[0]}"
echo -e "${TEXT[$1]}${BACKGROUND[$2]}TIMEZONE${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(timedatectl | grep "Time zone" | cut -d ":" -f 2 | xargs)${NORMAL[0]}"
echo -e "${TEXT[$1]}${BACKGROUND[$2]}USER${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(whoami)${NORMAL[0]}"
echo -e "${TEXT[$1]}${BACKGROUND[$2]}OS${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(uname) $(cat /etc/issue)${NORMAL[0]}"
echo -e "${NORMAL[0]}${TEXT[$1]}${BACKGROUND[$2]}DATE${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(date)${NORMAL[0]}"
echo -e "${TEXT[$1]}${BACKGROUND[$2]}UPTIME${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(uptime -p)${NORMAL[0]}"
echo -e "${TEXT[$1]}${BACKGROUND[$2]}UPTIME_SEC${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(cat /proc/uptime | cut -d ' ' -f 1 | cut -d '.' -f 1) sec${NORMAL[0]}"
IP=$(ip route | grep enp0s9\ proto\ kernel | xargs | cut -d " " -f 9)
echo -e "${TEXT[$1]}${BACKGROUND[$2]}IP${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$IP${NORMAL[0]}"
echo -e "${TEXT[$1]}${BACKGROUND[$2]}MASK${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(ifconfig | grep inet\  | grep "$IP" | xargs | cut -d " " -f 4)${NORMAL[0]}"
echo -e "${TEXT[$1]}${BACKGROUND[$2]}GATEWAY${NORMAL[0]} = ${TEXT[$3]}${BACKGROUND[$4]}$(ip route | grep enp0s9 | grep via | cut -d " " -f 3)${NORMAL[0]}"
ECHO_PAMYAT="./pamyat.sh"
if [ ! -f "$ECHO_PAMYAT" ]; then
echo "$ECHO_PAMYAT not found"
exit 1
fi
source "$ECHO_PAMYAT"
ECHO_KOREN="./koren.sh"
if [ ! -f "$ECHO_KOREN" ]; then
echo "$ECHO_KOREN not found"
exit 1
fi
source "$ECHO_KOREN"
