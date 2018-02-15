#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
typedef  pair<int,int> p;
int fin_ans=INT_MAX;
bool allVisited(bool visited[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            return false;
    }
    return true;
}
void solve(vector<p>v,bool visited[],int n,p curr,p _end,int sum)
{
    if(allVisited(visited,n))
    {
        int temp=sum+abs(curr.first- _end.first)+abs(curr.second-_end.second);
        fin_ans=min(fin_ans,temp);

        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                int temp=abs(curr.first-v[i].first)+abs(curr.second-v[i].second);

                p newt=make_pair(v[i].first,v[i].second);

                solve(v,visited,n,_end,newt,sum+temp);
                visited[i]=false;
            }
        }
    }
    return;
}
int main()
{
    int n,x1,y1,x2,y2;
    cin>>n;

    cin>>x1>>y1;
    cin>>x2>>y2;

    vector<p>v;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        v.push_back(make_pair(a,b));
    }
    bool visited[n];
    memset(visited,false,sizeof(visited));

    solve(v,visited,n,make_pair(x1,y1),make_pair(x2,y2),0);

    cout<<fin_ans<<endl;

    return 0;
}
