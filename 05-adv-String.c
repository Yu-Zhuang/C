#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
string處理
	basic:
	1. memset(str,'\0',strlen);初始化字串;
	2. int a = strlen(string); 取得string長度;
	3. scanf("%[^\n]", str[0]); 輸入字串(包含空格);
	4. puts(str); printf("%s", str); 輸出字串;
	
	advanced:
	5. strcmp(str1,str2); 比較兩字串大小, 會return (str1大小-str2大小); 
		*可另外寫func()先比較長度，if(一樣長) return strcmp(str1,str2); if(不一樣長) return strlen(str1)-strlen(str2);
	6. strstr(str, substr); 找str有無substr, 會return 找到substr的第一個位置;
	7. strcpy(str, templet_string); 將templet_string 複製到 str字串;
	8. strtok(str,"欲切字"); //回傳被切割字串的第一個位置
		ex:
			char *token, ret[1000][1000]; //變數宣告
			strcpy(copy,origin); //第一次切(因為會影響到被切字串, 因此將原字串copy至copy[]字串)
			token=strtok(copy," .,!()"); //將copy字串進行第一次切割, 並用token接位置
			while(token){ strcpy(ret[i], token); token=strtok(NULL," .,!()"); i++; } //將位置傳給ret[], 並繼續連續切割;

	9.	sscanf(string, "%lf",&num); //將 string 轉成double並assigned給 數字變數, ("%lf"改成"%d"即字串轉int);
	10. sprintf(string,"%.2lf", num); //將 數字 轉為 字串並assigned給 字串變數, ("%lf"改成"%d"即為int轉字串);

*/
int main(void){

   return 0;
}