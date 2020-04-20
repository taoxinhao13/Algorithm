#include <iostream>
#include <algorithm>

using namespace std;

/**
先输入n，再输入n组数，每组数第一个数代表截止时间，第二个数代表罚金，必须都是正整数
时间复杂度O(n^2)
*/
struct Event{
    int num;
    int time;
    int cost;
    int choose;
};

bool cmp_cost(const Event &a,const Event &b){
    return a.cost>b.cost;
}

bool cmp_time(const Event &a,const Event &b){
    return (a.choose>b.choose) || (a.choose==b.choose&&a.time<b.time);
}

bool Judge(int B[],int n){
    int i;
    for (i=0;i<n;i++){
        if (B[i]>i){
            return false;
        }
    }
    return true;
}

int main()
{
    int n,i,j;
    cin>>n;
    Event A[n];
    for (i=0;i<n;i++){
        A[i].num=i+1;
        cin>>A[i].time>>A[i].cost;
        A[i].choose=0;
    }

    //先按照代价进行排序
    sort(A,A+n,cmp_cost);

    int B[n]={0}; //用于选择最优解

    for (i=0;i<n;i++){
        if (Judge(B,A[i].time)){
            A[i].choose=1;
            if (A[i].time<=n){
                for (j=n-1;j>=A[i].time-1;j--){
                    B[j]++;
                }
            }
        }
    }

    //最后按照输出顺序排序
    sort(A,A+n,cmp_time);
    for (i=0;i<n;i++){
        cout<<A[i].num<<" ";
    }
    return 0;
}
