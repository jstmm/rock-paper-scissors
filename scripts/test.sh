#!/bin/bash

echo "(( Building game ))"
cmake -S . -B build
cmake --build build

echo "(( Starting test ))"
build/tests/tests
