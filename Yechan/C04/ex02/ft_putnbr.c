/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:43:34 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/14 16:13:50 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);
void	ft_put_number(int nb);

void	ft_putnbr(int nb)
{
	int	rev_neg;

	if (nb > 0)
		ft_put_number(nb);
	else if (nb == 0)
		ft_putchar('0');
	else if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		rev_neg = -nb;
		ft_put_number(rev_neg);
	}
	else
		write(1, "-2147483648", 11);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_put_number(int nb)
{
	if (nb > 0)
	{
		ft_put_number(nb / 10);
		ft_putchar('0' + (nb % 10));
	}
}
