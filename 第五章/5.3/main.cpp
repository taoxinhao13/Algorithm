#include <iostream>

using namespace std;

int main()
{
    int n,result=0;
    cin>>n;
    result+=n/10;
    n=n%10;
    result+=n/5;
    n=n%5;
    result+=n/2;
    n=n%2;
    result+=n;
    cout<<result;
    return 0;
}
