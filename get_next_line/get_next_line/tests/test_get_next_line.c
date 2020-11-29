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
	
//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/normal.txt", O_RDONLY);
	
//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/fewchar_perline.txt", O_RDONLY);

	
//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/64bit_line.txt", O_RDONLY);
	
	
//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/64bit_paragraph.txt", O_RDONLY);

//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/empty.txt", O_RDONLY);

//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/fewchar_perline.txt", O_RDONLY);

	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/only_newline.txt", O_RDONLY);
	
//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/long_line.txt", O_RDONLY);
	
//	fd = open("/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/test_file.txt", O_RDONLY);
	
	if (fd == -1)
		printf("not opened\n");
	else
		printf(".......................opened\n");
	
	line = NULL;
	
	int res;
	res = 1;
	int i = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		printf("%i | line %i: %s\n",res, i, line);
		free(line);
		i++;
	}


	if (close(fd) < 0)
		printf("not closed\n");
	else
		printf(".......................closed\n");
}


// KO IN LINE     FILE_NAME : test/fewchar_perline.txt                           BUFFER_SIZE : 1              OUT: "(null)"	EXPECTED : ""		 AT_LINE : 20

// here\n
//we\n
//have\n
//short\n
//strings\n
//0\n
//0\n
//0\n
//0\n
//0\n
//....
