/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 06:10:51 by moel-mes          #+#    #+#             */
/*   Updated: 2024/11/17 06:21:50 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int end)
{
	char	*new_str;
	int		len;

	if (!s)
		return (NULL);
	len = end - start;
	if (len < 0)
		return (NULL);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s + start, len);
	return (new_str);
}

char	*ft_strcpy(char *s, const char *str, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*new_str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s, len + 1);
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		len1;
	int		len2;

	if (!s1)
		s1 = ft_strdup("");
	else if (!s2)
		s2 = ft_strdup("");
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ft_strcpy(new_str, s1, len1);
	ft_strcpy(new_str + len1, s2, len2);
	free(s1);
	return (new_str);
}
