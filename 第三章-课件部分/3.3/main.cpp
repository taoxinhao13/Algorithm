#include <iostream>
#define N 32
using namespace std;

/*
32*32位整数的分治算法,该溢出溢出
T(n)=3T(n/2)+O(n)=O(n^1.59)
*/
int Mul(int X,int Y,int n)
{
    //基本情况
    if (n==1)
    {
        return X*Y;
    }
    //递归情况
    else
    {
        //划分阶段O(1)
        int A = X>>(n/2);
        int B = ((unsigned)X<<(32-n/2))>>(32-n/2);
        int C = Y>>(n/2);
        int D = ((unsigned)Y<<(32-n/2))>>(32-n/2);
        int E = A-B;
        int F = C-D;
        int AC,BD,EF;

        //解决阶段,3T(n/2)
        AC = Mul(A,C,n/2);
        BD = Mul(B,D,n/2);
        EF = Mul(E,F,n/2);

        //合并阶段O(n)
        return (AC<<n) + ((AC+BD-EF)<<(n/2)) + BD;
    }
}

int main()
{
    int X = 111;
    int Y = 31;
    int result;
    result = Mul(X,Y,N);
    cout<<result<<endl;
    return 0;
}
