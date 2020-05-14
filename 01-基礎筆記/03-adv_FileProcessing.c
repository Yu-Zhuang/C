#include<stdio.h>
#include<stdlib.h>
/*
1: file processing: read file, add new element to file, rewrite file;
*/
void ReadFile(char *file);
void ReWrite(char *file, char *element);
void Add(char *file, char *element);

int main(void){
	//element
	char string[]="\nvar hi=\"this is new string!\";\nconsole.log(hi);\n";
	char str2[]="\nconst str=\"add() read() and rewrite() done!\";\nconsole.log(str);\n";
	//file
	char file[]="JS.js";
	// add element to file
	printf("========Add==========\n");
	Add(file, string);
	ReadFile(file); //print the file
	// rewrite file with element2(str);
	printf("========ReWrite==========\n");
	ReWrite(file, strs);
	ReadFile(file);//print the file

	return 0;
}
void ReWrite(char *file, char *element){
	FILE *fptr=fopen(file, "w");
	fputs(element, fptr);
	fclose(fptr);
	printf("\n+ReWrite done+\n");
}
void Add(char *file, char *element){
	FILE *fptr=fopen(file, "a");
	fputs(element, fptr);
	fclose(fptr);
}
void ReadFile(char *file){
	FILE *fptr=fopen(file,"r");
	char ch;
	while((ch=fgetc(fptr)) != EOF){
		printf("%c", ch);
	}
	fclose(fptr);
	printf("\n");
}


