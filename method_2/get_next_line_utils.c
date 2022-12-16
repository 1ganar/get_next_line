/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:00:05 by mberrouk          #+#    #+#             */
/*   Updated: 2022/11/29 21:01:33 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    if (!str)
        return (0);
    while (str[len])
        len++;
    return len;   
}

t_list	*ft_lstlast(t_list *lst)
{
    t_list *last;
    
    last = lst;
    // if (!lst)
    //     return NULL;
	while (last)
	{
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	return (last);
}

int ft_is_line(t_list *list)
{
    t_list *last;
    int i;

    i = 0;
    if (!list)
        return (0);
    last = ft_lstlast(list);
    while (last && last->content[i] && last->content[i] != '\n')
        i++;
    if(last && last->content[i] == '\n')
        return (1);
    return (0);
}

void ft_addbuf(t_list **lst, char *buf, int len)
{
    t_list *new;
    t_list *last;
    int i;
    
    if (!buf || len <= 0)
        return ;
    new = malloc(sizeof(t_list));
    if (!new)
        return ;
    new->content = malloc(sizeof(char) * (len + 1));
    if (!new->content)
    {
        free(new);
        return ;
    }
    i = 0;
    while (buf[i])                // &&(i < len)
    {
        new->content[i] = buf[i];
        i++;
    }
    new->content[i] = '\0';
    new->next = NULL;
    if (!*lst)
        *lst = new;
    else
    {   
        last = ft_lstlast(*lst); 
        last->next = new;
    }
}

int ft_linelen(t_list *lst)
{
    t_list *tmp;
    int len;
    int i;
    
    len = 0;
    tmp = lst;
    if (!tmp)
        return len;
    while (tmp)             //&& lst->content
    {
        i = 0;
        while (tmp->content[i])
        {
            if (tmp->content[i] == '\n')
            {    
                len++;
                break ;
            }
            i++;
            len++;
        }
        tmp = tmp->next;
    }
    return len;
}

char *ft_trim(t_list **lst)
{
    int i;
    int y;
    t_list *tmp;
    char *line;
    
    y = 0;
    tmp = *lst;
    if (!tmp)
        return NULL;
    line = malloc(sizeof(char) * ft_linelen(tmp) + 1);
    if (!line)
        return NULL;
    while (tmp != NULL)
    {
        i = 0;
        while (tmp->content && tmp->content[i])
        {
            if (tmp->content[i] == '\n')
            {
                line[y] = tmp->content[i];
                y++;
                break ;
            }
            line[y] = tmp->content[i];
            i++;
            y++;

        }
        tmp = tmp->next;   
    }
    line[y] = '\0';
    return line;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
    t_list  *cur;

    cur = *lst;
	tmp = NULL;
	if (!lst || !*lst)
		return ;
	while (cur)
	{
		tmp = cur;
		free(cur->content);
        //cur->content = NULL;  // rm
 		cur = cur->next;
        free(tmp);
        tmp = NULL;  // rm
	}
}

void    ft_clean(t_list **lst)
{
    t_list *tmp;
    t_list *new;
    int i;
    int j;
    int size;
    
    if (!lst || !*lst)
        return;
    new = malloc(sizeof(t_list));
    if (!new)
        return ;
    tmp = *lst;
    tmp = ft_lstlast(tmp);
    i = 0;
    if (!tmp->content)
    {
        
        ft_lstclear(lst);
        free(new);
        return ; 
    }
    while(tmp->content[i] && tmp->content[i] != '\n')
        i++;
    if( tmp->content[i] == '\n')
        i++;
    size = ft_strlen(tmp->content) - i;
    new->content = malloc(sizeof(char) * (size + 1));
    if (!new->content)
        return ;
    j = 0;
    while (tmp->content[i + j])
    {
        new->content[j] = tmp->content[i + j];
        j++;
    }
    new->content[j] = '\0';
    new->next = NULL;
    ft_lstclear(lst);
    *lst = new;
}