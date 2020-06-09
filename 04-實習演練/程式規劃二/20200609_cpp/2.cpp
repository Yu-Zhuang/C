# include <iostream>
# include <cstdlib>
# include "vec.h"
using namespace std;

void GET_INPUT(double *v1, double *v2){
	for(int i=0;i<5;i++){
		cout <<"enter vector 1-"<<i<<": ";
		cin >>v1[i];
	}
	for(int i=0;i<5;i++){
		cout <<"enter vector 2-"<<i<<": ";
		cin >>v2[i];
	}
}
void GET_CHOSE(int &chose){
	cout <<"@ Menu @\n(1) add\n(2) substration\n(3) dot\n(4) norm\n(5) multiply\n(6) vec unit\n(0) END\nenter chose: ";
	cin >>chose;
}

void RESULT_PRINT(double *ret, int chose){
	if(chose==3 || chose==4)
		cout <<"ans :"<<ret[0]<< endl;
	else{
		cout <<"ans : ";
		for(int i=0;i<5;i++)
			cout <<ret[i]<<" ";
		cout <<""<< endl;
	}
}

int main(void){
	double v1[5] = {0}, v2[5] = {0}, ans[5] = {0};
	double num = 0;
	GET_INPUT(v1, v2);

	int chose = 1;
	while(chose){
		GET_CHOSE(chose);
		if(chose == 0)
			break;
		else if(chose == 1)
			VEC_ADD(v1, v2, ans);
		else if(chose == 2)
			VEC_SUB(v1, v2, ans);
		else if(chose == 3)
			VEC_DOT(v1, v2, ans);
		else if(chose == 4)
			VEC_NORM(v1, v2, ans);
		else if(chose == 5){
			cout <<"請輸入一實數: ";
			cin >> num;
			VEC_MULTI(v1, num, ans);
			RESULT_PRINT(ans, chose);
			VEC_MULTI(v2, num, ans);
			RESULT_PRINT(ans, chose);
		}else if(chose == 6){
			VEC_UNI(v1, ans);
			RESULT_PRINT(ans, chose);
			VEC_UNI(v2, ans);
			RESULT_PRINT(ans, chose);
		}
		else
			cout <<"wrong input"<< endl;
		if(chose<5 && chose>0)
			RESULT_PRINT(ans, chose);
	}

    return 0;
}