/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:23:00 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/26 16:39:13 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = 'a' + 'z' - argv[1][i];
			if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = 'A' + 'Z' - argv[1][i];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}