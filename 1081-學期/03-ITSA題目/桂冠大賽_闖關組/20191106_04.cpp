//未通過測試
#include<stdio.h>
int main(void){
    int i;
    long num=1;
    long squ=1;
    int n,m=0;
    int input;
    int temp=1;
    
    scanf("%d",&n);
    if(n>100||n<1)
        goto end;
    do{
        m+=1;
        squ=1;
        num=1;
        temp=1;
        scanf("%d",&input);
        if(input%5==0||input>1000000||input<2)
            goto end;
        for(i=0;i<=17;i++){
            temp+=1;
            squ=squ*10;
            num=num+squ;
            if(num%input==0){
                printf("%d\n",temp);
                break;
            }
            else
                continue;
        }
    }while(m<n);
    end:
    return 0;
}

