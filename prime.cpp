#include<iostream>
using namespace std;
int _max=100001;
int prime[100001];
bool isprime(int n)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void buildprefix()
{
        prime[0]=0;
        prime[1]=0;

        for(int i=2;i<_max;i++)
        {
            if(isprime(i))
            {
               prime[i]=prime[i-1]+1;
               }
               else
               {
                prime[i]=prime[i-1];
               }
        }

}

int main()
{
 buildprefix();

 int l=1,r=10;

 cout<<prime[r+1]-prime[l-1];
 return 0;
}
