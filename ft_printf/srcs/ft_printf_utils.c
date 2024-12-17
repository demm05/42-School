#include "../include/ft_printf.h"

int	get_len_of_flags(t_flags flags)
{
	int	len;

	len = 0;
	if (flags.hash)
		len++;
	if (flags.zero)
		len++;
	if (flags.minus)
		len++;
	if (flags.space)
		len++;
	if (flags.plus)
		len++;
	return (len);
}

int	parse_flag(char c, t_format_info *t_info, t_flags *flags)
{
	if (c == '+')
	{
		if (flags->plus || flags->space)
			return (-1);
		flags->plus = 1;
		return (1);
	}
	else if (c == ' ')
	{
		if (flags->plus || flags->space)
			return (-1);
		flags->space = 1;
		return (1);
	}
	else if (c == '-')
	{
		if (flags->minus || flags->zero)
			return (-1);
		flags->minus = 1;
		return (1);
	}
	else if (c == '0')
	{
		if (flags->zero)
			return (1);
		if (flags->minus)
			return (-1);
		flags->zero = 1;
		return (1);
	}
	else if (c == '#')
	{
		if (flags->hash)
			return (-1);
		flags->hash = 1;
		return (1);
	}
	return (0);
}
