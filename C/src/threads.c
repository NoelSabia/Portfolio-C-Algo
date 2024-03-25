#include "../includes/C-Algo.h"

long long int *arr_for_threads(s_algo *algo)
{
	static int start = 0;
	static int end = 0;
	static int	repetition = 1;
	int division = algo->home_arr_len / algo->threads;
	long long int *temp_arr;
	int i;

	if (start == 0)
		end = division;
	algo->division = division;
	temp_arr = malloc(sizeof(long long int) * (division + 1));
	i = 0;
	if (!temp_arr)
	{
		err_message("Allocation of an important array failed.");
		return NULL;
	}
	if (repetition < algo->threads)
	{
		while(start < end)
		{
			temp_arr[i] = *algo->home_arr[start];
			i++;
			start++;
		}
		end += division;
	}
	else
	{
		printf("start:%d\n", start);
		printf("home_arr_len: %d\n", algo->home_arr_len);
		while(start < algo->home_arr_len)
		{
			temp_arr[i] = *algo->home_arr[start];
			i++;
			start++;
		}
	}
	repetition++;
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
		for (int k = 0; k < algo->division; k++)
			printf("there: %lld\n", temp_arr[k]);
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
		printf("joined\n");
		if (result != 0)
		{
			err_message("Thread join failed!");
			return ;
		}
	}
}
