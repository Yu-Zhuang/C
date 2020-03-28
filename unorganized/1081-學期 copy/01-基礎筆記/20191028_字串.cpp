//
//  20191028.cpp
//  20191028
//
//  Created by Yu-Zhuang Lin on 2019/10/28.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.

//字串基本
// 字串=字元陣列= char 陣列名[位數]
// char str[]="sweet home"={'s','w'....'m','e','\0'}共11位數 因為最後要有\0才是 字串
// char str[11]="sweet home" (正確); char str[10]="sweet home" (不正確)
#include <stdio.h>
int main(void)
{
    char str[]="sweet home";
    printf("%d\n", sizeof(str)); //output: 11
    return 0;
}
//scanf後要用gets時 要先用getchar();
//字串的輸出輸入 input: gets(字串名); output: puts(字串名)
//gets() 可讀取字串空白內容; scanf()無法
//puts() 會自動換行 且無法更改輸出格式, 因此通常用 gets()與printf()完成字串輸出入
//printf("%s", 字串名);

//fgets使用 (建議數用)
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

#include <stdio.h>
int main(void)
{
    char str[15];
    
    puts("what is your name? ");
    gets(str);
    puts("Hi!");
    puts(str);
    puts("how are you");
    // ouput:
    /*
     what is your name?
     john (input)
     Hi!
     john (output)
     how are you
     */
    return 0;
}

//字串陣列 ()
// 字串名[字串個數][字串長度];
//
#include <stdio.h>
int main(void)
{
    char str[3][10]={"tom","lily","james le"};
    int i;
    
    for (i=0;i<=2;i++)
        printf("str[%d]=%s\n",i,str[i]);
    
    printf("\n");
    
    for (i=0;i<=2;i++)
    {
        printf("str[%d]=%p\n",i,str[i]);
        printf("address of str[%d][0]=%p\n\n",i,&str[i][0]);
    }
    
    return 0;
}
