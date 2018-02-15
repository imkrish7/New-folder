#include<iostream>
#include<stack>
using namespace std;
int bracketrev(string s,int n)
{
    stack<char> st;
    int i=0;
    while(i<n)
    {
        if(s[i]=='}' && !st.empty())
        {
            if(st.top()=='{')
                st.pop();
            else
                st.push(s[i]);
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }
    int ss=st.size();
    int c=0;
    while(!st.empty() && st.top()=='{')
    {
        st.pop();
        c++;
    }
    return((ss/2)+ (c/2) );
}
int main()
{
string st="{{{{{}}}";
int n=st.length();
cout<<bracketrev(st,n);
return 0;
}
