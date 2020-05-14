#include<stdio.h>  
#include<stdlib.h>  
int main(void){  
  char *input=(char*)malloc(sizeof(char));  
  int i=0, flag=1, j=0;  
  
  scanf("%s",input);  
  while(input[i]>='0') i++; i-=1;  
    
  while(j<i){  
    if(input[i]!=input[j]) { flag=0; break; }  
    i--; j++;  
  }  
  if(flag) printf("YES\n");  
  else printf("NO\n");  
  return 0;  
}  