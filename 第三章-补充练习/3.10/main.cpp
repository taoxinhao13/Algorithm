#include <iostream>
#include <math.h>
#define PI acos(-1)
using namespace std;
/*判断给出的n个点是不是在m边形中
并不需要分治算法,不考虑精度问题,边界不算在里面
复杂度O(nlgm)，每个点都是lgm
*/
struct node{
    double x;
    double y;
};
double Atan2(double y,double x){
    if (y>=0){
        return atan2(y,x);
    }
    else
        return atan2(y,x)+2*PI;
}
int main()
{
    int m,n,i;
    cin>>m>>n;
    node A[m];
    double D[m];
    node B[n];
    //逆时针从左下角输入
    for (i=0;i<m;i++){
        cin>>A[i].x>>A[i].y;
    }
    for (i=0;i<n;i++){
        cin>>B[i].x>>B[i].y;
    }
    D[0]=0;
    for (i=1;i<m;i++){
        D[i] = atan2((double)A[i].y-A[0].y,A[i].x-A[0].x);
    }
    for (i=0;i<n;i++){
        double d = Atan2((double)B[i].y-A[0].y,B[i].x-A[0].x);
        if (d<D[1] || d>D[m-1]){
            cout<<"F"<<endl;
        }
        else{
            int left = 0;
            int right = m-1;
            while (right-left>1){
                int middle = (left + right) / 2;
                if (D[middle] < d){
                    left = middle;
                }
                else if (D[middle] > d){
                    right = middle;
                }
                else{
                    if (((double)A[middle].x - A[0].x) / (B[i].x - A[0].x) > 1){
                        cout<<"T"<<endl;
                    }
                    else{
                        cout<<"F"<<endl;
                    }
                    goto nextturn;
                }
            }
            if (Atan2((double)B[i].y-A[left].y,B[i].y-A[left].y)>Atan2((double)A[right].y-A[left].y,A[right].y-A[left].y)){
                cout<<"T"<<endl;
            }
            else{
                cout<<"F"<<endl;
            }
        }
        nextturn:;
    }
    return 0;
}
