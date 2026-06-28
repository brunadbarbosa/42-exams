/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:09:38 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/29 19:31:02 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int	max;

	i = 0;
	max = tab[i];
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
#include <stdio.h>
int main()
{
	int int_tab[] = {1254789, 5, 0, 564, 12365};
	printf("%d", max(int_tab, 5));
}