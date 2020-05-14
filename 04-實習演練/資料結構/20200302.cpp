#include<stdio.h>
#include<stdlib.h>
#include<time.h>

bool ternaryS(int* nums, int numsSize, int target, int* n);
bool binaryS(int* nums, int numsSize, int target, int* n);

int main(void){
	srand(time(NULL));
	int list[10000]={0}, t=0, n=0;
	//initialize array;
	list[9999]=32767;
	for(int i=9999;i>0;i--) list[i-1]=list[i]-rand()%4; 
	//use ternary() find random int(t) 100 times;
	for(int j=0;j<100;j++){ 
		t=rand()%32768; n=0;
		if( ternaryS(list, 10000, t, &n) ) 
			printf("%d. use %d times to comparison, Find target(%d)\n", j+1, n, t);
		else 
			printf("%d. use %d times to comparison, No target(%d)\n", j+1, n, t);
	}
	return 0;
}

bool ternaryS(int* nums, int numsSize, int target, int* n){
	int left=0, right=numsSize-1, ptr_1=0, ptr_2=1;
	while(ptr_2 != ptr_1){
		n[0]+=2;
		ptr_1=(right-left)/3+left; 
		ptr_2=((right-left)/3)*2+left;
		if( target==nums[ptr_1] ) return true; 
		else if(target <= nums[ptr_1]) right=ptr_1; 
		else if(target > nums[ptr_2]) left=ptr_2; 
		else { left=ptr_1; right=ptr_2; }
	}
	return false;
}

bool binaryS(int* nums, int numsSize, int target, int* n){
	int left=0, right=numsSize-1, med=0;
	while((right+left)/2 != left){
		n[0]++;
		med=(right+left)/2;
		if(target == nums[med]) return true; 
		else if(target > nums[med]) left=med; 
		else right=med; 
	}
	return false;
}
/*
		if( ternaryS(list, 10000, t, &n) ) 
			printf("%d. use %d times to comparison, Find target(%d)\n", j+1, n, t);
		else 
			printf("%d. use %d times to comparison, No target(%d)\n", j+1, n, t);
			*/

/*
Writea“ternary”searchfunction
Exercise
– (20%) Construct an array L of 10,000 integers, • L[100,000]=32767
• L[i−1]=L[i]−arandompositiveintegerin[0,3]
– (10%) Generate a random integer t, which is to be searched for in L
– (40%) Write a “ternary” search function (as discussed in Case Study I)
– (30%) Generate t and call your “ternary” search function 100 times
• Outputthenumberofcomparisonsyour“ternary”searchfunction has conducted to search for t in L
*/