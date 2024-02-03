/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_text.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmin <junmin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:09:19 by junmin            #+#    #+#             */
/*   Updated: 2024/02/03 20:09:21 by junmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_TEXT_H
# define READ_TEXT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUF_SIZE 1
# define FAIL -1

int	try_read_txt(char **out, char *dir);

#endif
