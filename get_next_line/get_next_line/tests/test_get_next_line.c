//
//  test_get_next_line.c
//  get_next_line
//
//  Created by Yuliia Demura on 11/21/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//
 
 
#include "test_get_next_line.h"
#include "get_next_line.h"

#define FIXTURES_PATH_HOME "/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/text_files/"
#define FIXTURES_PATH_CODAM "/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/text_files/"

void	test_get_next_line(void)
{
	int fd;
	char *line;
	
//	fd = open(FIXTURES_PATH"normal.txt", O_RDONLY);
	
//	fd = open(FIXTURES_PATH"fewchar_perline.txt", O_RDONLY);
	
//	fd = open(FIXTURES_PATH"64bit_line.txt", O_RDONLY);
	
//	fd = open(FIXTURES_PATH"64bit_paragraph.txt", O_RDONLY);

//	fd = open(FIXTURES_PATH"empty.txt", O_RDONLY);

//	fd = open(FIXTURES_PATH"bar.txt", O_RDONLY);

//	fd = open(FIXTURES_PATH"only_newline.txt", O_RDONLY);
	
//	fd = open(FIXTURES_PATH"long_line.txt", O_RDONLY);
	
	fd = open(FIXTURES_PATH"test_file.txt", O_RDONLY);

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
