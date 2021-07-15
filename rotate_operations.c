#include "includes/push_swap.h"

void rotate_a(t_push_swap *arrays)
{
	int i;
	int tmp;

	if (arrays->a_size > 1)
	{
		i = 0;
		tmp = arrays->a[i];
		while (i++ < arrays->a_size)
			arrays->a[i - 1] = arrays->a[i];
		arrays->a[arrays->a_size - 1] = tmp;
	}
}

void rotate_b(t_push_swap *arrays)
{
	int i;
	int tmp;

	if (arrays->b_size > 1)
	{
		i = 0;
		tmp = arrays->b[i];
		while (i++ < arrays->b_size)
			arrays->b[i - 1] = arrays->b[i];
		arrays->b[arrays->b_size - 1] = tmp;
	}
}

void rotate_ab(t_push_swap *arrays)
{
	rotate_a(arrays);
	rotate_b(arrays);
}