/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:18:39 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 23:32:49 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "ft_strcat.h"
# include "string_util.h"

typedef struct s_vector
{
	char	*input;
	int		size;
	int		max;
}	t_vector;

int	add(t_vector *vec,char *add);

#endif