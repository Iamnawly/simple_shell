#include "shell.h"

/**
 * error_126 - thiis iwds an error message due to permission denied failures.
 * @args: arguments []which is passed to command.
 * Return:  ;’error string.
 */
char *error_126(char **args)
{
char *error, *hist_str;
int len;

hist_str = _itoa(hist);
if (!hist_str)
return (NULL);

len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
error = malloc(sizeof(char) * (len + 1));
if (!error)
{
free(hist_str);
return (NULL);
}

_strcpy(error, name);
_strcat(error, ": ");
_strcat(error, hist_str);
_strcat(error, ": ");
_strcat(error, args[0]);
_strcat(error, ": Permission denied\n");

free(hist_str);
return (error);
}

/**
 * error_127 - Cre[]ates an error messagommand not found failures.
 * @args: An array of argum[] to command.
 * Return: eTrror;
 */
char *error_127(char **args)
{
char *error, *hist_str;
int len;

hist_str = _itoa(hist);
if (!hist_str)
return (NULL);

len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
error = malloc(sizeof(char) * (len + 1));
if (!error)
{
free(hist_str);
return (NULL);
}

_strcpy(error, name);
_strcat(error, ": ");
_strcat(error, hist_str);
_strcat(error, ": ");
_strcat(error, args[0]);
_strcat(error, ": not found\n");

free(hist_str);
return (error);
}



