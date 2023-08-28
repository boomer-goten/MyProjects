#!/bin/bash
Errors=0
if [ $# -ne 6 ]
then
    echo "you can write only six option"
    (( Errors++ ))
else 


    first_reg='^[/]'
    if [[ $1 =~ $Third_reg ]]
    then
        if [[ -d $1 ]]
        then
            echo "good $1"
        else
            echo "bad argument $1"
            (( Errors++ ))
        fi
    else
        echo "use absolute path"
        (( Errors++ ))
    fi

    second_reg='^[1-9]{1,5}$'
    if [[ $2 =~ $second_reg ]]
    then
        echo "good $2"
    else
        echo "use only digital"
        (( Errors++ ))
    fi

    Third_reg='^[a-zA-Z]{1,7}$'
    if [[ $3 =~ $Third_reg ]]
    then
        echo "good $3"
    else
        echo "use english letters or you write too many letters for third argument"
        (( Errors++ ))
    fi

    fourth_reg='^[1-9]{1,5}$'
    if [[ $4 =~ $fourth_reg ]]
    then
        echo "good $4"
    else
        echo "use only digital"
        (( Errors++ ))
    fi


    Fifth_reg='^[a-zA-Z]{1,7}.[a-zA-Z]{1,3}$'
    if [[ $5 =~ $Fifth_reg ]]
    then
        echo "good $5"
    else
        echo "use english letters or you write too many letters for Fifth argument"
        (( Errors++ ))
    fi


    Sixth_reg='(^100kb$)|(^[0-9]{1,2}kb$)'
    if [[ $6 =~ $Sixth_reg ]]
    then
        echo "good $6"
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