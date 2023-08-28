#!/bin/bash
if [ $# -gt 1 ]
then
echo "Too many options"
exit 1
fi
re='^[+-]?[0-9]+([.][0-9]+)?$'
if [[ $1 =~ $re ]]
then
echo "Было введено число, некорректный ввод"
exit 1
fi
if [ -n "$1" ]
then
echo $1
else
echo "No parameters found. "
fi
