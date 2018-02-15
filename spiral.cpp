#include<iostream>
using namespace std;

void spiral(int arr[][4],int r,int c)
{

    int i,k=0,l=0;

    while(k<r && l<c)
    {
        for(i=l;i<c;i++)
        {
            cout<<arr[k][i]<<" ";
        }
        k++;
        //cout<<endl;
        for(i=k;i<r;i++)
        {
           cout<<arr[i][c-1]<<" ";
        }
        c--;
        //cout<<endl;
        if(k<r)
        {
            for(i=c-1;i>=l;i--)
            {
                cout<<arr[r-1][i]<<" ";
            }
        }
        r--;
        //cout<<endl;
        if(l<c)
        {
            for(i=r-1;i>=k;i--)
            {
                cout<<arr[i][l]<<" ";
            }
        }
        l++;
        //cout<<endl;
    }
}
int main()
{
       int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  spiral(mat, 4,4);
    return 0;
}
