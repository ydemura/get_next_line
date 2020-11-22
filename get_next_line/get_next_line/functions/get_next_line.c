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

int 	my_strlen(char *str)
{
	int i;
		
		i = 0;
		while (str[i])
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

int		get_next_line(int fd, char **line)
{
	int res = 0;
	static char *str = NULL;
	char *temp = NULL;
	int cnt = BUFFER_SIZE;
	
//	static data_type var_name = var_value;
	static char *counter;
	
	int len = 2;
	int i = 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
	{
		return (0);
	}
	
	res = (int)read(fd, str, cnt);
	counter = str;
	*line = counter;
	while (BUFFER_SIZE != 0)
	{
		if (res == -1)
		{
			free(str);
			return (-1);
		}
		else if (res == 0)
		{
			free(str);
			return (0);
		}
		else
		{
			i++;
			if (i >= len)
			{
				str = *line;
				len = len + 1;
				temp = calloc(len, sizeof(char));
				if (temp == NULL)
					return (0);
				str = my_memcpy(temp, str, len - 1);
				str = *line + len - 1;
			}
			if ((unsigned char)*str == '\n')
			{
				counter = my_memcpy(counter, (str + 1), my_strlen(str));
				len = custom_len(*line);
				str = malloc(len * sizeof(char));
				if (temp == NULL)
					return (0);
				my_memcpy(str, temp, len);
				*line = str;
				printf("counter:%p\n", counter);
				free(temp);
				free(str);
				return (0);
			}
		}
		cnt--;
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
