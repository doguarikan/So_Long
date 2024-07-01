/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:28:13 by darikan           #+#    #+#             */
/*   Updated: 2023/10/28 12:13:14 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t maxlen)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (tofind[0] == '\0' || tofind == str)
		return ((char *)(str));
	while ((str[i]))
	{
		j = 0;
		while (str[i + j] == tofind[j] && ((i + j) < maxlen))
		{
			if (str[j + i] == '\0' && tofind[j] == '\0')
				return ((char *)(str + i));
			j++;
		}
		if (tofind[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
