#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * create_file - creates a file and writes text content to it
 *
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, count = 0, write_count;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[count])
			count++;
		write_count = write(fd, text_content, count);
		if (write_count != count)
			return (-1);
	}

	close(fd);
	return (1);
}
