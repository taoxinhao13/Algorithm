#include <iostream>

using namespace std;
/**
时间复杂度O(n^3),空间复杂度O(n^2)
*/
int main()
{
    int n,i,j,k;
    cin>>n;
    int A[n];
    int R[n][n];
    int Sum[n][n];
    for (i=0;i<n;i++){
        cin>>A[i];
    }
    for (i=0;i<n;i++){
        R[i][i] = 0;
        Sum[i][i] = A[i];
    }
    for (i=1;i<n;i++){
        for (j=0;j<n-i;j++){
            Sum[j][j+i] = Sum[j][j]+Sum[j+1][j+i];
            R[j][j+i] = 2147483647;
            for (k=j;k<j+i;k++){
                R[j][j+i] = min(R[j][j+i],R[j][k] + R[k+1][j+i] + Sum[j][j+i]);
            }
        }
    }
    cout<<R[0][n-1];
    return 0;
}
