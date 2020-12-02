/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:46 by ydemura       #+#    #+#                 */
/*   Updated: 2020/11/21 13:12:47 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_memory
{
	char			left[BUFFER_SIZE + 1];
	unsigned int	counter;
	int				res;
}					t_memory;

int					ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char				*ft_strdup_till_n(const char *s1, int len);
void				after_n_memcpy(char *left, char *temp, unsigned int n);
void				clean_string(t_memory *memory);
int					cut_line_and_left(char **line, t_memory *memory, int n,
	char *temp);
int					ft_search_end_of_line(char **line, t_memory *memory);
int					ft_read(int fd, t_memory *memory, char **line);
int					get_next_line(int fd, char **line);

#endif
