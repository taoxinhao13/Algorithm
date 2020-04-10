#include <iostream>
#define LEFT 0
#define UP 1
using namespace std;
/**
时间空间复杂度都是O(n^2)
*/

void Print(int P[],int x,int y,int m){
    if (x==1 && y==1){
        return;
    }
    else if (x==1){
        Print(P,x,y-1,m);
        cout<<"-->("<<x<<","<<y<<")";
    }
    else if (y==1){
        Print(P,x-1,y,m);
        cout<<"-->("<<x<<","<<y<<")";
    }
    else{
        if (P[(x-1)*m+y-1] == UP){
            Print(P,x-1,y,m);
            cout<<"-->("<<x<<","<<y<<")";
        }
        else{
            Print(P,x,y-1,m);
            cout<<"-->("<<x<<","<<y<<")";
        }
    }
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int A[n][m];
    int R[n][m];
    int P[n*m]; //记录路径,一维数组便于传参,二维数组看着更舒服
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    R[0][0] = A[0][0];
    for (i=1;i<m;i++){
        R[0][i] = R[0][i-1] + A[0][i];
    }
    for (i=1;i<n;i++){
        R[i][0] = R[i-1][0] + A[i][0];
    }
    for (i=1;i<n;i++){
        for (j=1;j<m;j++){
            if (R[i-1][j] > R[i][j-1]){
                R[i][j] = R[i-1][j]+A[i][j];
                P[i*m+j] = UP;
            }
            else{
                R[i][j] = R[i][j-1]+A[i][j];
                P[i*m+j] = LEFT;
            }
        }
    }
    cout<<R[n-1][m-1]<<endl;
    cout<<"(1,1)";
    Print(P,n,m,m);

    return 0;
}
