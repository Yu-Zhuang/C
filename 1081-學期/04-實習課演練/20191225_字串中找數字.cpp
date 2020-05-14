#include<stdio.h>
#include<stdlib.h>
int FindNum(char* M,char* C); // M:被找字串, C:欲找字串. 功能:找目標字串後遇到的第一組數字,並轉為int形式;
int main(void){
    double h,w;
    char Q[]="The patient’s height is 180cm and his weight is 105kg ";
    char H[]="height",W[]="weight";
    
    h=FindNum(Q,H);
    w=FindNum(Q,W);
    
    printf("\n%s\n",Q);
    printf("BMI=%.1lf\n\n",w/(h*h/10000)); //output
    
    return 0;
}

int FindNum(char* M,char* C){ //  M被找字串, C欲找字串, 功能:找目標字串後遇到的第一組數字
    int i=0, j=0, *ret, count=0, output=0, ten=1;;
    ret=(int*)malloc(0);
    
    while(M[i]!='\0'){ //找到 字串C
        if(M[i]==C[j]){
            while(C[j]!='\0'&&C[j]==M[i]) {i++;j++;}
            if(C[j]=='\0') break;
        }
        j=0; i++;
    }

    while(M[i]>57||M[i]<48) i++; //找到字串C往後最先遇到的數字
    
    while(M[i]<58&&M[i]>47){ //將遇到的那組數字依序儲存數字至ret[]
        count+=1; ret=(int*)realloc(ret,sizeof(int)*count);
        ret[count-1]=M[i]-48;
        i++;
    }
    
    for(i=1;i<=count;i++){ //將ret中的資料轉換成一個數字
        output+=ret[count-i]*ten;
        ten*=10;
    }
    free(ret);
    return output;
}


/*
假設有字串”The patient’s height is 180cm and his weight is 105kg”，請設計一程式將此字串中的身高和體重數值擷取出來，求出其BMI。
 注意: 要先判斷出height這個字，再擷取出後面接的數值(即身高)，要判斷出weight這個字，再擷取出後面接的數值(即體重)。
 height與weight的先後順序可調換，意思是如果字串是”The patient’s weight is 105kg and his height is 180cm” 你的程式也要能判斷找出正確的身高和體重的值。


 */
