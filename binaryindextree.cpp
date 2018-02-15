#include<iostream>
using namespace std;
int getsum(int *bit,int n)
{
    int res=0;
    n=n+1;
    while(n>0)
    {
        res+=bit[n];
        n-=n&(-n);
    }
    return res;
}
int updateutil(int *bit,int n,int val,int i)
{
    i=i+1;

    while(i<=n)
    {
        bit[i]+=val;

        i+=i&(-i);
    }
}
int *cunstruct(int a[],int n)
{

    int *bit=new int[n+1]();

    for(int i=0;i<n;i++)
    {
        updateutil(bit,n,a[i],i);
    }

   return bit;
}

int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = cunstruct(freq, n);
    cout << "Sum of elements in arr[0..5] is "
         << getsum(BITree, 5);
}
