#include "iostream"
#include "stdio.h"
using namespace std;

//0404 希尔排序
void swapInt(int *a,int *b)
{
	int c=*a;
    *a=*b;
	*b=c;
	
}

void shell(int *data,int len)
{
	if(len<=1 || data==NULL)
		return;
	for(int div=len/2;div>=1;div=div/2)
	{
		for(int i=0;i<div;++i)
		{
			for(int j=i;j<len-div;j=j+div)
			{
				for(int k=j;k<len;k=k+div)
				{
					if(data[j]>data[k])
					{
						swapInt(data+j,data+k);
					}
				}
			}
		}
	}
}

void bubble_sort(int arr[], int len) // 冒泡排序
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
        if (arr[j] > arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
}
