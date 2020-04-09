#include <iostream>

using namespace std;
/**
时间复杂度O(n),空间复杂度O(1)
*/
int main()
{
    int n,i;
    cin>>n;
    double A[n];
    for (i=0;i<n;i++){
        cin>>A[i];
    }
    double Max=A[0],Min=A[0],result=A[0],c1,c2;
    for (i=1;i<n;++i)
    {
        c1=Max*A[i];
        c2=Min*A[i];
        Max=max(max(c1,c2),A[i]);
        Min=min(min(c1,c2),A[i]);
        result=max(result,Max);
    }
    cout<<result;
    return 0;
}

