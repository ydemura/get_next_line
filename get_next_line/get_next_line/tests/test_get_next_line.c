//
//  test_get_next_line.c
//  get_next_line
//
//  Created by Yuliia Demura on 11/21/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//
 
 //                    ************* SUBJECT ***************

//Write a function which returns a line read from a file descriptor, without the newline.

//Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by moulinette.
//Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin.

//                  *******************************************



// https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/
//read: From the file indicated by the file descriptor fd, the read() function reads cnt bytes of input into the memory area indicated by buf. A successful read() updates the access time for the file.


//size_t read (int fd, void* buf, size_t cnt);

//#1. file descriptor for reading
//#2. The value of what has been read

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

//	fd: file descripter
//	buf: buffer to read data from
//	cnt: length of buffer
#include "test_get_next_line.h"
#include "get_next_line.h"

void	test_get_next_line(void)
{
	int fd;
	char *line;
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/normal.txt", O_RDONLY);
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/fewchar_perline.txt", O_RDONLY);

	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/64bit_line.txt", O_RDONLY);
	
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/64bit_paragraph.txt", O_RDONLY);

//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/empty.txt", O_RDONLY);

//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/fewchar_perline.txt", O_RDONLY);

//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/only_newline.txt", O_RDONLY);
	
	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/long_line.txt", O_RDONLY);
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/test_file.txt", O_RDONLY);
	
	if (fd == -1)
		printf("not opened\n");
	else
		printf(".......................opened\n");
	
	line = NULL;
	
	int res;
	res = 1;
	int i = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		printf("%i | line %i: %s\n",res, i, line);
		line = NULL;
//		free(line);
		i++;
	}


	if (close(fd) < 0)
		printf("not closed\n");
	else
		printf(".......................closed\n");
}


// KO IN LINE     FILE_NAME : test/fewchar_perline.txt                           BUFFER_SIZE : 1              OUT: "(null)"	EXPECTED : ""		 AT_LINE : 20

// here\n
//we\n
//have\n
//short\n
//strings\n
//0\n
//0\n
//0\n
//0\n
//0\n
//....


// ********************************************* HOME ********************************************* \\

//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/normal.txt", O_RDONLY);
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/fewchar_perline.txt", O_RDONLY);

	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/64bit_line.txt", O_RDONLY);
	
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/64bit_paragraph.txt", O_RDONLY);

//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/empty.txt", O_RDONLY);

//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/fewchar_perline.txt", O_RDONLY);

//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/only_newline.txt", O_RDONLY);
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/long_line.txt", O_RDONLY);
	
//	fd = open("/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/test_file.txt", O_RDONLY);

// *****************************************************************************************************




// ******************************************************************** \\
//   						OLD VERSIONS
// ******************************************************************** \\


