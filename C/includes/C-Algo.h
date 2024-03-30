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

//defines
#define SUCCESS 1
#define FAILURE 0

// Structs
typedef struct t_algo
{
	long long int		**home_arr;
	int					home_arr_len;
	int					fd;
	int					threads;
	int					division;
}	s_algo;

typedef struct t_threadinfo
{
	long long int	*arr;
	long long int	len;
}	s_threadinfo;



//Functions
void	err_message(char *str);
int		parsing(s_algo *algo, char *buffer);
void	*merge_sort_main(void *threadinfo);
void	threads(s_algo *algo, int threads);
void	freeing(s_algo *algo);

#endif