/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhoh <junhoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:48:32 by junmin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/03 20:13:04 by junhoh           ###   ########.fr       */
=======
/*   Updated: 2024/02/03 20:12:16 by junmin           ###   ########.fr       */
>>>>>>> a930c03 (feat add util)
/*                                                                            */
/* ************************************************************************** */


typedef struct s_pos
{
	int	x;
	int	y;
	int	size;
}	t_pos;

typedef struct s_map
{
	char *data;
	int	height;
	int	width;
}	t_map;

typedef enum e_map_type
{
	error = 0,
	empty,
	obstacle,
	full,
}	t_map_type;

t_map_type	get_data(t_map *map,int x, int y);
