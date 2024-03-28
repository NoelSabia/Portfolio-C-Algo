#include "../includes/C-Algo.h"

long long int	*split_arr(long long int *dest, long long int *src, int start, int end)
{
	while (start <= end)
	{
		dest[start] = src[start];
		start++;
	}
	return (dest);
}

void	*merge_sort(void *array)
{
	s_threadinfo *threadinfo;
	float	middle;
	long long int *temp_arr1;
	long long int *temp_arr2;
	int		*solved_arr;

	if (threadinfo->len == 1)
		return ((void *)array);
	else
	{
		middle = (float)threadinfo->len / 2;
		float remainder = middle - (int)middle;
		if (remainder == 0.5)
		{
			middle += 0.5;
			temp_arr1 = split_arr(temp_arr1, array, 0, middle);
			temp_arr2 = split_arr(temp_arr2, array, middle + 1, threadinfo->len);
		}
		else
		{
			temp_arr1 = split_arr(temp_arr1, array, 0, middle);
			temp_arr2 = split_arr(temp_arr2, array, middle + 1, threadinfo->len);
		}
		long long int *left_arr = merge_sort((void *)temp_arr1);
		long long int *right_arr = merge_sort((void *)temp_arr2);
	}
	return ((void *)solved_arr);
}
