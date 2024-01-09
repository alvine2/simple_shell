#!/bin/bash

# Array of test scripts for Task 4
declare -a tests=("exit_no_arg.bash"
                  "exit_no_arg_1.bash")

# Path to your custom shell executable
SHELL_EXEC="./hsh"

# Loop over each test script in the array and run it
for test_script in "${tests[@]}"
do
    echo "Running test: $test_script"
    ./checker.bash $SHELL_EXEC $test_script
done
