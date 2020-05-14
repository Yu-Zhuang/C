#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 202

int main(void){
    char str[3][MAX]; 
    for(int i=0;i<3;i++) memset(str[i],'\0',MAX);
    int tmp=0, i=0, j=0, k=0, len_1=0, len_2=0;
    char sum=0;

    //input two interger ( < 1e+(MAX-2) );
    printf("input a interger ( number<1e+%d ):", MAX-2);
    scanf("%s", &str[0][1]);
    printf("input another interger ( number< 1e+%d ):", MAX-2);
    scanf("%s", &str[1][1]);

    //conpution
    len_1=strlen(&str[0][1]);  
    len_2=strlen(&str[1][1]);
    i=len_1;  
    j=len_2;

    while( j>0 || i>0 || sum>0 ){
        if(str[0][i]) { sum+=(str[0][i]-'0'); i--; }
        if(str[1][j]) { sum+=(str[1][j]-'0'); j--; }
        if(sum>9) { tmp=1; sum-=10; }
        str[2][k]= sum+'0' ; k++;
        sum=tmp;
        tmp=0;
    }
    //output sum
    for(int g=k-1;g>=0;g--) printf("%c", str[2][g]); printf("\n");

    return 0;
}