#include<iostream>
using namespace std;
void _find(int a[],int n)
{

    for(int i=0;i<n;i++)
    {
        if(a[abs(a[i])]>0)
        {
            a[abs(a[i])]=-a[abs(a[i])];

        }
        else
        cout<<abs(a[i])<<endl;
    }
}
int main()
{
        int a[]={17,2,8,9,17};

        _find(a,5);

        return 0;

}
