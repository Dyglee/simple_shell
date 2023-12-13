#include "shell.h"

/**
 * _memset - Fills memory with a constant byte.
 * @s: Pointer to the memory area.
 * @byte: The byte to fill the memory with.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area 's'.
 */
char *_memset(char *s, char byte, unsigned int n)
{
	/* Initialize loop counter */
	unsigned int i;

	/* Fill memory with 'byte' */
	for (i = 0; i < n; i++)
		s[i] = byte;

	return (s);
}

/**
 * ffree - Frees a string array and its contents.
 * @str_array: Pointer to a string array.
 */
void ffree(char **str_array)
{
	/* Create a copy of the pointer for freeing later */
	char **str_arr = str_array;

	/* Check if the pointer is valid */
	if (!str_array)
		return;

	/* Free each string and advance the pointer */
	while (*str_array)
		free(*str_array++);

	/* Free the original pointer */
	free(str_arr);
}

/**
 * _realloc - Reallocates a block of memory.
 * @ptr: Pointer to the previous malloc'ated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the reallocated block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/* Declare a new pointer */
	char *new_ptr;

	/* If 'ptr' is NULL, allocate a new block of 'new_size' bytes */
	if (!ptr)
		return (malloc(new_size));

	/* If 'new_size' is 0, free 'ptr' and return NULL */
	if (!new_size)
		return (free(ptr), NULL);

	/* If 'new_size' is the same as 'old_size', return 'ptr' as is */
	if (new_size == old_size)
		return (ptr);

	/* Allocate a new block of 'new_size' bytes */
	new_ptr = malloc(new_size);

	/* If allocation fails, return NULL */
	if (!new_ptr)
		return (NULL);

	/* Copy data from 'ptr' to 'new_ptr' */
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];

	/* Free the old block and return the new one */
	free(ptr);
	return (new_ptr);
}

