/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:27:05 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/17 11:18:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char ch)
{
	if (ch < 32 || ch > 126)
		return (0);
	return (1);
}

void	put_hex(unsigned char ch)
{
	ft_putchar("0123456789abcdef"[ch / 16]);
	ft_putchar("0123456789abcdef"[ch % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str))
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			put_hex(*str);
		}
		str++;
	}
}

/*int main(void)
{
	char *s = "Co\uA2F6ucou\tu vas ... H 13 $%^&*: bien ?";
	ft_putstr_non_printable(s);
	return (0);
}*/