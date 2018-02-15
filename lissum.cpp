#include<iostream>
using namespace std;

void LIS(int a[],int n)
{

    int *m=new int[n]();
    m[0]=0;
    for(int i=0;i<n;i++)
    {
        m[i]=a[i];
    }
    int sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                m[i]=m[j]+a[i];
                if(sum<m[i])
                    sum=m[i];
            }
        }
    }
    cout<<sum;
}
int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    LIS(arr,n);
    return 0;
}
