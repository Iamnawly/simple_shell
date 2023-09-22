#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Declaration of environ as an external variable */
extern char **environ;

#define BUFFER_SIZE 1024

/**
 * parse_input - Parse the input into command and arguments
 * @input: The input string
 * @cmd: Pointer to store the command
 * @args: Pointer to store the arguments
 */
void parse_input(char *input, char **cmd, char **args);

/**
 * execute_command - Execute the given command with arguments
 * @cmd: The command to execute
 * @args: The arguments for the command
 */
void execute_command(char *cmd, char **args);

/**
 * run_shell - Run the shell program
 */
void run_shell();

/**
 * print_env - Print the current environment variables
 */
void print_env(void);


#endif /* SHELL_H */

