/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:46 by ydemura       #+#    #+#                 */
/*   Updated: 2020/12/06 11:53:43 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

#define FIXTURES_PATH FIXTURES_PATH_CODAM
//#define FIXTURES_PATH FIXTURES_PATH_HOME
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

typedef struct		s_memory
{
	int				res;
	int				status;
	char			left[BUFFER_SIZE + 1];
}					t_memory;

int					ft_strlen(const char *str);
char				*ft_strdup_till_n(const char *s1, int len);
void				after_n_memcpy(char *left, char *temp, unsigned int n);
char				*ft_realloc(char **line, int new_len, t_memory *memory);
char				*ft_strjoin_realloc(char *s1, t_memory *memory);
int					return_management(char **line, t_memory *memory);
int					cut_line_and_left(char **line, t_memory *memory,
	char *temp);
int					find_cut_new_line(t_memory *memory, char **line);
int					ft_read(int fd, t_memory *memory, char **line);
int					get_next_line(int fd, char **line);

#endif
