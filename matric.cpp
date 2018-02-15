#include<iostream>
#include<string.h>
using namespace std;
#define n 3
int fillUtil(int dp[n][n],int mat[n][n],int i,int j)
{

    if(i<0||j<0||i>n||j>n)
        return 0;

     if(dp[i][j]!=-1)
            return dp[i][j];

     if(j<n && (mat[i][j]+1==mat[i][j+1]))
            return dp[i][j]=1+fillUtil(dp,mat,i,j+1);

     if(i<n && (mat[i][j]+1==mat[i+1][j]))
            return dp[i][j]=1+fillUtil(dp,mat,i+1,j);

     if(j>=0 && (mat[i][j]+1==mat[i][j-1]))
                return dp[i][j]=1+fillUtil(dp,mat,i,j-1);

     if(i>=0 && (mat[i][j]+1==mat[i-1][j]))
                return dp[i][j]=1+fillUtil(dp,mat,i-1,j);

     return dp[i][j]=1;
}
void _fill(int mat[n][n])
{
    int result=INT_MIN;
    int dp[n][n];
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j]==-1)
                fillUtil(dp,mat,i,j);

           result=max(result,dp[i][j]);
        }
    }
    cout<<result<<endl;
}
int main()
{
    int  mat[n][n] = {{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
                    _fill(mat);

              return 0;
}
