#include "../includes/C-Algo.h"

const int	divison = algo->home_arr_len / threads;
static int	start = 0;

int	*arr_for_threads(int thread)
{
	int		*temp_arr;
	t_algo	*algo;

	temp_arr = malloc(sizeof(long long int) * division + 1);
	// while(algo->)
}

void	threads(int threads)
{
	pthread_t		thread_id[threads];
	int				i;
	int				result;
	long long int	*temp_arr;

	for (i = 0; i < threads; i++)
	{
		temp_arr = arr_for_threads(threads);
		result = pthread_create(&thread_id[i], NULL, merge_sort, (void *)temp_arr);
		if (result != 0)
		{
			err_message("Thread creation failed!");
			free(temp_arr);
			return ;
		}
		free(temp_arr);
	}
	for (i = 0; i < threads; i++)
	{
		result = pthread_join(&thread_id[i], NULL);
		if (result != 0)
		{
			err_message("Thread join failed!");
			return ;
		}
	}
}
