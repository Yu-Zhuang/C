#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "hash.h"
int main(void){
	int num=123456789;
	int size=34;
	printf("1. %d\n", ModuloHash(num,size));
	printf("2. %d\n", DigitExtractHash(num,size));
	printf("3. %d\n", MidSqrHash(num,size));
	printf("4. %d\n", FoldHash(num,size));
	printf("5. %d\n", RotateHash(num,size));
	printf("6. %d\n", PseuRandHash(num,size));

	return 0;
}
