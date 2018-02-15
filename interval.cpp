#include<iostream>
#include<algorithm>
using namespace std;

struct interval{

        int s;
        int e;

};
bool mycomp(interval a1,interval a2)
{
    return(a1.s>a2.s);
}
void merginterval(interval a[],int n)
{
    sort(a,a+n,mycomp);
    int index=0;

    for(int i=0;i<n;i++)
    {

        if(index!=0 && a[index-1].s<=a[i].e)
        {
            while(index!=0 && a[index-1].s<a[i].e)
            {
                a[index-1].e=max(a[index-1].e,a[i].e);
                a[index-1].s=min(a[index-1].s,a[i].s);
                index--;
            }
        }
        else
        a[index]=a[i];
        index++;
    }
    for(int i=0;i<index;i++)
    {
        cout<<a[i].s<<"---"<<a[i].e<<endl;
    }
}
int main()
{
    interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    merginterval(arr, n);
    return 0;
}
