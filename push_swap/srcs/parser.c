/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:27:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/06 16:54:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
		result = result * 10 + (*nptr++ - '0');
	return (result * sign);
}

static int	get_i_of_next_num(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			while (str[++i])
				if (str[i] == '-' || str[i] == '+')
					return (-1);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (get_i_of_next_num(str + i) != -1)
				return (i);
			return (-1);
		}
		else
			return (-1);
	}
	return (i);
}

static int	check_for_duplicate(t_list *lst, int num)
{
	while (lst)
	{
		if (lst->data == num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	parse_str(char *str, t_list **lst)
{
	int	num;
	int	i;

	num = ft_atoi(str);
	if (check_for_duplicate(*lst, num))
	{
		ft_printf("Duplicate of numbers\n");
		return (-1);
	}
	i = get_i_of_next_num(str);
	if (i == -1)
	{
		ft_printf("Only numbers\n");
		return (-1);
	}
	append_list(lst, num);
	return (i);
}

t_list	*parse_argv(int argc, char *argv[])
{
	t_list	*head;
	char	*str;
	int		i;
	int		j;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			j = parse_str(str, &head);
			if (j == -1)
			{
				clean_list(&head);
				return (NULL);
			}
			str += j;
		}
		i++;
	}
	return (head);
}
