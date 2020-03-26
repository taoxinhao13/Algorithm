#include <iostream>

using namespace std;
/*
平面上有n个点，若A的横纵坐标都大于等于点B，则A支配B
求出所有不被支配的点
平均复杂度O(N)
*/
struct node{
    int x;
    int y;
};
int num;

void FindPoints(node A[],node result[],int n)
{
    //只有一个点直接返回
    if (n==1)
    {
        result[num++]=A[0];
        return;
    }
    //先找出横坐标最大元素
    int i,tempnum=0;
    node Max = A[0];
    for (i=1;i<n;i++)
    {
        if (A[i].x>Max.x || (A[i].x==Max.x && A[i].y>Max.y))
        {
            Max = A[i];
        }
    }
    result[num++]=Max;
    node B[n];
    //取出其他y大于该点的，才可能满足
    for (i=0;i<n;i++)
    {
        if (A[i].y>Max.y)
        {
            B[tempnum++] = A[i];
        }
    }
    //子问题
    FindPoints(B,result,tempnum);
}
int main()
{
    int i,n;
    cin>>n;
    node Points[n];
    node result[n];
    for (i=0;i<n;i++)
    {
        cin>>Points[i].x>>Points[i].y;
    }
    FindPoints(Points,result,n);
    for (i=0;i<num;i++)
    {
        cout<<result[i].x<<" "<<result[i].y<<endl;
    }
    return 0;
}
