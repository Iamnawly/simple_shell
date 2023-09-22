#include "shell.h"

/**
 * get_builtin - this defines the builtin commands
 * @command: The shows a command to match.
 * Return: this is a pointer to the corresponding builtin.
 */
int (*get_builtin(char *command))(char **args, char **front)
{
builtin_t funcs[] = {
{ "exit", my_exit },
{ "env", my_env },
{ "setenv", my_setenv },
{ "unsetenv", my_unsetenv },
{ "cd", my_cd },
{ "alias", my_alias },
{ NULL, NULL }
};
int i;

for (i = 0; funcs[i].name; i++)
{
if (_strcmp(funcs[i].name, command) == 0)
break;
}
return (funcs[i].f);
}

/**
 * my_exit -  this is allowed to terminates a process
 * @args: this is the aray of arguments which contains the exit value.
 * @front: pointer to the beginning.
 * Return: no arguments
 */
int my_exit(char **args, char **front)
{
int i, len_of_int = 10;
unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

if (args[0])
{
if (args[0][0] == '+')
{
i = 1;
len_of_int++;
}
for (; args[0][i]; i++)
{
if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
num = (num * 10) + (args[0][i] - '0');
else
return (create_error(--args, 2));
}
}
else
{
return (-3);
}
if (num > max - 1)
return (create_error(--args, 2));
args -= 1;
free_args(args, front);
free_env();
free_alias_list(aliases);
exit(num);
}

/**
 * my_cd - thus changes current directory of the shellby process.
 * @args: this is an array of arguments.
 * @front: this defines a  double pointer to beginning of args
 * Return: If the given string is not a directory
 */
int my_cd(char **args, char __attribute__((__unused__)) **front)
{
char **dir_info, *new_line = "\n";
char *oldpwd = NULL, *pwd = NULL;
struct stat dir;

oldpwd = getcwd(oldpwd, 0);
if (!oldpwd)
return (-1);

if (args[0])
{
if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
{
if ((args[0][1] == '-' && args[0][2] == '\0') ||
args[0][1] == '\0')
{
if (_getenv("OLDPWD") != NULL)
(chdir(*_getenv("OLDPWD") + 7));
}
else
{
free(oldpwd);
return (create_error(args, 2));
}
}
else
{
if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
&& ((dir.st_mode & S_IXUSR) != 0))
chdir(args[0]);
else
{
free(oldpwd);
return (create_error(args, 2));
}
}
}
else
{
if (_getenv("HOME") != NULL)
chdir(*(_getenv("HOME")) + 5);
}

pwd = getcwd(pwd, 0);
if (!pwd)
return (-1);

dir_info = malloc(sizeof(char *) * 2);
if (!dir_info)
return (-1);

dir_info[0] = "OLDPWD";
dir_info[1] = oldpwd;
if (my_setenv(dir_info, dir_info) == -1)
return (-1);

dir_info[0] = "PWD";
dir_info[1] = pwd;
if (my_setenv(dir_info, dir_info) == -1)
return (-1);
if (args[0] && args[0][0] == '-' && args[0][1] != '-')
{
write(STDOUT_FILENO, pwd, _strlen(pwd));
write(STDOUT_FILENO, new_line, 1);
}
free(oldpwd);
free(pwd);
free(dir_info);
return (0);
}


