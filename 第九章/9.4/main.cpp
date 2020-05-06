#include <iostream>

/**
目前仅能处理字符串中都是字母的情况
扩展仅需shift数组增大范围即可
*/

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int i;
    int n = s1.size();
    int m = s2.size();

    int shift[52];
    for (i=0;i<52;i++){
        shift[i] = m;
    }
    for (i=0;i<m-1;i++){
        shift[s2.operator[](i) - 65] = m-i-1;
    }

    i = m-1;
    while (i<n){
        bool flag = true;
        for (int j=0;j<m;j++){
            if (s1.operator[](i-j) != s2.operator[](m-1-j)){
                flag = false;
                break;
            }
        }
        if (flag){
            cout<<i-m+2<<endl;
        }

        //转移
        i += shift[s1.operator[](i) - 65];
    }
    return 0;
}
