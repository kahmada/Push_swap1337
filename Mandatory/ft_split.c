/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:45:43 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/21 14:37:40 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sep(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

static int	count_w(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && check_sep(s[i]))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && !check_sep(s[i]))
			i++;
	}
	return (count);
}

static int	strlen_sep(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !check_sep(str[i]))
		i++;
	return (i);
}

static char	*fill_word(char *s)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = strlen_sep(s);
	word = malloc(len +1);
	while (s[i] && !check_sep(s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *)
			* (count_w(str) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && check_sep(*str))
			str++;
		if (*str != '\0')
		{
			strings[i] = fill_word(str);
			i++;
		}
		while (*str && !check_sep(*str))
			str++;
	}
	strings[i] = 0;
	return (strings);
}
