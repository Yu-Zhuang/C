#include<stdio.h>
#include<stdlib.h>

void PrimeArray(int*,int); //將array儲存質數:位置號碼是質數設為1; 反之設為0;
void PrintArray(int*,int); //印出array:array[i]=1印出;array[i]=0不印, 每印五個換行;
bool Prime(int); //判斷是否為質數;

int main(void){
    int prime[1000]={0},i;
    for(i=1;i<1000;i++) prime[i]++; //array值皆初始化為1
    
    PrimeArray(prime,1000); //將array儲存質數:位置號碼是質數設為1; 反之設為0;
    PrintArray(prime,1000); //印出array:array[i]=1印出;array[i]=0不印, 每印五個換行;
    
    return 0;
}

void PrimeArray(int* nums,int numsSize){ //將array儲存質數:位置號碼是質數設為1; 反之設為0;
    for(int i=2;i<numsSize/2;i++){
        if(nums[i]==0) continue; //array位置已為 0則跳過;
        else if(Prime(i)==1){ //array位置i是質數,便將array中位置號碼為i質數倍數的位置 設為0;
            int j=i, k=2;
            while(j*k<1000) {nums[j*k]=0;++k;}
        }
    }
}

bool Prime(int num){ //判斷是否為質數;
    for(int i=2;i<=num;i++){
        if(i==num) return true;
        if(num%i==0) break;
    }
    return false;
}

void PrintArray(int* nums, int numsSize){ //印出array:array[i]=1印出;array[i]=0不印, 每印五個換行;
    int tmp=0,i;
    for(i=1;i<numsSize;i++){
        if(nums[i]==1) {printf("%5d ",i);tmp+=1;} //遇array位置為1則印出;
        if(tmp==5) {printf("\n");tmp=0;} //每印5個換行;
    }
}

/*
 (1)    利用陣列求質數。
 說明: Sieve of Eratosthenes是一種找出質數的方法，請設計程式來來實作找出1~999的質數。
 方法說明:
 1.    產生一個陣列int Prime[1000]，其初始值均設為1(代表真)。
 2.    1定義為質數，2<i<1000，若i為質數，則Prime[i]保持為1，反之若i不為質數，則Prime[i]設為0(代表假)。
 3.    從此陣列的Prime[2]開始，將2(是質數)的倍數(4、6、8、….)所對應的陣列位置均設為0，因為其不為質數，接著繼續找出3(是質數)的倍數(6、9、12、…) 所對應的陣列位置均設為0，因為其不為質數，接著繼續找出4(不是質數)，繼續找出5(是質數)的倍數，以此類推，直到陣列大小的一半(超過一半即不可能是質數)。最後陣列的值是1的就是質數，0就不是質數。
 4.    印出1~999所有質數結果。
 5.    要求:
 上述方面需實作在一個函式，將Prime[n]陣列作為參數傳到此函式去做判斷。
 印出質數結果也必須實作在函式，同樣將Prime[n] 陣列作為參數傳到此函式去做印出。印出質數需每5個數為一row，排列整齊。
 
 輸出
 1   2   3   5   7
 11  13  17  19  23
 …..

 */
