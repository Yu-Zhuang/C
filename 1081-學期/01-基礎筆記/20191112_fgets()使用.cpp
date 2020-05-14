//  Created by Yu-Zhuang Lin on 2019/10/2.
//
#include <stdio.h>
int main(void){
    char str[30];
    char *ptr;
    
    fgets(str,29,stdin); //fgets(字串變數名,指定字元數,stdin);
     
    printf("%s",str);//output
    
    ptr=str;//指派給指標
    printf("%s",ptr);
    
    return 0;
}
/*
 output
 hello c world!
 hello c world!
 hello c world!
 Program ended with exit code: 0
 */
