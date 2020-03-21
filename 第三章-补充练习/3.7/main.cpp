#include <iostream>
#include <algorithm>
#include <math.h>
#define INFINITY 1000000000
using namespace std;
/*
平面最小三角形
与最邻近点对类似，采用分治法，共线的三点不能构成三角形
时间复杂度O(nlgn)
*/
struct node{
    int x;
    int y;
};
bool comparex(const node &a,const node &b)
{
    if (a.x == b.x)
    {
        return a.y<=b.y;
    }
    else
    {
        return a.x<b.x;
    }
}
bool comparey(const node &a,const node &b)
{
    if (a.y == b.y)
    {
        return a.x<=b.x;
    }
    else
    {
        return a.y<b.y;
    }
}
bool Judge(node a,node b,node c)
{
    if (a.x*b.y+b.x*c.y+c.x*a.y-a.x*c.y-b.x*a.y-c.x*b.y == 0){
        return false;
    }
    return true;
}
double CalculateThreePoints(node a,node b,node c)
{
    return pow(pow(b.x-a.x,2)+pow(b.y-a.y,2),0.5)+pow(pow(c.x-a.x,2)+pow(c.y-a.y,2),0.5)+pow(pow(b.x-c.x,2)+pow(b.y-c.y,2),0.5);
}
double MinTriangle(node A[],node B[],int n)
{
    if (n==2){
        return INFINITY;
    }
    if (n==3){
        if (Judge(A[0],A[1],A[2]))
            return CalculateThreePoints(A[0],A[1],A[2]);
        return INFINITY;
    }
    node median= A[(n-1)/2];
    int i,I=0,j=0,k=0;
    //划分依然卡在线上
    node Aleft[(n+1)/2],Bleft[(n+1)/2];
    node Aright[n/2],Bright[n/2];
    node Mid1[n],Mid2[n];
    for (i=0;i<(n+1)/2;i++)
        Aleft[i] = A[i];
    for (;i<n;i++)
        Aright[i-(n+1)/2] = A[i];
    for (i=0;i<n;i++){
        if (comparex(median,B[i])){
            Bright[j++] = B[i];
        }
        else
            Bleft[k++] = B[i];
    }
    //解决阶段
    double d1 = MinTriangle(Aleft,Bleft,(n+1)/2);
    double d2 = MinTriangle(Aright,Bright,n/2);
    //合并阶段
    double d = min(d1,d2);
    for (i=0;i<n;i++){
        if (B[i].x<=median.x && B[i].x > median.x-d/2)
                Mid1[j++] = B[i];
        else if (B[i].x>median.x && B[i].x <= median.x+d/2)
                Mid2[k++] = B[i];
    }
    //左面一个点，右面两个点
    for (i=0;i<j;i++){
        while (Mid1[i].y<Mid2[I].y-d/2){
            I++;
        }
        if (Mid1[i].y<Mid2[I].y+d/2){
            int temp = I;
            node Temp1[k];
            int Count = 0;
            while (Mid1[i].y<Mid2[I].y+d/2 && Mid1[i].y>Mid2[I].y-d/2){
                Temp1[Count++] = Mid2[I++];
            }
            //Count最大为16，为常数时间暴力搜索
            for (int i1=0;i1<Count-1;i1++){
                for (int i2=i1+1;i2<Count;i2++){
                    if (Judge(Mid1[i],Temp1[i1],Temp1[i2]))
                        d = min(d,CalculateThreePoints(Mid1[i],Temp1[i1],Temp1[i2]));
                }
            }
            //回溯
            I = temp;
        }
    }
    //左面两个点，右面一个点
    for (i=0;i<k;i++){
        while (Mid2[i].y<Mid1[I].y-d/2){
            I++;
        }
        if (Mid2[i].y<Mid1[I].y+d/2){
            int temp = I;
            node Temp2[j];
            int Count = 0;
            while (Mid2[i].y<Mid1[I].y+d/2 && Mid2[i].y>Mid1[I].y-d/2){
                Temp2[Count++] = Mid2[I++];
            }
            //Count最大为16，为常数时间暴力搜索
            for (int i1=0;i1<Count-1;i1++){
                for (int i2=i1+1;i2<Count;i2++){
                    if (Judge(Mid1[i],Temp2[i1],Temp2[i2]))
                        d = min(d,CalculateThreePoints(Mid2[i],Temp2[i1],Temp2[i2]));
                }
            }
            //回溯
            I = temp;
        }
    }
    return d;
}
int main()
{
    int n,i;
    double result;
    cin>>n;
    node A[n],B[n];
    for (i=0;i<n;i++){
        cin>>A[i].x>>A[i].y;
        B[i] = A[i];
    }
    sort(A,A+n,comparex);
    sort(B,B+n,comparey);
    result = MinTriangle(A,B,n);
    cout<<result;
    return 0;
}
