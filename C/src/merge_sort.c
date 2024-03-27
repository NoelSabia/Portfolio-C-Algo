#include "../includes/C-Algo.h"

void	*merge_sort(void *array)
{
	s_threadinfo *threadinfo;
	float	middle;

	if (threadinfo->len == 1)
		return (threadinfo->arr);
	else
	{
		middle = (float)threadinfo->len / 2;
		float remainder = middle - (int)middle;
		if (remainder == 0.5)
		{
			middle += 0.5;
			char *temp_arr1 = memcpy(temp_arr1, threadinfo->arr, middle);
			char *temp_arr2 = memcpy(temp_arr2, threadinfo->arr, middle - 1); //TODO: not working like that would copy both the same part of arr
		}
		else
		{
			char *temp_arr1 = memcpy(temp_arr1, threadinfo->arr, middle);
			char *temp_arr2 = memcpy(temp_arr2, threadinfo->arr, middle - 1);	
		}
	}
	return NULL;
}
