/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:24:56 by houaslam          #+#    #+#             */
/*   Updated: 2022/11/21 18:19:34 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#define BUFFER_SIZE	1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		ft_strchr(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char	*s2);
char	*ft_check(char *buf, int fd);
size_t	ft_strlen(char *str);
char	*ft_handle(char *buf);
char	*after(char *buf);

#endif