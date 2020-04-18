#include <iostream>

using namespace std;

/**
时间复杂度O(nlgn),空间复杂度O(n)
*/
BinarySearch(int target,int End[],int n){
    int left = 0;
    int right = n-1;
    int mid = left;
    while (left<right){
        mid = (left + right) / 2;
        if (End[mid]>target){
            right = mid - 1;
        }
        else if (End[mid]<target){
            left = mid + 1;
        }
        else{
            return mid+1;
        }
    }
    if (End[left]<=target){
        return left+1;
    }
    else{
        return left;
    }
}
int main()
{
    int n,i;
    cin>>n;
    int Start[n];
    int End[n];
    int Weight[n];

    for (i=0;i<n;i++){
        cin>>Start[i]>>End[i]>>Weight[i];
    }

    int result[n+1];
    result[0] = 0;
    result[1] = Weight[0];

    for (i=2;i<=n;i++){
        result[i] = max(result[i-1],result[BinarySearch(Start[i-1],End,i-1)]+Weight[i-1]);
    }

    cout<<result[n];
    return 0;
}
