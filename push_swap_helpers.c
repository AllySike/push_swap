#include "includes/push_swap.h"

static void push_b_from_a(int ind_a, int ind_b, t_push_swap *arrays)
{
    int a;
    int b;

    a = ind_a;
    b = ind_b;
    if (ind_b * 2 < arrays->b_size && ind_a * 2 < arrays->a_size)
        while (ind_a && ind_b)
        {
            reverse_rotate_ab(arrays);
            ind_a--;
            ind_b--;
        }
    else if (ind_b * 2 >= arrays->b_size && ind_a * 2 >= arrays->a_size)
        while (ind_a && ind_b)
        {
            rotate_ab(arrays);
            ind_a--;
            ind_b--;
        }
    if (a * 2 > arrays->a_size)
        while (ind_a--)
            reverse_rotate_a(arrays);
    else
        while (ind_a--)
            rotate_a(arrays);
    if (b * 2 > arrays->b_size)
        while (ind_b--)
            reverse_rotate_b(arrays);
    else
        while (ind_b--)
            rotate_b(arrays);
    push_b(arrays);
}

void a_to_b(t_push_swap *arrays)
{
    int i;
    int j;
    int min;
    int ind_a;
    int ind_b;

    i = 0;
    min = 0;
    while (i < arrays->a_size)
    {
        j = 0;
        while (arrays->a[i] < arrays->b[j])
            j++;
        if (!min || (j * 2 < arrays->a_size && min > j + i + 1)
            || (j * 2 < arrays->a_size && min > j / 2 + i + 1))
        {
            min = j / 2 + i + 1;
            ind_a = i;
            ind_b = j;
        }
        i++;
    }
    push_b_from_a(ind_a, ind_b, arrays);
}

void b_to_a(t_push_swap *arrays)
{
    if (arrays->a_size > 3)
        while (arrays->b[0] < arrays->a[arrays->a_size - 1])
            reverse_rotate_a(arrays);
    push_a(arrays);
}