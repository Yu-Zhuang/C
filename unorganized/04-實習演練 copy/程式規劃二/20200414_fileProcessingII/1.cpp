#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct person{
	int n;
	char name[MAX];
	char id[MAX];
	double height;
	double weight;
	double bmi;
}PERSON;
//	FUNCTION
void FILE_PUT();
void FILE_PRINT();
int FILE_FIND(int n);
void FILE_UH_FIND();
void FILE_ADD(int n);
void FILE_DEDIT(int n);
void FILE_DELET(int n);
void FILE_REPUT();
//	MAIN
int main(void){
	// 將txt檔 寫入 dat檔
	FILE_PUT();
	int chose=1;
	while(chose){
		// 輸入 選擇
		printf("\t@主選單@\n(1)印出BMI.dat\n(2)搜尋國民\n(3)搜尋過重過輕國民\n(4)新增國民\n(5)編輯國民\n(6)刪除國民\n(7)照編號存回txt檔\n(0)結束\n請輸入: ");
		scanf("%d", &chose);
		// =0結束
		if(chose==0) break;
		// =1 印出dat檔
		if(chose==1) FILE_PRINT();
		// =2 查詢
		else if(chose==2){
			int n=0;
			//輸入查詢編號
			printf("輸入欲查詢國名編號: "); scanf("%d", &n);
			// 如果沒找到 顯示"無此國民"
			printf("\n======== 查詢國民 =========\n");
			if( ! FILE_FIND(n)) printf("無此國民\n");
			printf("=============================\n");
		}
		// =3 顯示不健康國民
		else if(chose==3){
			FILE_UH_FIND();		
		}
		// 新增國民
		else if(chose==4){
			int n=0;
			printf("請輸入欲增加國民編號: ");
			scanf("%d", &n);
			FILE_ADD(n);
		}
		// 編輯國民
		else if(chose==5){
			int n=0;
			printf("請輸入欲編輯國民編號: ");
			scanf("%d", &n);
			FILE_DEDIT(n);
		}
		else if(chose==6){
			int n=0;
			printf("請輸入欲刪除國民編號: ");
			scanf("%d", &n);
			FILE_DELET(n);
		}
		else if(chose==7){
			FILE_REPUT();
		}

	}
	
    return 0;
}
void FILE_REPUT(){
	//
	FILE *tmp=fopen("./BMI1.txt","w"); fclose(tmp);
	FILE *ftxt=fopen("./BMI1.txt","a");
	FILE *fptr=fopen("./BMI1.dat","rb");
	//
	char title[]="國人體重資訊\n----------------------------------\n";
	fputs(title,ftxt);
	int list[MAX]={0};
	
	while( ! feof(fptr) ){
		PERSON p={0,"","",0,0,0};
		if( fread(&p,sizeof(PERSON), 1, fptr) == 1 ){
			if(p.n>=0)
				list[p.n]=1;				
		}
		else break;
	}

	for(int i=0;i<MAX;i++){
		if(list[i]){
			int site=0;
			PERSON p={0,"","",0,0,0};
			rewind(fptr);
			while(! feof(fptr)){
				fread(&p,sizeof(PERSON),1,fptr);
				site++;
				if( p.n == i ) break;
		    }
		    fseek(fptr,(site-1)*sizeof(PERSON), SEEK_SET );
		    if( fread(&p,sizeof(PERSON),1,fptr) == 1 ){
		    	if(p.n>0)
		    		fprintf(ftxt, "%d\t%s\t%s\t%.1lf%.1lf\t%.1lf\n", p.n, p.name, p.id, p.height, p.weight, p.bmi);
			}
		}
	}

	fclose(ftxt);
	fclose(fptr);	
}
void FILE_DELET(int n){
	if( ! FILE_FIND(n)){
		printf("[ err: 無此國民! ]\n");
		return ;
	}else{
		FILE *fptr=fopen("./BMI1.dat", "rb+");
		FILE *ftxt=fopen("./deleted.txt", "a");
		PERSON p={0,"","",0,0,0};
		int site=0;

		while(! feof(fptr)){
	    	PERSON p={0,"","",0,0,0};
			fread(&p,sizeof(PERSON),1,fptr);
			site++;
			if( p.n == n ){
				fprintf(ftxt,"\n%d\t%s\t%s\t%.1lf\t%.1lf\t%.1f",p.n,p.name,p.id,p.height,p.weight,p.bmi);
				break;
			}
	    } 
		fseek(fptr, (site-1)*(sizeof(PERSON)), SEEK_SET);
		p.n=0;
		strcpy(p.name,"");
		strcpy(p.id,"");
		p.weight=0;
		p.height=0;
		p.bmi=0;
		fwrite(&p, sizeof(PERSON), 1, fptr);
		fclose(ftxt);
	    fclose(fptr);
	}
}

