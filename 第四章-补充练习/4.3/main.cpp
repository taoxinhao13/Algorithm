#include <iostream>

using namespace std;

/**
全是0则坐标输出(0,0),第一个元素为(1,1)
*/
int main()
{
    int n,i,j,k,x=-1,y=-1,Count=0;
    cin>>n;
    bool A[n][n];
    int R[n][n];
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cin>>A[i][j];
            R[i][j] = A[i][j];
        }
    }
    for (k=2;k<=n;k++){
        for (i=0;i<n-k+1;i++){
            for (j=0;j<n-k+1;j++){
                if (R[i][j] == k-1 && R[i+1][j] == k-1 && R[i][j+1] == k-1 && R[i+1][j+1] == k-1){
                    R[i][j]=k;
                    Count = k;
                    x = i;
                    y = j;
                }
            }
        }
    }
    cout<<"The size is:"<<Count<<"*"<<Count<<endl;
    cout<<"The start position is:("<<x+1<<","<<y+1<<")";
    return 0;
}