///* ************************************************************************** */
///*                                                                            */
///*                                                        ::::::::            */
///*   get_next_line.c                                    :+:    :+:            */
///*                                                     +:+                    */
///*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
///*                                                   +#+                      */
///*   Created: 2020/11/21 13:12:43 by ydemura       #+#    #+#                 */
///*   Updated: 2020/11/21 13:12:49 by ydemura       ########   odam.nl         */
///*                                                                            */
///* ************************************************************************** */
//
//#include "get_next_line.h"
//
//typedef struct s_memory
//{
//	char left[BUFFER_SIZE + 1];
//	unsigned int counter;
//	int res;
//
//} t_memory;
//
//char	*ft_strdup(const char *s1)
//{
//	int		len;
//	int		i;
//	char	*s2;
//
//	i = 0;
//	len = 0;
//	while (s1[len] != '\0')
//	{
//		len++;
//	}
//	s2 = (char *)malloc((len + 1) * sizeof(char));
//	if (s2 == NULL)
//	{
//		return (NULL);
//	}
//	while (s1[i] != '\0')
//	{
//		s2[i] = s1[i];
//		i++;
//	}
//	s2[i] = '\0';
//	return (s2);
//}
//
//char	*ft_strdup_till_n(const char *s1, int len)
//{
//	int		i;
//	char	*s2;
//
//	i = 0;
//	s2 = (char *)malloc((len + 1) * sizeof(char));
//	if (s2 == NULL)
//	{
//		return (NULL);
//	}
//	while (i < len)
//	{
//		s2[i] = s1[i];
//		i++;
//	}
//	s2[i] = '\0';
//	return (s2);
//}
//
//void	after_n_memcpy(char *left, char *temp, unsigned int n)
//{
//	unsigned int i;
//	unsigned int j;
//
//	i = 0;
//	j = 0;
//	while (i < n)
//	{
//		i++;
//	}
//	i++;
//	while (temp[i] != '\0')
//	{
//		left[j] = temp[i];
//		j++;
//		i++;
//	}
//	left[j] = '\0';
//}
//
////int	ft_search_end_of_line(char **line, t_memory *memory)
////{
////	char *temp;
////	unsigned int n = 0;
////
////	if (line != NULL)
////		temp = ft_strjoin(*line, memory->left);
////	else
////		temp = ft_strdup(memory->left);
////
//////	n = memory->counter;
////	while (temp[n] != '\0')
////	{
////		if (temp[n] == '\n')
////		{
////			*line = ft_strdup_till_n(temp, n);
////			after_n_memcpy(memory->left, temp, n);
////			free(temp);
////			return (1);
////		}
////		n++;
////	}
////	memory->counter = n;
////	return (0);
////}
//
//void	clean_string(t_memory *memory)
//{
//	int len;
//	int i;
//
//	len = ft_strlen(memory->left);
//	i = 0;
//
//	while (i < len)
//	{
//		(memory->left)[i] = '\0';
//		i++;
//	}
//}
//
//int cut_line_and_left(char **line, t_memory *memory, int n, char *temp)
//{
//	while (temp[n] != '\0')
//	{
//		if (temp[n] == '\n')
//		{
//			*line = ft_strdup_till_n(temp, n);
//			after_n_memcpy(memory->left, temp, n);
//			free(temp);
//			return (1);
//		}
//		n++;
//	}
//	return (0);
//}
//
//int	ft_search_end_of_line(char **line, t_memory *memory)
//{
//	char *temp;
//	unsigned int n = 0;
//
//	if (*line != NULL)
//		temp = ft_strjoin(*line, memory->left); // put into temp slow down a lot
//	else
//		temp = ft_strdup(memory->left);
//
//	if (memory->counter != 0)
//	{
//		n = memory->counter;
//	}
//	if (cut_line_and_left(line, memory, n, temp) == 1)
//	{
//		memory->counter = 0;
//		return (1);
//	}
//	memory->counter = n;
//	return (0);
//}
//
//int		ft_read(int fd, t_memory *memory)
//{
//	memory->res = (int)read(fd, memory->left, BUFFER_SIZE);
//	if (memory->res == -1)
//		return (-1);
//	memory->left[memory->res] = '\0';
//	return (memory->res);
//}
//
//int		get_next_line(int fd, char **line)
//{
//	static 	t_memory memory = {.counter = 0, .res = 1};
//
//	if (!fd || fd < 0)
//		return (-1);
////	*line = NULL;
//
//	while (memory.res > 0)
//	{
//		if (!*(memory.left))
//		{
//			if ((memory.res = ft_read(fd, &memory)) == -1)
//				return (-1);
//			if (memory.res == 0)
//			{
//				*line = ft_strjoin(*line, memory.left);
//			}
//
//		}
//		else
//		{
//			if(ft_search_end_of_line(line, &memory) == 1)
//			{
//				return (1);
//			}
//			else
//			{
//				*line = ft_strjoin(*line, memory.left);
//				clean_string(&memory);
//			}
//		}
//	}
//	return (0);
//}
//
//
//
//
//
//
//
//
////typedef struct s_memory
////{
////	char left[BUFFER_SIZE + 1];
////	unsigned int counter;
////	int res;
////
////} t_memory;
////
////
////char	*ft_strdup(const char *s1)
////{
////	int		len;
////	int		i;
////	char	*s2;
////
////	i = 0;
////	len = 0;
////	while (s1[len] != '\0')
////	{
////		len++;
////	}
////	s2 = (char *)malloc((len + 1) * sizeof(char));
////	if (s2 == NULL)
////	{
////		return (NULL);
////	}
////	while (s1[i] != '\0')
////	{
////		s2[i] = s1[i];
////		i++;
////	}
////	s2[i] = '\0';
////	return (s2);
////}
////
////
////char	*ft_strdup_till_n(const char *s1, int len)
////{
////	int		i;
////	char	*s2;
////
////	i = 0;
////	s2 = (char *)malloc((len + 1) * sizeof(char));
////	if (s2 == NULL)
////	{
////		return (NULL);
////	}
////	while (i < len)
////	{
////		s2[i] = s1[i];
////		i++;
////	}
////	s2[i] = '\0';
////	return (s2);
////}
////
////
////
////
////void	after_n_memcpy(char *left, char *temp, unsigned int n)
////{
////	unsigned int i;
////	unsigned int j;
////
////	i = 0;
////	j = 0;
//////	if (n == 0)
//////		n++;
////	while (i < n)
////	{
////		i++;
////	}
////	i++;
////	while (temp[i] != '\0')
////	{
////		left[j] = temp[i];
////		j++;
////		i++;
////	}
////	left[j] = '\0';
////}
////
////int	ft_search_end_of_line(char **line, char *left, unsigned int counter)
////{
////	char *temp;
////	unsigned int n = 0;
////
////	if (line != NULL)
////		temp = ft_strjoin(*line, left);
////	else
////		temp = ft_strdup(left);;
////
////	while (temp[n] != '\0')
////	{
////		if (temp[n] == '\n')
////		{
////			*line = ft_strdup_till_n(temp, n);
////			after_n_memcpy(left, temp, n);
////			free(temp);
////			return (1);
////		}
////		n++;
////	}
////	counter = n;
////	return (0);
////}
////
////void	clean_string(char *str)
////{
////	int len = ft_strlen(str);
////	int i = 0;
////	while (i < len)
////	{
////		str[i] = '\0';
////		i++;
////	}
////}
////
////int		ft_read(int fd, char *left, t_memory memory) //(int fd, char **line, char *left, t_memory memory)
////{
////	memory.res = (int)read(fd, left, BUFFER_SIZE);
////	if (memory.res == -1)
////		return (-1);
////	left[memory.res] = '\0';
////	return (memory.res);
////}
////
////
////int		get_next_line(int fd, char **line)
////{
////	static 	t_memory memory = {.counter = 0, .res = 1};
////
////	if (!fd || fd < 0)
////		return (-1);
////	*line = NULL;
////
////	while (memory.res > 0)
////	{
////		if (!*(memory.left))
////		{
////			if ((memory.res = ft_read(fd, memory.left, memory)) == -1)
////				return (-1);
////			if (memory.res == 0)
////			{
////				*line = ft_strjoin(*line, memory.left); //needed if no '\n' in last line
////			}
////		}
////		else
////		{
////			if(ft_search_end_of_line(line, memory.left, memory.counter) == 1)
////			{
////				return (1);
////			}
////			else
////			{
////				*line = ft_strjoin(*line, memory.left);
////				clean_string(memory.left);
////			}
////		}
////	}
////
////	return (0);
////}
////
//
//

