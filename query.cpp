#include<iostream>
#include<string.h>
using namespace std;
#define MAX_LEN 1005
#define MAX_CHAR 26
int cnt[MAX_LEN][MAX_CHAR];
int pre_processing(string s)
{
    int n=s.length();

    memset(cnt,0,sizeof(cnt));

    for(int i=0;i<n;i++)
    {
        cnt[i][s[i]-'a']++;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
        {
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    cout<<cnt[0][5];
}
int main()
{
    string s = "geeksforgeeks";
    int Q = 4;
    pre_processing(s);
   return 0;
}
