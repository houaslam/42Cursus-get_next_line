/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:38:08 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/17 23:33:50 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;
	size_t	b;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	b = strlen((char *)s2);
	p = (char *)malloc(sizeof(char) * (strlen((char *)s1) + b) + 1);
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i + j] = s2[j];
		j++;
	}
	free(s1);
	p[i + j] = '\0';
	return (p);
}

int	ft_strchr(const char *str, int c)
{
	int				i;
	char			*p;
	char			f;

	i = 0;
	if (!str)
		return 0;
	f = (char)c;
	p = (char *)str;
	while (p[i] != f)
	{
		if (p[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;
	size_t			k;

	if (!s)
		return (0);
	k = ft_strlen((char *)s);
	if (start > k)
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s + start))
		len = ft_strlen((char *)s + start);
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (NULL);
	while (i < len && start < k && s[i] != '\n')
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
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