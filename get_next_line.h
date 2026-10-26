/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 19:24:21 by ********          #+#    #+#             */
/*   Updated: 2026/10/25 02:27:29 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *dst, char *src);
char	*ft_strlcpy(char *dest, char *src, size_t size);
char	*get_next_line_bonus(int fd);

size_t	ft_strlen(char *s);
size_t	ft_strchr_stack(const char *s, int c);

#endif
