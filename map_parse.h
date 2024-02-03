/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:11:05 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 21:28:58 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "read_text.h"
#include "string_util.h"
#include "ft_split.h"
#include <malloc.h>

int		try_read_line(t_map *map, int line, char *str);
int		try_data_to_map(t_map *map, char **data);
int		get_map_data(t_map *map, char *dir);
int		try_parse_map(t_map *map, char *dir);
int		try_parse_maps(t_map **maps, char **dirs, int index, int max);