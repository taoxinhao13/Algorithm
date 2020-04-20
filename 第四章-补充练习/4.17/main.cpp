#include <iostream>
#define N 5
using namespace std;

/**
采用邻接矩阵和固定图的大小只是为了代码简单
邻接表可以大大增加速度,为O(N^2),而邻接矩阵则为0(n^3)
输入要保证为树
*/

int G[N][N];
int visit[N];

int FindMax(int n){
    visit[n] = 1;
    int Max = 0;
    for (int i=0;i<N;i++){
        if (G[n][i]!=0&&!visit[i]){
            Max += max(0,FindMax(i)+G[n][i]);
        }
    }
    return Max;
}
int main()
{
    int x,y,w,i,j,Max=0;
    for (i=0;i<N-1;i++){
        cin>>x>>y>>w;
        G[x-1][y-1] = w;
        G[y-1][x-1] = w;
    }

    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            visit[j]=0;
        }
        Max = max(Max,FindMax(i));
    }
    cout<<Max;
    return 0;
}
