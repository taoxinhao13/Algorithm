#include <iostream>

using namespace std;
/* 严格增序排列的数组循环右移k位，k未知
T(n) = T(n/2) + O(1)
T(n) = O(logn)
*/

int FindMax(int A[],int left,int right){
    //基本情况
    if (right == left){
        return A[left];
    }
    //递归情况
    int mid = (left + right) / 2 + 1;
    //分治
    if (A[left] < A[mid]){
        return FindMax(A,mid,right);
    }
    else{
        return FindMax(A,left,mid-1);
    }
}
int main()
{
    int n,i;
    cin>>n;
    int A[n];
    for (i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<FindMax(A,0,n-1);
    return 0;
}
