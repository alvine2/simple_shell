#!/bin/bash

# Array of test scripts for Task 8
declare -a tests=("exit_1000.bash"
                  "exit_with_status.bash"
                  "exit_neg_number.bash"
                  "exit_no_arg_1.bash"
                  "exit_no_arg.bash"
                  "exit_string.bash")

# Path to your custom shell executable
SHELL_EXEC="./hsh"

# Loop over each test script in the array and run it
for test_script in "${tests[@]}"
do
    echo "Running test: $test_script"
    ./checker.bash $SHELL_EXEC $test_script
done
