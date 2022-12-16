/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:43:41 by mberrouk          #+#    #+#             */
/*   Updated: 2022/11/26 01:35:12 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    char            *content;
    struct s_list   *next;
} t_list;

char *get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
void	ft_try2read(int fd, t_list **lst);
void 	ft_addbuf(t_list **lst, char *buf, int len);
char    *ft_trim(t_list **lst);
void    ft_clean(t_list **lst);
void	ft_lstclear(t_list **lst);
int ft_strlen(char *str);
int ft_is_line(t_list *list);

#endif