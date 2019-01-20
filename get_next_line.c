/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlahorba <vlahorba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:51:13 by vlahorba          #+#    #+#             */
/*   Updated: 2018/12/07 20:21:13 by vlahorba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "get_next_line.h"

int		read_thread_into_line(const int fd, char **line,
	char **thread, ssize_t read_bytes)
{
	char	*tmp;
	int		length;

	length = 0;
	while (thread[fd][length] != '\0' && thread[fd][length] != '\n')
		length++;
	if (thread[fd][length] == '\n')
	{
		*line = ft_strsub(thread[fd], 0, length);
		tmp = ft_strdup(thread[fd] + length + 1);
		free(thread[fd]);
		thread[fd] = tmp;
	}
	else if (thread[fd][length] == '\0')
	{
		if (read_bytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(thread[fd]);
		ft_strdel(&thread[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*nstr;
	ssize_t			read_bytes;
	static char		*thread[MAX_FD];
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || fd > MAX_FD || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (thread[fd] == NULL)
		thread[fd] = (char *)ft_memalloc(sizeof(char));
	while ((read_bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_bytes] = '\0';
		nstr = ft_strjoin(thread[fd], buff);
		free(thread[fd]);
		thread[fd] = nstr;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	if (read_bytes == 0 && (thread[fd] == NULL || thread[fd][0] == '\0'))
		return (0);
	return (read_thread_into_line(fd, line, thread, read_bytes));
  thread[fd] = (char *)ft_memalloc(sizeof(char));}
