/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 09:44:24 by hgrissen          #+#    #+#             */
/*   Updated: 2019/12/19 09:55:06 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		outtil(int fd, char **rest, char **line)
{
	char *tmp;

	if (BUFFER_SIZE < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	*line = ft_strdup("");
	if (rest[fd] != '\0')
	{
		if (!linend(rest[fd]))
		{
			*line = ft_strjoin(*line, rest[fd]);
			rest[fd] = NULL;
		}
		else
		{
			*line = ft_strjoin(*line, ft_substr(rest[fd], 0,
				linend(rest[fd]) - rest[fd]));
			tmp = rest[fd];
			rest[fd] = ft_strdup(&rest[fd][linend(rest[fd]) - rest[fd] + 1]);
			free(tmp);
			return (1);
		}
	}
	return (2);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	char		*str;
	static char	*rest[1024];

	i = 0;
	if ((i = outtil(fd, rest, line)) < 2)
		return (i);
	str = (char *)malloc(BUFFER_SIZE + 1);
	while ((i = read(fd, str, BUFFER_SIZE)))
	{
		str[i] = '\0';
		if (!linend(str))
			*line = ft_strjoin(*line, str);
		else
		{
			*line = ft_strjoin(*line, ft_substr(str, 0, linend(str) - str));
			rest[fd] = ft_strdup(&str[linend(str) - str + 1]);
			free(str);
			return (1);
		}
		str = (char*)malloc(BUFFER_SIZE + 1);
	}
	free(str);
	return (0);
}
