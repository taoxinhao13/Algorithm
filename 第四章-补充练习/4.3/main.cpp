#include <iostream>

using namespace std;

/**
输出为最大的矩阵的边长大小
时间和空间复杂度都是0(n^2)
*/
int main()
{
    int n,i,j,Count=0;
    cin>>n;
    bool A[n][n];
    int R[n+1][n+1];
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cin>>A[i][j];
        }
    }

    for (i=0;i<=n;i++){
        R[0][i] = 0;
        R[i][0] = 0;
    }

    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            R[i][j] = A[i-1][j-1]?min(min(R[i-1][j-1],R[i-1][j]),R[i][j-1])+1:0;
            Count = max(Count,R[i][j]);
        }
    }
    cout<<Count<<endl;
    return 0;
}
