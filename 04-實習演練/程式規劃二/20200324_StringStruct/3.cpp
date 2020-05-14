#include<stdio.h>
#include<stdlib.h>

typedef struct s{
	int id;
	int bio;
	int math;
	int avr;
}STUDENT;

void sort(STUDENT *, int, int);

int main(void){
	STUDENT student[20];
	int n=0;
	//input n
	printf("請輸入學生數: ");
	scanf("%d", &n);
	while(n<1) { printf("輸入錯誤, 請重新輸入: "); scanf("%d", &n); }
	//input grade
	for(int i=0;i<n;i++){
		printf("第%d位學生的成績(生物/微積分): ", i+1);
		scanf("%d %d",  &student[i].bio, &student[i].math);
		student[i].id=i+1;
		student[i].avr= ( student[i].bio + student[i].math )/2;
	}
	//selection
	int flag=1;
	while(flag){
		printf("@選單@\n(1)依生物排名.\n(2)依微積分排名.\n(3)依平均排名.\n(0)結束程式.\n請輸入: ");
		scanf("%d", &flag);
		while(flag<0 || flag>3) { printf("輸入錯誤, 請重新輸入: "); scanf("%d", &flag); }
	//依seletion 排序
		sort(student, flag, n);
		printf("學生\t生物\t微積分\t平均\t排名\n");
		int seq=1;
		for(int i=0;i<n;i++){
			//同分
			if(flag ==1  && i>0 && student[i].bio == student[i-1].bio){
				printf("%d\t%d\t%d\t%d\t%d\n", student[i].id, student[i].bio, student[i].math, student[i].avr,seq-1);
			}
			else if(flag ==2  && i>0 && student[i].math == student[i-1].math){
				printf("%d\t%d\t%d\t%d\t%d\n", student[i].id, student[i].bio, student[i].math, student[i].avr,seq-1);
			}
			else if(flag ==3  && i>0 && student[i].avr == student[i-1].avr){
				printf("%d\t%d\t%d\t%d\t%d\n", student[i].id, student[i].bio, student[i].math, student[i].avr,seq-1);
			}
			//非同分
			else {	
				printf("%d\t%d\t%d\t%d\t%d\n", student[i].id, student[i].bio, student[i].math, student[i].avr,seq);
				seq++;
			}
		}

	}
	return 0;
}
void sort(STUDENT *S, int chose, int size){
	//bio
	if(chose == 1){
		for(int i=0;i<size-1;i++){
			for(int j=i+1;j<size;j++){
				if(S[i].bio < S[j].bio){
					S[i].id = S[j].id + (S[j].id=S[i].id) - S[i].id;
					S[i].bio = S[j].bio + (S[j].bio=S[i].bio) - S[i].bio;
					S[i].math = S[j].math + (S[j].math=S[i].math) - S[i].math;
					S[i].avr = S[j].avr + (S[j].avr=S[i].avr) - S[i].avr;
				}
			}
		}
	//math
	}else if(chose == 2){
		for(int i=0;i<size-1;i++){
			for(int j=i+1;j<size;j++){
				if(S[i].math < S[j].math){
					S[i].id = S[j].id + (S[j].id=S[i].id) - S[i].id;
					S[i].bio = S[j].bio + (S[j].bio=S[i].bio) - S[i].bio;
					S[i].math = S[j].math + (S[j].math=S[i].math) - S[i].math;
					S[i].avr = S[j].avr + (S[j].avr=S[i].avr) - S[i].avr;
				}
			}
		}
	//avr
	}else if(chose == 3){
		for(int i=0;i<size-1;i++){
			for(int j=i+1;j<size;j++){
				if(S[i].avr < S[j].avr){
					S[i].id = S[j].id + (S[j].id=S[i].id) - S[i].id;
					S[i].bio = S[j].bio + (S[j].bio=S[i].bio) - S[i].bio;
					S[i].math = S[j].math + (S[j].math=S[i].math) - S[i].math;
					S[i].avr = S[j].avr + (S[j].avr=S[i].avr) - S[i].avr;
				}
			}
		}
	}
}