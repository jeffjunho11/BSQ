/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:01:18 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 21:19:14 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTIL_H
# define STRING_UTIL_H
# include <malloc.h>

int		get_len(char *str);
int		count_line(char *data);
void	free_string_array(char **array);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap_array(char **num1, char **num2);

#endif