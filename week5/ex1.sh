#!/bin/bash
gcc publisher.c -o publisher
gcc subscriber.c -o subscriber
n=$1
num=1
i=1
while [ $i -le $n ] ; do
   x-terminal-emulator -e ./subscriber $n $num &
   i=$((i+1))
   num=$((num+1))
done
x-terminal-emulator -e ./publisher $n

