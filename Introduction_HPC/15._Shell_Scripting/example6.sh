#!/bin/bash
           
T1=$1
T2=$2

if [ $T1 -lt $T2 ] 
then
    echo The first number $T1 is less than to the second one $T2
else
    echo The second number $T2 is less than or equal to the first one $T1 
fi

