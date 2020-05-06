#include <iostream>
#define BigPrime 122777
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size(),i;
    int F[m]={0};

    ComputePrefix(F,s2,m);

    int f2=0; //模式串的哈希值
    int f1=0; //目标串当前m位子串的哈希值
    int c = 1; //m位k进制数100000(共m位)的哈希值
    //ASCII码范围从0x30的0到0x7A的小写字母z,因此是75进制

    //预处理
    for (i=0;i<m-1;i++){
        f1 = (75 * f1 + s1.operator[](i) - 48) % BigPrime;
        f2 = (75 * f2 + s2.operator[](i) - 48) % BigPrime;
        c = 75 * c % BigPrime;
    }
    f1 = (75 * f1 + s1.operator[](i) - 48) % BigPrime;
    f2 = (75 * f2 + s2.operator[](i) - 48) % BigPrime;

    for (i=0;i<n-m;i++){
        //哈希值相同则进行每位的比较
        if (f1 == f2){
            bool flag = true;
            for (int j=0;j<m;j++){
                if (s1.operator[](i+j)!=s2.operator[](j)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout<<i+1<<endl;
            }
        }
        //更新哈希值
        f1 = f1 - (c * ((s1.operator[](i) - 48) % BigPrime));
        f1 = (75 * f1 + s1.operator[](i+m) - 48) % BigPrime;
        f1 = (f1 + BigPrime) % BigPrime;
    }
    if (f1 == f2){
        bool flag = true;
        for (int j=0;j<m;j++){
            if (s1.operator[](i+j)!=s2.operator[](j)){
                flag = false;
                break;
            }
        }
        if (flag){
            cout<<i+1<<endl;
        }
    }

    return 0;
}
