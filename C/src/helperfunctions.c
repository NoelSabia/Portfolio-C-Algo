#include "../includes/C-Algo.h"

void	freeing(s_algo *algo)
{
	int	i;

	i = -1;
	while (algo->home_arr[++i])
		free(algo->home_arr[i]);
	free(algo->home_arr);
}