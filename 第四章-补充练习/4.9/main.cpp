#include <iostream>
#include <string.h>
using namespace std;
/**
空间复杂度和时间复杂度都是O(n*m*p)
*/
int main()
{
    int n,m,p,i,j,k;
    cin>>n>>m>>p;
    char A[n];
    char B[m];
    char C[p];
    int R[n+1][m+1][p+1];
    memset(R,0,sizeof(int)*(n+1)*(m+1)*(p+1));
    for (i=0;i<n;i++){
        cin>>A[i];
    };
    for (i=0;i<m;i++){
        cin>>B[i];
    };
    for (i=0;i<p;i++){
        cin>>C[i];
    };
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            for (k=1;k<=p;k++){
                if (A[i-1] == B[j-1] && B[j-1] == C[k-1]){
                    R[i][j][k] = R[i-1][j-1][k-1]+1;
                }
                else{
                    R[i][j][k] = max(max(R[i][j][k-1],R[i][j-1][k]),R[i-1][j][k]);
                }
            }
        }
    }
    cout<<R[n][m][p];
    return 0;
}
