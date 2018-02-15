#include<iostream>
using namespace std;

int findway(int a[],int m,int n)
{

    if(n==0)
        return 1;

    if(n<0)
        return 0;

    if(m<=0 && n>=1)
    {
        return 0;
    }

    return findway(a,m-1,n)+findway(a,m,n-a[m-1]);

}
int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<findway(arr,m,4);
    return 0;
}
