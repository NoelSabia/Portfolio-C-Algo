#include "../includes/C-Algo.h"

void	threads(int threads)
{
	pthread_t	thread_id[threads];
	int			i;
	int			result;

	for (i = 0; i < threads; i++)
	{
		result = pthread_create(&thread_id[i], NULL, merge_sort(temp_arr), &i);
		if (result != 0)
		{
			err_message("Thread creation failed!");
			return ;
		}
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
