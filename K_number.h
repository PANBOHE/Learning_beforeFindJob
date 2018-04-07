#include "iostream"
using namespace std;
#include "stdio.h"
// k数，这个数前面的所有数都比他小，后面的所有数都比他大
//今日头条面试问我，
//07042018
int findNum_k(int *arr,int n)
{
	if(arr == NULL) return 0;
	int *cand = new int[n];
	int idx=0;
	cand[idx]=arr[0];
	int max =arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>= max){
			cand[idx++]=arr[i];
			max=arr[i];
		}else{
			while(idx>0 && cand[idx-1]>arr[i])
				idx--;
		}
	}
	cout<<"num: ";
	for(int i=0;i<idx;i++)
	{
		cout<<cand[i]<<" ";

	}
	cout<<endl;
	return 0;

}
//还有一个查表法， 逻辑懂了，，代码不太明白
/*
构造一个“查找表” Min[n]；对应位置上Min[i]，存放了原数组A[i]位置往后这一部分的最小值。

一个变量Max，保存了在遍历A[n]时，遇到的最大值。

遍历A[n]，如果 A[i]>=Max （比前面的数都大），并且 A[i] <= Min[i] （比后面的数都小），输出A[i].
*/
void LookupWay(int *beg, int *end){
	if(beg == end){
		cout<<*beg<<end;
		return;
	}

	int Size = end-beg+1;
	int *Min = new int[Size];
	int *pcur, *pM;

	*(Min+Size-1) = *end;
	for(pcur=end-1, pM=Min+Size-2; pcur>=beg; --pcur, --pM){
		*pcur<*(pM+1)? *pM=*pcur : *pM=*(pM+1);		// 构造“查找表”
	}

	int Max=*beg;
	for(pcur=beg, pM=Min; pcur<=end; ++pcur, ++pM){
		if(*pcur > Max){					// 修改“当前对象前面部分的最大值”
			Max = *beg;
		}
		if(*pcur >= Max && *pcur <= *pM){		// 判断是否符合条件
			cout<<*pcur<<' ';
		}
	}
	cout<<endl;

	delete[] Min;
}