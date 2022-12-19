//
//  test_64_without_NL.c
//  get_next_line
//
//  Created by Yuliia Demura on 12/5/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include "test_get_next_line.h"
#include "get_next_line.h"

#define FIXTURES_PATH_HOME "/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/test_64_without_NL/"
#define FIXTURES_PATH_CODAM "/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/test_64_without_NL/"

void	test_64_without_NL(void)
{
	int fd;
	char *line;
	
	//		printf("%i | line %i: %s\n",res, i, line);

	fd = open(FIXTURES_PATH"64bit_line.txt", O_RDONLY);
	assert(fd != -1);
	if (fd == -1)
		printf("not opened\n");
	
	line = NULL;
	int res;
	int i = 1;
	
	res = get_next_line(fd, &line);
//	printf("%i | line %i: %s\n",res, i, line);
	assert(strcmp(line, "9GN+3XuFJq9SoIVEwyf9N6V0SsRGamXC+5i7fs3TQaDax3Q7obX6his/LqVswZ12") == 0);
	assert(res == 0);
	free(line);
	i++;
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 0);
	free(line);

	if (close(fd) < 0)
		printf("not closed\n");
}

