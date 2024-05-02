/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:16:00 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/26 19:00:18 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atoi(char *s)
{
	long	result;
	int		signe;
	int		i;

	i = 0;
	result = 0;
	signe = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if ((*s) == '-' || (*s) == '+')
	{
		signe = 1 - 2 * (*s++ == '-');
		i++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if (*s != '0' && *(s + 1) != '0')
			i++;
		if (i > 11)
			return (LONG_MAX);
		result = result * 10 + (*s++ - '0');
	}
	return (signe * result);
}
