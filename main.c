/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:30:34 by kgale             #+#    #+#             */
/*   Updated: 2021/07/28 04:32:02 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	start_b(t_push_swap *arrays)
{
	push_b(arrays);
	push_b(arrays);
	push_b(arrays);
	if (arrays->b[0] < arrays->b[2] && arrays->b[1] > arrays->b[2])
		rotate_b(arrays, 1);
	else if ((arrays->b[0] < arrays->b[1] && arrays->b[1] < arrays->b[2])
		|| (arrays->b[0] < arrays->b[1] && arrays->b[0] > arrays->b[2]))
		swap_b(arrays, 1);
	if (arrays->b[0] > arrays->b[1] && arrays->b[1] < arrays->b[2])
		reverse_rotate_b(arrays, 1);
	if (arrays->b[0] < arrays->b[1] && arrays->b[0] > arrays->b[2])
		swap_b(arrays, 1);
}

static void	finish_sort(t_push_swap *arrays)
{
	int	min;
	int	i;
	int	index;

	min = arrays->a[0];
	index = 0;
	i = 0;
	while (i < arrays->a_size)
	{
		if (min > arrays->a[i])
		{
			min = arrays->a[i];
			index = i;
		}
		i++;
	}
	if (index * 2 > arrays->a_size)
	{
		index = arrays->a_size - index;
		while (index-- > 0)
			reverse_rotate_a(arrays, 1);
	}
	else
		while (index-- > 0)
			rotate_a(arrays, 1);
}

void	sort(t_push_swap *arrays)
{
	if (arrays->a_size > 3)
	{
		start_b(arrays);
		while (arrays->a_size > 3)
			a_to_b(arrays, 0);
	}
	sort_a(arrays);
	while (arrays->b_size > 0)
		b_to_a(arrays);
	if (arrays->a[0] > arrays->a[arrays->a_size - 1])
		finish_sort(arrays);
}

static void	push_swap(t_push_swap *arrays, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1] && i < arrays->a_size)
	{
		if (my_atoi(argv[i + 1], &(arrays->a[i])))
		{
			write(2, "Error: not int in stack\n", 24);
			return ;
		}
		j = i++ - 2;
		while (j >= 0)
		{
			if (arrays->a[j--] == arrays->a[i - 1])
			{
				write(2, "Error: duplicates in stack\n", 27);
				return ;
			}
		}
	}
	if (!check_sorted(arrays))
		sort(arrays);
	if (arrays->a)
		free(arrays->a);
}

int	main(int argc, char *argv[])
{
	t_push_swap	arrays;

	if (argc < 2)
	{
		write(2, "Error: few arguments\n", 22);
		return (0);
	}
	else if (argc == 2)
		arg_handler(&arrays, argv[1]);
	else
	{
		arrays.a = malloc(sizeof(int) * (argc - 1));
		arrays.b = malloc(sizeof(int) * (argc - 1));
		if (!arrays.a || !arrays.b)
		{
			write(2, "Error with malloc\n", 19);
			return (-1);
		}
		arrays.b_size = 0;
		arrays.a_size = argc - 1;
		push_swap(&arrays, argv);
		if (arrays.b)
			free(arrays.b);
	}
	return (0);
}
