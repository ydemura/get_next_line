//
//  test_empty_file.c
//  get_next_line
//
//  Created by Yuliia Demura on 12/5/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include <stdio.h>
#include "test_get_next_line.h"
#include "get_next_line.h"

#define FIXTURES_PATH_HOME "/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/test_empty/"
#define FIXTURES_PATH_CODAM "/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/test_empty/"

void	test_empty_file(void)
{
	int fd;
	char *line;

	fd = open(FIXTURES_PATH"empty.txt", O_RDONLY);
	if (fd == -1)
		printf("not opened\n");
	
	line = NULL;
	int res;
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 0);
//	printf("%i | line %i: %s\n",res, i, line);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 0);
	free(line);

	if (close(fd) < 0)
		printf("not closed\n");
}

