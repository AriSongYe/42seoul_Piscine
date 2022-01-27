/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:33:15 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/25 21:55:41 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int	i;
	int	num;

	i = 2;
	if (nb == 0 || nb == 1 || nb < 0)
		return (0);
	else if (nb % 2 == 0 && nb != 2)
		return (0);
	num = ft_sqrt(nb);
	while (i <= num)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while ((i * i) <= nb && i * i > 0)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (i - 1);
}
