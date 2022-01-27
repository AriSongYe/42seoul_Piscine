/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:58:44 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/24 17:18:47 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);
int	exception_base(char *base);
int	ft_atoi(char *str, char *base, int base_len);
int	is_base(char ch, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	i;
	int	base_len;

	i = 0;
	num = 0;
	if (exception_base(base) || str[0] == '\0')
		return (0);
	while (base[i] != '\0')
		i++;
	base_len = i;
	num = ft_atoi(str, base, base_len);
	return (num);
}

int	ft_atoi(char *str, char *base, int base_len)
{
	int	i;
	int	minus;
	int	num;

	num = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (is_base(str[i], base))
	{
		num = num * base_len + is_base(str[i], base) - 1;
		i++;
	}
	return (num * minus);
}

int	is_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ch)
			return (i + 1);
		i++;
	}
	return (0);
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
		else if (base[i] == ' ' || (base[i] >= '\t' && base[i] <= '\r'))
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
