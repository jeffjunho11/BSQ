/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changwpa <changwpa@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:00:08 by changwpa          #+#    #+#             */
/*   Updated: 2024/01/31 23:00:13 by changwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUF_SIZE 1
#define FAIL -1

long long	check_size(char *dir)
{
	char	buf[BUF_SIZE];
	int		fd;
	int		ret;
	long	count;

	fd = open(dir, O_RDONLY);
	count = 0;
	if (fd < 0)
		return (FAIL);
	ret = read(fd, buf, BUF_SIZE);
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		count++;
	}
	close(fd);
	if (ret == FAIL)
		return (FAIL);
	return (count);
}

int	try_read_txt(char **out, char *dir)
{
	int		fd;
	int		ret;
	long	buff_size;

	buff_size = check_size(dir);
	if (buff_size == FAIL)
		return (0);
	fd = open(dir, O_RDONLY);
	*out = (char *)malloc(sizeof(char) * (buff_size));
	ret = read(fd, *out, buff_size);
	close(fd);
	if (ret == FAIL)
		return (0);
	return (1);
}
