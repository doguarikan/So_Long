/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:11:17 by darikan           #+#    #+#             */
/*   Updated: 2023/12/02 15:30:35 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuhex(unsigned int n, int *result)
{
	char	*a;

	a = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putuhex(n / 16, result);
		ft_putuhex(n % 16, result);
	}
	else
	{
		ft_putchar(a[n], result);
	}
}

void	ft_putptr(unsigned long n, int *result)
{
	char	*a;

	a = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putptr(n / 16, result);
		ft_putptr(n % 16, result);
	}
	else
	{
		ft_putchar(a[n], result);
	}
}
