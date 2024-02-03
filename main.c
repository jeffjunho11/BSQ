/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:22 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 22:59:06 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_parse.h"
#include "solve_map.h"
#include <stdio.h>



int		try_parse_maps(char **dirs, int index, int max)
{
	t_pos	pos;
	t_map	map;

	index--;
	while (++index < max)
	{
		if (get_map_data(&map, dirs[index]) == 0)
		{
			write(1, "map error", 11);
			continue ;
		}
		solve_map(&map,&pos);
		if (pos.size == -1)
			write(1, "map error\n", 11);
		else
			print_map(&map);
		delete_dic(&map);
		write(1, "\n", 1);
	}
	return (0);
}

char	**get_input(char *input);

int	main(int argc, char **argv)
{
	char	**input;
	int		result;
	int 	index; 
	int 	max;
	
	if (argc <= 1)
	{
		// input = get_input(maps, argv, 1);
	}
	else
	{
		max = argc;
		index = 1;
		input = argv;
	}
	
	result = try_parse_maps(input, index, max);
	return (result);
}
