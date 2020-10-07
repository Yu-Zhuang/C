/* 圖目
請撰寫一程式，此程式在command上可輸入以下指令來完成轉換動作。
假設此程式執行檔為convert.exe，則
1. convert.exe /?
    功能：可列出所有可以執行的指令格式
2. convert.exe -encode A.txt B.txt 3
    功能：將A.txt轉換成B.txt，轉換方式為將每一個A.txt裡面的字元(a~z, A~Z)往右對應第3個字元(使用第四個參數)，如果超出範圍則回到首位繼續對應下去，並存到B.txt裡面。
    字元順序為abcdef...xyzABCDEF...XYZ
    舉例: 假設遇到字元X...往右對應三個字元...則對應到a

3. convert.exe -decode B.txt C.txt 3
    功能：將B.txt轉換成C.txt，轉換方式為將每一個B.txt裡面的字元往左對應3個字元(使用第四個參數)，存到C.txt裡面。(注意溢位問題)
          注意到的是轉換後的C.txt會和A.txt一模一樣
*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

void rotate(char *string, int letterCase){
	if(letterCase == 1){
		if(string[0] < 'a')
			string[0] = string[0] - 'a' + 'z' + 1; 
		else if(string[0] > 'z')
			string[0] = string[0] - 'z' + 'a' - 1; 		
	}
	else{
		if(string[0] < 'A')
			string[0] = string[0] - 'A' + 'Z' + 1; 		
		else if(string[0] > 'Z')
			string[0] = string[0] - 'Z' + 'A' - 1; 	
	}
}

void encode(char *string, int n){
	n %= 26;
	int len = strlen(string);
	
	for(int i=0;i<len;i++){
		int letterCase = 1;
		if(isalpha(string[i])){
			if(isupper(string[i]))
				letterCase = 2;
			string[i] -= n;
			rotate(&string[i], letterCase);
		}
	}
}

void decode(char *string, int n){
	n %= 26;
	int len = strlen(string);

	for(int i=0;i<len;i++){
		int letterCase = 1;
		if(isalpha(string[i])){
			if(isupper(string[i]))
				letterCase = 2;
			string[i] += n;
			rotate(&string[i], letterCase);
		}
	}
}

int main(int argc, char *argv[]){
	printf("\n%s\n", argv[1]);

	// condition setting
	char str[] = "abcABCxyzXYZ";
	int code = -3;
	//
	printf("\n\n@ simple encode / decode program @");
	printf("\n\torigin\t:\t%s\n", str);
	
	encode(str, code);
	printf("after encode:\t%s\n", str);
	
	decode(str, code);
	printf("after decode:\t%s\n\n", str);

	system("pause");
	return 0;
}

/* result
	origin	:	abcABCxyzXYZ
after encode:	xyzXYZuvwUVW
after decode:	abcABCxyzXYZ
[Finished in 0.1s]
*/