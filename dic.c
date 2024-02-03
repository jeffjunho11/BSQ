/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:23:42 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 22:19:19 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dic.h"
#include "ft_split.h"
#include "ft_strjoin.h"
#include "string_util.h"
#include "dic_util.h"
#include "ft_string_trim.h"
#include <malloc.h>

int	create_dic(t_dic *dic, int size)
{
	dic->key = malloc(sizeof(char *) * (size + 1));
	if (!(dic->key))
		return (0);
	dic->value = malloc(sizeof(char *) * (size + 1));
	if (!(dic->value))
		return (0);
	dic->key[size] = 0;
	dic->value[size] = 0;
	return (1);
}

void	delete_dic(t_dic *dic)
{
	char	**pointer;

	pointer = dic->key;
	while (*pointer)
		free(*pointer++);
	pointer = dic->value;
	while (*pointer)
		free(*pointer++);
	free(dic->key);
	free(dic->value);
}

int	try_parse_to_dic(t_dic *dic, char **data, int len)
{
	int		index;
	char	**split;
	int		size;

	if (create_dic(dic, len) == 0)
		return (0);
	index = 0;
	while (data[index])
	{
		if (*data[index] == 0)
			break ;
		split = ft_split(data[index], ": ");
		size = 0;
		while (*split[size])
			size++;
		dic->key[index] = ft_string_trim(split[0]);
		dic->value[index++] = ft_strjoin_from_one(size, split, " ");
		free_string_array(split);
	}
	dic->size = index;
	ft_sort_dic(dic, 0, dic->size - 1);
	return (1);
}
