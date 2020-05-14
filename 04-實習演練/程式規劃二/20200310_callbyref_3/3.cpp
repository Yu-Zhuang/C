#include<stdio.h>
#include<stdlib.h>
int main(void){
	char input[1000];
	int list[10]={0},data[10]={0};
	int n=0, a=0, ten=0, b=0, temp=0, ran=0;
	//input;
	scanf("%d", &n);
	scanf(" %[^\n]", input); 
	//compute string to number, and put into list[] and datap[]
	while(input[a]!='\0'){
		temp=a; ten=1;
		while(input[a]!=32&&input[a]!='\0') { ten*=10; a++; }
		a=temp; ten/=10;
		while(input[a]>='0'&&input[a]!='\0'){
			list[b]+=(input[a]-'0')*ten;
			ten/=10;
			data[b]+=input[a]-'0';
			a++;
		}
		a++; b++;
	}//sort;
	for(int i=0;i<n-1;i++){ 
		for(int j=i+1;j<n;j++){
			if(data[i]>data[j]||(data[i]==data[j]&&list[i]>list[j])){
				ran=data[i]; data[i]=data[j]; data[j]=ran;
				ran=list[j]; list[j]=list[i]; list[i]=ran;	
			}
		}
	}//output print
	for(int i=0;i<n;i++){ 
		if(i!=n-1) printf("%d ",list[i]);		
		else printf("%d\n",list[i]);
	}
	return 0;
}