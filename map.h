/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:48:32 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 19:56:24 by junmin           ###   ########.fr       */
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
}	t_map;

typedef enum e_map_type
{
	error = 0,
	empty,
	obstacle,
	full,
}	t_map_type;

e_map_type	get_data(t_map *map,int x, int y);
