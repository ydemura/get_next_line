/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:36 by ydemura       #+#    #+#                 */
/*   Updated: 2020/11/21 13:12:50 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	after_n_memcpy(char *left, char *temp, unsigned int n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < n)
		i++;
	i++;
	while (temp[i] != '\0')
	{
		left[j] = temp[i];
		j++;
		i++;
	}
	left[j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
