#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct interval{
        int s;
        int e;
};
bool comp(interval a1,interval a2)
{
    return (a1.s > a2.s);
}
void mergeinterval(interval a[],int n)
{
    stack<interval>s;
    sort(a,a+n,comp);

    s.push(a[0]);
    for(int i=0;i<n;i++)
    {

        cout<<a[i].s<<"--"<<a[i].e<<endl;
    }

    for(int i=1;i<n;i++)
    {
        interval top=s.top();

        if(top.e<a[i].s)
            s.push(a[i]);

        else if(top.e<a[i].e)
        {
            top.e=a[i].e;
            s.pop();
            s.push(top);
        }

    }
    while(!s.empty())
    {
        interval t=s.top();

        cout<<t.s<<t.e;

        s.pop();

    }
}
int main()
{
    interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeinterval(arr, n);
    return 0;
}
