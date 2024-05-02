/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:19:35 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/26 19:04:02 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*kast;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	kast = (char *)malloc((len + 1) * sizeof(char));
	if (!kast)
		return (NULL);
	while (s[start] && i < len)
	{
		kast[i++] = s[start++];
	}
	kast[i] = '\0';
	return (kast);
}
