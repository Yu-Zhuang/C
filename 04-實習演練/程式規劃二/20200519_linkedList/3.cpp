# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void){
	char paper[100001][9];
	char templet[4][9];
	for(int i=0;i<4;i++){
		scanf("%s", templet[i]);
		getchar();
	}
	long long int n=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", paper[i]);
		getchar();
	}

	long long int ret = 0;
	char rat[] = "0 0 0 0 0 0 0";
	int money[7]={2000000, 200000, 40000, 10000, 4000, 1000, 200};

	// go through each paper
	for(int i=0;i<n;i++){
		int tmp = 10;
		for(int j=0;j<4;j++){
			if( (strcmp(paper[i], templet[j]) == 0) && j == 0){
				tmp = 0;
				break;
			}
			else if( strcmp(paper[i], templet[j]) == 0 && j!=0){
				if(tmp >= 1)
					tmp = 1;
			}
			else if( strcmp(&paper[i][1], &templet[j][1]) == 0 && j!=0){
				if(tmp >= 2)
					tmp = 2;
			}
			else if( strcmp(&paper[i][2], &templet[j][2]) == 0  && j!=0){
				if(tmp >=3)
					tmp = 3;
			}
			else if( strcmp(&paper[i][3], &templet[j][3]) == 0  && j!=0){
				if(tmp >=4)
					tmp = 4;
			}
			else if( strcmp(&paper[i][4], &templet[j][4]) == 0 && j!=0 ){
				if(tmp >=5)
					tmp = 5;
			}
			else if( strcmp(&paper[i][5], &templet[j][5]) == 0  && j!=0){
				if(tmp >=6)
					tmp = 6;
			}
		}
		if(tmp != 10){
			switch(tmp){
				case 0: { ret+=2000000; rat[0]+=1; }; break;
				case 1: { ret+=200000; rat[2]+=1; }; break;
				case 2: { ret+=40000; rat[4]+=1; }; break;
				case 3: { ret+=10000; rat[6]+=1; }; break;
				case 4: { ret+=4000; rat[8]+=1; }; break;
				case 5: { ret+=1000; rat[10]+=1; }; break;
				case 6: { ret+=200; rat[12]+=1; }; break;
				default: break;
			}
		}
	}
	puts(rat);
	printf("%lld\n", ret);
	return 0;
}