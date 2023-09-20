#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * handle_exit - this exit the shell
 */
void handle_exit(void)
{
exit(EXIT_SUCCESS);
}

/**
 * handle_env - this prints the current environment variables
 */
void handle_env(void)
{
char **env = environ;

while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}
/**
 * process_input - the process user input
 * @input: the User input as a string
 * @args: the array to store tokenized arguments
 */
void process_input(char input[], char *args[])
{
tokenize_input(input, args);
}

/**
 * tokenize_input - this always tokenize input string into arguments
 * @input: this User input as a string
 * @args: an array to store tokenized arguments
 */
void tokenize_input(char *input, char *args[])
{
char *token = strtok(input, " ");
int z = 0;

while (token != NULL && z < MAX_ARGUMENTS - 1)
{
args[z++] = token;
token = strtok(NULL, " ");
}
args[z] = NULL;
}

