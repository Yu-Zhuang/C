# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# ifndef func_h
# define func_h
# include "func.h"
# endif
# define MAX 100

int main(int argc, char *argv[])
{
	char templet[5][MAX] = {"-dis","-area","-mid", "-cir", "-bary"};
	if( ! strcmp(argv[1],templet[0]) )
		DISTANCE(argv[2], argv[3], argv[4], argv[5]); // x1, y1, x2, y2
	else if( ! strcmp(argv[1],templet[1]) )
		AREA(argv[2], argv[3], argv[4], argv[5]);
	else if( ! strcmp(argv[1],templet[2]) )
		MID_POINT(argv[2], argv[3], argv[4], argv[5]);
	else if( ! strcmp(argv[1],templet[3]) )
		CIRCLE(argv[2], argv[3], argv[4]);
	else if( ! strcmp(argv[1],templet[4]) )
		BARY(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
	else
		printf("\tWrong input!\n");
	
	return 0;
}