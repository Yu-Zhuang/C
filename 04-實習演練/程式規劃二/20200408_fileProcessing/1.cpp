#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct ps{
	char name[MAX];
	char id[MAX];
	double height,weight,BMI;
}PERSON;

void GET_FILE(char *file, PERSON *DB, int *DBsize, PERSON *del_DB, int *del_DBsize);

void DB_PRINT(PERSON *DB, PERSON *del_DB, int DBsize, int del_DBsize);
void DB_UNH_PRINT(PERSON *DB, PERSON *del_DB, int DBsize, int del_DBsize);
void DB_SORT(PERSON *DB, int DBsize);
int DB_FIND(PERSON *DB, int DBsize, char *target);
void DB_ADD(PERSON *DB, int *DBsize);
void DB_DELETE(PERSON *DB, int *DBsize, PERSON *del_DB, int *del_DBsize);
void DB_SAVE(PERSON *DB, int DBsize, PERSON *del_DB, int del_DBsize, char *file);

int CMP(char *str1, char *srt2);

int main(void){
	PERSON DB[MAX], del_DB[MAX];
	int DBsize=0, del_DBsize=0, chose=1;;
	char file[]="./BMI.txt";

	GET_FILE(file, DB, &DBsize, del_DB, &del_DBsize);
	DB_SORT(DB, DBsize);

	while(chose){
		start:
		printf("\t@主選單@\n(1)印出資料庫\n(2)印出不健康國民\n(3)新增國民\n(4)刪除國民\n(5)儲存資料\n(0)結束程式\n請輸入: "); scanf("%d", &chose);
		if(chose<0||chose>5) {printf("輸入錯誤!\n"); goto start; }
		if( ! chose) break;
		if(chose==1){
			DB_PRINT(DB, del_DB, DBsize, del_DBsize);
		}
		else if(chose==2){
			DB_UNH_PRINT(DB, del_DB, DBsize, del_DBsize);
		}
		else if(chose==3){
			DB_ADD(DB, &DBsize);
			DB_SORT(DB, DBsize);
		}
		else if(chose==4){
			DB_DELETE(DB, &DBsize, del_DB, &del_DBsize);
		}
		else if(chose==5){
			DB_SAVE(DB, DBsize, del_DB, del_DBsize, file);
		}
	}

	return 0;
}
void DB_SAVE(PERSON *DB, int DBsize, PERSON *del_DB, int del_DBsize, char *file){
	FILE *fptr=fopen(file,"w");
	char str[]="國人體重資訊\n", str1[]="已刪除資料\n", str2[]="----------------------------------\n";
	fputs(str,fptr);
	fputs(str2,fptr);
	char tmp[MAX];
	for(int i=0;i<DBsize;i++){
		fputs(DB[i].name,fptr); fputc('\t',fptr);
		fputs(DB[i].id,fptr); fputc('\t',fptr);
		sprintf(tmp,"%.2lf",DB[i].height); fputs(tmp,fptr); fputc('\t',fptr);
		sprintf(tmp,"%.2lf",DB[i].weight); fputs(tmp,fptr); fputc('\t',fptr);
		sprintf(tmp,"%.2lf",DB[i].BMI); fputs(tmp,fptr); fputc('\n',fptr);
	}
	fputs(str2,fptr);

	fputs(str1,fptr);
	fputs(str2,fptr);
	for(int i=0;i<del_DBsize;i++){
		fputs(del_DB[i].name,fptr); fputc('\t',fptr);
		fputs(del_DB[i].id,fptr); fputc('\t',fptr);
		sprintf(tmp,"%.2lf",del_DB[i].height); fputs(tmp,fptr); fputc('\t',fptr);
		sprintf(tmp,"%.2lf",del_DB[i].weight); fputs(tmp,fptr); fputc('\t',fptr);
		sprintf(tmp,"%.2lf",del_DB[i].BMI); fputs(tmp,fptr); fputc('\n',fptr);
	}
	fputs(str2,fptr);	
}
void DB_DELETE(PERSON *DB, int *DBsize, PERSON *del_DB, int *del_DBsize){
	char tn[MAX];
	start3:
	printf("輸入身分證: "); scanf("%s", tn); getchar();
	if(DB_FIND(DB, DBsize[0],tn)==0) { printf("此帳號不存在!\n"); goto start3; }

	int tmp=0;
	printf("確定刪除? 1確定,  0不刪除 : "); scanf("%d", &tmp);
	if(tmp==0) return;

	int site=DB_FIND(DB, DBsize[0],tn)-1;
	/*
	strcpy(del_DB[del_DBsize[0]].name,DB[site].name);
	strcpy(del_DB[del_DBsize[0]].id,DB[site].id);	
	del_DB[del_DBsize[0]].height=DB[site].height;
	del_DB[del_DBsize[0]].weight=DB[site].weight;
	del_DB[del_DBsize[0]].BMI=DB[site].BMI;
	*/
	del_DB[del_DBsize[0]]=DB[site];
	del_DBsize[0]++;

	for(int i=site;i<DBsize[0];i++){
		DB[i]=DB[i+1];
		/*
		strcpy(DB[i].name,DB[i+1].name);
		strcpy(DB[i].id, DB[i+1].id);
		DB[i].height=DB[i+1].height;
		DB[i].weight= DB[i+1].weight;
		DB[i].BMI=DB[i+1].BMI;
		*/
	}
	DBsize[0]--;
}
void DB_SORT(PERSON *DB, int DBsize){
	char tmp[MAX];
	double tnum=0;
	int i=0,j=0;
	for(i=0;i<DBsize-1;i++){
		for(j=i;j<DBsize;j++){
			if(strcmp(DB[i].id, DB[j].id)>0){
				strcpy(tmp, DB[i].name); strcpy(DB[i].name, DB[j].name); strcpy(DB[j].name, tmp);
				strcpy(tmp, DB[i].id); strcpy(DB[i].id, DB[j].id); strcpy(DB[j].id, tmp);
				// a = b + (b=a) -a;
				tnum=DB[i].height; DB[i].height=DB[j].height; DB[j].height=tnum;
				tnum=DB[i].weight; DB[i].weight=DB[j].weight; DB[j].weight=tnum;
				tnum=DB[i].BMI; DB[i].BMI=DB[j].BMI; DB[j].BMI=tnum;
			}
		}
	}
}
void DB_ADD(PERSON *DB, int *DBsize){
	char tn[MAX], i[MAX];
	double h=0, w=0;
	start2:
	printf("輸入身分證: "); scanf("%s", i); getchar();
	if(DB_FIND(DB, DBsize[0],i)) { printf("已存在!\n"); goto start2; }
	printf("輸入姓名: "); scanf("%s", tn); getchar();
	printf("輸入身高: "); scanf("%lf", &h);
	while(h<=0) { printf("錯誤! 請重輸: "); scanf("%lf", &h); }
	printf("輸入體重: "); scanf("%lf", &w);
	while(h<=0) { printf("錯誤! 請重輸: "); scanf("%lf", &w); }

	strcpy(DB[DBsize[0]].name, tn);
	strcpy(DB[DBsize[0]].id, i);
	DB[DBsize[0]].height=h;
	DB[DBsize[0]].weight=w;
	double tmp=h/100;
	tmp=tmp*tmp;
	DB[DBsize[0]].BMI=w/tmp;
	DBsize[0]++;
}
int DB_FIND(PERSON *DB, int DBsize, char *target){
	for(int i=0;i<DBsize;i++){
		if( strcmp(DB[i].id, target)==0) return i+1;
	}
	return 0;
}
int CMP(char *str1, char *str2){
	int len_1=strlen(str1), len_2=strlen(str2);
	if(len_1 == len_2) return strcmp(str1, str2);
	return len_1-len_2;
}
void DB_UNH_PRINT(PERSON *DB, PERSON *del_DB, int DBsize, int del_DBsize){
	char str[]="國人體重資訊", str2[]="----------------------------------";
	puts(str); puts(str2);
	for(int i=0;i<DBsize;i++){
		if(DB[i].BMI>=24||DB[i].BMI<18.5)
			printf("%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", DB[i].name, DB[i].id, DB[i].height, DB[i].weight, DB[i].BMI);
	}
	puts(str2);	
}
void DB_PRINT(PERSON *DB, PERSON *del_DB, int DBsize, int del_DBsize){
	char str[]="國人體重資訊", str1[]="已刪除資料", str2[]="----------------------------------";
	puts(str); puts(str2);
	for(int i=0;i<DBsize;i++){
		printf("%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", DB[i].name, DB[i].id, DB[i].height, DB[i].weight, DB[i].BMI);
	}
	puts(str2);

	puts(str1); puts(str2);
	for(int i=0;i<del_DBsize;i++){
		printf("%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", del_DB[i].name, del_DB[i].id, del_DB[i].height, del_DB[i].weight, del_DB[i].BMI);
	}
	puts(str2);

}

