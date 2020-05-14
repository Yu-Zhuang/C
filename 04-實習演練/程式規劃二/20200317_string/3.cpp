#include<stdio.h>  
#include<stdlib.h>  
int main(void){  
    int c=0, r=0;  
    scanf("%d %d", &r, &c);  
    int ary[r][c];  
    for(int i=0;i<r;i++){  
        for(int j=0;j<c;j++){  
            if(j!=c-1)  
                scanf("%d ", &ary[i][j]);  
            else  
                scanf("%d", &ary[i][j]);  
        }  
    }  
    for(int i=0;i<c;i++){  
        for(int j=0;j<r;j++){  
            if(j!=r-1)  
                printf("%d ", ary[j][i]);  
            else  
                printf("%d\n", ary[j][i]);  
        }  
    }  
    return 0;  
} 