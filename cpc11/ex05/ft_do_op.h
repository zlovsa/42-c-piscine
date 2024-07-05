/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:05:48 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 14:05:57 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H
# include <unistd.h>

void	ft_plus(long l, long r);
void	ft_minus(long l, long r);
void	ft_div(long l, long r);
void	ft_mul(long l, long r);
void	ft_mod(long l, long r);
int		ft_strcmp(char *s1, char *s2);
long	ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(long nb);

#endif
