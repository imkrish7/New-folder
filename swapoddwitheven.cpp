#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int m=n & 0xAAAAAAAA;
    int k=n & 0x55555555;

    m=m>>1;
    k=k<<1;
    cout<<(m|k);
}
