#!/bin/bash

# Array of test scripts for Task 1
declare -a tests=("bin_ls.bash"
                  "bin_ls_3_times.bash"
                  "bin_ls_spaces.bash"
                  "ls_in_current_dir.bash"
                  "empty_input_small.bash"
                  "empty_input_large.bash"
                  "empty_input_medium.bash")

# Path to your custom shell executable
SHELL_EXEC="./hsh"

# Loop over each test script in the array and run it
for test_script in "${tests[@]}"
do
    echo "Running test: $test_script"
    ./checker.bash $SHELL_EXEC $test_script
done
