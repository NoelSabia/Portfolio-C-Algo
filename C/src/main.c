#include "../includes/C-Algo.h"

void	err_message(char *str)
{
	printf("An error has occurred!\n");
	printf("Error: %s\n", str);
}

int main()
{
	int		err;
	int		fd;
	int		i;
	char	*buffer;
	s_algo	algo;

	fd = open("/workspaces/C-Algo/textfiles/nums.txt", O_RDONLY);
	if (fd == -1)
	{
		err_message("Failed to open the File.");
		return (0);
	}
	buffer = (char *)malloc(2);
	i = -1;
	while ((err = read(fd, &buffer[++i], 1)) != 0)
	{
		buffer = realloc(buffer, 1);
		if (err == -1)
		{
			err_message("The function read() failed.");
			close(fd);
			break ;
		}
	}
	buffer[i] = '\0';
	parsing(&algo, buffer); //TODO: Check if the fd is always closed if exited
	free(buffer);
	close(fd);
	return (0);
}