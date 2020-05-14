//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
// 
#include <stdio.h>
int main(void){
    int nums[2][3]={{3,4,5},{6,2,8}};
    int i,j;
    int* ptr[2]; //格式
    
    ptr[0]=nums[0];//格式
    ptr[1]=nums[1];
    
    for(i=0;i<2;i++)
        for(j=0;j<3;j++){
            printf("%d ",nums[i][j]);
        }
    printf("\n");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++){
            printf("%d ",*(*(ptr+i)+j)); //格式
        }
    printf("\n");
    
    return 0;
}
//指標字串
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

