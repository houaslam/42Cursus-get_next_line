/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bounus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:38:08 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/22 16:07:40 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	p = (char *)malloc(sizeof(char) * 1 + ft_strlen(s1) + ft_strlen(s2));
	if (!p)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

int	ft_strchr(char *str)
{
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
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
