//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:題目:求 100 之內的質數
#include <stdio.h>
int main(void){
    int i,j;
    
    printf("100之內的質數: ");
    
    for (i=2;i<=100;i++)
        for (j=2;j<=i;j++){
            if (i==j)
                printf("%d ", i);
            if (i%j!=0)
                continue;
            if (i%j==0)
                break;
        }
    
    printf("\nend\n");
    return 0;
    
}
