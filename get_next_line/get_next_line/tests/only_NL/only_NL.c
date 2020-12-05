//
//  only_NL.c
//  get_next_line
//
//  Created by Yuliia Demura on 12/5/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include "test_get_next_line.h"
#include "get_next_line.h"

#define FIXTURES_PATH_HOME "/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/only_NL/"
#define FIXTURES_PATH_CODAM "/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/only_NL/"

void	test_only_NL(void)
{
	int fd;
	char *line;

	fd = open(FIXTURES_PATH"only_newline.txt", O_RDONLY);
	assert(fd != -1);
	if (fd == -1)
		printf("not opened\n");
	
	line = NULL;
	int res;
	int i = 1;
	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (res == 0 || res == -1)
			break;
		assert(res == 1);
		assert(strcmp(line, "") == 0);
//		printf("%i | line %i: %s\n",res, i, line);
		free(line);
		i++;
	}
	
	res = get_next_line(fd, &line);
	assert(res == 0);
//	printf("%i | line %i: %s\n",res, i, line);
	assert(strcmp(line, "") == 0);
	free(line);

	if (close(fd) < 0)
		printf("not closed\n");
}

