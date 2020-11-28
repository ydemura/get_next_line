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

void	*after_n_memcpy(char *dst, char *src, size_t n)
{
	unsigned	int		i;
	unsigned	char	*destination;
	unsigned	char	*sorce;

	destination = (unsigned char *)dst;
	sorce = (unsigned char *)src;
	i = 0;
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

int		find_copy_line(char *str, char **line, char *left)
{
	int len_substr;

	len_substr = 0;
	while (str[len_substr])
	{
		if (str[len_substr] == '\n')
		{
			*line = ft_strdup_till_n(str, len_substr);
			after_n_memcpy(left, str, BUFFER_SIZE);
			free(str);
			return (1);
		}
		len_substr++;
	}
	return (0);
}

char	*update_temp(char *temp, const char *buff, const char *left)
{
	char *updated_temp;

	updated_temp = NULL;
	if (temp)
	{
		updated_temp = ft_strjoin(temp, buff);
		free(temp);
	}
	else
		updated_temp = ft_strjoin(left, buff);
	return (updated_temp);
}


char	*malloc_it(size_t buff_s)
{
	char *str;

	str = malloc((buff_s + 1) * sizeof(char));
	if (!str)
		return (0);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char		left[BUFFER_SIZE + 1];
	char			*buff;
	int				res;
	char			*incompete_line;

	if (fd < 0 || !fd)
		return(-1);
	buff = malloc_it(BUFFER_SIZE);
	res = 1;
	incompete_line = NULL;
	*line = NULL;
	while (res > 0)
	{
		res = (int)read(fd, buff, BUFFER_SIZE);
		buff[res] = '\0';
		if (!*left && !incompete_line)
			incompete_line = ft_strdup(buff);
		else
			incompete_line = update_temp(incompete_line, buff, left);
		if (find_copy_line(incompete_line, line, left) == 1)
		{
//			after_n_memcpy(left, incompete_line, BUFFER_SIZE);
//			free(incompete_line);
			return (1);
		}
	}
	return (0);
}


// working but buff cannot be on stack (BUFF_SIZE 10.000.000 crashes it)
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
