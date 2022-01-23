/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:37:02 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/22 16:25:39 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int to_int(char *str, int start, int end_point);
int	is_num(char ch);
int find_minus(char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	start_point;
	int	end_point;
	int	num;

	start_point = 0;
	end_point = 0;
	i = 0;
	if(str[0] == '\0')
		return 0;
	while (str[i] != '\0')
	{
		if (is_num(str[i]) && !is_num(str[i + 1]))
			start_point = i + 1;
		else if(!is_num(str[i]) && is_num(str[i + 1]))
		{
			end_point = i;
			break;
		}
		i++;
	}
	num = to_int(str, start_point, end_point);
	return (find_minus(str) * num);
}

int main()
{
	int num;
	char *a = "2222222222222222222222222222";
	num = ft_atoi(a);
	printf("%d\n", num);
	return 0;
}

int	is_num(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 0;
	else
		return 1;
}

int to_int(char *str, int start, int end_point)
{
	int	temp;

	temp = 0; 

	while (start <= end_point)
	{
		temp = 10 * temp;
		temp = temp + (str[start] - '0');
		start++;
	}
	return (temp);
}

int find_minus(char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 1;
	while(str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	return (minus);
}
