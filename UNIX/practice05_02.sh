#!/bin/sh

# 10504_e02.sh

LANG=en_US

get_weekday(){
    echo -n "$sinput is: "
    date -d $1 +'%A'
}

echo "Please input a date in the formate yyyy/mm/dd."

read sinput

get_weekday $sinput