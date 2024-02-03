/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:22 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 21:30:58 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "map_parse.h"
#include <stdio.h>


char	**get_input(char *input);

int	main(int argc, char **argv)
{
	char	**input;
	t_map	**maps;

	get_map_data(*maps,argv[1]);
	for (size_t i = 0; i < (*maps)->data[i]; i++)
	{
		printf("%d ",(*maps)->data[i]);
		if (i + 1 == (*maps)->width)
			printf("\n");
	}
	
	printf("height\n %d\n\n",(*maps)->height);
	printf("width\n %d\n\n",(*maps)->width);
	printf("size\n %d\n\n",(*maps)->size);
	printf("empty\n %d\n\n",(*maps)->empty);
	printf("obstacle\n %d\n\n",(*maps)->obstacle);
	printf("full\n %d\n\n",(*maps)->full);
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
