/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_apply.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:54:48 by junmin            #+#    #+#             */
/*   Updated: 2024/01/30 22:17:20 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIC_APPLY_H
# define DIC_APPLY_H
# include "t_dic.h"

int	get_dic_new(t_dic *result, char *dir);
int	get_dic_default(t_dic *result);

#endif
