#include<iostream>
using namespace std;

int main()
{

int arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};

int n=sizeof(arr)/sizeof(arr[0]);

for(int i=1;i<n;i++)
{
 arr[i]=arr[i-1]+arr[i];
}
cout<<(arr[3]-arr[1-1]);
return 0;
}
