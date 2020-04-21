#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
输入要保证有解
时间复杂度O(nlgn)，空间复杂度O(1)
*/
struct node{
    int left;
    int right;
};

bool cmp_left(const node &a,const node &b){
    return a.left<b.left || (a.left==b.left&&a.right>b.right);
}
int main()
{
    int i,n,temp,result=1;
    unsigned j;
    cin>>n;
    node A[n];
    for (i=0;i<n;i++){
        cin>>A[i].left>>A[i].right;
    }

    sort(A,A+n,cmp_left);
    vector<node> B;
    B.push_back(A[0]);
    for (i=1;i<n;i++){
        if (A[i].left!=A[i-1].left){
            B.push_back(A[i]);
        }
    }
    temp=B.at(0).right;
    for (j=1;j<B.size()-1;j++){
        if (B.at(j).left<=temp && B.at(j+1).left>temp){
            temp = B.at(j).right;
            result++;
            if (temp==n){
                break;
            }
        }
    }
    if (temp!=n){  //选择最后一个
        result++;
    }
    cout<<result;
    return 0;
}
