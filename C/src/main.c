#include "../includes/C-Algo.h"

void	err_message(char *str)
{
	printf("An error has occurred!\n");
	printf("Error: %s\n", str);
}

int main(int argc, char *argv[])
{
	int				err;
	int				fd;
	int				i;
	char			*buffer;
	s_algo			*algo;

	if (argc < 2)
	{
		err_message("Wrong number of arguments.\nError: Need to know how many Threads are available.");
		return (0);
	}
	fd = open("../textfiles/nums.txt", O_RDONLY, 0644);
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

	algo = (s_algo *)malloc(sizeof(s_algo));
	if (parsing(algo, buffer) == FAILURE)
	{
		free(buffer);
		close(fd);
		free(algo->home_arr);
		exit(0);
	}
	algo->threads = atoll(argv[1]);
	if (algo->threads < 1)
		err_message("0 threads are not possible please take a number higher or equal to 1");
	else
		threads(algo, algo->threads);
	free(buffer);
	close(fd);
	free(algo->home_arr);
	return (0);
}
