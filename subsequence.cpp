#include<iostream>
using namespace std;
int *fwd,*bwd;
void preprocess(string a,string b)
{
    int n=a.length();

    fwd=new int[n]();
    bwd=new int[n]();
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(j<b.length() && a[i-1]==b[j])
         j++;

         fwd[i]=j;
    }
    j=0;
    for(int i=n-1;i>=1;i--)
    {
        if(j<b.length() && a[i-1]==b[b.length()-j-1])
         j++;


         bwd[i]=j;
    }
}
int main()
{
    string a = "abcabcxy", b = "acy";
    preprocess(a, b);

    if(fwd[1]+bwd[4]>=b.size())
    {
        cout<<"YES";
    }
    //cout<<bwd[8];
    return 0;
}
