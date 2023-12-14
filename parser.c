#include "shell.h"

/**
 * is_cmd determines if a file is an executable
 * @info: argument structure
 * @path: path to files
 * Return: 1 or 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat str;

	(void)info;
	if (!path || stat(path, &str))
		return (0);

	if (str.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - dupliactes character
 * @pathstr: path of string
 * @start: beginning of the index
 * @stop: stopping index
 * Return: pointer to the newly assgined buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0;
	int k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++]= pathstr[i];

	buf[k] = 0;
	return (buf);
}
/**
 * find_path - finds cmd in path
 * @info: argument structure
 * @pathstr: path string
 * @cmd: cmd to find
 * Return: path to cmd
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0;
	int current_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, current_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			current_pos = i;
		}
		i++;
	}
	return (NULL);
}
