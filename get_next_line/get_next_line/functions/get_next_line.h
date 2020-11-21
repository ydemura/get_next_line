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

#ifndef get_next_line_h
#define get_next_line_h

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);


#endif /* get_next_line_h */
