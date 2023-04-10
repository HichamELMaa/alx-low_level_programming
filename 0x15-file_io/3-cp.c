#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, otherwise error codes:
 * 97 - incorrect number of arguments
 * 98 - unable to read from file_from
 * 99 - unable to write to file_to or unable to close file descriptor
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t nread;
	char buffer[BUFFER_SIZE];
	struct stat st;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (fstat(fd_from, &st) == -1)
	{
		perror("fstat");
		exit(99);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & 0666);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((nread = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_to, buffer, nread) != nread)
		{
			perror("write");
			exit(99);
		}
	}

	if (nread == -1)
	{
		perror("read");
		exit(98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		perror("close");
		exit(100);
	}

	return (0);
}

