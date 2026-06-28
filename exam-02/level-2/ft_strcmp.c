/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:42:30 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/27 12:48:38 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(void)
{
	printf ("The value compared is: %d\n", ft_strcmp("ABC", "ABC"));
	printf ("The value compared is: %d\n", ft_strcmp("ABD", "ABC"));
	printf ("The value compared is: %d\n", ft_strcmp("CDD", "ABC"));
	printf ("The value compared is: %d\n", ft_strcmp("ABC", "BBB"));
	printf ("The value compared is: %d\n", ft_strcmp("bAA", "ABC"));
}