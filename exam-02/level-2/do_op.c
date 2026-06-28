/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:51:01 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/26 19:13:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int	main(int argc, char **argv)
{	
	if(argc == 4)
	{
		int n1 = atoi(argv[1]);
		int n2 = atoi(argv[3]);
		int	fn;
		if (argv[2][0] == '+')
			fn = n1 + n2;
		else if (argv[2][0] == '-')
			fn = n1 - n2;
		else if (argv[2][0] == '*')
			fn = n1 * n2;
		else if (argv[2][0] == '/')
			fn = n1 / n2;
		printf("%d", fn);
	}
	printf("\n");
	return (0);
}