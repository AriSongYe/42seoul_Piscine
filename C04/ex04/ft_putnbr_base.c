/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:20:29 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/23 21:18:29 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
void	recur_trans_int(int nbr, int base_len, char *temp);
void	ft_rev_int_tab(char *tab);
int	ft_strlen(char *str);
int	exception_base(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		i;
	char	temp[32];
	char	*plz;

	plz = temp;
	i = 0;
	if (exception_base(base))
		return ;
	if(nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	base_len = ft_strlen(base);
	printf("%s\n", base);
	recur_trans_int(nbr, base_len, plz);
	ft_rev_int_tab(plz);
	while (plz[i] != '\0')
	{
		write(1, &base[plz[i] - '0'], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_rev_int_tab(char *tab)
{
	int	index;
	int size;
	int	temp;

	size = 0;
	index = 0;
	while (tab[size] != '\0')
		size++;
	while (index < size / 2)
	{
		temp = tab[index];
		tab[index] = tab[size - 1 - index];
		tab[size - 1 - index] = temp;
		index++;
	}
}

void	recur_trans_int(int nbr, int base_len, char *temp)
{
	int temp_num;
	
	if(nbr > 0)
	{
		temp_num = nbr % base_len;
		*temp = temp_num + '0';
		temp++;
		recur_trans_int(nbr / base_len, base_len, temp);
	}
}
	

int exception_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if(base[i] == '-' || base[i] == '+')
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
