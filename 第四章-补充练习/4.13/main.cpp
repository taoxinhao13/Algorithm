#include <iostream>

using namespace std;

/**
如果有k种卡片，共n张卡片，则时间复杂度和空间复杂度都是O(n^k)
尽管这个系数很小，小于1/(k*k)，但n很大时还是会爆炸
*/
int main()
{
    int n,m,i,j,k,l,temp;
    cin>>n>>m;
    int score[n];
    for (i=0;i<n;i++){
        cin>>score[i];
    }
    int card[4]={0};
    for (i=0;i<m;i++){
        cin>>temp;
        card[temp-1]++;
    }

    int R[card[0]+1][card[1]+1][card[2]+1][card[3]+1];

    for (i=0;i<=card[0];i++){
        for (j=0;j<=card[1];j++){
            for (k=0;k<=card[2];k++){
                for (l=0;l<=card[3];l++){
                    R[i][j][k][l] = score[0];
                    int pos = i+2*j+3*k+4*l;
                    if (i!=0){
                        R[i][j][k][l] = max(R[i][j][k][l],R[i-1][j][k][l]+score[pos]);
                    }
                    if (j!=0){
                        R[i][j][k][l] = max(R[i][j][k][l],R[i][j-1][k][l]+score[pos]);
                    }
                    if (k!=0){
                        R[i][j][k][l] = max(R[i][j][k][l],R[i][j][k-1][l]+score[pos]);
                    }
                    if (l!=0){
                        R[i][j][k][l] = max(R[i][j][k][l],R[i][j][k][l-1]+score[pos]);
                    }
                }
            }
        }
    }

    cout<<R[card[0]][card[1]][card[2]][card[3]];
    return 0;
}
