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

char	*ft_strdup_till_n(const char *s1, int len)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	after_n_memcpy(char *left, char *temp, unsigned int n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < n)
		i++;
	i++;
	while (temp[i] != '\0')
	{
		left[j] = temp[i];
		j++;
		i++;
	}
	left[j] = '\0';
}

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

int cut_line_and_left(char **line, t_memory *memory, int n, char *temp)
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
	return (0);
}

int	ft_search_end_of_line(char **line, t_memory *memory)
{
	char *temp;
	unsigned int n = 0;

	if (*line != NULL)
		temp = ft_strjoin(*line, memory->left);
	else
		temp = ft_strdup(memory->left);
	
	if (memory->counter != 0)
	{
		n = memory->counter;
	}
	if (cut_line_and_left(line, memory, n, temp) == 1)
	{
		memory->counter = 0;
		return (1);
	}
	memory->counter = n;
	return (0);
}

int		ft_read(int fd, t_memory *memory)
{
	memory->res = (int)read(fd, memory->left, BUFFER_SIZE);
	if (memory->res == -1)
		return (-1);
	memory->left[memory->res] = '\0';
	return (memory->res);
}

int		get_next_line(int fd, char **line)
{
	static 	t_memory memory = {.counter = 0, .res = 1};
	
	if (!fd || fd < 0)
		return (-1);
//	*line = NULL;
	
	while (memory.res > 0)
	{
		if (!*(memory.left))
		{
			if ((memory.res = ft_read(fd, &memory)) == -1)
				return (-1);
			if (memory.res == 0)
				*line = ft_strjoin(*line, memory.left);
		}
		else
		{
			if(ft_search_end_of_line(line, &memory) == 1)
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
