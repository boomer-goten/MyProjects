#!/bin/bash
Errors=0
if [ $# -ne 3 ]
then
    echo "you can write only three option"
    (( Errors++ ))
else 


    Third_reg='^[a-zA-Z]{1,7}$'
    if [[ $1 =~ $Third_reg ]]
    then
        echo "good $1"
    else
        echo "use english letters or you write too many letters for third argument"
        (( Errors++ ))
    fi

    Fifth_reg='^[a-zA-Z]{1,7}.[a-zA-Z]{1,3}$'
    if [[ $2 =~ $Fifth_reg ]]
    then
        echo "good $2"
    else
        echo "use english letters or you write too many letters for Fifth argument"
        (( Errors++ ))
    fi


    Sixth_reg='(^100kb$)|(^[0-9]{1,2}Mb$)'
    if [[ $3 =~ $Sixth_reg ]]
    then
        echo "good $3"
    else
        echo "Write the size with Mb but no more than a hundred"
        (( Errors++ ))
    fi
fi
if [ $Errors -ne 0 ]
then
    echo "Repeat script with another arguments"
    exit 1
fi