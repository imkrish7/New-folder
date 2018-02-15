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

            g->edge=new Edge[g->E]();

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

void Kruskals(Graph *graph)
{
        int V=graph->V;

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
                _union(subset,x,y);
            }


        }

        for(int i=0;i<V;i++)
        {
            cout<<result[i].src<<"-->"<<result[i].dest<<"--->"<<result[i].weight<<endl;
        }

}
int main()
{
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    Kruskals(graph);

    return 0;
}
