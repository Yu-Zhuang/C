#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>

#define ID_SIZE 100 //id max length
#define NAME_SIZE 100 // name max length
#define LIST_SIZE 100  //list max size
// define list
typedef struct list{
	char id[ID_SIZE];
	char name[NAME_SIZE];
	double price;
	int number; //庫存量
}LIST;
// FUNCTION
void LIST_PRINT(LIST *DB, int size); // print data base(DB)
void LIST_SORT(LIST *DB, int size); // sort DB
void LIST_INSERT(LIST *DB, int *size); // insert element to DB
void LIST_LOW(LIST *DB, int *ret, int size, int* N); // find number of product <10

int LIST_FIND(LIST *DB, char *target, int size); //find element; return address;
int FIND(LIST *DB, char *target, int size);  //find element ; return duplicate number;

int main(void){
	LIST DB[LIST_SIZE];
	int chose=0, i=0, DBsize=0;
	char ch;
//input product
	while(chose!=-1){
		start:
		printf("連續輸入商品,輸入 -1 結束:\n");
		printf("ID: "); scanf("%[^\n]", DB[i].id);
		if(DB[i].id[0]=='-' && DB[i].id[1]=='1') break;
	// id is unique or not
		if( (FIND(DB, DB[i].id, i+1)) > 1 ) { getchar(); printf("ID 已重複, 請重新輸入!\n"); goto start; } 
		printf("名稱: ");  getchar(); scanf("%[^\n]",DB[i].name); 
		printf("價錢: ");  getchar(); scanf("%lf", &DB[i].price); 
		printf("數量: ");  scanf("%d", &DB[i].number); getchar();
		i++;
	}
	DBsize=i; // number of element in data base
	LIST_SORT(DB, DBsize); // sort element depend on ID
	LIST_PRINT(DB, DBsize); // print DB
// select function 
	while(chose!=-1){
	// input chose
		printf("\t@主選單@\n(1) 查詢商品\n(2) 列出庫存量少於10的商品\n(3) 新增商品\n(-1)結束程式\n請輸入: "); scanf("%d", &chose);
	// compution
		if(chose == -1) break;
	// find element
		else if(chose == 1){
			char target[ID_SIZE];
			int adr=0;
		// input id of target 
			printf("請輸入商品ID: "); scanf("%s", target); getchar();
		// find() , adr = element address in DB
			adr=LIST_FIND(DB, target, DBsize);
			//if found -> print element
			if(adr){
				printf("[ID]\t[名稱]\t[價錢]\t[數量]\n");
				printf("%s\t%s\t%.1lf\t%d\n", DB[adr-1].id, DB[adr-1].name, DB[adr-1].price, DB[adr-1].number);
			}
			//if not found 
			else printf("無此商品!\n");
		}
	// find number<10 in DB
		else if( chose == 2){
			int ret[DBsize], ArraySize=0;
		// find number <10 in DB
			LIST_LOW(DB, ret, DBsize, &ArraySize); 
		// if has product's number < 10
			if(ArraySize){
				printf("[ID]\t[名稱]\t[價錢]\t[數量]\n");
			// print those products
				for(int i=0;i<ArraySize;i++){
				printf("%s\t%s\t%.1lf\t%d\n", DB[ret[i]].id, DB[ret[i]].name, DB[ret[i]].price, DB[ret[i]].number);
				}
			}
		}
	// insert element to DB
		else if(chose == 3){
		// insert()
			LIST_INSERT(DB, &DBsize);
		// sort DB
			LIST_SORT(DB, DBsize);
		// print DB
			LIST_PRINT(DB, DBsize);
		}
		printf("繼續按1 , 結束按-1: "); scanf("%d", &chose);
	}
//end
	return 0;
}
// insert element to DB
void LIST_INSERT(LIST *DB, int *size){
	int i=size[0];
	char *tmp;
	start2:
	// input element
	printf("ID: ");  getchar(); scanf("%[^\n]", DB[i].id);
	// whether id is unique?
	if( (FIND(DB, DB[i].id, i+1)) > 1 ) { getchar(); printf("ID 已重複, 請重新輸入!\n"); goto start2; } 
	printf("名稱: ");  getchar(); scanf("%[^\n]",DB[i].name); 
	printf("價錢: ");  getchar(); scanf("%lf", &DB[i].price); 
	printf("數量: ");  scanf("%d", &DB[i].number); 
	// number of element in data base +=1;
	size[0]++; return; 
}
// find number of product <10
void LIST_LOW(LIST *DB, int *ret, int size, int *N){
	int count=0;
	for(int i=0;i<size;i++){
		// 如果 數量 小於 10 將 index 存給 ret[];
		if(DB[i].number < 10 ) { ret[count]=i; count++; }
	}
	// 有幾個商品 小於 10
	N[0]=count;
}
// find element in DB ; return duplicate number
int FIND(LIST *DB, char *target, int size){
	int ret=0;
	for(int i=0;i<size;i++){
		if(strcmp(DB[i].id, target) == 0) ret++;
	}
	// return duplicate number
	return ret;
}
// find element in DB ; return (address+1) of target
int LIST_FIND(LIST *DB, char *target, int size){
	for(int i=0;i<size;i++){ 

		if(strcmp(DB[i].id, target) == 0) return (i+1); // return (address+1) of target
	}
	// not fine return 0;
	return 0;
}
// sort DB
void LIST_SORT(LIST *DB, int size){
	char tmp[20];
	// selection sort
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
		// sort depend on ID number ( small to big)
			if(strcmp(DB[j].id, DB[i].id)<0){ 
				DB[i].price = DB[j].price + (DB[j].price=DB[i].price) - DB[i].price;
				DB[i].number = DB[j].number + (DB[j].number=DB[i].number) - DB[i].number;
				strcpy(tmp, DB[j].id); strcpy(DB[j].id, DB[i].id); strcpy(DB[i].id, tmp);
				strcpy(tmp, DB[j].name); strcpy(DB[j].name, DB[i].name); strcpy(DB[i].name, tmp);
			}
		}
	}
}
// print DB
void LIST_PRINT(LIST *DB, int size){
	printf("========== LIST_PRINT ============\n");
	printf("[ID]\t[名稱]\t[價錢]\t[數量]\n");
	for(int i=0;i<size;i++){
		//print each element
		printf("%s\t%s\t%.1lf\t%d\n", DB[i].id, DB[i].name, DB[i].price, DB[i].number);
	}
	printf("========== END LIST_PRINT ============\n");
}





