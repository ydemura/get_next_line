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


typedef struct s_memory
{
	char left[BUFFER_SIZE + 1];
	unsigned int counter;
	int res;
	
} t_memory;


char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s2;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}


char	*ft_strdup_till_n(const char *s1, int len)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
	{
		return (NULL);
	}
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
	{
		i++;
	}
	i++;
	while (temp[i] != '\0')
	{
		left[j] = temp[i];
		j++;
		i++;
	}
	left[j] = '\0';
}

//int	ft_search_end_of_line(char **line, t_memory *memory)
//{
//	char *temp;
//	unsigned int n = 0;
//
//	if (line != NULL)
//		temp = ft_strjoin(*line, memory->left);
//	else
//		temp = ft_strdup(memory->left);
//
////	n = memory->counter;
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
//	memory->counter = n;
//	return (0);
//}



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
	
	if (line != NULL)
		temp = ft_strjoin(*line, memory->left); // put into temp slow down a lot
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

int check_static_for_n(t_memory *memory, char **line)
{
	int n;
	n = 0;
	while (memory->left[n] != 0)
	{
		if (memory->left[n] == '\n')
		{
			*line = ft_strdup_till_n(memory->left, n);
			after_n_memcpy(memory->left, memory->left, n);
			n++;
		}
	}
	
	
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
	*line = NULL;
	
	while (memory.res > 0)
	{
		if (!*(memory.left))
		{
			if ((memory.res = ft_read(fd, &memory)) == -1)
				return (-1);
			if (check_static_for_n(&memory, line) == 1)
			{
				return (1);
			}
			if (memory.res == 0) //for \0 at the end not null in last line
			{
				*line = ft_strjoin(*line, memory.left);
			}
			
		}
		else
		{
			if(ft_search_end_of_line(line, &memory) == 1)
			{
				return (1);
			}
			else
			{
				*line = ft_strjoin(*line, memory.left);
				clean_string(&memory);
			}
		}
	}

	return (0);
}








//typedef struct s_memory
//{
//	char left[BUFFER_SIZE + 1];
//	unsigned int counter;
//	int res;
//
//} t_memory;
//
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
//
//
//
//void	after_n_memcpy(char *left, char *temp, unsigned int n)
//{
//	unsigned int i;
//	unsigned int j;
//
//	i = 0;
//	j = 0;
////	if (n == 0)
////		n++;
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
//int	ft_search_end_of_line(char **line, char *left, unsigned int counter)
//{
//	char *temp;
//	unsigned int n = 0;
//
//	if (line != NULL)
//		temp = ft_strjoin(*line, left);
//	else
//		temp = ft_strdup(left);;
//
//	while (temp[n] != '\0')
//	{
//		if (temp[n] == '\n')
//		{
//			*line = ft_strdup_till_n(temp, n);
//			after_n_memcpy(left, temp, n);
//			free(temp);
//			return (1);
//		}
//		n++;
//	}
//	counter = n;
//	return (0);
//}
//
//void	clean_string(char *str)
//{
//	int len = ft_strlen(str);
//	int i = 0;
//	while (i < len)
//	{
//		str[i] = '\0';
//		i++;
//	}
//}
//
//int		ft_read(int fd, char *left, t_memory memory) //(int fd, char **line, char *left, t_memory memory)
//{
//	memory.res = (int)read(fd, left, BUFFER_SIZE);
//	if (memory.res == -1)
//		return (-1);
//	left[memory.res] = '\0';
//	return (memory.res);
//}
//
//
//int		get_next_line(int fd, char **line)
//{
//	static 	t_memory memory = {.counter = 0, .res = 1};
//
//	if (!fd || fd < 0)
//		return (-1);
//	*line = NULL;
//
//	while (memory.res > 0)
//	{
//		if (!*(memory.left))
//		{
//			if ((memory.res = ft_read(fd, memory.left, memory)) == -1)
//				return (-1);
//			if (memory.res == 0)
//			{
//				*line = ft_strjoin(*line, memory.left); //needed if no '\n' in last line
//			}
//		}
//		else
//		{
//			if(ft_search_end_of_line(line, memory.left, memory.counter) == 1)
//			{
//				return (1);
//			}
//			else
//			{
//				*line = ft_strjoin(*line, memory.left);
//				clean_string(memory.left);
//			}
//		}
//	}
//
//	return (0);
//}
//





































// ******************************************************************** \\
//faining on tests with many \n\n\n need to rewrite hardly
// ******************************************************************** \\




