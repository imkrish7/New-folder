#include <bits/stdc++.h>
using namespace std;

bool isWinning(bool a[])
{
    //cout<<"hello";
    for(int i=0;i<10;i++)
    {
        if(a[i]==false)
            return false;
    }

    return true;
}
bool findmatch(string s2,bool v[])
{


    int n2=s2.length();
    //cout<<s2;

      for(int j=0;j<n2;j++)
        {
            //cout<<"hello1";
            if(v[s2[j]-'0']==false)
            {

                v[s2[j]-'0']=true;
            }
        }
        //isWinning(v);
    if(isWinning(v)==true)
    {
        return true;
    }
    else
    {
        return false;
    }

}
long winningLotteryTicket(vector <string> tickets) {
    int n=tickets.size();
    long c=0;
    for(int i=0;i<n;i++)
    {
          string s1=tickets[i];
          bool v[10];
          memset(v,false,10);
          for(int j=0;j<s1.length();j++)
          {
            if(v[s1[j]-'0']==false)
            {

                v[s1[j]-'0']=true;
            }
          }
        for(int j=i+1;j<n;j++)
        {

                    string s2=tickets[j];


                    if(findmatch(s2,v)==true)
                    {
                        cout<<s1<<"->"<<s2<<endl;
                        c++;
                    }


        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    vector<string> tickets(n);
    for(int tickets_i = 0; tickets_i < n; tickets_i++){
       cin >> tickets[tickets_i];
    }
    long result = winningLotteryTicket(tickets);
    cout << result << endl;
    return 0;
}
