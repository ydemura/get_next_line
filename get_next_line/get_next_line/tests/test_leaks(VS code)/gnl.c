/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:36 by ydemura       #+#    #+#                 */
/*   Updated: 2020/12/05 22:25:29 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

typedef struct		s_memory
{
	int				res;
	int				status;
	char			left[BUFFER_SIZE + 1];
}					t_memory;

void	after_n_memcpy(char *left, char *temp, unsigned int n)
{
	unsigned int j;

	n++;
	j = 0;
	while (temp[n] != '\0')
	{
		left[j] = temp[n];
		j++;
		n++;
	}
	left[j] = '\0';
}

int		return_management(char **line, t_memory *memory)
{
	if (memory->status == -1)
	{
		if (*line)
		{
			free(*line);
		}
		return (-1);
	}
	if (memory->status == 1)
	{
		// do I do smth with line here? split into left/line mb?
		return (1);
	}
	return (0);
}

char	*ft_realloc(char **line, int new_len, t_memory *memory)
{
	int len;
	char *new_line;
	
	len = ft_strlen(*line);
	if (!*line)
	{
		new_line = malloc(new_len + 1);
		if (!new_line)
			memory->status = -1;
		return (new_line);
	}
	new_line = malloc((new_len + 1) * sizeof(char));
	if (!new_line)
	{
		memory->status = -1;
	}
	return (new_line);
}

char	*ft_strjoin_realloc(char *line, t_memory *memory)
{
	char	*new_str;
//	char 	*temp;
	int		i;
	int		j;
	int new_len;
	
	new_len = ft_strlen(memory->left) + ft_strlen(line);
//	temp = malloc((new_len + 1) * sizeof(char));
	i = 0;
	j = 0;
	new_str = ft_realloc(&line, new_len, memory);
	if (!new_str)
		memory->status = -1;
	while (line != 0 && line[i] != '\0')
	{
		new_str[i] = line[i];
		i++;
	}
	while (*(memory->left) != 0 && memory->left[j] != '\0')
	{
		new_str[i] = memory->left[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	free(line);
	return (new_str);
}

int		cut_line_and_left(char **line, t_memory *memory, char *temp)
{
	int n;
	
	n = 0;
	while (temp[n] != '\0')
	{
		if (temp[n] == '\n')
		{
			*line = ft_strdup_till_n(temp, n);
			if (!*line)
				memory->status = -1;
			after_n_memcpy(memory->left, temp, n);
			return (1);
		}
		n++;
	}
	return (0);
}

int		find_cut_new_line(t_memory *memory, char **line)
{
	char *temp;
	
	temp = ft_strjoin_realloc(*line, memory);
	if (memory->status == -1)
	{
		free(temp);
		return (-1);
	}
	if (cut_line_and_left(line, memory, temp) == 1)
	{
		if (temp != 0)
		free(temp);
		memory->status = 1;
		return (1);
	}
	*line = ft_strdup_till_n(temp, ft_strlen(temp));
	free(temp);
	if (!line)
		memory->status = -1;
	*(memory->left) = '\0';
	return (0);
}

int		ft_read(int fd, t_memory *memory, char **line) //int fd, t_memory *memory, char **line
{
	memory->res = (int)read(fd, memory->left, BUFFER_SIZE);
	if (memory->res == -1)
	{
		memory->status = -1;
		return (-1);
	}
	if (memory->res == 0)
	{
		memory->left[memory->res] = '\0';
//		*line = ft_strdup_till_n(memory->left, ft_strlen(memory->left));
		*line = ft_strjoin_realloc(*line, memory);
		if (!line)
			memory->status = -1;
	}
	memory->left[memory->res] = '\0';
	return (memory->res);
}

int		get_next_line(int fd, char **line)
{
	static	t_memory memory;
	
	memory.res = 1;
	memory.status = 0;
	*line = NULL;
	while (memory.res > 0)
	{
		if (*(memory.left))
		{
			find_cut_new_line(&memory, line);
			if (memory.status == 1 || memory.status == -1)
				return (return_management(line, &memory));
		}
		else if ((ft_read(fd, &memory, line)) < 0) //((ft_read(fd, &memory, line)) < 0)
		{
			return (return_management(line, &memory));
		}
	}
	return (return_management(line, &memory));
}
