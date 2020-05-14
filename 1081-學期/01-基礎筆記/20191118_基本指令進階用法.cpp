//  Created by Yu-Zhuang Lin on 2019/10/2.
========================================================
//可以讀取空白格字元的scanf
//有時候scanf/gets會直接讀到緩衝區內空白字元而出現錯誤
//可用 getchar()將空白字元讀掉
#include<stdio.h>
int main(void){
    char str[20];
    char string[20];
    int i=0;
    int count=0;
    
    scanf("%[^\n]",str); //scanf用這個方式輸入字串可以讀取空格
    for(i=0;i<10;i++){ //計算空格
        if(str[i]==' '){
            count+=1;
        }
    }
    printf("%d\n", count); //output
    
    count=0;
 
    scanf("%s",string); //scanf一般用法無法讀取空格
    for(i=0;i<10;i++){ //計算空格
        if(string[i]==' '){
            count+=1;
        }
    }
    printf("%d\n", count);//output
    
    return 0;
}
/*output:
 a b c d e //input
 4   //output,  printf("%s", str) :a b c d e
 a b c d e  //input
 0  //output ,  printf("%s", string) :a
 Program ended with exit code: 0
 */
========================================================
//代替輸出入的變數
#include<stdio.h>
int main(void){
    int input;
    char ipi[]="%d"; //可以直接代替"%d"
    scanf(ipi,&input);
    printf(ipi,input);
    printf("\n");
    return 0;
}
========================================================
// 指標 當陣列給初始值與空間
/*
 指標一定要初始過才能當陣列使用
 例如:
 int *ret;
 int temp[5]={1,2,3,4,5};
 
 for(;;){ //沒初始過 直接當陣列使用 不行
    ret[i]=temp[i]
 }
 
 .初始可以是給空間 例:ret=(int*)malloc(sizeof(int)*10);
 .或是 ret=temp;
 .或是如下用法
 */
#include<stdio.h>
int main(void){
    int *input;
    int i=0;
    input=(int[10]){1,2,3,4,5,6,7,7,8,9};
    for(;;){
        i+=1;
        if(input[i]==8)
            break;
        else
            printf("%d\n",input[i]);
    }
    return 0;
}

/* scanf進階用法
 scanf中不常見但有用的轉換字元 [...] 和 [^...]

 範例程式01
 #include <stdio.h>
 int main()
 {
 char s[200];
 scanf("%[abc]",s);
 printf("%s\n",s);
 return 0;
 }
 其中" [ ] " 為掃描字符集合
 那上述主程式的主要功能為
 輸入的每個字元 會掃描[]中的字元
 若掃描到輸入的字元屬於[]中的某個字元 就提取該字元
 若掃描到不屬於[]中的字元就結束提取

 範例輸入: abc123
 範例輸出: abc
=========================
 範例程式02
 #include <stdio.h>
 int main()
 {
 char s[200];
 scanf("%[^abc]",s);
 printf("%s\n",s);
 return 0;
 }
 再來scanf中 多了一個" ^ " 的符號
 用字元^可以說明補集 把^字元放在[]中的第一字元時,構成其他字元組成的命令的補集合 指示scanf指接受位說明的其他字元
 那該程式的功能 就跟上一個相反
 輸入的每個字元 會掃描[]中的字元
 若掃描到輸入的字元不屬於[]中的某個字元 就提取該字元
 若掃描到屬於[]中的字元就結束提取

 範例輸入: 123abc
 範例輸出: 123
===============================
 那有了這個概念
 也可以做輸入空白會提早結束讀取的錯誤

 範例程式03
 #include <stdio.h>
 int main()
 {
 char s[200];
 scanf("%[^\n]",s);
 printf("%s\n",s);
 return 0;
 }
 該程式值到我輸入換行的功能 也就是enter鍵才會結束讀取
 就不會碰到空白提早結束

 那[]掃描字符集合 接受這樣的寫法 [A-Z]
 意思是掃描A~Z的字元

 要注意的是 掃描字元集合裡 方括號兩邊不能有空格 如[ abc ] or [ ^abc ] 這些是錯的寫法 不然空格也會算再裡面 導致輸入碰到空格一樣會提早結束提取的問題

 */
