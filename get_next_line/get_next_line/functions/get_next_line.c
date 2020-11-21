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

void free_it(char *str)
{
	free(str);
}

static char *malloc_it(char *str, int len)
{
	free_it(str);
	str = malloc(len * sizeof(char));
	if (str == NULL)
	{
		return (0);
	}
	return (str);
}


int		get_next_line(int fd, char **line)
{
	size_t res = 0;
//	size_t len = 0;
	char *str = NULL;
	
	int len = 1;
	int i = 0;
	str = malloc_it(str, len);
	
	while ((res = read(fd, str, BUFFER_SIZE))) //if not error of EOF it is == 1(true)
	{
		*line = str;
		//printf("%s\n", str);
		//printf("%s", *line);
		if (i >= len)
		{
			len = len * 2;
			str = malloc_it(str, len);
		}
		if ((unsigned char)*line == '\n')
		{
			return ((int)res);
		}
		line++;
		str++;
		i++;
	}
	
	return ((int)res);
}

//Return value 1 : A line has been read
//			   0 : EOF has been reached
//			  -1 : An error happened
