#include "rush.h"
#include <stdio.h>

char **create_group_of_numbers(char *number)
{
	int i;
	int g;
	int num_groups;
	int group_size;
	char **groups;

	i = ft_strlen(number) - 1;
	num_groups = (i + 3) / 3;
	groups = malloc(sizeof(char *) * (num_groups + 1));
	g = num_groups - 1;
	while (i >= 0)
	{
		if (i >= 2)
			group_size = 3;
		else
			group_size = i + 1;	
		groups[g] = malloc(sizeof(char *) * (group_size + 1	));
		ft_strncpy(groups[g], &number[i - group_size + 1], group_size);
		groups[g][group_size] = 0;
		i -= group_size;
		g--;
	}
	groups[num_groups] = 0;

	return (groups);
}

void    logic(struct s_arguments *args)
{
	char	**groups;
	int		groups_len;
	int		i;
	int		group_len;
	char	***result;
	char	*group;
	int		j;

	groups = create_group_of_numbers(args->number);
	i = 0;
	groups_len = 0;
	while (groups[i])
	{
		groups_len++;
		i++;
	}
	result = malloc(sizeof(char *) * (groups_len + 1));
	i = 0;
	while (groups[i])
	{
		group = groups[i];
		group_len = ft_strlen(group);
		if (group_len == 1)
			result[i] = get_digit_printable(args, group[0]);
		if (group_len == 2)
			result[i] = get_tens_printable(args, group);
		if (group_len == 3)
			result[i] = get_hudrets_printable(args, group);
		i++;
	}
	result[i] = 0;
	i = 0;
	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			ft_putstr(result[i][j]);
			if (i == groups_len - 1 && j == 3)
				return ;
			ft_putstr(" ");
			j++;
		}
		if (i != 0)
			j = 3;
		if (i != groups_len - 1)
		{
			ft_putstr(get_value_of_nbr(args, "1" , ((groups_len - 1) * 3 + 1) - 3 * i));
			ft_putstr(" ");
		}
		i++;
	}
}
