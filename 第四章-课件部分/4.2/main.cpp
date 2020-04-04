#include <iostream>

using namespace std;
/**
最长递增子序列,以整数序列为例
输出为序列中元素的个数
动态规划算法
时间复杂度为O(nlgn)
*/
int FindPosition(int m,int dp[],int n){
    int left = 0;
    int right = n-1;
    while (right>left){
        int mid = (left + right) / 2;
        if (m < dp[mid]){
            right = mid;
        }
        else if (m > dp[mid]){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
    return left;
}

int main()
{
    int i,n;
    cin>>n;
    int A[n],Max=0;
    int result[n]; //result[i]:以第i个数结尾的最长序列中的元素个数
    int dp[n];    //dp[i]:个数为i的序列结尾的最小元素的值
    for (i=0;i<n;i++){
        cin>>A[i];
        result[i] = 0;
        dp[i] = 2147483647;
    }
    for (i=0;i<n;i++){
        int p = FindPosition(A[i],dp,n);
        result[i] = p+1;
        Max = max(Max,result[i]);
        dp[p] = A[i];
    }
    cout<<Max;
    return 0;
}
