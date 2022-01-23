/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:07:40 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/17 16:41:20 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	put_char(char a);
void	put_out(int a, int b, int c);

void	ft_print_comb(void)
{
	int	i;
	int	hund;
	int	tens;
	int	units;

	i = 0;
	while (i++ < 788)
	{
		hund = i / 100;
		tens = (i % 100) / 10;
		units = (i % 100) % 10;
		if (hund != tens && tens != units && hund != units)
			if (hund < tens && tens < units)
				put_out(hund, tens, units);
	}
	write(1, "789", 3);
}

void	put_char(char a)
{
	write(1, &a, 1);
}

void	put_out(int a, int b, int c)
{
	put_char('0' + a);
	put_char('0' + b);
	put_char('0' + c);
	put_char(',');
	put_char(' ');
}
