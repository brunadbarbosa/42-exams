#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int lines, width;
	char empt, obst, full;
	char **map;
} BSQ;

#endif