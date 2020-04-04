#include <iostream>
using namespace std;
/**
矩阵链乘问题
输入请务必合法
动态规划算法
时间复杂度O(n^3)，空间复杂度O(n^2)
*/
struct Matrix{
    int row;
    int col;
};

int main()
{
    int i,j,k,n;
    cin>>n;
    Matrix A[n];
    for (i=0;i<n;i++){
        cin>>A[i].row>>A[i].col;
    }

    int DP[n][n];
    for (i=0;i<n;i++)
    {
        DP[i][i] = 0;
    }
    for (i=1;i<n;i++){
        for (j=0;j<n-i;j++){
            DP[j][j+i] = 2147483647;
            for (k=j;k<j+i;k++){
                DP[j][j+i] = min(DP[j][j+i],DP[j][k] + DP[k+1][j+i] + A[k].row*A[k].col*A[k+1].col);
            }
        }
    }
    cout<<DP[0][n-1];
    return 0;
}
