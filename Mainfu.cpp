#include"stdio.h"  
int GetMinK(int A[],int n,int k)  
{  
    int s=-1,i=0,j=n-1,temp;  
    int beg=i;  
    int end=j;  
    while(s!=k)  
    {  
        beg=i;  
        end=j;  
        temp=A[i];  
        while(i<j)  
        {  
            while(i<j&&A[j]>=temp)j--;A[i]=A[j];  
                   while(i<j&&A[i]<=temp)i++;A[j]=A[i];  
        }  
         A[i]=temp;  
        s=i;  
   
     
        if(s==k)  
            return A[k];  
        if(s>k){i=beg;j--;} //�����Ѱ��   
        if(s<k){j=end;i++;} //���Ҳ�Ѱ��   
    }  
}  
int main()  
{  
    int A[]={2,3,4,1,5,10,9,7,8,6};  
    int k=3;  
    printf("��%dСԪ��Ϊ��(��0��ʼ)\n%d ",k,GetMinK(A,10,k));  
	getchar();
    return 0;  
}