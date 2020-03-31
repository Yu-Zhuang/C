#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
int main(void){  
    char input[101];  
    int N=0, sSize=0;  
// input string and shift num
    scanf("%[^\n]",input); scanf("%d",&N);  
    sSize=strlen(input);  
// compution
    // shift each element in input string 
    for(int i=0;i<sSize;i++){  
        // if element is Alphabate
        if(input[i]>='a'&&input[i]<='z') input[i]=(input[i]-'a'+N)%26+'a';  
        else if(input[i]>='A'&&input[i]<='Z') input[i]=(input[i]-'A'+N)%26+'A'; 
        // if element is number 
        else if(input[i]>='0'&&input[i]<='9') input[i]=(input[i]-'0'+N)%10+'0';  
    }  
// print result
    puts(input);  
    return 0;  
} 