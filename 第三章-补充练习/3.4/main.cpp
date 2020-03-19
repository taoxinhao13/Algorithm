#include <iostream>

using namespace std;
/*分治法求最大子串
复杂度O(nlgn)
*/
int Calculate(int A[],int left,int right)
{
    if (right==left)
    {
        return A[left];
    }
    int i,r1,r2,r3,r4,temp1,temp2,middle=(left+right)/2;
    r1 = Calculate(A,left,middle);
    r2 = Calculate(A,middle+1,right);
    r3 = A[middle];
    temp1=r3;
    for (i=middle-1;i>=left;i--)
    {
        r3+=A[i];
        temp1=max(temp1,r3);
    }
    r4 = A[middle+1];
    temp2 =r4;
    for (i=middle+2;i<=right;i++)
    {
        r4+=A[i];
        temp2=max(temp2,r4);
    }
    temp1 +=temp2;
    return max(max(r1,r2),temp1);
}
int main()
{
    int i,n,result;
    cin>>n;
    int A[n];
    for (i=0;i<n;i++)
    {
        cin>>A[i];
    }
    result = Calculate(A,0,n-1);
    cout<<result;
    return 0;
}
