#include<iostream>
#include<vector>
using namespace std;
long long mod=1e9+7;
int prime[100005];
int dp[1005][1005];
int a[1005][1005];
int mark[1005][1005];
pair<int ,int>ans[100005];
void sieve()
{
    for(int i=2;i*i<=100005;i++)
    {
        if(prime[i]==0)
        {
         for(int j=i*i;j<=100005;j+=i)
         {
             prime[i*i]=1;
         }
    }
}
}
int q=0,n,m;
void dfs(int i,int j,int k)
{
    if(a[i][j]==0|| i>n||j>m||mark[i][j]||q)
     return;

    mark[i][j]=1;
    ans[k]=make_pair(i,j);

    if(i==0 && j==m)
    {
        q=k;
        return;
    }
    dfs(i+1,j+1,k+1);
    dfs(i+1,j,k+1);
    dfs(i,j+1,k+1);
}
int main()
{
    sieve();
    cin>>n>>m;

    //int path[n][m];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            cin>>a[i][j];
            if(prime[a[i][j]]==0)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 && j==1)
                continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1])%mod;
            if(a[i][j]==0)
            {
                dp[i][j]=0;
            }
        }
    }
    dfs(1,1,1);
    cout<<dp[n][m]<<endl;

    for(int i=0;i<q;i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

}
