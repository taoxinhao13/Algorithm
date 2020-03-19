#include <iostream>

using namespace std;
/*
主元素,O(n)
*/
struct node
{
    int num;
    bool flag;
};
int main()
{
    int i,j=1,n,Count=0;
    cin>>n;
    node A[n];
    for (i=0;i<n;i++)
    {
        cin>>A[i].num;
        A[i].flag=true;
    }
    for (i=0;i<n;i++)
    {
        if (A[i].flag==true)
        {
            while ((A[j].num==A[i].num || A[j].flag==false) && j<n)
            {
                j++;
            }
            if (j==n)
                break;
            A[i].flag=false;
            A[j].flag=false;
        }
    }
    for (i=0;i<n;i++)
    {
        if (A[i].flag==true)
        {
            j = A[i].num;
            break;
        }
    }
    for (i=0;i<n;i++)
    {
        if (A[i].num == j)
        {
            Count++;
        }
    }
    if (Count>n/2)
    {
        cout<<j;
    }
    else
    {
        cout<<"No main element";
    }
    return 0;
}
