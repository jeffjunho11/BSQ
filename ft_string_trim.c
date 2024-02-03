/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:41:51 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 22:40:35 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "ft_strjoin.h"

void	copy_data(char *src, char *new, int len, int index)
{
	int		first_num;
	int		meet_zero;

	meet_zero = 0;
	first_num = 0;
	while (src[++len] != '\0')
	{
		if (src[len] == ',' || src[len] == '.')
			continue ;
		if (src[len] == '0' && first_num == 0)
		{
			meet_zero = 1;
			continue ;
		}
		if (src[len] < '0' || src[len] > '9')
			break ;
		new[index++] = src[len];
		first_num = 1;
	}
	if ((meet_zero && !first_num) || (!meet_zero && !first_num))
		new[index++] = '0';
	new[index] = 0;
}

void	copy_trim(char *src, char *new, int count_sign, int len)
{
	int		index;

	index = 0;
	len--;
	if (count_sign % 2 == 1)
		new[index++] = '-';
	copy_data(src, new, len, index);
}

char	*ft_string_trim(char *src)
{
	char	*new;
	int		len;
	int		count_sign;

	count_sign = 0;
	new = (char *)malloc(sizeof(char) * get_len(src));
	if (!new)
		return (0);
	len = 0;
	while (src[len] && ((src[len] <= 13 && src[len] >= 9) || src[len] == ' '))
		len++;
	while (src[len] != '\0' && (src[len] == '+' || src[len] == '-'))
		if (src[len++] == '-')
			count_sign++;
	copy_trim(src, new, count_sign, len);
	return (new);
}
