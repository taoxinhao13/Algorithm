#include <iostream>
#include <math.h>
using namespace std;
/**
输出最优解的代价以及聚类方案
例:若输出38 1->2 3->5 6则代表总代价为38，将前两个分为一类，中间三个分为一类，最后一个一类

*/
int main()
{
    int n,i,j,k,K;
    cin>>n>>K;
    double A[n];
    double R[n][n];
    double D[n][n];  //记录最后一堆起始点
    for (i=0;i<n;i++){
        cin>>A[i];
    }

    for (i=0;i<n;i++){
        R[i][i] = 0;
        D[i][i] = -1;
    }

    for (i=1;i<n;i++){
        R[i][0] = pow(A[i] - A[0],2);
        D[i][0] = -1;
        for (j=1;j<i;j++){
            R[i][j] = INFINITY;
            for (k=j-1;k<i;k++){
                if (R[k][j-1] + pow(A[i] - A[k+1],2) < R[i][j]){
                    R[i][j] = R[k][j-1] + pow(A[i] - A[k+1],2);
                    D[i][j] = k;
                }
            }
        }
    }

    cout<<R[n-1][K-1]<<endl;

    int x = n-1;
    int y = K-1;
    while (y>=0){
        if (x == D[x][y]+1){
            cout<<x+1<<endl;
        }
        else{
            cout<<D[x][y]+2<<"->"<<x+1<<endl;
        }
        x = D[x][y];
        y -= 1;
    }
    return 0;
}
