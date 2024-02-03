/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:23:53 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 02:20:20 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

char	*allocate(int size)
{
	char	*arr;

	arr = malloc(size);
	if (!arr)
		return (0);
	arr[size - 1] = 0;
	return (arr);
}

int	get_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_concatenate_from_one(char *arr, int size, char **strs, char *sep)
{
	int	count;
	int	repeat;
	int	len;

	len = 0;
	count = 1;
	while (count < size)
	{
		repeat = 0;
		while (strs[count][repeat])
		{
			arr[len++] = strs[count][repeat];
			repeat++;
		}
		repeat = 0;
		count++;
		if (count == size)
			break ;
		while (sep[repeat])
			arr[len++] = sep[repeat++];
	}
	arr[len] = 0;
}

char	*ft_strjoin_from_one(int size, char **strs, char *sep)
{
	char			*arr;
	unsigned int	len;
	int				count;
	unsigned int	repeat;

	if (size == 0)
		return (allocate(1));
	count = 1;
	repeat = get_len(sep);
	len = 0;
	while (count < size)
		len += get_len(strs[count++]) + repeat;
	len -= repeat;
	arr = allocate(len + 1);
	ft_concatenate_from_one(arr, size, strs, sep);
	return (arr);
}
