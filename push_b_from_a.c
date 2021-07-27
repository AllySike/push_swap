/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_from_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:30:56 by kgale             #+#    #+#             */
/*   Updated: 2021/07/27 23:30:57 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	push_b_from_a_helper1(int a, int *ind_a, t_push_swap *arrays)
{
	if (a * 2 > arrays->a_size)
		while (ind_a[0]-- > 0)
			reverse_rotate_a(arrays, 1);
	else
		while (ind_a[0]-- > 0)
			rotate_a(arrays, 1);
}

static void	push_b_from_a_helper2(int b, int *ind_b, t_push_swap *arrays)
{
	if (b * 2 > arrays->b_size)
		while (ind_b[0]-- > 0)
			reverse_rotate_b(arrays, 1);
	else
		while (ind_b[0]-- > 0)
			rotate_b(arrays, 1);
}

static void	rotate_both(int *ind_a, int *ind_b, t_push_swap *arrays)
{
	while (*ind_a && *ind_b)
	{
		rotate_ab(arrays);
		ind_a[0]--;
		ind_b[0]--;
	}
}

static void	reverse_rotate_both(int *ind_a, int *ind_b, t_push_swap *arrays)
{
	while (*ind_a && *ind_b)
	{
		reverse_rotate_ab(arrays);
		ind_a[0]--;
		ind_b[0]--;
	}
}

void	push_b_from_a(int ind_a, int ind_b, t_push_swap *arrays)
{
	int	a;
	int	b;

	a = ind_a;
	b = ind_b;
	if (ind_a * 2 > arrays->a_size)
		ind_a = arrays->a_size - ind_a;
	if (ind_b * 2 > arrays->b_size)
		ind_b = arrays->b_size - ind_b;
	if (b * 2 < arrays->b_size && a * 2 < arrays->a_size)
		rotate_both(&ind_a, &ind_b, arrays);
	else if (b * 2 > arrays->b_size && a * 2 > arrays->a_size)
		reverse_rotate_both(&ind_a, &ind_b, arrays);
	push_b_from_a_helper1(a, &ind_a, arrays);
	push_b_from_a_helper2(b, &ind_b, arrays);
	push_b(arrays);
}
