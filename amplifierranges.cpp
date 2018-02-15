#include<iostream>
#include<vector>
using namespace std;

int countchanges(vector<vector<int>>a,int N,int M)
{
    int c=0;
    for(int i=0;i<N;i++)
    {
        int f=1;
        for(int j=0;j<M;j++)
        {
            if(a[i][j]==0)
            {
                f=0;
            }
        }
        if(f==1)
        {
            c++;
        }
    }
    return c;
}

vector<vector<int>>applychanges(vector<vector<int>> a,int c,int N)
{

    for(int i=0;i<N;i++)
    {
        a[i][c]=1-a[i][c];
    }
    return a;
}

int _find(vector<vector<int>>a,int k,int s,int N,int M)
{
    int ans=INT_MIN;
    if(k==1)
    {
       ans=max(ans,countchanges(a,N,M));
    }
    else
    {
            for(int i=s;i<M;i++)
            {
                a=applychanges(a,i,N);
                ans=max(ans,_find(a,k-1,i,N,M));
                a=applychanges(a,i,N);
            }

    }
return ans;
}
int main()
{
  int N=4;
  int M=5;
  vector<vector<int>> a{{0,0,0,1,0},{0,0,0,1,0},{0,0,0,0,0},{0,0,0,0,0},};

    cout<<_find(a,5,0,N,M)<<endl;;
    return 0;
}
