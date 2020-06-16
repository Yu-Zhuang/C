# include <iostream>
# include <cstdlib>
# include <math.h>
//using namespace std;


void VEC_ADD(double *v1, double *v2, double *ret){
	for(int i=0;i<5;i++)
		ret[i] = v1[i] + v2[i]; // 兩向量 相加
}

void VEC_SUB(double *v1, double *v2, double *ret){
	for(int i=0;i<5;i++)
		ret[i] = v1[i] - v2[i]; // 兩向量 相乘
}

void VEC_DOT(double *v1, double *v2, double *ret){
	ret[0] = 0;
	for(int i=0;i<5;i++)
		ret[0] += v1[i] * v2[i]; // 兩向量 內積
}

void VEC_NORM(double *v1, double *v2, double *ret){
	ret[0] = 0;
	for(int i=0;i<5;i++)
		ret[0] += (v1[i]-v2[i]) * (v1[i]-v2[i]);
	ret[0] = sqrt(ret[0]);  // 兩向量 距離
}

void VEC_MULTI(double *v1, double num, double *ret){
	for(int i=0;i<5;i++)
		ret[i] = v1[i] * num; // 向量 乘一實數
}

void VEC_UNI(double *v, double *ret){
	double distance = 0;
	for(int i=0;i<5;i++) // 求出該向量長度
		distance += v[i] * v[i];
	distance = sqrt(distance);
	for(int i=0;i<5;i++)
		ret[i] = v[i] / distance; // 換算 單位向量
}