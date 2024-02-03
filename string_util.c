/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:02:05 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 21:20:06 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	get_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	count_line(char *data)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (data[index])
	{
		if (data[index] == '\n' || data[index] == 0)
			count++;
		index++;
	}
	return (count);
}

void	free_string_array(char **array)
{
	int		count;

	count = 0;
	while (*array[count])
		free(array[count++]);
	free(array[count]);
	free(array);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (get_len(s1) != get_len(s2))
		return (get_len(s1) - get_len(s2));
	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap_array(char **num1, char **num2)
{
	char	*temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
