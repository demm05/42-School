/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:41:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:49:43 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

static int	get_len_of_num(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	set_values(int n, long *num, int *len, int *is_minus, t_spec_info s_info)
{
	int	len_of_n;

	*num = n;
	*len = 0;
	*is_minus = 0;
	if (*num < 0)
	{
		*is_minus = 1;
		*num *= -1;
		*len = *len + 1;
	}
	len_of_n = get_len_of_num(*num);
	*len += len_of_n;
	if (s_info.precision > len_of_n)
		*len += s_info.precision - len_of_n;
	if (s_info.width > *len && !s_info.flags.minus)
		*len += s_info.width - len_of_n;
}

char	*pf_itoa(int n, t_spec_info s_info)
{
	long	num;
	int		len;
	int		is_minus;
	char	*res;
	int		len_of_n;
	char	pad;

	set_values(n, &num, &len, &is_minus, s_info);
	len_of_n = get_len_of_num(num);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len--] = 0;
	while (len_of_n--)
	{
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	if (s_info.flags.zero || (s_info.is_precision && s_info.precision > s_info.width))
		pad = '0';
	else
		pad = ' ';
	while (len - is_minus >= 0)
		res[len--] = pad;
	if (is_minus)
		res[0] = '-';
	return (res);
}

// char	*do_int_precision(char *buffer, t_spec_info s_info)
// {
// 	int		len;
// 	int		i;
// 	int		j;
// 	char	*pads;
// 	char	*temp;
// 
// 	if (!s_info.precision)
// 		return (buffer);
// 	len = ft_strlen(buffer);
// 	if (s_info.precision <= len)
// 		return (buffer);
// 	temp = buffer;
// 	buffer = malloc(sizeof(char) * (s_info.precision + 1));
// 	i = 0;
// 	j = 0;
// 	while (i < s_info.precision - len)
// 		buffer[i++] = '0';
// 	while (i < s_info.precision)
// 		buffer[i++] = temp[j++];
// 	free(temp);
// 	return (buffer);
// }

char	*pf_integer(va_list val, t_spec_info s_info)
{
	int		nb;
	char	*temp;
	char	*buffer;

	nb = va_arg(val, int);
	if (nb == 0 && s_info.is_precision && !s_info.precision)
		return (ft_strdup(""));
	buffer = pf_itoa(nb, s_info);
	if (!buffer)
		return (0);
	temp = buffer;
	if (s_info.flags.plus && buffer[0] != '-')
		buffer = ft_strjoin("+", buffer); 
	else if (s_info.flags.space && buffer[0] != '-')
		buffer = ft_strjoin(" ", buffer); 
	else
		return (buffer);
	free(temp);
	return (buffer);
}
