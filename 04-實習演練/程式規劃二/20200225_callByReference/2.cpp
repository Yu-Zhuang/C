#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
/*
class pro and com grade
*/
void MaxScore(int*, int*, int*, int*, int*, int*, int*, int*);
void Aver(int*, int*);
void Graph(int*, int*);
int main(void){
	srand(time(NULL));
	int listC[100]={0}, listP[100]={0};
	int *MaxCind=(int*)malloc(sizeof(int)), 
		*MaxPind=(int*)malloc(sizeof(int));
	int MaxC=0, MaxP=0, MaxCn=0, MaxPn=0; 

	MaxScore(listC, listP, MaxCind, MaxPind, &MaxCn, &MaxPn, &MaxC, &MaxP);
	printf("計概最高:%d, %d人\n 程規最高:%d, %d人\n", MaxC, MaxCn, MaxP, MaxPn);
	Graph(listC, listP);
	Aver(listC, listP);

	

	return 0;
}
void Graph(int* listC, int *listP){
	printf("++graph:++\n");
	printf("<10:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<20) printf("*");
	}printf("\n");
	printf("10~19:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<40&&listC[i]+listP[i]>=20) printf("*");
	}printf("\n");
	printf("20~29:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<60&&listC[i]+listP[i]>=40) printf("*");
	}printf("\n");
	printf("30~39:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<80&&listC[i]+listP[i]>=60) printf("*");
	}printf("\n");
	printf("40~49:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<100&&listC[i]+listP[i]>=80) printf("*");
	}printf("\n");
	printf("50~59:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<120&&listC[i]+listP[i]>=100) printf("*");
	}printf("\n");
	printf("60~69:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<140&&listC[i]+listP[i]>=120) printf("*");
	}printf("\n");
	printf("70~79:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<160&&listC[i]+listP[i]>=140) printf("*");
	}printf("\n");
	printf("80~89:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<180&&listC[i]+listP[i]>=160) printf("*");
	}printf("\n");
	printf("90~99:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]<200&&listC[i]+listP[i]>=180) printf("*");
	}printf("\n");
	printf("100:");
	for(int i=0;i<100;i++){
		if(listC[i]+listP[i]==200) printf("*");
	}printf("\n");

}



void Aver(int*listC, int*listP){
	for(int i=0;i<100;i++){
		if((listC[i]+listP[i])/2 < 60) printf("student%d' average=%d\n", i, (listC[i]+listP[i])/2);
	}
}


void MaxScore(int computer[], int program[], int MaxComIndex[], int MaxProgIndex[], 
	int *MaxComNum, int *MaxProgNum,  int *MaxComScore, int *MaxProScore){

	MaxComScore[0]=0; MaxProScore[0]=0;
	*MaxComNum=0; *MaxProgNum=0;
	for(int i=0;i<100;i++){ computer[i]=rand()%101; program[i]=rand()%101; }

	for(int i=0;i<100;i++){
			if(computer[i] > MaxComScore[0]){
				MaxComScore[0]=computer[i];
			}

			if(program[i] > MaxProScore[0]){
				MaxProScore[0]=program[i];
			}

	}

	int count_1=0, count_2=0;
	printf("計概最高分的學生是:");
	for(int i=0;i<100;i++){
		if(computer[i]== *MaxComScore){
			MaxComIndex[count_1]=computer[i]+1;
			printf("%d, ", i);
			count_1++;
		}
	}printf("\n");
	printf("程規最高分的學生是:");
	for(int i=0;i<100;i++){
		if(program[i]== *MaxProScore){
			MaxProgIndex[count_1]=computer[i]+1;
			printf("%d, ", i+1);
			count_2++;
		}
	}printf("\n");
	*MaxComNum=count_1;
	*MaxProgNum=count_2;
}
