/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhoh <junhoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:22 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 22:55:07 by junhoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_parse.h"
#include "solve_map.h"
#include <stdio.h>


char	**get_input(char *input);

int	main(int argc, char **argv)
{
	char	**input;
	t_map	map;
	t_pos	pos;

	//get_map_data(&map,"example_file");
	solve_map(&map,&pos);
	print_map(&map);
	printf("height\n %d\n\n",map.height);
	printf("width\n %d\n\n",map.width);
	printf("size\n %d\n\n",map.size);
	printf("empty\n %c\n\n",map.empty);
	printf("obstacle\n %c\n\n",map.obstacle);
	printf("full\n %c\n\n",map.full);
	// if (argc <= 1)
	// {
	// 	// input = get_input(maps, argv, 1);
	// }
	// else
	// {
	// 	if (try_parse_maps(maps, argv, 1, argc))
	// 	{
	// 		delete_dic(&maps);
	// 		return (0);
	// 	}
	// }
	
	// delete_dic(&maps);
	return (0);
}
