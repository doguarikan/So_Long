/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:33:52 by darikan           #+#    #+#             */
/*   Updated: 2023/10/25 18:26:39 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	str1len;
	size_t	totallen;
	char	*result;

	if (!str1 || !str2)
	{
		return (NULL);
	}
	str1len = ft_strlen(str1) + 1;
	totallen = str1len + ft_strlen(str2);
	result = (char *)malloc(totallen + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(result, str1, str1len);
	ft_strlcat(result, str2, totallen);
	return (result);
}
