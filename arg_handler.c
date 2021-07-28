#include "includes/push_swap.h"

static int	count_size(char *arg)
{
	int	i;
	int	size;
	int	flag;

	i = 0;
	flag = 0;
	size = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] != ' ')
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			size++;
		}
		i++;
	}
	if (flag == 1)
		size++;
	return (size);
}

static int	arg_push_swap(t_push_swap *arrays, char *arg)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (arg[i] && k < arrays->a_size)
	{
		if (my_atoi_arg(arg, &i, &(arrays->a[k])))
		{
			write(2, "Error: not int in stack\n", 24);
			return (1);
		}
		j = k++ - 2;
		while (j >= 0)
		{
			if (arrays->a[j--] == arrays->a[k - 1])
			{
				write(2, "Error: duplicates in stack\n", 27);
				return (1);
			}
		}
	}
	return (0);
}

void	arg_handler(t_push_swap *arrays, char *arg)
{
	int	size;

	size = count_size(arg);
	arrays->a = malloc(sizeof(int) * size);
	arrays->b = malloc(sizeof(int) * size);
	if (!arrays->a || !arrays->b)
	{
		write(2, "Error with malloc\n", 19);
		return ;
	}
	if (size < 2)
	{
		write(2, "Error: need more args\n", 22);
		return ;
	}
	arrays->a_size = size;
	arrays->b_size = 0;
	if (!arg_push_swap(arrays, arg) && !check_sorted(arrays))
		sort(arrays);
	if (arrays->a)
		free(arrays->a);
	if (arrays->b)
		free(arrays->b);
}
