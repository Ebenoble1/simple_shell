#include "main.h"

/**
  * double_free - free's char * arrays
  * @argv: vector arguement
  */
void double_free(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
