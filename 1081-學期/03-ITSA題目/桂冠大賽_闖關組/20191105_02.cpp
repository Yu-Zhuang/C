//
#include <stdio.h>
int main(void){
    int i,j,k,n;
    int input, sum, temp=1;
    scanf("%d",&n);
    while(temp<=n){
        scanf("%d", &input);
        for(i=0;i<=9;i++)
            for(j=0;j<=9;j++)
                for(k=0;k<=9;k++){
                    sum=(i*100+k*10+j)+(j*100+i*10+k)+(j*100+k*10+i)+\
                    (k*100+i*10+j)+(k*100+j*10+i);
                    if (input==sum)
                        printf("%d %d %d\n",i,j,k);
                    else
                        continue;
                }
        temp+=1;
    }
    return 0;
}
