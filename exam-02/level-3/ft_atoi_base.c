int	is_valid(int c, int baselen)
{
	char	*lc = "0123456789abcdef";
	char	*uc = "0123456789ABCDEF";
	int	i = 0;

	while (i < baselen)
	{
		if (c == lc[i] || c == uc[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	n = 1;
	int	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] && is_valid(str[i], str_base))
	{
		result *= str_base;
		if (str[i] >= '0'&& str[i] <= 'z')
			result += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'z')
			result += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result += str[i] - 'A' + 10;
		i++;
	}
	return (result * n);
}