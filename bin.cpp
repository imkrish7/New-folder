#include<iostream>
using namespace std;
void BST(int a[][4],int r,int c,int m)
{
    int i=0;
    int j=c-1;
    while(i<r && j>=0)
    {
        if(a[i][j]==m)
        {
            cout<<"found at"<<endl;
            break;
        }
        if(a[i][j]>m)
         j--;
        else
         i++;
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
