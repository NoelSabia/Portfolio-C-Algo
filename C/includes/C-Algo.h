#ifndef ALGO_H
#define ALGO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <stdbool.h>
# include <pthread.h>

// Structs
typedef struct t_algo
{
	long long int		**home_arr;
	int					home_arr_len;
	int					fd;
	int					threads;
	int					division;
}	s_algo;



//Functions
void	err_message(char *str);
void	parsing(s_algo *algo, char *buffer);
void	*merge_sort(void *array);
void	threads(s_algo *algo, int threads);
void	freeing(s_algo *algo);

#endif