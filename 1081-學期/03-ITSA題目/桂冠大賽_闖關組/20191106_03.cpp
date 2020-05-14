//未通過測試
#include <stdio.h>
int countf(char n[]); //計算輸入的數列有幾位(含空格)
int main(void){
    int m,n=0;
    char num[10001]; //input 儲存數列
    int i;
    int data[10]; //各數在數列出現的次數
    int rule, temp=0;
    
    scanf("%d",&m); //有幾組資料要計算
    getchar(); //避免scanf後使用gets的bug
    
    do{ //執行m次
        gets(num); //將數列儲存進入num[]
        
        for(i=0;i<=9;i++){ //將 各數 初始值 歸零
            data[i]=0;
        }
        
        for(i=0;i<countf(num);i++){ //運算 數列中各數出現次數
            switch(num[i]){
                case '0':
                    data[0]+=1;
                    break;
                case '1':
                    data[1]+=1;
                    break;
                case '2':
                    data[2]+=1;
                    break;
                case '3':
                    data[3]+=1;
                    break;
                case '4':
                    data[4]+=1;
                    break;
                case '5':
                    data[5]+=1;
                    break;
                case '6':
                    data[6]+=1;
                    break;
                case '7':
                    data[7]+=1;
                    break;
                case '8':
                    data[8]+=1;
                    break;
                case '9':
                    data[9]+=1;
                    break;
            }
        }
        
        temp=0; //temp值歸零
        rule=(((countf(num)+1)/2)+1)/2; //rule等於數列一半(or一半無條件進位)的值
        
        if(((countf(num)+1)/2)%2==0){//數列中數字有偶數個時執行
            for(i=0;i<=9;i++){
                temp+=1;
                if(data[i]>rule){
                   printf("%d\n",i);
                    break;
                }
                else
                    continue;
            }
            if (temp==10)
                printf("0\n");
        }
        
        else{   //數列中數字有奇數個時執行
            for(i=0;i<=9;i++){
                temp+=1;
                if(data[i]>=rule){
                   printf("%d\n",i);
                    break;
                }
                else
                    continue;
            }
            if (temp==10)
                printf("0\n");
        }

        n+=1;
    }while(n<m);
    return 0;
}
int countf(char n[]){ //計算輸入的數列有幾位(含空格)
    int i;
    int termi=0;
    int count=-2;
    for(i=0;i<=10000;i++){
        if (n[i]>='0'&&n[i]<='9'){
            termi=0;
            count+=1;
            continue;
        }
        else{
            termi+=1;
            count+=1;
            if(termi==2)
                break;
        }
    }
    return count;
}
