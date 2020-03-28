//
#include <stdio.h>
void toUpper(char s[]);
int main(void){
    char str[15];
    
    printf("請輸入一個ㄧ字串: "); //input
    gets(str);
    
    toUpper(str); //conputional function
    
    printf("轉換成大寫: %s", str); //ouput
    printf("\nend\n");
    return 0;
}

void toUpper(char s[]){ //conputional function
    int i=0;
    
    while(s[i]!='\0'){
        if (s[i]>=97&&s[i]<=122) //a-z(小寫字母)的範圍是在ascii的97~122
            s[i]=s[i]-32; //小寫-32在ascii剛好是該字母的大寫
        i++;
    }
    
    return;
}
