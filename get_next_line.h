/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:09:07 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/17 23:33:58 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE -5
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_check(char *buf, int fd);
int		ft_cpy(char *src, char *dest);
size_t	ft_strlen(char *str);
char	*ft_substr(char const *buf, unsigned int ret, size_t k);
char	*ft_strdup(const char *s);
#endif