#include "shell.h"

/**
 * parse_input - Parse the input into command and arguments
 * @input: The input string
 * @cmd: Pointer to store the command
 * @args: Pointer to store the arguments
 **/
void parse_input(char *input, char **cmd, char **args)
{
*cmd = input;
while (*input != '\0' && *input != ' ')
input++;
if (*input != '\0')
{
*input = '\0';
input++;
}
*args = input;
}

/**
 * execute_command - Execute the given command with arguments
 * @cmd: The command to execute
 * @args: The arguments for the command
 **/
void execute_command(char *cmd, char **args)
{
pid_t child_pid;
int status;

if (access(cmd, X_OK) != -1)
{
child_pid = fork();
if (child_pid == -1)
{
perror("fork");
return;
}
if (child_pid == 0)
{
/* Child process */
execvp(cmd, args);
perror("execvp");
_exit(EXIT_FAILURE);
}
else
{
/* Parent process */
/* Wait for child to finish */
waitpid(child_pid, &status, 0);
}
}
else
{
printf("No such file or directory: %s\n", cmd);
}
}

/**
 * print_env - Print the current environment variables
 */
void print_env(void)
{
char **env = environ;

while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}

/**
 * run_shell - Run the shell program
 **/
void run_shell(void)
{
char input[BUFFER_SIZE];
char *cmd;
char *args;

while (1)
{
/* Display custom prompt */
printf("#cisfun$ ");

/* Read input */
if (fgets(input, sizeof(input), stdin) == NULL)
{
/* Handle end of file (Ctrl+D) */
printf("\n");
break;
}

/* Remove newline character */
input[strcspn(input, "\n")] = '\0';

/* Parse input */
parse_input(input, &cmd, &args);

/* Check for exit command */
if (strcmp(cmd, "exit") == 0)
{
int exit_status = 0;
if (*args != '\0')
exit_status = atoi(args);
exit(exit_status);
}
if (strcmp(cmd, "env") == 0)
{
print_env();
continue;
}
/* Execute command */
execute_command(cmd, &args);
}
}

