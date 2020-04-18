#include <iostream>

using namespace std;

/**
时间复杂度和空间复杂度都是O(n^2)
*/
int main()
{
    int n,i,j;
    cin>>n;
    int R[n][n];
    for (i=0;i<n;i++){
        R[i][0] = 1;
    }

    for (j=1;j<n;j++){
        for (i=0;i<n;i++){
            if (j>i){
                R[i][j] = R[i][j-1];
            }
            else if (j<i){
                R[i][j] = R[i][j-1] + R[i-j-1][j];
            }
            else{
                R[i][j] = R[i][j-1] + 1;
            }
        }
    }

    cout<<R[n-1][n-1];
    return 0;
}
