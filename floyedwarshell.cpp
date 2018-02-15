#include<iostream>
using namespace std;
int V 9;
void floyedwarshell(int Graph[][V])
{
        int dist[V][V];

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                dist[i][j]=Graph[i][j];
            }
        }

        for(int k=0;k<V;k++)
        {
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                    if(Graph[i][j]>Graph[i][k]+Graph[k][j])
                    {
                        Graph[i][j]=Graph[i][j]+Graph[k][j];
                    }
                }
            }
        }
}
