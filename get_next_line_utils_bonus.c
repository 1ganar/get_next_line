/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:21:09 by mberrouk          #+#    #+#             */
/*   Updated: 2022/12/15 21:18:44 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	result = malloc (sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	if (s1)
		free(s1);
	return (result);
}

char	*ft_get_line(char *hold, int *i)
{
	char	*result;

	*i = 0;
	if (!hold || !hold[(*i)])
		return (NULL);
	while (hold[(*i)] && hold[(*i)] != '\n')
		(*i)++;
	if (hold[(*i)] == '\n')
		(*i)++;
	result = (char *)malloc(sizeof(char) * ((*i) + 1));
	if (!result)
		return (NULL);
	(*i) = 0;
	while (hold[(*i)] && hold[(*i)] != '\n')
	{
		result[(*i)] = hold[(*i)];
		(*i)++;
	}
	if (hold[(*i)] == '\n')
		result[(*i)++] = '\n';
	result[(*i)] = '\0';
	return (result);
}

char	*ft_trim(char *hold, int i, int len)
{
	int		y;
	char	*result;

	y = 0;
	if (!hold[i])
	{
		free(hold);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (hold[i])
		result[y++] = hold[i++];
	result[y] = '\0';
	free(hold);
	return (result);
}
