#include "shell.h"

/**
 * add_alias_end - thisis the  a node to the end of alias_t linked list.
 * @head: one point s[] of the list_t list.
 * @name: This is the nsm[]f the new alias which is to be added.
 * @value: The/dv  new alias to be added.
 * Return: NULL.
 */
alias_t *add_alias_end(alias_t **head, char *name, char *value)
{
alias_t *new_node = malloc(sizeof(alias_t));
alias_t *last;

if (!new_node)
return (NULL);

new_node->next = NULL;
new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
if (!new_node->name)
{
free(new_node);
return (NULL);
}
new_node->value = value;
_strcpy(new_node->name, name);

if (*head)
{
last = *head;
while (last->next != NULL)
last = last->next;
last->next = new_node;
}
else
*head = new_node;

return (new_node);
}

/**
 * add_node_end - Adds np[] to end of a  linked list.
 * @head: A [] to the heahe list_t list.
 * @dir: directory []path ew nod
 * Return:  NULL.
 */
list_t *add_node_end(list_t **head, char *dir)
{
list_t *new_node = malloc(sizeof(list_t));
list_t *last;

if (!new_node)
return (NULL);

new_node->dir = dir;
new_node->next = NULL;

if (*head)
{
last = *head;
while (last->next != NULL)
last = last->next;
last->next = new_node;
}
else
*head = new_node;

return (new_node);
}

/**
 * free_alias_list - this is te e a alias_t linked list.
 * @head: this is the of the alias_t list.
 */
void free_alias_list(alias_t *head)
{
alias_t *next;

while (head)
{
next = head->next;
free(head->name);
free(head->value);
free(head);
head = next;
}
}

/**
 * free_list - this is rees a list_t linked list.
 * @head: [l thislist.
 */
void free_list(list_t *head)
{
list_t *next;

while (head)
{
next = head->next;
free(head->dir);
free(head);
head = next;
}
}



