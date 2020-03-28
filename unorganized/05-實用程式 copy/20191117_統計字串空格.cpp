//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
#include<stdio.h>
#include<stdlib.h>
int main(void){
    char str[]="hello c world !";
    int temp=0,count=0;
    while(str[temp]!='\0'){
        if(str[temp]==' ')
            count+=1;
        temp+=1;
    }
    printf("%d\n",count);
    return 0;
}
