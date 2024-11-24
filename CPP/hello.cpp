#include <iostream>

using namespace std;

const int maxn = 2e5+1;
const int mod = 1e9+7;
int fact[maxn], inv[maxn];

int power(int x, int y) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x;
    } else {
        int temp = power(x,y/2);
        temp = (1LL * temp * temp) % mod;
        if (y%2 == 1) {
            temp = (1LL * temp * x) % mod;
        }
        return temp;
    }
}

int C(int k, int n) {
    return (((1LL * fact[n] * inv[k]) % mod) * 1LL * inv[n-k])%mod;
}

int main() {
    int n,k;
    cin>>n>>k;
    fact[0] = 1;
    inv[0]=1;
    for (int i=1; i<maxn; i++) {
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = power(fact[i], mod-2);
    }

    cout<<C(k,n);    
    return 0;
}