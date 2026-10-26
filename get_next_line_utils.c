/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 15:38:18 by ********          #+#    #+#             */
/*   Updated: 2026/10/25 00:24:30 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strchr_stack(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && (s[i] != (unsigned char)c))
		i++;
	if (s[i] == (unsigned char)c)
		return (i + 1);
	return (0);
}

char	*ft_strjoin(char *dest, char *src)
{
	int		i;
	int		j;
	int		length;
	char	*result;

	i = 0;
	length = ft_strlen(dest) + ft_strlen(src);
	result = malloc(length + 1);
	if (!result)
	{
		free(dest);
		return (NULL);
	}
	while (dest && dest[i] != '\0')
	{
		result[i] = dest[i];
		i++;
	}
	j = i;
	i = 0;
	while (src[i] != '\0')
		result[j++] = src[i++];
	result[j] = '\0';
	free(dest);
	return (result);
}

char	*ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
