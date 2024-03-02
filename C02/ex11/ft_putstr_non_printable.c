/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:55:43 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/02 21:23:50 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable(str[i]) == 1)
			write(1, &str[i], 1);
		else
		{
			ft_putchar('\\');
			write(1, &"0123456789abcdef"[str[i] / 16], 1);
			write(1, &"0123456789abcdef"[str[i] % 16], 1);
		}
		i++;
	}
}
