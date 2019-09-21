#include<bits/stdc++.h>
using namespace std;
typedef int _int;
#define int long long

int n, m, p,type;

int exgcd(int a, int b, int &x, int &y){
    if(!b){ x = 1, y = 0; return a; }
    int gcd = exgcd(b, a%b, x, y), tmp;
    tmp = x, x = y, y = tmp-a/b*y;
    return gcd;
}

inline int Mod(int x, int mod){ return x > mod ? x-mod : x; }

inline int inv(int a, int mod){
    int x, y; exgcd(a, mod, x, y);
    return (x%mod+mod)%mod;
}

inline int qpow(int x, int n, int mod){
    int res = 1;
    for(; n; x = x*x%mod, n >>= 1)
        if(n & 1) (res *= x) %= mod;
    return res;
}

int fac(int n, int pi, int pk){
    if(!n) return 1;
    int res = 1;
    for(int i = 2; i < pk; i++)
        if(i % pi) (res *= i) %= pk;
    res = qpow(res, n/pk, pk);
    for(int i = 2; i <= n%pk; i++)
        if(i % pi) (res *= i) %= pk;
    return fac(n/pi, pi, pk)*res%pk;
}

inline int C(int n, int m, int pi, int pk){
    if(n < m) return 0;
    int r1 = fac(n, pi, pk), r2 = fac(m, pi, pk);
    int r3 = fac(n-m, pi, pk), cnt = 0;
    for(int i = n; i; i /= pi) cnt += i/pi;
    for(int i = m; i; i /= pi) cnt -= i/pi;
    for(int i = n-m; i; i /= pi) cnt -= i/pi;
    return r1*inv(r2, pk)%pk*inv(r3, pk)%pk*qpow(pi, cnt, pk)%pk;
}

inline int exlucas(int n, int m, int p){
    int pi, pk, res = 0, x, y, gcd, c, M = 1;
    for(int i = 2; i*i <= p; i++){
        if(p % i == 0){
            pi = i, pk = 1;
            while(p % i == 0) p /= i, pk *= i;
            gcd = exgcd(M, pk, x, y), c = Mod((C(n, m, pi, pk)-res)%pk+pk, pk);
            x = Mod(x*(c/gcd)%pk+pk, pk);
            res += M*x, M *= pk/gcd, res %= M;
        }
    }
    if(p > 1){
        pi = pk = p; gcd = exgcd(M, pk, x, y);
        c = Mod((C(n, m, pi, pk)-res)%pk+pk, pk);
        x = Mod(x*(c/gcd)%pk+pk, pk);
        res += M*x, M *= pk/gcd, res %= M;
    }
    return res;
}

_int main(){
    cin>>type>>n>>m>>p;
    int ans1=1;
    for(int i=1;i<=m;i++)ans1=ans1*i%p;
    int ans=ans1*exlucas(n-m+1,m,p)%p;
    cout<<ans<<endl;
    return 0;
}