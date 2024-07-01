/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:03:32 by darikan           #+#    #+#             */
/*   Updated: 2023/10/25 18:45:38 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	index;

	index = ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == (char)ch)
		{
			return ((char *)(str + index));
		}
		index--;
	}
	return (NULL);
}
