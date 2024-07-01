/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:51:14 by darikan           #+#    #+#             */
/*   Updated: 2023/10/27 21:02:04 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while ((*str != '\0') && (*str != (char)ch))
	{
		str++;
	}
	if (*str == (char)ch)
	{
		return ((char *)str);
	}
	return (NULL);
}
