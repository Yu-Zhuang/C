# include <iostream>
# include <cstdlib>
using namespace std;
int main(void){
	int n = 0;
	long long int price = 0; // 預算
	int p = 0; // 人數
	int p_n = 0; // 價格數
	int num[100] = {0}; // 禮物價格
	
	//do{
	cin >>n;
	//	scanf("%d", &n);
	//}while(n<1 || n>10);
	for(int i=0;i<n;i++){
		//do{
		cin >>price>>p>>p_n;
	//		scanf("%d %d %d", &price, &p, &p_n);
		//}while(p > p_n || p_n>100);
		//T, m 和 k ， m ≤ k ≤ 100 ；
		for(int j=0;j<p_n;j++)
			cin >>num[j];
			//scanf("%d", &num[j]);
		int tmp ;
		for(int m=0;m<p_n-1;m++){
			for(int k=m+1;k<p_n;k++){
				if(num[m] > num[k]){
					tmp = num[m];
					num[m] = num[k];
					num[k] = tmp;
				}
			}
		}
		long long int total = 0;
		for(int a=0;a<p;a++){
			if(total - price > 0)
				break;
			total += num[a];
		}
		if(total > price)
			cout <<"Impossible"<<endl;
			//printf("Impossible\n");
		else
			cout <<total<<endl;
			//printf("%lld\n", total);
	}
	return 0;
}