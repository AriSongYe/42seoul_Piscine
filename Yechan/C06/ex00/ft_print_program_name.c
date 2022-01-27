/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:48:51 by yecsong           #+#    #+#             */
/*   Updated: 2022/01/26 16:59:33 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	str_len(char *str);

int	main(int argc, char **argv)
{
	int	argv_len;

	argv_len = argc;
	argv_len = str_len(argv[0]);
	write(1, argv[0], argv_len);
	write(1, "\n", 1);
	return (0);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
