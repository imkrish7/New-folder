#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
using namespace std;
struct suffix{
        int index;
        char *suff;
};
int cmp(suffix a,suffix b)
{
    return strcmp(a.suff,b.suff)<0?1:0;
}
void _search(char *pat,char *text,int *suffarr,int n)
{

    int m=strlen(pat);

    int l=0,r=n;
    while(l<r)
    {
        int mid=l+(r-1)/2;
        int res=strncmp(pat,text+suffarr[mid],m);

        if(res==0)
        {
            cout<<"Pattern found at indesx"<<suffarr[mid];
            break;
        }
        else if(r<0)
            r=mid-1;
        else
            l=mid+1;

    }
}
int *cresuffix(char *st,int n)
{
    //int n=st.length();

    suffix s[n];

    for(int i=0;i<n;i++)
    {
        s[i].index=i;
        s[i].suff=(st+i);
    }
    sort(s,s+n,cmp);

    int *sufarr=new int[n];

    for(int i=0;i<n;i++)
    {
        sufarr[i]=s[i].index;
    }
return sufarr;
}
int main()
{
    char txt[] = "banana";
    char pat[]="nan";

    int n = strlen(txt);
    int *suffarr=cresuffix(txt,n);
    _search(pat,txt,suffarr,n);
    //cout << "Following is suffix array for " << txt << endl;
    //printArr(suffixArr, n);
    return 0;
}
