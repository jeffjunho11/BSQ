/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:34:29 by junmin            #+#    #+#             */
/*   Updated: 2024/01/30 21:08:53 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRJOIN_H
# define FT_STRJOIN_H
# include <malloc.h>

char	*ft_strjoin_from_one(int size, char **strs, char *sep);
int		get_len(char *str);

#endif