void FILE_DEDIT(int n){
	if(! FILE_FIND(n)){
		printf("[ err: 無此國民! ]\n");
		return ;
	}else{
		FILE *fptr=fopen("./BMI1.dat", "rb+");
		PERSON p={0,"","",0,0,0};
		int site=0;

		while(! feof(fptr)){
	    	PERSON p={0,"","",0,0,0};
			fread(&p,sizeof(PERSON),1,fptr);
			site++;
			if( p.n == n ) break;
	    } 
		fseek(fptr, (site-1)*(sizeof(PERSON)), SEEK_SET);

		printf("請依序輸入新 姓名 身份字號 身高 體重: ");
		scanf("%s %s %lf %lf", p.name, p.id, &p.height, &p.weight); getchar();
		p.n=n;
		p.bmi = p.weight / ((p.height*p.height)/10000);
		fwrite(&p,sizeof(PERSON),1,fptr);

	    fclose(fptr);
	}
}
void FILE_ADD(int n){
	if(FILE_FIND(n)){
		printf("[ err: 已有此國民! ]\n");
		return ;
	}else{
		FILE *fptr=fopen("./BMI1.dat", "ab");
		PERSON p={0,"","",0,0,0};
		printf("請依序輸入 姓名 身份字號 身高 體重: ");
		scanf("%s %s %lf %lf", p.name, p.id, &p.height, &p.weight); getchar();
		p.n=n;
		p.bmi = p.weight / ((p.height*p.height)/10000);
		fwrite(&p,sizeof(PERSON),1,fptr);

	    fclose(fptr);
	}
}

// 找過輕重國民
void FILE_UH_FIND(){
	FILE *fptr=fopen("./BMI1.dat","rb");
  	int flag=0;
  	printf("\n========= 不健康國民資料 ========\n");
    while(! feof(fptr)){
		PERSON p={0,"","",0,0,0};
		flag=0;
		if(fread(&p,sizeof(PERSON),1,fptr)==1){
			if( p.n!=0&& (p.bmi>=24||p.bmi<18.5 )) {
				printf("%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\n",p.n,p.name,p.id,p.height,p.weight,p.bmi);
			}
		}
    }
   	printf("==============================\n\n");
    fclose(fptr);
}
// 找國民
int FILE_FIND(int n){
	FILE *fptr=fopen("./BMI1.dat","rb");
    while(! feof(fptr)){
    	PERSON p={0,"","",0,0,0};
		fread(&p,sizeof(PERSON),1,fptr);
		if( p.n == n ) {
			printf("%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\n",p.n,p.name,p.id,p.height,p.weight,p.bmi);
			fclose(fptr);
			return 1;
		}
    } 	
    fclose(fptr);
    return 0;
}
//	印出dat檔
void FILE_PRINT(){
	FILE *fptr=fopen("./BMI1.dat","rb");
  	int flag=0;
  	printf("\n========= 國民資料 ========\n");
    while(! feof(fptr)){
    	PERSON p={0,"","",0,0,0};
		flag=0;
		fread(&p,sizeof(PERSON),1,fptr);
		if(p.height!=0) 
			printf("%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\n",p.n,p.name,p.id,p.height,p.weight,p.bmi);
    }
    printf("==============================\n\n");
    fclose(fptr);
}
// 將txt檔 寫入 dat 檔
void FILE_PUT(){
	// 以rb開 txt檔 , wb開dat檔
	FILE *ftxt=fopen("./BMI1.txt","r");
	FILE *fptr=fopen("./BMI1.dat","wb");
    char take[100]={'\0'};
    int flag=0;
    while( feof(ftxt)==0 ){
		if(flag==0) fgets(take,100,ftxt);
		if(flag==0&&take[2]=='-') { flag=1; continue; }
		if(flag){
			PERSON p={-1,"","",0,0,0};
		    fscanf(ftxt,"%d%s%s%lf%lf%lf",&p.n, p.name,p.id, &p.height, &p.weight, &p.bmi);
		    fwrite(&p,sizeof(PERSON),1,fptr);
		} 
    }
	fclose(ftxt);
	fclose(fptr);
}
