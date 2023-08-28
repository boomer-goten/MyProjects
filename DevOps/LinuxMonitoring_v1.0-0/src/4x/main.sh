#!/bin/bash
ECHO_COLOR="./color_settings.sh"
if [ ! -f "$ECHO_COLOR" ]; then
echo "$ECHO_COLOR not found"
exit 1
fi
source "$ECHO_COLOR"
echo -e "${color_1}HOSTNAME${NORMAL[0]} = ${color_2}$(hostname)${NORMAL[0]}"
echo -e "${color_1}TIMEZONE${NORMAL[0]} = ${color_2}$(timedatectl | grep "Time zone" | cut -d ":" -f 2 | xargs)${NORMAL[0]}"
echo -e "${color_1}USER${NORMAL[0]} = ${color_2}$(whoami)${NORMAL[0]}"
echo -e "${color_1}OS${NORMAL[0]} = ${color_2}$(uname) $(cat /etc/issue)${NORMAL[0]}"
echo -e "${color_1}DATE${NORMAL[0]} = ${color_2}$(date)${NORMAL[0]}"
echo -e "${color_1}UPTIME${NORMAL[0]} = ${color_2}$(uptime -p)${NORMAL[0]}"
echo -e "${color_1}UPTIME_SEC${NORMAL[0]} = ${color_2}$(cat /proc/uptime | cut -d ' ' -f 1 | cut -d '.' -f 1) sec${NORMAL[0]}"
IP=$(ip route | grep enp0s9\ proto\ kernel | xargs | cut -d " " -f 9)
echo -e "${color_1}IP${NORMAL[0]} = ${color_2}$IP${NORMAL[0]}"
echo -e "${color_1}MASK${NORMAL[0]} = ${color_2}$(ifconfig | grep inet\  | grep "$IP" | xargs | cut -d " " -f 4)${NORMAL[0]}"
echo -e "${color_1}GATEWAY${NORMAL[0]} = ${color_2}$(ip route | grep enp0s9 | grep via | cut -d " " -f 3)${NORMAL[0]}"
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
echo -e ""
echo "Column 1 background = ${output[1]} (${colors[${arr[1]}]})"
echo "Column 1 font color = ${output[2]} (${colors[${arr[2]}]})"
echo "Column 2 background = ${output[3]} (${colors[${arr[3]}]})"
echo "Column 2 font color = ${output[4]} (${colors[${arr[4]}]})"
