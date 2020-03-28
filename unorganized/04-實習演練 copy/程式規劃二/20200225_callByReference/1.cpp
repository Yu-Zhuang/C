#include <stdio.h>
#include <stdlib.h> 
void input(int*);
void findMAM(int*);

int main(void){
	int *array=(int*)malloc(sizeof(int)*5);

	input(array);
	findMAM(array);
	for(int i=0;i<3;i++) printf("%d ", array[i]);

	return 0;
}
void input(int* list){
	int i;
	for(i=0;i<5;i++){
		printf("enter number %d: ", i+1);
		scanf("%d", &list[i]);
	}
}
void findMAM(int *nums){
	int ret[3]={0};
	ret[0]=nums[0]; ret[1]=nums[0]; ret[2]=0;
	for(int i=0;i<5;i++){
		ret[2]+=nums[i];
		if(nums[i]>ret[0]) ret[0]=nums[i];
		if(nums[i]<ret[1]) ret[1]=nums[i];
	}
	ret[2] = ret[2]/5;

	nums[0]=ret[0];
	nums[1]=ret[1];
	nums[2]=ret[2];
}
/*
function to find max min and average
*/
