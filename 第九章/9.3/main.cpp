#include <iostream>
#include <string>
using namespace std;

/**
全部采用洛谷P3375的格式来进行字符串匹配
*/

void ComputePrefix(int F[],string s2,int length){
    int k = 0;
    for (int i=1;i<length;i++){
        while (k>0 && s2.operator[](k)!=s2.operator[](i)){
            k = F[k-1];
        }
        if (s2.operator[](k) == s2.operator[](i)){
            k = k + 1;
        }
        F[i] = k;
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size(),i,j;
    int F[m]={0};

    ComputePrefix(F,s2,m);

    j = 0;
    for (i=0;i<n;i++){
        while (j>0 && s1.operator[](i)!=s2.operator[](j)){
            j = F[j-1];
        }
        if (s1.operator[](i) == s2.operator[](j)){
            j = j + 1;
        }
        if (j == m){
            cout<<i-m+2<<endl;
            j = F[j-1];
        }
    }
    //KMP算法的前缀函数的输出,仅仅是因为题目要求
    for (i=0;i<m-1;i++){
        cout<<F[i]<<" ";
    }
    cout<<F[i];
    return 0;
}
