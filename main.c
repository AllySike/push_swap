#include "includes/push_swap.h"

void push_swap(t_push_swap *arrays, char *argv[])
{
	int i;

	i = 0;
	while (argv[i + 1], i < arrays->a_size)
	{
		arrays->a[i] = atoi(argv[i + 1]);
		i++;
	}
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
	arrays.b[0] = (int)argv[1];
	push_swap(&arrays, argv);
	int i = 0;
	printf("a before:\n");
	while (i < arrays.a_size)
		printf("%i\n", arrays.a[i++]);
	i = 0;
	printf("\nb before:\n");
	while (i < arrays.b_size)
		printf("%i\n", arrays.b[i++]);
	push_b(&arrays);
	push_b(&arrays);
	printf("\na after:\n");
	i = 0;
	while (i < arrays.a_size)
		printf("%i\n", arrays.a[i++]);
	i = 0;
	printf("\nb after:\n");
	while (i < arrays.b_size)
		printf("%i\n", arrays.b[i++]);
	reverse_rotate_ab(&arrays);
	printf("\na after:\n");
	i = 0;
	while (i < arrays.a_size)
		printf("%i\n", arrays.a[i++]);
	i = 0;
	printf("\nb after:\n");
	while (i < arrays.b_size)
		printf("%i\n", arrays.b[i++]);
	if (arrays.a)
		free(arrays.a);
	if (arrays.b)
		free(arrays.b);
	return 0;
}
