//
//  test_fewchars.c
//  get_next_line
//
//  Created by Yuliia Demura on 12/5/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include "test_get_next_line.h"
#include "get_next_line.h"

#define FIXTURES_PATH_HOME "/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/test_fewchars/"
#define FIXTURES_PATH_CODAM "/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/test_fewchars/"

void	test_fewchars(void)
{
	int fd;
	char *line;

	fd = open(FIXTURES_PATH"fewchar_perline.txt", O_RDONLY);
	assert(fd != -1);
	if (fd == -1)
		printf("not opened\n");
//	else
//		printf(".......................opened\n");
	
	line = NULL;
	
	int res;
	res = 1;
	int i = 1;
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
//	printf("%i | line %i: %s\n",res, i, line);
	free(line);
	i++;
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "a") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "bb") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "ccc") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "dddd") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "eeeee") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "ffffff") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "a") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "a") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "bb") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "ccc") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "a") == 0);
	assert(res == 1);
	free(line);
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 0);
	free(line);
	

	if (close(fd) < 0)
		printf("not closed\n");
//	else
//		printf(".......................closed\n");
}
