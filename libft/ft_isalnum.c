/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:59:40 by darikan           #+#    #+#             */
/*   Updated: 2023/10/22 17:28:19 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int input)
{
	if ((input <= 'z' && input >= 'a') || (input <= 'Z' && input >= 'A')
		|| (input <= '9' && input >= '0'))
	{
		return (1);
	}
	return (0);
}
