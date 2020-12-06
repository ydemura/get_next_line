//
//  test_get_next_line.h
//  get_next_line
//
//  Created by Yuliia Demura on 11/21/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//


#ifndef test_get_next_line_h
#define test_get_next_line_h

//#define FIXTURES_PATH FIXTURES_PATH_CODAM
#define FIXTURES_PATH FIXTURES_PATH_HOME

#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

void	test_get_next_line(void);
void	test_empty_file(void);
void	test_fewchars(void);
void	test_longline(void);
void	test_64_without_NL(void);
void	test_only_NL(void);

#endif /* test_get_next_line_h */
