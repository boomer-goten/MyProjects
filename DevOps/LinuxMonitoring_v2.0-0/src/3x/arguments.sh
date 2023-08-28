#!/bin/bash
if [ $# -ne 1 ]
then
    echo "you can write only one option"
    exit 1
fi

First_reg='^[1-3]{1}$'
if [[ $1 =~ $First_reg ]]
then
    echo "good $1"
else
    echo "use only digits 1, 2, 3"
fi
