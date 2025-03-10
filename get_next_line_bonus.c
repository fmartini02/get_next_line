/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:06:03 by francema          #+#    #+#             */
/*   Updated: 2025/03/10 19:23:08 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char *line)
{
	int		i;
	char	*ret;

	i = ft_strlen_char(line, '\n');
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*ft_get_surplus(char *line)
{
	int		i;
	char	*ret;

	i = ft_strlen_char(line, '\n');
	ret = NULL;
	if (line[i] == '\n')
		ret = malloc(sizeof(char) * (i + 2));
	else if (line[i] == '\0')
		ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*ft_fill_line(int fd, char *ret)
{
	int		r_bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r_bytes = 1;
	buf[0] = '\0';
	while ((!ft_strchr(buf, '\n') && r_bytes > 0))
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes <= 0)
		{
			free(buf);
			if (r_bytes == 0)
				return (ret);
			free(ret);
			return (NULL);
		}
		buf[r_bytes] = '\0';
		ret = ft_strjoin_free(ret, buf);
	}
	free(buf);
	return (ret);
}

char	*ft_update_line(char *line)
{
	int		i;
	char	*tmp;

	i = ft_strlen_char(line, '\n');
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	tmp = ft_strdup(&line[i + 1]);
	free(line);
	if (!tmp[0])
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line[MAX_FD];
	char		*ret;
	char		*tmp;
	int			i;

	ret = ft_strdup(NULL);
	tmp = ft_strdup(NULL);
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line[fd])
	{
		ret = get_next_line_utils(line, ret, tmp, fd);
		if (ret)
			return (ret);
	}
	if (!ret && !line[fd])
	{
		line[fd] = ft_fill_line(fd, line[fd]);
		if (!line[fd])
			return (NULL);
		ret = extract_line(line[fd]);
		line[fd] = ft_update_line(line[fd]);
	}
	return (ret);
}
