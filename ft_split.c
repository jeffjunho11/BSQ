/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:31:27 by junmin            #+#    #+#             */
/*   Updated: 2024/01/31 02:19:59 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	is_separator(char check, char *charset)
{
	int	count;

	count = 0;
	while (charset[count])
	{
		if (check == charset[count])
			return (1);
		count++;
	}
	return (0);
}

int	get_split_length(char *str, char *charset, int count)
{
	int	len;

	len = 0;
	if (str[count] == '\0')
		return (0);
	while (str[count] && !is_separator(str[count + len], charset)
		&& str[count + len])
		len++;
	return (len);
}

int	get_split_count(char *str, char *charset)
{
	int	result;
	int	count;
	int	len;
	int	is_sep;

	count = 0;
	result = 0;
	is_sep = 1;
	while (str[count])
	{
		if (is_sep)
		{
			len = get_split_length(str, charset, count);
			if (len > 0)
				result++;
			count += len;
		}
		is_sep = is_separator(str[count++], charset);
	}
	return (result);
}

char	**try_split(char **result, char *str, char *charset)
{
	int		len;
	int		copy_index;
	int		index;
	int		count;
	int		is_sep;

	count = 0;
	index = 0;
	is_sep = 1;
	while (str[count])
	{
		len = get_split_length(str, charset, count);
		if (is_sep && len > 0)
		{
			copy_index = 0;
			result[index] = malloc(len + 1);
			if (!result[index])
				return (0);
			while (copy_index < len)
				result[index][copy_index++] = str[count++];
			result[index++][copy_index] = 0;
		}
		is_sep = is_separator(str[count++], charset);
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**result;

	word_count = get_split_count(str, charset);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (0);
	if (try_split(result, str, charset) == 0)
		return (0);
	result[word_count] = malloc(1);
	result[word_count][0] = 0;
	return (result);
}
