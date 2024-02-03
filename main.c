/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:02:22 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 20:10:14 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	main(int argc, char **argv)
{
	t_map	result;

	if (argc > 3 || argc < 2)
	{
		write (2, "Error\n", 7);
		return (1);
	}
	if (argc == 3)
	{
		if (new_dic(&result, argv[1], argv[2]) == 0)
			return (1);
	}
	else
	{
		if (defalut_dic(&result, argv[1]) == 0)
			return (1);
	}
	delete_dic(&result);
	return (0);
}
