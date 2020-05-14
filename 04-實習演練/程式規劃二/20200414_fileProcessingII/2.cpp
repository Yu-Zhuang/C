#include<stdio.h>
#include<stlib.h>
int main(void){  
    int m=0, n=0, ret=1;  
    scanf("%d %d", &m, &n);  
    if(n>m){ n^=m; m^=n; n^=m; }  
    if(n == m) printf("%d\n", m);  
    if(n<m){   
        while(ret){  
            ret=m%n;  
            m=n;  
            n=ret;  
        }  
        printf("%d\n",m);  
    }  
    return 0;  
}
