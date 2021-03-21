#!/bin/sh

g++ main.cpp

for i in `seq 1 51`
do
    id=`printf %04d $i`
    ./a.out < tools/in/$id.txt > tools/out/$id.txt
done

cd tools/

for i in `seq 1 51`
do
    id=`printf %04d $i`
    cargo run --release --bin vis in/$id.txt out/$id.txt
done

cd ../