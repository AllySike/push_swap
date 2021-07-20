#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h>

typedef struct s_commands
{
    int         command;
    void        *next;
} t_commands;

typedef struct s_push_swap
{
	int *a;
	int *b;
	int a_size;
	int b_size;
	t_commands *commands;
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
void add_command(t_push_swap *arrays, int i);
void a_to_b(t_push_swap *arrays);
void b_to_a(t_push_swap *array);

#endif
