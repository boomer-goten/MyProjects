#!/bin/bash
TIME=$(date +\ %D_%m_%Y_%H_%M_%S | cut -d "/" -f 3)
exec 2>"../pomoika"
exec 1>"$TIME.status"
echo "HOSTNAME = $(hostname)"
echo "TIMEZONE = $(timedatectl | grep "Time zone" | cut -d ":" -f 2 | xargs)"
echo "USER = $(whoami)"
echo "OS = $(uname) $(cat /etc/issue)"
echo "DATE = $(date)"
echo "UPTIME = $(uptime -p)"
echo "UPTIME_SEC = $(cat /proc/uptime | cut -d ' ' -f 1 | cut -d '.' -f 1) sec"
IP=$(ip route | grep enp0s9\ proto\ kernel | xargs | cut -d " " -f 9)
echo "IP = $IP"
echo "MASK = $(ifconfig | grep inet\  | grep "$IP" | xargs | cut -d " " -f 4)"
echo "GATEWAY = $(ip route | grep enp0s9 | grep via | cut -d " " -f 3)"
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