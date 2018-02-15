#include<iostream>
#include<string.h>
using namespace std;


int findmin(string s,int n)
{
    int cur_len=1;
    int max_len=1;
    int prev_index;
    int *visited =new int[26];


    memset(visited,-1,sizeof(visited));

    visited[s[0]]=0;
    //cout<<visited[s[1]-'A'];
    for(int i=1;i<n;i++)
    {

        prev_index=visited[s[i]];
        //cout<<prev_index;
        if(prev_index ==-1 || i-cur_len>prev_index)
           {
            cur_len++;
           cout<<i;
           }
        else
        {
            cout<<"hellokkkl"<<i;
          if(cur_len>max_len)
             max_len=cur_len;

          cur_len=i-prev_index;
        }

        visited[s[i]]=i;
    }

    if(cur_len>max_len)
        max_len=cur_len;

    delete(visited);

    return max_len;
}

int main()
{
    string s="ABDEFGABEF";

    int n=s.length();

    cout<<findmin(s,n);
    return 0;
}
