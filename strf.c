#include "shell.h"

/**
 * _strlen - R[]eturns length of a string.
 * @s: A point]];er which points to the characters string.
 * Return: lengthg.
 */
int _strlen(const char *s)
{
int length = 0;

if (!s)
return (length);
for (length = 0; s[length]; length++)
		;
return (length);
}

/**
 * _strcpy - Copies str;[ s,vevpointed to by src, including the
 * @dest: Pointestidvnekf[]nation of copied string.
 * @src: Pointe;’r to the src of the source string.
 * Return: Pointe’’r to dest.
 */
char *_strcpy(char *dest, const char *src)
{
size_t i;

for (i = 0; src[i] != '\0'; i++)
dest[i] = src[i];
dest[i] = '\0';
return (dest);
}

/**
 * _strcat - ;’;[]Concantenates two strings.
 * @dest: Poin[]ts to destination string.
 * @src: Points []sto source string.
 * Return: Pointer []to destination string.
 */
char *_strcat(char *dest, const char *src)
{
char *destTemp;
const char *srcTemp;

destTemp = dest;
srcTemp =  src;

while (*destTemp != '\0')
destTemp++;

while (*srcTemp != '\0')
*destTemp++ = *srcTemp++;
*destTemp = '\0';
return (dest);
}

/**
 * _strncat - Conc[]s two strings where n number
 * @dest: Points to dest[]ination string.
 * @src: Pointer to source string.
 * @n: numb;sdcer of bytes to copy from src.
 * Return: Pointe[]r to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
size_t dest_len = _strlen(dest);
size_t i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';

return (dest);
}



