/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:12:00 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 22:34:25 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "string_util.h"
#include "string_util.h"
#include "ft_atoi.h"
#include <malloc.h>
#include <unistd.h>

int	create_map(t_map *map, int width)
{
	map->width = width;
	map->size = width * map->height;
	map->data = malloc(sizeof(t_map_type) * (map->size + 1));
	if (!(map->data))
		return (0);
	map->data[map->size] = 0;
	return (1);
}

int	set_value(t_map *map, char *info)
{
	char	empty;
	char	obstacle;
	char	full;
	int		index;
	int		check;

	index = -1;
	while (++index < get_len(info))
	{
		check = 0;
		while (check < index)
			if (info[check++] == info[index])
				return (0);
	}
	map->height = ft_atoi(info, &index);
	map->empty = info[index++];
	map->obstacle = info[index++];
	map->full = info[index++];
	return (1);
}

void	delete_dic(t_map *map)
{
	free(map->data);
}

t_map_type	get_data(t_map *map,int x, int y)
{
	int	index;

	index = x + y * map->width;
	if (index >= map->size || index < -1)
		return (error);
	return (map->data[index]);
}

void	print_map(t_map *map)
{
	int	index;

	index = -1;
	while (++index < map->size)
	{
		if (index != 0 && index % (map->width) == 0)
			write(1, "\n", 1);
		if (map->data[index] == empty)
			write(1, &(map->empty), 1);
		else if (map->data[index] == obstacle)
			write(1, &(map->obstacle), 1);
		else if (map->data[index] == full)
			write(1, &(map->full), 1);
	}
	write(1, "\n", 1);
}