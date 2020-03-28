//variable/output
#include<iostream>
#include<cstdlib>
using namespace std;
int main(void){
    char ch='T';
    int a=12;
    float b=12.6;
    
    cout <<ch<<"是字元"<< endl;
    cout <<a<<"是整數"<< endl;
    cout <<b<<"是福點數"<< endl;
    
    system("pause");
    return 0;
}
// input/ output
#include<iostream>
#include<cstdlib>
using namespace std;
int main(void){
	int input;
	float input_2;
	
	cout <<"enter a interger:";
	cin >>input;
	cout <<"enter a float:";
	cin >>input_2;
	
	cout <<"x*y="<<input*input_2<< endl;
	
	system("pause");
	return 0;
}
// bool
#include<iostream>
#include<cstdlib>
using namespace std;
int main(void){
	bool is_odd;
	int num;
	
	cout <<"enter a interger:";
	cin >>num;
	
	if(num%2==0) is_odd=false;
	else is_odd=true;
	
	if(num==0) cout <<"num is zero"<< endl;
	else if(is_odd) cout <<"num is odd"<< endl;
	else cout <<"num is even"<< endl;
	
	system("pause");
	return 0;
}
//函數的多載
#include<iostream>
#include<cstdlib>
using namespace std;

void show(int);
void show(float);

int main(void){
	int input;
	float input_2;
	
	cout <<"enter an interger:";
	cin >>input;
	show(input);
	
	cout <<"enter an float:";
	cin >>input_2;
	show(input_2);
	
	system("pause");
	return 0;
}
void show(int num){
	cout <<num<<" is interger"<< endl;
}
void show(float num){
	cout <<num<<" is float"<< endl;
}
//
//class(類別)=struct+funtion封裝: data member + function member;
//object(物件)=以 類別(class) 型別宣告的 "變數" 稱為 物件(object);
#include<iostream>
#include<cstdlib>
using namespace std;

class CWin{ //class
	public: //設為公有 (private 為私有:僅有該類別可存取)
		char id; //data member;
		int width, height;
		
		int area(){ //function member: 計算面積 ;
			return width*height; 
		}
};
int main(void){
	CWin win1; //宣告一物件(object) win1;
	
	win1.id='A'; 
	win1.width=50;
	win1.height=40;
	
	cout <<"window"<<win1.id<<":"<< endl;
	cout <<"area = "<<win1.area()<< endl;
	
	system("pause");
	return 0;
}
//類別裡 函數成員相互呼叫
#include<iostream>
#include<cstdlib>
using namespace std;

class CWin{ //class
	public: //設為公有 (privacy 為私有:僅有該類別可存取)
		char id; //data member;
		int width, height;
		
		int area(){ //function member: 計算面積 ;
			return width*height; 
		}
		void showarea(){
			cout <<"area of windowsis: "<<area()<< endl; //類別裡 函數成員相互呼叫;
		}
};
int main(void){
	CWin win1; //宣告一物件(object) win1;
	
	win1.id='A'; 
	win1.width=50;
	win1.height=40;
	
	cout <<"window"<<win1.id<<":"<< endl;
	win1.showarea();
	
	system("pause");
	return 0;
}
//引入 物件 到函數裡
#include<iostream>
#include<cstdlib>
using namespace std;

class CWin{ //class
	public: //設為公有 (privacy 為私有:僅有該類別可存取)
		char id; //data member;
		int width, height;
		
		int area(){ //function member: 計算面積 ;
			return width*height; 
		}
		void set_data(char i, int w, int h){
			id=i;
			width=w;
			height=h;
		}
		void showarea(){
			cout <<"area of the windows is: "<<area()<< endl;
		}
};

void showWin(CWin);

int main(void){
	CWin win1; //宣告一物件(object) win1;
	
	win1.set_data('a',50,40); 
	
	showWin(win1); 
	
	system("pause");
	return 0;
}
void showWin(CWin win){
	cout <<"window: "<<win.id<< endl;
	win.showarea();
}
//private and public
#include<iostream>
#include<cstdlib>
using namespace std;

class CWin{ //class
	private: //不寫(設)或private將成員設為私有:僅能在class中存取;
		char id; //data member;
		int width, height;
		
	public: //設為公有 (privacy 為私有:僅有該類別可存取)
		int area(){ //function member: 計算面積 ;
			return width*height; 
		}
		void set_data(char i, int w, int h){
			id=i;
			width=w;
			height=h;
		}
		void showarea(){
			cout <<"name of the window is: "<<id<< endl;
			cout <<"area of the windows is: "<<area()<< endl;
		}
};

void showWin(CWin);

int main(void){
	CWin win1; //宣告一物件(object) win1;
	
	win1.set_data('a',50,40); //用類別中的公有函數去設定私有成員,但不能從外部直接設定私有成員;
	
	showWin(win1);  
	
	system("pause");
	return 0;
}
void showWin(CWin win){
	win.showarea();
}
//建構元
#include<iostream>
#include<cstdlib>
using namespace std;

class CWin{ //class
	private: //不寫(設)或private將成員設為私有:僅能在class中存取;
		char id; //data member;
		int width, height;
		
	public: //設為公有 (privacy 為私有:僅有該類別可存取)
		CWin(char i, int w, int h){ //建構元:物件一建立便會直接被執行，不須呼叫;
			id=i;
			width=w;
			height=h;
			cout <<"建構元被呼叫了"<< endl;
		}
		int area(){ //function member: 計算面積 ;
			return width*height; 
		}
		void showarea(){
			cout <<"name of the window is: "<<id<< endl;
			cout <<"area of the windows is: "<<area()<< endl;
		}
};

void showWin(CWin);

int main(void){
	CWin win1('a',50,40); //宣告一物件(object) win1,並設定初值; 
	
	showWin(win1); 
	
	system("pause");
	return 0;
}
void showWin(CWin win){
	win.showarea();
}
//建構元的多載
#include<iostream>
#include<cstdlib>
using namespace std;

class CWin{ //class
	private: //不寫(設)或private將成員設為私有:僅能在class中存取;
		char id; //data member;
		int width, height;
		
	public: //設為公有 (privacy 為私有:僅有該類別可存取)
		int area(){ //function member: 計算面積 ;
			return width*height; 
		}
		CWin(char i, int w, int h){ //建構元
			id=i;
			width=w;
			height=h;
			cout <<"建構元被呼叫了"<< endl;
		}
		CWin(void){ //建構元
			id='b';
			width=10;
			height=20;
			cout <<"建構元void被呼叫了"<< endl;
		}
		void showarea(){
			cout <<"name of the window is: "<<id<< endl;
			cout <<"area of the windows is: "<<area()<< endl;
		}
};

void showWin(CWin);

int main(void){
	CWin win1('a',50,40), win2; //宣告一物件(object) win1,並設定初值; 

	
	showWin(win1); 
	showWin(win2);
	
	system("pause");
	return 0;
}
void showWin(CWin win){
	win.showarea();
}
