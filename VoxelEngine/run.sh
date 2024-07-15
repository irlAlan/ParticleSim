#!/bin/bash

cmake -B build/; cmake --build build/; mv ./build/libVoxelEngine.a ../lib/; cd ../; ./run.sh
