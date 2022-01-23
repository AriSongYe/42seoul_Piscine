/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:20:29 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/22 15:29:31 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_strlen(char *str);

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;

	base_len = ft_strlen(str);

}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int recur_trans_int(int nbr, int base_len)
{
	
	if(nbr > 0)
	{

	}
}
