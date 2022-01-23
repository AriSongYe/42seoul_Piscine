/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:19:06 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/23 14:44:32 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arr_length(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	i;

	i = 0;
	dest_length = arr_length(dest);
	src_length = arr_length(src);
	if (dest_length >= size)
		return (src_length + size);
	while (i < size - (1 + dest_length) && src[i] != '\0')
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i + dest_length] = '\0';
	return (dest_length + src_length);
}

int	arr_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
