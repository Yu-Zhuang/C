# include "func.h"
# include <stdio.h>
# include <string.h>
# include <math.h>

void DISTANCE(char *argv_2, char *argv_3, char *argv_4, char *argv_5){
	double x1, y1, x2, y2;
	sscanf(argv_2, "%lf", &x1);
	sscanf(argv_3, "%lf", &y1);
	sscanf(argv_4, "%lf", &x2);
	sscanf(argv_5, "%lf", &y2);
	printf("distance: %.2lf\n", sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) );
}

void AREA(char *argv_2, char *argv_3, char *argv_4, char *argv_5){
	double x1, y1, x2, y2;
	sscanf(argv_2, "%lf", &x1);
	sscanf(argv_3, "%lf", &y1);
	sscanf(argv_4, "%lf", &x2);
	sscanf(argv_5, "%lf", &y2);
	double ret = (x2-x1)*(y2-y1);
	if(ret < 0)
		ret *= -1;
	printf("area: %.2lf\n",  ret);
}

void MID_POINT(char *argv_2, char *argv_3, char *argv_4, char *argv_5){
	double x1, y1, x2, y2;
	sscanf(argv_2, "%lf", &x1);
	sscanf(argv_3, "%lf", &y1);
	sscanf(argv_4, "%lf", &x2);
	sscanf(argv_5, "%lf", &y2);
	printf("mid point: (%.2lf, %.2lf)\n", (x2+x1)/2, (y2+y1)/2 );	
}

void CIRCLE(char *argv_2, char *argv_3, char *argv_4){
	double r;
	sscanf(argv_4, "%lf", &r);
	printf("circle area: %.2lf\n", r*r*3.14);
}

void BARY(char *argv_2, char *argv_3, char *argv_4, char *argv_5, char *argv_6, char *argv_7){
	double x1, y1, x2, y2, x3, y3;
	sscanf(argv_2, "%lf", &x1);
	sscanf(argv_3, "%lf", &y1);
	sscanf(argv_4, "%lf", &x2);
	sscanf(argv_5, "%lf", &y2);	
	sscanf(argv_6, "%lf", &x3);
	sscanf(argv_7, "%lf", &y3);
	printf("center of traingle: (%.2lf, %.2lf)\n", (double)(x1+x2+x3)/3, (double)(y1+y2+y3)/3);
}