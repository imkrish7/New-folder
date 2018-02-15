
#include<iostream>
#include<cstring>
using namespace std;

int countM(int a[],int n)
{
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    for(int len=1;len<=n;++len)
    {
        for(int i=0;i+len<=n;i++)
        {
            int j=i+len;
            int &curr=dp[i][j];
            curr=dp[i+1][j]+1;
            for(int k=i+1;k<j;k++)
            {
                if(a[i]==a[k])
                {
                   //cout<<"print";
                   int bon=dp[i+1][k]+dp[k+1][j];
                   curr=min(curr,bon);
                }
            }
        }
    }
    cout<<dp[0][n];
    return 0;
}
int main()
{

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    countM(a,n);

}