void GET_FILE(char *file, PERSON *DB, int *DBsize, PERSON *del_DB, int *del_DBsize){
	FILE *fptr=fopen(file, "r");
	char tmp[MAX][MAX];
	char ret[MAX][MAX][MAX];
	int flag=0, i=0, j=0, k=0, del=0;

	while( fgets(tmp[i],MAX,fptr)!=NULL){
		if(flag==0&&tmp[i][2]=='-') { flag=1; i++; continue; } //start
		if(flag==1&&tmp[i][2]=='-') { flag=0; if(!del) del=1; i++; continue;} //end
		if(flag&&tmp[i][0]!=' '){
			k=0;
			char *token;
			char copy[MAX];
			strcpy(copy,tmp[i]);
			token=strtok(copy,"\t");
			while(token){ strcpy(ret[j][k],token); k++; token=strtok(NULL,"\t"); }
			j++; // j = 總共幾個人line
			if(del) del++; // del 有幾個人被刪除
		}
		i++;
	}
	del-=1;
	DBsize[0]=j-del; //DBsize
	del_DBsize[0]=del; //del_DBsize

	for(int i=0;i<DBsize[0];i++){
			strcpy(DB[i].name,ret[i][0]); 
			strcpy(DB[i].id,ret[i][1]); 
			sscanf(ret[i][2], "%lf",&DB[i].height); 
			sscanf(ret[i][3],"%lf",&DB[i].weight); 
			sscanf(ret[i][4],"%lf",&DB[i].BMI); 
		
	}
	int a=0;
	for(int i=DBsize[0];i<DBsize[0]+del_DBsize[0];i++){
			strcpy(del_DB[a].name,ret[i][0]); 
			strcpy(del_DB[a].id,ret[i][1]); 
			sscanf(ret[i][2],"%lf", &del_DB[a].height); 
			sscanf(ret[i][3],"%lf",&del_DB[a].weight); 
			sscanf(ret[i][4],"%lf",&del_DB[a].BMI); 
		
		a++;
	}
	fclose(fptr);
}