#include<stdio.h>  
#include<stdlib.h>  

void seq(char* str, int* size);  

int main(void){  
  int tmp=0, i=0, size=0, n=0;  
  scanf("%d", &n);  
  for(int i=0;i<n;i++){  
    char *str=(char*)malloc(sizeof(char));  
    scanf(" %[^\n]", str);  
    seq(str,&size);  
  }  
  return 0;  
}  

void seq(char* str,int* size){  
  int ary[100]={0}, i=0, j=0, tmp=0, count=0;  
    ary[83]=40; //S  
    ary[72]=30; //H  
    ary[68]=20; //D  
    ary[67]=10; //C  
  while(tmp!=2){ //算字串大小  
    if(str[i]<48) { tmp++; count++; }  
    else tmp=0;  
    i++;  
  }  
  tmp=0;  
  count-=1; //幾張牌  
  *size=i-2; //字串大小  
  int nums[1000]={0}; //放新結構  
  char newstr[1000]={0};  
  for(i=0;i<size[0];i++){  
    if(str[i]<'0') { tmp++; continue; }  
    else if(str[i]>='A') newstr[tmp]=str[i];  //A~Z
    else if(str[i]<'A'&&str[i]>='0'){  // 0~9
      if(str[i+1]>='0'){  // 1x
        nums[tmp]=nums[tmp]+str[i+1]-'0'+10*(str[i]-'0');  
        i++;  
      }  
      else  
        nums[tmp]+=str[i]-'0';  
    }   
  }  
  for(i=0;i<size[0]-1;i++){  //排序  
    for(j=i+1;j<size[0];j++){  
      if(ary[newstr[i]]<ary[newstr[j]]){  
        newstr[i]^=newstr[j];  
        newstr[j]^=newstr[i];  
        newstr[i]^=newstr[j];  
        if(nums[i]!=nums[j]){  
          nums[i]^=nums[j];  
          nums[j]^=nums[i];  
          nums[i]^=nums[j];  
        }  
      }  
      else if(ary[newstr[i]]==ary[newstr[j]]&&nums[i]<nums[j]){  
        nums[i]^=nums[j];  
        nums[j]^=nums[i];  
        nums[i]^=nums[j];  
      }  
    }  
  }  
  for(i=0;i<count;i++){ //印出  
      printf("%c", newstr[i]);  
      if(i!=count-1)  
        printf("%d ", nums[i]);  
      else  
        printf("%d\n", nums[i]);  
  }  
} 