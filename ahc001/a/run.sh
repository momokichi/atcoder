#!/bin/sh

g++ main.cpp
./a.out < test/sample-1.in > sample-1.out
cd tools/
cargo run --release --bin vis ../test/sample-1.in ../sample-1.out
cd ../