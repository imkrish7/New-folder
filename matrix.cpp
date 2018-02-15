#include<iostream>
using namespace std;

int BSTUTIL(int a[][4],int r,int cs,int ce,int k)
{

        while(cs<=ce)
        {

           int m=cs+(ce-cs)/2;
            if(a[r][m]>k)
            {
                ce=m-1;
            }
            else if(a[r][m]<k)
            {
                cs=m+1;
            }
            else{

                return m;
            }
            //cout<<r<<m<<endl;
        }
        return -1;
}
void BST(int a[][4],int r,int c,int m)
{

    for(int i=0;i<r;i++)
    {
        int t=BSTUTIL(a,i,0,c,m);
        if(t>=0)
        {
            cout<<"element found at"<<a[i][t]<<endl;
            break;
        }

    }
}
int main()
{
    int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  BST(mat, 4,4, 29);
  return 0;
}
