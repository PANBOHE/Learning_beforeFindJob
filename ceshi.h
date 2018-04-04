#include "iostream"
#include "stdio.h"
using namespace std;

int findNum(int *arr,int n)
{
	if(arr==  NULL) return 0;
	int *cand = new int[n];
	int idx=0;
	cand[idx++]=arr[0];
	int max = arr[0],i;
	for(i=1;i<n;i++)
	{
		if(arr[i]>=max)
		{
			cand[idx++]=arr[i];
			max=arr[i];
		}else{
			while(idx>0 && cand[idx-1]>arr[i]) idx--;

		}
	}
	std::cout<<"num: ";
	for(i=0;i<idx;i++)
		printf("%d ", cand[i]);
	printf("\n");
	return idx;
}

void ViolentWay(int *beg, int *end){  
    if(beg == end){  
        cout<<*beg<<end;  
        return;  
    }  
    int *cur;  
    for(cur = beg; cur<=end; ++cur){  
        int *temp;  
        for(temp = beg; temp<cur; ++temp){  //与前面的数进行比较  
            if(*temp > *cur){  
                break;  
            }  
        }  
        if(temp != cur){    // 如果是中途break出来的，则 temp!=cur ，这时要continue，对下一个数进行判断  
            continue;  
        }  
        for(temp=cur+1; temp<end+1; ++temp){// 与后面的数进行比较  
            if(*temp < *cur){  
                break;  
            }  
        }  
        if(temp == end+1){// 两个循环安全走完，复合要求  
            cout<<*cur<<' ';  
        }  
    }  
    cout<<endl;  
} 

void printarr(int array[], int n) //打印数组函数
{
	for (int i=0;i<n;i++)
	{
		cout<<array[i]<<"  ";
		
	}
	cout<<endl;
}
