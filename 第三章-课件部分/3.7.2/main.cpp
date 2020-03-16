#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

/*
二维空间最近邻点对分治算法
排序仅有两次，O(nlgn)
除排序外
T(n)=2T(n/2)+O(n)
T(n)=O(nlgn)
洛谷P1429，非AC
*/
struct node
{
    double x;
    double y;
};

//结构体比较，前者小返回1，否则为0
bool comparex(const node &a,const node &b)
{
    if (a.x == b.x)
    {
        return a.y<=b.y;
    }
    else
    {
        return a.x<b.x;
    }
}
bool comparey(const node &a,const node &b)
{
    if (a.y == b.y)
    {
        return a.x<=b.x;
    }
    else
    {
        return a.y<b.y;
    }
}
double Distance(node A,node B)
{
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}
double MinDistance(node A[],node B[],int n)
{
    //一般情况
    if (n == 1)
    {
        return INFINITY;
    }
    else if (n == 2)
    {
        return Distance(A[0],A[1]);
    }
    //递归情况
    else
    {
        //划分阶段,选出中位数,复制结构体数组
        node median= A[(n-1)/2];
        int i,I,j=0,k=0,Count;
        //划分就卡在线上，中位数默认左侧,2O(N)
        node Aleft[(n+1)/2],Bleft[(n+1)/2];
        node Aright[n/2],Bright[n/2];
        node Mid1[n],Mid2[n];
        for (i=0;i<(n+1)/2;i++)
        {
            Aleft[i] = A[i];
        }
        for (;i<n;i++)
        {
            Aright[i-(n+1)/2] = A[i];
        }
        for (i=0;i<n;i++)
        {
            if (comparex(median,B[i]))
            {
                Bright[j++] = B[i];
            }
            else
            {
                Bleft[k++] = B[i];
            }
        }
        //解决阶段2T(n/2)
        double d1 = MinDistance(Aleft,Bleft,(n+1)/2);
        double d2 = MinDistance(Aright,Bright,n/2);
        cout<<d1<<" "<<d2<<endl;
        //合并阶段O(n)
        double d = min(d1,d2);
        j = 0;
        k = 0;
        I = 0;
        //先按y排列找到在中部的点
        for (i=0;i<n;i++)
        {
            if (B[i].x<=median.x && B[i].x > median.x-d)
            {
                Mid1[j++] = B[i];
            }
            else if (B[i].x>median.x && B[i].x <= median.x+d)
            {
                Mid2[k++] = B[i];
            }
        }
        //之后对Mid中的元素进行操作，最多Mid2中每个数遍历7次(Mid1中一次)，复杂度8O(n)
        if (k == 0)
        {
            return d;
        }
        for (i=0;i<j;i++)
        {
            //舍去过于靠下的左边的点
            if (Mid1[i].y<=Mid2[I].y-d)
            {
                continue;
            }
            //舍去过于靠下的右边的点
            while (Mid1[i].y>=Mid2[I].y+d && I<k)
            {
                I++;
            }
            //记录第一个可能有用值
            int temp = I;
            for (Count = 0;Count<=5;Count++)
            {
                if (I+Count>=k)
                {
                    break;
                }
                d = d<(Distance(Mid1[i],Mid2[I+Count]))?d:(Distance(Mid1[i],Mid2[I+Count]));
            }
            //回溯
            I = temp;
        }
        return d;
    }
}

int main()
{
    int n,i;
    double result;
  //  cout<<"Input the number of nodes:";
    cin>>n;
    struct node A[n];
    struct node B[n];
    for (i=0;i<n;i++)
    {
        cin>>A[i].x>>A[i].y;
        B[i] = A[i];
    }
    sort(A,A+n,comparex);
    sort(B,B+n,comparey);
    result = MinDistance(A,B,n);
    printf("%.4f",result);
    return 0;
}
