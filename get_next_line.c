/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:41:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/17 23:27:35 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*buf;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	// buf = (char *)malloc(BUFFER_SIZE + 1);
	// ret = read(fd, buf, BUFFER_SIZE);
	// if (ret == -1)
	// {
	// 	free(buf);
	// 	return 0;
	// }
	// buf[ret] = '\0';
	buf = ft_check(buf, fd);
	return (buf);
}

char	*ft_check(char *buf, int fd)
{
	char	*save;
	int		i;

	i = 0;
	save = (char *)malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buf, '\n') && *buf != '\0' && i!= 0)
	{
		i = read(fd, save, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(save);
			return 0;
		}
		save[i] = '\0';
		buf = ft_strjoin(buf, save);
	}
	ft_substr(buf, 0, ft_strlen(buf));
	return (buf);
}

