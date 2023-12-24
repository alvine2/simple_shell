Enhanced Command-Line Interface: ALX Advanced Shell

Crafted by Alvine as an essential module within the ALX educational ecosystem, the ALX Advanced Shell project surpasses the conventional Unix shell ('/bin/sh') by not only meeting fundamental criteria but also integrating a multitude of sophisticated features, elevating the command-line interaction to a superior level of efficiency and functionality.

Core Development Team
.KINYERA ALVINE
.Norbert NIRUGIRA Muhizi

Comprehensive Features and Operational Capabilities
Initial Rollout: ALX Shell 0.1
At this juncture, the shell concentrates on establishing foundational capabilities. It presents a prompt, awaiting user input for a command. Only single-word commands are processed, excluding arguments or special characters. If an executable isn't found, the shell gracefully returns an error message while proceeding to display the subsequent prompt. It adeptly handles the "end of file" condition, often triggered by Ctrl+D.

Version Advancement: ALX Shell 0.2
Expanding on its foundational features, this version introduces support for command-line arguments. The shell now comprehends not only single-word commands but also their associated arguments.

Feature-Enriched Progression: ALX Shell 0.3
This iteration elevates the shell's complexity by integrating the PATH environment variable. Additionally, it optimizes performance by refraining from invoking fork when the entered command does not exist.

Version Update: ALX Shell 0.4
At this stage, the shell acquires the capability to self-terminate via the built-in exit command, sans the need for additional arguments.

Sturdy Release: ALX Shell 1.0
This version introduces the 'env' built-in command, displaying current environment variables when invoked.

Streamlined Input Handling: ALX Shell 0.1.1
Focused on efficiency, this update features a custom getline function that efficiently reads multiple characters at once using a buffer, reducing system calls. The standard getline function is now obsolete.

Expanded Exit Command: ALX Shell 0.4.1
An extension to the existing 'exit' functionality is introduced here. The shell can now accept an integer status as an argument when exiting.

Environmental Governance: Setenv and Unsetenv
This feature set introduces two new built-in commands, 'setenv' and 'unsetenv', enabling users to initialize, modify, or remove environment variables.

Variable Substitution
This upgrade introduces the ability to dynamically handle variable replacement, including the incorporation of special variables like $? and $$.

Comment Recognition
The shell now identifies comments. Any input line starting with # is treated as a comment and remains unexecuted.

File-Driven Execution
In this advanced feature set, the shell is equipped to read commands from a file passed as a command-line argument. It reads and executes these commands one per line, without displaying a prompt or reading from stdin.


Compilation Directives
Execute the following command for compilation:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o alx_shell


