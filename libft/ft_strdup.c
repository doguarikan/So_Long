/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:34:15 by darikan           #+#    #+#             */
/*   Updated: 2023/10/28 12:14:23 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*sdup;

	len = ft_strlen(str);
	sdup = (char *)malloc(len * sizeof(char) + 1);
	if (sdup == NULL)
	{
		return (NULL);
	}
	ft_memcpy(sdup, str, len);
	sdup[len] = '\0';
	return (sdup);
}
