#include <iostream>
#define N 10
#define INFINITY 1000000000
using namespace std;

//T(n) = 2T(n/2) + 2
//T(n) = 1.5n - 2
//参数:数组，头下标，尾下标
struct Mm MinMax(int a[],int i,int j);

struct Mm
{
    int Max;
    int Min;
};
int main()
{
    struct Mm result;
    //例子
    int a[N]={5,-1,16,2,11,5,9,1};
    result = MinMax(a,0,N-1);
    cout<<result.Max<<" "<<result.Min<<endl;
    return 0;
}

struct Mm MinMax(int a[],int i,int j)
{
    //基本情况
    if (j == i) //0次
    {
        struct Mm temp = {a[i],a[i]};
        return temp;
    }
    else if (j-i == 1)  //1次
    {
        int tempMax = a[j]>a[i]?a[j]:a[i];
        struct Mm temp = {tempMax,a[i]+a[j]-tempMax};
        return temp;
    }
    //递归情况
    else
    {
        //划分阶段O(1)
        int k = (i+j) / 2;

        struct Mm temp1;
        struct Mm temp2;
        //解决阶段,2T(n/2)
        temp1=MinMax(a,i,k);
        temp2=MinMax(a,k+1,j);

        //合并阶段,2次比较
        if (temp2.Max > temp1.Max)
        {
            temp1.Max = temp2.Max;
        }
        if (temp2.Min < temp1.Min)
        {
            temp1.Min = temp2.Min;
        }
        return temp1;
    }
}
