//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
int main(void){
    int i;
    char* name[3]; //指標字串 
    char str[3][10];
    for(i=0;i<3;i++){
        gets(str[i]);
        name[i]=str[i];
    }
    for(i=0;i<3;i++){
        printf("%s ",name[i]);
    }

    return 0;
}
