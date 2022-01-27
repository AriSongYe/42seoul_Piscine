/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:25:17 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/22 12:10:34 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char ch);
void	print_hex(unsigned char ch);

void	ft_putstr_non_printable(char *str)
{
	unsigned char	ch;

	ch = *str;
	while (*str != '\0')
	{
		ch = *str;
		if (ch < 32 || ch > 126)
			print_hex(ch);
		else
			ft_putchar(ch);
		str++;
	}
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	print_hex(unsigned char ch)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[ch / 16]);
	ft_putchar(hex[ch % 16]);
}
