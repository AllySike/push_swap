#include "includes/push_swap.h"

static void sort_a(t_push_swap *arrays)
{
    if (arrays->a[0] > arrays->a[2] && arrays->a[1] < arrays->a[2])
        rotate_a(arrays);
    else if ((arrays->a[0] > arrays->a[1] && arrays->a[1] > arrays->a[2])
             || (arrays->a[0] > arrays->a[1] && arrays->a[0] < arrays->a[2]))
        swap_a(arrays);
    if (arrays->a[0] < arrays->a[1] && arrays->a[1] > arrays->a[2])
        reverse_rotate_a(arrays);
    if (arrays->a[0] > arrays->a[1] && arrays->a[0] < arrays->a[2])
        swap_a(arrays);
}

static void start_b(t_push_swap *arrays)
{
    push_b(arrays);
    push_b(arrays);
    push_b(arrays);
    if (arrays->b[0] < arrays->b[2] && arrays->b[1] > arrays->b[2])
        rotate_b(arrays);
    else if ((arrays->b[0] < arrays->b[1] && arrays->b[1] < arrays->b[2])
        || (arrays->b[0] < arrays->b[1] && arrays->b[0] > arrays->b[2]))
        swap_b(arrays);
    if (arrays->b[0] > arrays->b[1] && arrays->b[1] < arrays->b[2])
        reverse_rotate_b(arrays);
    if (arrays->b[0] < arrays->b[1] && arrays->b[0] > arrays->b[2])
        swap_b(arrays);
}

static void finish_sort(t_push_swap * arrays)
{
    int min;
    int i;
    int index;


    min = arrays->a[0];
    index = 0;
    i = 0;
    while (i < arrays->a_size)
    {
        if (min > arrays->a[i])
        {
            min = arrays->a[i];
            index = i;
        }
        i++;
    }
    if (index * 2 > arrays->a_size)
        while (index-- > 0)
            rotate_a(arrays);
    else
        while (index++ < arrays->a_size)
            reverse_rotate_a(arrays);
}

static void sort(t_push_swap *arrays)
{
    if (arrays->a_size > 3)
        start_b(arrays);
    while (arrays->a_size > 3)
        a_to_b(arrays);
    sort_a(arrays);
    while (arrays->b_size > 0)
        b_to_a(arrays);
    finish_sort(arrays);
}

static void push_swap(t_push_swap *arrays, char *argv[])
{
	int i;

	i = 0;
	while (argv[i + 1] && i < arrays->a_size)
	{
		arrays->a[i] = atoi(argv[i + 1]);
		i++;
	}
	arrays->commands = NULL;

    sort(arrays);
    i = 0;
    printf("\na after:\n");
    while (i < arrays->a_size)
        printf("%i\n", arrays->a[i++]);
    i = 0;
    printf("\nb after:\n");
    while (i < arrays->b_size)
        printf("%i\n", arrays->b[i++]);

}

int main(int argc, char *argv[]) {
	t_push_swap arrays;

	if (argc < 2)
	{
		write(1, "Too few arguments\n", 18);
		return (0);
	}
	arrays.a = malloc(sizeof(int) * (argc - 1));
	arrays.b = malloc(sizeof(int) * (argc - 1));
	if (!arrays.a || !arrays.b)
	{
		write(1, "Error with malloc\n", 18);
		return (-1);
	}
	arrays.a_size = argc - 1;
	arrays.b_size = 0;
	push_swap(&arrays, argv);


//	int i = 0;
//	printf("a before:\n");
//	while (i < arrays.a_size)
//		printf("%i\n", arrays.a[i++]);
//	i = 0;
//	printf("\nb before:\n");
//	while (i < arrays.b_size)
//		printf("%i\n", arrays.b[i++]);
//
//	printf("\na after:\n");
//	i = 0;
//	while (i < arrays.a_size)
//		printf("%i\n", arrays.a[i++]);
//	i = 0;
//	printf("\nb after:\n");
//	while (i < arrays.b_size)
//		printf("%i\n", arrays.b[i++]);
//	reverse_rotate_ab(&arrays);
//	printf("\na after:\n");
//	i = 0;
//	while (i < arrays.a_size)
//		printf("%i\n", arrays.a[i++]);
//	i = 0;
//	printf("\nb after:\n");
//	while (i < arrays.b_size)
//		printf("%i\n", arrays.b[i++]);
	if (arrays.a)
		free(arrays.a);
	if (arrays.b)
		free(arrays.b);

	return 0;
}
