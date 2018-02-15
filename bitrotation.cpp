#include<iostream>
using namespace std;
int INT_BITS=32;
int main()
{
    int n,d;
    cin>>n>>d;

    int a=n<<(d);

    //int b=n>>(INT_BITS-d);

    cout<<a<<endl;
    return 0;
}
