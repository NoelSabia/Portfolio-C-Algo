#include "../includes/C-Algo.h"

static int	arr_position = 0;

void	put_into_home_arr(s_algo *algo, char *temp)
{
	long long int			num;

	num = atoi(temp);
	algo->home_arr[arr_position] = malloc(sizeof(num));
	algo->home_arr[arr_position++] = (long long int*)num;
}

void	parsing(s_algo *algo, char *buffer)
{
	int		i;
	int		j;
	int		wrong_sign;
	char	*temp;
	int		temp_size;

	i = 0;
	wrong_sign = 0;
	temp_size = 0;
	algo->home_arr = (long long int **)malloc(sizeof(long long int *) * 1 + 1);
	temp = (char *)malloc(sizeof(char) * 2);
	while (buffer[i] && buffer[i] == ' ')
		i++;
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
						return ;
					}
					temp = new_temp;
				}
			}
			temp[j] = '\0';
			put_into_home_arr(algo, temp);
		}
		else
		{
			wrong_sign += 1;
			break ;
		}
		i++;
	}
	algo->home_arr[arr_position] = NULL;
	if (wrong_sign >= 1)
	{
		err_message("Unallowed signs found. Stop process.\nError: Use format: <space><number><comma>");
		// free(temp);
		return ;
	}
	// free(temp); //TODO: idk irgendwie ein bisschen komisch, dass temp schon oben gefreed wird
}
