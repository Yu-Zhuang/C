#include<stdio.h>
#include<stdlib.h>
void sub(int **);
int main(void){
    int **list=(int**)malloc(sizeof(int));;
    list[0]=(int*)malloc(sizeof(int));
    for(int i=0;i<10;i++) list[0][i]=i;
    for(int i=0;i<10;i++) printf("%d ",list[0][i]);
    printf("\n");
    sub(list);
    return 0;
}
void sub(int **list){
    for(int i=0;i<10;i++) printf("%d ",list[0][i]);
}
