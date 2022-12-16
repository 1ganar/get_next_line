/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:20:57 by mberrouk          #+#    #+#             */
/*   Updated: 2022/12/15 21:22:53 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char			*line;
	static char		*hold;
	int				index;
	int				len;
	char			*buf;

	buf = NULL;
	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(hold, '\n') == 1)
	{
		line = ft_get_line(hold, &index);
		hold = ft_trim(hold, index, ft_strlen(&hold[index]));
		return (line);
	}
	hold = ft_try2read(fd, hold, buf, &len);
	if (!hold)
		return (NULL);
	line = ft_get_line(hold, &index);
	hold = ft_trim(hold, index, (len - index));
	return (line);
}
