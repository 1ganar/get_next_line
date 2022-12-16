/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:42:44 by mberrouk          #+#    #+#             */
/*   Updated: 2022/11/29 21:44:44 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_try2read(int fd, t_list **lst)
{
    char *buf;
    int len;

    len = 1;
    while(ft_is_line(*lst) == 0 && len > 0)
    {
        buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buf)
            return ;
        len = read(fd, buf, BUFFER_SIZE);
        if ((!*lst && len == 0) || len == -1 || len == 0)  // || (len == 0)
        {
            // {
             if (len == -1)
                 if(*lst != NULL)
                     ft_clean(lst);
            // }
           //if (len == -1)
            //
            free(buf);
            return ; 
        }    
        //if (len <= 0)
            //return ;
        buf[len] = '\0';
        ft_addbuf(lst, buf, len);
        free(buf);
    }
}

char *get_next_line(int fd)
{
    static t_list  *lines;
    char *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)     // ||(read(fd, &line, 0) < 0)
    {
        // if (read(fd, &line, 0) < 0)
        //     return NULL;
        if (lines)
            ft_lstclear(&lines);
        return NULL;
    }
    line = NULL;
    ft_try2read(fd, &lines);
    line = ft_trim(&lines);
    if (line == NULL || line[0] == '\0')
	{
		ft_lstclear(&lines);
		lines = NULL;
        if (line == NULL)
		    return (NULL);
		else 
            free(line);
        return NULL;
	}
    //if (lines)
        ft_clean(&lines);
    return line;
}