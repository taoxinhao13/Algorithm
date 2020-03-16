#include <iostream>
#include <cmath>
#define INFINITY 10000000.1
using namespace std;

/*
一维空间最近邻点对分治算法
T(n)=2T(n/2)+O(n)
T(n)=O(nlgn)
复用上题代码
*/

void InsertionSort(double A[],int left,int right)
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
int Partition(double A[],int left,int right,double x)
{
    int i = left;
    int j = right;
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

double Select(double A[],int left,int right,int pos)
{
    double x;
    if (right-left < 5)
    {
        InsertionSort(A,left,right);
        x = A[(left+right)/2];
    }
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

double MinDistance(double A[],int n)
{
    //一般情况
    if (n == 1)
    {
        return INFINITY;
    }
    else if (n == 2)
    {
        return abs(A[0]-A[1]);
    }

    //递归情况
    else
    {
        //划分阶段,选出中位数,复制数组并取出最大值最小值,O(n)
        double median,Max,Min;
        int i,j=0,k=0;
        //保证不会让点卡在线上
        median = ((double)Select(A,0,n-1,n/2-1)+Select(A,0,n-1,n/2))/2;
        double left[n/2];
        double right[(n+1)/2];
        Max = -INFINITY;
        Min = INFINITY;
        for (i=0;i<n;i++)
        {
            if (A[i]<median)
            {
                left[j++]=A[i];
                Max = Max>A[i]?Max:A[i];
            }
            else if (A[i]>median)
            {
                right[k++]=A[i];
                Min = Min<A[i]?Min:A[i];
            }
            else  //与两数平均数相等，说明有重复数据
            {
                return 0;
            }
        }

        //解决阶段2T(n/2)
        double d1 = MinDistance(left,n/2);
        double d2 = MinDistance(right,(n+1)/2);

        //合并阶段O(1)
        return min(min(Min-Max,d1),min(d1,d2));
    }
}
int main()
{
    int n,i;
    double result;
    cout<<"Input the number of nodes:";
    cin>>n;
    double A[n];
    for (i=0;i<n;i++)
    {
        cin>>A[i];
    }
    result=MinDistance(A,n);
    //精度
    if (result<0.000001)
    {
        result = 0;
    }
    cout<<result;
    return 0;
}
