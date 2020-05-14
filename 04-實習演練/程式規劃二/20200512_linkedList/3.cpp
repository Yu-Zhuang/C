# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define MAX 30000
int main(void){
	while(1){
		cnt ++;
		char input[MAX] = {'\0'};
		int n=0, nums[12]={0};
		scanf("%[^\n]", input); getchar();
		char *take = strtok(input," \t\n");
		if(take == NULL) break;
		while(take){
			sscanf(take, "%d", &nums[n]);
			n += 1;
			take = strtok(NULL, " \t\n");
		}
		int flag = 0, count = 0;
		for(int i=0;i<n && (!flag);i++){
			count = 0;
			for(int j=0;j<n && (!flag);j++){
				if(nums[i] == nums[j]) 
					count ++;
				if(count > n/2)
					{printf("%d\n",nums[j]); flag = 1;}
			}
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}