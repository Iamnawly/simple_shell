#include "shell.h"

/**
 * get_location - ‘ uw locationd in the PATH.
 * @command: this is the command to locate.
 * Return: - NULL.
 */
char *get_location(char *command)
{
char **path, *temp;
list_t *dirs, *head;
struct stat st;

path = _getenv("PATH");
if (!path || !(*path))
return (NULL);

dirs = get_path_dir(*path + 5);
head = dirs;

while (dirs)
{
temp = malloc(_strlen(dirs->dir) + _strlen(command) + 2);
if (!temp)
return (NULL);

_strcpy(temp, dirs->dir);
_strcat(temp, "/");
_strcat(temp, command);

if (stat(temp, &st) == 0)
		{
free_list(head);
return (temp);
}

dirs = dirs->next;
free(temp);
}

free_list(head);

return (NULL);
}

/**
 * fill_path_dir - path  copies but also’;es leading/sandwiched/trailing
 * @path: This is the one o fn eparated full list of directories.
 * Return: li ny show sy leading/sandwiched/trailing colons replaced
 */
char *fill_path_dir(char *path)
{
int i, length = 0;
char *path_copy, *pwd;

pwd = *(_getenv("PWD")) + 4;
for (i = 0; path[i]; i++)
{
if (path[i] == ':')
{
if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
length += _strlen(pwd) + 1;
else
length++;
}
else
length++;
}
path_copy = malloc(sizeof(char) * (length + 1));
if (!path_copy)
return (NULL);
path_copy[0] = '\0';
for (i = 0; path[i]; i++)
{
if (path[i] == ':')
		{
if (i == 0)
{
_strcat(path_copy, pwd);
_strcat(path_copy, ":");
}
else if (path[i + 1] == ':' || path[i + 1] == '\0')
{
_strcat(path_copy, ":");
_strcat(path_copy, pwd);
}
else
_strcat(path_copy, ":");
}
else
{
_strncat(path_copy, &path[i], 1);
}
}
return (path_copy);
}

/**
 * get_path_dir - this defines and tokenizes a colon-separated list of
 * @path: The one-separated list of directories.
 * Return: this is the initialized linked list.
 */
list_t *get_path_dir(char *path)
{
int index;
char **dirs, *path_copy;
list_t *head = NULL;

path_copy = fill_path_dir(path);
if (!path_copy)
return (NULL);
dirs = _strtok(path_copy, ":");
free(path_copy);
if (!dirs)
return (NULL);

for (index = 0; dirs[index]; index++)
{
if (add_node_end(&head, dirs[index]) == NULL)
{
free_list(head);
free(dirs);
return (NULL);
}
}

free(dirs);

return (head);
}


