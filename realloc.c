#include "shell.h"

/**
 * *_memset - fills memory with bytes
 * @s: pointer to memory
 * @b: bytes to fill s
 * @n: amount of bytes to be filled
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees string
 * @pp: sting of the strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free (*pp++);
	free(a);
}

/**
 * _realloc - reallocates block of memory
 * @ptr: pointer to previous malloc block
 * @old_size: bytes of prev block
 * @new_size: bytes of new block
 * Return: pointer of old block of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
