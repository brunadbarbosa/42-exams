/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:40:22 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/29 19:02:51 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
		if (n <= 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 != 0)
			return (0);
		n /= 2;
	}
	return (1);
}

#include <stdio.h>
int main()
{
	printf("%d", is_power_of_2(16));
}