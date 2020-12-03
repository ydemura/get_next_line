/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:43 by ydemura       #+#    #+#                 */
/*   Updated: 2020/11/21 13:12:49 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_string(t_memory *memory)
{
	int len;
	int i;

	len = ft_strlen(memory->left);
	i = 0;
	while (i < len)
	{
		(memory->left)[i] = '\0';
		i++;
	}
}

int		cut_line_and_left(char **line, t_memory *memory, int n, char *temp)
{
	while (temp[n] != '\0')
	{
		if (temp[n] == '\n')
		{
			*line = ft_strdup_till_n(temp, n);
			after_n_memcpy(memory->left, temp, n);
			free(temp);
			return (1);
		}
		n++;
	}
	memory->counter = n;
	free(temp);
	return (0);
}

int		ft_search_end_of_line(char **line, t_memory *memory)
{
	char			*temp;
	unsigned int	n;

	n = 0;
	if (*line != NULL)
		temp = ft_strjoin(*line, memory->left);
	else
		temp = ft_strdup(memory->left);
	if (memory->counter != 0)
		n = memory->counter - 1;
	if (cut_line_and_left(line, memory, n, temp) == 1)
	{
		memory->counter = 0;
		return (1);
	}
	return (0);
}

int		ft_read(int fd, t_memory *memory, char **line)
{
	memory->res = (int)read(fd, memory->left, BUFFER_SIZE);
	if (memory->res == -1)
		return (-1);
	memory->left[memory->res] = '\0';
	if (memory->res == 0)
		*line = ft_strjoin(*line, memory->left);
	return (memory->res);
}

int		get_next_line(int fd, char **line)
{
	static	t_memory memory;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	memory.res = 1;
	*line = NULL;
	while (memory.res > 0)
	{
		if (!*(memory.left))
		{
			if ((ft_read(fd, &memory, line)) == -1)
				return (-1);
		}
		else
		{
			if (ft_search_end_of_line(line, &memory) == 1)
				return (1);
			else
			{
				*line = ft_strjoin(*line, memory.left);
				clean_string(&memory);
			}
		}
	}
	return (0);
}
