/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:07:40 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/11 13:37:15 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void put_char(char a);

void	ft_print_comb(void)
{
	int i;
	int hund;
	int tens;
	int units; 

	i = 0;

	while (i++ < 789)
	{
		hund = i / 100;
		tens = (i % 100) / 10;
		units = (i % 100) % 10;
		if (hund != tens && tens != units && hund != units)
		{
			put_char('0' + hund);
			put_char('0' + tens);
			put_char('0' + units);
			put_char(',');
			put_char(' ');
		}
	}
	write(1, "789", 3);
}

void put_char(char a) {
	write(1, &a, 1);
}
