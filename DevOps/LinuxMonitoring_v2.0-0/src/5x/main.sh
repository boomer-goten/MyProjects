#!/bin/bash
ECHO_VVOD="./arguments.sh"
if [ ! -f "$ECHO_VVOD" ]; 
then
    echo "$ECHO_VVOD not found"
    exit 10
fi
source "$ECHO_VVOD"

# First method
if [[ $1 -eq 1 ]]
then
    awk '{print $0}' ../4x/*.log | sort -k8
fi

# Second method
if [[ $1 -eq 2 ]]
then
    cat ../4x/*.log | awk '{print $1}' | sort -u
fi

# Third method
if [[ $1 -eq 3 ]]
then
    grep -Eh '[4-5][0-9]{2}' ../4x/*.log | awk '{print $0}'
fi

# Fourth method
if [[ $1 -eq 4 ]]
then
    grep -Eh '[4-5][0-9]{2}' ../4x/*.log | awk '{print $1}' | sort -u
fi