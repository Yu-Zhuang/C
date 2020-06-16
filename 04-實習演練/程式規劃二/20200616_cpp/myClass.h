
using namespace std;
class SIGHT{
public:
	string getName(void){ return name; };
	string getTown(void){ return town; };
	string getType(void){ return type; };
	double getX(void){ return x; };
	double getY(void){ return y; };
	void setName(void){
		cout <<"input name: ";
		cin >>name;
	}
	void setTown(void){
		string site[13] = {"花蓮市", "鳳林鎮", "玉里鎮", "新城鄉", "吉安鄉", "壽豐鄉", "光復鄉", "豐濱鄉", "瑞穗鄉", "富里鄉", "秀林鄉", "萬榮鄉", "卓溪鄉"};
		int chose = 0;
		do{
			cout <<"(1)花蓮市、(2)鳳林鎮、(3)玉里鎮、(4)新城鄉、(5)吉安鄉、(6)壽豐鄉、\n(7)光復鄉、(8)豐濱鄉、(9)瑞穗鄉、(10)富里鄉、(11)秀林鄉、(12)萬榮鄉、(13)卓溪鄉\n請輸入景點定點: ";
			cin >> chose;
			if(chose < 1 || chose > 13)
				cout <<"wrong input"<< endl;
		}while(chose < 1 || chose > 13);
		town = site[chose-1];
	}
	void setType(void){
		string t_type[4] = {"風景", "美食", "體驗", "探索"} ;
		int chose = 0;
		do{
			cout <<"(1)風景 (2)美食 (3)體驗 (4)探索\n請輸入景點類型: ";
			cin >> chose;
			if(chose < 1 || chose > 4)
				cout <<"wrong input"<< endl;
		}while(chose < 1 || chose > 4);
		type = t_type[chose-1];
	}
	void setX(void){
		int min = -180, max = 180;
		do{
			cout <<"請輸入經度(-180~180): ";
			cin >> x;
			if(x>max || x<min)
				cout <<"wrong input"<< endl;
		}while(x>max || x<min);
	}
	void setY(void){
		int min = -90, max = 90;
		do{
			cout <<"請輸入緯度(-90~90): ";
			cin >> y;
			if(y>max || y<min)
				cout <<"wrong input"<< endl;
		}while(y>max || y<min);
	}
	double dis(SIGHT ts){
		return sqrt((x-ts.x)*(x-ts.x)+(y-ts.y)*(y-ts.y));
	}
	void show(){
		cout <<"名: "<<name<<"\t鄉鎮: "<<town<<"\t類型: "<<type<<"\t經度: "<<x<<"\t緯度: "<<y<< endl;
	}


private:
	string name;
	string town;
	string type;
	double x; // 經度
	double y; // 緯度
};



