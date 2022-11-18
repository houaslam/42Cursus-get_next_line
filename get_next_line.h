/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:09:07 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/18 20:38:02 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		ft_strchr(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char  *s2);
char	*ft_check(char *buf, int fd);
size_t	ft_strlen(char *str);
char	*ft_handle(char *buf);
char	*ft_strdup(const char *s);
char	*after(char *buf);
char	*ft_free(char *save, char *buf);

#endif