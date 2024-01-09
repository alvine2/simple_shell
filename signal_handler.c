#include "shell.h"

/**
 * sigint_handler - Handle the SIGINT signal.
 * @signo: The signal number.
 */
void sigint_handler(int signo)
{
    (void) signo; // Silence the "unused parameter" warning
    write(STDOUT_FILENO, "\n#SimpleShell$ ", 15);
    fflush(stdout);
}
