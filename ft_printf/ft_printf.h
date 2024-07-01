/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:26:29 by darikan           #+#    #+#             */
/*   Updated: 2023/12/03 18:26:33 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_checker(va_list *p, char c, int *result);
void	ft_putnbr(int n, int *result);
void	ft_putstr(char *s, int *result);
void	ft_putchar(char c, int *result);
void	ft_putlhex(unsigned int n, int *result);
void	ft_putuhex(unsigned int n, int *result);
void	ft_putptr(unsigned long n, int *result);
void	ft_putunsigned(unsigned int n, int *result);
int		ft_printf(const char *s, ...);

#endif