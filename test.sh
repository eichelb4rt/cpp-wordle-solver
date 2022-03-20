#!/bin/bash

cd build 2> /dev/null || echo "build first!"; exit 1
make test
