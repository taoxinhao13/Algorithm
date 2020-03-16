#include <iostream>
#include <complex>
#define PI acos(-1)
using namespace std;

/*
多项式乘法，FFT+IDFT，分治
分为求点值，进行点值乘法，插值三步
复杂度分别为O(nlgn),O(n),O(nlgn)
T(n)=O(nlgn)
格式为洛谷P3803
*/

void FFT(complex<double> A[],int n,int mode)
{
	//一般情况
    if (n==2)
    {
        complex<double> Temp1 = A[0];
        complex<double> Temp2 = A[1];
        A[0] = Temp1 + Temp2;
        A[1] = Temp1 - Temp2;
        return;
    }

    //递归情况
    //1.划分0(n)
    complex<double> temp1[n>>1],temp2[n>>1];
    complex<double> beta(cos(2*PI/n),mode*sin(2*PI/n));
    complex<double> e(1,0);
    int i;
    for (i=0;i<(n>>1);i++)
    {
        temp1[i] = A[i<<1];
        temp2[i] = A[(i<<1)+1];
    }

    //2.解决阶段2T(n/2)
    FFT(temp1,n>>1,mode);
    FFT(temp2,n>>1,mode);

    //3.合并阶段O(n)
    for (i=0;i<(n>>1);i++)
    {
        A[i]=temp1[i]+e*temp2[i];
        A[i+(n>>1)]=temp1[i]-e*temp2[i];
        e *= beta;
    }
    return;
}

int main()
{
    //1.读入并适当处理数据
    int n,m,i,temp,Max;
    cin>>n>>m;
    temp = (n>m?n:m);
    for (Max=1;Max<=temp;Max = (Max<<1));
    Max = Max<<1; //把Max补到2的k次幂,保证结果不会超过2^k-1阶
    complex<double> result[Max],a[Max],b[Max];
    for (i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=n+1;i<Max;i++)
    {
        a[i] = 0;
    }
    for (i=0;i<=m;i++)
    {
        cin>>b[i];
    }
    for (i=m+1;i<Max;i++)
    {
        b[i] = 0;
    }
    //2.FFT,求点值,O(nlgn)
    FFT(a,Max,1);
    FFT(b,Max,1);
    //3.点值乘法,O(n)
    for (i=0;i<Max;i++)
    {
        result[i] = a[i] * b[i];
    }

    //4.IDFT,插值,O(nlgn)
    FFT(result,Max,-1);

    for (i=0;i<n+m;i++)
    {
        cout<<(int)(result[i].real()+0.5) / Max<<" ";
    }
    cout<<(int)(result[i].real()+0.5) / Max;
    return 0;
}
