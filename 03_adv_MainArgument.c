#include<stdio.h>
#include<stdlib.h>
//int agrc: argument numbers, char agrv: argument value;
int main(int argc, char **argv){
	printf("size of agrc= %d\n", agrc);
	for(int i=0;i<agrc;i++){
		printf("%s\n", agrv[i]);
	}
	return 0;
}

