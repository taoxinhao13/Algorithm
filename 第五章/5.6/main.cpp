#include <iostream>
#include <algorithm>
using namespace std;

/**
时间复杂度O(nlgn) (用来排序)
空间复杂度O(1)
*/

struct Order{
    int num;
    int need;
    int time;
};

bool cmp_need(const Order &a,const Order &b){
    return (a.need<b.need) || (a.need==b.need&&a.time>b.time);
}
int main()
{
    int i,n,temp=0;
    cin>>n;
    Order A[n];
    for (i=0;i<n;i++){
        A[i].num=i+1;
        cin>>A[i].need>>A[i].time;
    }
    sort(A,A+n,cmp_need);
    for (i=0;i<n;i++){
        if (temp+A[i].need<=A[i].time){
            cout<<A[i].num<<" ";
            temp+=A[i].need;
        }
    }

    return 0;
}
