#include "iostream"
using namespace std;
#include "stdio.h"
// k���������ǰ���������������С���������������������
//����ͷ���������ң�
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
//����һ������� �߼����ˣ������벻̫����
/*
����һ�������ұ� Min[n]����Ӧλ����Min[i]�������ԭ����A[i]λ��������һ���ֵ���Сֵ��

һ������Max���������ڱ���A[n]ʱ�����������ֵ��

����A[n]����� A[i]>=Max ����ǰ��������󣩣����� A[i] <= Min[i] ���Ⱥ��������С�������A[i].
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
		*pcur<*(pM+1)? *pM=*pcur : *pM=*(pM+1);		// ���조���ұ�
	}

	int Max=*beg;
	for(pcur=beg, pM=Min; pcur<=end; ++pcur, ++pM){
		if(*pcur > Max){					// �޸ġ���ǰ����ǰ�沿�ֵ����ֵ��
			Max = *beg;
		}
		if(*pcur >= Max && *pcur <= *pM){		// �ж��Ƿ��������
			cout<<*pcur<<' ';
		}
	}
	cout<<endl;

	delete[] Min;
}