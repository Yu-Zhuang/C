#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void geneDNA(char A[],char B[]);
void muDNA(char T[],int *sT);
void changeDNA(char A[], char B[], int* sA, int* sB);
void matDNA(char A[], char B[], int* sA, int* sB);
void printDNA(char A[],char B[], int* sA, int* sB);

int main(void){
	srand(time(NULL));
	char A[101],B[101];
	int sA=-1, sB=-1;
	int flag=1;
	memset(A,'a',101);
	memset(B,'a',101);

	geneDNA(A,B); //generate DNA;
	printDNA(A,B,&sA,&sB);
	while(flag){
		start:
		printf("1)單突變DNA; 2)交換DNA; 3)交配DNA; -1)結束: ");
		scanf("%d", &flag);
		if(flag!=1&&flag!=2&&flag!=3&&flag!=-1) goto start;
		if(flag== -1) break;
		else if(flag==1){
			sA=-1; sB=-1;
			muDNA(A, &sA); //mu
			printDNA(A,B,&sA,&sB);
		}else if(flag==2){
			sA=-1; sB=-1;
			changeDNA(A,B,&sA,&sB);
			printDNA(A,B,&sA,&sB);
		}else if(flag==3){
			sA=-1; sB=-1;
			matDNA(A,B,&sA,&sB);
			printDNA(A,B,&sA,&sB);
		}		
	}


    return 0;
}
void matDNA(char A[], char B[], int* sA, int* sB){
	printf("\n==================Mating DNA==================\n");
	int site;
	char tmp;
	site=rand()%99;
	printf("交配位置在:%d.\n", site);
	for(int i=0;i<(100-site);i++){
		tmp=A[site+i];
		A[site+i]=B[site+i];
		B[site+i]=tmp;
	}
	sA[0]=site;
	sB[0]=site;
}
void changeDNA(char A[], char B[], int* sA, int* sB){
	printf("\n==================Change DNA==================\n");
	int site_1=0, site_2=0;
	int size=0;
	char tmp;
	size=rand()%26+5;

	site_1=rand()%(100-size);
	site_2=rand()%(100-size);
	printf("交換size為: %d.\n", size);
	printf("A起始點為:%d\n", site_1);
	printf("B起始點為:%d\n", site_2);
	for(int i=0;i<size;i++){
		tmp=A[site_1+i];
		A[site_1+i]=B[site_2+i];
		B[site_2+i]=tmp;
	}
	sA[0]=site_1;
	sB[0]=site_2;
}


void muDNA(char T[], int *sT){ 
	printf("\n==================Mutate DNA==================\n");
	char list[]="ATCG";
	char ch;
	int site, flag=1;
	site=rand()%100;
	printf("POINT MUTATION SITE AT: %d.\n", site);
	while(flag){
		ch=list[rand()%4];
		if(T[site]==ch) continue;
		else { T[site]=ch; break; }
	}
	sT[0]=site;
}
void geneDNA(char A[],char B[]){
	printf("\n==================Genetate DNA==================\n");
	char list[]="ATCG";
	for(int i=0;i<100;i++){
		A[i]=list[(rand()%4)];
		B[i]=list[(rand()%4)];
	}
	A[100]='\0';
	B[100]='\0';
}
void printDNA(char A[],char B[], int *sA, int *sB){
	int i=0, j=0;
	printf("A chain DNA:\n");
	while(A[i]!='\0') { printf("%c", A[i]); i++; if(i%50==0) printf("\n"); if(i==sA[0]) printf("\""); }
	printf("\nB chain DNA:\n");
	while(B[j]!='\0') { printf("%c", B[j]); j++; if(j%50==0) printf("\n"); if(j==sB[0]) printf("\"");}
}
