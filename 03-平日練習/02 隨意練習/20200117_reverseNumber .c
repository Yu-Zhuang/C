#include<stdio.h>
#include<stdlib.h>

int reverNum(int);

int main(void){
    int input=0, output;
    
    scanf("%d", &input);
    
    output=reverNum(input);
    
    printf("reverse number: %d\n", output);
    
    return 0;
}

int reverNum(int num){
    int ret=0, ten=1, i=-1, *list=(int*)malloc(sizeof(int));
    
    while(num){ i++; list[i]=num%10; num/=10;}
    
    for(int j=i;j>=0;j--){ ret+=ten*list[j]; ten*=10;}
    
    return ret;
}
