#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// FUNCTION_ANNOUNCEMENT
int* ARY_CREATE(int n); 
double ARY_AVR(int *nums, int numsSize);
double ARY_MEDIAN(int *nums, int numsSize);
void ARY_SORT(int *nums, int numsSize);
void ARY_PRINT(int *nums, int numsSize);
// MAIN
int main(void){
	srand(time(NULL));
	int n=0, *ary=NULL;
	double avr=0, mdn=0;
	start:
	// 輸入 array 大小
	printf("請輸入陣列大小: ");
	scanf("%d", &n);
	// FPD
	while(n<1) { printf("錯誤!\n"); goto start; }
	// 創建array
	ary = ARY_CREATE(n);
	// 排序array
	ARY_SORT(ary, n);
	// 找出平均數與中位數並指派給avr與mdn變數
	avr = ARY_AVR(ary, n);
	mdn = ARY_MEDIAN(ary, n);
	// 印出結果
	printf("排序後結果: "); ARY_PRINT(ary,n);
	printf("中位數:%.2lf\t平均數:%.2lf\n", mdn, avr);
	// 釋放記憶體
	free(ary);
	return 0;
}
// 印出array狀態
void ARY_PRINT(int *nums, int numsSize){
	for(int i=0;i<numsSize;i++) //依序印出
		printf("%d ", nums[i]);
	printf("\n");
}
// 排序array
void ARY_SORT(int *nums, int numsSize){
	// 氣泡排序 由小到大
	for(int i=0;i<numsSize-1;i++)
		for(int j=i+1;j<numsSize;j++)
			if(nums[i] > nums[j]) 
				nums[i] = nums[j] + (nums[j]=nums[i]) - nums[i];
}
// 傳回array 中位數
double ARY_MEDIAN(int *nums, int numsSize){
	// 大小是基數的話
	if(numsSize%2)
		return nums[numsSize/2];
	// 大小是偶數的話
	return double((double(nums[numsSize/2])+double(nums[numsSize/2-1]))/2);
}
// 傳回array 平均
double ARY_AVR(int *nums, int numsSize){
	int sum = 0;
	// 計算加總
	for(int i=0;i<numsSize;i++)
		sum += nums[i];
	// 傳回平均
	return double(sum)/double(numsSize);
}
// 產生n大小字串 (數值在0~100)
int* ARY_CREATE(int n){
	int *ary = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		ary[i] = rand()%101;
		printf("%d, ", ary[i]);
	}printf("\n");
	return ary;
}