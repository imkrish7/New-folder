#include<iostream>
#include<algorithm>
using namespace std;

struct Edge{

        int src,dest,weight;
};

struct Graph{

    int V,E;

    Edge *edge;
};

Graph *createGraph(int v,int e)
{
            Graph *g=(Graph *)malloc(sizeof(Graph));
            g->V=v;
            g->E=e;

            g->edge=new Edge[g->E];

            return g;

}

struct subsets
{
 int parent;
 int _rank;
};

int _find(subsets subset[],int i)
{


    if(subset[i].parent!=i)
        subset[i].parent=_find(subset,subset[i].parent);

    return subset[i].parent;
}

void _union(subsets subset[],int x,int y)
{
    int xroot=_find(subset,x);
    int yroot=_find(subset,y);

    if(subset[xroot]._rank>subset[yroot]._rank)
    {
            subset[yroot].parent=xroot;
    }
    else if(subset[xroot]._rank<subset[yroot]._rank)
    {
        subset[xroot].parent=yroot;
    }
    else
    {
        subset[xroot].parent=yroot;
        subset[xroot]._rank++;
    }
}
int mycomp(const void *a,const void *b)
{

    Edge *a1=(Edge *)a;
    Edge *b1=(Edge *)b;

    return a1->weight>b1->weight;
}

void Kruskals(Graph *graph,int cost)
{
        int V=graph->V;
        int sum=0;
        Edge *result=new Edge[graph->E];

        int e=0;
        int i=0;

        qsort(graph->edge,graph->E,sizeof(graph->edge[0]),mycomp);

        subsets *subset=new subsets[V];

        for(int j=0;j<V;j++)
        {
            subset[j].parent=j;
            subset[j]._rank=0;
        }

        while(e<V-1)
        {
            Edge next_edge=graph->edge[i++];

           int x=_find(subset,next_edge.src);
           int y=_find(subset,next_edge.dest);

            if(x!=y)
            {
                result[e++]=next_edge;
                //sum+=next_edge.weight;
                _union(subset,x,y);
            }


        }
        int c=0;
        for(int i=0;i<V;i++)
        {
            if(result[i].weight<cost && sum+result[i].weight<cost)
            {
                sum+=result[i].weight+1;
                c++;
            }
        }
        if(c==0)
        {
            cout<<"-1"<<endl;;
        }
        else
        {
            cout<<c<<endl;
        }
}
int main()
{
    int N,M,C;
    cin>>N>>M>>C;

    Graph *graph=createGraph(N,M);

    for(int i=0;i<M;i++)
    {
        cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
    }
    //qsort(graph->edge,graph->E,mycomp)
    cout<<"hello";
    Kruskals(graph,C);

    return 0;
}
