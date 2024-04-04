#include "../includes/C-Algo.h"

void combine_and_resultfile(s_algo *algo, s_threadinfo *threadinfo)
{
	long long int	result_arr[algo->home_arr_len];
	long long int	i = 0;
	long long int	smallest = LLONG_MAX;
	s_threadinfo	*thread = threadinfo;

	// Go back to the start of the list
	while (thread->prev != NULL)
		thread = thread->prev;
	// Combine the 2D array into a 1D sorted array
	while (i < algo->home_arr_len)
	{
		threadinfo = thread;
		smallest = LLONG_MAX;

		// Compare all arr in each threadinfo to find the smallest num
		while (threadinfo != NULL)
		{
			if (threadinfo->index < threadinfo->len && threadinfo->arr[threadinfo->index] < smallest)
			{
				smallest = threadinfo->arr[threadinfo->index];
				threadinfo->index++;
			}
			threadinfo = threadinfo->next;
		}
		result_arr[i] = smallest;
		i++;
	}
	FILE *file = fopen("sorted.txt", "w");
	if (file == NULL)
	{
		err_message("The sorted textfile couldnt be created. Do you have enough memory left?");
		return ;
	}
	for (i = 0; i <= algo->home_arr_len; i++)
		fprintf(file, " %lld,", result_arr[i]);
	fclose(file);
}