//int		find_copy_line(char *str, char **line, char *left)
//{
//	int len_substr;
//
//	len_substr = 0;
//	while (str[len_substr])
//	{
//		if (str[len_substr] == '\n')
//		{
//			*line = ft_strdup_till_n(str, len_substr);
//			after_n_memcpy(left, str, BUFFER_SIZE);
//			free(str);
//			return (1);
//		}
//		len_substr++;
//	}
//	return (0);
//}

//char	*update_temp(char *temp, const char *buff, const char *left)
//{
//	char *updated_temp;
//
//	updated_temp = NULL;
//	if (temp)
//	{
//		updated_temp = ft_strjoin(temp, buff);
//		free(temp);
//	}
//	else
//		updated_temp = ft_strjoin(left, buff);
//	return (updated_temp);
//}


//char	*malloc_it(size_t buff_s)
//{
//	char *str;
//
//	str = malloc((buff_s + 1) * sizeof(char));
//	if (!str)
//		return (0);
//	return (str);
//}



//void	*after_n_memcpy(char *dst, char *src, size_t n)
//{
//	unsigned	int		i;
//	unsigned	char	*destination;
//	unsigned	char	*sorce;
//
//	destination = (unsigned char *)dst;
//	sorce = (unsigned char *)src;
//	i = 0;
//	while (*sorce != '\n')
//	{
//		sorce++;
//	}
//	sorce++;
//	while (i < n && (dst != (void *)0 || src != (void *)0))
//	{
//		destination[i] = sorce[i];
//		i++;
//	}
//	destination[i] = '\0';
//	return (dst);
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
//int		find_copy_line(char *str, char **line, char *left)
//{
//	int len_substr;
//
//	len_substr = 0;
//	while (str[len_substr])
//	{
//		if (str[len_substr] == '\n')
//		{
//			*line = ft_strdup_till_n(str, len_substr);
//			after_n_memcpy(left, str, BUFFER_SIZE);
//			free(str);
//			return (1);
//		}
//		len_substr++;
//	}
//	return (0);
//}
//
//char	*update_temp(char *temp, const char *buff, const char *left)
//{
//	char *updated_temp;
//
//	updated_temp = NULL;
//	if (temp)
//	{
//		updated_temp = ft_strjoin(temp, buff);
//		free(temp);
//	}
//	else
//		updated_temp = ft_strjoin(left, buff);
//	return (updated_temp);
//}
//
//
//char	*malloc_it(size_t buff_s)
//{
//	char *str;
//
//	str = malloc((buff_s + 1) * sizeof(char));
//	if (!str)
//		return (0);
//	return (str);
//}
//
//int		get_next_line(int fd, char **line)
//{
//	static char		left[BUFFER_SIZE + 1];
//	char			*buff;
//	int				res;
//	char			*incompete_line;
//
//	if (fd < 0 || !fd)
//		return(-1);
//	buff = malloc_it(BUFFER_SIZE);
//	res = 1;
//	incompete_line = NULL;
//	*line = NULL;
//	while (res > 0)
//	{
//		res = (int)read(fd, buff, BUFFER_SIZE);
//		buff[res] = '\0';
//		if (!*left && !incompete_line)
//			incompete_line = ft_strdup(buff);
//		else
//			incompete_line = update_temp(incompete_line, buff, left);
//		if (find_copy_line(incompete_line, line, left) == 1)
//		{
////			after_n_memcpy(left, incompete_line, BUFFER_SIZE);
////			free(incompete_line);
//			return (1);
//		}
//	}
//	return (0);
//}





// ******************************************************************** \\
// working but buff cannot be on stack (BUFF_SIZE 10.000.000 crashes it)
// ******************************************************************** \\

//int		get_next_line(int fd, char **line)
//{
//	static char		left[BUFFER_SIZE + 1];
//	char			buff[BUFFER_SIZE + 1];
//	int				res;
//	char			*incompete_line;
//
//	if (fd < 0)
//		return(-1);
//	res = 1;
//	incompete_line = NULL;
//	*line = NULL;
//	while (res > 0)
//	{
//		res = (int)read(fd, buff, BUFFER_SIZE);
//		buff[res] = '\0';
//		if (!*left && !incompete_line)
//			incompete_line = ft_strdup(buff);
//		else
//			incompete_line = update_temp(incompete_line, buff, left);
//		if (find_copy_line(incompete_line, line) == 1)
//		{
//			after_n_memcpy(left, incompete_line, BUFFER_SIZE);
//			free(incompete_line);
//			return (1);
//		}
//	}
//	return (0);
//}
