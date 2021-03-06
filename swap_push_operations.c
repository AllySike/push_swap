/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:31:08 by kgale             #+#    #+#             */
/*   Updated: 2021/07/27 23:31:09 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_a(t_push_swap *array, int flag)
{
	int	tmp;

	if (array->a_size > 1)
	{
		tmp = array->a[0];
		array->a[0] = array->a[1];
		array->a[1] = tmp;
	}
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_b(t_push_swap *array, int flag)
{
	int	tmp;

	if (array->b_size > 1)
	{
		tmp = array->b[0];
		array->b[0] = array->b[1];
		array->b[1] = tmp;
	}
	if (flag)
		write(1, "sb\n", 3);
}

void	swap_ab(t_push_swap *array)
{
	swap_a(array, 0);
	swap_b(array, 0);
	write(1, "ss\n", 3);
}

void	push_a(t_push_swap *arrays)
{
	int	i;

	if (arrays->b_size > 0)
	{
		i = arrays->a_size;
		while (i-- > 0)
			arrays->a[i + 1] = arrays->a[i];
		i = 0;
		arrays->a[i] = arrays->b[i];
		while (i++ < arrays->b_size)
			arrays->b[i - 1] = arrays->b[i];
		arrays->b_size--;
		arrays->a_size++;
	}
	write(1, "pa\n", 3);
}

void	push_b(t_push_swap *arrays)
{
	int	i;

	if (arrays->a_size > 0)
	{
		i = arrays->b_size;
		while (i-- > 0)
			arrays->b[i + 1] = arrays->b[i];
		i = 0;
		arrays->b[i] = arrays->a[i];
		while (i++ < arrays->a_size)
			arrays->a[i - 1] = arrays->a[i];
		arrays->a_size--;
		arrays->b_size++;
	}
	write(1, "pb\n", 3);
}
