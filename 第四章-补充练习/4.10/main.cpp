#include <iostream>

using namespace std;
/**
有多个可能的输出则随机输出一个正解
时间复杂度O(n^3),空间复杂度O(n^2)
*/
void Print(int Num[],char Op[],int P[],int left,int right,int Size){
    if (left==right){
        cout<<Num[left];
    }
    else{
        int right2 = P[left*Size+right];
        int left2 = right2+1;
        if (right2!=left){
            cout<<"(";
            Print(Num,Op,P,left,right2,Size);
            cout<<")";
        }
        else{
            Print(Num,Op,P,left,right2,Size);
        }
        cout<<Op[right2];
        if (left2!=right){
            cout<<"(";
            Print(Num,Op,P,left2,right,Size);
            cout<<")";
        }
        else{
            Print(Num,Op,P,left2,right,Size);
        }
    }
}

int main()
{
    int n,i,j,k;
    cin>>n;
    int Num[n];
    char Op[n-1];
    int R[n][n]={0};
    int P[n*n]; //同样为了好传参
    for (i=0;i<n-1;i++){
        cin>>Num[i]>>Op[i];
    }
    cin>>Num[n-1];

    for (i=0;i<n;i++){
        R[i][i] = Num[i];
        P[i*n+i] = -1;
    }

    for (i=1;i<n;i++){
        for (j=0;j<n-i;j++){
            R[j][j+i] = -2147383648;
            for (k=j;k<j+i;k++){
                if (Op[k]=='+'){
                    if (R[j][j+i]<R[j][k]+R[k+1][j+i]){
                        R[j][j+i]=R[j][k]+R[k+1][j+i];
                        P[j*n+j+i] = k;
                    }
                }
                else if (Op[k]=='-'){
                    if (R[j][j+i]<R[j][k]-R[k+1][j+i]){
                        R[j][j+i]=R[j][k]-R[k+1][j+i];
                        P[j*n+j+i] = k;
                    }
                }
                else{
                    if (R[j][j+i]<R[j][k]*R[k+1][j+i]){
                        R[j][j+i]=R[j][k]*R[k+1][j+i];
                        P[j*n+j+i] = k;
                    }
                }
            }
        }
    }
    cout << "The result is:"<<R[0][n-1] << endl;
    Print(Num,Op,P,0,n-1,n);
    return 0;
}
