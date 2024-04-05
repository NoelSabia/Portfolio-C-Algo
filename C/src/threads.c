#include "../includes/C-Algo.h"

static int temp_arr_len;

long long int *arr_for_threads(s_algo *algo, int *start, int *end)
{
	static int	repetition = 1;
	int division = algo->home_arr_len / algo->threads;
	long long int *temp_arr;
	int i;

	if (*start == 0)
		*end = division;
	algo->division = division;
	temp_arr = malloc(sizeof(long long int) * (division + 10));
	i = 0;
	temp_arr_len = 0;
	if (!temp_arr)
	{
		err_message("Allocation of an important array failed.");
		return NULL;
	}
	if (repetition < algo->threads)
	{
		while(*start < *end)
		{
			temp_arr[i] = *(algo->home_arr[*start]);
			i++;
			(*start)++;
		}
		*end += division;
		temp_arr_len = division;
	}
	else
	{
		while(*start < algo->home_arr_len)
		{
			temp_arr[i] = *(algo->home_arr[*start]);
			i++;
			(*start)++;
		}
		temp_arr_len = algo->home_arr_len - (*start - i);
	}
	repetition++;
	return (temp_arr);
}

void put_into_2d_array(s_algo *algo, s_threadinfo *threadinfo, long long int *sorted_arr, int index)
{
	for (int i = 0; i <= threadinfo->len; i++)
		algo->home_arr[index][i] = sorted_arr[i];
}

void	threads(s_algo *algo, int threads)
{
	s_threadinfo	*prev_threadinfo = NULL;
	s_threadinfo	*begin = NULL;
	pthread_t		thread_id[threads];
	int				i;
	int				result;
	long long int	*temp_arr;
	int				start = 0;
	int				end = 0;


	for (i = 0; i < threads; i++)
	{
		//fill up the temp_arr in parts of the original arr for multitherading
		temp_arr = arr_for_threads(algo, &start, &end);

		//allocate memory
		s_threadinfo *threadinfo = malloc(sizeof(s_threadinfo));
		threadinfo->arr = malloc(sizeof(long long int) * temp_arr_len);
		if (!threadinfo || !threadinfo->arr)
		{
			err_message("Allocation of an important struct failed.");
			return ;
		}

		//initialize the struct and put the values in there
		memcpy(threadinfo->arr, temp_arr, sizeof(long long int) * temp_arr_len);
		threadinfo->len = temp_arr_len;
		threadinfo->index = 0;
		threadinfo->prev = prev_threadinfo;
		threadinfo->next = NULL;
		if (prev_threadinfo != NULL)
			prev_threadinfo->next = threadinfo;
		
		// Set begin to the first threadinfo
		if (begin == NULL)
			begin = threadinfo;

		//create threads with errorcheck
		result = pthread_create(&thread_id[i], NULL, merge_sort_main, (void *)threadinfo);
		if (result != 0)
		{
			err_message("Thread creation failed!");
			free(temp_arr);
			return ;
		}

		free(temp_arr);
		prev_threadinfo = threadinfo;

		if (i == threads - 1)
		{
			while (threadinfo->prev != NULL)
				threadinfo = threadinfo->prev;
			for (i = 0; i < threads; i++)
			{
				void *thread_result;
				result = pthread_join(thread_id[i], &thread_result); //TODO: thread_result has sometimes a zero which is wrong
				//the problem is that an empty array has a 0 stored in there and is used in the mergesort
				if (result != 0)
				{
					err_message("Thread join failed!");
					return ;
				}
				long long int *sorted_arr = (long long int *)thread_result;
				put_into_2d_array(algo, threadinfo, sorted_arr, i);
				threadinfo = threadinfo->next;
			}
			threadinfo = begin;
			while (threadinfo->prev != NULL)
				threadinfo = threadinfo->prev;
			combine_and_resultfile(algo, threadinfo);
		}

	}
}
