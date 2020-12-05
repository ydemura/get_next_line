//
//  main.c
//  get_next_line
//
//  Created by Yuliia Demura on 11/21/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include <stdio.h>
#include "get_next_line.h"
#include "test_get_next_line.h"

int main() //int argc, const char * argv[]
{
//	test_get_next_line();
	
	test_only_NL();
	test_empty_file();
	test_fewchars();
	test_longline();
	test_64_without_NL(); //after this one there is weird behaviour in test god knows why
	
//	system ("leaks a.out");
	return 0;
}
