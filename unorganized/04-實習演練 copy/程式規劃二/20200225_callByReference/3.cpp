#include <stdio.h>
int main(void){
	int input[3][3]={0},i,j,flag=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++) scanf("%d ",&input[i][j]);
	}
	for(int i=0;i<3;i++){
		if(input[i][0] == input[i][1] && input[i][0] ==input[i][2]) { flag=1; break; }
		if(input[0][i] == input[1][i] && input[0][i] ==input[2][i]) { flag=1; break; }
	}
	if(input[0][0] == input[1][1] && input[0][0] == input[2][2]) { flag=1;}
	else if(input[0][2] == input[1][1] && input[0][2] == input[2][0]) { flag=1;}
	if(flag) printf("True\n");
	else if(!flag) printf("False\n");
	return 0;
}
/* 
ooxx遊戲,
input array
0 0 0
1 0 1
1 1 0
 output True or False


