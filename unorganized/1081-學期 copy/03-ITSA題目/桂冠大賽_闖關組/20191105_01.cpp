//
#include <stdio.h>
int main(void){
    int i,n,input;
    int temp=1;
    int termi=0;
    
    scanf("%d", &n);
    
    for (i=1;i<=n;i++){
        temp=1;
        termi=0;
        scanf("%d", &input);
        do{
            if (input%3==0){
                temp*=3;
                input=input/3;
            }
            if (input%5==0){
                temp*=5;
                input=input/5;
            }
            else if (input%3!=0&&input%5!=0)
                termi+=1;
        }
        while(termi==0);
        printf("%d\n",temp);
    }
    return 0;
}
