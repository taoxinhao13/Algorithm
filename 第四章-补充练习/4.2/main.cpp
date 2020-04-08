#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/**
输入要求必须按x和y的大小排好序
输出为最短距离
时间与空间复杂度都是O(n^2)
*/
struct Node{
    int x;
    int y;
};
double dis(Node a,Node b){
    return pow((double)pow(a.x-b.x,2)+(double)pow(a.y-b.y,2),0.5);
}
int main()
{
    int n,i,j;
    cin>>n;
    Node position[n];
    for (i=0;i<n;i++){
        cin>>position[i].x>>position[i].y;
    }

    //D[i][j]:，i->0->j;i>=j,无重复边的最优解
    double D[n][n];
    D[0][0] = 0;
    for (i=1;i<n;i++){
        for (j=0;j<=i;j++){
            if (j == i){
                D[i][j] = D[i][j-1] + dis(position[j-1],position[j]);
            }
            else if (j == i-1){
                if (j == 0){
                    D[i][j] = dis(position[0],position[1]);
                    continue;
                }
                D[i][j] = INFINITY;
                for (int k=0;k<j;k++){
                    D[i][j] = min(D[i][j],D[j][k]+dis(position[k],position[i]));
                }
            }
            else{
                D[i][j] = D[i-1][j] + dis(position[i-1],position[i]);
            }
        }
    }
    printf("%.2f",D[n-1][n-1]);
    return 0;
}
