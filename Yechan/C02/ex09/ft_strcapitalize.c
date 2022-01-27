/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:13:34 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/22 11:40:55 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	num_alpha(char ch);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[0] - 32;
		if (!num_alpha(str[i]) && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] = str[i + 1] - 32;
		else if (num_alpha(str[i]) && str[i + 1] >= 'A' && str[i + 1] <= 'Z')
			str[i + 1] = str[i + 1] + 32;
		i++;
	}
	return (str);
}

int	num_alpha(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	else if (ch >= 'A' && ch <= 'Z')
		return (1);
	else if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}
