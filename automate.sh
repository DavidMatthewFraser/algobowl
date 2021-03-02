#!/bin/bash
x=270 
for filename in ./inputs/*.txt; do
    x=$((x+1))
    ./make_chain < $filename > "./out/out_$x" 
done
