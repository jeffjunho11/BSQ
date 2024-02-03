/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:10:15 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 22:19:19 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_dic.h"
#include "string_util.h"
#include "ft_split.h"
#include "dic.h"

void	swap_key_value(t_dic *dic, int i, int j)
{
	char	*temp;

	temp = dic->key[i];
	dic->key[i] = dic->key[j];
	dic->key[j] = temp;
	temp = dic->value[i];
	dic->value[i] = dic->value[j];
	dic->value[j] = temp;
}

void	ft_sort_dic(t_dic *dic, int left, int right)
{
	char	*p_key;
	char	*p_value;
	int		count_l;
	int		count_r;

	if (left >= right)
		return ;
	count_l = left;
	count_r = right;
	swap_key_value(dic, left, (left + right) / 2);
	p_key = dic->key[left];
	p_value = dic->value[left];
	while (count_l < count_r)
	{
		while (ft_strcmp(p_key, dic->key[count_r]) < 0)
			count_r--;
		while (count_l < count_r && ft_strcmp(p_key, dic->key[count_l]) >= 0)
			count_l++;
		swap_key_value(dic, count_l, count_r);
	}
	swap_key_value(dic, left, count_l);
	dic->key[count_l] = p_key;
	dic->value[count_l] = p_value;
	ft_sort_dic(dic, left, count_l - 1);
	ft_sort_dic(dic, count_l + 1, right);
}

int	is_key_valid(char *key)
{
	int	count;

	count = 0;
	while (key[count])
	{
		if (key[count] < '0' || key[count] > '9')
			return (0);
		count++;
	}
	return (1);
}
