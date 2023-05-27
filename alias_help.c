#include "shell.h"

/**
 * print_alias - print an alias str
 * @node: alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * unset_alias - ste alias to str
 * @info: param struct
 * @str: str alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, f;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	f = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias,
				node_starts_with(info->alias, str, -1)));
	*p = f;
	return (ret);
}

/**
 * set_alias - set alias to str
 * @info: param struct
 * @str: str alias
 *
 * Return: Always 0 on success, 1 on an error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
