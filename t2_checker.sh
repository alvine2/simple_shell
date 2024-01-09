#!/bin/bash

# Array of test scripts for Task 2
declare -a tests=("bin_ls_1_arg.bash"
                  "bin_ls_1_arg_1.bash"
                  "echo_1_arg.bash")

# Path to your custom shell executable
SHELL_EXEC="./hsh"

# Loop over each test script in the array and run it
for test_script in "${tests[@]}"
do
    echo "Running test: $test_script"
    ./checker.bash $SHELL_EXEC $test_script
done
