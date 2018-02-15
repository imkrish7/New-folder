#include<iostream>
using namespace std;
int arr[1005];
void preprocess(int a[],int n)
{
    arr[0]=0;
    /*for(int i=1;i<n;i++)
    {
        a[i]=a[i-1]^i;
    }*/
    for(int i=1;i<=n;i++)
    {
        arr[i]=arr[i-1]^a[i];
        //cout<<arr[i];
    }
    cout<<arr[3];

}
int main()
{
 int a[]={ 0, 1, 3, 0, 4, 1, 7, 0, 8, 1, 11};
 int n=sizeof(a)/sizeof(a[0]);

 preprocess(a,n);
 cout<<(arr[4]^arr[1]);
}