//
//
//// ******************************************************************** \\
////faining on tests with many \n\n\n need to rewrite hardly
//// ******************************************************************** \\
//
//
//
//
////int		find_copy_line(char *str, char **line, char *left)
////{
////	int len_substr;
////
////	len_substr = 0;
////	while (str[len_substr])
////	{
////		if (str[len_substr] == '\n')
////		{
////			*line = ft_strdup_till_n(str, len_substr);
////			after_n_memcpy(left, str, BUFFER_SIZE);
////			free(str);
////			return (1);
////		}
////		len_substr++;
////	}
////	return (0);
////}
//
////char	*update_temp(char *temp, const char *buff, const char *left)
////{
////	char *updated_temp;
////
////	updated_temp = NULL;
////	if (temp)
////	{
////		updated_temp = ft_strjoin(temp, buff);
////		free(temp);
////	}
////	else
////		updated_temp = ft_strjoin(left, buff);
////	return (updated_temp);
////}
//
//
////char	*malloc_it(size_t buff_s)
////{
////	char *str;
////
////	str = malloc((buff_s + 1) * sizeof(char));
////	if (!str)
////		return (0);
////	return (str);
////}
//
//
//
////void	*after_n_memcpy(char *dst, char *src, size_t n)
////{
////	unsigned	int		i;
////	unsigned	char	*destination;
////	unsigned	char	*sorce;
////
////	destination = (unsigned char *)dst;
////	sorce = (unsigned char *)src;
////	i = 0;
////	while (*sorce != '\n')
////	{
////		sorce++;
////	}
////	sorce++;
////	while (i < n && (dst != (void *)0 || src != (void *)0))
////	{
////		destination[i] = sorce[i];
////		i++;
////	}
////	destination[i] = '\0';
////	return (dst);
////}
////
////char	*ft_strdup_till_n(const char *s1, int len)
////{
////	int		i;
////	char	*s2;
////
////	i = 0;
////	s2 = (char *)malloc((len + 1) * sizeof(char));
////	if (s2 == NULL)
////	{
////		return (NULL);
////	}
////	while (i < len)
////	{
////		s2[i] = s1[i];
////		i++;
////	}
////	s2[i] = '\0';
////	return (s2);
////}
////
////int		find_copy_line(char *str, char **line, char *left)
////{
////	int len_substr;
////
////	len_substr = 0;
////	while (str[len_substr])
////	{
////		if (str[len_substr] == '\n')
////		{
////			*line = ft_strdup_till_n(str, len_substr);
////			after_n_memcpy(left, str, BUFFER_SIZE);
////			free(str);
////			return (1);
////		}
////		len_substr++;
////	}
////	return (0);
////}
////
////char	*update_temp(char *temp, const char *buff, const char *left)
////{
////	char *updated_temp;
////
////	updated_temp = NULL;
////	if (temp)
////	{
////		updated_temp = ft_strjoin(temp, buff);
////		free(temp);
////	}
////	else
////		updated_temp = ft_strjoin(left, buff);
////	return (updated_temp);
////}
////
////
////char	*malloc_it(size_t buff_s)
////{
////	char *str;
////
////	str = malloc((buff_s + 1) * sizeof(char));
////	if (!str)
////		return (0);
////	return (str);
////}
////
////int		get_next_line(int fd, char **line)
////{
////	static char		left[BUFFER_SIZE + 1];
////	char			*buff;
////	int				res;
////	char			*incompete_line;
////
////	if (fd < 0 || !fd)
////		return(-1);
////	buff = malloc_it(BUFFER_SIZE);
////	res = 1;
////	incompete_line = NULL;
////	*line = NULL;
////	while (res > 0)
////	{
////		res = (int)read(fd, buff, BUFFER_SIZE);
////		buff[res] = '\0';
////		if (!*left && !incompete_line)
////			incompete_line = ft_strdup(buff);
////		else
////			incompete_line = update_temp(incompete_line, buff, left);
////		if (find_copy_line(incompete_line, line, left) == 1)
////		{
//////			after_n_memcpy(left, incompete_line, BUFFER_SIZE);
//////			free(incompete_line);
////			return (1);
////		}
////	}
////	return (0);
////}
//
//
//
//
//
//// ******************************************************************** \\
//// working but buff cannot be on stack (BUFF_SIZE 10.000.000 crashes it)
//// ******************************************************************** \\
//
////int		get_next_line(int fd, char **line)
////{
////	static char		left[BUFFER_SIZE + 1];
////	char			buff[BUFFER_SIZE + 1];
////	int				res;
////	char			*incompete_line;
////
////	if (fd < 0)
////		return(-1);
////	res = 1;
////	incompete_line = NULL;
////	*line = NULL;
////	while (res > 0)
////	{
////		res = (int)read(fd, buff, BUFFER_SIZE);
////		buff[res] = '\0';
////		if (!*left && !incompete_line)
////			incompete_line = ft_strdup(buff);
////		else
////			incompete_line = update_temp(incompete_line, buff, left);
////		if (find_copy_line(incompete_line, line) == 1)
////		{
////			after_n_memcpy(left, incompete_line, BUFFER_SIZE);
////			free(incompete_line);
////			return (1);
////		}
////	}
////	return (0);
////}
//
