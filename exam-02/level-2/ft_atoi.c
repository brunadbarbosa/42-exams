/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:21:49 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/27 12:41:48 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	n;

	i = 0;
	result = 0;
	n = 1;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				n = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] -'0');
			i++;
		}
	return (result * n);
}

int	main(void)
{
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("-42"));
}