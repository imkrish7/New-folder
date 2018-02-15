#include<iostream>
#include<map>
using namespace std;

struct area{

    int a,b;
    area(int a,int b): a(a),b(b){};
};

int findsurvival(int A,int B,area X,area Y,area Z,int last,map<pair<int,int>,int>&memo)
{

    if(A<=0 || B<=0)
        return 0;
     pair<int,int>cur=make_pair(A,B);
     if(memo.find(cur)!=memo.end())
            return memo[cur];

     int temp;
     switch(last)
     {
        case 1:
                temp=1+max(findsurvival(A+Y.a,B+Y.b,X,Y,Z,2,memo),findsurvival(A+Z.a,B+Z.b,X,Y,Z,3,memo));
                    break;
        case 2:
                temp=1+max(findsurvival(A+X.a,B+X.b,X,Y,Z,1,memo),findsurvival(A+Z.a,B+Z.b,X,Y,Z,3,memo));
                break;

        case 3:
                temp=1+max(findsurvival(A+X.a,B+X.b,X,Y,Z,1,memo),findsurvival(A+Y.a,B+Y.b,X,Y,Z,2,memo));
                break;

     }
     memo[cur]=temp;

     return temp;
}
int survival(int A,int B,area X,area Y,area Z)
{

    map<pair<int,int>,int>memo;

    return max(findsurvival(A+X.a,B+X.b,X,Y,Z,1,memo),max(findsurvival(A+Y.a,B+Y.b,X,Y,Z,2,memo),findsurvival(A+Z.a,B+Z.b,X,Y,Z,3,memo)));
}
int main()
{
area X(3, 2);
    area Y(-5, -10);
    area Z(-20, 5);

    int A = 20;
    int B = 8;
    cout << survival(A, B, X, Y, Z);

    return 0;
}
