/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:20:57 by mberrouk          #+#    #+#             */
/*   Updated: 2022/12/15 21:24:44 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_try2read(int fd, char *hold, char *buf, int *len)
{
	int		getting;

	*len = ft_strlen(hold);
	getting = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (ft_strchr(buf, '\n') == 0 && getting > 0)
	{
		getting = read(fd, buf, BUFFER_SIZE);
		if (getting == -1)
		{
			if (hold)
				free(hold);
			free(buf);
			return (NULL);
		}
		buf[getting] = '\0';
		*len += getting;
		hold = ft_strjoin(hold, buf, *len);
	}
	free(buf);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char		*hold[OPEN_MAX];
	int				index;
	int				len;
	char			*line;
	char			*buf;

	buf = NULL;
	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (ft_strchr(hold[fd], '\n') == 1)
	{
		line = ft_get_line(hold[fd], &index);
		hold[fd] = ft_trim(hold[fd], index, ft_strlen(&(hold[fd][index])));
		return (line);
	}
	hold[fd] = ft_try2read(fd, hold[fd], buf, &len);
	if (!hold[fd])
		return (NULL);
	line = ft_get_line(hold[fd], &index);
	hold[fd] = ft_trim(hold[fd], index, (len - index));
	return (line);
}
