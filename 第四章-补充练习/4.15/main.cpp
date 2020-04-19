#include <iostream>

using namespace std;

int main()
{
    int T,V,A,C,i,j,k;
    cin>>T>>V>>A>>C;
    int S[T],D[T];
    for (i=0;i<T;i++){
        cin>>S[i]>>D[i];
    }

    int R[T][V+1];
    for (i=0;i<T;i++){
        for (j=0;j<=V;j++){
            R[i][j] = 1000000;
        }
    }
    for (i=0;i<=A-C&&i<=V;i++){
        R[0][i] = D[0]*(i+S[0])+C*i;
    }

    for (i=1;i<T;i++){
        for (j=0;j<=V;j++){
            for (k=max(0,j+S[i]-V);k<=min(j+S[i],A);k++){
                R[i][j] = min(R[i][j],D[i]*k+C*j+R[i-1][j-k+S[i]]);
            }
        }
    }
    cout<<R[T-1][0];
    return 0;
}
