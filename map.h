/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:36:53 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 23:04:43 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_H
# define MAP_H
# include "string_util.h"
# include "string_util.h"
# include "ft_atoi.h"
# include <malloc.h>
# include <unistd.h>

typedef struct s_pos
{
	int	x;
	int	y;
	int	size;
}	t_pos;

typedef enum e_map_type
{
	error = -1,
	empty,
	obstacle,
	full,
}	t_map_type;

typedef struct s_map
{
	t_map_type	*data;
	int			height;
	int			width;
	int			size;
	char		empty;
	char		obstacle;
	char		full;
}	t_map;

t_map_type	*get_data(t_map *map,int x, int y);
int			create_map(t_map *map, int line);
int			set_value(t_map *map, char *info);
void		delete_dic(t_map *map);
void		print_map(t_map *map);

#endif
