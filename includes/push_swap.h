#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h>

typedef struct s_push_swap
{
	int *a;
	int *b;
	int a_size;
	int b_size;
} t_push_swap;

void swap_a(t_push_swap *array);
void swap_b(t_push_swap *array);
void swap_ab(t_push_swap *array);
void push_b(t_push_swap *array);
void push_a(t_push_swap *array);
void rotate_a(t_push_swap *array);
void rotate_b(t_push_swap *arrays);
void rotate_ab(t_push_swap *arrays);
void reverse_rotate_a(t_push_swap *arrays);
void reverse_rotate_b(t_push_swap *arrays);
void reverse_rotate_ab(t_push_swap *arrays);

#endif
