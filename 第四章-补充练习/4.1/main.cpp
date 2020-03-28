#include <stdio.h>
#include <iostream>
#define MAX 101
using namespace std;
/**
数字三角形问题，dp算法
时间复杂度O(n^2),空间复杂度O(n)
*/
int main()
{
    int i,j,n;
    cin>>n;
    int digit[n][n];
    int maxsum[n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<=i;j++)
        {
            cin>>digit[i][j];
        }
    }
    for (i=0;i<n;i++){
        maxsum[i] = digit[n-1][i];
    }
    for (i=n-2;i>=0;i--)
    {
        for (j=0;j<=i;j++)
        {
            maxsum[j]=max(maxsum[j],maxsum[j+1])+digit[i][j]; //递推方程，从最后一行往前递推
        }
    }
    printf("%d",maxsum[0]);
    return 0;
}
