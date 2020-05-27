#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<ctype.h>  
int main(void){  
    char input[2000]={'\0'};
    // read input  
    scanf("%[^\n]", input);  
    // 轉小寫
    for(int i=0;i<strlen(input);i++)  
        if(isupper(input[i])) input[i]=tolower(input[i]);  
    int count=0;  
    char templet[2000][2000];  
    int i=0, flag=0, tmp=0;  
    while(input[i]!='\0'){  
        tmp=0;  
        flag=0;  
        // 將各substring放入tmpelet 中
        while( ! isspace(input[i])&& input[i]!='\0'){  
            templet[count][tmp]=input[i];  
            i++;  
            tmp++;  
            flag=1;  
        }
        // substring 加上 結束字元
        if(flag) { templet[count][tmp]='\0'; count++; continue; }  
        else i++;  
    }  
    char ret[2000][2000];  
    int n=0;  
    // go through all subString
    for(int i=0;i<count;i++){  
        flag=0;  
        int tmp=n;  
        while(tmp){  
            // 是否重複
            if( ! strcmp(templet[i], ret[tmp-1])) { flag=1; break; }  
            tmp--;  
        }  
        // 無複則 放入 ret
        if( !flag){ strcpy(ret[n],templet[i]); n++; }  
    }  
    // output
    for(int i=0;i<n;i++){  
        if(i!=n-1) printf("%s ", ret[i]);  
        else printf("%s\n", ret[i]);  
    }  
    return 0;  
}  