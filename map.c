/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhoh <junhoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:12:00 by junmin            #+#    #+#             */
/*   Updated: 2024/02/04 02:01:03 by junhoh           ###   ########.fr       */
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
	int		pivot;
	char	obstacle;
	char	full;
	int		index;
	int		check;

	map->height = ft_atoi(info, &index);
	pivot = index;
	index = -1;
	// while (++index < pivot)
	// {
	// 	check = 0;
	// 	while (check < index)
	// 		if (info[check++] == info[index])
	// 			return (0);
	// }
	map->empty = info[pivot++];
	map->obstacle = info[pivot++];
	map->full = info[pivot++];
	return (1);
}

void	delete_dic(t_map *map)
{
	free(map->data);
}

t_map_type	*get_data(t_map *map,int x, int y)
{
	int	index;

	index = x + y * map->width;
	if (index >= map->size || index < -1)
		return (NULL);
	return (&map->data[index]);
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
}