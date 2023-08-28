#!/bin/bash
if [ $# -ne 1 ]
then
echo "you can write only one options"
exit 1
fi
prov='*[/]$'
if [ -d "$1" ] || [[ $1 =~ $prov ]]
then
echo "good" > /dev/null
else
echo "No such directory"
exit 1
fi
