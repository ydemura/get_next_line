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

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*after_n_memcpy(char *dst, char *src, size_t n);
char	*ft_strdup_till_n(const char *s1, int len);
char	*ft_strdup(const char *s1);


//int		find_copy_line(char *str, char **line);
int		find_copy_line(char *str, char **line, char *left);


void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*update_temp(char *temp, const char *buff, const char *left);

#endif
