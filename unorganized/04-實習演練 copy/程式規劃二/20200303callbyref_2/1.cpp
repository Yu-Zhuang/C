#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void inputF(int n, int list[][3], int *seq);
void seletF(int list[][3], int *seq, int n);
void sortedF(int depend, int list[][3], int *seq, int n);

int main(void){
	int seq[20]={0}, list[20][3]={0}, n=0;
	while(n>20||n<1){
		printf("學生數:");
		scanf("%d", &n);
		if(n>20||n<1) printf("請重新輸入\n");
	}

	inputF(n,list, seq);
	seletF(list, seq, n);

	return 0;
}
void sortedF(int depend, int list[][3], int *seq, int n){
	int tmp, i, j;
	//init
	for(int i=0;i<n;i++) seq[i]=i+1; 

	int copy[20]={0};
	for(int i=0;i<n;i++) { copy[i]=list[i][depend];}printf("\n");

	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(copy[j]>copy[i]){
				tmp=copy[j];
				copy[j]=copy[i];
				copy[i]=tmp;
				tmp=seq[j];
				seq[j]=seq[i];
				seq[i]=tmp;
			}
		}
	}
}
void seletF(int list[][3], int *seq, int n){
	int selec=0, flag, tmp[2]={0};
	tmp[0]=-1; tmp[1]=0;
	while(1){
		flag=0;
		printf("選項: (1)生物排名 (2)微積分排名 (3)平均排名 (-1)結束: ");
		scanf("%d", &selec);
		if(selec == 1) {flag=1; sortedF(0, list, seq, n); }
		else if(selec == 2) {flag=1; sortedF(1, list, seq, n); }
		else if(selec == 3) {flag=1; sortedF(2, list, seq, n); }
		else if(selec == -1) break;
		else printf("輸入錯誤, 請重新輸入.\n");
		if(flag){
			for(int i=0;i<n;i++){
				if(list[seq[i]-1][selec-1]!=tmp[0]){
					printf("排名%d 學生%d 生物%d 微積分%d 平均%d\n", i+1, seq[i], list[seq[i]-1][0], list[seq[i]-1][1], list[seq[i]-1][2]);
					tmp[0]=list[seq[i]-1][selec-1];
					tmp[1]=i+1;
				}
				else
					printf("排名%d 學生%d 生物%d 微積分%d 平均%d\n", tmp[1], seq[i], list[seq[i]-1][0], list[seq[i]-1][1], list[seq[i]-1][2]);
			}
		}
	}
}
void inputF(int n, int list[][3], int *seq){
	for(int i=0;i<n;i++){
		scanf("%d %d", &list[i][0], &list[i][1]);
		list[i][2] = (list[i][0]+list[i][1])/2;
		seq[i]=i+1;
	}
	for(int i=0;i<n;i++) printf("第%d位學生成績(生物/微積分): %d %d\n", seq[i], list[i][0], list[i][1]);
}
