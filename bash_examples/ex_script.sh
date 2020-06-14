#!/bin/bash

cd run_external_scripts/              # change working directory to run_external_scripts
echo -e "\nNEW DIRECTORY: \c"         # announce directory change
pwd                                   # print working directory
python3 bashpy.py                     # execute bashpy.py
cd ..                                 # go up one directory
cd ..
cd Palindromer/                       # change working directory to Palindromer/
echo -e "\nNEW DIRECTORY: \c"
pwd                                   # print working directory
g++ palindromer.cpp -o palindromer    # compile palindromer.cpp
./palindromer                         # execute palindromer
