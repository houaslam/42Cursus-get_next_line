/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:41:51 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/20 20:35:29 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *save, char *buf)
{
	free(save);
	free(buf);
	return (NULL);
}

char	*after(char *buf)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	res = (char *)malloc(ft_strlen(buf) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (buf[i])
	{
		res[j] = buf[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_handle(char *buf)
{
	char	*res;
	int		i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	res = (char *)malloc(i + 1);
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
	save = (char *)malloc(BUFFER_SIZE + 1);
	if (!save)
		return (NULL);
	while (ft_strchr(buf) == 0 && i != 0)
	{
		i = read(fd, save, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(save, buf));
		if (i == 0)
			break ;
		save[i] = '\0';
		buf = ft_strjoin(buf, save);
	}
	if (save[0])
		free(save);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_check(buf, fd);
	if (!str || !str[0])
	{
		free(buf);
		return (NULL);
	}
	buf = after(str);
	line = ft_handle(str);
	free(str);
	return (line);
}
