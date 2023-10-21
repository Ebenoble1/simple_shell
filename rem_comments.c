#include "main.h"

/**
  * rem_comments - deletes comments from a string
  * @str: proposed string for surgery
  */
void rem_comments(char *str)
{
	char *del = _strchr(str, '#');

	if (del)
		*del = '\0';
}
