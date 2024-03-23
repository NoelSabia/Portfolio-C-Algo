#include "../includes/C-Algo.h"

void	freeing(int **home_arr)
{
	int	i;

	i = -1;
	while (home_arr[++i])
		free(home_arr[i]);
	free(home_arr);
}