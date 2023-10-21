#include "main.h"

/**
 * _realloc - realloc(ates) old ptr to new
 * @ptr: old 1
 * @old_size: old(ancient) size of pointer
 * @new_size: new(modern) size of pointer
 * Return: void *
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *babypointer;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	babypointer = malloc(sizeof(char) * new_size);
	if (babypointer == NULL)
		return (NULL);
	if (ptr)
	{
		for (i = 0; i < old_size; i++)
		{
			babypointer[i] = *((char *)ptr + i);
		}
	}
	free(ptr);
	return (babypointer);
}

/**
 *_atoi - a str to an integer converter
 *@s: the str to be converted
 *Return: zero if no numbers in str, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * _strlen - string character counter
 * @str: a string pointer
 *
 * Return: number of characters in the string
 */

int _strlen(char *str)
{
	int count = 0;

	while (*(str + count))
		count++;

	return (count);
}

/**
 * _strdup - memory allocates new str and copy *str into it
 * @str: the copied string
 * Return: new string ptr
 */
char *_strdup(char *str)
{
	unsigned int i;
	int count = 0;
	char *dest;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		count++;
	}
	count += 1;
	dest = malloc(count * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}
	dest[i] = str[i];
	return (dest);
}

/**
  * _strcmp - a fxn to compare two strings
  * @s1: the 1st string
  * @s2: the 2nd string
  *
  * Return: int
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
		break;
	}
	return (*s1 - *s2);
}
