#include "main.h"

/**
  * whitcher - cmd's locator in the PATH
  * @cmd: the cmd cahr * cointainer
  * @env: linked list environment
  * Return: NULL or dir file is in
  */

char *whitcher(char *cmd, env_list_t **env)
{
	char *PATH = _getenv_list_value("PATH", env);
	char *PATH_COPY;
	static char buf[256];
	char **tokens;
	int i;

	if (!PATH)
		return (NULL);
	PATH_COPY = _strdup(PATH);
	tokens = get_tokens(PATH_COPY, ":");

	for (i = 0; tokens[i]; i++)
	{
		if (isin_dir(cmd, tokens[i]))
		{
			buf[0] = 0; /* empty buffer */
			_strcat(buf, tokens[i]);
			FREE(PATH_COPY);
			free(tokens);
			return (buf);
		}
	}
	FREE(PATH_COPY);
	free(tokens);
	return (NULL);
}
