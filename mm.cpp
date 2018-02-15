#include <bits/stdc++.h>

using namespace std;
const unsigned int mod=1e9+7;

unsigned int f(int k,int n)
{
     unsigned long long sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=(sum +i)%mod;
        i=( i*k)%mod;
    }
    return sum;
}
unsigned int simplestSum(int k, int a, int b) {
    unsigned long long  sum=0;
    for(int i=a;i<=b;i++)
    {
        sum=((sum)%mod+f(k,i)%mod)%mod;
    }

    return sum;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        int a;
        int b;
        cin >> k >> a >> b;
        long long int result = simplestSum(k, a, b);
        cout << result << endl;
    }
    return 0;
}
