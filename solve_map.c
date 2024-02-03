/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhoh <junhoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:05:15 by junhoh            #+#    #+#             */
/*   Updated: 2024/02/03 22:51:53 by junhoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "map.h"

/*
int	valid_check()
{
	
}
*/
int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_pos	*find_max_square(t_map *map, t_pos *max, int **dp)
{
	int	i;
	int	j;
	int	max_cell;

	max_cell = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (dp[i][j] > max_cell)
			{
				max->x = j;
				max->y = i;
				max->size = dp[i][j];
			}
		}
	}
	return (max);
}

void	memory_free(int **dp, t_map *map)
{
	int i;
	
	i = 0;
	while (i < map->width)
		free(dp[i]);
	free(dp);
}

t_pos	*solve_map(t_map *map, t_pos *max)
{
	int	i;
	int	j;
	int	min_check;
	int	**dp;

	dp = (int **)malloc(sizeof(int *) * (map->height + 1));
	while (i < map->height)
	{
		j = 0;
		dp[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		while (j < map->width)
		{
			if (get_data(map, i, j) == obstacle)
				dp[i][j] = 0;
			else
				dp[i][j] = 1;
			if (i == 0 || j == 0)
				continue ;
			if (dp[i][j] != 0)
			{
				min_check = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = 1 + min(min_check, dp[i - 1][j - 1]);
			}
			j++;
		}
		i++;
	}
	max = find_max_square(map, max, dp);
	memory_free(dp, map);
	return (max);
}
