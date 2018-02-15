#include<iostream>
#include<algorithm>
using namespace std;

int LowerBound(int arr[],int n,int x)
{

    int l=0;
    int r=n;
    while(l<r)
    {

        int mid=l+(r-l)/2;

        if(arr[mid]>=x)
             r=mid-1;
        else
           l=mid+1;
    }

  return l;
}
int upperBound(int arr[],int n,int x)
{

    int l=0;
    int r=n;
    while(l<r)
    {

        int mid=l+(r-l)/2;

        if(arr[mid]<=x)
             l=mid+1;
        else
           r=mid;
    }

  return r;
}

int countRange(int arr[],int n,int x,int y)
{

    //sort(arr,arr+n);
    int _count=0;
    _count=upperBound(arr,n,y)-LowerBound(arr,n,x);

    return _count;
}
int main()
{
    int arr[] = { 1, 4, 4, 9, 10, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Preprocess array
    sort(arr, arr + n);

    // Answer queries
    int i = 1, j = 4;
    cout << countRange(arr, n, i, j) << endl;
    return 0;
}
