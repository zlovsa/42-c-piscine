/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:17:08 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 09:17:09 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	init(char opc[5][2])
{
	int i;

	opc[0][0] = '+';
	opc[1][0] = '-';
	opc[2][0] = '/';
	opc[3][0] = '*';
	opc[4][0] = '%';
	i = 0;
	while (i < 5)
		opc[i++][1] = 0;
}

int		main(int argc, char *argv[])
{
	char	opc[5][2];
	void	(*ops[5])(long, long);
	int		i;

	if (argc != 4)
		return (0);
	init(opc);
	ops[0] = &ft_plus;
	ops[1] = &ft_minus;
	ops[2] = &ft_div;
	ops[3] = &ft_mul;
	ops[4] = &ft_mod;
	i = 0;
	while (i < 5 && ft_strcmp(opc[i], argv[2]) != 0)
		i++;
	if (i < 5)
		(*ops[i])(ft_atoi(argv[1]), ft_atoi(argv[3]));
	else
		write(1, "0\n", 2);
	return (0);
}
