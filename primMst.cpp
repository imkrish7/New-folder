#include<iostream>
using namespace std;

#define V 5

int _min(bool sptset[],int key[])
{
        int m=INT_MAX,m_index=0;

        for(int i=0;i<V;i++)
        {
            if(sptset[i]==false && key[i]<m)
            {
                m=key[i];
                m_index=i;
            }
        }
return m_index;
}
void print(int parent[],int n,int key[])
{
    for(int i=1;i<n;i++)
    {
        cout<<i<<"--"<<parent[i]<<"---"<<key[i];
    }
}
void primmst(int Graph[V][V])
{
        bool mstset[V];
        int parent[V];
        int key[V];

        for(int i=0;i<V;i++)
        {
            mstset[i]=false;
            key[i]=INT_MAX;
        }

        key[0]=0;
        parent[0]=-1;

        for(int c=0;c<V-1;c++)
        {
            int u=_min(mstset,key);

            mstset[u]=true;

            for(int v=0;v<V;v++)
            {
                if(Graph[u][v] && !mstset[v] && Graph[u][v]<key[v])
                {
                    parent[v]=u;
                    key[v]=Graph[u][v];
                }
            }
        }
        print(parent,V,key);
}
int main()
{
     int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primmst(graph);

    return 0;
}
