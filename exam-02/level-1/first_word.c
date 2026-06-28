/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:28:09 by brmaria-          #+#    #+#             */
/*   Updated: 2025/05/23 18:03:39 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc != 2 || argv[1] == NULL)
    {
        write (1, "\n", 1);
        return (0);
    }
    if(argc == 2)
    {
        int i;

        i = 0;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while ((argv[1][i] != ' ' || argv[1][i] != '\t') && argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1); 
    return (0);
}