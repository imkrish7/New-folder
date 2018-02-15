#include<iostream>
#include<string.h>
using namespace std;
#define R 3
#define C 3
int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};

int dp[R][C];
bool isValid(int i,int j)
{
    if(i<0 || R<i||j<0|| C<j)
        return false;
   return true;
}
bool isadjacent(char pre,char curr)
{
    return(((curr-'a')-(prev-'a'))==1);
}
int getLenUtil(char mat[][C],int i,int j,char s)
{

           if(!isValid(i,j)|| !isadjacent(s,mat[i][j]))
                return 0;

           if(dp[i][j]!=-1)
            return dp[i][j];

            int ans =0;

            for(int k=0;k<8;k++)
            {
                ans=max(ans,1+getLenUtil(mat,i+x[k],j+y[k],mat[i][j]));

            }

   return dp[i][j]=ans;

}
int getLen(char mat[][C],char s)
{
    memset(dp,-1,sizeof(dp));

    int ans=0;

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==s)
            {
                for(int k=0;k<8;k++)
                    ans=max(ans,1+getLenUtil(mat,i+x[k],j+y[k],s));
            }
        }
    }
    return ans;
}
int main()
{
    char mat[R][C] = { {'a','c','d'},
                     { 'h','b','a'},
                     { 'i','g','f'}};

    cout << getLen(mat, 'a') << endl;
    return 0;
}
