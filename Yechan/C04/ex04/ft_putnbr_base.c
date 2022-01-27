/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:20:29 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/24 13:39:45 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	recur_trans_int(int nbr, int base_len, char *temp, char *base);
int		ft_strlen(char *str);
int		exception_base(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		i;
	char	temp[32];
	char	*place;

	place = temp;
	i = 0;
	if (exception_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
	}
	if (nbr == 0)
		write(1, &base[0], 1);
	base_len = ft_strlen(base);
	recur_trans_int(nbr, base_len, place, base);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	recur_trans_int(int nbr, int base_len, char *temp, char *base)
{
	int	temp_num;
	int	a;

	a = 0;
	if (nbr != 0)
	{
		temp_num = nbr % base_len;
		*temp = temp_num;
		temp++;
		recur_trans_int(nbr / base_len, base_len, temp, base);
		if (nbr > 0)
		{
			a = *(temp - 1);
			write(1, &base[a], 1);
		}		
		else
		{
			a = *(temp - 1) * (-1);
			write(1, &base[a], 1);
		}
	}
}

int	exception_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
