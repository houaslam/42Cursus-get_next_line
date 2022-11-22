/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:41:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/22 16:18:33 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*after(char *buf)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * 1 + ft_strlen(buf) - i);
	if (!res)
	{
		free(buf);
		return (NULL);
	}
	while (buf[i])
		res[j++] = buf[i++];
	res[j] = '\0';
	free(buf);
	return (res);
}

char	*ft_handle(char *buf)
{
	char	*res;
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	res = (char *)malloc(i + 1 * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		res[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_check(char *buf, int fd)
{
	char	*save;
	int		i;

	i = 1;
	save = (char *)malloc((BUFFER_SIZE * sizeof(char)) + sizeof(char));
	if (!save)
		return (NULL);
	while (ft_strchr(buf) == 0)
	{
		i = read(fd, save, BUFFER_SIZE);
		if (i == -1)
		{
			if (buf)
				free(buf);
			free(save);
			return (NULL);
		}
		if (i == 0)
			break ;
		save[i] = '\0';
		buf = ft_strjoin(buf, save);
	}
	free(save);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_check(buf[fd], fd);
	if (!buf[fd] || !buf[fd][0])
	{
		if (buf[fd])
			free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	line = ft_handle(buf[fd]);
	buf[fd] = after(buf[fd]);
	return (line);
}
