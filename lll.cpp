#include<iostream>
using namespace std;

int main()
{
    int a[]={1,3};
    int &curr=a[0];
    cout<<curr;
    curr=a[1]+1;
    cout<<curr;
    cout<<a[0]<<a[1];
    return 0;
}
