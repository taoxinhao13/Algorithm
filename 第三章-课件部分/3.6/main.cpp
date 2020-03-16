#include <iostream>
#include <stdio.h>
using namespace std;

/*
求中位数算法
T(n) = T(7*n/10)+T(n/5)+O(n)
所以T(n) = O(n)
*/

//简单插入排序
void InsertionSort(int A[],int left,int right)
{
    int j;
    for (int i = left+1;i<=right;i++)
    {
        j = i;
        while (j>=left+1 && A[j-1]>A[j])
        {
            swap(A[j-1],A[j]);
            j--;
        }
    }
}

//对数x做划分
int Partition(int A[],int left,int right,int x)
{
    int i = left;
    int j = right;
    //无需额外考虑特殊情况,类似一趟快排
    while (i<j)
    {
        while (A[i]<=x && i<j)
        {
            i++;
        }
        swap(A[i],A[j]);
        while (A[j]>x && i<j)
        {
            j--;
        }
        swap(A[i],A[j]);
    }
    if (A[i]<=x)
    {
        return i-left;
    }
    else
    {
        return i-left-1;
    }
}

int Select(int A[],int left,int right,int pos)
{
    //划分阶段
    //排序用时n/5*(5*2)=O(n)
    //选基准元用时T(n/5)
    //划分用时0(n)
    //因此总用时O(n)+T(n/5)
    int x;
    //基本情况
    if (right-left < 5)
    {
        InsertionSort(A,left,right);
        x = A[(left+right)/2];
    }
    //递归情况
    else
    {
        int i;
        for (i=left;i<=right-5;i+=5)
        {
            InsertionSort(A,i,i+4);
            swap(A[(i-left)/5+left],A[i+2]);
        }
        InsertionSort(A,i,right);
        swap(A[(i-left)/5+left],A[(i+right)/2]);

        x = Select(A,left,left+(i-left)/5,(i-left)/10);
    }
    int k = Partition(A,left,right,x);

    //解决阶段,T(7*n/10+6)
    if (k == pos)
    {
        return x;
    }
    else if (k>pos)
    {
        return Select(A,left,left+k-1,pos);
    }
    else
    {
        return Select(A,left+k+1,right,pos-k-1);
    }
}
int main()
{
    int n;
    double result;
    cout<<"Input the length of the Array:";
    cin>>n;
    int A[n];
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    if (n%2 != 0)
    {
        result = Select(A,0,n-1,n/2);
    }
    else
    {
        result = ((double)Select(A,0,n-1,n/2-1)+Select(A,0,n-1,n/2))/2;
    }
    printf("%.1f",result);
    return 0;
}
