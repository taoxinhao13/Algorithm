#include <iostream>
#include <math.h>
using namespace std;
/**
凸多边形的三角划分,坐标以double类型举例
目标为划分用的直线的总长度最短，输出总长度
输入请按照逆时针排列，否则请先调用凸包算法
动态规划算法
时间复杂度O(n^3),空间复杂度O(n^2)
*/

class node{
public: double x;
        double y;
        bool equals(node a){
            return ((fabs(this->x-a.x)<0.00001) && (fabs(this->y-a.y)<0.00001));
        }
        double distance(node a){
            return pow(pow((this->x-a.x),2) +  pow((this->y-a.y),2),0.5);
        }
};

double Cost(node a,node b,node c){
    if (a.equals(b) || a.equals(b) || b.equals(c)){
        return 0;
    }
    return a.distance(b)+b.distance(c)+c.distance(a);
}
int main()
{
    int i,j,k,n;
    cin>>n;
    node A[n];
    /*
    cost[i][j]:第i个点到第j个点构成的多边形中，切割后三角形总周长的最小代价
    cost[0][n-1]的值就是多边形总周长+2*切割边总长度
    因此与原问题同解
    */
    double cost[n][n];
    for (i=0;i<n;i++){
        cin>>A[i].x>>A[i].y;
        cost[i][i] = 0;
    }

    //两个点构不成三角形
    for (i=0;i<n-1;i++){
        cost[i][i+1] = 0;
    }

    for (i=2;i<n;i++){
        for (j=0;j<n-i;j++){
            cost[j][j+i] = INFINITY;
            for (k=j+1;k<j+i;k++){
                cost[j][j+i] = min(cost[j][j+i],cost[j][k]+cost[k][j+i]+Cost(A[j],A[k],A[j+i]));
            }
        }
    }

    //转化为最终结果
    for (i=0;i<n-1;i++){
        cost[0][n-1] -= A[i].distance(A[i+1]);
    }
    cost[0][n-1] -= A[n-1].distance(A[0]);
    cout<< cost[0][n-1] / 2.0;
    return 0;
}
