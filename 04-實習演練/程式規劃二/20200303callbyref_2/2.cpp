#include<stdio.h>
#include<stdlib.h>

void initAry(int *nums, int numsSize, int value);

int main(void){
	int seq[4]={0}, input, i, j;
	char templet[5][10][6]={ 
	  { "*****","    *" ,"*****" ,"*****","*   *","*****","*****","*****","*****","*****" },
	  { "*   *","    *" ,"    *" ,"    *","*   *","*    ","*    ","    *","*   *","*   *" },
	  { "*   *","    *" ,"*****" ,"*****","*****","*****","*****","    *","*****","*****" },
	  { "*   *","    *" ,"*    " ,"    *","    *","    *","*   *","    *","*   *","    *" },
	  { "*****","    *" ,"*****" ,"*****","    *","*****","*****","    *","*****","    *" } 
	};
	scanf("%d", &input);
	
	initAry(seq, 4, input);
	for( i=0;i<5;i++){
		for( j=0;j<4;j++){
			if(j<3)
				printf("%s ", templet[i][seq[j]]);
			else
				printf("%s\n", templet[i][seq[j]]);

		}
	}

	return 0;
}
void initAry(int *nums, int numsSize, int value){
	for(int i=numsSize-1;i>=0;i--){
		nums[i]=value%10;
		value /= 10;
	}
}


