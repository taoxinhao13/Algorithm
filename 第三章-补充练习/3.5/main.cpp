#include <stdio.h>
#include <stdlib.h>
long sum=0;
void Merge(int a[],int m,int s,int n,int b[])
{
    int i,p0=0,p1=m,p2=s+1;
    while (p1<=s &&p2<=n)
    {
        if (a[p1]<=a[p2])
        {
            b[p0++]=a[p1++];
        }
        else
        {
            sum+=s+1-p1;
            b[p0++]=a[p2++];
        }
    }
    while (p1<=s)
    {
        b[p0++]=a[p1++];
    }
    while (p2<=n)
    {
        b[p0++]=a[p2++];
    }
    for (i=0;i<=n-m;i++)
    {
        a[m+i]=b[i];
    }
}
void Mergesort(int a[],int m,int n,int b[])
{
    int s;
    if (m<n)
    {
        s=(m+n)/2;
        Mergesort(a,m,s,b);
        Mergesort(a,s+1,n,b);
        Merge(a,m,s,n,b);
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Mergesort(a,0,n-1,b);
    printf("%ld",sum);
    return 0;
}

