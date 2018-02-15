#include<iostream>
#include<math.h>
using namespace std;
int getSumUtil(int *st,int ss,int se,int qs,int qe,int si)
{
        if(qs<=ss && qe>=se)
        {
            return st[si];
        }
        if(se<qs || ss>qe)
          return 0;

        int mid=ss+(se-ss)/2;

        return getSumUtil(st,ss,mid,qs,qe,2*si+1)+getSumUtil(st,mid+1,se,qs,qe,2*si+2);
}
int getSum(int *st,int ss,int se,int qs,int qe)
{
    if(qs<ss || qe>se || qs>qe)
    {
        cout<<"Ivalid input";
        return 0;
    }


    return getSumUtil(st,ss,se-1,qs,qe,0);
}
void updateValueUtil(int *st,int ss,int se,int i,int diff,int si)
{
    if(i<ss || i>se)
     return ;

     st[si]=diff+st[si];
     if(se!=ss)
     {
        int mid=ss+(se-ss)/2;
        updateValueUtil(st,ss,mid,i,diff,2*si+1);
        updateValueUtil(st,mid+1,se,i,diff,2*si+2);

     }
}
void updateValue(int arr[],int *st,int ss,int se,int i,int val)
{
    if(i<0 || i>se-1)
    {
        cout<<"invalid input";
    }

    int diff=val-arr[i];

    updateValueUtil(st,ss,se-1,i,diff,0);
}
int cunstructutil(int arr[],int *st,int ss,int se,int si)
{

    if(ss==se)
    {
    st[si]=arr[ss];
    return st[si];
    }

    int mid=ss+(se-ss)/2;
    st[si]=cunstructutil(arr,st,ss,mid,2*si+1)+cunstructutil(arr,st,mid+1,se,2*si+2);

  return st[si];
}
int *cunstruct(int arr[],int n)
{


    int x=(int)(ceil(log2(n)));
    int max_size=2*(int)pow(2,x)-1;

    int *st=new int[max_size];

    cunstructutil(arr,st,0,n-1,0);

    return st;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);


    int *st = cunstruct(arr, n);


    cout<<"Sum of values in given range = %dn"<<getSum(st,0,n,1,3)<<endl;
    updateValue(arr, st, 0,n, 1, 10);

    // Find sum after the value is updated
    cout<<"Updated sum of values in given range = %dn"<<getSum(st, 0,n, 1, 3)<<endl;
    return 0;
}
