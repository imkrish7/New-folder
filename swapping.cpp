#include<iostream>
using namespace std;

int main()
{
 string s;
 cin>>s;

 int n=s.length()-1;

 int start=0;

    while(start<n)
    {

        if((s[start]>='a' && s[start]<='z')==false)
        {
            start++;
        }
        else if((s[n]>='a' && s[n]<='z')==false)
        {
            --n;
        }
        else if((s[start]>='a' && s[start]<='z') && (s[n]>='a' && s[n]<='z'))
        {
            s[start]=s[start]^s[n];
            s[n]=s[n]^s[start];
            s[start]=s[start]^s[n];

            start++;
            --n;
        }

    }
    cout<<s<<endl;

}
