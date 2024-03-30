#include "../includes/C-Algo.h"

long long int *merge(long long int *arr, size_t left, size_t middle, size_t right)
{
	int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
		{
            arr[k] = L[i];
            i++;
        }
        else
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
	{
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
	{
        arr[k] = R[j];
        j++;
        k++;
    }
	return (arr);
}

long long int *mergeSort(long long int *arr, size_t left, size_t right, size_t len)
{
	
	long long int *solved;
	size_t middle = left + (right - left) / 2;
	

	if (left < right)
	{
		mergeSort(arr, left, middle, len);
		mergeSort(arr, middle + 1, right, len);
		solved = merge(arr, left, middle, right);
	}
	if (left + right == len)
		return (solved);
	return (NULL);
}

void	*merge_sort_main(void *threadinfo)
{
	s_threadinfo	*thread = threadinfo;
	long long int	*arr = thread->arr;
	long long int	*solved;

	// printf("\n");
	// for (int j = 0; j < thread->len; j++)
	// 	printf("before[%d]: %lld\n", j, thread->arr[j]);
	// printf("\n");
	solved = mergeSort(arr, 0, thread->len, thread->len);
	// printf("\n");
	// for (int k = 0; k < thread->len; k++)
	// 	printf("solved[%d]: %lld\n", k, solved[k]);
	// printf("\n");
	return ((void *)solved);
}
