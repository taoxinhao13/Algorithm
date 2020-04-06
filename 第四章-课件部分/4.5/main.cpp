#include <iostream>

using namespace std;
/**
01背包问题
约束：输入均为整数,m件物品，背包总容量n
输出为装入价值最大的一组最优解中的物品编号(第一个输入为1号)，如果有多组解则任意输出一组
动态规划算法
时间复杂度和空间复杂度都是O(mn)
*/

struct Item{
    int Size;
    int Cost;
};

int main()
{
    int m,n,i,j;
    cout<<"Please input the total number of items and the bag's capacity:";
    cin>>m>>n;
    Item A[m];

    //result[i][k]:前i+1个物品在背包重量为k+1的情况下所能装入的最大价值
    int result[m][n];
    for (i=0;i<m;i++){
        cin>>A[i].Size>>A[i].Cost;
    }

    for (i=0;i<n;i++){
        if (i>=A[0].Size){
            result[0][i] = A[0].Cost;
        }
        else{
            result[0][i] = 0;
        }
    }

    for (i=1;i<m;i++){
        for (j=0;j<n;j++){
            if (j>=A[i].Size){
                result[i][j] = max(result[i-1][j],result[i-1][j-A[i].Size]+A[i].Cost);
            }
            else{
                result[i][j] = result[i-1][j];
            }
        }
    }

    i = m-1;
    j = n-1;
    while (i>0 && j>0){
        if (result[i][j]!=result[i-1][j]){
            cout<<i+1<<" ";
            j -= A[i].Size;
        }
        i--;
    }

    return 0;
}
