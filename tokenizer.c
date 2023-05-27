#include "shell.h"

/**
 * **strtow - splits into words. Repeats are omited
 * @str: string input
 * @d: string delim
 * Return: an array of strings, or NULL on error
 */

char **strtow(char *str, char *d)
{
int x, y, k, m, nbwds = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (x = 0; str[x] != '\0'; x++)
if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
nbwds++;

if (nbwds == 0)
return (NULL);
s = malloc((1 + nbwds) *sizeof(char *));
if (!s)
return (NULL);
for (x = 0, y = 0; y < nbwds; y++)
{
while (is_delim(str[x], d))
x++;
k = 0;
while (!is_delim(str[x + k], d) && str[x + k])
k++;
s[y] = malloc((k + 1) * sizeof(char));
if (!s[y])
{
for (k = 0; k < y; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[y][m] = str[x++];
s[y][m] = 0;
}
s[y] = NULL;
return (s);
}

/**
* **strtow2 - split into words
* @str: the input string
* @d: delimeter
* Return: array of strings, or NULL on error
*/
char **strtow2(char *str, char d)
{
int x, y, k, m, nbwds = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (x = 0; str[x] != '\0'; x++)
if ((str[x] != d && str[x + 1] == d) ||
(str[x] != d && !str[x + 1]) || str[x + 1] == d)
nbwds++;
if (nbwds == 0)
return (NULL);
s = malloc((1 + nbwds) *sizeof(char *));
if (!s)
return (NULL);
for (x = 0, y = 0; y < nbwds; y++)
{
while (str[x] == d && str[x] != d)
x++;
k = 0;
while (str[x + k] != d && str[x + k] && str[x + k] != d)
k++;
s[y] = malloc((k + 1) * sizeof(char));
if (!s[y])
{
for (k = 0; k < y; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[y][m] = str[x++];
s[y][m] = 0;
}
s[y] = NULL;
return (s);
}
