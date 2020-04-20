#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n,result=0,i;
    cin>>n;
    int A[n],B[n];
    for (i=0;i<n;i++){
        cin>>A[i];
    }
    for (i=0;i<n;i++){
        cin>>B[i];
    }
    sort(A,A+n);
    sort(B,B+n);
    for (i=0;i<n;i++){
        result+=(int)pow((int)A[i],(int)B[i]);
    }
    cout << result;
    return 0;
}
