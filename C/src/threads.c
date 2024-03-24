#include "../includes/C-Algo.h"

long long int	*arr_for_threads(s_algo *algo)
{
	int		division = algo->home_arr_len / algo->threads;
	static int		start = 0;
	printf("start: %d\n", start);
	static int		end;
	long long int	*temp_arr;
	int				i;

	i = 0;
	end = division;
	printf("end: %d\n", end);
	algo->division = division;
	temp_arr = malloc(sizeof(long long int) * division + 1);
	if (!temp_arr)
	{
		err_message("Allocation of an important array failed.");
		return (NULL);
	}
	while(start <= division)
	{
		printf("start: %d\n", start);
		temp_arr[i] = *algo->home_arr[start];
		// printf("home_arr: %lld\n", *algo->home_arr[start]);
		i++;
		start++;
	}
	start += division;
	end += division;
	return (temp_arr);
}

void	threads(s_algo *algo, int threads)
{
	pthread_t		thread_id[threads];
	int				i;
	int				result;
	long long int	*temp_arr;

	for (i = 0; i < threads; i++)
	{
		temp_arr = arr_for_threads(algo);
		// for (int k = 0; k < algo->division - 1; k++)
		// 	printf("there: %lld\n", temp_arr[k]);
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
		result = pthread_join(thread_id[i], NULL);
		if (result != 0)
		{
			err_message("Thread join failed!");
			return ;
		}
	}
}
