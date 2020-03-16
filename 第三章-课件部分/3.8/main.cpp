#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <stdio.h>
#define PI acos(-1)
using namespace std;

/*
凸包Graham-Scan算法
不能处理重复点，3点以下，以及仅有3点但共线(因为无定义)
复杂度0(nlgn)
洛谷
*/
struct Node
{
    double x;
    double y;
    double k;
};
bool compare(Node a,Node b)
{
    return (a.k<b.k ||(a.k==b.k&&a.x<b.x))?1:0;
}
//返回的为弧度,[0,2PI)
double Computek(Node a,Node b)
{
    if (b.y>=a.y)
    {
        return atan2((double)(b.y-a.y),(double)(b.x-a.x));
    }
    else
    {
        return 2*PI+atan2((double)(b.y-a.y),(double)(b.x-a.x));
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    Node node[n],temp,temp1,temp2;
    double result=0;
    stack<Node> nodestack;
    for (i=0;i<n;i++)
    {
        cin>>node[i].x>>node[i].y;
    }
    //找到左下角元素
    Node minnode=node[0];
    j = 0;
    for (i=1;i<n;i++)
    {
        if (node[i].y<minnode.y || (node[i].y==minnode.y&&node[i].x<minnode.x))
        {
            minnode = node[i];
            j = i;
        }
    }
    //计算斜率并排序
    node[j].k = -1;
    for (i=0;i<n;i++)
    {
        if (i!=j)
        {
            node[i].k = Computek(node[j],node[i]);
        }
    }
    sort(node,node+n,compare);
  //  for (i=0;i<n;i++)
  //  {
  //      cout<<node[i].x<<" "<<node[i].y<<" "<<node[i].k<<endl;
  //  }
    //找到最外圈,O(n)
    nodestack.push(node[0]);
    nodestack.push(node[1]);
    nodestack.push(node[2]);
    i = 3;
    while (i<n)
    {
        while(1) //共最多进行2n次
        {
            temp = nodestack.top();
            nodestack.pop();
            double k1 = Computek(nodestack.top(),node[i]);
            double k2 = Computek(temp,node[i]);
            if (k1<k2)
            {
                nodestack.push(temp);
                nodestack.push(node[i]);
                break;
            }
        }
        i++;
    }
    temp1 = nodestack.top();
  //  cout<<temp1.x<<" "<<temp1.y<<endl;
    temp2 = temp1;
    nodestack.pop();
    while (!nodestack.empty())
    {
        temp = nodestack.top();
   //     cout<<temp.x<<" "<<temp.y<<endl;
        result += pow(pow((temp.x-temp1.x),2)+pow((temp.y-temp1.y),2),0.5);
        nodestack.pop();
        temp1 = temp;
    }
    result += pow(pow((temp2.x-temp1.x),2)+pow((temp2.y-temp1.y),2),0.5);
    printf("%.2f",result);
    return 0;
}
