#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 100000
int main(void){
	srand(time(NULL));
	char str[6][MAX];
	for(int i=0;i<6;i++) memset(str[i],'\0',MAX);
	//input
	printf("請輸入姓名: ");
	scanf("%[^\n]", str[0]); 
	printf("請輸入五句話:\n");
	for(int i=1;i<6;i++) { getchar(); scanf("%[^\n]", str[i]); }
	//add name
	int r=rand()%5+1;
	int nlength=strlen(str[0]);
	int plength=strlen(str[r]);
	for(int i=plength;i>=0;i--) str[r][i+nlength+1]=str[r][i];
	for(int i=0;i<nlength;i++) str[r][i]=str[0][i]; 
	str[r][nlength]=',';
	//select
	char chose='t';
	while(chose!='q'){
		getchar();
		printf("<t>對話, <q>離開: ");
		scanf("%c",&chose);
		while(chose!='t' && chose!='q') { printf("輸入錯誤, 請重新輸入: "); getchar(); scanf("%c",&chose); }
		if(chose == 'q') break;
		if(chose == 't'){
			puts(str[(rand()%5+1)]);
		}
	}

	return 0;
}