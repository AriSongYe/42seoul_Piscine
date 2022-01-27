/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:01:22 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/26 13:03:41 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dfs(int x);
void	print_chess(char *g_answer);
void	init_array(int *array);
void	init_char_array(char *array);

char	g_answer[10];
int		g_right_dia[20];
int		g_left_dia[20];
int		g_col[10];
int		g_cnt;

int	ft_ten_queens_puzzle(void)
{
	dfs(0);
	return (g_cnt);
}

void	dfs(int x)
{
	int	i;

	i = 0;
	if (x == 10)
	{
		print_chess(g_answer);
	}	
	while (i < 10)
	{
		if (!g_right_dia[i + x] && !g_left_dia[10 + x - i] && !g_col[i])
		{
			g_col[i] = 1;
			g_right_dia[i + x] = 1;
			g_left_dia[10 + x - i] = 1;
			g_answer[x] = i + '0';
			dfs(x + 1);
			g_col[i] = 0;
			g_right_dia[i + x] = 0;
			g_left_dia[10 + x - i] = 0;
		}
		i++;
	}
}

void	print_chess(char *g_answer)
{
	write(1, g_answer, 10);
	write(1, "\n", 1);
	g_cnt++;
}
