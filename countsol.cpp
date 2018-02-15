#include<iostream>
using namespace std;

int countSol(int a[],int start,int n,int rhs)
{
    if(rhs==0)
        return 1;

      int result=0;

       for(int i=start;i<=n;i++)
       {
        if(a[i]<=rhs)
            result+=countSol(a,i,n,rhs-a[i]);
       }
return result;
}

int main()
{
    int coeff[]  = {2, 2, 5};
    int rhs = 4;
    int n = sizeof(coeff)/sizeof(coeff[0]);
    cout << countSol(coeff, 0,n-1, rhs);
    return 0;
}
