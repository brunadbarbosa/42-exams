/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:42:25 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/24 19:54:38 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void    ft_putnbr(int n)
{
	if(n > 9)
		ft_putnbr(n / 10);
	write(1,&"0123456789"[n % 10], 1);
}

int main(void)
{
    int i;

    i = 1;
    while(i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else 
            ft_putnbr(i);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}