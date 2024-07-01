/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:19:14 by darikan           #+#    #+#             */
/*   Updated: 2024/05/08 16:33:43 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_gstrlen(const char *str);
int		finder(const char *str);
char	*strjoin(char *line, char *bf);
char	*getbefore(char *str);
char	*getafter(char *str);
#endif