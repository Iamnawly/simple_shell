#include "shell.h"

/**
 * free_args - this defines and frees memory taken by args.
 * @args: double pointer which contains commands/arguments.
 * @front: pointer to the beginning of args.
 */
void free_args(char **args, char **front)
{
size_t z;

for (z = 0; args[z] || args[z + 1]; z++)
free(args[z]);

free(front);
}

/**
 * get_pid - this obtains the current process ID.
  * Return: This is the current process ID or NULL on failure.
 */
char *get_pid(void)
{
size_t i = 0;
char *buffer;
ssize_t file;

file = open("/proc/self/stat", O_RDONLY);
if (file == -1)
{
perror("Cant read file");
return (NULL);
}
buffer = malloc(120);
if (!buffer)
{
close(file);
return (NULL);
}
read(file, buffer, 120);
while (buffer[i] != ' ')
i++;
buffer[i] = '\0';

close(file);
return (buffer);
}

/**
 * get_env_value -  this gets the value corresponding to an env variable.
 * @beginning: This is the env variable to search for.
 * @len: This is the length of the environmental variable to search for.
 * Return: an empty string.
 */
char *get_env_value(char *beginning, int len)
{
char **var_addr;
char *replacement = NULL, *temp, *var;

var = malloc(len + 1);
if (!var)
return (NULL);
var[0] = '\0';
_strncat(var, beginning, len);

var_addr = _getenv(var);
free(var);
if (var_addr)
{
temp = *var_addr;
while (*temp != '=')
temp++;
temp++;
replacement = malloc(_strlen(temp) + 1);
if (replacement)
_strcpy(replacement, temp);
}

return (replacement);
}

/**
 * variable_replacement -  this hsve to handles variable replacement.
 * @line: this is double pointer which contains the command and arguments.
 * @exe_ret: A pointer to return value of the last executed command.
 *
 * Description: this is the $$ with the current PID, $? with the return value
 */
void variable_replacement(char **line, int *exe_ret)
{
int j, k = 0, len;
char *replacement = NULL, *old_line = NULL, *new_line;

old_line = *line;
for (j = 0; old_line[j]; j++)
{
if (old_line[j] == '$' && old_line[j + 1] &&
old_line[j + 1] != ' ')
{
if (old_line[j + 1] == '$')
{
replacement = get_pid();
k = j + 2;
}
else if (old_line[j + 1] == '?')
{
replacement = _itoa(*exe_ret);
k = j + 2;
}
else if (old_line[j + 1])
{
/* extract the variable name to search for */
for (k = j + 1; old_line[k] &&
old_line[k] != '$' &&

old_line[k] != ' '; k++);
len = k - (j + 1);
replacement = get_env_value(&old_line[j + 1], len);
}
new_line = malloc(j + _strlen(replacement)
+ _strlen(&old_line[k]) + 1);
if (!line)
return;
new_line[0] = '\0';
_strncat(new_line, old_line, j);
if (replacement)
{
_strcat(new_line, replacement);
free(replacement);
replacement = NULL;
}
_strcat(new_line, &old_line[k]);
free(old_line);
*line = new_line;
old_line = new_line;
j = -1;
}
}
}

