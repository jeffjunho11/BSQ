/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:10:15 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 02:38:22 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIC_UTIL_H
# define DIC_UTIL_H
# include "t_dic.h"
# include "string_util.h"
# include "ft_split.h"

void	ft_sort_dic(t_dic *dic, int left, int right);
int		is_key_valid(char *key);

#endif