#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>

int COMP(char *str1, char *str2); //自定 比較法

int main(void){  
	//variable
	char str[][5]={"55", "5", "555"}, tmp[4];
	// 印出 排序前
	for(int i=0;i<3;i++) puts(str[i]);
	printf("=====================\n");
	// 排序
	for(int i=0;i<2;i++){
		for(int j=i+1;j<3;j++){
			// 比較 str[i], str[j] 大小 ( str[i] > str[j]會大於0, 等於會等於0 )
			if( COMP(str[i],str[j])<0 ){
				//交換
				strcpy(tmp, str[i]); strcpy(str[i],str[j]); strcpy(str[j],tmp);
			}
		}
	}
	//印出 排序後 結果
	for(int i=0;i<3;i++) puts(str[i]);
    return 0;  
}  
// 先比長度,  如果長度一樣 再比 字串
int COMP(char *str1, char *str2){
	int len_1=0, len_2=0;
	// 取兩字串長度
	len_1 = strlen(str1);
	len_2 = strlen(str2);
	// 如果 字串 長度不一樣 
	if(len_1 != len_2) return len_1 - len_2;
	// 長度一樣
	else return strcmp(str1, str2);
}
