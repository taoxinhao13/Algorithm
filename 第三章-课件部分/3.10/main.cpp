#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <math.h>
using namespace std;

/*
平面最小覆盖圆
洛谷P1742
期望时间为O(n)
*/
struct Point{
    double x;
    double y;
};
struct Circle{
    double x;
    double y;
    double r;
};
bool IsIncircle(Circle a,Point b)
{
    return pow((b.x-a.x),2)+pow((b.y-a.y),2)<=pow(a.r,2);
}
//三点定圆
Circle ComputeCircle(Point p1,Point p2,Point p3)
{
    Circle result;
    double a = p1.x-p2.x;
    double b = p1.y-p2.y;
    double c = p1.x-p3.x;
    double d = p1.y-p3.y;
    double e = (pow(p1.x,2)+pow(p1.y,2)-pow(p2.x,2)-pow(p2.y,2))/2;
    double f = (pow(p1.x,2)+pow(p1.y,2)-pow(p3.x,2)-pow(p3.y,2))/2;
    result.x = -(d*e-b*f)/(b*c-a*d);
    result.y = -(a*f-c*e)/(b*c-a*d);
    result.r = pow(pow(result.x-p1.x,2)+pow(result.y-p2.y,2),0.5);
    return result;
}
int main()
{
    srand(time(NULL));
    int n,i,j,k;
    cin>>n;
    Point point[n];
    Circle result;
    for (i=0;i<n;i++)
    {
        cin>>point[i].x>>point[i].y;
    }
    //线性打乱，使得复杂度为期望时间
    for (i=0;i<n-1;i++)
    {
        swap(point[i],point[i+rand()%(n-i)]);
    }
    result = ComputeCircle(point[0],point[1],point[2]);

    for (i=3;i<n;i++)
    {
        if (!IsIncircle(result,point[i]))
        {
            result.x=point[i].x;
            result.y=point[i].y;
            result.r=0;
            for (j=0;j<i;j++)
            {
                if (!IsIncircle(result,point[j]))
                {
                    result.x = (point[i].x+point[j].x)/2;
                    result.y = (point[i].y+point[j].y)/2;
                    result.r = pow(pow(result.x-point[i].x,2)+pow(result.y-point[i].y,2),0.5);
                    for (k=0;k<j;k++)
                    {
                        if (!IsIncircle(result,point[k]))
                        {
                            result = ComputeCircle(point[i],point[j],point[k]);
                        }
                    }
                }
            }
        }
    }
    printf("%.10lf\n%.10lf %.10lf\n",result.r,result.x,result.y);
    return 0;
}
