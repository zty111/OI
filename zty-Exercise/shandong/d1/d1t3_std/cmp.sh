#! /bin/bash
# Compare myans with ans
g++ *.cpp
num=1
numwa=0

while (($num<11)) 
do
    time ./a.out < *${num}.in > a.o
    tim=($Time - $Tims)
    if diff a.o *${num}.out -b; then
        printf "AC for ${num} in ${tim} ms\n"
    else
        printf "WA for ${num}\n"
        let "numwa=1"
    fi
    let "num++"
done


if(($numwa>0)); then printf "WrongAnswer\n"
else printf "Accept\n"
fi