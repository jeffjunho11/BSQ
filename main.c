/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhoh <junhoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:22 by junmin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/03 22:56:05 by junmin           ###   ########.fr       */
=======
/*   Updated: 2024/02/03 22:55:07 by junhoh           ###   ########.fr       */
>>>>>>> 877945e5a15ae161be616751edfd9db5e0692854
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
		// solve_map(&map,&pos);
		// if (pos.size == -1)
		// 	write(1, "map error\n", 11);
		// else
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
<<<<<<< HEAD
	int		result;
	int 	index; 
	int 	max;
=======
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
>>>>>>> 877945e5a15ae161be616751edfd9db5e0692854
	
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
