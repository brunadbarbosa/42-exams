/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:59:11 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/26 11:35:49 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char **argv)
{
    int i;
    int j;

    if(argc == 2)
    {
        i = 0;
        while (argv[1][i])
        {
            if(argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                j = 0;
                while(j < argv[1][i] - 64)
                {
                    write(1, &argv[1][i], 1);
                    j++;
                }
            }
            else if(argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                j = 0;
                while (j < argv[1][i] - 96)
                {
                    write(1, &argv[1][i], 1);
                    j++;
                }
            }
            else
            {
                write(1, &argv[1][i], 1);
            }
			i++;
        }
    }
	write(1, "\n", 1);
    return (0);
}