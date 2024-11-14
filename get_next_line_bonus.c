/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:58:49 by moel-mes          #+#    #+#             */
/*   Updated: 2024/11/13 23:26:19 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(t_lst **list, int i)
{
	t_lst	*ln;
	t_lst	*cn;
	int		j;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	cn = malloc(sizeof(t_lst));
	if (!buff || !cn)
		return ;
	ln = find_last_node(*list);
	j = 0;
	while (ln->str_b[i] != '\0' && ln->str_b[i] != '\n')
		i++;
	while (ln->str_b[i] && ln->str_b[i + 1])
		buff[j++] = ln->str_b[++i];
	buff[j] = '\0';
	cn->str_b = buff;
	cn->next = NULL;
	dealloc(list, cn, buff);
}

char	*get_the_line(t_lst *list)
{
	int		len;
	char	*next_str;

	if (!list)
		return (NULL);
	len = len_to_newline(list);
	next_str = malloc(len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_lst **list, char *buff)
{
	t_lst	*nn;
	t_lst	*ln;

	ln = find_last_node(*list);
	nn = malloc(sizeof(t_lst));
	if (!nn)
		return ;
	if (!ln)
		*list = nn;
	else
		ln->next = nn;
	nn->str_b = buff;
	nn->next = NULL;
}

void	creat_list(t_lst **list, int fd)
{
	int		i;
	char	*buff;

	while (!f_newline(*list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buff);
			return ;
		}
		buff[i] = '\0';
		append(list, buff);
	}
}

char	*get_next_line(int fd)
{
	static t_lst	*list[1024] = {NULL};
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	if (!list[fd])
		creat_list(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	next_line = get_the_line(list[fd]);
	free_list(&list[fd], 0);
	if (!next_line)
		return (NULL);
	return (next_line);
}

// int	main(void)
// {
// 	char *line;
// 	int i;

// 	int fd1 = open("../tests/test.txt", O_RDONLY);
// 	int fd2 = open("../tests/test2.txt", O_RDONLY);
// 	int fd3 = open("../tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	line = get_next_line(fd3);
//     printf("line %d: %s\n", i++, line);
//     free(line);
// 	line = get_next_line(fd2);
//     printf("line %d: %s\n", i++, line);
//     free(line);
// 	line = get_next_line(fd3);
//     printf("line %d: %s\n", i++, line);
//     free(line);
// }
