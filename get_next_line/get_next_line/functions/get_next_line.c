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

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


int		custom_len(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
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
	destination[i] = '\0';
	return (dst);
}

void	*after_n_memcpy(char *dst, char *src, size_t n)
{
	unsigned	int		i;
//	unsigned	int		j;
	unsigned	char	*destination;
	unsigned	char	*sorce;

	destination = (unsigned char *)dst;
	sorce = (unsigned char *)src;
	i = 0;
//	j = 0;
	while (*sorce != '\n')
	{
		sorce++;
	}
	sorce++;
	while (i < n && (dst != (void *)0 || src != (void *)0))
	{
		destination[i] = sorce[i];
		i++;
	}
	destination[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
//	if (!s1 || !s2)
//		return (0);
	new_str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
	* sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

typedef struct	s_memory
{
	int len;
	char left[BUFFER_SIZE + 1];
	char *collect;
	
}				t_memory;

int		find_line(char *buff, char **line) //t_memory memory
{
	
	int len_substr = 0;
	while (buff[len_substr])
	{
		if (buff[len_substr] == '\n')
		{
			*line = malloc((len_substr + 1) * sizeof(char));
			if (*line == NULL)
				return (0);
			*line = ft_memcpy(*line, buff, len_substr);
			return (1);
		}
		len_substr++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_memory memory = {.len = 0};
	char *buff;
	int res;
	int buff_s = BUFFER_SIZE;
	res = 1;
	buff = malloc((buff_s + 1) * sizeof(char));
	*line = NULL;
	int i = 0;
	while ( res > 0)
	{
		
		if (!*(memory.left) && i == 0)
		{
			res = (int)read(fd, buff, BUFFER_SIZE);
			memory.collect = ft_strjoin(memory.left, buff);
		}
		else
		{
			if (i == 0)
			{
				ft_memcpy(buff, memory.left, buff_s);
				ft_memcpy(memory.collect, memory.left, ft_strlen(memory.left));
			}
			else
			{
				res = (int)read(fd, buff, BUFFER_SIZE);
				memory.collect = ft_strjoin(memory.collect, buff);
			}
		}
		if (memory.collect != NULL && find_line(memory.collect, line) == 1)
		{
			after_n_memcpy(memory.left, buff, BUFFER_SIZE);
			memory.left[ft_strlen(memory.left)] = '\0';
			return (1);
		}
//		buff_s += buff_s;
		i++;
	}
	return (0);
}











//working but not really
//typedef struct	s_memory
//{
//	char str_read[BUFFER_SIZE + 1];
//	int len_already_read;
//}				t_memory;
//
//
//int		get_next_line(int fd, char **line)
//{
//	static t_memory memory = {.len_already_read = 0};
//	char *buff;
//	char *old_buff;
//	int res;
//	int len;
//	char *start;
//	char *next_start;
//	int check = 0;
//
//	int sbstr_len = 0;
//	start = 0;
//	len = BUFFER_SIZE * 2;
//	buff = malloc((len + 1) * sizeof(char));
//	if (buff == NULL)
//		return (0);
//	my_memcpy(buff, memory.str_read, memory.len_already_read);
//	start = buff + memory.len_already_read;
//	while (1)
//	{
//		if (start + BUFFER_SIZE > buff + len)
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
//		res = (int)read(fd, start, BUFFER_SIZE);
//		if (res == -1)
//			{
//				*line = NULL;
//				free(buff);
//				return (-1);
//			}
//		check = custom_len(buff);
//		if (res == 0 && check < 1)
//		{
//			*line = NULL;
//			return (0);
//		}
//		if (res < BUFFER_SIZE )
//		{
//			while (*buff && sbstr_len <= check)
//			{
////				sbstr_len = custom_len(buff);
//				if (buff[sbstr_len] == '\n' && buff[sbstr_len]) //if str has \n
//				{
//					*line = malloc((sbstr_len + 1) * sizeof(char));
//					if (*line == NULL)
//							return (0);
//					*line = my_memcpy(*line, buff, sbstr_len);
//					my_memcpy(memory.str_read, buff + sbstr_len + 1, BUFFER_SIZE - sbstr_len);
//					return (1);
//				}
//				sbstr_len++;
//			}
//
//			start[res] = '\0';
//			*line = buff;
//			my_memcpy(memory.str_read, buff + sbstr_len + 1, BUFFER_SIZE - sbstr_len);
//			return (1);
//		}
//		next_start = start + BUFFER_SIZE;
//		while (start < next_start)
//		{
//			if (*start == '\n')
//			{
//				*line = buff;
//				*start = '\0';
//				memory.len_already_read	= (int)(next_start - start - 1);
//				my_memcpy(memory.str_read, start + 1, memory.len_already_read);
//				return (1);
//			}
//			start++;
//		}
//	}
//
//
//	return (0);
//}






//typedef struct	s_list
//{
//	struct	s_list *next;
//	int		len;
//	int		start;
//	int		fd;
//	char 	buff[BUFFER_SIZE];
//}				t_list;



//typedef struct	s_memory
//{
//	int len;
//	char str[BUFFER_SIZE + 1];
//}				t_memory;
//
//int		get_next_line(int fd, char **line)
//{
//	static t_memory memory = {.len = 0};
//	char *buff;
//
////	int buff_size = BUFFER_SIZE;
//	int sbstr_len = 0;
//	int res = 1;
//	*line = NULL;
//
//	while (res > 0)
//	{
//		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
//		if (buff == NULL)
//			return (0);
//
//		if (!*memory.str) //if str is already empty - read further
//		{
//			res = (int)read(fd, buff, BUFFER_SIZE);
//			if (res == 0)
//				return (0);
//			my_memcpy(memory.str, buff, BUFFER_SIZE);
//		}
//		else //or str has \n or does not
//		{
//			buff = my_memcpy(buff, memory.str, BUFFER_SIZE);
//		}
//		while (1) //condition is stupid (memory.len < BUFFER_SIZE) wtf
//		{
//			if (buff[sbstr_len] == '\n' && buff[sbstr_len]) //if str has \n
//			{
//				*line = malloc((sbstr_len + 1) * sizeof(char));
//				if (*line == NULL)
//					return (0);
//				*line = my_memcpy(*line, buff, sbstr_len);
//				my_memcpy(memory.str, buff + sbstr_len + 1, BUFFER_SIZE - sbstr_len);
//				return (1);
//			}
////			else //if str has no \n I need to read again - give more malloc to buff? and break? //increase B_S
//			sbstr_len++;
//		}
//	}
//	return (0);
//}


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










// working with a a a

//typedef struct	s_memory
//{
//	int len;
//	char str[BUFFER_SIZE + 1];
//}				t_memory;
//
//int		get_next_line(int fd, char **line)
//{
//	static t_memory memory = {.len = 0};
//	static char str[BUFFER_SIZE + 1];
//	char *buff;
//
//	int sbstr_len = 0;
//	int res = 1;
//
//	while (res > 0)
//	{
//		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
//		if (buff == NULL)
//		{
//			return (0);
//		}
//		*line = NULL;
//
//		if (!*str) //if str is already empty - read further
//		{
//
//			res = (int)read(fd, buff, BUFFER_SIZE);
//			if (res == 0)
//			{
//				return (0);
//			}
//			my_memcpy(str, buff, BUFFER_SIZE);
//		}
//		else //or str has \n or does not
//		{
//			buff = my_memcpy(buff, str, BUFFER_SIZE);
//		}
//		while (memory.len < BUFFER_SIZE)
//		{
//			if (buff[sbstr_len] == '\n' && buff[sbstr_len])
//			{
//				*line = malloc((sbstr_len + 1) * sizeof(char));
//				if (*line == NULL)
//				{
//					return (0);
//				}
//				*line = my_memcpy(*line, buff, sbstr_len);
//				my_memcpy(str, buff + sbstr_len + 1, BUFFER_SIZE - sbstr_len);
//				return (1);
//			}
//			sbstr_len++;
//		}
//	}
//	return (0);
//}










//buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
//if (buff == NULL)
//{
//	return (0);
//}
//*line = NULL;
//
//if (!*str) //if str is already empty - read further
//{
//
//	res = (int)read(fd, buff, BUFFER_SIZE);
//	my_memcpy(str, buff, BUFFER_SIZE);
//}
//else //or str has \n or does not
//{
//	buff = my_memcpy(buff, str, BUFFER_SIZE);
//}
//while (memory.len < BUFFER_SIZE)
//{
//	if (buff[sbstr_len] == '\n' && buff[sbstr_len])
//	{
//		*line = malloc((sbstr_len + 1) * sizeof(char));
//		if (*line == NULL)
//		{
//			return (0);
//		}
//		*line = my_memcpy(*line, buff, sbstr_len);
//		my_memcpy(str, buff + sbstr_len + 1, BUFFER_SIZE - sbstr_len);
//		return (1);
//	}
//	sbstr_len++;
//}











// working with long lines

//typedef struct	s_memory
//{
//	char already_read[BUFFER_SIZE];
//	int len_already_read;
//}				t_memory;
//static t_memory memory = {.len_already_read = 0};
//
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
//	len = BUFFER_SIZE * 2;
//	buff = malloc(len * sizeof(char));
//	if (buff == NULL)
//		return (0);
//	my_memcpy(buff, memory.already_read, memory.len_already_read);
//	start = buff + memory.len_already_read;
//	while (1)
//	{
//		if (start + BUFFER_SIZE > buff + len)
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
//				memory.len_already_read	= (int)(next_start - start - 1);
//				my_memcpy(memory.already_read, start + 1, memory.len_already_read);
//				return (1);
//			}
//			start++;
//		}
//	}
//
//
//	return (0);









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
