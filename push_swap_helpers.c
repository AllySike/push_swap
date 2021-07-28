/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:30:59 by kgale             #+#    #+#             */
/*   Updated: 2021/07/28 04:25:07 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	a_to_b_helper(int i, t_push_swap *arrays)
{
	int	j;

	if (arrays->b[0] > arrays->b[arrays->b_size - 1] || (arrays->b[0]
			< arrays->b[arrays->b_size - 1] && arrays->b[0] > arrays->a[i]))
	{
		j = 0;
		while (j < arrays->b_size && arrays->a[i] < arrays->b[j])
			if (j++ < arrays->b_size - 1 && arrays->b[j - 1] < arrays->b[j])
				return (j);
	}
	else
	{
		j = arrays->b_size - 1;
		while (j > 0 && arrays->a[i] > arrays->b[j])
			if (j-- > 0 && arrays->b[j] < arrays->b[j + 1])
				return (j + 1);
		if (j++ > arrays->b_size - 1)
			j = 0;
	}
	return (j);
}

int	check_min(int i, int j, t_push_swap *arrays)
{
	int	ret;

	ret = 0;
	if (i * 2 <= arrays->a_size)
		ret += i;
	else
		ret += arrays->a_size - i;
	if (j * 2 <= arrays->b_size)
		ret += j;
	else
		ret += arrays->b_size - j;
	return (ret);
}

void	a_to_b(t_push_swap *arrays, int i)
{
	int	j;
	int	min;
	int	ind_a;
	int	ind_b;
	int	tmp;

	min = 0;
	while (i < arrays->a_size)
	{
		j = a_to_b_helper(i, arrays);
		tmp = check_min(i, j, arrays);
		if (!min || min > tmp)
		{
			ind_a = i;
			ind_b = j;
			min = tmp;
		}
		i++;
	}
	push_b_from_a(ind_a, ind_b, arrays);
}

int	check_sorted(t_push_swap *arrays)
{
	int	d;

	d = 0;
	while (d < arrays->a_size)
	{
		if (d > 0 && arrays->a[d - 1] > arrays->a[d])
			return (0);
		d++;
	}
	return (1);
}
