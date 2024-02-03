/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:55:25 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 22:19:19 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dic.h"
#include "read_text.h"
#include "dic.h"
#include "string_util.h"
#include "dic_util.h"

int	get_dic(t_dic *result, char *dir)
{
	char	*read;
	char	**data;
	int		try;

	if (try_read_txt(&read, dir) == 0)
		return (0);
	data = ft_split(read, "\n");
	try = try_parse_to_dic(result, data, count_line(read));
	free_string_array(data);
	free(read);
	return (try);
}

int	get_dic_default(t_dic *result)
{
	char	*dir;

	dir = "numbers.dict";
	return (get_dic(result, dir));
}

void	swap_contents(t_dic *result, t_dic	*new)
{
	int		count;
	int		index;

	index = -1;
	while (++index < new->size)
	{
		count = -1;
		while (++count < result->size)
		{
			if (ft_strcmp(new->key[index], result->key[count]) == 0)
			{
				ft_swap_array(&(new->value[index]), &(result->value[count]));
				break ;
			}
		}
	}
}

int	check_dic(t_dic *base, t_dic *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < base->size && j < new->size)
	{
		if (is_key_valid(new->key[j]) == 0)
			return (0);
		if (ft_strcmp(base->key[i], new->key[j]) == 0)
			i++;
		j++;
	}
	return (base->size == i);
}

int	get_dic_new(t_dic *result, char *dir)
{
	t_dic	new;

	if (get_dic(&new, dir) == 0)
		return (0);
	if (get_dic_default(result) == 0)
		return (0);
	if (check_dic(result, &new) == 0)
		return (0);
	swap_contents(result, &new);
	delete_dic(&new);
	return (1);
}
