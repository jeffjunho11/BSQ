/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:18:27 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 23:33:06 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcat.h"
#include "string_util.h"
#include "vector.h"

char	*ft_strdup(char *src, int size)
{
	char	*dup;
	int		len;

	dup = (char *)malloc(sizeof(char) * size);
	if (!dup)
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		dup[len] = src[len];
		len++;
	}
	dup[len] = 0;
	return (dup);
}

int	add(t_vector *vec,char *add)
{
	char *copy;
	int	new_len;

	new_len = get_len(add);
	if (vec->size + new_len >= vec->max)
	{
		copy = ft_strdup(vec->input, vec->max * 2 );
		free(vec->input);
		vec->input = copy;
	}
	ft_strcat(vec->input, add);
}