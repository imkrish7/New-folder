#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;

int Graph[1005][100005];
int dp[1005][100005];

int minkey(int key[],bool mstset[],int n)
{
    int m=INT_MAX, min_index;
    for(int i=0;i<n;i++)
    {
      if(mstset[i]==false && key[i]<m)
      {
          m=key[i];
          min_index=i;

      }
    }

    return min_index;
}
void Prims(int n,int v)
{
    int key[n];
    bool mstset[n];

    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mstset[i]=false;
    }

     key[0]=0;

    for(int i=0;i<n-1;i++)
    {
        int u=minkey(key,mstset,n);
        mstset[u]=true;

        for(int v=0;v<n;i++)
        {
            if(Graph[u][v] && !mstset[v] && Graph[u][v]<key[v])
            {
                dp[u][v]=Graph[u][v];
                key[v]=Graph[u][v];
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;

    while(T>0)
    {
        int N,P,M;

        cin>>N>>P>>M;

        for(int i=0;i<P;i++)
        {
            int u,v,d;
            cin>>u>>v>>d;
            Graph[u-1][v-1]=d;
        }
        memset(dp,0,sizeof(dp));
        Prims(N,P);
        for(int i=0;i<M;i++)
        {
            int u,v;
            cin>>u>>v;
            cout<<dp[u-1][v-1]<<endl;
        }
        T--;
    }
}
