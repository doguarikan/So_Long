/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:38:58 by darikan           #+#    #+#             */
/*   Updated: 2023/10/28 11:47:54 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (0);
	}
	while ((i < size - 1) && str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	return (((unsigned char)str1[i] - (unsigned char)str2[i]));
}
