#include <iostream>
#include <algorithm>
using namespace std;

/**
时间复杂度O(n)
空间复杂度O(1)
*/
int main()
{
    int i,n,result=0;
    cin>>n;
    int A[n];
    for (i=0;i<n;i++){
        cin>>A[i];
    }

    sort(A,A+n);
    for (i=0;i<n;i++){
        result+=(n-i-1)*A[i];
    }
    cout<<result;
    return 0;
}
