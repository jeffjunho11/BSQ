/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:11:05 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 22:51:20 by junmin           ###   ########.fr       */
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
