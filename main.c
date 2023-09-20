#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * printPrompt - Print the shell prompt
 */
void printPrompt(void)
{
    if (isatty(STDIN_FILENO)) {
        printf("$ ");
        fflush(stdout);
    }
}

/**
 * processInput - Process user input
 * @input: The user input as a string
 * @args: The array to store tokenized arguments
 */
void processInput(char input[], char *args[])
{
    if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
        if (isatty(STDIN_FILENO)) {
            printf("\n");
        }
    } else {
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) != 0) {
            if (strcmp(input, "exit") == 0) {
                handle_exit();
            } else if (strcmp(input, "env") == 0) {
                handle_env();
            } else {
                tokenize_input(input, args);
                execute_command(args[0], args);
            }
        }
    }
}

int main(void)
{
    char input[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];

    while (1) {
        printPrompt();
        processInput(input, args);
        printPrompt();
    }

    return 0;
}

