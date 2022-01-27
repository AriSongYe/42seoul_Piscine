/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:40:14 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/12 20:26:22 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);
void	ft_tran_print(int num1, int num2);

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		while (j < 100)
		{
			if (i == 98 && j == 99)
				write(1, "98 99", 5);
			else if (i < j)
			{
				ft_tran_print(i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_tran_print(int num1, int num2)
{
	int	num1_tens;
	int	num1_units;
	int	num2_tens;
	int	num2_units;

	num1_tens = num1 / 10;
	num1_units = num1 % 10;
	num2_tens = num2 / 10;
	num2_units = num2 % 10;
	ft_putchar('0' + num1_tens);
	ft_putchar('0' + num1_units);
	ft_putchar(' ');
	ft_putchar('0' + num2_tens);
	ft_putchar('0' + num2_units);
	ft_putchar(',');
	ft_putchar(' ');
}
