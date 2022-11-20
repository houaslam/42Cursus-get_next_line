/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:38:08 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/20 20:44:28 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;
	size_t	b;
	int		l;

	i = 0;
	j = 0;
	b = ft_strlen(s2);
	l = ft_strlen(s1);
	if (!s1 && s2)
		return (ft_strdup(s2));
	p = (char *)malloc(sizeof(char) * (l + b) + 1);
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

int	ft_strchr(const char *str)
{
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*s1;
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	s1 = malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	if (!s1)
		return (NULL);
	while (i < ft_strlen(s2))
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
