#include <iostream>
#include <string.h>
using namespace std;

/**
n>=m,否则基础上转置即可
时间复杂度O(n^3)
空间复杂度O(n^2)
*/
int main()
{
    int i,j,k,n,m;
    cin>>n>>m;
    int A[n][m];
    int R[n+1][n+1];

    memset(R,0,sizeof(int)*(n+1)*(n+1));
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            cin>>A[i][j];
        }
    }

    R[1][2] = A[0][1] + A[1][0];

    for (k=2;k<m+n;k++){
        for (i=n-1;i>0;i--){
            for (j=n;j>i;j--){
                if (k>=i-1 && k>=j-1 && i+m-1>k && j+m-1>k && i+j-1>k){
                    R[i][j] = max(max(R[i][j-1],R[i-1][j]),max(R[i-1][j-1],R[i][j])) +A[i-1][k-i+1]+A[j-1][k-j+1];
                }
            }
        }
    }

    cout<<R[n-1][n]+A[n-1][m-1]+A[0][0];
    return 0;
}
