#include <iostream>
#define IMPOSSIBLE -1000000000
using namespace std;
/*
主元素问题,元素不可排序，本题用int举例，实际改为泛型即可
分治法，复杂度O(nlgn)
*/
//最多有两个主元素
struct Possible{
    int x1;
    int x2;
};
Possible MainElement(int A[],int left,int right)
{
    Possible result,p1,p2;
    result.x1=IMPOSSIBLE;
    result.x2=IMPOSSIBLE;
    int i,j,Count,num=0;
    //基本情况
    if (left == right)
    {
        result.x1=A[left];
        result.x2=IMPOSSIBLE;
        return result;
    }
    //划分
    int temp[4];
    int middle = (left + right) / 2;
    //解决问题
    p1 = MainElement(A,left,middle);
    p2 = MainElement(A,middle+1,right);
    //合并，对选出的可能主元素暴力查找,4O(n)
    temp[0] = p1.x1;
    temp[1] = p1.x2;
    temp[2] = p2.x1;
    temp[3] = p2.x2;
    for (i=1;i<4;i++)
    {
        for (j=0;j<i;j++)
        {
            if (temp[i]==temp[j])
            {
                temp[i]=IMPOSSIBLE;
                break;
            }
        }
    }
    for (i=0;i<4;i++)
    {
        if (temp[i]!=IMPOSSIBLE)
        {
            Count=0;
            for (j=left;j<=right;j++)
            {
                if (temp[i]==A[j])
                {
                    Count++;
                }
            }
            if (Count>=(right-left+1)/2)
            {
                if (num==0)
                {
                    result.x1=temp[i];
                    num++;
                }
                else if (num==1)
                {
                    result.x2=temp[i];
                    num++;
                }
            }
        }
    }
    return result;
}
int main()
{
    int n,i;
    Possible p;
    cin>>n;
    int A[n];
    for (i=0;i<n;i++)
    {
        cin>>A[i];
    }
    p=MainElement(A,0,n-1);
    if (p.x1 == IMPOSSIBLE)
    {
        cout<<"No main element!";
    }
    else
    {
        cout<<p.x1;
        if (p.x2!=IMPOSSIBLE)
        {
            cout<<" "<<p.x2;
        }
    }
    return 0;
}
