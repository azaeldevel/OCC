#!/bin/bash

for run in {1..10}; do
  ./Debug/src/develop-lexer-flex-c90 < src/main-c90.c > flex-c90.txt
done