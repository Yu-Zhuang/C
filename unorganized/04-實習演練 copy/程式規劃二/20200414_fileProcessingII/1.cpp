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
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// define string max size
#define MAX 100
// define data type
typedef struct p{
    int n;
    char name[MAX];
    char id[MAX];
    double height, weight, bmi;
}PERSON;
// function announcement
int FILE_PUT();
void FILE_PRINT();
bool FILE_FIND(int n);
void FILE_UH_PRINT();
void FILE_ADD();
void FILE_UPDATE();
void FILE_DELET();
void FILE_REPUT();
void FIND();
// main
int main(void){
    int flag=1, run=0;
    run=FILE_PUT(); // write to .dat success or not?
    while(flag&&run){  
        start:
        printf("\t@主選單@\n(1)顯示國民\n(2)尋找國民\n(3)印出不健康國民\n(4)新增國民\n(5)編輯國民\n(6)刪除國民\n(7)存回txt檔\n(0)結束程式\n請輸入選擇: ");
        scanf("%d", &flag);
        // FPD
        while(flag<0||flag>7) {printf("err: 輸入錯誤!\n"); goto start; }
        switch(flag){
            case 1: FILE_PRINT(); break;
            case 2: FIND(); break;
            case 3: FILE_UH_PRINT(); break;
            case 4: FILE_ADD(); break;
            case 5: FILE_UPDATE(); break;
            case 6: FILE_DELET(); break;
            case 7: FILE_REPUT(); break;
            default: break;
        }

    }
    // if not sucess 
    if(!run) printf("can't open file\n");
    return 0;
}
void FIND(){
    int input=0;
    printf("輸入欲搜尋國民: ");
    scanf("%d", &input);
    FILE_FIND(input);
}
void FILE_REPUT(){
    FILE *ptmp = fopen("./BMI1.txt","w");
    if(!ptmp) printf("can't open file\n");
    else{
        fclose(ptmp);
        FILE *ptxt = fopen("./BMI1.txt","a");
        FILE *pdat = fopen("./BMI1.dat", "rb+");
        if(! pdat || !ptxt) printf("can't open file.\n");
        else{
            char str1[]="國人體重資訊\n----------------------------------\n";
            fputs(str1, ptxt);

            int list[MAX]={0};
            PERSON p={0,"","",0,0,0};
            while( !feof(pdat) ){
                fread(&p,sizeof(PERSON), 1,pdat);
                if(p.n>0){
                    list[p.n]++;
                }
            }
            rewind(pdat);
            for(int i=0;i<MAX;i++){
                if(list[i]){
                    while( !feof(pdat) ){
                        fread(&p,sizeof(PERSON), 1,pdat);
                        if(p.n==i){
                            fprintf(ptxt, "%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", p.n, p.name, p.id, p.height, p.weight, p.bmi);
                            break;
                        }
                    }
                    rewind(pdat);      
                }
            }             
        }
        fclose(pdat);
        fclose(ptxt);    
    }
    return;
}
void FILE_DELET(){
    FILE *pdat = fopen("./BMI1.dat", "rb+");
    FILE *pdel = fopen("./deleted.txt","a");
    if(! pdat || !pdel) printf("can't open file.\n");
    else{
        int n=0;
        printf("請輸入欲刪除編號: "); scanf("%d", &n);
        if( ! FILE_FIND(n)) printf("無此編號\n");
        else{
            int tmp=0;
            printf("確定要刪? 1確定 0不刪: "); scanf("%d", &tmp);
            if(tmp){
                PERSON p={0,"","",0,0,0};
                int site=0;
                while( !feof(pdat)){
                    fread(&p, sizeof(PERSON), 1, pdat);
                    if(p.n==n){
                        fprintf(pdel,"\n%d %s %s %.1lf %.1lf %.1lf", p.n, p.name, p.id, p.height, p.weight, p.bmi);
                        break;
                    }
                    site++;
                }
                rewind(pdat);
                fseek(pdat, (site)*sizeof(PERSON), SEEK_SET);
                PERSON empty={0,"","",0,0,0};
                fwrite(&empty, sizeof(PERSON), 1, pdat);
            }
        }
    }
    fclose(pdat);
    fclose(pdel);   
}
void FILE_UPDATE(){
    FILE *pdat = fopen("./BMI1.dat", "rb+");
    if(! pdat) printf("can't open file.\n");
    else{
        int n=0;
        
        printf("請輸入欲編輯: "); scanf("%d", &n);
        if( ! FILE_FIND(n)) printf("無此編號\n");
        else{
            PERSON p={0,"","",0,0,0};
            int site=0;
            while( !feof(pdat)){
                fread(&p, sizeof(PERSON), 1, pdat);
                if(p.n==n) break;
                site++;
            }
            rewind(pdat);
            fseek(pdat, (site)*sizeof(PERSON), SEEK_SET);
            printf("新 姓名 身分證號 身高 體重: "); 
            scanf("%s %s %lf %lf", p.name, p.id, &p.height, &p.weight);
            p.n=n;
            p.bmi = p.weight / p.height / p.height * 10000;
            fwrite(&p, sizeof(PERSON), 1, pdat);
        }        
    }
    fclose(pdat);   
}
void FILE_ADD(){
    FILE *pdat = fopen("./BMI1.dat", "ab");
    if(! pdat) printf("can't open file.\n");
    else{
        int n=0;
        PERSON p={0,"","",0,0,0};
        printf("請輸入欲增加編號: "); scanf("%d", &n);
        if(n==0 || FILE_FIND(n)) printf("此編號不可使用\n");
        else{
            printf("請依序輸入 姓名 身分證號 身高 體重: "); 
            scanf("%s %s %lf %lf", p.name, p.id, &p.height, &p.weight);
            p.n=n;
            p.bmi = p.weight / p.height / p.height * 10000;
            fwrite(&p, sizeof(PERSON),1, pdat);
        }
    }
    fclose(pdat);
}
bool FILE_FIND(int n){
    FILE *pdat = fopen("./BMI1.dat", "rb");
    int flag=0;
    if(! pdat) printf("can't open file.\n");
    else{
        while(! feof(pdat)){
            PERSON p={0,"","",0,0,0};
            fread(&p, sizeof(PERSON), 1, pdat);
            // 如果 找到 就顯示
            if(p.n == n){
                printf("%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", p.n, p.name, p.id, p.height, p.weight, p.bmi);
                flag=1;
                break;
            }
        }        
    }
    fclose(pdat);     
    if(flag) return true; 
    return false;
}
void FILE_UH_PRINT(){
    FILE *pdat = fopen("./BMI1.dat", "rb");
    if(! pdat) printf("can't open file.\n");
    else{
        while(! feof(pdat)){
            PERSON p={0,"","",0,0,0};
            // 讀取 dat資料
            fread(&p, sizeof(PERSON), 1, pdat);
            // 如果 超出健康 range 顯示該資料
            if(p.n>0&& (p.bmi>=24||p.bmi<18.5)) printf("%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", p.n, p.name, p.id, p.height, p.weight, p.bmi);
        }        
    }
    fclose(pdat);   
}
void FILE_PRINT(){
    FILE *pdat = fopen("./BMI1.dat", "rb");
    if(! pdat) printf("can't open file.\n"); 
    else{
        while(! feof(pdat)){
            PERSON p={0,"","",0,0,0};
            // 讀取 dat資料
            fread(&p, sizeof(PERSON), 1, pdat);
            // 印出
            if(p.n>0) printf("%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", p.n, p.name, p.id, p.height, p.weight, p.bmi);
        }        
    }
    fclose(pdat);
}
// 將txt檔 存回 txt檔
int FILE_PUT(){
    FILE *ptxt = fopen("./BMI1.txt","r");
    FILE *pdat = fopen("./BMI1.dat", "wb");
    //  如果開失敗 return 回去
    if(!ptxt || !pdat){
        printf("\terr: file can't open!\n");
        fclose(ptxt);
        fclose(pdat);        
        return 0;
    // 開成功
    }else{
        char tmp[MAX];
        // 將前兩行不需要的讀掉
        for(int i=0;i<2;i++) fscanf(ptxt, "%s", tmp);
        //  開始將資料 讀進 dat檔
        while( ! feof(ptxt)){
            PERSON p={0,"","",0,0,0};
            //  從txt檔 資料
            fscanf(ptxt, "%d %s %s %lf %lf %lf", &p.n, p.name, p.id, &p.height, &p.weight, &p.bmi );
            //  將資料 寫入 dat檔
            if(p.n>0) fwrite(&p, sizeof(PERSON), 1 ,pdat);
        }    
    }
    fclose(ptxt);
    fclose(pdat);
    return 1;
}

*/
