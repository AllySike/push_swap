static int	ft_is_minus(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	helper(int minus)
{
	if (minus == -1)
		return (-1);
	else
		return (1);
}

int	my_atoi(const char *str, int *output)
{
	int				minus;
	int				i;

	i = 0;
	minus = 1;
	*output = 0;
	if (str[i] == '-')
		minus = ft_is_minus(str[i++]);
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			*output = (*output) * 10 + (str[i++] - 48);
			if (i >= 19)
				return (helper(minus));
		}
		else
			return (1);
	}
	return (0);
}

int	my_atoi_arg(const char *str, int *i, int *output)
{
	int	minus;

	minus = 1;
	*output = 0;
	if (str[*i] == '-')
		minus = ft_is_minus(str[i[0]++]);
	while (str[*i])
	{
		if (str[*i] <= '9' && str[*i] >= '0')
		{
			*output = (*output) * 10 + (str[i[0]++] - 48);
		}
		else if (str[*i] != ' ' && (str[*i] > '9' || str[*i] < '0'))
			return (1);
		else
		{
			i[0]++;
			output[0] *= helper(minus);
			return (0);
		}
	}
	return (0);
}
