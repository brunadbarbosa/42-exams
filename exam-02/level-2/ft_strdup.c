/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:29:48 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/27 13:45:22 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	ft_strlen(char *s)
{
	int	c;

	c = 0;
	while (s[c])
	{
		c++;
	}
	return (c);
}
char	*ft_strdup(char *src)
{
	int	i;
	char	*ns;

	i = 0;
	ns = malloc((ft_strlen(src + 1)) * sizeof(char));
	if (!ns)
		return (0);
	while (src[i])
	{
		ns[i] = src[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

#include <stdio.h>

int main()
{
	char	*a;
	a = "Hello World";
	printf("%s\n", ft_strdup(a));
}