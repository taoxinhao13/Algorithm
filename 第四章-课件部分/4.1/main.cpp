#include <iostream>
#include <stdio.h>
using namespace std;
/**
最长公共子序列
求出该序列对应的内容，本题以字符序列举例
两个数组长度分别是n和m
dp算法，正确性证明略，时间复杂度和空间复杂度都是0(mn)
*/

void PrintTrace(char A[],int** position,int m,int n,int N){
    if (m<=0 || n<=0){
        return;
    }
    if (*((int *)position +(m-1)*N + (n-1)) == 1){
        PrintTrace(A,(int**)position,m-1,n-1,N);
        cout<<A[m-1];
    }
    else if (*((int *)position +(m-1)*N + (n-1)) == 2){
        PrintTrace(A,(int**)position,m-1,n,N);
    }
    else{
        PrintTrace(A,(int**)position,m,n-1,N);
    }
}

int main()
{
    int i,j,n,m;
    cin>>m>>n;
    char A[m],B[n];
    int length[m+1][n+1];
    int position[m][n];
    for (i=0;i<m;i++){
        cin>>A[i];
    }
    for (i=0;i<n;i++){
        cin>>B[i];
    }

    for (i=0;i<n+1;i++){
        length[0][i] = 0;
    }
    for (i=0;i<m+1;i++){
        length[i][0] = 0;
    }

    for (i=1;i<m+1;i++){
        for (j=1;j<n+1;j++){
            if (A[i-1] == B[j-1]){
                length[i][j] = length[i-1][j-1]+1;
                position[i-1][j-1] = 1;
            }
            else{
                length[i][j] = max(length[i-1][j],length[i][j-1]);
                if (length[i][j] == length[i-1][j]){
                    position[i-1][j-1] = 2;
                }
                else{
                    position[i-1][j-1] = 3;
                }
            }
        }
    }
    PrintTrace(A,(int**)position,m,n,n);
    return 0;
}

