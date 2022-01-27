/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:35:31 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/17 21:29:16 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	dfs(int n, int index);
int		print_num(void);
void	ft_putchar(char ch);
void	comma_blank(int max);

char	g_num[10];
int		g_stack[10];

void	ft_print_combn(int n)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (i < 10)
	{
		g_stack[i] = 0;
		g_num[i] = '0' + i;
		i++;
	}
	dfs(n, index);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	print_num(void)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < 10)
	{
		if (g_stack[i] == 1)
		{
			ft_putchar(g_num[i]);
			max++;
		}
		i++;
	}
	return (max);
}

void	dfs(int n, int index)
{
	int	max;

	max = 0;
	if (n == 0)
	{
		max = print_num();
		comma_blank(max);
	}
	while (index < 10)
	{
		if (n != 0)
		{
			g_stack[index] = 1;
			dfs(n - 1, index + 1);
			g_stack[index] = 0;
		}
		index++;
	}
}

void	comma_blank(int max)
{
	int	is_max;
	int	tr_max;

	is_max = 0;
	tr_max = 10 - max;
	while (tr_max < 10)
	{
		if (g_stack[tr_max] == 0)
		{
			is_max = 1;
			break ;
		}
		tr_max++;
	}
	if (is_max == 1)
		write(1, ", ", 2);
}
