#include <iostream>
#include <stdlib.h>

using namespace std;
/*两个有序数组中找到综合中位数
二分法，复杂度O(lgn)
*/
int main()
{
    int i,n;
    cin>>n;
    int Aleft=0,Aright=n-1,Bleft=0,Bright=n-1,Amid,Bmid;
    float A[n],B[n];
    for (i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for (i=0;i<n;i++)
    {
        cin>>B[i];
    }
    while (Aright-Aleft>1)
    {
        Amid = (Aright+Aleft)/2;
        Bmid = (Bright+Bleft)/2;
        //奇数
        if ((Aright-Aleft)%2==0)
        {
            if (A[Amid]==B[Bmid])
            {
                cout<<(A[Amid]+B[Bmid])/2.0;
                exit(0);
            }
            else if (A[Amid]>B[Bmid])
            {
                Aright = Amid;
                Bleft = Bmid;
            }
            else
            {
                Aleft = Amid;
                Bright = Bmid;
            }
        }
        else
        {
            if (A[Amid]==B[Bmid])
            {
                Aleft = Amid;
                Bleft = Bmid;
                Aright = Amid+1;
                Bright = Bmid+1;
            }
            else if (A[Amid]>B[Bmid])
            {
                Aright = Amid+1;
                Bleft = Bmid;
            }
            else
            {
                Aleft = Amid;
                Bright = Bmid+1;
            }
        }
    }
    if (A[Aleft]<=B[Bleft])
    {
        cout<<(B[Bleft]+(A[Aright]>=B[Bright]?B[Bright]:A[Aright]))/2.0;
    }
    else
    {
        cout<<(A[Aleft]+(A[Aright]>=B[Bright]?B[Bright]:A[Aright]))/2.0;
    }
    return 0;
}
