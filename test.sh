#!/bin/bash

echo "(( Building game ))"
cmake -S . -B build
cmake --build build

echo "(( Starting test ))"
gcc -o build/test test.c game.c game_actions.c -lcriterion
./build/test --verbose
