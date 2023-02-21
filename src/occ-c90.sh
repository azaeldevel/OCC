#!/bin/bash

for run in {1..100}; do
  ./Optimized/src/occ-c90 src/main-c90.c > occ-c90.txt
done