#include "shell.h"

/**
 * _strchr - []es a character in a string.
 * @s: searched for.
 * @c: The[]cter to be located.
 * Return: If is[] found - a pointer to the first occurence.
 */
char *_strchr(char *s, char c)
{
int index;

for (index = 0; s[index]; index++)
{
if (s[index] == c)
return (s + index);
}

return (NULL);
}

/**
 * _strspn - []the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: []fix to be measured.
 * Return: []number of bytes in s which
 */
int _strspn(char *s, char *accept)
{
int bytes = 0;
int index;

while (*s)
{
for (index = 0; accept[index]; index++)
{
if (*s == accept[index])
{
bytes++;
break;
}
}
s++;
}
return (bytes);
}

/**
 * _strcmp - ompares two strings.
 * @s1: []to be compared.
 * @s2: The sec[]ond strin.
 * Return: Positive byt[]ference
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}

if (*s1 != *s2)
return (*s1 - *s2);

return (0);
}

/**
 * _strncmp - []compare  strings.
 * @s1: a string.
 * @s2: string.
 * @n: ‘[[ n u98y0t n bytes of the strings to be compared.
 * Return:  s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;

for (i = 0; s1[i] && s2[i] && i < n; i++)
{
if (s1[i] > s2[i])
return (s1[i] - s2[i]);
else if (s1[i] < s2[i])
return (s1[i] - s2[i]);
}
if (i == n)
return (0);
else
return (-15);
}



