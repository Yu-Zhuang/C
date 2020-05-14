#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

double colision=0;
void Filegenetor();
void ReadFile(char ary[][4], int *N);
void HashA(char A[][4], char ary[][4], int N);
void FindE(char A[][4], char target[]);

int main(void){
    //變數宣告與初始化;
    srand(time(NULL));
    int times=1;
    int N=0; //幾組字串;
    char A[100][4];
    char ary[101][4]; //放字串;
    char test[4]="lad"; //test case;
    //執行運算
    while(times){
        printf("\n程式執行次數: ");
        scanf("%d", &times);
        colision=0; //init colision;
        for(int i=0;i<times;i++){
            for(int i=0;i<100;i++) memset(A[i],'\0',4); //init A[][];
            for(int i=0;i<101;i++) memset(ary[i],'\0',4); //init ary[][];
            Filegenetor(); //產生隨機字串(1~3)寫在一個file中;
            ReadFile(ary, &N);  //讀取file, 並將字串放進 ary[][]中;
            HashA(A,ary,N); //產生 字串對應key, 並放入A[key][]中;
            FindE(A, ary[2]);  //在A中 找 目標字串[];
            printf("\n===================END===================\n");
        }
        if(times) printf("\n________ 平均碰撞次數: %lf ________\n",colision/times-15);
    }
    printf("\n**************程式執行結束**************\n");
    return 0;
}

void FindE(char A[][4], char target[]){
    int flag=1, key=0, CP=0;
    int func[3]={1,27,223};
    printf("\n===================FIND===================\n");
    for(int i=0;target[i]!='\0';i++) key+=(target[i]-'a'+1)*func[i]; //hash compution;
    key=key%100;
    if(A[key][0] != '\0'){
        printf("find at: %d.\n", key);
        for(int i=0;i<3;i++) printf("%c\t%c\n",target[i], A[key][i]);
        CP++; //CP;
    }
    else printf("not found!\n");
    printf("FIND()比較%d次.\n", CP); //CP;
}
void HashA(char A[][4], char ary[][4], int N){
    int index=0, count=0, CP=0;
    int record[100]={0}, func[3]={1,27,223};
    printf("\n===================KEY===================\n");
    for(int i=0;i<N;i++){
        if(i%5==0) printf("%d:\t",i+1);
        for(int j=0;ary[i][j]!='\0';j++) index+=(ary[i][j]-'a'+1)*func[j]; //hash compution;
        index=index%100;
        printf("%d\t",index);
        if((i+1)%5==0) printf("\n");
        record[index]++;
        if(record[index] > 1) { count++; colision++; } //統計碰撞次數;
        for(int k=0;k<3;k++) A[index][k]=ary[i][k]; //hash put str into A[][]; 
        index=0;
        CP++; //CP;
    }

    printf("\nKEY\tCOLISION\t\n");
    for(int i=0;i<100;i++){ 
        if(record[i]>1){
            printf("%d\t",i);
            for(int j=0;j<record[i]-1;j++) printf("*");
            printf("\n");
        }
    }
    printf("colision times: %d\n", count);//print colision
    printf("HashA()比較%d次.\n", CP); //CP;
}
void ReadFile(char ary[][4], int *N){
    FILE *fptr; //指向檔案的指標
    char ch; //接收讀取字元
    int i=0,j=0,flag=0;
    printf("\n===================FILE===================\n");
    fptr=fopen("/Users/yuzhuanglin/Desktop/F.cpp","r"); 
    if(fptr!=NULL){
        printf("%d:\t",i+1);
        while((ch=getc(fptr))!=EOF) {
            printf("%c",ch); //print element;
            
            if(ch>='a' && ch<='z'){ //put element to ary[][];
                ary[i][j]=ch;
                j++;
                flag=1;
            }
            if((ch<'a'||ch>'z')&&flag) { j=0; i++; flag=0; printf("%d:\t",i+1); }
        }
        fclose(fptr);
    }
    *N=i;
}
void Filegenetor(){
    FILE *fptr;
    fptr=fopen("/Users/yuzhuanglin/Desktop/F.cpp","w");
    char ch;
    for(int i=0;i<100;i++){
        for(int j=0;j<(rand()%3+1);j++){
            ch=rand()%26+97;
            fputc(ch, fptr);
        }
        fputc('\n',fptr);
    }
    fclose(fptr);
}






