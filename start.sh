#!/bin/bash

echo "(( Building game ))"
cmake -S . -B build
cmake --build build

echo "(( Starting game ))"
build/rock-paper-scissors
