#include "shell.h"

/**
 * _eputs - print input str
 * @str: the str to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_eputchar(str[n]);
		n++;
	}
}

/**
 * _eputchar - write the char f to stderr
 * @f: the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set approp.
 */
int _eputchar(char f)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(2, buf, n);
		n = 0;
	}
	if (f != BUF_FLUSH)
		buf[n++] = f;
	return (1);
}

/**
 * _putsmd - print integer str
 * @str: the str to be printed
 * @md: the file desc to write to
 *
 * Return: the number of chars put
 */
int _putsmd(char *str, int md)
{
	int n = 0;

	if (!str)
		return (0);
	while (*str)
	{
		n += _putmd(*str++, md);
	}
	return (n);
}

/**
 * _erratoi - convert string to integer
 * @g: the string to be converted
 * Return: 0 if no number in string, converted number otherwise
 * -1 on error
 */
int _erratoi(char *g)
{
	int n = 0;
	unsigned long int result = 0;

	if (*g == '+')
		g++;

	for (n = 0; g[n] != '\0'; n++)
	{
		if (g[n] >= '0' && g[n] <= '9')
		{
			result *= 10;
			result += (g[n] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - print error msg
 * @info: the param & return in struct
 * @estr: string containspecified error
 * Return: 0 if no numbes in string, converted number otherwise
 * -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
