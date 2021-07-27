#include "includes/push_swap.h"

static void push_b_from_a(int ind_a, int ind_b, t_push_swap *arrays)
{
    int a;
    int b;

    a = ind_a;
    b = ind_b;
    if (ind_a * 2 > arrays->a_size)
        ind_a = arrays->a_size - ind_a;
    if (ind_b * 2 > arrays->b_size)
        ind_b = arrays->b_size - ind_b;
    if (b * 2 <= arrays->b_size && a * 2 <= arrays->a_size)
        while (ind_a && ind_b)
        {
            rotate_ab(arrays);
            ind_a--;
            ind_b--;
        }
    else if (b * 2 >= arrays->b_size && a * 2 >= arrays->a_size)
        while (ind_a && ind_b)
        {
            reverse_rotate_ab(arrays);
            ind_a--;
            ind_b--;
        }
    if (a * 2 > arrays->a_size)
        while (ind_a--)
            reverse_rotate_a(arrays, 1);
    else
        while (ind_a--)
            rotate_a(arrays, 1);
    if (b * 2 > arrays->b_size)
        while (ind_b--)
            reverse_rotate_b(arrays, 1);
    else
        while (ind_b--)
            rotate_b(arrays, 1);
    push_b(arrays);
}

static int find_min(int *array)
{
    int i;

    i = 0;
    while (array[i + 1] && array[i] > array[i + 1])
        i++;
    return (i + 1);
}

static int a_to_b_helper(int i, t_push_swap *arrays)
{
    int j;

    j = 0;
    if (arrays->b[0] > arrays->a[i])
    {
        j = 0;
        while (j < arrays->b_size && arrays->a[i] < arrays->b[j])
        {
            if (j < arrays->b_size - 1 && arrays->b[j] < arrays->b[j + 1])
                return (j + 1);
            j++;
        }
    }
    else
    {
        j = arrays->b_size - 1;
        while (j > 0 && arrays->a[i] > arrays->b[j])
        {
            if (j > 0 && arrays->b[j - 1] < arrays->b[j])
                return (j);
            j--;
        }
    }
    return (j);
}

int check_min(int i, int j, int a_size, int b_size)
{
    int ret;

    ret = 0;
    if (i * 2 <= a_size)
        ret += i;
    else
        ret += a_size - i;
    if (j * 2 <= b_size)
        ret += j;
    else
        ret += b_size - j;
    return (ret);
}

void a_to_b(t_push_swap *arrays)
{
    int i;
    int j;
    int min;
    int ind_a;
    int ind_b;
    int tmp;

    i = 0;
    min = 0;
    while (i < arrays->a_size)
    {
        j = a_to_b_helper(i, arrays);
        tmp = check_min(i, j, arrays->a_size, arrays->b_size);
        if (!min || min > tmp)
        {
            ind_a = i;
            ind_b = j;
            min = tmp;
        }
        i++;
    }
    push_b_from_a(ind_a, ind_b, arrays);
}

void b_to_a(t_push_swap *arrays)
{
    if (arrays->a_size > 3)
        while (arrays->b[0] < arrays->a[arrays->a_size - 1]
            && !(arrays->a[0] < arrays->a[arrays->a_size - 1]))
                reverse_rotate_a(arrays, 1);
    push_a(arrays);
}