/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:13:38 by darikan           #+#    #+#             */
/*   Updated: 2023/10/30 22:33:04 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int var, size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = ptr;
	while (i < size)
	{
		a[i] = var;
		i++;
	}
	return (ptr);
}
