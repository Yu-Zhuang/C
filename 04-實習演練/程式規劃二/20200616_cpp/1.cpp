# include <iostream>
# include <cstdlib>
# include <math.h>
# include "myClass.h"
using namespace std;
# define MAX 100
/* SIGHT
	string name;
	string town;
	string type;
	double x; // 經度
	double y; // 緯度
*/

void SWAP(SIGHT &a, SIGHT &b){
	SIGHT tmp = a;
	a = b;
	b = tmp;
}

void SWAP(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void SWAP(double &a, double &b){
	double tmp = a;
	a = b;
	b = tmp;
}

int FIND(SIGHT *DB, int curNum, string target, int chose){ // chose:1:找name, chose:2:找town, chose:3:找type 
	if(chose == 1){
		for(int i=0;i<curNum;i++)
			if(DB[i].getName() == target)
				return i;
	}else if(chose == 2){
		for(int i=0;i<curNum;i++)
			if(DB[i].getTown() == target)
				return i;
	}else if(chose == 3){
		for(int i=0;i<curNum;i++)
			if(DB[i].getType() == target)
				return i;
	}
	else
		cout<<"wrong input"<<endl;
	return -1;
// -1 沒找到, 其他 回傳index;
}
//int FIND(SIGHT *DB, int curNum, string target, int chose)
void ADD(SIGHT *DB, int &curNum){
	if(curNum == MAX){ // 判斷DB是否還放的下
		cout <<"DB is full"<< endl;
		return;
	}
	int flag = 1;
	// input name
	while(flag){
		flag = 0;
		DB[curNum].setName();
		// 判斷是否存在
		if( FIND(DB, curNum, DB[curNum].getName(), 1) != -1)
			flag = 1;
	}
	// 依序設定新元素屬性
	DB[curNum].setTown();
	DB[curNum].setType();
	DB[curNum].setX();
	DB[curNum].setY();
	// DB大小 +1;
	curNum += 1;
}

void DELTE(SIGHT *DB, int &curNum){
	if(curNum < 1){
		cout <<"DB is empty"<< endl;
		return;
	}
	string target;
	cout <<"欲刪除景點名: "<<endl;
	cin >> target;
	// 是否有該景點
	int ret = FIND(DB, curNum, target, 1);
	if( ret == -1){
		cout <<"無此地點";
		return ;
	}
	// 有
	int chose = 1;
	cout <<"(!0) 確定刪除 (0) 不刪: ";
	cin >> chose;
	if(chose != 0){
		SWAP(DB[curNum], DB[ret]);
		curNum --;
	}	
}

void SHOW(SIGHT *DB, int curNum){
	for(int i=0;i<curNum;i++)
		DB[i].show();
}

void SHOW_TOWN(SIGHT *DB, int curNum){
	string site[13] = {"花蓮市", "鳳林鎮", "玉里鎮", "新城鄉", "吉安鄉", "壽豐鄉", "光復鄉", "豐濱鄉", "瑞穗鄉", "富里鄉", "秀林鄉", "萬榮鄉", "卓溪鄉"};
	int chose = 0;
	do{
		cout <<"(1)花蓮市、(2)鳳林鎮、(3)玉里鎮、(4)新城鄉、(5)吉安鄉、(6)壽豐鄉、\n(7)光復鄉、(8)豐濱鄉、(9)瑞穗鄉、(10)富里鄉、(11)秀林鄉、(12)萬榮鄉、(13)卓溪鄉\n請輸入景點定點: ";
		cin >> chose;
		if(chose < 1 || chose > 13)
			cout <<"wrong input"<< endl;
	}while(chose < 1 || chose > 13);
	string target;
	target = site[chose-1];
	for(int i=0;i<curNum;i++)
		if(DB[i].getTown() == target)
			DB[i].show();
}

void SHOW_TYPE(SIGHT *DB, int curNum){
	string t_type[4] = {"風景", "美食", "體驗", "探索"} ;
	int chose = 0;
	do{
		cout <<"(1)風景 (2)美食 (3)體驗 (4)探索\n請輸入景點類型: ";
		cin >> chose;
		if(chose < 1 || chose > 4)
			cout <<"wrong input"<< endl;
	}while(chose < 1 || chose > 4);
	string target = t_type[chose-1];
	for(int i=0;i<curNum;i++)
		if(DB[i].getType() == target)
			DB[i].show();
}

void DIS(SIGHT *DB, int curNum){
	string s1, s2;
	int index_1 = 0, index_2 = 0;
	do{
		cout <<"輸入景點1: ";
		cin >>s1;
		//FIND(DB, curNum, DB[curNum].getName(), 1) != -1)
		index_1 = FIND(DB, curNum, s1, 1);
		if( index_1 == -1)
			cout <<"無該景點 請重新輸入"<<endl;
	}while(index_1 == -1);
	do{
		cout <<"輸入景點2: ";
		cin >>s2;
		//FIND(DB, rNum, DB[curNum].getName(), 1) != -1)
		index_2 = FIND(DB, curNum, s2, 1);
		if( index_2 == -1)
			cout <<"無該景點 請重新輸入"<<endl;
	}while(index_2 == -1);	
	cout <<"distance: "<<DB[index_1].dis(DB[index_2])<< endl;
}

void FIND_MIN_DIS(SIGHT *DB, int curNum){
	string oriSite;
	int oriIndex = 0;
	do{
		cout <<"請輸入原地點: ";
		cin >>oriSite;
		oriIndex = FIND(DB, curNum, oriSite, 1);		
		if(oriIndex == -1)
			cout<<"無此地點 請重新入數"<< endl;
	}while(oriIndex == -1);
	int min_index = 0;
	for(int i=0;i<curNum;i++){
		if(i == oriIndex)
			continue;
		// 找最小距離index
		if(DB[oriIndex].dis(DB[i]) < DB[oriIndex].dis(DB[min_index]))
			min_index = i;
	}
	cout <<"最短距離景點: "<<DB[min_index].getName()<< endl;
}

void FIND_FIVE_LOCAL_SITE(SIGHT *DB, int curNum){
	string oriSite;
	int oriIndex = 0;
	do{
		cout <<"請輸入原地點: ";
		cin >>oriSite;
		oriIndex = FIND(DB, curNum, oriSite, 1);		
		if(oriIndex == -1)
			cout<<"無此地點 請重新入數"<< endl;
	}while(oriIndex == -1);	
	int min_index[5] = {0};
	int *index = (int*)malloc(sizeof(int)*(curNum-1) ); // 存index
	double *value = (double*)malloc(sizeof(double)*(curNum-1) ); // 存距離
	int cnt = 0; // 紀錄存到第幾筆
	for(int i=0;i<curNum;i++){
		if(i == oriIndex)
			continue;
		index[cnt] = i;
		value[cnt] = DB[oriIndex].dis(DB[i]);
		cnt ++;
	}
	// 排序 找出最小 5 個index
	for(int i=0;i<5;i++){
		for(int j=i+1;j<curNum-1;j++){
			if(value[i] > value[j]){
				SWAP(value[i], value[j]);
				SWAP(index[i], index[j]);
			}
		}
	}
	for(int i=0;i<5;i++){
		DB[index[i]].show();
	}
}

int main(void){
	int chose = 1;
	int curNum = 0;
	SIGHT DB[MAX];

	while(chose != 0){
		cout <<"(1)新增 (2)刪除 (3)印出全部 (4)印出指定地區景點 \n(5)印出指定類型景點 (6)印出兩地點距離 (7)找出某地附近(最近)景點 (8)找出某地附近(最近5個)景點\n請輸入選擇: ";
		cin >>chose;
		switch(chose){
			case 0: cout<<"end"<<endl; break;
			case 1: ADD(DB, curNum); break;
			case 2: DELTE(DB, curNum); break;
			case 3: SHOW(DB, curNum); break;
			case 4: SHOW_TOWN(DB, curNum); break;
			case 5: SHOW_TYPE(DB, curNum); break;
			case 6: DIS(DB, curNum); break;
			case 7: FIND_MIN_DIS(DB, curNum); break;
			case 8: FIND_FIVE_LOCAL_SITE(DB, curNum); break;
			default: cout<<"wrong input"<<endl; break;
		}
	}

	return 0;
}