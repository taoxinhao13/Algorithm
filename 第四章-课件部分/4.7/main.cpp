#include <iostream>
#include <stdio.h>
#define INFINITY 10000000
using namespace std;

/**
最优二叉搜索树问题
请输入严格递增的n个数的序列，之后2n+1个的权值要求和为1，前n个为值的权值，后n+1个为区间的权值
输出为最优二叉搜索树的中序遍历表示，如(2(4))表示2为根，4为2的右儿子
*/

void BuildTree(int A[],int left,int right,int** R){
    if (right<left){
        return;
    }
    else if (left==right){
        cout<<"["<<A[left]<<"]";
    }
    else{
        cout<<"[";
        BuildTree(A,left,R[left][right+1]-1,R);
        cout<<A[R[left][right+1]];
        BuildTree(A,R[left][right+1]+1,right,R);
        cout<<"]";
    }
}
int main()
{
    int n,i,j,k;
    cin>>n;
    int A[n];  //按大小顺序输入的值
    double node[n];  //成功节点权重
    double leaf[n+1];  //失败节点权重

    //W[i][j]:从第i号到第j-1号的所有点以及其叶节点的总权值
    double W[n+1][n+1];

    //W[i][j]:从第i号到第j-1号的所有点以及其叶节点的最小期望值(最优解)
    double E[n+1][n+1];

    //W[i][j]:从第i号到第j-1号的所有点以及其叶节点的最小期望值情况下，根节点的下标
    int R[n+1][n+1];

    for (i=0;i<n;i++){
        cin>>A[i];
    }
    for (i=0;i<n;i++){
        cin>>node[i];
    }
    for (i=0;i<=n;i++){
        cin>>leaf[i];
    }

    //处理只有叶节点(虚节点/查找失败点)的情况
    for (i=0;i<=n;i++){
        W[i][i] = leaf[i];
        E[i][i] = leaf[i];
        R[i][i] = -1;
    }

    for (i=1;i<=n;i++){
        for (j=0;j<=n-i;j++){
            W[j][j+i] = W[j][j+i-1] + leaf[j+i] + node[j+i-1];
            E[j][j+i] = INFINITY;
            for (k=j;k<j+i;k++){
                if (E[j][j+i]>E[j][k] + E[k+1][j+i] + W[j][j+i]){
                    E[j][j+i] = E[j][k] + E[k+1][j+i] + W[j][j+i];
                    R[j][j+i] = k;
                }
            }
        }
    }

    int* support[n+1];
    for (i=0;i<n+1;i++){
        support[i] = R[i];
    }
    BuildTree(A,0,n-1,support);
    return 0;
}
