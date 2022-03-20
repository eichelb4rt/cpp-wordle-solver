#!/bin/bash

cd build 2>/dev/null || { echo "build first!"; exit 1; }
ctest -j10 -C Debug -T test --output-on-failure
