/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhoh <junhoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:05:15 by junhoh            #+#    #+#             */
/*   Updated: 2024/02/04 02:07:03 by junhoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "map.h"

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
	
	i = 0;
	max_cell = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (dp[i][j] > max_cell)
			{
				max->x = j;
				max->y = i;
				max->size = dp[i][j];
				max_cell = dp[i][j];
			}
			j++;
		}
		i++;
	}
	return (max);
}

void	memory_free(int **dp, t_map *map)
{
	int i;
	
	i = -1;
	while (++i < map->height)
		free(dp[i]);
	free(dp);
}

void fill_map(t_map *map, t_pos *max, int **dp)
{
	int i;
	int j;
	i = max->size - 1;
	while(i >= 0)
	{
		j = max->size - 1;
		while(j >= 0)
		{
			*get_data(map, max->x - j, max->y - i) = full;
			j--;
		}
		i--;
	}
}

t_pos	*solve_map(t_map *map, t_pos *max)
{
	int	i;
	int	j;
	int	min_check;
	int	**dp;
	i = 0;
	dp = (int **)malloc(sizeof(int *) * (map->height + 1));
	while (i < map->height)
	{
		j = 0;
		dp[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		while (j < map->width)
		{
			if (*get_data(map, j, i) == obstacle)
			{
				dp[i][j] = 0;
			}
			else
				dp[i][j] = 1;
			if (i == 0 || j == 0)
			{
				j++;
				continue ;
			}
			if (dp[i][j] != 0)
			{
				min_check = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = 1 + min(min_check, dp[i - 1][j - 1]);
			}
			j++;
		}
		i++;
	}
	
	find_max_square(map, max, dp);
	fill_map(map, max, dp);
	// memory_free(dp, map);
	return (max);
}
