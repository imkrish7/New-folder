#include<iostream>
#include<vector>
using namespace std;

void prind(vector<vector<int>>a,int n,int c)
{

    for(int i=0;i<n;i++)
    {
        int k=i;
        int j=0;
        while(k>=0 && j<=i )
        {
            cout<<a[k][j]<<" ";
            k--;
            j++;
        }
        cout<<endl;
    }
}
int main()
{
 vector<vector<int>>a {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
    };
    prind(a,5,4);
    return 0;
}
