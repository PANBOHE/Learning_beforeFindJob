#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
using namespace std;
void Merge(int* data, int a,int b, int length,int n	)
{
	int right;
	if(b+length-1 >=n-1) right = n-b;
	else right=length;
	int* temp = new int[length+right];
	int i=0,j=0;
	while(i<=length-1 && j<=right-1)
	{
		if(data[a+i]<=data[b+j])
		{
			temp[i+j]=data[a+i];
			i++;
		}else
		{
			temp[i+j]=data[b+j];
			j++;
		}
	}
	if(j==right){ //a中还有元素，且全都比b中的大，a[i]还未使用
		memcpy(temp+i+j,data+a+i,(length-i)*sizeof(int));
	
	}else if(i==length){
		memcpy(temp+i+j,data+b+j,(right-j)*sizeof(int));
	}
	memcpy(data+a,temp,(right+length)*sizeof(int));
	delete[] temp;
}

void MergeSort(int* data,int n)
{
	int step=1;
	while(step<n)
	{

		for(int i=0;i<=n-step-1;i+=2*step)
		{
			Merge(data,i,i+step,step,n);
			step=step*2;
		}
	}
}