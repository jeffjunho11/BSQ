/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:12:00 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 20:26:19 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "map.h"
#include "ft_split.h"
#include "ft_strjoin.h"
#include "string_util.h"
#include "ft_string_trim.h"
#include <malloc.h>

int	create_map(t_map *map, int width, int height)
{
	map->size = width * height;
	map->width = width;
	map->height = height;
	map->data = malloc(sizeof(t_map_type) * (map->size + 1));
	if (!(map->data))
		return (0);
	map->data[map->size] = 0;
	return (1);
}

void	delete_dic(t_map *map)
{
	free(map->data);
}

int	try_parse_to_dic(t_map *map, char **data, int len)
{
	int		index;
	char	**split;
	int		size;

	if (create_map(map, len) == 0)
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
		map->key[index] = ft_string_trim(split[0]);
		map->value[index++] = ft_strjoin_from_one(size, split, " ");
		free_string_array(split);
	}
	map->size = index;
	ft_sort_dic(map, 0, map->size - 1);
	return (1);
}