#include <iostream>

using namespace std;

void Add(int A[],int n,int x){
    A[n] = x;
    int i=n;
    while (i/2>=1){
        if (A[i]<A[i/2]){
            swap(A[i],A[i/2]);
            i /= 2;
        }
        else{
            break;
        }
    }
}

int Delete(int A[],int n){
    int result = A[1];
    A[1] = A[n];
    int i=1;
    while (i*2<n){
        if (i*2+1==n){  //只有左子树
            if (A[i]>A[i*2]){
                swap(A[i],A[i*2]);
                i *= 2;
            }
            else{
                break;
            }
        }
        else{   //左右子树都有
            if (A[i*2]<=A[i*2+1]&& A[i*2]<A[i]){
                swap(A[i],A[i*2]);
                i *= 2;
            }
            else if(A[i*2+1]<A[i*21]&& A[i*2+1]<A[i]){
                swap(A[i],A[i*2+1]);
                i = i*2+1;
            }
            else{
                break;
            }
        }
    }
    return result;
}
int main()
{
    int n,i,x,temp,result=0;
    cin>>n;
    int A[n+1]={0};
    for (i=0;i<n;i++){
        cin>>x;
        Add(A,i+1,x);
    }

    for (i=0;i<n-1;i++){
        temp = Delete(A,n-i)+Delete(A,n-i-1);
        result += temp-1;
        Add(A,n-i-1,temp);
    }
    cout<<result;
    return 0;
}
