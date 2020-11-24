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
#include <stdio.h>

//Parameters 	#1. file descriptor for reading
//				#2. The value of what has been read

int	my_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}


int		custom_len(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}

void	*my_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned	int		i;
	unsigned	char	*destination;
	unsigned	char	*sorce;

	destination = (unsigned char *)dst;
	sorce = (unsigned char *)src;
	i = 0;
	while (i < n && (dst != (void *)0 || src != (void *)0))
	{
		destination[i] = sorce[i];
		i++;
	}
	return (dst);
}

char	*my_strjoin(char *s1, char *s2, unsigned int start)
{
	char			*join;
	unsigned int	index;
//	unsigned int	start;

	if (!s1 || !s2)
		return (0);
	index = 0;
	start = 0;
	join = malloc(sizeof(char) * (custom_len(s1) + custom_len(s2) + 1));
	if (!join)
		return (0);
	while (s1[index])
	{
		join[index] = s1[index];
		index++;
	}
	while (s2[start])
	{
		join[index] = s2[start];
		index++;
		start++;
	}
	join[index] = '\0';
	return (join);
}

typedef struct	s_memory
{
	char already_read[BUFFER_SIZE];
	int len_already_read;
}				t_memory;
static t_memory memory = {.len_already_read = 0};

int		get_next_line(int fd, char **line)
{
	char *buff;
	char *old_buff;
	int read_len;
	int len;
	char *start;
	char *next_start;

	start = 0;
	len = BUFFER_SIZE * 2;
	buff = malloc(len * sizeof(char));
	if (buff == NULL)
		return (0);
	my_memcpy(buff, memory.already_read, memory.len_already_read);
	start = buff + memory.len_already_read;
	while (1)
	{
		if (start + BUFFER_SIZE > buff + len)
		{
			old_buff = buff;
			len = len * 2;
			buff = malloc(len * sizeof(char));
			if (buff == NULL)
			{
				free(old_buff);
				return (0);
			}
			my_memcpy(buff, old_buff, len / 2);
			free(old_buff);
			start = buff + len / 2;
		}
		read_len = (int)read(fd, start, BUFFER_SIZE);
		if (read_len == -1)
		{
			*line = NULL;
			free(buff);
			return (-1);
		}
		if (read_len < BUFFER_SIZE)
		{
			start[read_len] = '\0';
			*line = buff;
			return (0);
		}
		next_start = start + BUFFER_SIZE;
		while (start < next_start)
		{
			if (*start == '\n')
			{
				*line = buff;
				*start = '\0';
				memory.len_already_read	= (int)(next_start - start - 1);
				my_memcpy(memory.already_read, start + 1, memory.len_already_read);
				////////// todo
				return (1);
			}
			start++;
		}
	}


	return (0);
}



//       READ
//Returns: How many bytes were actually read
//return Number of bytes read on success
//return 0 on reaching end of file
//return -1 on error
//return -1 on signal interrupt


// subject
//Return value 1 : A line has been read
//			   0 : EOF has been reached
//			  -1 : An error happened








//int		get_next_line(int fd, char **line)
//{
//	char *buff;
//	char *old_buff;
//	int read_len;
//	int len;
//	char *start;
//	char *next_start;
//
//	start = 0;
//	len = BUFFER_SIZE;
//	buff = malloc(len * sizeof(char));
//	if (buff == NULL)
//		return (0);
//	start = buff;
//	while (1)
//	{
//		if (start >= buff + len)
//		{
//			old_buff = buff;
//			len = len * 2;
//			buff = malloc(len * sizeof(char));
//			if (buff == NULL)
//			{
//				free(old_buff);
//				return (0);
//			}
//			my_memcpy(buff, old_buff, len / 2);
//			free(old_buff);
//			start = buff + len / 2;
//		}
//		read_len = (int)read(fd, start, BUFFER_SIZE);
//		if (read_len == -1)
//		{
//			*line = NULL;
//			free(buff);
//			return (-1);
//		}
//		if (read_len < BUFFER_SIZE)
//		{
//			start[read_len] = '\0';
//			*line = buff;
//			return (0);
//		}
//		next_start = start + BUFFER_SIZE;
//		while (start < next_start)
//		{
//			if (*start == '\n')
//			{
//				*line = buff;
//				*start = '\0';
//				////////// todo
//				return (1);
//			}
//			start++;
//		}
//	}
//
//
//	return (0);
//}











//int		get_next_line(int fd, char **line)
//{
//	int res = 0;
//	char *str = NULL;
//	char *temp = NULL;
//	int cnt = BUFFER_SIZE;
//
//	int len = 2;
//	int i = 1;
//	str = malloc((len + 1) * sizeof(char));
//	if (str == NULL)
//	{
//		return (0);
//	}
//
//	res = (int)read(fd, str, BUFFER_SIZE);
//	*line = str;
//	while (BUFFER_SIZE != 0)
//	{
//		if (res == -1)
//		{
//			free(str);
//			return (-1);
//		}
//		else if (res == 0)
//		{
//			free(str);
//			return (0);
//		}
//		else
//		{
//			i++;
//			if (i >= len)
//			{
//				str = *line;
//				len = len + 1;
//				temp = calloc(len, sizeof(char));
//				if (temp == NULL)
//					return (0);
//				str = my_memcpy(temp, str, len - 1);
//				str = *line + len - 1;
//			}
//			if ((unsigned char)*str == '\n')
//			{
//				len = custom_len(*line);
//				str = malloc(len * sizeof(char));
//				if (temp == NULL)
//					return (0);
//				my_memcpy(str, temp, len);
//				*line = str;
//				free(temp);
//				free(str);
//				return (1);
//			}
//		}
//		line++;
//	}
//	return (0);
//}
