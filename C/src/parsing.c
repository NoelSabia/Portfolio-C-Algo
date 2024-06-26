#include "../includes/C-Algo.h"
#include <string.h>

static int	arr_position = 0;

void	put_into_home_arr(s_algo *algo, char *temp)
{
	long long int num = atoll(temp);
	algo->home_arr[arr_position] = malloc(sizeof(long long int));
	if (algo->home_arr[arr_position] == NULL)
	{
		err_message("An allocation of an array failed. Check your available storage.");
		return;
	}
	*algo->home_arr[arr_position] = num;
	arr_position++;
}

int	parsing(s_algo *algo, char *buffer)
{
	int		i;
	int		j;
	int		wrong_sign;
	char	*temp;
	int		temp_size;

	i = 0;
	wrong_sign = 0;
	temp_size = 0;
	algo->home_arr = malloc(sizeof(long long int *) * 100000);
	temp = (char *)malloc(sizeof(char) * 2);
	while (buffer[i])
	{
		if (buffer[i] == ' ')
		{
			i++;
			continue ;
		}
		else if ((buffer[i] >= '0' && buffer[i] <= '9') || (buffer[i] == '-' || buffer[i] == '+'))
		{
			j = 0;
			while (buffer[i] && (buffer[i] == '+' || buffer[i] == '-' || (buffer[i] >= '0' && buffer[i] <= '9')))
			{
				temp[j] = buffer[i];
				j++;
				i++;
				if (j + 1 > temp_size)
				{
					temp_size += 10;
					char *new_temp = realloc(temp, temp_size * sizeof(char));
					if (new_temp == NULL)
					{
						free(temp);
						return (FAILURE);
					}
					temp = new_temp;
					free(new_temp);
				}
			}
			temp[j] = '\0';
			put_into_home_arr(algo, temp);
		}
		else if (buffer[i] == '\n')
		{
			i++;
			continue ;
		}
		else
		{
			wrong_sign += 1;
			break ;
		}
		i++;
	}
	algo->home_arr_len = arr_position;
	if (wrong_sign >= 1)
	{
		printf("Error: Unallowed signs found:'%c'", buffer[i]);
		err_message("Use format: <space><number><comma> (comma also for the last number!)");
		return (FAILURE);
	}
	return (SUCCESS);
}
