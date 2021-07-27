#include "includes/push_swap.h"

static int	b_to_a_helper(t_push_swap *arrays)
{
	int	j;

	if (arrays->a[0] < arrays->a[arrays->a_size - 1]
		|| (arrays->a[arrays->a_size - 1]
			< arrays->a[0] && arrays->a[0] < arrays->b[0]))
	{
		j = 0;
		while (j < arrays->a_size && arrays->b[0] > arrays->a[j])
			if (j++ < arrays->a_size - 1 && arrays->a[j - 1] > arrays->a[j])
				return (j);
	}
	else
	{
		j = arrays->a_size - 1;
		while (j > 0 && arrays->b[0] < arrays->a[j])
			if (j-- > 0 && arrays->a[j] > arrays->a[j + 1])
				return (j + 1);
		if (j++ > arrays->a_size - 1)
			j = 0;
	}
	return (j);
}

void	b_to_a(t_push_swap *arrays)
{
	int	i;

	i = b_to_a_helper(arrays);
	if (i * 2 > arrays->a_size)
	{
		i = arrays->a_size - i;
		while (i--)
			reverse_rotate_a(arrays, 1);
	}
	else
		while (i--)
			rotate_a(arrays, 1);
	push_a(arrays);
}
