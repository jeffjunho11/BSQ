/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhoh <junhoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:48:32 by junmin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/03 22:03:15 by junhoh           ###   ########.fr       */
=======
/*   Updated: 2024/02/03 21:26:22 by junmin           ###   ########.fr       */
>>>>>>> 8cc2e18 (feat parse data)
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "string_util.h"
# include "string_util.h"
# include "ft_atoi.h"
# include <malloc.h>

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

t_map_type	get_data(t_map *map,int x, int y);
int			create_map(t_map *map, int line);
int			set_value(t_map *map, char *info);
void		delete_dic(t_map *map);
t_map_type	get_data(t_map *map,int x, int y);

#endif
