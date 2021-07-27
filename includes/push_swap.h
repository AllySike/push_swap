#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct s_push_swap
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
}	t_push_swap;

void	swap_a(t_push_swap *array, int flag);
void	swap_b(t_push_swap *array, int flag);
void	swap_ab(t_push_swap *array);
void	push_b(t_push_swap *array);
void	push_a(t_push_swap *array);
void	rotate_a(t_push_swap *array, int flag);
void	rotate_b(t_push_swap *arrays, int flag);
void	rotate_ab(t_push_swap *arrays);
void	reverse_rotate_a(t_push_swap *arrays, int flag);
void	reverse_rotate_b(t_push_swap *arrays, int flag);
void	reverse_rotate_ab(t_push_swap *arrays);
void	a_to_b(t_push_swap *arrays, int i);
void	b_to_a(t_push_swap *array);
void	push_b_from_a(int ind_a, int ind_b, t_push_swap *arrays);

#endif
