/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 06:10:54 by moel-mes          #+#    #+#             */
/*   Updated: 2024/11/19 02:06:29 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAX 2147483647

char	*ft_substr(char *s, int start, int end);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *s, const char *str, int len);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);

#endif