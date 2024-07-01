/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:39:19 by darikan           #+#    #+#             */
/*   Updated: 2023/10/28 12:01:26 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t maxlen)
{
	size_t	i;
	size_t	j;
	size_t	destlen;

	j = 0;
	i = ft_strlen(dest);
	destlen = ft_strlen(dest);
	if (maxlen == 0 && !dest)
	{
		return (ft_strlen(src));
	}
	if (maxlen <= i)
	{
		return (maxlen + ft_strlen(src));
	}
	while ((i + 1 < maxlen) && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(src) + destlen);
}
