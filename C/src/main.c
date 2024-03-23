#include "../includes/C-Algo.h"

void	err_message(char *str)
{
	printf("An error has occurred!\n");
	printf("Error: %s\n", str);
}

int main(int argc, char *argv[])
{
	int		err;
	int		fd;
	int		i;
	char	*buffer;
	s_algo	*algo;

	if (argc < 1)
	{
		err_message("Wrong number of arguments.");
		return (0);
	}
	fd = open("/workspaces/C-Algo/textfiles/nums.txt", O_RDONLY);
	if (fd == -1)
	{
		err_message("Failed to open the File.");
		return (0);
	}

	buffer = (char *)malloc(2);
	if (!buffer)
	{
		err_message("Buffer allocation failed.");
		close(fd);
		return (0);
	}

	i = -1;
	while ((err = read(fd, &buffer[++i], 1)) != 0)
	{
		buffer = realloc(buffer, i + 2);
		if (err == -1)
		{
			err_message("The function read() failed.");
			close(fd);
			break ;
		}
	}
	buffer[i] = '\0';

	printf("buffer: %s\n", buffer);
	algo = (s_algo *)malloc(sizeof(s_algo));
	parsing(algo, buffer); //TODO: Check if the fd is always closed if exited
	
	free(buffer);
	close(fd);
	return (0);
}
