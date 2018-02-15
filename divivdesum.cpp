#include<iostream>
using namespace std;

int maxsum(int n )
{
    if(n==0 || n==1)
        return n;

    int dp[n+1];
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i/2]+dp[i/3]+dp[i/4],i);

    }
    return dp[n];
}

int main()
{
    int n=5;

    cout<<maxsum(5);
    return 0;

}
