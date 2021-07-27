/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:31:04 by kgale             #+#    #+#             */
/*   Updated: 2021/07/27 23:31:07 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	rotate_a(t_push_swap *arrays, int flag)
{
	int	i;
	int	tmp;

	if (arrays->a_size > 1)
	{
		i = 0;
		tmp = arrays->a[i];
		while (i++ < arrays->a_size)
			arrays->a[i - 1] = arrays->a[i];
		arrays->a[arrays->a_size - 1] = tmp;
	}
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_push_swap *arrays, int flag)
{
	int	i;
	int	tmp;

	if (arrays->b_size > 1)
	{
		i = 0;
		tmp = arrays->b[i];
		while (i++ < arrays->b_size)
			arrays->b[i - 1] = arrays->b[i];
		arrays->b[arrays->b_size - 1] = tmp;
	}
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_push_swap *arrays)
{
	rotate_a(arrays, 0);
	rotate_b(arrays, 0);
	write(1, "rr\n", 3);
}

void	sort_a(t_push_swap *arrays)
{
	if (arrays->a_size > 2 && arrays->a[0] > arrays->a[2]
		&& arrays->a[1] < arrays->a[2])
		rotate_a(arrays, 1);
	else if (arrays->a_size > 2 && ((arrays->a[0] > arrays->a[1]
				&& arrays->a[1] > arrays->a[2]) || (arrays->a[0] > arrays->a[1]
				&& arrays->a[0] < arrays->a[2])))
		swap_a(arrays, 1);
	if (arrays->a_size > 2 && arrays->a[0] < arrays->a[1]
		&& arrays->a[1] > arrays->a[2])
		reverse_rotate_a(arrays, 1);
	if (arrays->a_size > 2 && arrays->a[0] > arrays->a[1]
		&& arrays->a[0] < arrays->a[2])
		swap_a(arrays, 1);
}
