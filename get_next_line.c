/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 19:26:25 by ********          #+#    #+#             */
/*   Updated: 2026/10/26 16:27:39 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_stack_data(char *stack)
{
	char	*result;
	int		i;

	i = 0;
	if (!stack)
		return (NULL);
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	if (stack[i] == '\0' || stack[i + 1] == '\0')
	{
		free(stack);
		return (NULL);
	}
	result = malloc(ft_strlen(stack) - i);
	if (result)
		ft_strlcpy(result, &stack[i + 1], ft_strlen(stack) - i);
	free(stack);
	return (result);
}

ssize_t	add_stack_data(int fd, char **stack)
{
	char	*buffer;
	ssize_t	n;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	n = read(fd, buffer, BUFFER_SIZE);
	if (n > 0)
	{
		buffer[n] = '\0';
		*stack = ft_strjoin(*stack, buffer);
		if (!*stack)
			n = -1;
	}
	free(buffer);
	return (n);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*stack;
	size_t		limit;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = 1;
	while (ft_strchr_stack(stack, '\n') == 0 && n > 0)
		n = add_stack_data(fd, &stack);
	if (n < 0 || !stack)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	limit = ft_strchr_stack(stack, '\n');
	limit = ft_strchr_stack(stack, '\n');
	if (limit == 0)
		limit = ft_strlen(stack);
	result = malloc(limit + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, stack, limit + 1);
	stack = clean_stack_data(stack);
	return (result);
}
