/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:52:30 by moel-mes          #+#    #+#             */
/*   Updated: 2024/11/14 16:07:34 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

typedef struct s_list
{
	char			*str_b;
	struct s_list	*next;
}					t_lst;

void				append(t_lst **list, char *buff);
void				creat_list(t_lst **list, int fd);
char				*get_next_line(int fd);
char				*get_the_line(t_lst *list);
void				free_list(t_lst **list, int i);
t_lst				*find_last_node(t_lst *list);
int					f_newline(t_lst *list);
void				copy_str(t_lst *list, char *str);
int					len_to_newline(t_lst *list);
void				dealloc(t_lst **list, t_lst *cn, char *buff);

#endif
