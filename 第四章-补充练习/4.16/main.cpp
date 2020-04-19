#include <iostream>
#include <cmath>
using namespace std;

/**
时间复杂度O(n^2),空间复杂度O(n)
*/

void Print(double A[],int pre[],int n){
    if (pre[n]==-1){
        cout<<A[n]<<" ";
    }
    else{
        Print(A,pre,pre[n]);
        cout<<A[n]<<" ";
    }
}

int main()
{
    int n,f,i,j,Max_pos=0;
    cin>>n>>f;
    double A[n];
    for (i=0;i<n;i++){
        cin>>A[i];
    }
    int pre[n];  //pre[i]:以节点i结尾的最优子序列的前驱下标
    int R[n]={0}; //R[i]:以节点i结尾的最优子序列的长度

    pre[0] = -1;
    R[0] = 1;
    for (i=1;i<n;i++){
        for (j=i-1;j>=0;j--){
            if (fabs(A[i]-A[j])<=f){
                if (R[i]<R[j]+1){
                    R[i] = R[j]+1;
                    pre[i] = j;
                }
            }
        }
    }
    for (i=0;i<n;i++){
        if (R[i]>R[Max_pos]){
            Max_pos = i;
        }
    }
    cout<<R[Max_pos]<<endl;
    Print(A,pre,Max_pos);
    return 0;
}
