/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:48:32 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 20:27:19 by junmin           ###   ########.fr       */
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
	t_map_type	*data;
	int			height;
	int			width;
	int			size;
	char		empty;
	char		obstacle;
	char		full;
}	t_map;

typedef enum e_map_type
{
	error = -1,
	empty,
	obstacle,
	full,
}	t_map_type;

t_map_type	get_data(t_map *map,int x, int y);
