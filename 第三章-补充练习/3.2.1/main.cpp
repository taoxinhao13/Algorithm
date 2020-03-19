#include <iostream>
#define IMPOSSIBLE -1000000000
using namespace std;
/*
主元素问题,元素不可排序，本题用int举例，实际改为泛型即可
分治法，复杂度O(nlgn)
*/

int MainElement(int A[],int left,int right)
{
    int p1,p2;
    int i,Count;
    //基本情况
    if (left == right)
    {
        return A[left];
    }
    //划分
    int middle = (left + right) / 2;
    //解决问题
    p1 = MainElement(A,left,middle);
    p2 = MainElement(A,middle+1,right);
    if (p1!=IMPOSSIBLE)
    {
        Count = 0;
        for (i=left;i<=right;i++)
        {
            if (p1 == A[i])
            {
                Count++;
            }
        }
        if (Count>(right-left+1)/2)
        {
            return p1;
        }
    }
    if (p2!=IMPOSSIBLE)
    {
        Count = 0;
        for (i=left;i<=right;i++)
        {
            if (p2 == A[i])
            {
                Count++;
            }
        }
        if (Count>(right-left+1)/2)
        {
            return p2;
        }
    }
    return IMPOSSIBLE;
}
int main()
{
    int n,i,p;
    cin>>n;
    int A[n];
    for (i=0;i<n;i++)
    {
        cin>>A[i];
    }
    p=MainElement(A,0,n-1);
    if (p==IMPOSSIBLE)
    {
        cout<<"No main element!";
    }
    else
    {
        cout<<p;
    }
    return 0;
}
