/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:32:45 by darikan           #+#    #+#             */
/*   Updated: 2023/10/28 12:23:35 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t size)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)ptr;
	while (i < size)
	{
		if (a[i] == (unsigned char)ch)
		{
			return ((char *)ptr + i);
		}
		i++;
	}
	return (NULL);
}
