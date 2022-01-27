/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:18 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/27 13:33:35 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reset_array(int *order, int argc);
void	print_array(char *order);
void	ft_swap(int *a, int *b);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	order[100000];

	i = 1;
	j = 1;
	reset_array(order, argc);
	while (i < argc)
	{
		j = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[order[i]], argv[order[j]]) > 0)
				ft_swap(&order[i], &order[j]);
			j++;
		}
		print_array(argv[order[i]]);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reset_array(int *order, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		order[i] = i;
		i++;
	}
}

void	print_array(char *order)
{
	int	i;

	i = 0;
	while (order[i] != '\0')
	{
		write(1, &order[i], 1);
		i++;
	}
}
