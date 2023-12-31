#include "shell.h"

/**
 * my_env - this defines a fuction that prints the current environment.
 * @args: this is a an array of arguments passed to shell.
 * @front: A pointer to the beginning of args.
 * Return: when an error occurs
 */
int my_env(char **args, char __attribute__((__unused__)) **front)
{
int index;
char nc = '\n';

if (!environ)
return (-1);

for (index = 0; environ[index]; index++)
{
write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
write(STDOUT_FILENO, &nc, 1);
}

(void)args;
return (0);
}

/**
 * my_setenv - Changes or adds to the PATH, an enviromental variable.
 * @args: this is an array of arguments passed to shell.
 * @front: this defines a double pointer starting point of args.
 * Description: args new or existing variable
 * Return: If an error occurs
 */
int my_setenv(char **args, char __attribute__((__unused__)) **front)
{
char **env_var = NULL, **new_environ, *new_value;
size_t size;
int index;

if (!args[0] || !args[1])
return (create_error(args, -1));

new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
if (!new_value)
return (create_error(args, -1));
_strcpy(new_value, args[0]);
_strcat(new_value, "=");
_strcat(new_value, args[1]);

env_var = _getenv(args[0]);
if (env_var)
{
free(*env_var);
*env_var = new_value;
return (0);
}
for (size = 0; environ[size]; size++)
		;

new_environ = malloc(sizeof(char *) * (size + 2));
if (!new_environ)
{
free(new_value);
return (create_error(args, -1));
}

for (index = 0; environ[index]; index++)
new_environ[index] = environ[index];

free(environ);
environ = new_environ;
environ[index] = new_value;
environ[index + 1] = NULL;

return (0);
}

/**
 * my_unsetenv - this deletes an environmental variable from the PATH.
 * @args: this defines an array of argument passed to shell.
 * @front: this a double pointer to the starting point of args.
 * Return: If an error occurs
 */
int my_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
char **env_var, **new_environ;
size_t size;
int index, index2;

if (!args[0])
return (create_error(args, -1));
env_var = _getenv(args[0]);
if (!env_var)
return (0);

for (size = 0; environ[size]; size++)
		;

new_environ = malloc(sizeof(char *) * size);
if (!new_environ)
return (create_error(args, -1));

for (index = 0, index2 = 0; environ[index]; index++)
{
if (*env_var == environ[index])
{
free(*env_var);
continue;
}
new_environ[index2] = environ[index];
index2++;
}
free(environ);
environ = new_environ;
environ[size - 1] = NULL;
return (0);
}

