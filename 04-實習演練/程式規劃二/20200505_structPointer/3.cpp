#include<stdio.h>
int main(void){
	int price[3]={15,20,30}, r_coin[3]={1,5,50}, input[4]={0};
	scanf("%d %*c %d %*c %d %*c %d", &input[0],&input[1],&input[2],&input[3]);
	int total = input[0] - (input[1]*price[0] + input[2]*price[1] + input[3]*price[2]);
	if(total < 0) 
		printf("0\n");
	else{
		int ret[3]={0};
		for(int i=0;i<3;i++){
			if(i != i-1){
				ret[i] = total/r_coin[2-i];
				total -= r_coin[2-i]*(total/r_coin[2-i]);
			}
			else
				ret[i] = total/r_coin[2-i];
		} 
		for(int i=2;i>=0;i--)
			if(i!=0)
				printf("%d,", ret[i]);
			else
				printf("%d\n", ret[i]);
	}
	return 0;
}