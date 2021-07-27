#include "includes/push_swap.h"

void	reverse_rotate_a(t_push_swap *arrays, int flag)
{
	int	i;
	int	tmp;

	if (arrays->a_size > 1)
	{
		i = arrays->a_size;
		tmp = arrays->a[arrays->a_size - 1];
		while (--i > 0)
			arrays->a[i] = arrays->a[i - 1];
		arrays->a[0] = tmp;
	}
	if (flag)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_push_swap *arrays, int flag)
{
	int	i;
	int	tmp;

	if (arrays->b_size > 1)
	{
		i = arrays->b_size;
		tmp = arrays->b[arrays->b_size - 1];
		while (--i > 0)
			arrays->b[i] = arrays->b[i - 1];
		arrays->b[0] = tmp;
	}
	if (flag)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_push_swap *arrays)
{
	reverse_rotate_a(arrays, 0);
	reverse_rotate_b(arrays, 0);
	write(1, "rrr\n", 4);
}
