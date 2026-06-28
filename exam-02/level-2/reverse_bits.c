/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:27:26 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/29 20:33:17 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	new  = '\0';
	int	bit = 7;
	int	new_bit = 0;

	while (bit >= 0)
	{
		if (octet >> bit & 1)
			new |= 1 << new_bit;
		bit--;
		new_bit++;
	}
	return (new);
}
