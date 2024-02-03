/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:00:39 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 05:15:27 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIC_H
# define DIC_H
# include "t_dic.h"
# include "ft_split.h"
# include "ft_strjoin.h"
# include <malloc.h>

int		count_line(char *data);
int		create_dic(t_dic *dic, int size);
void	delete_dic(t_dic *dic);
int		try_parse_to_dic(t_dic *dic, char **data, int len);

#endif