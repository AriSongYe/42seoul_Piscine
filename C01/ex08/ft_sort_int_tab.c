/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:20:52 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/20 13:31:45 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_next(int *tab, int index);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap_next(tab, j);
			j++;
		}
		i++;
	}
}

void	ft_swap_next(int *tab, int index)
{
	int	temp;

	temp = tab[index];
	tab[index] = tab[index + 1];
	tab[index + 1] = temp;
}
