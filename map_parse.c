/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:11:05 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 22:51:24 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "read_text.h"
#include "string_util.h"
#include "ft_split.h"
#include <malloc.h>

int	try_read_line(t_map *map, int line, char *str)
{
	int	count;
	int	len;
	int index;

	len = get_len(str);
	index = line * map->width;
	count = -1;
	while (++count < len && str[count] != '\0')
	{
		if (str[count] == map->empty)
			map->data[count + index] = empty;
		else if (str[count] == map->obstacle)
			map->data[count + index] = obstacle;
		else
			return (0);
	}
	return (1);
}

int	try_data_to_map(t_map *map, char **data, int count_line)
{
	int		index;
	int		len;

	index = 0;
	if (set_value(map, data[index++]) == 0)
		return (0);
	if (create_map(map, get_len(data[index])) == 0)
		return (0);
	while (index < count_line + 1)
	{
		len = get_len(data[index]);
		if (len != map->width)
			break ;
		if (try_read_line(map, index - 1, data[index]) == 0)
			break ;
		index++;
	}
	return (1);
}

int	get_map_data(t_map *map, char *dir)
{
	char	*read;
	char	**data;
	int		try;

	if (try_read_txt(&read, dir) == 0)
		return (0);
	data = ft_split(read, "\n");
	try = try_data_to_map(map, data, count_line(read));
	free_string_array(data);
	free(read);
	return (try);
}
