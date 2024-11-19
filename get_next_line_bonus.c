/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:18:10 by moel-mes          #+#    #+#             */
/*   Updated: 2024/11/19 15:56:34 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*memory(char **line, int n)
{
	char	*tmp;
	int		l;

	l = ft_strlen(*line);
	tmp = ft_substr(*line, n, l + 1);
	free(*line);
	*line = NULL;
	return (tmp);
}

char	*the_line(char **line, int n)
{
	char	*tmp;

	tmp = ft_substr(*line, 0, n + 1);
	*line = memory(line, n + 1);
	return (tmp);
}

char	*read_line(int fd, char **line, char *buf)
{
	int		r;
	int		n;
	char	*last_line;

	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		*line = ft_strjoin(*line, buf);
		n = check_line(*line);
		if (n != -1)
			return (the_line(&(*line), n));
		r = read(fd, buf, BUFFER_SIZE);
	}
	if (*line && *line[0] != '\0' && r >= 0)
	{
		last_line = ft_strdup(*line);
		free(*line);
		*line = NULL;
		return (last_line);
	}
	free(*line);
	*line = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*buf;
	int			n;

	if (BUFFER_SIZE >= MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!line[fd])
		line[fd] = ft_strdup("");
	n = check_line(line[fd]);
	if (n != -1)
		return (the_line(&line[fd], n));
	return (read_line(fd, &line[fd], buf));
}

int	main(void)
{
	int fd1 = open("../tests/test.txt", O_RDONLY);
	int fd2 = open("../tests/test2.txt", O_RDONLY);
	printf("line 1:%s", get_next_line(fd1));
	printf("line 1:%s", get_next_line(fd2));
	printf("line 2:%s", get_next_line(fd1));
}