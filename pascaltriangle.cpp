#include<iostream>
using namespace std;
/*int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int getcombination(int n,int r)
{
    int factn=fact(n);
    int factr=fact(r);
    int factnr=fact(n-r);

    return (factn/(factr * factnr));

}
void getPascal(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<getcombination(i,j);
            cout<<" ";
        }
        cout<<endl;
    }

}*/
void printPascal(int n)
{
for (int line = 1; line <= n; line++)
{
	int C = 1; // used to represent C(line, i)
	for (int i = 1; i <= line; i++)
	{
	cout<<C; // The first value in a line is always 1
	C = C * (line - i) / i;

	}
	cout<<"\n";
}
}
int main()
{
    int n;
    cin>>n;
    printPascal(n);
}
