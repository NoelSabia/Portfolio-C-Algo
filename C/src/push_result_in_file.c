#include "../includes/C-Algo.h"

void combine_and_resultfile(s_algo *algo, s_threadinfo *threadinfo)
{
	long long int	result_arr[algo->home_arr_len];
	long long int	i = 0;
	long long int	smallest = LLONG_MAX;

	// Combine the 2D array into a 1D sorted array
	while (i <= algo->home_arr_len)
	{
		smallest = LLONG_MAX;
		s_threadinfo *smallest_threadinfo = NULL;

		// Compare all arr in each threadinfo to find the smallest num
		s_threadinfo *current_threadinfo = threadinfo;
		while (current_threadinfo != NULL)
		{
			if (current_threadinfo->index < current_threadinfo->len && current_threadinfo->arr[current_threadinfo->index] < smallest)
			{
				smallest = current_threadinfo->arr[current_threadinfo->index];
				smallest_threadinfo = current_threadinfo;
			}
			current_threadinfo = current_threadinfo->next;
		}

		// Increment the index of the threadinfo that had the smallest num
		if (smallest_threadinfo != NULL && smallest_threadinfo->index < smallest_threadinfo->len)
				smallest_threadinfo->index++;

		//put the smallest num into the result_arr
		result_arr[i] = smallest;
		i++;
	}
	FILE *file = fopen("../textfiles/sorted_nums.txt", "w");
	if (file == NULL)
	{
		err_message("The sorted textfile couldnt be created. Do you have enough memory left?");
		return ;
	}
	for (i = 0; i < algo->home_arr_len; i++)
		fprintf(file, " %lld,", result_arr[i]);
	fclose(file);
}
