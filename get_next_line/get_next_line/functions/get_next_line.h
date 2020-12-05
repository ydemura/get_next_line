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

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <unistd.h>
# include <stdlib.h>

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
