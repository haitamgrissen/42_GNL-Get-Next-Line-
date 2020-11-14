/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:05:00 by hgrissen          #+#    #+#             */
/*   Updated: 2019/12/19 10:06:55 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>

# include <stdlib.h>

# include <unistd.h>

int				outtil(int fd, char **rest, char **line);
int				get_next_line(int fd, char **line);
char			*linend(char		*str);
char			*ft_substr(char		*s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
int				ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);

#endif
