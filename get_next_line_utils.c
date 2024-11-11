/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:59:04 by moel-mes          #+#    #+#             */
/*   Updated: 2024/11/11 16:49:22 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*find_last_node(t_lst *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	f_newline(t_lst *list)
{
	long	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_b[i] && i < BUFFER_SIZE)
		{
			if (list->str_b[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	copy_str(t_lst *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_b[i])
		{
			if (list->str_b[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_b[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_newline(t_lst *list)
{
	int	len;
	int	i;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_b[i])
		{
			if (list->str_b[i] == '\n')
			{
				len++;
				return (len);
			}
			++len;
			++i;
		}
		list = list->next;
	}
	return (len);
}

void	dealloc(t_lst **list, t_lst *cn, char *buff)
{
	t_lst	*tp;

	if (!list)
		return ;
	while (*list)
	{
		tp = (*list)->next;
		free((*list)->str_b);
		free(*list);
		*list = tp;
	}
	*list = NULL;
	if (cn->str_b[0])
		*list = cn;
	else
	{
		free(buff);
		free(cn);
	}
}
