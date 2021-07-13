#include "includes/push_swap.h"

void swap_a(t_push_swap *array)
{
	int tmp;

	if (array->a_size > 1)
	{
		tmp = array->a[0];
		array->a[0] = array->a[1];
		array->a[1] = tmp;
	}
}

void swap_b(t_push_swap *array)
{
	int tmp;

	if (array->b_size > 1)
	{
		tmp = array->b[0];
		array->b[0] = array->b[1];
		array->b[1] = tmp;
	}
}

void swap_ab(t_push_swap *array)
{
	swap_a(array);
	swap_b(array);
}

void push_a(t_push_swap *array)
{
	int i;

	if (array->b_size > 0)
	{
		i = array->a_size - 1;
		while (i >= 0)
			array->a[i] = array->a[--i];
		array->a[i] = array->b[i];
		while (i < array->b_size)
			array->b[i] = array->b[++i];
		array->b_size--;
		array->a_size++;
	}
}

void push_b(t_push_swap *arrays)
{
	int i;

	if (arrays->a_size > 0)
	{
		i = arrays->b_size - 1;
		if (i < 0)
			i = 0;
		while (i > 0)
			arrays->b[i] = arrays->b[--i];
		arrays->b[i] = arrays->a[i];
		while (i < arrays->a_size)
			arrays->a[i] = arrays->a[++i];
		arrays->a_size--;
		arrays->b_size++;
	}
}