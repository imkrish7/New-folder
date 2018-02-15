#include<iostream>
#include<vector>
using namespace std;

void findmax(vector<vector<int>>a,int N,int M)
{

    vector<vector<int>>s(N,vector<int>(M));

    for(int i=0;i<N;i++)
        s[i][0]=a[i][0];

    for(int i=1;i<M;i++)
            s[0][i]=a[0][i];

    for(int i=1;i<N;i++)
    {
        for(int j=1;j<M;j++)
        {
            if(a[i][j]==1)
            {
                s[i][j]=min(s[i][j-1],min(s[i-1][j],s[i-1][j-1]))+1;
            }
            else
            {
                s[i][j]=0;
            }
        }
    }
    int max_s=INT_MIN;
    int min_i=0,min_j=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(max_s<s[i][j])
            {
                max_s=s[i][j];
                min_i=i;
                min_j=j;
            }
        }
    }
    cout<<max_s<<endl;;
    for(int i=min_i;i>min_i-max_s;i--)
    {
        for(int j=min_j;j>min_j-max_s;j--)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    vector<vector<int>>a {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

                   findmax(a,4,5);

               return 0;
}
