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

int		find_copy_line(char *str, char **line)
{
	int len_substr;

	len_substr = 0;
	while (str[len_substr])
	{
		if (str[len_substr] == '\n')
		{
			*line = ft_strdup_till_n(str, len_substr);
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

int		get_next_line(int fd, char **line)
{
	static char		left[BUFFER_SIZE + 1];
	char			buff[BUFFER_SIZE + 1];
	int				res;
	char			*incompete_line;

	res = 1;
	incompete_line = NULL;
	*line = NULL;
	while (res > 0)
	{
		res = (int)read(fd, buff, BUFFER_SIZE);
		buff[res] = '\0';
		if (!*left)
			incompete_line = ft_strdup(buff);
		else
			incompete_line = update_temp(incompete_line, buff, left);
		if (find_copy_line(incompete_line, line) == 1)
		{
			after_n_memcpy(left, incompete_line, BUFFER_SIZE);
			free(incompete_line);
			return (1);
		}
	}
	return (0);
}
