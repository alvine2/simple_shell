#!/bin/bash

# Array of test scripts for Task 3
declare -a tests=("ls_.bash"
                  "ls_in_two_parent_dir_2.bash"
                  "ls_1_arg.bash"
                  "bin_ls_1_arg_1.bash"
                  "ls_in_parent_dir.bash"
                  "ls_in_two_parent_dir.bash"
                  "ls_in_two_parent_dir_3.bash"
                  "bin_ls.bash"
                  "ls_path_bin_last.bash"
                  "bin_ls_large_input.bash"
                  "bin_ls_empty_path.bash"
                  "bin_ls_1_arg.bash"
                  "mix_ls_bin_ls_spaces.bash"
                  "ls_spaces.bash"
                  "ls_empty_path.bash"
                  "bin_ls_spaces.bash"
                  "ls_in_current_dir.bash"
                  "ls_dot_ls.bash"
                  "env_ignore_ls.bash"
                  "ls_path_bin_first.bash"
                  "env_ignore_bin_ls.bash"
                  "bin_ls_3_times.bash"
                  "bin_ls_medium_input.bash"
                  "mix_ls_bin_ls.bash"
                  "ls_path_no_bin.bash"
                  "ls_path_bin_middle.bash"
                  "empty_path_failing_cmd.bash"
                  "path_path1_var.bash"
                  "path_current_dir_ls.bash"
                  "unknown_command_no_fork.bash")

# Path to your custom shell executable
SHELL_EXEC="./hsh"

# Loop over each test script in the array and run it
for test_script in "${tests[@]}"
do
    echo "Running test: $test_script"
    ./checker.bash $SHELL_EXEC $test_script
done
