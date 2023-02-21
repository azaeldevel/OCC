#!/bin/bash

echo "OCC Lexer"
time src/occ-c90.sh

echo ""
echo "Flex lexer"
time src/flex-c90.sh