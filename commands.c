#include "includes/push_swap.h"

void add_command(t_push_swap *arrays, int i)
{
    t_commands *tmp;

    tmp = arrays->commands;
    while (tmp && (t_commands *)tmp->next)
        tmp = (t_commands *)tmp->next;
    ((t_commands *)tmp->next)->command = i;
}
