#include<iostream>
using namespace std;

int main()
{
int arr[]={-7, 1, 5, 2, -4, 3, 0};
int n=sizeof(arr)/sizeof(arr[0]);
    int leftsum=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

    }
    cout<<sum;
    for(int i=0;i<n;i++)
    {
        sum-=arr[i];
        cout<<leftsum<<"---"<<sum<<endl;
        if(leftsum==sum)
        {

            cout<<i<<endl;
            break;
        }
        leftsum+=arr[i];

    }

}
