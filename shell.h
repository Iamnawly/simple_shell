#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * execute_command - Execute a command with arguments
 * @command: The command to be executed
 * @args: Array of arguments for the command
 */
void execute_command(char *command, char *args[]);

/**
 * handle_exit - Exit the shell
 */
void handle_exit(void);

/**
 * handle_env - Print the current environment variables
 */
void handle_env(void);

/**
 * tokenize_input - Tokenize user input into arguments
 * @input: The user input as a string
 * @args: The array to store tokenized arguments
 */
void tokenize_input(char *input, char *args[]);

/**
 * get_username - Retrieves the current username.
 *
 * Return: A pointer to the current username.
 */
char *get_username(void);

/**
 * get_current_directory - Retrieves the current working directory.
 *
 * Return: A pointer to the current working directory.
 */
char *get_current_directory(void);

#endif /* SHELL_H */

