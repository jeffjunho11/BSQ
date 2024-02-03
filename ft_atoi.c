/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:38:17 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 21:06:20 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char check)
{
	if (check >= 9 && check <= 13)
		return (1);
	if (check == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str, int *index)
{
	int				result;
	int				sign;

	*index = 0;
	result = 0;
	sign = 1;
	while (ft_is_space(str[*index]) == 1)
		(*index)++;
	while (str[*index] == '-' || str[*index] == '+')
	{
		if (str[(*index)++] == '-')
			sign *= -1;
	}
	while (str[*index] != '\0')
	{
		if (str[*index] < '0' || str[*index] > '9')
			break ;
		result = result * 10 + str[*index] - '0';
		index++;
	}
	return (result * sign);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n",ft_atoi("123456789"));
// 	printf("%d\n",ft_atoi("2147483647"));
// 	printf("%d\n",ft_atoi("-2147483648"));
// 	printf("%d\n",ft_atoi("--+-+-++-123456"));
// 	return 0;
// }