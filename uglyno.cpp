#include<iostream>
using namespace std;

int nextugly(int n)
{
    int i2=0,i3=0,i5=0;
    int a[n];
    int next_ugly_multiple2=2;
    int next_ugly_multiple3=3;
    int next_ugly_multiple5=5;
    int next_ugly_no;
    a[0]=1;
    for(int i=1;i<n;i++)
    {
        next_ugly_no=min(next_ugly_multiple2,min(next_ugly_multiple3,next_ugly_multiple5));

        a[i]=next_ugly_no;

        if(next_ugly_no==next_ugly_multiple2)
        {
            i2=i2+1;
            next_ugly_multiple2=a[i2]*2;
        }
        if(next_ugly_no==next_ugly_multiple3)
        {
         i3=i3+1;
         next_ugly_multiple3=a[i3]*3;
        }
        if(next_ugly_no==next_ugly_multiple5)
        {
            i5=i5+1;
            next_ugly_multiple5=a[i5]*5;
        }
    }
    return next_ugly_no;
}
int main()
{
    cout<<nextugly(150);
    return 0;
}
