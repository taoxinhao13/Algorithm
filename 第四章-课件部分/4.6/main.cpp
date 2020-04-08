#include <iostream>

using namespace std;

/**
计算两个字符串的编辑距离
两个字符串的长度分别是m,n
只输出编辑距离的值
动态规划算法
时间复杂度和空间的复杂度都是0(mn)
*/


int main()
{
    int m,n,i,j;
    cin>>m>>n;
    char str1[m],str2[n];

    //D[i][j]:第一个字符串的前i个字符与第二个字符串的前j个字符的编辑距离
    int D[m+1][n+1];
    for (i=0;i<m;i++){
        cin>>str1[i];
    }
    for (i=0;i<n;i++){
        cin>>str2[i];
    }

    //初始化空字符串的情况
    for (i=0;i<n+1;i++){
        D[0][i] = i;
    }
    for (i=0;i<m+1;i++){
        D[i][0] = i;
    }

    for (i=1;i<m+1;i++){
        for (j=1;j<n+1;j++){
            D[i][j] = min(min(D[i-1][j]+1,D[i][j-1]+1),D[i-1][j-1] + (str1[i]==str2[i]?0:1));
        }
    }

    cout<<D[m][n];
    return 0;
}
