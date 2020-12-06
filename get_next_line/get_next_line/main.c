//
//  main.c
//  get_next_line
//
//  Created by Yuliia Demura on 11/21/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "test_get_next_line.h"

int main() //int argc, const char * argv[]
{
	test_get_next_line();

	test_only_NL();
	test_empty_file();
	test_fewchars();
	test_longline();
	test_64_without_NL(); //after this one there is weird behaviour in test god knows why

//	system ("leaks a.out");
	return 0;
}








//# ifndef STDIN_FILENO
//#  define STDIN_FILENO 0
//# endif
//
//
//void	my_ft_putchar_fd(char c, int fd)
//{
//	if (write(fd, &c, 1) == -1)
//		write(2, &c, 1);
//}
//
//void	my_ft_putstr_fd(char *s, int fd)
//{
//	if (!s)
//		return ;
//	if (write(fd, s, ft_strlen(s)) == -1)
//		write(2, s, ft_strlen(s));
//}
//
//void	my_ft_putnbr_fd(int n, int fd)
//{
//	if (n < 0)
//	{
//		my_ft_putchar_fd('-', fd);
//		if (n < -9)
//			my_ft_putnbr_fd(-(n / 10), fd);
//	}
//	else if (n > 9)
//		my_ft_putnbr_fd(n / 10, fd);
//	(n > 0) ? my_ft_putchar_fd(n % 10 + '0', fd) \
//		: my_ft_putchar_fd(-(n % 10) + '0', fd);
//}
//
//int	main(int argc, char *argv[])
//{
//	int 	fd_test_me;
//
//	if (argc != 2)
//	{
//		my_ft_putstr_fd("failed to provide the file to be opened as arg\n", 2);
//		return (0);
//	}
//	if((fd_test_me = open(argv[1], O_RDONLY)) == -1)
//	{
//		my_ft_putstr_fd("failed to open", 2);
//		my_ft_putstr_fd(argv[1], 2);
//		my_ft_putstr_fd("filedescriptor.\n", 2);
//		return (0);
//	}
//	char	*line;
//	int		result;
//	char 	buf[BUFFER_SIZE + 1];
//
//	line = NULL;
//	result = 1;
//	my_ft_putstr_fd("\n\n\t\t\tlets see how your GNL behaves with the STDIN_FILENO:\n", 1);
////	while (result > 0)
////	{
////		result = get_next_line(0, &line);
////		if (result != -1)
////		{
////			my_ft_putstr_fd(line, 1);
////			my_ft_putchar_fd('\n', 1);
////		}
////		free(line);
////	}
////	my_ft_putstr_fd("<--------END\nyour GNL returned:", 1);
////	my_ft_putnbr_fd(result, 1);
////	my_ft_putstr_fd("\n\n\t\t\tnow compare with read behavior:\n", 1);
//	result = 1;
//	while (result > 0)
//	{
//		result = (int)read(STDIN_FILENO, buf, BUFFER_SIZE);
//		if (result != -1)
//		{
//			buf[result] = '\0';
//			my_ft_putstr_fd(buf, 1);
//		}
//		if (result && buf[result - 1] == '\n')
//			result = 0;
//	}
//	my_ft_putstr_fd("<--------END\n", 1);
//	my_ft_putnbr_fd(result, 1);
//	my_ft_putstr_fd("\n", 1);
//	return (0);
//}





//int	main(int argc, char *argv[])
//{
//	int 	fd_test_me;
//	char	*line;
//	int		result;
//
//	line = NULL;
//	result = 1;
//	if (argc != 2)
//	{
//		my_ft_putstr_fd("failed to provide the file to be opened as arg\n", 2);
//		return (0);
//	}
//	if((fd_test_me = open(argv[1], O_RDONLY)) == -1)
//	{
//		my_ft_putstr_fd("failed to open", 2);
//		my_ft_putstr_fd(argv[1], 2);
//		my_ft_putstr_fd("filedescriptor.\n", 2);
//		return (0);
//	}
//	if (BUFFER_SIZE == 0)
//		assert(-1 == get_next_line(fd_test_me, &line));
//	else
//	{
//		assert(-1 == get_next_line(-1, &line));
//		free(line);
//		line = NULL;
//		assert(-1 == get_next_line(-42, &line));
//		free(line);
//		line = NULL;
//		assert(-1 == get_next_line(42, &line)); //
//		free(line);
//		line = NULL;
//		assert(-1 == get_next_line(42, NULL)); //
//		free(line);
//		line = NULL;
//		assert(-1 == get_next_line(fd_test_me, NULL));
//	}
//	free(line);
//	line = NULL;
//	close(fd_test_me);
//	return (0);
//}
