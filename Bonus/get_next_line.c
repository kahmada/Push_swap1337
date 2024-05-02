/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:20:03 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/26 19:03:38 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*make_stock(char *str)
{
	int		i;
	char	*stock;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			stock = ft_strdup(str + i + 1);
			free(str);
			str = NULL;
			return (stock);
		}
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static char	*ft_extract(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (ft_substr(str, 0, i + 1));
}

static char	*read_from_fd(int fd, char **str)
{
	char	*buf;
	int		nbyt_read;
	int		nl_position;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nbyt_read = 1;
	while (nbyt_read)
	{
		nbyt_read = read(fd, buf, BUFFER_SIZE);
		if (nbyt_read < 0)
			return (free(*str), *str = NULL, NULL);
		buf[nbyt_read] = '\0';
		*str = ft_strjoin(*str, buf);
		nl_position = ft_check(buf);
		if (nl_position != -1)
			break ;
	}
	free(buf);
	buf = NULL;
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (free(str), str = NULL, NULL);
	str = read_from_fd(fd, &str);
	if (!str || !str[0])
		return (free(str), str = NULL, NULL);
	line = ft_extract(str);
	if (!line || !line[0])
		return (free(str), str = NULL, NULL);
	str = make_stock(str);
	return (line);
}
