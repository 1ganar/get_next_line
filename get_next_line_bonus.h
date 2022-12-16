/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:21:23 by mberrouk          #+#    #+#             */
/*   Updated: 2022/12/15 21:25:01 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_try2read(int fd, char *hold, char *buf, int *len);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2, int len);
int		ft_strlen(char *str);
char	*ft_trim(char *hold, int i, int len);
char	*ft_get_line(char *hold, int *i);

#endif
