#include<iostream>
using namespace std;
int N=3;
int M=4;
int a[3][4]={ {1, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 0, 0, 0},
            };
void applychangesr(int r)
{
        for(int i=0;i<M;i++)
        {
            a[r][i]=1;
        }
}
void applychangesc(int c)
{
    for(int i=0;i<N;i++)
    {
        a[i][c]=1;
    }
}
void made()
{

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(a[i][j]==1)
            {
                applychangesr(i);
                applychangesc(j);
                i++;
                j++;
            }
        }
    }
}
int main()
{


        made();

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
             cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
}
