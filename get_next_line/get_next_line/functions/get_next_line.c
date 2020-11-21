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

static char *malloc_it(char *str, int len)
{
	char *new_str;
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
	{
		return (0);
	}
	int i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	//free(str);
	return (new_str);
}


int		get_next_line(int fd, char **line)
{
	size_t res = 0;
//	size_t len = 0;
	char *str = NULL;
	char *temp = NULL;
	
	int len = 1;
	int i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (0);
	}
	
	while ((res = read(fd, str, BUFFER_SIZE))) //if not error of EOF it is == 1(true)
	{
		*line = str;
		//printf("%s\n", str);
		//printf("%s", *line);
		if ((unsigned char)*line == '\n')
		{
			return ((int)res);
		}
		line++;
		str++;
		i++;
		if (i >= len)
		{
			len = len * 2;
			printf("%s\n", str);
			str[i] = '\0';
			temp = malloc_it(str, len);
			free(str);
			str = temp;
		}
	}
	
	return ((int)res);
}

//Return value 1 : A line has been read
//			   0 : EOF has been reached
//			  -1 : An error happened
