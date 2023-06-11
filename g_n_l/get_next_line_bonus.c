/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:17:19 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/11 17:45:55 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_line(int fd, char *line)
{
	char	*buff;
	int		rd_byt;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_byt = 1;
	while (!ft_strchr_g(line, '\n') && rd_byt != 0)
	{
		rd_byt = read(fd, buff, BUFFER_SIZE);
		if (rd_byt == -1)
		{
			if (line)
				free(line);
			free(buff);
			return (NULL);
		}
		buff[rd_byt] = '\0';
		line = ft_strjoin_g(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*ret_valu;
	static char	*line[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line[fd] = ft_read_to_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	ret_valu = ft_get_line(line[fd]);
	line[fd] = ft_new_line(line[fd]);
	return (ret_valu);
}
