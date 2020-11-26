//
//  test_get_next_line.c
//  get_next_line
//
//  Created by Yuliia Demura on 11/21/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//
 
 //                    ************* SUBJECT ***************

//Write a function which returns a line read from a file descriptor, without the newline.

//Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by moulinette.
//Your read must use the BUFFER_SIZE defined during compilation to read from a file or from stdin.

//                  *******************************************



// https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/
//read: From the file indicated by the file descriptor fd, the read() function reads cnt bytes of input into the memory area indicated by buf. A successful read() updates the access time for the file.


//size_t read (int fd, void* buf, size_t cnt);

//#1. file descriptor for reading
//#2. The value of what has been read

//       READ
//Returns: How many bytes were actually read
//return Number of bytes read on success
//return 0 on reaching end of file
//return -1 on error
//return -1 on signal interrupt


// subject
//Return value 1 : A line has been read
//			   0 : EOF has been reached
//			  -1 : An error happened

//	fd: file descripter
//	buf: buffer to read data from
//	cnt: length of buffer
#include "test_get_next_line.h"
#include "get_next_line.h"

void	test_get_next_line(void)
{
	int fd;
	char *line;
	
	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/test_file.dict", O_RDONLY);
	if (fd == -1)
		printf("not opened\n");
	else
		printf(".......................opened\n");
	
	line = NULL;
	
	int res;
	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		printf("int %i: %s\n", res, line);
		free(line);
		if (res != 1)
			break;
	}

//TESTS:
	
//1: B_S = 8

//hello
//world got //wo:rld -> 8
//herewego
//d
//d
//d
	
//1: B_S = 5, 6, 7,
	
//hello
//world
//herewego
//d
//d
//d

	if (close(fd) < 0)
		printf("not closed\n");
	else
		printf(".......................closed\n");
	
}


// from rush 02

//int		ft_check_size(int fd)
//{
//	int ret;
//	char buf[500 + 1];
//	int len;
//
//	len = 0;
//	while((ret = read(fd, buf, 500)))
//	{
//		buf[ret] = '\0';
//		len = len + ret;
//	}
//	return(len);
//}
