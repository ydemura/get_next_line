/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:46 by ydemura       #+#    #+#                 */
/*   Updated: 2020/12/05 20:19:17 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>


#define FIXTURES_PATH FIXTURES_PATH_CODAM
//#define FIXTURES_PATH FIXTURES_PATH_HOME

#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

void	test_get_next_line(void);
void	test_empty_file(void);
void	test_fewchars(void);
void	test_longline(void);
void	test_64_without_NL(void);
void	test_only_NL(void);

//typedef struct		s_memory
//{
//	unsigned int	counter;
//	int				res;
//	char			left[BUFFER_SIZE + 1];
//}					t_memory;
//
int					ft_strlen(const char *str);
int					get_next_line(int fd, char **line);
void				*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_strdup_till_n(const char *s1, int len);


#endif
